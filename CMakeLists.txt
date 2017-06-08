cmake_minimum_required( VERSION 2.8 )

PROJECT( TEST )

find_package( gflags REQUIRED )

ADD_EXECUTABLE(test test.cpp)

target_link_libraries(test gflags)
