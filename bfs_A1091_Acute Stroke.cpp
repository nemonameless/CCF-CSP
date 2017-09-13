#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<fstream>
using namespace std;
const int maxn=10000;
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
bool vis[1287][129][61]={false};
int maze[1287][129][61]={};
int n,m,t,T;
bool test(int x,int y,int z){
	if(x<0 || x>=n||y<0||y>=m||z>=t||z<0|| maze[x][y][z]==0 || vis[x][y][z]==true)
		return false;
	return true;
}
struct node{
	int x, y,z;
};
int bfs(int x,int y,int z){
	queue<node> q;
	node st;
	st.x=x;
	st.y=y;
	st.z=z;
	vis[x][y][z]=true;
	int tot=0;
	q.push(st);
	while(!q.empty()){
		node top=q.front();
		q.pop();
		tot++;
		for(int i=0;i<6;i++){
			int nx=top.x+X[i];
			int ny=top.y+Y[i];
			int nz=top.z+Z[i];
			if(test(nx,ny,nz)){
				node nt;
				nt.x=nx;
				nt.y=ny;
				nt.z=nz;
				vis[nx][ny][nz]=true;
				q.push(nt);
				//tot++;
			}
		}
	}
	if(tot>=T)
		return tot;
	else
		return 0;
}
int main(){
#ifdef _DEBUG
	ifstream cin("a.txt");
#endif
		cin>>n>>m>>t>>T;
		for(int z=0;z<t;z++)
			for(int x=0;x<n;x++)
				for(int y=0;y<m;y++)
					cin>>maze[x][y][z];
		int ans=0;
		for(int z=0;z<t;z++)
			for(int x=0;x<n;x++)
				for(int y=0;y<m;y++)
					if(test(x,y,z))
						ans+=bfs(x,y,z);

		cout<<ans<<endl;

#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}