#!/bin/bash

## Alternative Method 1
# mkdir -p /var/www/html
# wget "http://www.adminer.org/latest.php" -O /var/www/html/index.php
# chown -R www-data:www-data /var/www/html/index.php
# chmod 755 /var/www/html/index.php
# php -S 0.0.0.0:8080 -t /var/www/html

## [ Running one of the two alternative methods will run the adminer. So, remove comment lines from one of the two blocks. ]

## Alternative Method 2
cd /etc/apache2/conf-available
ln -s ../../adminer/apache.conf adminer.conf
cp /usr/share/adminer/adminer.php /var/www/html/index.php
a2enconf adminer
service apache2 reload
php -S 0.0.0.0:8080 -t /var/www/html