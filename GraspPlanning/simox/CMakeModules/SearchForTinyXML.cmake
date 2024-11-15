find_library(tinyxml_library tinyxml)
if (tinyxml_library)
  message (STATUS " ** Looking for libtinyxml - found")
  set(tinyxml_libraries ${tinyxml_library})
endif ()

find_path(tinyxml_include_dirs NAMES tinyxml.h PATH_SUFFIXES tinyxml)
if (NOT tinyxml_include_dirs)
   message (STATUS " ** Looking for tinyxml/tinyxml.hpp or tinyxml/tinyxml.h - not found.")
endif ()

if (NOT tinyxml_include_dirs OR NOT tinyxml_libraries)
   include (FindPkgConfig)
   if (PKG_CONFIG_FOUND)
     # Find tinyxml
     pkg_check_modules(tinyxml tinyxml)
   else()
     MESSAGE(STATUS " ** tinyxml not found")
   endif()
endif ()
