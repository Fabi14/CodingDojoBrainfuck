#include "pch.h"
#include "BrainfuckInterpreter.h"
#include <map>
#include <functional>

auto BrainfuckInterpreter::run(std::string const& code, const InputOutput& inOut) -> Memory
{
    Memory memory;
    auto memoryPointer{ memory.begin() };

    std::map<char, std::function<void()>> commands
    {
        {'+', [&] {(*memoryPointer)++; }},
        {'-', [&] {(*memoryPointer)--; }},
        {'>', [&]
            {
                memoryPointer++;
                if (memoryPointer == memory.end())
                {
                    memoryPointer = memory.begin();
                }
            }
        },
        {'<', [&]
            {
                if (memoryPointer == memory.begin())
                {
                    memoryPointer = memory.end();
                }
                memoryPointer--;
            }
        },
        { '.', [&] { inOut.output << (*memoryPointer); } },
        { ',', [&] { inOut.input >> (*memoryPointer); } }
    };

    for (const auto c : code)
    {
        std::invoke(commands.at(c));
    }
    return memory;
}
