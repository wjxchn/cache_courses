#include<stdio.h>
int main()
{
	int a[5];
	int i,j,k;
	double n;
	scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	for(i=0;i<5;i++)
	{
		for (j=i+1;j<5;j++)
		{
			if(a[i]<a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	printf("%d\n",a[2]);
	n=(a[0]+a[1]+a[2]+a[3]+a[4])/5.0;
	printf("%.2lf",n);
	return 0;
}
