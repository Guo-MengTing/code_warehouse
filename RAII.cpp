//智能指针的原理（RAII+指针的行为（解引用、访问空间内容））
#include<iostream>
using namespace std;
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{

	}
	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
struct Date
{
	int _year;
	int _month;
	int _day;
};
int main()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	cout << *sp1 << endl;

	SmartPtr<Date> sp2(new Date);
	sp2->_year = 2019;
	sp2->_month = 4;
	sp2->_day = 9;
}

//auto_ptr(C++ 98,管理权转移)
#include<iostream>
#include<memory>
using namespace std;
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{

	}
	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;

			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}
private:
	T* _ptr;
};
struct Date
{
	int _year;
	int _month;
	int _day;
};
int main()
{
	AutoPtr<Date> ap(new Date);
	AutoPtr<Date> copy(ap);
	//拷贝构造后把ap对象的指针置空，此时通过ap对象访问资源出现问题
	ap->_year = 2018;
	return 0;
}


//unique_ptr(防拷贝，不让拷贝和赋值)
#include<iostream>
#include<memory>
using namespace std;
template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr=nullptr)
		:_ptr(ptr)
	{

	}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	//C++98 防拷贝方式：只声明不实现+声明成私有
	UniquePtr(UniquePtr<T> const&);
	UniquePtr& operator=(UniquePtr<T> const&);

	//C++11防拷贝方式：delete
	UniquePtr(UniquePtr<T> const &) = delete;
	UniquePtr& operator=(UniquePtr<T> const &) = delete;
};


//shared_ptr(通过引用计数方式实现多个shared_ptr对象共享资源)
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr (ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{
		if (_ptr == nullptr)
			*_pRefCount = 0;
	}
	~SharedPtr()
	{
		Release();
	}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		,_pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		//如果是空指针对象，则不加引用计数
		if (_ptr)
			AddRefCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			Release();

			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			if (_ptr)
				AddRefCount();
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}

	int UseCount()
	{
		return *_pRefCount;
	}
	T* Get()
	{
		return _ptr;
	}
	int AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}
	int SubRefCount()
	{
		_pMutex->lock();
		--(*_pRefCount);
		_pMutex->unlock();
		return *_pRefCount;
	}
private:
	void Release()
	{
		if (_ptr&&SubRefCount() == 0)
		{
			delete _ptr;
			delete _pRefCount;
		}
	}
private:
	T* _ptr;
	int* _pRefCount; //引用计数
	mutex* _pMutex;
};
int main()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;

	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;

	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;

}

