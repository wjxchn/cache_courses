#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int a,b,c,d,k;
int w[3000010];
int e,f;
int i;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	while(~scanf("%d%d%d%d%d",&a,&b,&c,&d,&k)){
		w[0]=d;
		q.push(d);
		for(i = 1; i < 3000000; i++){
			w[i] = ((1LL * w[i - 1] * a ^ b) + c) % 1000000007;
			q.push(w[i]);
			printf("%d",upper_bound(w));
		}
    			
    	//sort(w,w+3000000);
    	e=1;
    	f=q.top();
    	q.pop();
		while(e!=k){
			if(f!=q.top()){
				f=q.top();
				e++;
			}
			q.pop();
		}
		printf("%d\n",f);	
		while(!q.empty()){
			q.pop();
		}
	}
}
