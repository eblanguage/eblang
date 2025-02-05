#include <eblang/vm/vm.hpp>
#include <iostream>

int main() {
  eblang::VM vm;

  try {
    vm.Execute({
        // clang-format off

        // Mov
        123, // dump (test)
        0x1, 1, 14, // mov 1 228 
        123, // dump

        // Jump
        0x1, 2, 2, // mov 2 1
        0x4, 1, 2, // mul 1 2
        123, // dump
        0x7, 15, // jmp 15
        0x12,// unknown instruction
        0x1, 3, 7, // mov 3 1
        123, // dump

        // Stack
        0x1, 0, 5, // mov 0 5
        0x1, 1, 8, // mov 1 8
        0xA, 0, // push 0
        0xA, 1, // push 1
        0xB, 2, // pop 2
        0xB, 3, // pop 3
        123, // dump

        // Call
        123, // dump
        0x1, 0, 9, // mov 0 3
        0xA, 0, // push 0
        0x8, 43, // call 43 (Mark)
        0x12, // unknown instruction

        // Mark
        0x1, 0, 0, // mov 0 0
        0xB, 3, // pop 3
        123, // dump
        0x9, // ret
        

        // // System call
        // 0xA, 0, // push 0
        // 0xC, 0x0, // system call

        // clang-format on
    });
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}