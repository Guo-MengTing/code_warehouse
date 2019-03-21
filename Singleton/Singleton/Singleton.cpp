#include<iostream>
using namespace std;
#include<mutex>
#include<thread>

//����ģʽ��һ����ֱ�Ӵ�������
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	Singleton(){}
	Singleton(Singleton const&){}
	Singleton& operator=(Singleton const&){}

	static Singleton m_instance;

};
Singleton Singleton::m_instance;


//����ģʽ������һ������ָ�룩
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (m_pInstance = nullptr)
		{
			m_mtex.lock();
			if (m_pInstance == nullptr)
			{
				m_pInstance = new Singleton;
			}
			m_mtex.unlock();

		}
		return m_pInstance;
	}
	class CGarbo
	{
		~CGarbo()
		{
			if (Singleton::m_pInstance)
			{
				delete Singleton::m_pInstance;
			}
		}
	};
	static CGarbo Garbo;
private:
	Singleton(){}
	Singleton(Singleton const&){}
	Singleton& operator=(Singleton const&){}

	static Singleton* m_pInstance;
	static mutex m_mtex;
};
Singleton* Singleton::m_pInstance = nullptr;
mutex Singleton::m_mtex;
