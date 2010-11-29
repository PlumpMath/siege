FIND_PATH(SQUIRREL_INCLUDE_DIR squirrel.h PATH_SUFFIXES squirrel)

FIND_LIBRARY(SQUIRREL_LIBRARY NAMES squirrel PATH_SUFFIXES squirrel)
IF(NOT SQUIRREL_LIBRARY)
    MESSAGE(SEND_ERROR "Squirrel not found")
ENDIF(NOT SQUIRREL_LIBRARY)

FIND_LIBRARY(SQUIRREL_STD_LIBRARY NAMES sqstdlib PATH_SUFFIXES squirrel)
IF(NOT SQUIRREL_STD_LIBRARY)
    MESSAGE(SEND_ERROR "Squirrel not found")
ENDIF(NOT SQUIRREL_STD_LIBRARY)

IF(SQUIRREL_INCLUDE_DIR AND SQUIRREL_STD_LIBRARY)
   SET(SQUIRREL_FOUND TRUE)
ENDIF(SQUIRREL_INCLUDE_DIR AND SQUIRREL_STD_LIBRARY)

IF(SQUIRREL_FOUND)
   IF (NOT Squirrel_FIND_QUIETLY)
	   MESSAGE(STATUS "Found Squirrel: ${SQUIRREL_LIBRARY}, ${SQUIRREL_STD_LIBRARY}")
   ENDIF (NOT Squirrel_FIND_QUIETLY)
ELSE(SQUIRREL_FOUND)
   IF (Squirrel_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find Squirrel")
   ENDIF (Squirrel_FIND_REQUIRED)
ENDIF(SQUIRREL_FOUND)
