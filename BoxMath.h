#ifndef __BOXMATH__
#define __BOXMATH__
#include <iostream>
#include <ctime>
#include <cstdlib>
class BoxMath{
public:
	BoxMath(){}
	~BoxMath(){}
	int genRandInt(int start, int range);
	double genRandDouble(double start, double range);	
private:
protected:
};


#endif