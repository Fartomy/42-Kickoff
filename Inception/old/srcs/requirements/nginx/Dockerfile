FROM debian:10
RUN apt-get update -y
RUN apt install nginx -y
RUN apt install openssl -y
COPY ./conf/default /etc/nginx/sites-enabled/default
COPY ./tools/nginx.sh /var/www
RUN chmod +x /var/www/nginx.sh
EXPOSE 443
ENTRYPOINT [ "var/www/nginx.sh" ]
CMD ["nginx", "-g", "daemon off;"]