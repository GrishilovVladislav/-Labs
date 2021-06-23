#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <class T>
class MyVector 
{

private:
	int* x;
	int size;
	int capacity;

public:
	MyVector(int newSize);
	MyVector(const MyVector& vector);
	~MyVector();
	class Iterator;
	void Push_back(T data);
	void Pop_back();
	int Size();
	void Resize(int num);
	void Empty();
	Iterator Begin();
	Iterator End();
	void Show();

	class Iterator : iterator<bidirectional_iterator_tag, T>
	{
	private:
		T* p;

	public:
		Iterator()
		{
			p = nullptr;
		}

		explicit Iterator(T* p)
		{
			this->p = p;
		}

		T* operator->()
		{
			return p;
		}

		Iterator& operator++()
		{
			p++;
			return *this;
		}

		Iterator& operator--()
		{
			p--;
			return *this;
		}

		int& operator*()
		{
			return *p;
		}

		int operator*() const
		{
			return *p;
		}

		bool operator==(const Iterator& rhs) const
		{
			return p == rhs.p;
		}

		bool operator!=(const Iterator& rhs) const
		{
			return p != rhs.p;
		}
		Iterator& operator=(const Iterator& rhs)
		{
			p = rhs.p;
			return *this;
		}
		friend Iterator operator+(const int& n, const Iterator& rhs)
		{
			return Iterator(rhs.object + n);
		}
	};
};

template<class T>
MyVector<T>::MyVector(int newSize)
{
	this->x = new int[newSize];
	this->size = newSize;
	capacity = newSize;
	for (int i = 0; i < size; i++) {
		cin >> x[i];
	}
}

template<class T>
MyVector<T>::MyVector(const MyVector& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->x = new T[capacity];
	for (int i = 0; i < size; i++) {
		x[i] = vector.x[i];
	}
}


template<class T>
MyVector<T>::~MyVector()
{
	delete[] this->x;
}

template<class T>
void MyVector<T>::Push_back(T data)
{
	T* newX = new int[++size];
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
		{
			newX[i] = x[i];
		}
		else
		{
			newX[i] = data;
			break;
		}
	}
	delete[] x;
	x = newX;
}

template<class T>
void MyVector<T>::Pop_back()
{
	if (size > 0)
	{
		size--;
	}
	else
	{
		cout << "Error";
	}
}

template<class T>
int MyVector<T>::Size()
{
	return size;
}

template<class T>
void MyVector<T>::Resize(int num)
{
	if (size > num)
	{
		size = num;
	}
	else
	{		
		for (int i = size; size < num; i++) 
		{
			Push_back(0);			
		}	
	}
}

template<class T>
void MyVector<T>::Empty()
{
	size = 0;
}

template<class T>
typename MyVector<T>::Iterator MyVector<T>::Begin() {
	return Iterator(x);
}

template<class T>
typename MyVector<T>::Iterator MyVector<T>::End() {
	return Iterator(x + size);
}

template<class T>
void MyVector<T>::Show()                                                                                   
{
	for (int i = 0; i < size; i++) {
		cout << x[i];
	}
}



int main() 
{

	MyVector<int> V1 = MyVector<int>(5);
	V1.Resize(7);
	V1.Push_back(10);
	V1.Push_back(6);
	V1.Push_back(220);
	V1.Pop_back();
	V1.Begin();
}
