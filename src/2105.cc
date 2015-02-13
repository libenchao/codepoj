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

int main()
{
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		int num = 0;
		for(int i = 0; i < 8; ++i){
			num*=2;
			num+=s[i]-'0';
		}
		cout << num << ".";
		num = 0;
		for(int i = 8; i < 16; ++i){
			num *= 2;
			num += s[i]-'0';
		}
		cout << num << ".";
		num = 0;
		for(int i = 16; i < 24; ++i){
			num *= 2;
			num +=s[i]-'0';
		}
		cout << num << ".";
		num = 0;
		for(int i = 24; i < 32; ++i){
			num *= 2;
			num +=s[i]-'0';
		}
		cout << num << endl;
	}
			
	return 0;
}
