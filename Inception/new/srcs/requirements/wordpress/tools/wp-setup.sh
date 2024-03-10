#!/bin/bash

mkdir -p /var/www/html

chown -R www-data:www-data /var/www/*
chown -R 755 /var/www/*

cd /var/www/html
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

wp core download --allow-root
rm -rf /var/www/html/wp-config-sample.php
mv /root/wp-config.php /var/www/html/

wp core install --allow-root --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_MAIL --skip-email --allow-root
wp user create --allow-root $WP_USER $WP_USER_MAIL --user_pass=$WP_USER_PASS --allow-root

# Theme
wp theme install console --activate --allow-root

# Redis
wp plugin install redis-cache --activate --allow-root

# wp plugin update --all --allow-root
# wp plugin activate redis-cache --allow-root
# wp redis enable --force --allow-root

mkdir /run/php/

wp redis enable --allow-root

/usr/sbin/php-fpm7.4 --nodaemonize