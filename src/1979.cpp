#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
using namespace std;

char matrix[21][21];

int dfs(char matrix[21][21],int startx,int starty,int x,int y){
	if(startx < 0 || starty < 0 || startx >= x || starty >= y)return 0;
	if(matrix[startx][starty] == '#')return 0;
	matrix[startx][starty] = '#';
	return 1+dfs(matrix,startx-1,starty,x,y)+
		dfs(matrix,startx+1,starty,x,y)+
		dfs(matrix,startx,starty+1,x,y)+
		dfs(matrix,startx,starty-1,x,y);
}

int main()
{
	int x,y;
	int startx,starty;
	while(cin >> y >> x){
		if(x == 0 && y == 0){
			break;
		}
		for(int i = 0; i < x; ++i){
			string input;
			cin >> input;
			for(int j = 0; j < input.size(); ++j){
				if(input[j] == '.'){
					matrix[i][j] = '.';
				}
				else if(input[j] == '#'){
					matrix[i][j] = '#';
				}
				else{
					startx = i;
					starty = j;
					matrix[i][j] = '.';
				}
			}
		}
		cout << dfs(matrix,startx,starty,x,y) << endl;
	}
	return 0;
}
