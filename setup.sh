#!/usr/bin/env bash
# a Bash script that sets up your web servers for the deployment of web_static

apt-get update
apt-get install -y nginx
ufw allow 'Nginx HTTP'


echo "Hello World!" > /var/www/html/index.html
echo "Ceci n'est pas une page" > /var/www/html/error_404.html

echo "server {
        listen 80 default_server;
        listen [::]:80 default_server;
        add_header X-Served-By \"$HOSTNAME\";

        root /var/www/html;
        index index.html index.htm index.nginx-debian.html;

        server_name _;

        location / {
                try_files \$uri \$uri/ =404;
        }

        location /redirect_me {
                return 301 https://www.youtube.com/watch?v=QH2-TGUlwu4;
        }
        error_page 404 /error_404.html;
}" > /etc/nginx/sites-available/default

service nginx restart
