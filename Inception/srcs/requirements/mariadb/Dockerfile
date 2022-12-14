FROM debian:10
RUN apt-get update
RUN apt-get install mariadb-server -y
CMD ["systemctl", "enable", "mariadb"]
CMD ["mysql", "-V"]