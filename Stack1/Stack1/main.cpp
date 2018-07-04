//
//  main.cpp
//  Stack1
//
//  Created by 胡欣妍 on 2018/7/1.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <deque>
using namespace std;

template <typename T>
class Stack;

template <typename T>
ostream& operator <<(ostream& os, Stack<T> const& stack) {
    for (T elem : stack.elems) {
        os << elem << " ";
    }
    return os;
}

template <typename T>
class Stack {
    vector<T> elems;
    
public:
    void push(T const&);
    void pop();
    T const& top() const;
    bool empty() const {
        return elems.empty();
    }
    
    friend ostream& operator << <T> (ostream&, Stack const&);
};

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back();
}

template <>
class Stack<string> {
    deque<string> elems;
    
public:
    void push(string const&);
    void pop();
    string const& top() const;
    bool empty() const {
        return elems.empty();
    }
    friend ostream& operator << <string> (ostream&, Stack const&);
};

void Stack<string>::push(string const& elem) {
    elems.push_back(elem);
}

void Stack<string>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

string const& Stack<string>::top() const {
    assert(!elems.empty());
    return elems.back();
}


int main(int argc, const char * argv[]) {
    Stack<int> s;
    s.push(11);
    int a = 0;
    s.push(move(a));
    cout << s << endl;
    
    Stack<string> s1;
    s1.push("hello");
    s1.push("world");
    cout << s1 << endl;
    return 0;
}
