<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/documentation/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */

define( 'DB_NAME', 'inception_db' );

/** Database username */
define( 'DB_USER', 'tempuser' );

/** Database password */
define( 'DB_PASSWORD', 'tempuser123' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/** Cache Settings */

define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', 6379 );
define('WP_CACHE', true);

// define('WP_CACHE_KEY_SALT', 'ftekdrmi@ftekdrmi.com');
// define('WP_REDIS_TIMEOUT', 1);
// define('WP_REDIS_READ_TIMEOUT', 1);
// define('WP_REDIS_DATABASE', 0);

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '2D`[+(y.=L}x2TuZ5d#Uop}ojl|tvzt/K%sbW>>1}Cl6yPh1]T[>>^|_DO3_6{ZC');
define('SECURE_AUTH_KEY',  'upZ|G yg-RTeX>RE~.>M`~  9v*u9Qm)8;C%%IL~)3%e_PuiHY0AJR};Bw&]d,tE');
define('LOGGED_IN_KEY',    '2LAEzlM >:Ph_6@C,3M5>Ts4|N)dy};b1!jOSOfDvCQPVG?B.6=ya,_K*EQg[2y%');
define('NONCE_KEY',        'w3 -+{hz=%EVRO&?G_b$VUz/qCe0Dt{Z|e67uk5|(/o(Fz331m?,:P#~t]4O%Jq&');
define('AUTH_SALT',        'i:bl-SVwVsSla]Sxho%y?l@ V|+kr$-ED=3iJNZEY2$Qa=@?XMm~p#T<V$L(|Unn');
define('SECURE_AUTH_SALT', '}U.K:--Ux2Y8Q#O}wwwl5w#!n{vSom:Z2iUv[VgSwaYV[-HdLdH< $d{uF1c98MH');
define('LOGGED_IN_SALT',   '/5: p-|rrTs8<o6R3GV`F.c9Sb+%R3Y[l@jG{9T|]nO8zP7`XXljuBXeF]4&U?jC');
define('NONCE_SALT',       '%&${d><g1w=Md8A~{)nmBn^s%$Zd_h>BsFk6,y55QEvTk*MP@+$=0OQ8Xm+Rt%0>');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/documentation/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
