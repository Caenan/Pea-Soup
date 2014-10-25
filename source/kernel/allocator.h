//------------------------------------------------------------------------------
//	Pea-Soup Engine
//	(c) Smokestack Games
//------------------------------------------------------------------------------
#ifndef PEASOUP_KERNEL_ALLOCATOR_H_INCLUDED
#define PEASOUP_KERNEL_ALLOCATOR_H_INCLUDED
//------------------------------------------------------------------------------
#include "kernel/defines.h"

namespace peasoup
{
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	class Allocator
	{
	public:
		Allocator(const size_t size, void* start);
		virtual ~Allocator();

		virtual void*					allocate(const size_t size, const size_t alignment = 4) = 0;
		virtual void					deallocate(void* memory) = 0;

		inline void*					getStart();

		inline size_t					getNumberOfAllocations();
		inline size_t					getSize();
		inline size_t					getUsedMemorySize();

	private:
		void*							m_start;

		size_t							m_numberOfAllocations;
		size_t							m_size;
		size_t							m_usedMemorySize;
	};

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	inline void* Allocator::getStart()
	{
		return m_start;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	inline size_t Allocator::getNumberOfAllocations()
	{
		return m_numberOfAllocations;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	inline size_t Allocator::getSize()
	{
		return m_size;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	inline size_t Allocator::getUsedMemorySize()
	{
		return m_usedMemorySize;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	template <class t_object> t_object allocate(Allocator& allocator)
	{
		return new allocator.allocate(sizeof(t_object), __alignof(t_object)) t_object;
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	template <class t_object> t_object allocate(Allocator& allocator, const t_object& copyObject)
	{
		return new allocator.allocate(sizeof(t_object), __alignof(t_object)) t_object(copyObject);
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	template <class t_object> t_object deallocate(Allocator& allocator, t_object& deletionObject)
	{
		deletionObject.~t_object();
		allocator.deallocate(&deletionObject);
	}
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#define PS_NEW(TYPE, ALLOCATOR) \
	peasoup::allocate<TYPE>(ALLOCATOR)

#define PS_NEW_COPY(TYPE, ALLOCATOR, COPY) \
	peasoup::allocate<TYPE>(ALLOCATOR, COPY)

#define PS_DELETE(TYPE, ALLOCATOR, TARGET) \
	peasoup::deallocate<TYPE>(ALLOCATOR, TARGET)

//------------------------------------------------------------------------------
#endif // PEASOUP_KERNEL_ALLOCATOR_H_INCLUDED
//------------------------------------------------------------------------------
