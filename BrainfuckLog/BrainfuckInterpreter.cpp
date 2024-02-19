#include "pch.h"
#include "BrainfuckInterpreter.h"

auto BrainfuckInterpreter::run(std::string const& code) -> Memory
{
    Memory memory;
    for (const auto c : code)
    {
        if (c == '+')
        {
            (*memory.getIterator())++;
        }
    }
    return memory;
}
