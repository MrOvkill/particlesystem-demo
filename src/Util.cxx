#include "Util.hpp"

namespace trillek
{

namespace util
{

	void Util::Seed()
	{
		srand(time(NULL));
	}
	int Util::RandInt(int min, int max)
	{
		return rand() % max + min;
	}
	float Util::RandFloat(float min, float max)
	{
		return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
	}

}

}
