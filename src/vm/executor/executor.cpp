#include "executor.hpp"
#include "../virtual_machine.hpp"

Executor::Executor() {
    this->executables[LOAD_NUMBER] = Executor::loadNumber;
    this->executables[PRINT_NUMBER] = Executor::printNumber;
    this->executables[ADD_NUMBER] = Executor::addNumber;
    this->executables[MULTIPLY_NUMBER] = Executor::multiplyNumber;
    this->executables[DIVIDE_NUMBER] = Executor::divideNumber;
    this->executables[SUBTRACT_NUMBER] = Executor::subtractNumber;
    this->executables[MOD_NUMBER] = Executor::modNumber;
    this->executables[POW_NUMBER] = Executor::powNumber;
    this->executables[EQUAL_NUMBER] = Executor::equalNumber;
    this->executables[GREATER_THAN_NUMBER] = Executor::greaterThanNumber;
    this->executables[GREATER_THAN_EQUAL_NUMBER] = Executor::greaterEqualThanNumber;

    this->executables[LOAD_BOOLEAN] = Executor::loadBoolean;
    this->executables[EQUAL_BOOLEAN] = Executor::equalBoolean;
    this->executables[PRINT_BOOLEAN] = Executor::printBoolean;

    this->executables[LOAD_STRING] = Executor::loadString;
    this->executables[APPEND_STRING] = Executor::appendString;
    this->executables[SUBSTRING_AT] = Executor::substringAt;
    this->executables[SUBSTRING_WITH_LENGTH] = Executor::substringWithLength;
    this->executables[PRINT_STRING] = Executor::printString;

    this->executables[JUMP_TRUE] = Executor::jumpIfTrue;
    this->executables[JUMP_FALSE] = Executor::jumpIfFalse;
    this->executables[JUMP] = Executor::jump;

    this->executables[STORE_GLOBAL] = Executor::storeGlobal;
    this->executables[LOAD_GLOBAL] = Executor::loadGlobal;

    this->executables[STORE_LOCAL] = Executor::storeLocal;
    this->executables[LOAD_LOCAL] = Executor::loadLocal;

    this->executables[DECLARE_FUNCTION] = Executor::declareFunction;
    this->executables[CALL_FUNCTION] = Executor::callFunction;
    this->executables[RETURN] = Executor::doReturn;

    this->executables[DECLARE_OBJECT] = Executor::declareObject;
    this->executables[DECLARE_OBJECT_ATTRIBUTE] = Executor::declareObjectAttribute;
    this->executables[DELETE_OBJECT] = Executor::deleteObject;
    this->executables[STORE_ATTRIBUTE] = Executor::storeAttribute;
    this->executables[LOAD_ATTRIBUTE] = Executor::loadAttribute;
    this->executables[LOAD_OBJECT] = Executor::loadObject;

    this->executables[HALT] = Executor::halt;
}


void Executor::execute(VirtualMachine *vm, const uint8_t *operation) const {
    this->executables.at(*operation)(vm);
}

void Executor::jump(VirtualMachine* vm) {
    uint16_t jumpInstructionPointer = vm->advanceInstruction();

    vm->setInstructionPointerTo(jumpInstructionPointer);
}

void Executor::halt(VirtualMachine *vm) {
    vm->stop(0);
}
