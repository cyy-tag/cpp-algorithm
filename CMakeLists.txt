cmake_minimum_required(VERSION 3.27)
project(cpp_algorithm)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(third_party/googletest)
include_directories(
            third_party/googletest/googletest/include
            third_party/googletest/googlemock/include)


enable_testing()
add_executable(TestSort src/sort/TestMain.cpp)

target_link_libraries(TestSort gtest_main gtest)
include(GoogleTest)
gtest_discover_tests(TestSort)