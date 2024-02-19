#include "pch.h"
#include "BrainfuckInterpreter.h"

auto BrainfuckInterpreter::run(std::string const& code) -> Memory
{
    Memory memory;
    auto memoryPointer{ memory.getIterator() };
    for (const auto c : code)
    {
        if (c == '+')
        {
            (*memoryPointer)++;
        }
        else if (c == '-')
        {
            (*memoryPointer)--;
        }
        else if (c == '>')
        {
            memoryPointer++;
        }
    }
    return memory;
}
