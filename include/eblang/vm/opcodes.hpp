#pragma once

#include <cstdint>

namespace eblang {
enum : std::uint8_t {
  OP_DUMP = 123,
  OP_HALT = 0x00,
  OP_MOV = 0x01,
  OP_ADD = 0x02,
  OP_SUB = 0x03,
  OP_MUL = 0x04,
  OP_DIV = 0x05,
  OP_MOD = 0x06,
  OP_JMP = 0x07,
  OP_CALL = 0x08,
  OP_RET = 0x09,
  OP_PUSH = 0x0A,
  OP_POP = 0x0B,
  OP_SYSCALL = 0x0C
};
}