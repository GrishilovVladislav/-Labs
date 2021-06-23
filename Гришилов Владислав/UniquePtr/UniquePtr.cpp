#include <iostream>

using namespace std;

template <typename T>
class SmartPointerUnique
{
private:
	T* ptr;
	int copy;
public:
	SmartPointerUnique(T* p)
	{
		ptr = p;
		copy = 0;
	}

	SmartPointerUnique(const T& obj)
	{
		ptr = obj.ptr;
		copy = 1;
	}

	~SmartPointerUnique()
	{
		if (copy == 0 && ptr != nullptr)
		{
			delete ptr;
		}
	}

	SmartPointerUnique operator=(const T& obj)
	{
		ptr = obj.ptr;
		copy = 1;
	}


	T* operator ->()
	{
		return ptr;
	}

	T& operator*()
	{
		return *ptr;
	}

	T& GetData()
	{
		return *ptr;
	}

	T* Get()
	{
		return ptr;
	}

	T* Release()
	{
		T* tempPtr = Get();
		ptr = nullptr;
		return tempPtr;		
	}

	void Reset(T* p)
	{
		this->~SmartPointerUnique();
		ptr = p;
	}


	void Reset()
	{
		this->~SmartPointerUnique;
		ptr = nullptr;
		copy = 0;
	}
};

class Test
{	
public:
	int a = 10;
	int b = 15;
	Test(int a, int b) 
	{
		this->a = a;
		this->b = b;
		cout << "TestConst" << endl;
	}
	~Test() 
	{
		cout << "TestDestr" << endl;
	}
};

int main()
{
	SmartPointerUnique<int> SP1 = new int(10);
	cout << SP1.Get() << endl;
	SmartPointerUnique<int> SP2 = new int();
	SP2.Reset(SP1.Release());
	cout << SP2.GetData() << endl;
	
	SmartPointerUnique<Test> SP3 = new Test(11, 3);
	cout << SP3->a << endl;
	cout << SP3->b << endl;

};