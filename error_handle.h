#pragma once
#include "include_glfw.h"
#include <string>

namespace ErrorHandling {
  void handle_error(bool condition, const std::string& error_text); 
  void handle_shader_error(GLuint shader, GLenum shader_operation);
}
