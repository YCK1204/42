#!/bin/bash

sleep 10

echo -e "\n127.0.0.1\t$DOMAIN_NAME\n" | xargs >> /etc/hosts

wp core install \
	--url=$DOMAIN_NAME \
    --title=$WEB_SITE_NAME \
    --admin_user=$ADMIN_USER_NAME \
    --admin_password=$ADMIN_USER_PASSWORD \
    --admin_email=$ADMIN_USER_EMAIL \
    --allow-root
wp user create \
	$FIRST_USER_NAME $FIRST_USER_EMAIL \
    --role=Administrator \
    --user_pass=$FIRST_USER_PASSWORD \
    --path=$WORDPRESS_PATH \
    --allow-root
wp user create \
	$SECOND_USER_NAME $SECOND_USER_EMAIL \
    --role=editor \
    --user_pass=$SECOND_USER_PASSWORD \
    --path=$WORDPRESS_PATH \
    --allow-root
php-fpm7.4 -F
