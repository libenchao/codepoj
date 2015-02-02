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
pair<pair<int,int>,pair<int,int> >  data[maxn];

bool func1(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b){
	return a.first.first < b.first.first;
}

bool func2(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b){
	return a.second.first < b.second.first;
}

class Comp{
	public:
		bool operator() (pair<int,int> a,pair<int,int> b){
			return a.first > b.first;
		}
};

int main()
{
	int n;
	while(scanf("%d",&n)!= EOF){
		for(int i = 0; i < n; ++i){
			int start,end;
			scanf("%d%d",&start,&end);
			data[i] = make_pair(make_pair(start,end),make_pair(i,0));
		}
		sort(data,data+n,func1);
		priority_queue<pair<int,int> ,vector<pair<int,int> >,Comp> pq;
		for(int i = 0; i < n; ++i){
			if(pq.size() == 0 || pq.top().first >= data[i].first.first){
				pq.push(make_pair(data[i].first.second,pq.size()+1));
				data[i].second.second = pq.size();
			}else{
				pair<int,int> tmp = pq.top();
				pq.pop();
				tmp.first = data[i].first.second;
				pq.push(tmp);
				data[i].second.second = tmp.second;
			}
			//cout << "pop:" << pq.top().first << " " << pq.top().second << endl;
		}
		printf("%d\n",pq.size());
		sort(data,data+n,func2);
		//for(int i = 0; i < n; ++i){
			//cout << "ans:" << data[i].second.first << "->" << data[i].second.second << endl;
		//}
		for(int i = 0; i < n; ++i){
			printf("%d\n",data[i].second.second);
		}
	}
	return 0;
}
