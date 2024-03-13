#!/usr/bin/env bash
set -Eeuo pipefail

# Docker environment variables

: "${HV="Y"}"
: "${KVM:="Y"}"
: "${CPU_FLAGS:=""}"
: "${CPU_MODEL:=""}"
: "${DEF_MODEL:="qemu64"}"

[ "$ARCH" != "amd64" ] && KVM="N"

if [[ "$KVM" != [Nn]* ]]; then

  KVM_ERR=""

  if [ ! -e /dev/kvm ]; then
    KVM_ERR="(device file missing)"
  else
    if ! sh -c 'echo -n > /dev/kvm' &> /dev/null; then
      KVM_ERR="(no write access)"
    else
      if ! grep -q -e vmx -e svm /proc/cpuinfo; then
        KVM_ERR="(vmx/svm disabled)"
      fi
    fi
  fi

  if [ -n "$KVM_ERR" ]; then
    KVM="N"
    error "KVM acceleration not available $KVM_ERR, this will cause a major loss of performance."
    error "See the FAQ on how to enable it, or continue without KVM by setting KVM=N (not recommended)."
    [[ "$DEBUG" != [Yy1]* ]] && exit 88
  fi

fi

if [[ "$KVM" != [Nn]* ]]; then

  CPU_FEATURES="kvm=on,l3-cache=on"
  HV_FEATURES="+hypervisor,+invtsc,hv_passthrough"
  KVM_OPTS=",accel=kvm -enable-kvm -global kvm-pit.lost_tick_policy=discard"

  if [ -z "$CPU_MODEL" ]; then
    CPU_MODEL="host"
    CPU_FEATURES="$CPU_FEATURES,migratable=no"
  fi

else

  CPU_FEATURES="l3-cache=on"
  HV_FEATURES="+hypervisor,hv_passthrough"

  if [[ "$ARCH" != "amd64" ]]; then
    KVM_OPTS=""
  else
    KVM_OPTS=" -accel tcg,thread=multi"
  fi

  if [ -z "$CPU_MODEL" ]; then
    if [[ "$ARCH" == "amd64" ]]; then
      CPU_MODEL="max"
      CPU_FEATURES="$CPU_FEATURES,migratable=no"
    else
      CPU_MODEL="$DEF_MODEL"
    fi
  fi

  CPU_FEATURES="$CPU_FEATURES,+ssse3,+sse4.1,+sse4.2"

fi

if [[ "$HV" != [Nn]* ]] && [[ "${BOOT_MODE,,}" == "windows"* ]]; then

  [ -n "$CPU_FEATURES" ] && CPU_FEATURES="$CPU_FEATURES,"
  CPU_FEATURES="$CPU_FEATURES${HV_FEATURES}"

fi

if [ -z "$CPU_FLAGS" ]; then
  if [ -z "$CPU_FEATURES" ]; then
    CPU_FLAGS="$CPU_MODEL"
  else
    CPU_FLAGS="$CPU_MODEL,$CPU_FEATURES"
  fi
else
  if [ -z "$CPU_FEATURES" ]; then
    CPU_FLAGS="$CPU_MODEL,$CPU_FLAGS"
  else
    CPU_FLAGS="$CPU_MODEL,$CPU_FEATURES,$CPU_FLAGS"
  fi
fi

return 0
