#include"ThreadCache.h"
#include"CentralCache.h"

//从中心缓存获取对象
void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	FreeList* freelist = &_freelist[index];
	size_t maxsize = freelist->MaxSize();
	size_t numtomove = min(SizeClass::NumMoveSize(size),maxsize);

	void* start = nullptr;
	void* end = nullptr;
	size_t batchsize = CentralCache::GetInstance()->FetchRangeObj(start, end, numtomove, size);

	if (batchsize > 1)
	{
		freelist->PushRange(NEXT_OBJ(start), end, batchsize - 1);
	}
	if (batchsize >= freelist->MaxSize())
	{
		freelist->SetMaxSize(maxsize + 1);
	}
	return start;
}

void* ThreadCache::Allocate(size_t size)
{
	size_t index =SizeClass::Index(size);
	FreeList* freelist = &_freelist[index];
	if (!freelist->empty())
	{
		return freelist->Pop();
	}
	else
	{
		return FetchFromCentralCache(index, SizeClass::Roundup(size));
	}
}
void ThreadCache::Deallocate(void* ptr,size_t size)
{
	size_t index = SizeClass::Index(size);
	FreeList* freelist = &_freelist[index];
	freelist->Push(ptr);

	if (freelist->Size() > freelist->MaxSize())
	{
		ListTooLong(freelist, size);
	}
}

void ThreadCache::ListTooLong(FreeList* freelist, size_t size)
{
	void* start = freelist->PopRange();
	CentralCache::GetInstance()->ReleaseListToSpan(start, size);
}

