#include "config.h"
#include "include_glfw.h"
#include <iostream>
#include <tuple>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);

// NOLINTNEXTLINE(modernize-use-trailing-return-type)
int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  const auto WINDOW_HEIGHT { 600 }; 
  const auto WINDOW_WIDTH  { 800 };

  auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", nullptr, nullptr);

  if (window == nullptr) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // We need reinterpret_cast to convert glfw's proc adress to a GLAD proc
  // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
  if (!static_cast<bool>(gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  while(!static_cast<bool>(glfwWindowShouldClose(window))) {
    processInput(window);

    const auto olive_green { std::make_tuple(0.2F, 0.3F, 0.3F, 1.0F) };

    glClearColor(std::get<0>(olive_green), std::get<1>(olive_green), std::get<2>(olive_green), std::get<3>(olive_green));
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return 0;
}

// This is a callback therefore some parameters might be unusued as  window !!Review this no lint each time the function is changed :(
// NOLINTNEXTLINE(misc-unused-parameters)
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}
