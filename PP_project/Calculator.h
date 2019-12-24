#pragma once

#include<vector>
#include<functional>
#include<thread>
#include<future>


// M = vector<vector<float>>
// V = vector<float>

class Calculation
{
	typedef std::vector<float> V;
	typedef std::vector<V> M;
	std::vector<std::future<V>> futures;
public:
	Calculation(M& queries, M& dataset, std::function<float(V&, V&)> distance_function);
	void parallel_query(V& a, M& b, std::function<float(V&, V&)> distance_function, std::promise<V>&& promise);
	M Get();
};