ARCH=$(uname -a)
PCPU=$(cat /proc/cpuinfo | grep cpu\ cores | uniq | awk '{print($4)}')
VCPU=$(cat /proc/cpuinfo | grep processor | wc -l)
CPUUSG=$(top -b -n1 | grep "Cpu(s)" | awk '{print($4)"%"}')
LASTBOOT=$(who -b | awk '{print $3,$4}')
lvmrtn=$(lsblk | grep "lvm" | wc -l)
LVMGET=$(if [ $lvmrtn -eq 0 ]; then echo no; else echo yes; fi)
TCPCNT=$(netstat | grep ESTABLISHED | wc -l)
TCPEST=$(netstat | grep ESTABLISHED | awk '{print($6)}')
USRCNT=$(who | wc -l)
NTWRKMAC=$(ip link show | grep link/ether | awk '{print($2)}')
NTWRKIP=$(hostname -I)
SUDOCNT=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
MEMUSG=$(free -m | grep Mem: | awk '{print($3)}')
MEMUSGTTL=$(free -m | grep Mem: | awk '{print($2)}')
MEMUSGPRCNT=$(free -m | grep Mem: | awk '{printf("%.2f"),($3/$2*100)}')
DSKUSGMB=$(df -BM --total | grep total | awk '{print($3)}' | tr -d M)
DSKUSGGB=$(df -BG --total | grep total | awk '{print($3)}' | tr -d G)
DSKUSGPRCNT=$(df --total | grep root | awk '{print($5)}')
wall "
        #Architecture: $ARCH
        #CPU physical : $PCPU
        #vCPU : $VCPU
        #Memory Usage: $MEMUSG/$MEMUSGTTL"MB" ($MEMUSGPRCNT"%")
        #Disk Usage: $DSKUSGMB/$DSKUSGGB"Gb" ($DSKUSGPRCNT)
        #CPU load: $CPUUSG
        #Last boot: $LASTBOOT
        #LVM use: $LVMGET
        #Connexions TCP : $TCPCNT $TCPEST
        #User log: $USRCNT
        #Network: "IP" $NTWRKIP ($NTWRKMAC)
        #Sudo : $SUDOCNT cmd
"
