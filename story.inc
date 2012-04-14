<?php

class StoryMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migration of old stories into article nodes');
  }
}
