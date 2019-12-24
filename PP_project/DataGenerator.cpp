#include "DataGenerator.h"

void DataGenerator::generate_data(std::vector<std::vector<float> >& vectors_to_fill)
{
	int number_of_vectors = 16;
	vectors_to_fill.resize(number_of_vectors, std::vector<float>(number_of_vectors >> 1));
	for (int i = 0; i < vectors_to_fill.size(); i++)
	{
		for (int j = 0; j < vectors_to_fill[i].size(); j++)
		{
			vectors_to_fill[i][j] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		}
	}
}