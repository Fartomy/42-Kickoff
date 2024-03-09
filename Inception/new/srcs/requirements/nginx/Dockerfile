FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install nginx openssl -y

RUN mkdir /etc/nginx/ssl && chmod 700 /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/nginx/ssl/inception.key -out /etc/nginx/ssl/inception.crt -subj / 
# "/C=TR/ST=Istanbul/L=Istanbul/O=wordpress/CN=${DOMAIN_NAME}" --> "-subj" den sonra konulacak satir ancak "DOMAIN_NAME" ".env" dosyasindan sanirim alinamiyor.

COPY ./conf/default /etc/nginx/sites-available/default

EXPOSE 443

CMD [ "nginx", "-g", "daemon off;" ]