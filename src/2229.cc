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

const int maxn = 1000001;
int dp[maxn];

void init(){
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <maxn; ++i){
		if(i % 2){
			dp[i] = dp[i-1];
		}else{
			dp[i] = dp[i/2]+dp[i-1];
		}
		dp[i] %= 1000000000;
	}
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n) != EOF){
		printf("%d\n",dp[n]);
	}

	return 0;
}
