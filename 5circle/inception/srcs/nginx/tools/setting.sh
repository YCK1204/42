#!/bin/sh

openssl req -x509 -days 30 -nodes -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt \
    -subj "/C=KR/ST=seoul/L=gaepo-dong/O=42seoul/OU=yeckim-cadet/CN=localhost"

cp /copy/default /etc/nginx/sites-available/default


nginx -g "daemon off;"
