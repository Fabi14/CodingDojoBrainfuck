#include "pch.h"
#include "CppUnitTest.h"
#include "../BrainfuckLog/BrainfuckInterpreter.h"

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
			Assert::IsTrue(expectedMemoryState.get() == memory.get());
		}
		TEST_METHOD(TestIncrementFirstMemoryPosition)
		{
			std::string codeToExecute{ "+" };
			BrainfuckInterpreter::Memory memory{ BrainfuckInterpreter::run(codeToExecute) };

			Assert::AreEqual(static_cast<unsigned char>(1u), memory.get().front());
		}

		TEST_METHOD(TestDecrementFirstMemoryPosition)
		{
			std::string codeToExecute{ "-" };
			BrainfuckInterpreter::Memory memory{ BrainfuckInterpreter::run(codeToExecute) };

			Assert::AreEqual(static_cast<unsigned char>(255u), memory.get().front());
		}

		TEST_METHOD(TestIncrementTheDataPointerAndIncrement)
		{
			std::string codeToExecute{ ">+" };
			BrainfuckInterpreter::Memory memory{ BrainfuckInterpreter::run(codeToExecute) };

			Assert::AreEqual(static_cast<unsigned char>(1u), *std::next(memory.get().begin()));
		}
	};
}
