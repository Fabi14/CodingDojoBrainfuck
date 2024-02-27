#include "pch.h"
#include "BrainfuckInterpreter.h"
#include <map>
#include <functional>

auto BrainfuckInterpreter::run(std::string const& code, const InputOutput& inOut) -> Memory
{
    Memory memory;
    auto memoryPointer{ memory.begin() };
    auto codePointer{ code.begin() };

    std::function<void()> runLoop;

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
        { ',', [&] { inOut.input >> (*memoryPointer); } },
        { '[', [&] { runLoop(); }},
        { ']', [&] { } }
    };

    runLoop = [&]()
        {
            ++codePointer; // '[' wurde schon behandelt
            auto beginOfLoop = codePointer;
            while ((*memoryPointer) != 0)
            {
                codePointer = beginOfLoop; //jump to begin of Loop
                for (; (*codePointer) != ']'; ++codePointer)
                {
                    std::invoke(commands.at(*codePointer));
                }
            }
        };

    for (; codePointer < code.end(); ++codePointer)
    {
        std::invoke(commands.at(*codePointer));
    }
    return memory;
}
