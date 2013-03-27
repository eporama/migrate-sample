<?php

class UserMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migration of old users into drupal users');

    /*
    * Build up a query of the old users
    */
    $query = Database::getConnection('default', 'for_migration')
             ->select('authors', 'old_users');
    $query->fields('old_users'); // this grabs all fields from "old_users"

    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationUser();

    /*
     * Add field mappings as Drupal object property and source field name
     */
    $this->addFieldMapping('name', 'username');
    $this->addFieldMapping('mail', 'email');
    $this->addFieldMapping('pass', 'password');
    $this->addFieldMapping('created', 'date_created');
    $this->addFieldMapping('access', 'last_login');
    $this->addFieldMapping('status', '')->defaultValue(1);

    /*
     *  Add the SQL Mapping to store the key <-> key identifiers
     */
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array('id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'ID of source row',
        )
      ),
      MigrateDestinationUser::getKeySchema()
    );
  }
}
