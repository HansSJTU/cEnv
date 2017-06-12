cmake_minimum_required( VERSION 2.8 )

PROJECT( TEST )

# opencv
find_package(OpenCV REQUIRED)
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})
list(APPEND LINKER_LIBS ${OpenCV_LIBS})
message("-- OpenCV version: ${OpenCV_VERSION}")

# boost
FIND_PACKAGE(Boost REQUIRED COMPONENTS
    regex
    filesystem
    system
)
include_directories(SYSTEM ${Boost_INCLUDE_DIR})
list(APPEND LINKER_LIBS ${Boost_LIBRARIES})
if (NOT Boost_FOUND)
  message("cann't find Boost!")
endif()

# glog
include("cmake/FindGlog.cmake")
include_directories(SYSTEM ${GLOG_INCLUDE_DIRS})
list(APPEND LINKER_LIBS ${GLOG_LIBRARIES})

# gflags
include("cmake/FindGFlags.cmake")
include_directories(SYSTEM ${GFLAGS_INCLUDE_DIRS})
list(APPEND LINKER_LIBS ${GFLAGS_LIBRARIES})

# jsoncpp
include("cmake/FindJsonCpp.cmake")
include_directories(SYSTEM ${JSONCPP_INCLUDE_DIRS})
list(APPEND LINKER_LIBS ${JSONCPP_LIBRARIES})

# openmp
FIND_PACKAGE(OpenMP REQUIRED)
if(OPENMP_FOUND)
    message("-- Found openmp")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
else()
    message(FATAL "openmp not found")
endif()

# use c++ 11
add_compile_options(-std=c++11)

ADD_EXECUTABLE(test test.cpp)

target_link_libraries(test ${LINKER_LIBS})
