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
int data[maxn];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,S;
		scanf("%d%d",&n,&S);
		for(int i = 0; i < n; ++i){
			scanf("%d",&data[i]);
		}
		int ans = 0;
		int left = 0,right = 0;
		int sum = data[0];
		while(true){
			if(sum >= S){
				if(ans == 0){
					ans = right-left+1;
				}else if(right-left+1 < ans){
					ans = right-left+1;
				}
				sum -= data[left];
				left++;
			}else{
				sum += data[right+1];
				right++;
			}
			if(right >= n){
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
