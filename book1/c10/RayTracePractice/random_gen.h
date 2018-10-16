#pragma once
#include<random>
#include<functional>

//beter to use a function base Low Discrepancy Sequence;
class random_gen
{
public:
	random_gen();
	float dice();
	std::default_random_engine generator;
	std::uniform_real_distribution<float> distribution;
};

