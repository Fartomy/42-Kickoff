FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install mariadb-server mariadb-client expect -y

COPY ./tools/* /root/

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

RUN chmod +x /root/mysql_setup.sh

EXPOSE 3306

CMD [ "/root/mysql_setup.sh" ]