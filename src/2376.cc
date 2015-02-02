#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 25001;
pair<int,int> data[MAXN];

bool func(pair<int,int> a,pair<int,int> b){
	return a.first < b.first;
}

int main()
{
	int n,t;
	while(scanf("%d%d",&n,&t) != EOF){
		for(int i = 0; i < n; ++i){
			int start,end;
			scanf("%d%d",&start,&end);
			data[i] = make_pair(start,end);
		}
		sort(data,data+n,func);
		int cur = 1;
		int dcur = 0;
		int ans = 0;
		bool solvable = true;
		while(cur <= t){
			pair<int,int> hehe;
			bool found = false;
			for(;dcur < n;dcur++){
				if(data[dcur].first <= cur && data[dcur].second >= cur){
					if(found && data[dcur].second > hehe.second){
						hehe = data[dcur];
					}else if(!found){
						found = true;
						hehe = data[dcur];
					}
				}else if(data[dcur].first > cur){
					break;
				}
			}
			if(!found){
				solvable = false;
				break;
			}
			ans++;
			cur = hehe.second+1;
		}
		if(solvable){
			printf("%d\n",ans);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
