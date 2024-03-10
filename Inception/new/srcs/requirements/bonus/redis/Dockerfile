FROM debian:11

RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install redis-server -y

COPY ./conf/redis.conf /etc/redis/redis.conf

# EXPOSE 6379

CMD ["redis-server", "--protected-mode", "no"]