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

const int MAXN = 100001;
int S[MAXN*2];

void init(int n){
	for(int i = 0; i <= n*2; ++i){
		S[i] = i;
	}
}
int find(int x){
	if(S[x] == x){
		return x;
	}
	int ret =  find(S[x]);
	S[x] = ret;
	return S[x];
}
void merge(int x,int y){
	int px = find(x);
	int py = find(y);
	if(px != py)S[px] = py;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		init(n);
		for(int i = 0; i<m; ++i){
			char ch[5];
			int x,y;
			scanf("%s%d%d",ch,&x,&y);
			if(ch[0] == 'A'){
				if(find(x) == find(y)){
					cout << "In the same gang." << endl;
				}else if(find(x) == find(y+n)){
					cout << "In different gangs." << endl;
				}else{
					cout << "Not sure yet." << endl;
				}
			}else{
				merge(x,y+n);
				merge(x+n,y);
			}
		}
	}
	return 0;
}
