enable_testing()
add_executable(test test.cpp)
target_link_libraries(test PUBLIC type_conversion GTest::gtest GTest::gtest_main)
add_test(Test test)