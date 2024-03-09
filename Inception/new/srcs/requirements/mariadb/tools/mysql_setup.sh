#!/bin/bash

# surekli /root/db.sql yazmak yerine Dockerfile'da "WORKDIR /root" yapildiginda service ayaga kalkiyor ancak "mariadb" konteyniri surekli olarak "restarting"e
# dusuyor ve o sekilde ("restarting") takili kaliyor.

echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;" > /root/db.sql
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASS';" >> /root/db.sql
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';" >> /root/db.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '12345';" >> /root/db.sql
echo "FLUSH PRIVILEGES;" >> /root/db.sql

service mariadb start
chmod +x /root/mysql_secure.expect
./root/mysql_secure.expect
mysql < /root/db.sql

mysqld