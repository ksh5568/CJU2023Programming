#include <stdio.h>

double centi_to_meter(int x);

int main(void)
{
	double res = 0.0;

	res = centi_to_meter(187);
	printf("% .2lfm\n", res);

	return 0;
}

double centi_to_meter(int x)
{
	double temp;
	temp = x * 0.01;
	return temp;
}