# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appProxyModelThing_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appProxyModelThing_autogen.dir/ParseCache.txt"
  "appProxyModelThing_autogen"
  )
endif()
