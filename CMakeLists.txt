cmake_minimum_required(VERSION 3.11)
project(engineering_code)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory("third_party/googletest")

FILE(GLOB TEST_SRCS "src/*_test.cc")

foreach(testSrc ${TEST_SRCS})
  get_filename_component(testName ${testSrc} NAME_WE)
  add_executable(${testName} ${testSrc})

  target_link_libraries(${testName} gtest gtest_main)

  string(REGEX MATCH "(offer_)?[0-9_]+"
    testNumber ${testName})

  add_test(NAME ${testNumber}
    COMMAND ${testName}
  )
endforeach(testSrc)

FILE(GLOB TEST_UTILITY "src/utility/*_test.cc")

foreach(testSrc ${TEST_UTILITY})
  get_filename_component(testName ${testSrc} NAME_WE)
  add_executable(${testName} ${testSrc})

  target_link_libraries(${testName} gtest gtest_main)

  add_test(NAME ${testName}
    COMMAND ${testName}
  )
endforeach(testSrc)