#include<stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d\n%d%d%d",&a,&b,&c,&d,&e,&f);
	if(a<d&&b==e&&c==f){
		printf("Anniversary!");
	}
	else{
		if(f%10==1&&f!=11){
			printf("%dst",f);
		}
		else if(f%10==2&&f!=12){
			printf("%dnd",f);
		}
		else if(f%10==3&&f!=13){
			printf("%drd",f);
		}
		else{
			printf("%dth",f);
		}
		if(e==1){
			printf(" Jan.");
		}
		else if(e==2){
			printf(" Feb.");
		}
		else if(e==3){
			printf(" Mar.");
		}
		else if(e==4){
			printf(" Apr.");
		}
		else if(e==5){
			printf(" May.");
		}
		else if(e==6){
			printf(" Jun.");
		}
		else if(e==7){
			printf(" Jul.");
		}
		else if(e==8){
			printf(" Aug.");
		}
		else if(e==9){
			printf(" Sept.");
		}
		else if(e==10){
			printf(" Oct.");
		}
		else if(e==11){
			printf(" Nov.");
		}
		else{
			printf(" Dec.");
		}
	}
	return 0;
} 
