#include "Calculator.h"
#include <iostream>

Calculation::Calculation(M& queries, M& dataset, std::function<float(V&, V&)> distance_function)
{
	for (int i = 0; i < queries.size(); i++)
	{
		std::promise<Calculation::V> p;
		futures.push_back(p.get_future());
		std::thread(&Calculation::parallel_query, this, queries[i], dataset, distance_function, std::move(p)).detach();
	}
}

Calculation::M Calculation::Get()
{
	M result;
	for (int i = 0; i < futures.size(); i++)
	{
		result.push_back(futures[i].get());
	}
	return result;
}

void Calculation::parallel_query(V& a, M& b, std::function<float(V&, V&)> distance_function, std::promise<V>&& promise)
{
	static int aa = 0;
	std::cout << "Here we go: " << aa++ << std::endl;
	std::vector<float> result;
	for (int j = 0; j < b.size(); j++)
	{
		result.push_back(distance_function(b[j], a));
	}
	promise.set_value(result);
}