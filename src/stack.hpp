// stack.hpp
#include <iostream>
#include <string>

constexpr int STK_MAX = 1000;

class Stack {
    int _top;
    char buf[STK_MAX];

public:
    Stack(){
        _top = 0;
    }

    void push(char c){
        if (!isFull()){
            buf[_top] = c;
            _top += 1;
        }     

    }

    char pop(){
    if (isEmpty()){
        return '@';
    }
    _top -= 1;    
    return buf[_top];
}

    char top(){
    if (isEmpty()){
        return '@';
    }
        return buf[_top-1];
}

    bool isEmpty(){
        return _top == 0;
    }

    bool isFull(){
        return _top == STK_MAX;
    }

};

void push_all(Stack& stk, std::string line){
    for (int i=0;i<line.length();i++){
        stk.push(line[i]);
    }
}

void pop_all(Stack& stk){
    while (!stk.isEmpty()) {
    std::cout << stk.pop();
    }
    std::cout << std::endl;
}