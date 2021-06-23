#include <iostream>
#include <iterator>

using namespace std;

template<typename T>
class MyList
{
private:
    struct node;
    node* head, * tail;
    size_t count;
public:
    MyList();
    ~MyList();
    void PushFront(const T&);
    void PushBack(const T&);
    bool Empty();
    void PopFront();
    void PopBack();
    size_t Size();
    class Iterator;
    Iterator Begin();
    Iterator End();

};


template<typename T>
struct MyList<T>::node
{
    T data;
    node* next, * prev;
    node() = default;
    node(const T& data) 
        {
        this->data = data; 
        next = nullptr;
        prev = nullptr;
    }
};

template<typename T>
MyList<T>::MyList()  
{
    head = nullptr;
    tail = nullptr; 
    count = 0;
}

template<typename T>
MyList<T>::~MyList()
{
    while (count != 0)
    {
        PopFront();
    }
}

template<typename T>
void MyList<T>::PushFront(const T& val)
{
    node* newNode = new(nothrow) node(val);
    if (newNode != nullptr)
    {
        if (head == nullptr)
        {
            head = tail = newNode;
            head->next = tail;
            tail->next = nullptr;
            head->prev = nullptr;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    ++count;
}

template<typename T>
void MyList<T>::PushBack(const T& val)
{
    node* newNode = new(std::nothrow) node(val);
    if (newNode != nullptr)
    {
        if (head == nullptr)
        {
            head = tail = newNode;
            head->next = tail;
            tail->next = nullptr;
            head->prev = nullptr;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    ++count;
}

template<typename T>
bool MyList<T>::Empty()
{
    if (count > 0) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
void MyList<T>::PopFront()
{
    node* tmp = head->next;

    tmp->prev = nullptr;
    delete head;
    head = tmp;

    count--;
}

template<typename T>
void MyList<T>::PopBack()
{
    node* tmp = tail->prev;
    node* last = new node;
    last->data = 0;
    last->prev = tmp;
    tmp->next = last;
    delete tail;
    tail = tmp;
    count--;
}

template<typename T>
size_t MyList<T>::Size()
{
    return size_t();
}

template<typename T>
class MyList<T>::Iterator {
private:
    node* x;
public:
    Iterator()
    {
        x = nullptr;
    }
    Iterator(const Iterator& other)
    {
        x = other.x;
    }
    explicit Iterator(node* val)
    {
        x = val;
    }
    node* operator->()
    {
        return x;
    }
    Iterator& operator++()
    {
        x = x->next;
        return *this;
    }
    Iterator& operator++(int)
    {
        Iterator tmp = *this;
        this->x = this->x->next;
        return tmp;
    }
    Iterator& operator--(int)
    {
        Iterator tmp = *this;
        this->x = this->x->prev;
        return tmp;
    }
    Iterator& operator--()
    {
        x = x->next;
        return *this;
    }
    int& operator*()
    {
        return x->data;
    }
    int operator*() const
    {
        return x->data;
    }
    bool operator==(const Iterator& rhs) const
    {
        return x == rhs.x;
    }
    bool operator!=(const Iterator& rhs) const
    {
        return x != rhs.x;
    }
};

template<typename T>
typename MyList<T>::Iterator MyList<T>::Begin()
{
    return Iterator(head);
}

template<typename T>
typename MyList<T>::Iterator MyList<T>::End()
{
    return Iterator(tail);
}


int main()
{
    MyList<int> L1;
    L1.PushBack(1);
    L1.PushBack(2);
    L1.PushBack(3);
    L1.PushFront(-1);
    L1.PushFront(-2);
    L1.PushFront(-3);

    L1.Begin();
    L1.End();

    L1.PopBack();
    L1.PopBack();
    L1.PopBack();
    L1.PopBack();
    L1.PopBack();

    

    
}
