FROM	debian:buster

# get update software packages in debian
RUN		apt-get update && apt-get upgrade -y
# wget command will be used to get .tar file of phpmyadmin and wordpress
RUN		apt-get -y install wget
RUN		apt-get -y install vim

# nginx
RUN		apt-get -y install nginx
COPY	./srcs/nginx.conf /etc/nginx/sites-available/
RUN		rm -f ./etc/nginx/sites-enabled/default
RUN		ln -s  /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/nginx.conf

# php-mysql
RUN		apt-get -y install mariadb-server
RUN		apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

WORKDIR	/var/www/html/

# PHPMYADMIN
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN		tar -xf phpMyAdmin-5.0.1-english.tar.gz
RUN		rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN		mv phpMyAdmin-5.0.1-english phpmyadmin
COPY	./srcs/config.inc.php phpmyadmin

# WORDPRESS
RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar -xvzf latest.tar.gz
RUN		rm -rf latest.tar.gz
COPY	./srcs/wp-config.php /var/www/html/

RUN		openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Moscow/L=moscow/O=21/OU=21School/CN=localhost" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt

EXPOSE	80 443
RUN		rm index.nginx-debian.html

COPY	./srcs/start.sh ./
COPY	./srcs/index.sh ./
RUN		chmod -R 755 /var/www/html/*.sh

CMD		bash ./start.sh

# docker build -t khotah .
# docker run -it --rm -p 80:80 -p 443:443 khotah
