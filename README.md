# CentMinMod_Wordpress_Staging<br />
git clone https://github.com/Brijendrasial/CentMinMod_Wordpress_Staging.git<br />
cd  CentMinMod_Wordpress_Staging<br /><br />
Production to Staging<br />
sh staging-wordpress-cmm.sh --staging production_domain staging_domain<br /><br />
Staging to Production<br />
sh staging-wordpress-cmm.sh --production production_domain staging_domain

example Production to Staging <br />
sh staging-wordpress-cmm.sh --staging bullten.buzz dev.bullten.buzz<br /><br />
example Staging to Production <br />
sh staging-wordpress-cmm.sh --production bullten.buzz dev.bullten.buzz
