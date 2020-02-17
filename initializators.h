#pragma once
#include "include_glfw.h"
#include "error_handle.h"
#include <cassert>

void initialize_glfw(); 
void setup_glad(); 

template<typename T>
auto setup_window(const int width, const int height, T framebuffer_size_change_callback) {
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)
  assert(width > 0);
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)
  assert(height > 0);

  auto window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);

  ErrorHandling::handle_error(window == nullptr, "Failed to create GLFW window");

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_change_callback);

  return window;
}

namespace Initializators {
  template<typename T>
    GLFWwindow* bootstrap_window(const int width, const int height, T framebuffer_size_change_callback) {
      initialize_glfw();
      auto window = setup_window(width, height, framebuffer_size_change_callback);
      setup_glad();

      return window;
    }

  GLuint setup_shaders(); 
}
