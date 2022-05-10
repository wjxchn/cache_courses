#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int x;
	int y;
	bool operator <(const node & w) const
	{
		return x>w.x;
	}
}r;
int m;
int inf=1000000001;
int n;
int i;
int a[200010],p[200010];
priority_queue<node> q;
int u,v,w;
long long price;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i],&p[i]);
		r.x=p[i];
		r.y=i;
		q.push(r);
		if(m<a[i]){
			m=a[i];
		}
		if(inf>a[i]){
			inf=a[i];
		}
	}
	r=q.top();
	u=r.x;
	v=r.y;
	price=price+u*(m-a[v]);
	//printf("%d %d",m,a[v]);
	q.pop();
	while(!q.empty()&&a[v]!=0){
		r=q.top();
		u=r.x;
		w=r.y;
		if(a[w]<a[v]){
			price+=u*(a[v]-a[w]);
			v=w;
		}
		q.pop();
	}
	printf("%lld",price);
}
