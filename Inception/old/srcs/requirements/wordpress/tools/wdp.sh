#!/bin/bash

	sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/" "/etc/php/7.3/fpm/pool.d/www.conf";
	chown -R www-data:www-data /var/www/*;
	chown -R 755 /var/www/*;
	mkdir -p /run/php/;
	touch /run/php/php7.3-fpm.pid;

if [ ! -f /var/www/html/wp-config.php ]; then
	echo "Wordpress: setting up..."
	mkdir -p /var/www/html
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar;
	chmod +x wp-cli.phar; 
	mv wp-cli.phar /usr/local/bin/wp;
	cd /var/www/html;
	wp core download --allow-root;
	mv /var/www/wp-config.php /var/www/html/
	echo "Wordpress: creating users..."
	wp core install --allow-root --url=${DOMAIN_NAME} --title=${WORDPRS_TTL} --admin_user=${WORDPRS_ADMIN} --admin_password=${WORDPRS_ADMIN_PASS} --admin_email=${WORDPRS_ADMIN_MAIL}
	wp user create --allow-root ${WORDPRS_USR} ${WORDPRS_USR_MAIL} --user_pass=${WORDPRS_USR_PASS};
	echo "Wordpress: set up!"
fi

exec "$@"