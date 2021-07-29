# CentMinMod_Wordpress_Staging<br />
git clone https://github.com/Brijendrasial/CentMinMod_Wordpress_Staging.git<br />
cd  CentMinMod_Wordpress_Staging<br /><br />
Production to Staging<br />
sh staging-wordpress-cmm.sh --staging production_domain staging_domain staging_mysql_db_name staging_mysql_db_user staging_mysql_db_pass<br /><br />
Staging to Production<br />
sh staging-wordpress-cmm.sh --production production_domain staging_domain

example Production to Staging <br />
sh staging-wordpress-cmm.sh --staging bullten.buzz dev.bullten.buzz sial_db72 sial_user72 sial@123<br /><br />
example Staging to Production <br />
sh staging-wordpress-cmm.sh --production bullten.buzz dev.bullten.buzz
