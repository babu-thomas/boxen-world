#pragma once

#include <string>
#include <fstream>
#include <stdexcept>

namespace util {
	std::string read_file(const std::string& filename)
	{
		std::ifstream file;
		file.open(filename.c_str());

		std::string output;
		std::string line;

		if (file.is_open())
		{
			while (file.good())
			{
				std::getline(file, line);
				output.append(line + "\n");
			}
		}
		else
		{
			throw std::runtime_error("Unable to open file: " + filename);
		}
		return output;
	}
}