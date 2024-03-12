FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install vsftpd ssh -y

COPY ./tools/ftp_setup.sh /root/

COPY ./conf/vsftpd.conf /etc/vsftpd.conf

COPY ./conf/sshd_config /etc/ssh/sshd_config

RUN chmod +x /root/ftp_setup.sh

CMD [ "/root/ftp_setup.sh" ]