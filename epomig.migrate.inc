<?php
/*
 * Implementation of hook_migrate_api.
 */
function epomig_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
            'User' => array('class_name' => 'UserMigration'),
    )
  );
  return $api;
}
