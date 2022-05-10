#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1000005;
const int MAXM=1000005;
int d[MAXN],n,m,p[MAXN],eid,S,T,x[MAXN],y[MAXN],z[MAXN],a[105][105],sz,sum;
int l[MAXN],r[MAXN],w[MAXN];
int i;
struct A{  //灰常正常的最大流（Dinic）
	int v,c,next;
}e[MAXM];
void init(){
	memset(p,-1,sizeof(p));
	eid=0;
}
void add(int u,int v,int c){
	e[eid].v=v;
	e[eid].c=c;
	e[eid].next=p[u];
	p[u]=eid++;
}
void insert(int u,int v,int c){
	add(u,v,c);
	add(v,u,c);
}
int bfs(){
	memset(d,-1,sizeof(d));
	queue<int>q;
	d[S]=0;
	q.push(S);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=p[u];i!=-1;i=e[i].next){
			int v=e[i].v;
			if(e[i].c>0&&d[v]==-1){
				d[v]=d[u]+1;
				q.push(v);	
			}
		}
	}
	return (d[T]!=-1);
}
int dfs(int u,int flow){ 
	if(u==T) return flow;
	int ret=0;
	for(int i=p[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(e[i].c>0&&d[v]==d[u]+1){
			int tmp=dfs(v,min(flow,e[i].c));
			e[i].c-=tmp;
			e[i^1].c+=tmp;
			flow-=tmp;
			ret+=tmp;
			if(!flow) break;
		}
	}
	if(!ret) d[u]=-1;
	return ret;
}
int Dinic(){
	int ret=0;
	while(bfs()){
		ret+=dfs(S,INF);
	}
	return ret;
}
int main(){    //以下开始码风突变（中了yjq的膜法）
	init();
	scanf("%d%d", &n, &m);
	S=1;T=n;//建立源点和汇点
	for(i=0;i<m;i++){
		scanf("%d%d%d",&l[i],&r[i],&w[i]);
		insert(l[i],r[i],w[i]);
	}
	printf("%d",Dinic());//总的边权 - 最大流（最小割）
	return 0;
}
