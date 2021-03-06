#include <iostream>
#include <object/object.hpp>
#include "memory.hpp"

Memory Memory::createWithSize(uint16_t bytes) {
    return Memory(bytes);
}

Memory::Memory(uint16_t size) {
    this->resize(size);
    this->allocate({0}); // Use first byte of memory for null value
}

void Memory::resize(uint16_t toSize){
    this->block.resize(toSize);
}

uint16_t Memory::allocate(std::vector<uint16_t> bytes) {
    uint16_t sizeOfAllocation = bytes.size();
    uint16_t numberOfFreeBytesInARow = 0;
    uint16_t memoryIndex = 0;

    while(numberOfFreeBytesInARow != sizeOfAllocation) {
        if(this->block.size() <= memoryIndex) {
            this->resize(this->block.size() + sizeOfAllocation - numberOfFreeBytesInARow);
        }

        if(!this->block[memoryIndex++].isAllocated()) {
            numberOfFreeBytesInARow++;
        } else {
            numberOfFreeBytesInARow = 0;
        }
    }

    auto startingPointer = memoryIndex - sizeOfAllocation;

    for(size_t i = startingPointer;i<memoryIndex;i++) {
        this->block[i].write(bytes.front());
        bytes.erase(bytes.begin(), bytes.begin() + 1);
    }

    return startingPointer;
}

void Memory::freeAt(uint16_t offset, uint16_t sizeOfDeletion) {
    uint16_t endOfDeletionIndex = offset + sizeOfDeletion;

    for(uint16_t index = offset;index<endOfDeletionIndex;index++) {
        this->block[index].free();
    }
}

void Memory::dump() {
    for(auto & chunk : this->block) {
        if(chunk.isAllocated()) {
            std::cout << chunk.read() << std::endl;
        }
    }
}

std::string Memory::stringFrom(Object memoryInformation) {
    std::string assembledString;
    for(int i = memoryInformation.startingPoint; i < memoryInformation.startingPoint + memoryInformation.length; i++) {
        assembledString.push_back(this->block[i].read());
    }

    return assembledString;
}

std::vector<uint16_t> Memory::readAt(uint16_t startingPoint, uint16_t length) {
    std::vector<uint16_t> readMemory{};
    for(int i = startingPoint; i < startingPoint+length; i++) {
        readMemory.push_back(this->block[i].read());
    }

    return readMemory;
}

void Memory::updateAt(uint16_t offset, std::vector<uint16_t> bytesToStore) {
    for(int i = offset + bytesToStore.size() - 1;i >= offset; i--) {
        this->block[i].write(bytesToStore.back());
        bytesToStore.pop_back();
    }
}
