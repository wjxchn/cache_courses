#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1000005;
const int MAXM=1000005;
int d[MAXN],n,m,p[MAXN],eid,S,T,x[MAXN],y[MAXN],z[MAXN],a[105][105],sz,sum;
struct A{  //�ҳ��������������Dinic��
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
	add(v,u,0);
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
int main(){    //���¿�ʼ���ͻ�䣨����yjq��Ĥ����
	init();
	scanf("%d%d", &m, &n);
	S=0;T=n*m+1;//����Դ��ͻ��
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			sum += a[i][j];
			sz ++;
			if((i + j) % 2){
				insert(S, sz, a[i][j]);//����Դ��
				if(j < n) insert(sz, sz + 1, INF);//������������������������Ȩע��Ҫ������
				if(j > 1) insert(sz, sz - 1, INF);
				if(i < m) insert(sz, sz + n, INF);
				if(i > 1) insert(sz, sz - n, INF);
			} else {
				insert(sz,T,a[i][j]);//������
			}
		}
	} 
	printf("%d",sum - Dinic());//�ܵı�Ȩ - ���������С�
	return 0;
}
