#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int i;
int w[200010];
int dp[200010][20];
int m;
int a[10010],b[10010];
int j;
int k;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		dp[i][0]=w[i];
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	
	for(j=1;j<=(int)(log(n*1.0)/log(2.0));j++){
		for(i=1;i+(1<<j)-1<=n;i++){
			dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
		}
	}
	for(i=0;i<m;i++){
		k=(int)(log((b[i]-a[i]+1)*1.0)/log(2.0));
		printf("%d\n",max(dp[a[i]][k],dp[b[i]-(1<<k)+1][k]));
	}
}
