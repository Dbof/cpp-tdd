add_library (TestThis whattotest.cpp whattotest.h)
add_executable (demo main.cpp)
target_link_libraries (demo TestThis)
