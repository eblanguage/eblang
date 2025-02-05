#pragma once

#include <cstdint>

namespace eblang {
enum : std::uint8_t {
  DTYPE_INTEGER,
  DTYPE_FLOAT,
  DTYPE_BOOLEAN,
  DTYPE_STRING,
};
}