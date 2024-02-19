#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBrainfuck
{
	TEST_CLASS(UnitTestBrainfuck)
	{
	public:
		
		TEST_METHOD(TestEmptyMemoryForNoCode)
		{
			std::string codeToExecute{ "" };
			BrainfuckInterpreter::Memory memory{ BrainfuckInterpreter::run(codeToExecute) };

			BrainfuckInterpreter::Memory expectedMemoryState{};
			Assert::AreEqual(expectedMemoryState, memory);
		}
	};
}
