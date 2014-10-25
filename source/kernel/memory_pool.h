//------------------------------------------------------------------------------
//	Pea-Soup Engine
//	(c) Smokestack Games
//------------------------------------------------------------------------------
#ifndef PEASOUP_KERNEL_MEMORY_POOL_H_INCLUDED
#define PEASOUP_KERNEL_MEMORY_POOL_H_INCLUDED
//------------------------------------------------------------------------------
#include "allocator.h"

namespace peasoup
{
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	class MemoryPool : public Allocator
	{
	public:
		MemoryPool(const size_t size, void* start);
		virtual ~MemoryPool();

		void*							allocate(const size_t size, const size_t alignment = 4) override;
		void							deallocate(void* memory) override;

	private:
		//------------------------------------------------------------------------------
		//------------------------------------------------------------------------------
		struct Header
		{
			size_t						size;
			size_t						adjustment;
		};

		//------------------------------------------------------------------------------
		//------------------------------------------------------------------------------
		struct Block
		{
			size_t						size;
			Block*						next;
		};

		Block*							m_freeBlocks;

		//------------------------------------------------------------------------------
		//	Not to be implemented.
		//------------------------------------------------------------------------------
		MemoryPool(const MemoryPool&);
		MemoryPool&						operator = (const MemoryPool&);
	};
}

//------------------------------------------------------------------------------
#endif // PEASOUP_KERNEL_MEMORY_POOL_H_INCLUDED
//------------------------------------------------------------------------------
