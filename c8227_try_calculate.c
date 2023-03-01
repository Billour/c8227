#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char * addBinary(char *, char *);

/* test Linked list*/
struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
/*end  test*/

struct day_price
{
	double open_price;
	double end_price;
	double lowest_price;
	double highest_price;
	double trading_volume;
	struct tm trading_time; 
	struct tm update_time; 

};

struct period_day
{
	struct day_price dp[10];
}pd;

int main()
{
	/*test pointer to Array 20230301 */
	int i , val , num;
	NODE *first, *current, *previous;
	printf("Number of nodes:");
	scanf("%d", &num);
	for(i=0; i<num; i++)
	{
		current = (NODE *) malloc(sizeof(NODE));
		printf("Data for node %d:", i + 1);
		scanf("%d", &(current->data));
		if(i ==0 )
			first = current;
		else
			previous->next = current;
		current->next = NULL;
		previous = current;
	
	}
	current = first;
	while(current != NULL)
	{
		printf("address=%p , ", current);
		printf("data=%d, ", current->data);
		printf("next=%p \n", current->next);
		previous = current;
		current = current->next;
		free(previous);
	}
	free(current);
	printf("\n End test ----\n\n");

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
	/* 20230227 I tested C language with struct day price, period day price. 
	 * I also tested <time.h>, used it on the struct day_price.
	 * */

	time_t t = time(NULL);
	struct tm t1 = *localtime(&t); 

	
	struct tm td = *localtime(&t);// td is the 8277.tw trading day.
	td.tm_year = 123;
	td.tm_mon = 1;
	td.tm_mday = 24;
	struct day_price dd = {175.00, 169.00, 165.00, 175.00, 1822470, td,t1};
	//char * cp = malloc(9 * sizeof(char) );
	//cp = "20230224";
	printf("The open price %lf\n", dd.open_price);
	printf("The end price %lf\n", dd.end_price);
	printf("The lowest price %lf\n", dd.lowest_price);
	printf("The lowest price %lf\n", dd.highest_price);
	printf("The lowest price %lf\n", dd.trading_volume);
        printf( "dd's now: %d-%02d-%02d %02d:%02d:%02d\n", dd.update_time.tm_year + 1900, dd.update_time.tm_mon + 1, dd.update_time.tm_mday, dd.update_time.tm_hour, dd.update_time.tm_min, dd.update_time.tm_sec);
        printf( "Trading's day: %d-%02d-%02d %02d:%02d:%02d\n", dd.trading_time.tm_year + 1900, dd.trading_time.tm_mon + 1, dd.trading_time.tm_mday, dd.trading_time.tm_hour, dd.trading_time.tm_min, dd.trading_time.tm_sec);

/**/	/*
	char a = '1';
	char b = '1';
	char *a = &a_input, *b = &b_input;
	char *result;
	result = addBinary(&a, &b);
	printf("Result ofchar %s \n", *result);
	free(result);
*/
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
