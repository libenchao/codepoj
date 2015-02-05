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

int main()
{
	int data[10];
	int n;
	int t;
	cin >> t;
	getchar();
	while(t--){
		n = 0;
		while(true){
			char ch = getchar();
			if(ch == '\n'){
				break;
			}
			if(ch == ' '){
				continue;
			}
			data[n++]=ch-'0';
		}
		sort(data,data+n);
		if(n % 2){
			int big = 0;
			if(data[0]==0){
				big+=data[1];
				big*=10;
			}else{
				big+=data[0];
				big*=10;
				big+=data[1];
			}
			for(int i = 2; i <= n/2;++i){
				big*=10;
				big+=data[i];
			}
			int small = 0;
			for(int i = n-1; i > n/2; --i){
				small *= 10;
				small += data[i];
			}
			cout << big-small << endl;
		}else{
			if(n==2){
				cout << data[1]-data[0] << endl;
				continue;
			}
			
			cout << big-small << endl;
		}
	}
	return 0;
}
