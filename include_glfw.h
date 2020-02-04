// Use this file to include GLFW3 and prevent
// Problems with glad, since glad should be included before
// glfw3 because glfw3 includes gl.h and whence glad encounters
// that it is already included, it throws an error(I don't really know why and that sucks)
#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
