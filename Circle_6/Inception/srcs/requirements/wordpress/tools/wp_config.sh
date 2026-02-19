#!/bin/bash

sleep 10

if [ ! -e /var/www/html/wp-config.php ]; then
    echo "Wordpress configuration..."

    wp core download --allow-root

    wp config create --dbname=${MYSQL_DATABASE} \
                    --dbuser=${MYSQL_USER} \
                    --dbpass=${MYSQL_PASSWORD} \
                    --dbhost=mariadb \
                    --allow-root

    wp core install --url=${DOMAIN_NAME} \
                    --title="mchiaram Inception" \
                    --admin_user=${WP_ADMIN_USER} \
                    --admin_password=${WP_ADMIN_PASSWORD} \
                    --admin_email=${WP_ADMIN_EMAIL} \
                    --skip-email \
                    --allow-root

    wp user create ${WP_USER} ${WP_EMAIL} \
                    --role=author \
                    --user_pass=${WP_PASSWORD} \
                    --allow-root

    echo "WordPress configuration done!"
else
    echo "WordPress is already set up. Installation skipped."
fi

echo "PHP-FPM startup..."
exec /usr/sbin/php-fpm7.4 -F