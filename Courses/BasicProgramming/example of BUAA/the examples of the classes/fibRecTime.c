#include<stdio.h>
#include<time.h>

long fib(int n)
{
	return n<=1 ? 1 : fib(n-1)+fib(n-2);//f(0)=f(1)=1,从第0项开始f(2)=f(1)+f(0)
}

int main()
{
	double x;
	int n;
	for(n=35;n<46;n++)
	{
		x=clock();
		printf("Fib %d is %ld in",n,fib(n));
		printf(" %fs\n",(clock()-x)/CLOCKS_PER_SEC);
	}
	return 0;
}
