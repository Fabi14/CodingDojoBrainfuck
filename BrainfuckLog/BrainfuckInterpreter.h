#pragma once
#include <memory>
#include <array>
#include <string>

class BrainfuckInterpreter
{
public:
	struct Memory
	{
		using MemoryIntern = std::array<unsigned char, 30'000>;
		MemoryIntern const& get() const
		{
			return *memory.get();
		}
		MemoryIntern::iterator begin()
		{
			return memory.get()->begin();
		}
		MemoryIntern::iterator end()
		{
			return memory.get()->end();
		}
	private:
		std::unique_ptr<MemoryIntern> memory{ std::make_unique<MemoryIntern>() };
	};

	static Memory run(std::string const& code);
};

