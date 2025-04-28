/**
* @file library.h
* @author Christian McKenzie
* @author Tyson Arnold
* @date 2025-04-25
* @brief Deque
* 
*/

#include "deque.h"
#include <iostream>

Deque::Deque() {
    blockSize = 8;
    blockCount = 4;
    blockmap = new int*[blockCount];
    for (int i = 0; i < blockCount; i++) {
        blockmap[i] = new int[blockSize];
    }
    frontBlock = blockCount / 2;
    backBlock = frontBlock;
    frontIndex = blockSize / 2;
    backIndex = frontIndex - 1;
    count = 0;
}

Deque::~Deque() {
    for (int i = 0; i < blockCount; i++) {
        delete[] blockmap[i];
    }
    delete[] blockmap;
}

void Deque::growFront() {
    if (frontIndex == 0 && frontBlock == 0) {
        growBlockmap();
    }
    if(frontIndex == 0){
        frontBlock--;
        frontIndex = blockSize;
    }
}

void Deque::growBack() {
    if (backIndex == blockSize - 1 && backBlock == blockCount - 1) {
        growBlockmap();
    }
    if(backIndex == blockSize - 1){
        backBlock++;
        backIndex = -1;
    }
}

void Deque::growBlockmap() {
    int newBlockCount = blockCount * 2;
    int** newBlockmap = new int*[newBlockCount];

    for(int i = 0; i < newBlockCount; i++){
        newBlockmap[i] = new int[blockSize];
    }

    int shift = (newBlockCount - blockCount) / 2;

    for(int i = 0; i < blockCount; i++){
        for(int j = 0; j < blockSize; j++){
            newBlockmap[i + shift][j] = blockmap[i][j];
        }
    }

    for(int i = 0; i < blockCount; i++){
        delete[] blockmap[i];
    }
    delete[] blockmap;

    blockmap = newBlockmap;
    frontBlock += shift;
    backBlock += shift;
    blockCount = newBlockCount;
}

void Deque::push_front(int value) {
    if (frontIndex == 0) {
        growFront();
    }
    frontIndex--;
    blockmap[frontBlock][frontIndex] = value;
    count++;
}

void Deque::push_back(int value) {
    if (backIndex == blockSize - 1) {
        growBack();
    }
    backIndex++;
    blockmap[backBlock][backIndex] = value;
    count++;
}

void Deque::pop_front() {
    if (!empty()) {
        frontIndex++;
        if(frontIndex >= blockSize) {
            frontBlock++;
            frontIndex = 0;
        }
        count--;
    }
}

void Deque::pop_back() {
    if (!empty()) {
        backIndex--;
        if(backIndex < 0) {
            backBlock--;
            backIndex = blockSize - 1;
        }
        count--;
    }
}

int Deque::front() {
    return blockmap[frontBlock][frontIndex];
}

int Deque::back() {
    return blockmap[backBlock][backIndex];
}

bool Deque::empty() {
    return count == 0;
}

int Deque::size() {
    return count;
}

int& Deque::operator[](int index) {
    int absoluteFront = frontBlock * blockSize + frontIndex;
    int absoluteIndex = absoluteFront + index;
    int block = absoluteIndex / blockSize;
    int indexInBlock = absoluteIndex % blockSize;
    return blockmap[block][indexInBlock];
}
