#include<cstdio>
using namespace std;
int t;
int n,m;
int a,b,c;
int i,j,k;
int s[205][205];
int w;
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		w=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				s[i][j]=-1;
			}
		}
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			s[a][b]=c;
		}
		for(k=1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(s[i][j]>s[i][k]+s[k][j]&&s[i][k]!=-1&&s[k][j]!=-1){
						s[i][j]=s[i][k]+s[k][j];
					}
					else if(s[i][j]==-1&&s[i][k]!=-1&&s[k][j]!=-1&&i!=j){
						s[i][j]=s[i][k]+s[k][j];
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(w<s[i][j]){
					w=s[i][j];
				}
			}
		}
		//printf("%d",w);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(w==s[i][j]&&i!=j){
					printf("%d %d\n",i,j);
				}
			}
		}
	}
}
