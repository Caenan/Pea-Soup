//------------------------------------------------------------------------------
//	Pea-Soup Engine
//	(c) Smokestack Games
//------------------------------------------------------------------------------
#ifndef PEASOUP_KERNEL_MEMORY_MAP_H_INCLUDED
#define PEASOUP_KERNEL_MEMORY_MAP_H_INCLUDED
//------------------------------------------------------------------------------
#include "memory_pool.h"
#include <functional>
#include <string>
#include <unordered_map>

namespace peasoup
{
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	class MemoryMap
	{
	public:
		MemoryMap();
		~MemoryMap();

	private:
		typedef std::unordered_map<std::string, MemoryMap>	InternalMemoryMap;

		InternalMemoryMap									m_memoryMap;
		void*												m_applicationMemory;
	};
}

//------------------------------------------------------------------------------
#endif // PEASOUP_KERNEL_MEMORY_MAP_H_INCLUDED
//------------------------------------------------------------------------------
