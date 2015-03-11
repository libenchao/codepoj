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

const int maxn = 100001;
int stall[maxn];
int n;
int c;

int main()
{
	while(scanf("%d%d",&n,&c) != EOF){
		for(int i = 0; i < n; ++i){
			scanf("%d",&stall[i]);
		}
		sort(stall,stall+n);
		int left = 1,right = 1000000000;
		bool found = false;
		int ans = 0;
		while(left <= right){
			int mid = left + (right-left)/2;
			int cnt = 1;
			int last = stall[0];
			int cur = 1;
			bool ok = false;
			while(cur < n){
				while(cur<n && stall[cur]-last < mid){
					cur++;
				}
				if(cur >= n){
					break;
				}
				cnt++;
				last = stall[cur];
				if(cnt >= c){
					ok = true;
					break;
				}
			}
			if(ok){
				found = true;
				ans = mid;
				left = mid+1;
			}else{
				right = mid-1;
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}
