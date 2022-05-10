#include<stdio.h>
#define INFINITY 2000000000
int n,m,s,a,b,c;
int wfound[100];
int Sweight[100];
int Weights[100][100];
int Spath[100];
int i,j;
void Dijkstra()
{
    int i, j, v, minweight;
    for(i=1; i<=n; i++) { Sweight[i] = Weights[1][i]; Spath[i] = 1; }  //初始化数组Sweight和Spath
    Sweight [1] = 0;  
    wfound [1] = 1;  
    for(i=1; i<= n-1; i++) {  //迭代VNUM-1次
        minweight = INFINITY;
        for(j=1; j <= n;  j++)   //找到未标记的最小权重值顶点 
            if( !wfound[j] && ( Sweight[j] < minweight) ) {
                v = j; 
                minweight = Sweight[v];
            }
        wfound[v] = 1;	//标记该顶点为已找到最短路径
        for(j =1; j <= n; j++) //找到未标记顶点且其权值大于v的权值+(v,j)的权值，更新其权值
            if( !wfound[j]  &&  (minweight + Weights[v][j] < Sweight[j] )) {
                Sweight[j] = minweight + Weights[v][j];
                Spath[j] = v;  //记录前驱顶点
            }
    } 
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			Weights[i][j]=INFINITY;
		}
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);	
		Weights[a][b]=c;
	}
	Dijkstra();
	for(i=1;i<=n;i++){
		printf("%d ",Sweight[i]);
	}
}
