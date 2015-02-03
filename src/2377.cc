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

int n,m;
typedef struct edge{
	int start,end;
	int cost;
	bool operator< (const struct edge &a)const{
		return cost > a.cost;
	}
}edge;

const int maxm=20001;
const int maxn=1001;
int fa[maxn];
struct edge edges[maxm];

void init(int n){
	for(int i = 0; i <= n; ++i){
		fa[i] = i;
	}
}
int findfa(int x){
	if(x == fa[x]){
		return x;
	}
	int f = findfa(fa[x]);
	fa[x] = f;
	return f;
}
void merge(int x,int y){
	int fx = findfa(x);
	int fy = findfa(y);
	if(fx != fy){
		fa[fx] = fy;
	}
}

int main()
{
	while(scanf("%d%d",&n,&m) != EOF){
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d",&edges[i].start,&edges[i].end,&edges[i].cost);
		}
		sort(edges,edges+m);
		init(n);
		//for(int i = 0; i < m; ++i){
			//cout << edges[i].start << "->" << edges[i].end << "=" << edges[i].cost << endl;
		//}
		int cnt = 0;
		int ans = 0;
		for(int i = 0; i < m; ++i){
			if(findfa(edges[i].start) != findfa(edges[i].end)){
				merge(edges[i].start,edges[i].end);
				cnt++;
				ans += edges[i].cost;
				//cout << "edge" << edges[i].cost << endl;
			}
			if(cnt == n-1){
				break;
			}
		}
		//cout << cnt << endl;
		if(cnt == n-1){
			printf("%d\n",ans);
		}else{
			printf("-1\n");
		}
	}

	return 0;
}
