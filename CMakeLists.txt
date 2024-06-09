cmake_minimum_required(VERSION 3.16)
project(cpp_algorithm)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party/googletest)
add_subdirectory(third_party/benchmark)
include_directories(
            third_party/googletest/googletest/include
            third_party/googletest/googlemock/include
            third_party/benchmark/include
            src/)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
link_libraries(gtest_main gtest benchmark::benchmark)
#compiler_command.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()
file(GLOB_RECURSE  SCPP_SRC_LIST "src/*.cpp")
foreach(v ${SCPP_SRC_LIST})
    # message(STATUS "test=${v}")
    string(REGEX MATCH "src/.*" relative_path ${v})
    string(REGEX REPLACE "src/" "" target_name ${relative_path})
    # message(STATUS "relative_path=${target_name}")
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})
    string(REGEX REPLACE "/|\\." "_" target_name ${target_name})
    # message(STATUS "relative_path=${target_name}")
    add_executable(${target_name} ${v})
endforeach()
