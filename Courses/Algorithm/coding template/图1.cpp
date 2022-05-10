#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define max 300005
using namespace std;
typedef long long ll;
struct node {
	int a,b,c;
} ver[max];
struct Edge {
	int v;
	int c;
	int next;
} e[max];
int head[max],e_num=0;
int n,m,S,T;
ll mid;
int color[max],vis[max];
void add(int u,int v,int c) {
	e[e_num].v=v;
	e[e_num].c=c;
	e[e_num].next=head[u];
	head[u]=e_num;
	e_num++;
}
void insert(int u,int v,int c) {
	add(u,v,c);
	add(v,u,c);
}
bool dfs(int u, int c)
{
	vis[u]=1;
    color[u]=c;
    for(int i=head[u];~i;i=e[i].next)
    {
        int j=e[i].v;
        if(!color[j])
        {
            if(!dfs(j, 3-c)) return false;
        }
        else if(color[j]==c) return false;
    }
    return true;
}
bool check() {
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	memset(color,0,sizeof(color));
	for(int i=1; i<=m; i++) {
		if(ver[i].c>mid) insert(ver[i].a,ver[i].b,ver[i].c);//如果大则连边
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			if(!dfs(i,1)) return false;
		}
	}
	return true;
}
int main() {
	int a,b,c;
	ll ans;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&ver[i].a,&ver[i].b,&ver[i].c);
	}
	ll l=0,r=1e14;
	while(l<=r){
		mid=((l+r)>>1);
		if(check()) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
}
