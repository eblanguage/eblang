#pragma once

#include <array>
#include <stack>
#include <vector>

#include "systemcall.hpp"

namespace eblang {
class VM {
 private:
  std::array<std::uintptr_t, 4> registers{};
  std::vector<std::uint8_t> bytecode{};
  std::stack<std::uint8_t> stack{};
  std::stack<std::uintptr_t> call_stack{};
  std::vector<std::uint8_t> heap;
  std::uintptr_t pc{};

 public:
  VM();

  void Execute(std::vector<std::uint8_t> code);

  void SystemCall(SYSTEMCALL type);
};
}  // namespace eblang
