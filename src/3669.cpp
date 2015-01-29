#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
using namespace std;

int matrix[302][302];
int ans[302][302];
void init(){
	for(int i = 0; i < 302; ++i){
		for(int j = 0; j < 302; ++j){
			matrix[i][j] = 0;//not get here
			ans[i][j] = -1;//safe
		}
	}
}
void mset(int x,int y,int t){
	if(x < 0 || y < 0){
		return;
	}
	if(ans[x][y] < 0){
		ans[x][y] = t;
	}else if(ans[x][y] > t){
		ans[x][y] = t;
	}
}
typedef struct Stage{
	Stage(int x,int y,int t):x(x),y(y),t(t){}
	int x,y,t;
} stage;
int main()
{
	int m;
	while(cin >> m){
		init();
		int x,y,t;
		for(int i = 0; i < m; ++i){
			//cin >> x >> y >> t;
			scanf("%d%d%d",&x,&y,&t);
			mset(x,y,t);
			mset(x-1,y,t);
			mset(x+1,y,t);
			mset(x,y-1,t);
			mset(x,y+1,t);
		}
		queue<stage> q;
		if(ans[0][0] < 0){
			cout << 0 << endl;
		}else{
			q.push(stage(0,0,0));
			matrix[0][0] = 1;
			bool solved = false;
			while(!solved && q.size()){
				stage cur = q.front();
				q.pop();
				if(ans[cur.x][cur.y] < 0){
					cout << cur.t << endl;
					solved = true;
				}
				if(cur.t >= ans[cur.x][cur.y]){
					continue;
				}
				if(cur.x > 0 && matrix[cur.x-1][cur.y] == 0){
					q.push(stage(cur.x-1,cur.y,cur.t+1));	
					matrix[cur.x-1][cur.y] = 1;
				}
				if(cur.y > 0 && matrix[cur.x][cur.y-1] == 0){
					q.push(stage(cur.x,cur.y-1,cur.t+1));
					matrix[cur.x][cur.y-1] = 1;
				}
				if(matrix[cur.x+1][cur.y] == 0){
					q.push(stage(cur.x+1,cur.y,cur.t+1));
					matrix[cur.x+1][cur.y] = 1;
				}
				if(matrix[cur.x][cur.y+1] == 0){
					q.push(stage(cur.x,cur.y+1,cur.t+1));
					matrix[cur.x][cur.y+1] = 1;
				}
			}
			if(!solved){
				cout << -1 << endl;
			}
		}
	}
			
	return 0;
}
