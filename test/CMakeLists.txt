# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${TEST_SOURCE_DIR}/src)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests timertest)
target_link_libraries(runTests Timer ${GTEST_LIBRARIES} pthread)
