FROM debian:10
RUN apt-get update -y
RUN apt-get install php7.3 wget sendmail php-mysqli php-fpm -y
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
COPY ./tools /var/www/

RUN chmod +x /var/www/wdp.sh

ENTRYPOINT ["/var/www/wdp.sh"]

EXPOSE 9000
CMD ["/usr/sbin/php-fpm7.3", "--nodaemonize"]