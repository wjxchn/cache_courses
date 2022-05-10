//codevs 1993
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x7ffffff;

queue <int> q;
int n,m,x,y,s,t,g[201][201],pre[201],flow[201],maxflow; 
//g�ڽӾ����ͼ��pre����·����ÿ�����ǰ����flowԴ�㵽���������� 
int a,b;
inline int bfs(int s,int t)
{
    while (!q.empty()) q.pop();
    for (int i=1; i<=n; i++) pre[i]=-1;
    pre[s]=0;
    q.push(s);
    flow[s]=INF;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        if (x==t) break;
        for (int i=1; i<=n; i++)
          //EKһ��ֻ��һ������· 
          if (g[x][i]>0 && pre[i]==-1)
          {
            pre[i]=x;
            flow[i]=min(flow[x],g[x][i]);
            q.push(i);
          }
    }
    if (pre[t]==-1) return -1;
    else return flow[t];
}

//increaseΪ��������� 
void EK(int s,int t)
{
    int increase=0;
    while (bfs(s,t)!=-1)
    {//���� 
        int k=t;
        while (k!=s)
        {
            int last=pre[k];//�Ӻ���ǰ��·��
            g[last][k]-=increase;
            g[k][last]+=increase;
            k=last;
        }
        maxflow+=increase;
    }
}

int main()
{
    scanf("%d%d%d%d",&a,&m,&b,&n);
    for (int i=1; i<=m; i++)
    {
        int z;
        scanf("%d%d%d",&x,&y,&z);
        g[x][y]+=z;//�˴�����ֱ�����룬Ҫ+= 
    }
    EK(b,n);
    printf("%d",maxflow);
    return 0;
}
