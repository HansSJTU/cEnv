cmake_minimum_required( VERSION 2.8 )

PROJECT( TEST )

# glog  
include("cmake/FindGlog.cmake")  
include_directories(SYSTEM ${GLOG_INCLUDE_DIRS})  
list(APPEND LINKER_LIBS ${GLOG_LIBRARIES})  

# gflags  
include("cmake/FindGFlags.cmake")  
include_directories(SYSTEM ${GFLAGS_INCLUDE_DIRS})  
list(APPEND LINKER_LIBS ${GFLAGS_LIBRARIES})  

ADD_EXECUTABLE(test test.cpp)

target_link_libraries(test ${LINKER_LIBS})
