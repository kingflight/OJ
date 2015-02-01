#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mypow(double bot,int pow)
{
	double r = 1;
	for(int i =0 ;i <pow;++i)
	{
		r*=bot;
	}
	return r;
}
int main(int argc,char** argv)
{
	double dBot= 0.4321;
	int iPow=20;
	double r = mypow(dBot,iPow);
	printf("%f\n",r);
	return 0;
}
