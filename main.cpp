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
    Deque d;

    d.push_back(10);
    d.push_back(20);
    d.push_front(5);

    cout << d.front() << endl; 
    cout << d.back() << endl; 
    cout << d.size() << endl;
    d.pop_front();
    cout << d.front() << endl; 
    d.pop_back();
    cout << d.back() << endl; 

}