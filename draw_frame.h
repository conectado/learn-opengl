#include "include_glfw.h"
#include "shape_data.h"

void draw_frame(unsigned int VAO) {
    glBindVertexArray(VAO);
    // Note: indices.size() is constexpr so no performance loss here
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
