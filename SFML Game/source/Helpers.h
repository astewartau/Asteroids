#pragma once
#include <random>
#include <time.h>

extern int RandInt(int min, int max) {
	int range = abs(max - min);
	int rnd = min + int((range * rand()) / (RAND_MAX + 1.0));

	return rnd;
}

float RandFloat(float min, float max) {
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}