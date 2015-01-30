#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
using namespace std;

class COW{
	public:
		int low,high;
		COW(int x,int y):low(x),high(y){}
		bool operator< (const COW &c)const{
			if(c.high > this->high){
				return true;
			}else if(c.high == this->high){
				if(c.low > this->low){
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}
};

class lotion{
	public:
		int SPF,cnt;
		lotion(int x,int y):SPF(x),cnt(y){}
		bool operator< (const lotion &l)const{
			if(this->SPF < l.SPF){
				return true;
			}else{
				return false;
			}
		}
};

int main()
{
	int C,L;
	while(cin >> C >> L){
		vector<COW> cows;
		vector<lotion> lotions;
		for(int i = 0; i < C; ++i){
			int x,y;
			cin >> x >> y;
			cows.push_back(COW(x,y));
		}
		for(int i = 0; i < L; ++i){
			int x,y;
			cin >> x >> y;
			lotions.push_back(lotion(x,y));
		}
		sort(cows.begin(),cows.end());
		sort(lotions.begin(),lotions.end());
		for(int i = 0; i < cows.size(); ++i){
			//cout << cows[i].low << " " << cows[i].high << endl;
		}
		for(int i = 0; i < lotions.size(); ++i){
			//cout << lotions[i].SPF << " " << lotions[i].cnt << endl;
		}
		int ans = 0;
		for(int i = 0; i < cows.size(); ++i){
			for(int j = 0; j < lotions.size(); ++j){
				if(lotions[j].cnt <= 0){
					continue;
				}
				if(lotions[j].SPF < cows[i].low){
					continue;
				}
				if(lotions[j].SPF > cows[i].high){
					break;
				}
				lotions[j].cnt--;
				ans++;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
