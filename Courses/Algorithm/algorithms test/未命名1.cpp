#include<cstdio>
#include<algorithm>
using namespace std;
int n,i;
int v[100010];
int w[100010];
int u;
int main()
{
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++){
			scanf("%d",&v[i]);
		}
		w[1]=v[1];
		for(i=2;i<=n;i++){
			w[i]=max(w[i-1],w[i-2]+v[i]);
		}
		//u=max(w[i],w[i-1]+v[0]);
		printf("%d",w[n]);
	}
}
