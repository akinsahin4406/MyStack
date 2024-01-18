#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <tuple>
#include <memory>
#include <queue>

#define MAX_ARRAY 10

template<typename T>
class MyStack
{
    T **m_data;
    int count;
    int capacity;
    public:
    MyStack():
    count{0},
    capacity{MAX_ARRAY}
    {
        m_data = new T*[MAX_ARRAY];
    }
    ~MyStack()
    {
        count = 0;
        capacity = 0;
        delete m_data;
    }
    void push(T newvalue);
    T& top() const;
    void pop();
    int size() const;
    MyStack(MyStack& rhs);
    MyStack& operator = (MyStack& rhs);
    MyStack(MyStack&& rhs);
    MyStack& operator = (MyStack&& rhs);
    void clear();

    void printValues()
    {
        for(int i=0;i<capacity;++i)
        {
            std::cout << "value:"<< top()->my_int_data << std::endl;
            pop();
        }
    }
};
