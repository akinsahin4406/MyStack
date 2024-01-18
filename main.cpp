#include <iostream>
#include <MyStack.h>

class MyClass
{
    public:
    int my_int_data;
    MyClass(int x):
    my_int_data{x}
    {
    }
    ~MyClass()
    {
        std::cout << "Destructor of MyClass" << std::endl;
    }
};

int main()
{
    MyStack<MyClass*> mys;
    for(int j=20;j<30;++j)
    {
        MyClass* ptr = new MyClass(j);
        mys.push(ptr);
    }

    mys.printValues();

    mys.clear();

    return 0;
}
