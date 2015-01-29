#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
using namespace std;

set<int> res;

void sub(int x,int y,int grid[6][6],int cnt,int sum){
	if(cnt == 6){
		res.insert(sum);
		return;
	}
	sum *= 10;
	sum += grid[x][y];
	if(x > 0){
		sub(x-1,y,grid,cnt+1,sum);
	}
	if(y > 0){
		sub(x,y-1,grid,cnt+1,sum);
	}
	if(x < 4){
		sub(x+1,y,grid,cnt+1,sum);
	}
	if(y < 4){
		sub(x,y+1,grid,cnt+1,sum);
	}
}

int main()
{
	int grid[6][6];
	while(true){
		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				if(!(cin >> grid[i][j])){
					return 0;
				}
			}
		}
		res.clear();
		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				sub(i,j,grid,0,grid[i][j]);
			}
		}
		cout << res.size() << endl;
	}
	return 0;
}
