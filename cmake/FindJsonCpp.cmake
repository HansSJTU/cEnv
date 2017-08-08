# - Try to find JSONCPP
#
# The following variables are optionally searched for defaults
#  JSONCPP_ROOT_DIR:            Base directory where all JSONCPP components are found
#
# The following are set after configuration is done:
#  JSONCPP_FOUND
#  JSONCPP_INCLUDE_DIRS
#  JSONCPP_LIBRARIES
#  JSONCPP_LIBRARYRARY_DIRS

include(FindPackageHandleStandardArgs)

set(JSONCPP_ROOT_DIR "" CACHE PATH "Folder contains JsonCpp")

# We are testing only a couple of files in the include directories
if(WIN32)
    find_path(JSONCPP_INCLUDE_DIR jsoncpp/json/json.h
        PATHS ${JSONCPP_ROOT_DIR}/src/windows)
else()
    find_path(JSONCPP_INCLUDE_DIR jsoncpp/json/json.h
        PATHS ${JSONCPP_ROOT_DIR})
endif()

if(MSVC)
    find_library(JSONCPP_LIBRARY_RELEASE
        NAMES libjsoncpp
        PATHS ${JSONCPP_ROOT_DIR}
        PATH_SUFFIXES Release)

    find_library(JSONCPP_LIBRARY_DEBUG
        NAMES libjsoncpp-debug
        PATHS ${JSONCPP_ROOT_DIR}
        PATH_SUFFIXES Debug)

    set(JSONCPP_LIBRARY optimized ${JSONCPP_LIBRARY_RELEASE} debug ${JSONCPP_LIBRARY_DEBUG})
else()
    find_library(JSONCPP_LIBRARY jsoncpp
        PATHS ${JSONCPP_ROOT_DIR})
endif()

find_package_handle_standard_args(JsonCpp DEFAULT_MSG JSONCPP_INCLUDE_DIR JSONCPP_LIBRARY)


if(JSONCPP_FOUND)
    set(JSONCPP_INCLUDE_DIRS ${JSONCPP_INCLUDE_DIR})
    set(JSONCPP_LIBRARIES ${JSONCPP_LIBRARY})
    message(STATUS "Found jsoncpp  (include: ${JSONCPP_INCLUDE_DIR}, library: ${JSONCPP_LIBRARY})")
    mark_as_advanced(JSONCPP_LIBRARY_DEBUG JSONCPP_LIBRARY_RELEASE
                     JSONCPP_LIBRARY JSONCPP_INCLUDE_DIR JSONCPP_ROOT_DIR)
endif()
