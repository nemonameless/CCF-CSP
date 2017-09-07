#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<fstream>
using namespace std;
bool vis[101][101][1001]={false};
int maze[101][101]={};
struct Node{
	int x,y,step;
}node;
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int n,m,t;
bool test(int x,int y,int time){
	if(x<1 ||x>n || y<1 ||y>m)
		return false;
	return true;
}
int bfs(int n,int m){
	queue<Node> q;
	node.x=1;
	node.y=1;
	node.step=0;
	q.push(node);
	while(!q.empty()){
		Node top=q.front();
		q.pop();
		//cout<<top.x<<" "<<top.y<<" "<<top.step<<endl;
		if(top.x==n && top.y==m)
			return top.step;

		for(int i=0;i<4;i++){
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			int newstep=top.step+1; //top.step++»á³ö´í
			if(test(newx,newy,newstep)){
				Node next;
				next.x=newx;
				next.y=newy;
				next.step=newstep;
				if(vis[newx][newy][newstep]==false){
					vis[newx][newy][newstep]=true;//////////
					q.push(next);
				}
			}
		}
	}
	return 0;
}


int main(){
#ifdef _DEBUG
	ifstream cin("a.txt");
#endif

	cin>>n>>m>>t;
	for(int i=0;i<t;i++){
		int x,y,st,ed;
		cin>>x>>y>>st>>ed;
		for(int j=st;j<=ed;j++){
			vis[x][y][j]=1;
		}
	}
	
	cout<<bfs(n,m)<<endl;
	

#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}
//

