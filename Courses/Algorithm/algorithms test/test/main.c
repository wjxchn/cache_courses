#include<stdio.h>

static int a=1;
int b=2;
int c;

int main()
{
	int c=3;
	int b=4;
	foo();
	printf("a=%d,b=%d,c=%d\n",a,b,c);
	return 0;	
} 
