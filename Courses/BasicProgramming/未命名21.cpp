#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("(%d,%d,%d)",&a,&b,&c);
	if(a<100000000){
	    printf("%08d\n%o\n%X\n",a,b,c);
    }
    else{
    	printf("%d\n%o\n%X\n",a,b,c);
	}	    
	return 0; 
}
