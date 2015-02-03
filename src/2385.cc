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

const int T=1002;
const int W=31;
int opt[T][W][2];
int t,w;
int apples[T];

void pp(){
	for(int i = 0; i <= t; ++i){
		for(int j = 0; j <= w; ++j){
			cout << "opt[" << i << "][" << j << "][0]=" << opt[i][j][0] << "  " ;
			cout << "opt[" << i << "][" << j << "][1]=" << opt[i][j][1] << endl;
		}
	}
}

int main()
{
	while(scanf("%d%d",&t,&w) != EOF){
		for(int i = 1; i <= t; ++i){
			int tree;
			scanf("%d",&tree);
			apples[i] = tree;
		}
		//for(int i = 1; i <= t; ++i){
			//cout << apples[i] << endl;
		//}
		for(int i = 0; i <= w; ++i){
			opt[1][i][0] = apples[1]==1?1:0;
		}
		opt[1][0][1] = 0;
		for(int i = 1; i <= w; ++i){
			opt[1][i][1] = apples[1]==2?1:0;
		}
		//pp();
		for(int i = 2; i <= t; ++i){
			for(int j = 0; j <= w; ++j){
				if(j > 0){
					opt[i][j][0] = max(opt[i-1][j-1][1],opt[i-1][j][0])+(apples[i]==1?1:0);
					opt[i][j][1] = max(opt[i-1][j-1][0],opt[i-1][j][1])+(apples[i]==2?1:0);
				}else{
					opt[i][j][0] = opt[i-1][j][0] + (apples[i] == 1?1:0);
					opt[i][j][1] = opt[i-1][j][1] + (apples[i] == 2?1:0);
				}
			}
		}
		//pp();
		printf("%d\n",max(opt[t][w][0],opt[t][w][1]));
	}
	return 0;
}
