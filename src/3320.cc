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

const int maxn = 1000001;
int data[maxn];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 0;i < n; ++i){
			scanf("%d",&data[i]);
		}
		map<int,int> mm;
		for(int i = 0; i < n; ++i){
			mm[data[i]]++;
		}
		int count = mm.size();
		mm.clear();
		int cur = 0;
		count--;
		mm[data[0]]++;
		while(count){
			if(mm[data[cur+1]] == 0){
				count--;
			}
			mm[data[cur+1]]++;
			cur++;
		}
		int ans = cur+1;
		int left = 0;
		int right = cur;
		while(true){
			if(--mm[data[left++]] == 0){
				right++;
				mm[data[right]]++;
				while(right < n && data[right] != data[left-1]){
					right++;
					if(right != n){
						mm[data[right]]++;
					}
				}
				if(right >= n){
					break;
				}
			}
			if(right-left+1 < ans){
				ans = right-left+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
