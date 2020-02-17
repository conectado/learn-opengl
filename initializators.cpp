#include "initializators.h"
#include "shaders.h"
#include <array>

void initialize_glfw() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void setup_glad() {

  // We need reinterpret_cast to convert glfw's proc adress to a GLAD proc
  ErrorHandling::handle_error(gladLoadGLLoader(
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
        reinterpret_cast<GLADloadproc>(glfwGetProcAddress)) == 0, 
      "Failed to initialize GLAD"
      );
}

template<typename T>
void attach_shader(GLenum shader_type, const T& shader_source, const GLuint& shader_program) {

  const auto shader = glCreateShader(shader_type);
  glShaderSource(shader, 1, &shader_source, nullptr);
  glCompileShader(shader);
  ErrorHandling::handle_shader_error(shader, GL_COMPILE_STATUS);

  glAttachShader(shader_program, shader);
  glDeleteShader(shader_program);
}

void link_shader_program(const GLuint& shader_program) {
  glLinkProgram(shader_program);
  ErrorHandling::handle_shader_error(shader_program, GL_LINK_STATUS);
} 

GLuint Initializators::setup_shaders() {
  auto shader_program = glCreateProgram();
  attach_shader(GL_VERTEX_SHADER, vertex_shader_source, shader_program);
  attach_shader(GL_FRAGMENT_SHADER, fragment_shader_source, shader_program);
  glLinkProgram(shader_program);


  return shader_program;
}
