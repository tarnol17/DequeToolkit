/**
* @file library.h
* @author Christian McKenzie
* @author Tyson Arnold
* @date 2025-04-25
* @brief Deque
* 
*/

#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    int** blockmap;
    int blockSize;
    int blockCount;
    int frontIndex;
    int backIndex;
    int numElements;

public:
    Deque();
    ~Deque();

    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();

    int front();
    int back();
    bool empty();
    int size();
    int& operator[](int index);
};
#endif