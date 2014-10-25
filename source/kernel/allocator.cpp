//------------------------------------------------------------------------------
//	Pea-Soup Engine
//	(c) Smokestack Games
//------------------------------------------------------------------------------
#include "allocator.h"
#include "kernel\assert.h"

namespace peasoup
{
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	Allocator::Allocator(const size_t size, void* start)
		: m_start(start)
		, m_numberOfAllocations(0)
		, m_size(size)
		, m_usedMemorySize(0)
	{
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	Allocator::~Allocator()
	{
		PS_ASSERT(m_numberOfAllocations == 0 && m_usedMemorySize == 0, "Trying to close down an allocator when memory still remains allocated.");

		m_size = 0;
		m_start = nullptr;
	}
}
