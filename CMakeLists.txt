cmake_minimum_required(VERSION 3.16)
project(cpp_algorithm)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party/googletest)
include_directories(
            third_party/googletest/googletest/include
            third_party/googletest/googlemock/include)


enable_testing()
add_executable(TestSort src/sort/TestMain.cpp)
add_executable(TestMath src/math/test.cpp)

target_link_libraries(TestSort gtest_main gtest)
target_link_libraries(TestMath gtest_main gtest)
include(GoogleTest)
gtest_discover_tests(TestSort)
