#include <iostream>
#include <vector>

using namespace std;


template <class T>
class MyDeque
{
private:
	T* arr = new T[10];
	int start, finish;
	int size;
	int capacity;
	
public:
    MyDeque();
	MyDeque(const MyDeque& other);
    ~MyDeque();
	void Resize(int newSize);
    void PushBack(T data);
    void PushFront(T data);
    void PopBack();
    void PopFront();
	T GetBack();
	T GetFront();
    void Clear();
    int Size();
    bool Empty();
	
};


template<class T>
MyDeque<T>::MyDeque()
{
	start = 1;
	finish = 0;
	size = 0;
	capacity = 32;

}

template<class T>
MyDeque<T>::MyDeque(const MyDeque& other)
{
	this->capacity = other.capacity;
	this->start = other.start;
	this->finish = other.finish;
	this->size = other.size;
	this->arr = other.arr;
}



template<class T>
MyDeque<T>::~MyDeque()
{
	delete[] arr;
}

template<class T>
void MyDeque<T>::Resize(int newCapacity)
{
	int* tmp = new T[newCapacity];   
	int j = start;                     
	for (int i = 0; j != finish; i++)
	{     
		tmp[i] = arr[j];
		j = (j + 1) % capacity;
	}
	tmp[size - 1] = arr[finish];    
	delete[] arr;                   
	arr = tmp;                     
	capacity = newCapacity;       
	start = 0;                   
	finish = size-1 ;            
}

template<class T>
void MyDeque<T>::PushBack(T data)
{
	if (size == capacity) 
	{
		this->Resize(2 * capacity);
	}
	finish = (finish + 1) % capacity;
	arr[finish] = data;
	size++;

}

template<class T>
void MyDeque<T>::PushFront(T data)
{
	if (size == capacity) 
	{
		this->Resize(2 * capacity);
	}
	start = (start - 1 + capacity) % capacity ;
	arr[start] = data;
	size++;
}

template<class T>
void MyDeque<T>::PopBack()
{
	finish = (finish - 1 + capacity) % capacity;
	size--;
}

template<class T>
void MyDeque<T>::PopFront()
{
	start = (start + 1) % capacity ;
	size--;
}

template<class T>
T MyDeque<T>::GetBack()
{
	return arr[finish];
}

template<class T>
T MyDeque<T>::GetFront()
{
	return arr[start];
}

template<class T>
void MyDeque<T>::Clear()
{
	finish = 0;
	start = 0;
	size = 0;
}

template<class T>
int MyDeque<T>::Size()
{
	return size;
}

template<class T>
bool MyDeque<T>::Empty()
{
	if (size > 0) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}

int main()
{
	MyDeque<int> D1;
	
	D1.PushBack(10);
	D1.Resize(4);
	D1.PushBack(20);
	D1.PushBack(30);
	D1.PushBack(110);
	D1.PushBack(330);
	D1.PushFront(402);
	D1.PushFront(403);
	D1.PushFront(450);
	D1.Resize(70);
	D1.GetFront();
	D1.GetBack();
	D1.Resize(30);
	D1.PopBack();
	D1.PopFront();
	D1.GetFront();
	D1.GetBack();
	D1.Clear();
}