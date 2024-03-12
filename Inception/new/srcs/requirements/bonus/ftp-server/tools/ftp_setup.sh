#!/bin/bash

## SFTP SERVER - SSHD
addgroup sftp
adduser --disabled-password --gecos "" $SFTP_USER
echo "$SFTP_USER:$SFTP_USER_PASS" | chpasswd &> /dev/null
usermod -a -G sftp $SFTP_USER
chown $SFTP_USER:$SFTP_USER /var/www/html/
service ssh reload
service ssh restart


## FTP SERVER - VSFTPD
mkdir -p /var/run/vsftpd/empty
adduser --disabled-password --gecos "" $FTP_USER
echo "$FTP_USER:$FTP_USER_PASS" | chpasswd &> /dev/null
echo "$FTP_USER" | tee -a /etc/vsftpd.userlist &> /dev/null
chown $FTP_USER:$FTP_USER /var/www/html/
/usr/sbin/vsftpd /etc/vsftpd.conf
