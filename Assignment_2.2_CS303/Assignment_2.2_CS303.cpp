// Assignment_2.2_CS303.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric> // For std:: accumulate
using namespace std;

class Stack { // Create a stack
private:
    std::vector<int> elements; // Use a Vectors elements to create the stack

public:
    // Check if the stack is empty
    bool isEmpty() const { // Logic for bool empty
        return elements.empty(); // Return that the stack is empty
    }

    // Push an integer onto the stack
    void push(int value) { // Use built in Vector push function
        elements.push_back(value);
    }

    // Pop an integer from the stack
    void pop() { // Use built in Vector pop function
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty, cannot pop."); // Throw the exception that the stack is empty
        }
        elements.pop_back();
    }

    // Get the top element of the stack
    int top() const { //Use built in Vector top function
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty, no top element"); // Throw the exception that the stack is empty
        }
        return elements.back();
    }

    // Calculate the average value of the stack elements
    double average() const { // Create a number function to check average
        if (isEmpty()) { 
            throw std::out_of_range("Stack is empty, cannot compute average."); // Throw the exception that the stack is empty
        }
        double sum = std::accumulate(elements.begin(), elements.end(), 0); // Calculate the sum of the numbers by adding up the value of the items
        return sum / elements.size(); // Divide the sum by the size of the stack to find the average

    }

    // Display the stack elements (for testing purposes)
    void display() const {
        std::cout << "Stack Elements: "; // Print Stack Elements
        for (const int& elem : elements) { // Print the elements
            cout << elem << " ";
        }
        cout << std::endl; // Formatting for the display
    }

};


int main()
{
    int num_1 = 0; // Define 5 variables for user inputs in the stack
    int num_2 = 0;
    int num_3 = 0;
    int num_4 = 0;
    int num_5 = 5;
    Stack stack;

    // 1) Create a stack object
    std::cout << "Stack created." << std::endl;


    // 2) Check if the stack is empty
    std::cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    // 3) Insert some integer values onto the stack
    cout << "Please insert a number to add to the stack: ";
    cin >> num_1;
    cout << "Please insert a number to add to the stack: ";
    cin >> num_2;
    cout << "Please insert a number to add to the stack: ";
    cin >> num_3;
    cout << "Please insert a number to add to the stack: ";
    cin >> num_4;
    cout << "Please insert a number to add to the stack: ";
    cin >> num_5;

    stack.push(num_1); // Push the user inputs into the stack
    stack.push(num_2);
    stack.push(num_3);
    stack.push(num_4);
    stack.push(num_5);
    stack.display(); // Display the stack

    // 4) Remove an element from the stack
    stack.pop();
    stack.display(); // Display the stack after popping

    // 5) Find the Top of the stack
    try {
        cout << "Top of the stack: " << stack.top() << std::endl; // Print the top of the stack
    }
    catch (const std::exception& e) { // Catch the exception for if there is nothing in the stack
        cout << e.what() << std::endl;
    }

    // 6) Find average value of the stack elements
    try {
        cout << "Average of stack elements: " << stack.average() << std::endl; // Print the average
    }
    catch (const std::exception& e) { //Throw the exception if the stack is empty
        cout << e.what() << std::endl;
    }

    return 0;

}
