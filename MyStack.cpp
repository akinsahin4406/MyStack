template<typename T>
void MyStack<T>::push(T newvalue)
{
    if (count == capacity)
    {
        capacity *= 2;
        T **ptr = m_data;
        m_data = new T*[capacity];
        for(int i=0;i<count;++i)
        {
            m_data[i] = ptr[i];
        }
        delete[] ptr;
    }
    ++count;
    m_data[count-1] = new T(newvalue);
}

template<typename T>
T& MyStack<T>::top() const
{
    T *ret = m_data[count-1];
    return *ret;
}

template<typename T>
void MyStack<T>::pop()
{
    T this_one = *m_data[count-1];
    delete this_one;
    --count;
}

template<typename T>
int MyStack<T>::size() const
{
    return count;
}

template<typename T>
MyStack<T>::MyStack(MyStack& rhs)
{
    capacity = rhs.capacity;
    count = rhs.count;
    m_data = new T[capacity];
    for(int j=0;j<count;++j)
    {
        m_data[j] = rhs.m_data[j];
    }
}

template<typename T>
MyStack<T>& MyStack<T>::operator = (MyStack& rhs)
{
    if (this != &rhs)
    {
        if (capacity < rhs.capacity)
        {
            delete[] m_data;
            m_data = new T[rhs.capacity];
        }
        capacity = rhs.capacity;
        count =rhs.count;
        for(int i=0;i<count;++i)
        {
            m_data[i] = rhs.m_data[i];
        }
    }
    return *this;
}

template<typename T>
MyStack<T>::MyStack(MyStack&& rhs)
{
    delete[] m_data;
    count = rhs.count;
    capacity = rhs.capacity;
    m_data = rhs.m_data;
    rhs.m_data = nullptr;
    rhs.count = 0;
    rhs.capacity = 0;
}

template<typename T>
MyStack<T>& MyStack<T>::operator = (MyStack&& rhs)
{
    if (this != &rhs)
    {
        delete[] m_data;
        count = rhs.count;
        capacity = rhs.capacity;
        m_data = rhs.m_data;
        rhs.m_data = nullptr;
        rhs.count = 0;
        rhs.capacity = 0;
    }
} 

template<typename T>
void MyStack<T>::clear() 
{
    for (int i=0;i<count;i++)
    {
        T this_one = *m_data[count-1];
        delete this_one;
    }
    
    m_data = nullptr;
    capacity =0;
    count = 0;

}
