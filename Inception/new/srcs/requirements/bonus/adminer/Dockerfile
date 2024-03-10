FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

## Alternative Method 1 Packages
# RUN apt-get install wget php7.4 php-mysqli php-fpm -y

## Alternative Method 2 Packages
RUN apt-get install adminer php7.4 php-fpm php-mysqli -y 

COPY ./tools/adminer_setup.sh /root/

RUN chmod +x /root/adminer_setup.sh

CMD [ "/root/adminer_setup.sh" ]