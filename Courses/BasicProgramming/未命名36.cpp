#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n%12==0||n%12==11){
		printf("0:0:0.0000000");
	}
	else if(n%12==1){
		printf("1:5:27.2727273");
	}
	else if(n%12==2){
		printf("2:10:54.5454545");
	}
	else if(n%12==3){
		printf("3:16:21.81818180");
	}
	else if(n%12==4){
		printf("4:21:49.0909091");
	}
	else if(n%12==5){
		printf("5:27:16.3636364");
	}
	else if(n%12==6){
		printf("6:32:43.6363636");
	}
	else if(n%12==7){
		printf("7:38:10.9090909");
	}
	else if(n%12==8){
		printf("8:43:38.1818182");
	}
	else if(n%12==9){
		printf("9:49:5.4545455");
	}
	else if(n%12==10){
		printf("10:54:0.0000000");
	}
	return 0;	
}
