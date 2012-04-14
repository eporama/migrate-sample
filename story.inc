<?php

class StoryMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migration of old stories into article nodes');

    /*
    * Build up a query of the old stories
    */
    $query = Database::getConnection('default', 'for_migration')
             ->select('stories', 'old_stories');
    $query->fields('old_stories'); // this grabs all fields from "old_stories"
 
    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationNode();
    $this->map = new MigrateSQLMap();
  }
}
