//------------------------------------------------------------------------------
//	Pea-Soup Engine
//	(c) Smokestack Games
//------------------------------------------------------------------------------
#ifndef PEASOUP_KERNEL_ASSERT_H_INCLUDED
#define PEASOUP_KERNEL_ASSERT_H_INCLUDED
#if defined _DEBUG
//------------------------------------------------------------------------------
#include "defines.h"

namespace peasoup
{
	//------------------------------------------------------------------------------
	//	Information on how to respond to an assert.
	//------------------------------------------------------------------------------
	struct AssertResponse
	{
		enum Type
		{
			Break,
			Ignore,
			Terminate,
		};
	};

	//------------------------------------------------------------------------------
	//	Assert implementation.
	//------------------------------------------------------------------------------
	class Assert
	{
	public:
		static Assert&				getInstance();

		AssertResponse::Type		reportError(const char* file, const int line, const char* condition, const char* message, ...);

	private:
		Assert();

		//------------------------------------------------------------------------------
		//	Not to be implemented.
		//------------------------------------------------------------------------------
		Assert(const Assert& assert);
		Assert&						operator = (const Assert& assert);
	};
}

//------------------------------------------------------------------------------
//	Usage macros for debug mode to initiate asserts.
//------------------------------------------------------------------------------
#define PS_ASSERT(CND, MSG, ...) \
	do { if (!(CND)) { switch (peasoup::Assert::getInstance().reportError(__FILE__, __LINE__, #CND, MSG, __VA_ARGS__)) { case peasoup::AssertResponse::Break: PS_BREAK(); break; case peasoup::AssertResponse::Ignore: break; case peasoup::AssertResponse::Terminate: PS_ABORT(); break; } } } while (0)

#define PS_ASSERT_FAIL(MSG, ...) \
	do { switch (peasoup::Assert::getInstance().reportError(__FILE__, __LINE__, nullptr, MSG, __VA_ARGS__)) { case peasoup::AssertResponse::Break: PS_BREAK(); break; case peasoup::AssertResponse::Ignore: break; case peasoup::AssertResponse::Terminate: PS_ABORT(); break; } } while (0)

//------------------------------------------------------------------------------
#else // Usage macros for release mode so asserts do not fire.
//------------------------------------------------------------------------------
#define PS_ASSERT(CND, MSG, ...) \
	do { PS_UNUSED(CND); PS_UNUSED(MSG); } while (0)

#define PS_ASSERT_FAIL(MSG, ...) \
	do { PS_UNUSED(MSG); } while (0)

//------------------------------------------------------------------------------
#endif // defined __debug
//------------------------------------------------------------------------------
#define PS_STATIC_ASSERT(CND, MSG) \
	static_assert(CND, MSG);

//------------------------------------------------------------------------------
#endif // PEASOUP_KERNEL_ASSERT_H_INCLUDED
//------------------------------------------------------------------------------
