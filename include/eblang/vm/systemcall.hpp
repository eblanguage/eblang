#pragma once

#include <cstdint>

enum class SYSTEMCALL : std::uint8_t {
  SYSTEMCALL_COUT = 0x0,
  SYSTEMCALL_CIN = 0x1
};