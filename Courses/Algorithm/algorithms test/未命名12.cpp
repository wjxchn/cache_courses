#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int i,j;
int s;
int a[100];
int b[100][100];
int main()
{
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<n;i++)
		{
			//b[i][i]=a[i];
			b[i][i+1]=max(a[i],a[i+1]);
		}
		
		for(i=1;i<=n-1;i++){
			j=i+2;
			while(j!=i+1){
				/*if(j==n+1){
					b[i][1]=max(b[i][j-2]+a[1],b[i][j-1]);
					j=1;
				}
				else if(j==n+2){
					b[i][2]=max(b[i][j-2]+a[2],b[i][1]);
					j=2;
				}
				else{
					b[i][j]=max(b[i][j-2]+a[j],b[i][j-1]);
				}*/
				if(j==n+1){
					b[i][1]=max(b[i][j-2]+a[1],b[i][j-1]);
					j=1;
				}
				else{
					b[i][j]=max(b[i][j-2]+a[j],b[i][j-1]);
				}
				j++;
			}
		}
		b[n][1]=max(a[n],a[1]);
		b[n][2]=max(b[n][1],b[n][n]+a[2]);
		for(j=3;j<=n;j++){
			b[n][j]=max(b[n][j-2]+a[j],b[n][j-1]);
		}
		for(i=2;i<=n;i++){
			s=max(s,b[i][i-1]);
		}
		s=max(s,b[n][1]);
		printf("%d\n",s);
	}
	
}
