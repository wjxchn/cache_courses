#include<stdio.h>
#include<time.h>
#define MAXN 80
long dp[MAXN];
long fib(int n)
{
	if(n<=1) return 1;//递归边界
	if(dp[n]!=0) return dp[n];//已经计算，直接返回结果，不再重复计算
	else
    {
        dp[n]=fib(n-1)+fib(n-2);//f(0)=f(1)=1,从第0项开始f(2)=f(1)+f(0)
        return dp[n];
    }
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
