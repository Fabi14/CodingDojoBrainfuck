#include "pch.h"
#include "BrainfuckInterpreter.h"
#include <map>
#include <functional>

auto BrainfuckInterpreter::run(std::string const& code) -> Memory
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
        }
    };

    for (const auto c : code)
    {
        std::invoke(commands.at(c));
    }
    return memory;
}
