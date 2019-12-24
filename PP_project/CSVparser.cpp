#include "CSVParser.h"

#include<fstream>
#include<sstream>

void CSVParser::parse(std::string path_before_csv_file, std::vector<std::vector<float>>& vectors_to_fill)
{
	vectors_to_fill.resize(1024, std::vector<float>(512));
	std::filebuf fb;
	fb.open(path_before_csv_file, std::ios::in);
	std::istream is(&fb);
	std::string line;
	int line_number = 0;
	
	while (std::getline(is, line))
	{
		if (line_number == 1024)
		{
			throw std::exception("Wrong numbers of lines");
		}
		std::istringstream iss(line);
		float f;
		int element_number = 0;
		while (iss >> f)
		{
			if (element_number == 512)
			{
				throw std::exception(std::string("Wrong numbers of element in line " + std::to_string(line_number)).c_str());
			}
			vectors_to_fill[line_number][element_number] = f;
			element_number++;
		}
		line_number++;
	}
	fb.close();
}
