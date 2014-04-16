#ifndef UTIL_H
#define UTIL_H

#include <cstdlib>
#include <ctime>

namespace trillek
{

namespace util
{

class Util
{
	public:
		static void Seed();
		static float RandFloat(float min, float max);
		static int RandInt(int min, int max);
};

}

}

#endif
