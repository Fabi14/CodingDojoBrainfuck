#pragma once
#include <memory>
#include <array>
#include <string>

class BrainfuckInterpreter
{
public:
	struct Memory
	{
		std::array<unsigned char, 30'000> const& get() const
		{
			return *memory.get();
		}
	private:
		std::unique_ptr<std::array<unsigned char, 30'000>> memory{ std::make_unique<std::array<unsigned char, 30'000>>() };
	};

	static Memory run(std::string const& code);

	


};

