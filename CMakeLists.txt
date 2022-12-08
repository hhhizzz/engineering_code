cmake_minimum_required(VERSION 3.24)
project(engineering_code)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory("third_party/googletest")

FILE(GLOB TEST_SRCS "src/*_test.cc")

foreach(testSrc ${TEST_SRCS})
  get_filename_component(testName ${testSrc} NAME_WE)
  add_executable(${testName} ${testSrc})

  target_link_libraries(${testName} gmock gtest gtest_main)

  string(REGEX MATCH "(offer_)?[0-9]+"
    testNumber ${testName})

  add_test(NAME ${testNumber}
    COMMAND ${testName}
  )
endforeach(testSrc)