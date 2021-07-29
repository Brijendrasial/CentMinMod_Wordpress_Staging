#x# HTTPS-DEFAULT
 server {

   server_name demo.com www.demo.com;
   return 302 https://demo.com$request_uri;
   root /home/nginx/domains/demo.com/public;
   include /usr/local/nginx/conf/staticfiles.conf;
 }

server {
  listen 443 ssl http2;
  server_name demo.com www.demo.com;

  ssl_dhparam /usr/local/nginx/conf/ssl/demo.com/dhparam.pem;
  ssl_certificate      /usr/local/nginx/conf/ssl/demo.com/demo.com.crt;
  ssl_certificate_key  /usr/local/nginx/conf/ssl/demo.com/demo.com.key;
  include /usr/local/nginx/conf/ssl_include.conf;



  # mozilla recommended
  ssl_ciphers ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-RSA-AES256-SHA256:DHE-RSA-AES256-SHA:ECDHE-ECDSA-DES-CBC3-SHA:ECDHE-RSA-DES-CBC3-SHA:EDH-RSA-DES-CBC3-SHA:AES128-GCM-SHA256:AES256-GCM-SHA384:AES128-SHA256:AES256-SHA256:AES128-SHA:AES256-SHA:DES-CBC3-SHA:!DSS;
  ssl_prefer_server_ciphers   on;
  #add_header Alternate-Protocol  443:npn-spdy/3;

  # before enabling HSTS line below read centminmod.com/nginx_domain_dns_setup.html#hsts
  #add_header Strict-Transport-Security "max-age=31536000; includeSubdomains;";
  #add_header X-Frame-Options SAMEORIGIN;
  add_header X-Xss-Protection "1; mode=block" always;
  add_header X-Content-Type-Options "nosniff" always;
  #add_header Referrer-Policy "strict-origin-when-cross-origin";
  #add_header Permissions-Policy "accelerometer=(), camera=(), geolocation=(), gyroscope=(), magnetometer=(), microphone=(), payment=(), usb=()";
  #spdy_headers_comp 5;
  ssl_buffer_size 1369;
  ssl_session_tickets on;

  # enable ocsp stapling
  resolver 8.8.8.8 8.8.4.4 1.1.1.1 1.0.0.1 valid=10m;
  resolver_timeout 10s;
  #ssl_stapling on;
  #ssl_stapling_verify on;

  access_log /home/nginx/domains/demo.com/log/access.log combined buffer=256k flush=5m;
  error_log /home/nginx/domains/demo.com/log/error.log;

  root /home/nginx/domains/demo.com/public;
  # uncomment cloudflare.conf include if using cloudflare for
  # server and/or vhost site
  #include /usr/local/nginx/conf/cloudflare.conf;
  include /usr/local/nginx/conf/503include-main.conf;

  location / {
  include /usr/local/nginx/conf/503include-only.conf;

  # Wordpress Permalinks
  try_files $uri $uri/ /index.php?q=$uri&$args;

  }

  include /usr/local/nginx/conf/php-wpsc.conf;

  # https://community.centminmod.com/posts/18828/
  #include /usr/local/nginx/conf/php-rediscache.conf;
  include /usr/local/nginx/conf/pre-staticfiles-local-bullten.buzz.conf;
  include /usr/local/nginx/conf/pre-staticfiles-global.conf;
  include /usr/local/nginx/conf/staticfiles.conf;
  include /usr/local/nginx/conf/drop.conf;
  #include /usr/local/nginx/conf/errorpage.conf;
  include /usr/local/nginx/conf/vts_server.conf;
}
