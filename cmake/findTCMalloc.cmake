# - Try to find TCMALLOC
#
# The following variables are optionally searched for defaults
#  TCMALLOC_ROOT_DIR:            Base directory where all TCMALLOC components are found
#
# The following are set after configuration is done:
#  TCMALLOC_FOUND
#  TCMALLOC_INCLUDE_DIRS
#  TCMALLOC_LIBRARIES
#  TCMALLOC_LIBRARYRARY_DIRS

include(FindPackageHandleStandardArgs)

set(TCMALLOC_ROOT_DIR "" CACHE PATH "Folder contains JsonCpp")

# We are testing only a couple of files in the include directories
if(WIN32)
    find_path(TCMALLOC_INCLUDE_DIR gperftools/tcmalloc.h
        PATHS ${TCMALLOC_ROOT_DIR}/src/windows)
else()
    find_path(TCMALLOC_INCLUDE_DIR gperftools/tcmalloc.h
        PATHS ${TCMALLOC_ROOT_DIR})
endif()

if(MSVC)
    find_library(TCMALLOC_LIBRARY_RELEASE
        NAMES libtcmalloc
        PATHS ${TCMALLOC_ROOT_DIR}
        PATH_SUFFIXES Release)

    find_library(TCMALLOC_LIBRARY_DEBUG
        NAMES libtcmalloc-debug
        PATHS ${TCMALLOC_ROOT_DIR}
        PATH_SUFFIXES Debug)

    set(TCMALLOC_LIBRARY optimized ${TCMALLOC_LIBRARY_RELEASE} debug ${TCMALLOC_LIBRARY_DEBUG})
else()
    find_library(TCMALLOC_LIBRARY tcmalloc)
endif()

find_package_handle_standard_args(tcmalloc DEFAULT_MSG TCMALLOC_INCLUDE_DIR TCMALLOC_LIBRARY)


if(TCMALLOC_FOUND)
    set(TCMALLOC_INCLUDE_DIRS ${TCMALLOC_INCLUDE_DIR})
    set(TCMALLOC_LIBRARIES ${TCMALLOC_LIBRARY})
    message(STATUS "Found TCMALLOC (include: ${TCMALLOC_INCLUDE_DIR}, library: ${TCMALLOC_LIBRARY})")
    mark_as_advanced(TCMALLOC_LIBRARY_DEBUG TCMALLOC_LIBRARY_RELEASE
                     TCMALLOC_LIBRARY TCMALLOC_INCLUDE_DIR TCMALLOC_ROOT_DIR)
endif()
