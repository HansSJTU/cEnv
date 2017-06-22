# - Try to find PROFILER
#
# The following variables are optionally searched for defaults
#  PROFILER_ROOT_DIR:            Base directory where all PROFILER components are found
#
# The following are set after configuration is done:
#  PROFILER_FOUND
#  PROFILER_INCLUDE_DIRS
#  PROFILER_LIBRARIES
#  PROFILER_LIBRARYRARY_DIRS

include(FindPackageHandleStandardArgs)

set(PROFILER_ROOT_DIR "" CACHE PATH "Folder contains JsonCpp")

# We are testing only a couple of files in the include directories
if(WIN32)
    find_path(PROFILER_INCLUDE_DIR gperftools/profiler.h
        PATHS ${PROFILER_ROOT_DIR}/src/windows)
else()
    find_path(PROFILER_INCLUDE_DIR gperftools/profiler.h
        PATHS ${PROFILER_ROOT_DIR})
endif()

if(MSVC)
    find_library(PROFILER_LIBRARY_RELEASE
        NAMES libprofiler
        PATHS ${PROFILER_ROOT_DIR}
        PATH_SUFFIXES Release)

    find_library(PROFILER_LIBRARY_DEBUG
        NAMES libprofiler-debug
        PATHS ${PROFILER_ROOT_DIR}
        PATH_SUFFIXES Debug)

    set(PROFILER_LIBRARY optimized ${PROFILER_LIBRARY_RELEASE} debug ${PROFILER_LIBRARY_DEBUG})
else()
    find_library(PROFILER_LIBRARY profiler)
endif()

find_package_handle_standard_args(profiler DEFAULT_MSG PROFILER_INCLUDE_DIR PROFILER_LIBRARY)


if(PROFILER_FOUND)
    set(PROFILER_INCLUDE_DIRS ${PROFILER_INCLUDE_DIR})
    set(PROFILER_LIBRARIES ${PROFILER_LIBRARY})
    message(STATUS "Found GProfiler (include: ${PROFILER_INCLUDE_DIR}, library: ${PROFILER_LIBRARY})")
    mark_as_advanced(PROFILER_LIBRARY_DEBUG PROFILER_LIBRARY_RELEASE
                     PROFILER_LIBRARY PROFILER_INCLUDE_DIR PROFILER_ROOT_DIR)
endif()
