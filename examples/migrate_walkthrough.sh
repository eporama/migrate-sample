for step in \
step_0_readme \
step_1_module_info \
step_2_story \
step_3_constructor \
step_4_map_source_destination \
step_5_source_conn \
step_6_query \
step_7_field_mappings \
step_8_more_fields \
step_9_map_structure \
step_10_map_source \
step_11_map_destination \
step_12_compacting_map \
step_13_default_user \
step_14_users \
step_15_connect_users

do
  read -p "Ready for $step?"
  git checkout $step
done
