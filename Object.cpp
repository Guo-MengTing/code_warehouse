#pragma once

template < class T, size_t N_OBJ = 20>
class ObjectPool
{
public:
	ObjectPool() = default;
	ObjectPool(const ObjectPool<T>&) = delete;
	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;

	template<class INIT_T>

private:
	char* _start = nullptr;
	char* _finish = nullptr;
	void* _freelist = nullptr;
};