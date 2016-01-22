add_library (Timer timer.cpp timer.h)
add_executable (demo main.cpp)
target_link_libraries (demo Timer)
