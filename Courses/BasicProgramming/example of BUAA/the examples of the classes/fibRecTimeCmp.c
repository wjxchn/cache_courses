#include<stdio.h>
#include<time.h>
#define MAXN 80
long dp[MAXN];
long fib(int n)
{
	if(n<=1) return 1;//�ݹ�߽�
	if(dp[n]!=0) return dp[n];//�Ѿ����㣬ֱ�ӷ��ؽ���������ظ�����
	else
    {
        dp[n]=fib(n-1)+fib(n-2);//f(0)=f(1)=1,�ӵ�0�ʼf(2)=f(1)+f(0)
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
