#include "BoxMath.h"

int BoxMath::genRandInt(int start, int range){
	srand(time(0));
	return rand() % range + start;
}
double BoxMath::genRandDouble(double start, double range){
	srand(time(0));
	int intRange = (int)(range * 100000);
	int randInt = rand() % intRange;
	return (double)randInt / 100000.0 + start;
}