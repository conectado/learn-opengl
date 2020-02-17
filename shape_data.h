#pragma once
#include <array>

constexpr auto vertices = std::array{
  0.5F,  0.2F, 0.0F,
    0.256F, -0.4F, 0.25555F, 
    -0.9F, -0.5F, 0.2F, 
    -0.4F,  0.5F, 0.0F
};

constexpr auto indices = std::array{
  0U, 1U, 2U,
    0U, 1U, 2U,
};
