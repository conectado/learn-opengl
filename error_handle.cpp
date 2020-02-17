#include "error_handle.h"
#include <array>
#include <iostream>
#include <string_view>

void log_and_terminate(const std::string& error_text) {
  std::cerr << error_text << std::endl;
  glfwTerminate();
  std::exit(1);
}

template<typename L>
void handle_error(bool condition, const std::string& error_text, L get_error_message) {
    if (condition) {
    log_and_terminate(error_text + get_error_message());
  }
}

void ErrorHandling::handle_error(bool condition, const std::string& error_text) {
  ::handle_error(condition, error_text, []{return std::string{""};});
}

void ErrorHandling::handle_shader_error(GLuint shader, GLenum shader_operation) {
  int success;
  glGetShaderiv(shader, shader_operation, &success);

  auto error_handle_function = [shader]{ 
    constexpr auto gl_infolog_len = 512; // TODO(conectado): Check if there is an OpenGL constant for this number
    std::array<char, gl_infolog_len> infolog{};
    glGetShaderInfoLog(shader, gl_infolog_len, nullptr, infolog.data());
    auto infolog_view = std::string(infolog.data());
    return infolog_view;
  };

  ::handle_error(success == 0, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n", error_handle_function);
}
