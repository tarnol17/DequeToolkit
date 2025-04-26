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

void Deque::push_front(int value) {
    frontIndex--;
    if (frontIndex < 0) {

    }
    blockmap[0][frontIndex] = value;
    count++;
}

void Deque::push_back(int value) {
    backIndex++;
    if (backIndex >= blockSize) {

    }
    blockmap[0][backIndex] = value;
    count++;
}


void Deque::pop_front() {
    if (!empty()) {
        frontIndex++;
        count--;
    }
}

void Deque::pop_back() {
    if (!empty()) {
        backIndex--;
        count--;
    }
}

int Deque::front() {
    return blockmap[0][frontIndex];
}

int Deque::back() {
    return blockmap[0][backIndex];
}

bool Deque::empty() {
    return count == 0;
}

int Deque::size() {
    return count;
}

int& Deque::operator[](int index) {
    return blockmap[0][frontIndex + index];
}
