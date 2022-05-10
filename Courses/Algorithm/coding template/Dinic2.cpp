#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#define INF 2147483647
#define max 10005
struct node{
	int a,b,c,num;
}p[105];
int min(int a,int b){
	if(a<b) return a;
	return b;
}
struct Edge{
	int v;
	int c;
	int next;
}e[max];
int head[max],e_num=-1;
int n,m,S,T;
int cmp(const void *a,const void *b){
	struct node c,d;
	c=*(struct node*)a;
	d=*(struct node*)b;
	return c.c-d.c;
}
void add(int u,int v,int c){
	e_num++;
	e[e_num].v=v;
	e[e_num].c=c;
	e[e_num].next=head[u];
	head[u]=e_num;
}
void insert(int u,int v,int c){
	add(u,v,c);
	add(v,u,c);
}
int depth[max];// 层次网络 
bool bfs()
{
    std::queue<int> q;//定义一个bfs寻找分层图时的队列
    while (!q.empty()) q.pop();
    memset(depth,-1,sizeof(depth));
    depth[S]=0;//源点深度为0
    q.push(S);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(e[i].c>0&&depth[v]==-1){
                q.push(v);
                depth[v]=depth[u]+1;
            }
        }
    }
    return (depth[T]!=-1);
}
int dfs(int u,int flow){        //flow表示当前搜索分支的流量上限
    if(u==T){
        return flow;
    }
    int res=0;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(e[i].c>0&&depth[u]+1==depth[v]){
            int tmp=dfs(v,min(flow,e[i].c));    // 递归计算顶点 v，用 c(u, v) 来更新当前流量上限
            flow-=tmp;
            e[i].c-=tmp;
            res+=tmp;
            e[i^1].c+=tmp;      // 修改反向弧的容量
            if(flow==0){        // 流量达到上限，不必继续搜索了
                break;
            }
        }
    }
    if(res==0){     // 当前没有经过顶点 u 的可行流，不再搜索顶点 u
        depth[u]=-1;
    }
    return res;
}
int dinic(){        // 函数返回值就是最大流的结果
    int res=0;
    while(bfs()){
        res+=dfs(S,INF);    // 初始流量上限为 INF
    }
    return res;
}
int main(){
	int i,j;
	int ans[505]={};
    scanf("%d%d",&n,&m);//m为边
    for(i=0;i<m;i++){
        scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
        p[i].num=i;
    }
    qsort(p,m,sizeof(struct node),cmp);
    for(i=0;i<m;i++){
    	memset(head,-1,sizeof(head));
    	memset(e,0,sizeof(e));
    	e_num=-1;
    	S=p[i].a,T=p[i].b;
    	for(j=i;j>=0;j--){
    		if(p[j].c==p[i].c) continue;
    		insert(p[j].a,p[j].b,1);
		}	
		ans[p[i].num]=dinic();
	}
	for(i=0;i<m;i++){
		printf("%d ",ans[i]);
	}
    return 0;
}
