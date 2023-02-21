#include <stdio.h>


int main()
{
	int in_data = 173;
	int i_max = 20;
	double i_multi = 1.07;
	for(int i=1; i<= i_max ; ++i )
		in_data *= i_multi;
	printf("Result: %d, i_max: %d, multi:%f \n",in_data, i_max, i_multi);

	return 0;
}
