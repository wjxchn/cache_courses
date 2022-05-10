#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int n,i,a,c,d,e,s;
int main()
{
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			scanf("%d",&a);
			q.push(a);
		}
		s=0;
		while(q.size()>=3){
			c=q.top();
			q.pop();
			d=q.top();
			q.pop();
			e=q.top();
			q.pop();
			q.push(c+d+e);
			s=s+c+d+e;
			//printf("%d",c);
		}
		printf("%d\n",s);
		while(!q.empty()){
			q.pop();
		}
	}
}
