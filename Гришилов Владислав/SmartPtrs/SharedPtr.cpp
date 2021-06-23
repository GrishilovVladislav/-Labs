#include <iostream>
using namespace std;

template <class T>
class SmartPointerShared
{

private:
	T* ptr;
	int* count = 0;
public:
	SmartPointerShared()
	{
		ptr = nullptr;
		count = nullptr;
	}

	SmartPointerShared(T* p)
	{
		ptr = p;
		count = new int(1);
	}

	SmartPointerShared(const SmartPointerShared& obj)
	{
		count = obj.count;
		ptr = obj.ptr;
		(*count)++;
	}

	~SmartPointerShared()
	{
		if (count != nullptr && -- * count == 0) 
		{
			delete ptr;
			delete count;
		}
	}

	SmartPointerShared& operator=(SmartPointerShared& obj)
	{
		if (this != &obj) {
			this->~SmartPointerShared();

			ptr = obj.ptr;
			count = obj.count;
			(*count)++;
		}
		return *this;
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
		Reset();
		count = new int(1);
		ptr = p;
	}


	void Reset()
	{
		this->~SmartPointerShared();
		ptr = nullptr;
		count = nullptr;
	}

	bool IsUnique() const {
		return (*count == 1);
	}

	int UseCount()
	{
		return *count;
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
	SmartPointerShared<int> SPS1 = new int(10);
	SmartPointerShared<int> SPS2 = new int(15);
	SmartPointerShared<int> SPS3 = SPS1;

	SmartPointerShared<int> SPS4 = SPS1;
	SmartPointerShared<int> SPS5 = SPS2;


	SPS1.IsUnique();

	SmartPointerShared<int> SPS6 = new int(100);
	
	cout << SPS5.GetData() << endl;
	cout << SPS1.UseCount() << endl;
	cout << SPS4.IsUnique() << endl;

	SPS6.Reset();

	SmartPointerShared<Test> SPST1 = new Test(100, 300);
	SmartPointerShared<Test> SPST2 = SPST1;
	cout << SPST2->a << endl;
	SPST1->a = 30;
	cout << SPST2->a << endl;
	
	
};
