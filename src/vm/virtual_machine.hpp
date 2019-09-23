#ifndef VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP

#include "state.hpp"
#include "type.hpp"
#include "executor/executor.hpp"
#include <string>
#include <stack>
#include <vector>

typedef unsigned int Bytecode;
typedef unsigned short ReturnCode;

class VirtualMachine {
private:
    friend class Executor;
    const std::vector<Bytecode> program;
    State state;
    Executor executor;
    std::stack<Type*> stack;

    explicit VirtualMachine(std::vector<Bytecode>);

    bool instructionPointerIsOutOfBound();
public:
    static VirtualMachine* initializeWith(const std::vector<Bytecode> &program);
    void run();
    void stop(ReturnCode);
    Bytecode advanceInstruction();
    bool isRunning();
};


#endif //VIRTUAL_MACHINE_VIRTUAL_MACHINE_HPP
