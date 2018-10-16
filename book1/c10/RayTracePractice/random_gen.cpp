#include "random_gen.h"

random_gen::random_gen()
{
	distribution = std::uniform_real_distribution<float>(0, 1);
}

float random_gen::dice()
{
	return distribution(generator);
}
