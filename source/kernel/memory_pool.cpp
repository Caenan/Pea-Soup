//------------------------------------------------------------------------------
//	Pea-Soup Engine
//	(c) Smokestack Games
//------------------------------------------------------------------------------
#include "memory_pool.h"
#include "assert.h"
#include "utility.h"

namespace peasoup
{
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	MemoryPool::MemoryPool(const size_t size, void* start)
		: Allocator(size, start)
		, m_freeBlocks((Block*)start)
	{
		PS_ASSERT(size != 0, "This memory pool is being created with a size of zero.");

		m_freeBlocks->size = size;
		m_freeBlocks->next = nullptr;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	MemoryPool::~MemoryPool()
	{
		m_freeBlocks = nullptr;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	void* MemoryPool::allocate(const size_t size, const size_t alignment)
	{
		PS_ASSERT(size != 0, "Trying to allocate 0 bytes");
		PS_ASSERT(isPowerOfTwo(alignment), "Trying to allocate with a non power two alignment of %d", alignment);

		return nullptr;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	void MemoryPool::deallocate(void* memory)
	{
		PS_ASSERT(memory != nullptr, "Trying to deallocate from a null pointer.");
	}
}
