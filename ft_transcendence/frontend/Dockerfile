FROM node:18

RUN apt-get update

WORKDIR /usr/root/frontend

COPY . /usr/root/frontend/

EXPOSE 4242

RUN npm i

RUN npm run build

ENTRYPOINT [ "npm", "run", "start" ]
