FIND_PATH(FREETYPE2_INCLUDE_DIR freetype2)

FIND_LIBRARY(FREETYPE2_LIBRARY NAMES freetype)
IF(NOT FREETYPE2_LIBRARY)
    MESSAGE(SEND_ERROR "Freetype2 not found")
ENDIF(NOT FREETYPE2_LIBRARY)

IF(FREETYPE2_INCLUDE_DIR AND FREETYPE2_LIBRARY)
   SET(FREETYPE2_FOUND TRUE)
ENDIF(FREETYPE2_INCLUDE_DIR AND FREETYPE2_LIBRARY)

IF(FREETYPE2_FOUND)
   IF (NOT Freetype2_FIND_QUIETLY)
      MESSAGE(STATUS "Found Freetype2: ${FREETYPE2_LIBRARY}")
   ENDIF (NOT Freetype2_FIND_QUIETLY)
ELSE(FREETYPE2_FOUND)
   IF (Freetype2_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find Freetype2")
   ENDIF (Freetype2_FIND_REQUIRED)
ENDIF(FREETYPE2_FOUND)