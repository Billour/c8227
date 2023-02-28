#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * addBinary(char *, char *);

struct day_price
{
	double open_price;
	double end_price;
	double lowest_price;

};

struct period_day
{
	struct day_price dp[10];
}pd;

int main()
{
	/*20230221 I'd like to win a lot of money from 8227.tw stock share.
	 * So I made this program by Geometric progression, a progression of numbers 
	 * with a constant ratio between each number and the one before.
	 * (e.g each subsequent number is increased by a factor of 1.07 in
	 * the progression 173, 173*1.07, 173*1.07*1.07 ).
	 * */
	int in_data = 173;
	int i_max = 20;
	double i_multi = 1.07;
	for(int i=1; i<= i_max ; ++i )
		in_data *= i_multi;
	//printf("Result: %d, i_max: %d, multi:%f \n",in_data, i_max, i_multi);
/* 20230227 I tested C language with struct day price, period day price. */

	//char * cp = malloc(9 * sizeof(char) );
	//cp = "20230224";
	struct day_price dd = {175.00, 169.00, 165.00};
	printf("The open price %lf\n", dd.open_price);
	printf("The end price %lf\n", dd.end_price);
	printf("The lowest price %lf\n", dd.lowest_price);
	

/**/	
	char a = '1';
	char b = '1';
	//char *a = &a_input, *b = &b_input;
	char *result;
	//result = addBinary(&a, &b);
	//printf("Result ofchar %s \n", *result);

	

	free(result);
	return 0;
}

char *addBinary(char *a, char *b){
	int i, j, k, c =0;
	char *res;

	i = strlen(a);
	j = strlen(b);
	k = i > j ? i : j;
	k +=2;
	res = malloc(k * sizeof(char));
	i--;
	j--;
	res[--k] = '\0';
	while(--k >= 0){
		c += i >= 0 ? a[i--] - '0' :0;
		c += j >= 0 ? b[j--] - '0' : 0;
		res[k] = c%2 + '0';
		c /= 2;
	}
	if(res[0] == '0')
		memmove(res, res+1, strlen(res)* sizeof(char));
	return res;
}
