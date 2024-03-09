FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install nginx openssl -y

COPY ./conf/default /etc/nginx/sites-available/default

COPY ./tools/nginx_setup.sh /root/

RUN chmod +x /root/nginx_setup.sh

CMD [ "/root/nginx_setup.sh" ]