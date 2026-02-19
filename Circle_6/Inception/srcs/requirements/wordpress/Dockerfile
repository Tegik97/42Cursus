FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y php7.4-fpm \
                        php7.4-mysql \
                        mariadb-client \
                        curl

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY tools/wp_config.sh /usr/local/bin/wp_config.sh
RUN chmod +x /usr/local/bin/wp_config.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wp_config.sh"]