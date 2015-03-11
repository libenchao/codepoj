#include<limits.h>
#include<cmath>
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

const int maxn = 10001;
double data[maxn];

int main()
{
	int n,k;
	while(cin >> n >> k){
		for(int i = 0; i < n; ++i){
			cin >> data[i];
		}
		double ulimit = data[0];
		for(int i = 1; i < n; ++i){
			if(data[i] > ulimit){
				ulimit = data[i];
			}
		}
		double llimit = 0.00;
		bool found = false;
		while(ulimit-llimit >=0.01){
			double mlimit = (ulimit-llimit)/2+llimit;
			int cnt = 0;
			for(int i = 0; i < n; ++i){
				cnt += data[i]/mlimit;
			}
			if(cnt < k){
				ulimit = mlimit;
			}else{
				found = true;
				llimit = mlimit;
			}
		}
		if(found){
			printf("%.2f\n",(floor(llimit*100))/100);
		}
		else{
			printf("0.00\n");
		}
	}
	return 0;
}
