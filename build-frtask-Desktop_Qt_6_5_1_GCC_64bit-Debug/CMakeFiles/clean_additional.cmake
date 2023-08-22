# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appfrtask_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appfrtask_autogen.dir/ParseCache.txt"
  "appfrtask_autogen"
  )
endif()
