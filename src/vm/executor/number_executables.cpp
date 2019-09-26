#include <cmath>
#include "executor.hpp"
#include "virtual_machine.hpp"

void Executor::loadNumber(VirtualMachine *vm) {
    Type *number = new Type(static_cast<float>(vm->advanceInstruction()));

    vm->stack.push(number);
}

void Executor::addNumber(VirtualMachine *vm) {
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value + secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::multiplyNumber(VirtualMachine *vm) {
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value * secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::divideNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value / secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::subtractNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value - secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::modNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(static_cast<float>(std::fmod(firstNumber->number_value, secondNumber->number_value))));

    free(firstNumber);
    free(secondNumber);
}

void Executor::equalNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value == secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::notEqualNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value != secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::greaterThanNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value > secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::greaterEqualThanNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value >= secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::lessThanNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value < secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::lessEqualThanNumber(VirtualMachine *vm){
    Type* firstNumber = vm->stack.top();
    vm->stack.pop();

    Type* secondNumber = vm->stack.top();
    vm->stack.pop();

    vm->stack.push(new Type(firstNumber->number_value <= secondNumber->number_value));

    free(firstNumber);
    free(secondNumber);
}

void Executor::printNumber(VirtualMachine *vm) {
    Type *const number = vm->stack.top();
    vm->stack.pop();

    std::cout << number->number_value << std::endl;

    free(number);
}