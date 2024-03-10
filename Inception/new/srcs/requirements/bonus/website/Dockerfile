FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install nodejs npm -y

COPY ./tools /root

RUN chmod +x /root/website_setup.sh

CMD [ "/root/website_setup.sh" ]