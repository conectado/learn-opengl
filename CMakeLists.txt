cmake_minimum_required(VERSION 3.10)

project(LearnOpenGL VERSION 1.0)

find_program(CLANG_C_COMPILER clang)
find_program(CLANG_CXX_COMPILER clang++)
if(CLANG_COMPILER AND CLANG_CXX_COMPILER)
  message(STATUS "Found Clang compiler: will default to use Clang")
  SET(CMAKE_C_COMPILER ${CLANG_C_COMPILER})
  SET(CMAKE_CXX_COMPILER ${CLANG_CXX_COMPILER})
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(third-parties)
list(APPEND EXTRA_LIBS GLAD)

configure_file(config.h.in config.h)
add_executable(LearnOpenGL main.cpp)

find_program(CLANG_TIDY clang-tidy)
if(CLANG_TIDY)
  message(STATUS "Found clang-tidy: will perform all checks")
  SET(DO_CLANG_TIDY "${CLANG_TIDY}" "-checks=*")
  set_target_properties(LearnOpenGL PROPERTIES CXX_CLANG_TIDY "${DO_CLANG_TIDY}")
endif()


# Use GLVND instead of GL for find_opengl
# when both are available
cmake_policy(SET CMP0072 NEW)

# Let's use the installed packages for now
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(LearnOpenGL PUBLIC ${EXTRA_LIBS} glfw OpenGL::GL -lpthread -ldl)
target_include_directories(LearnOpenGL PUBLIC "${PROJECT_BINARY_DIR}")
