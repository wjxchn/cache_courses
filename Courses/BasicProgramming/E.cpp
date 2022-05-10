#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char c[110];
char d[110];

void sort(char array[110],int n);
int main()
{
	int a,b,i,j,t;
	scanf("%s %s",&c,&d);
	a=strlen(c);
	b=strlen(d);
	if(a!=b){
		printf("NIE\n");
	}
	else if(a==b){
        for(i=0;i<b;i++){
        	for(j=0;j<b-i-1;j++){
        		if(c[j]>c[j+1]){
        			t=c[j];
        			c[j]=c[j+1];
        			c[j+1]=t;
				}
			}
		}
		for(i=0;i<b;i++){
        	for(j=0;j<b-i-1;j++){
        		if(d[j]>d[j+1]){
        			t=d[j];
        			d[j]=d[j+1];
        			d[j+1]=t;
				}
			}
		}
        for(i=0;i<b;i++){
        	if(c[i]!=d[i]){
        		printf("NIE\n");
        		break;
			}
			if(i==b-1){
               printf("TAK\n");
			}
		}		
	}
}
