FROM debian:11

COPY ./tools/setting.sh /setting.sh

RUN chmod 777 setting.sh
RUN apt update; \
    apt install -y php-mysql php7.4 php-mysql php-fpm curl mariadb-client

RUN mkdir -p /var/www/html

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d
COPY ./conf /var/www/

EXPOSE 9000

RUN mkdir -p /run/php
RUN groupadd -r mysql && useradd -r -g mysql mysql

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
RUN chown www-data:www-data /run/php

RUN groupadd -r wordpress && useradd -r -g wordpress -d /var/www/html wordpress && \
	chown -R wordpress:wordpress /var/www/html

WORKDIR /var/www/html

ENTRYPOINT ["sh", "/setting.sh"]
