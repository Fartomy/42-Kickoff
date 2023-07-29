FROM node:18

RUN apt-get update

WORKDIR /usr/root/backend

COPY . /usr/root/backend/

EXPOSE 3000

RUN npm i

RUN npm run build

ENTRYPOINT [ "npm", "run", "start:prod" ]
