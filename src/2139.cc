#include<limits.h>
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
const int maxn = 301;
int dist[maxn],flag[maxn];
int edges[maxn][maxn];
int n,m;
void init(int n){
	for(int i = 0; i <= n; ++i){
		dist[i] = INT_MAX;
		flag[i] = 0;
	}
}
void dijkstra(int s){
	init(n);
	dist[s] = 0;
	flag[s] = 1;
	for(int i = 0; i < n-1; ++i){
		bool first = true;
		int cur;
		for(int i = 1; i <= n; ++i){
			if(flag[i] == 1){
				if(first){
					first = false;
					cur = i;
				}else if(dist[i] < dist[cur]){
					cur = i;
				}
			}
		}
		flag[cur] = 2;
		for(int i = 1; i <= n; ++i){
			if(flag[i] < 2 && edges[cur][i] > 0){
				if(dist[cur]+edges[cur][i] < dist[i]){
					dist[i] = dist[cur]+edges[cur][i];
					flag[i] = 1;
				}
			}
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&m) != EOF){
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= n; ++j){
				edges[i][j] = -1;
			}
		}
		for(int i = 0; i < m; ++i){
			int cnt ;
			scanf("%d",&cnt);
			for(int j = 0; j < cnt; ++j){
				scanf("%d",&flag[j]);
			}
			for(int j = 0; j < cnt; ++j){
				for(int k = j+1; k < cnt; ++k){
					edges[flag[j]][flag[k]] = 1;
					edges[flag[k]][flag[j]] = 1;
				}
			}
		}
		int ret = INT_MAX;
		for(int i = 1; i <= n; ++i){
			dijkstra(i);
			int sum = 0;
			for(int i = 1; i <= n; i++){
				sum += dist[i];
			}
			if(sum < ret){
				ret = sum;
			}
		}
		printf("%d\n",ret*100/(n-1));
	}
	return 0;
}
