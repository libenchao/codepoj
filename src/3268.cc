#include<iostream>
#include<limits.h>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 1001;
int edges[maxn][maxn];
int n,m,x;
int flag[maxn],dist1[maxn],dist2[maxn];

void init(int n){
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= n; ++j){
			edges[i][j] = -1;
		}
	}
}
void init1(int n){
	for(int i = 0; i <= n; ++i){
		flag[i] = 0;
		dist1[i] = INT_MAX;
	}
}
void init2(int n){
	for(int i = 0; i <= n; ++i){
		flag[i] = 0;
		dist2[i] = INT_MAX;
	}
}

int main()
{
	while(scanf("%d%d%d",&n,&m,&x)!=EOF){
		init(n);
		for(int i = 0; i < m; ++i){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			edges[a][b] = c;
		}
		init1(n);
		flag[x] = 1;
		dist1[x] = 0;
		for(int i = 0; i < n-1; ++i){
			bool first = true;
			int cur;
			for(int j = 1; j <= n; ++j){
				if(flag[j] == 1){
					if(first){
						cur = j;
						first = false;
					}
					else if(dist1[j] < dist1[cur]){
						cur = j;
					}
				}
			}
			flag[cur] = 2;
			for(int j = 1; j <= n; ++j){
				if(flag[j] < 2 && edges[cur][j] > 0){
					if(dist1[cur]+edges[cur][j] < dist1[j]){
						dist1[j] = dist1[cur]+edges[cur][j];
						flag[j] = 1;
					}
				}
			}
		}
		init2(n);
		flag[x] = 1;
		dist2[x] = 0;
		for(int i = 0; i < n-1; ++i){
			bool first = true;
			int cur;
			for(int j = 1; j <= n; ++j){
				if(flag[j] == 1){
					if(first){
						cur = j;
						first = false;
					}
					else if(dist2[j] < dist2[cur]){
						cur = j;
					}
				}
			}
			flag[cur] = 2;
			for(int j = 1; j <= n; ++j){
				if(flag[j] < 2 && edges[j][cur] > 0){
					if(dist2[cur]+edges[j][cur] < dist2[j]){
						dist2[j] = dist2[cur]+edges[j][cur];
						flag[j] = 1;
					}
				}
			}
		}
		int ans = -1;
		for(int i = 1; i <= n; ++i){
			if(dist1[i]+dist2[i] > ans){
				ans = dist1[i]+dist2[i];
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
