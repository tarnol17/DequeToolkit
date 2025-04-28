/**
 * @file main.cpp
 * @author Christian McKenzie
 * @author Tyson Arnold
 * @date 2025-04-25
 * @brief Main program for the Deque Toolkit
 * 
 * Interface for managing the deque toolkit.
 */

#include "deque.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Functional Test" << endl;
    Deque d;

    d.push_back(10);
    d.push_back(20);
    d.push_front(5);

    cout << "Front (Should be 5): " << d.front() << endl; 
    cout << "Back (Should be 20): "<< d.back() << endl; 
    cout << "Size (Should be 3): " << d.size() << endl;
    d.pop_front();
    cout << "Pop front (Should be 10): " << d.front() << endl; 
    d.pop_back();
    cout << "Pop Back (Should be 10): " << d.back() << endl; 

    //Now the real test
    cout << "Real Stress Test" << endl;
    Deque d2;

    const int num = 1000;

    // Push 1000 elements to the back
    for (int i = 0; i < num; i++) {
        d2.push_back(i);
    }

    // Push thousand elements to the front
    for (int i = 0; i < num; i++) {
        d2.push_front(i);
    }

    cout << "Front (Should be 999)" << d2.front() << endl;
    cout << "Back (Should be 999): " << d2.back() << endl;
    cout << "Size (Should be 2000): " << d2.size() << endl;

    // Pop 1000 elements from the front
    for (int i = 0; i < num; i++) {
        d2.pop_front();
    }

    cout << "Front after pops (Should be 0): " << d2.front() << endl;
    cout << "Back after pops (Should be 999): " << d2.back() << endl;
    cout << "Size after pops (Should be 1000): " << d2.size() << endl;

}