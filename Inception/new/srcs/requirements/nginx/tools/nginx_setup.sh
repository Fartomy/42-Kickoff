#!/bin/bash

mkdir /etc/nginx/ssl
chmod 700 /etc/nginx/ssl

openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/nginx/ssl/inception.key -out /etc/nginx/ssl/inception.crt -subj "/C=TR/L=IST/O=wordpress/OU=student/CN=${DOMAIN_NAME}"

nginx -g "daemon off;"