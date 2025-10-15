#pragma once
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

class Stack {
private:
    std::vector<int> elements; // Use a vector to store stack elements

public:
    bool isEmpty() const;     // Check if the stack is empty
    void push(int value);     // Push an integer onto the stack
    void pop();               // Pop an integer from the stack
    int top() const;          // Get the top element of the stack
    double average() const;   // Calculate the average value of the stack elements
    void display() const;     // Display the stack elements
};

#endif // STACK_H
