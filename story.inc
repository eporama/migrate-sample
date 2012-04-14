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

    $this->destination = new MigrateDestinationNode('article');

    /*
     * Add field mappings as Drupal object property and source field name
     */
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('uid', 'author_id');
    $this->addFieldMapping('created', 'date_created');

    $this->map = new MigrateSQLMap();
  }
}
