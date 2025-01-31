#ifndef PROBLEM155_MAIN_H
#define PROBLEM155_MAIN_H
#include <stack>
#include <limits>

class MinStack {
    private:
std::stack<int> internal;
std::stack<int> mins;

public:

    MinStack();
    
    void push(int val);
    
    void pop();
    
    int top();
    
    int getMin();
};
#endif // PROBLEM155_MAIN_H
