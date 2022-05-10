#include <stdio.h>
#define MAXLEN 100

int data[MAXLEN];

int *calcfact(int n)
{
	int i,j;
	int digit  = 1; //数据位数变量
	for(i = 1; i < MAXLEN + 1; i++)
		data[i] = 0;
	data[1] = 1; //data[1]存放n!的个位数

	for(i = 1;i < n+1; i++)
	{
		int c=0;//进位
		for(j = 1; j < digit+1; j++)
        {
			    data[j] =  data[j]*i+c; //计算阶乘
			    c=data[j]/10;
			    data[j]%=10;
        }
        while(c)
        {
            data[++digit]=c%10;
            c/=10;
        }

        }
	printf("%d!=", n);
	for(i = digit; i > 0; i--)
		printf("%d", data[i]);
    printf("\n");
	return data;
}

int main()
{
	int n;

	//printf("Enter a positive number :");
	//scanf("%d", &n);
	for(n=1;n<=100;n++)
    {
             calcfact(n);
    }

	return 0;
}

