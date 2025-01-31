#include "solution.hpp"
#include <limits>
#include <stack>

    MinStack::MinStack() {
    }
    
    void MinStack::push(int val) {
        if(mins.size()==0||mins.top()>=val){
            mins.push(val);
        }
        internal.push(val);
    }
    
    void MinStack::pop() {
        if(internal.top()==mins.top()){
            mins.pop();
        }
        internal.pop();
    }
    
    int MinStack::top() {
        return internal.top();
    }
    
    int MinStack::getMin() {
        return mins.top();
        
    }

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
