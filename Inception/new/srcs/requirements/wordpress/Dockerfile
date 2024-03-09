FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install wget php7.4 php-fpm php-mysqli -y

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./tools/* /root/

RUN chmod +x /root/wp-setup.sh

EXPOSE 9000

CMD [ "/root/wp-setup.sh" ]