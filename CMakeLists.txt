# Path to the Google Test source directory
set(GTEST_DIR path/to/gtest)

# Add the Google Test library
add_subdirectory(${GTEST_DIR})
include_directories(${GTEST_DIR}/include)

# Your project's executable(s)
add_executable(your_project_executable main.cpp)

# Link your project with the Google Test library
target_link_libraries(your_project_executable gtest_main)
