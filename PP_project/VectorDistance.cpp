#include "VectorDistance.h"
#include <cmath>

float Distance::Hamming(std::vector<float>& lhv, std::vector<float>& rhv)
{
	float distance = 0;
	for (int i = 0; i < lhv.size(); i++)
	{
		distance += fabs(lhv[i] - rhv[i]);
	}
	return distance;
}