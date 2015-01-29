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

bool sub(vector<int> &cur,vector<bool> &used, int m){
	if(cur.size() == used.size()){
		vector<int> tmp(cur);
		while(tmp.size() != 1){
			for(int i = 0; i < tmp.size()-1; ++i){
				tmp[i] = tmp[i] + tmp[i+1];
			}
			tmp.pop_back();
		}
		if(tmp[0] == m){
			return true;
		}else{
			return false;
		}
	}
	for(int i = 0; i < used.size(); ++i){
		if(!used[i]){
			cur.push_back(i+1);
			used[i] = true;
			if(sub(cur,used,m)){
				return true;
			}
			used[i] = false;
			cur.pop_back();
		}
	}
	return false;
}

int main()
{
	int n,m;
	while(cin >> n >> m){
		vector<bool> used(n);
		fill(used.begin(),used.end(),false);
		vector<int> cur;
		if(sub(cur,used,m)){
			for(int i = 0; i < cur.size(); ++i){
				cout << cur[i];
				if(i != cur.size()-1){
					cout << " ";
				}
			}
			cout << endl;
		}else{
			cout << "wrong" << endl;
		}
	}
	return 0;
}
