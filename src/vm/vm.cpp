#include "eblang/vm/vm.hpp"

#include <iostream>
#include <string>

#include "eblang/vm/opcodes.hpp"

namespace eblang {
VM::VM() {}

void VM::Execute(std::vector<std::uint8_t> bytecode) {
  while (pc < bytecode.size()) {
    std::uint8_t instruction = bytecode[pc++];
    switch (instruction) {
      // dump
      case OP_DUMP: {
        std::cout << "PC: " << pc << " | " << "r0: " << registers[0]
                  << " r1: " << registers[1] << " r2: " << registers[2] << " "
                  << "r3: " << registers[3] << std::endl;
        break;
      }

      // Arithmetic operations
      case OP_MOV: {
        auto dest = bytecode[pc++];
        auto value = bytecode[pc++];
        registers[dest] = value;
        break;
      }
      case OP_ADD: {
        auto dest = bytecode[pc++];
        auto value = registers[bytecode[pc++]];
        registers[dest] += value;
        break;
      }
      case OP_SUB: {
        auto dest = bytecode[pc++];
        auto value = registers[bytecode[pc++]];
        registers[dest] -= value;
        break;
      }
      case OP_MUL: {
        auto dest = bytecode[pc++];
        auto value = registers[bytecode[pc++]];
        break;
      }
      case OP_DIV: {
        auto dest = bytecode[pc++];
        auto value = registers[bytecode[pc++]];
        registers[dest] /= value;
        break;
      }
      case OP_MOD: {
        auto dest = bytecode[pc++];
        auto value = registers[bytecode[pc++]];
        registers[dest] %= value;
        break;
      }

      // Procedure call operations
      case OP_JMP: {
        pc = bytecode[pc++];
        break;
      }
      case OP_CALL: {
        call_stack.push(pc + 1);
        pc = bytecode[pc];
        break;
      }
      case OP_RET: {
        pc = call_stack.top();
        call_stack.pop();
        break;
      }
      case OP_HALT: {
        return;
      }

      // Stack operations
      case OP_PUSH: {
        stack.push(registers[bytecode[pc++]]);
        break;
      }
      case OP_POP: {
        registers[bytecode[pc++]] = stack.top();
        stack.pop();
        break;
      }
      case OP_SYSCALL: {
        auto value = static_cast<SYSTEMCALL>(bytecode[pc++]);
        SystemCall(value);
      }
      default:
        throw std::runtime_error("Unknown instruction");
        break;
    }
  }
}

void VM::SystemCall(SYSTEMCALL type) {
  switch (type) {
    case SYSTEMCALL::SYSTEMCALL_COUT: {
      std::cout << std::to_string(stack.top()) << std::endl;
      stack.pop();
    } break;
    case SYSTEMCALL::SYSTEMCALL_CIN: {
      std::cin >> stack.top();
    } break;
    default:
      throw std::runtime_error("Unknown system call");
      break;
  }
}
}  // namespace eblang