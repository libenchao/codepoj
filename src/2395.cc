#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
typedef struct edge{
	int start,end,val;
	bool operator< (const struct edge &a)const{
		return this->val < a.val;
	}
}edge;
const int maxn = 2002;
const int maxm = 10002;
edge edges[maxm];
int fa[maxn];
void init(int n){
	for(int i = 0; i <= n; ++i){
		fa[i] = i;
	}
}
int getfa(int x){
	if(x == fa[x]){
		return x;
	}
	int f = getfa(fa[x]);
	fa[x] = f;
	return fa[x];
}
void merge(int x,int y){
	int xf = getfa(x);
	int yf = getfa(y);
	if(xf != yf){
		fa[xf] = yf;
	}
}
int n,m;

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d",&edges[i].start,&edges[i].end,&edges[i].val);
		}
		init(n);
		sort(edges,edges+m);
		int cnt = 0;
		int cur = 0;
		while(cnt < n-1){
			if(getfa(edges[cur].start) != getfa(edges[cur].end)){
				cnt++;
				merge(edges[cur].start,edges[cur].end);
			}
			cur++;
		}
		printf("%d\n",edges[cur-1].val);
	}
	return 0;
}
