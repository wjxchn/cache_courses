#include<cstdio>
#include<cstring>
using namespace std;
char s[1010];
int i;
int t;
int n;
int a[50];
int c[50];
int b[100000];
int main()
{
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&b[i]);
	}
	a[1]=2;
	a[2]=2;
	for(i=3;i<50;i++){
		if(i<=12){
			c[i]=a[i-2];
			a[i]=a[i-1]+c[i];
		}
		else if(i<=20){
			c[i]=a[i-2]-a[i-12];
			a[i]=a[i-1]+c[i];
		}
		else if(i==21){
			c[i]=c[i-2]+c[i-3]+c[i-4]+c[i-5]+c[i-6]+c[i-7]+c[i-8]+c[i-9]+c[i-10]+c[i-11];
			a[i]=a[i-1]-a[1]+c[i];
		}
		else if(i==22){
			c[i]=c[i-2]+c[i-3]+c[i-4]+c[i-5]+c[i-6]+c[i-7]+c[i-8]+c[i-9]+c[i-10]+c[i-11];
			a[i]=a[i-1]+c[i];
		}
		else if(i>=23){
			c[i]=c[i-2]+c[i-3]+c[i-4]+c[i-5]+c[i-6]+c[i-7]+c[i-8]+c[i-9]+c[i-10]+c[i-11];
			a[i]=a[i-1]-c[i-20]+c[i];
		}
	}
	for(i=0;i<t;i++){
		printf("%d\n",a[b[i]]);		
	}
}
