#include "config.h"
#include "config_vars.h"
#include "draw_frame.h"
#include "error_handle.h"
#include "include_glfw.h"
#include "initializators.h"
#include "setup_vao.h"
#include "shape_data.h"
#include <cassert>
#include <tuple>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow *window);

int main() {
  const auto window = Initializators::bootstrap_window(WINDOW_WIDTH, WINDOW_HEIGHT, framebuffer_size_callback);
  const auto shader_program = Initializators::setup_shaders();
  const auto VAO = setup_vao();
  constexpr auto olive_green { std::make_tuple(0.2F, 0.3F, 0.3F, 1.0F) };

  while(!static_cast<bool>(glfwWindowShouldClose(window))) {
    process_input(window);
    glClearColor(std::get<0>(olive_green), std::get<1>(olive_green), std::get<2>(olive_green), std::get<3>(olive_green));
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader_program);

    draw_frame(VAO);

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

void process_input(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}
