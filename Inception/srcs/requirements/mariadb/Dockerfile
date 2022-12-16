FROM debian:10
RUN apt-get update
RUN apt-get install mariadb-server -y
COPY ./conf/mariadb_server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /var/www/
RUN service mysql start
EXPOSE 3306
CMD ["mysql", "<", "/var/www/set_data.sql"]
CMD ["mysqld"]