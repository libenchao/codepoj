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

const int maxn = 50001;
pair<int,int> data[maxn];
int ret[maxn];

bool func(pair<int,int> a,pair<int,int> b){
	return a.first < b.first;
}

int main()
{
	int n;
	while(scanf("%d",&n)!= EOF){
		map<pair<int,int>,int> mm;
		for(int i = 0; i < n; ++i){
			int start,end;
			scanf("%d%d",&start,&end);
			data[i] = make_pair(start,end);
			mm[data[i]] = i;
		}
		sort(data,data+n,func);
		vector<int> ans;
		for(int i = 0; i < n; ++i){
			bool found = false;
			for(int j = 0; j < ans.size(); ++j){
				if(ans[j] < data[i].first){
					found = true;
					ans[j] = data[i].second;
					ret[mm[data[i]]] = j+1;			
					break;
				}
			}
			if(!found){
				ans.push_back(data[i].second);
				ret[mm[data[i]]] = ans.size();
			}
		}
		printf("%d\n",ans.size());
		for(int i = 0; i < n; ++i){
			printf("%d\n",ret[i]);
		}
	}
	return 0;
}
