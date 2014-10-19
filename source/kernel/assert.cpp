//------------------------------------------------------------------------------
//	Pea-Soup Engine
//	(c) Smokestack Games
//------------------------------------------------------------------------------
#if defined _DEBUG
//------------------------------------------------------------------------------
#include "assert.h"

#include <Windows.h>
#include <cstdio>
#include <cstdarg>
#include <sstream>

namespace peasoup
{
	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	Assert::Assert()
	{
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	AssertResponse::Type Assert::reportError(const char* file, const int line, const char* condition, const char* message, ...)
	{
		std::stringstream messageBoxOutput;

		if (file != nullptr)
		{
			messageBoxOutput << "File: " << file << std::endl;
			messageBoxOutput << "Line: " << line << std::endl;
		}

		if (condition != nullptr)
		{
			messageBoxOutput << "Condition: " << condition << std::endl;
		}

		if (message != nullptr)
		{
			char messageBuffer[1024];
			va_list arguments;
			va_start(arguments, message);
			vsnprintf_s(messageBuffer, 1024, message, arguments);
			va_end(arguments);
			const char* messageWithArguments = messageBuffer;
			messageBoxOutput << "Message: " << messageBuffer << std::endl;
		}

		switch (MessageBox(nullptr, messageBoxOutput.str().c_str(), "Pea Soup Assert", MB_ICONERROR | MB_ABORTRETRYIGNORE))
		{
		case IDABORT:
			return AssertResponse::Terminate;

		case IDRETRY:
			return AssertResponse::Break;

		default:
			return AssertResponse::Ignore;
		}
	}

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------
	Assert& Assert::getInstance()
	{
		static Assert assert;
		return assert;
	}
}

//------------------------------------------------------------------------------
#endif // defined _DEBUG
//------------------------------------------------------------------------------
