//ac.jobdu.com/problem.php?pid=1456
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
bool vis[51][51][51]={false};
int maze[51][51][51]={};
int n,m,t,T;
bool test(int x,int y,int z){
	if(x<0 || x>=n||y<0||y>=m||z>=t||z<0|| maze[x][y][z]==1)
		return false;
	return true;
}
struct node{
	int x, y,z;
	int step;//一定要定义为node的成员，节点运动中记录着步数。
};
int bfs(int n,int m,int t){
	queue<node> q;
	node st;
	st.x=0;
	st.y=0;
	st.z=0;
	vis[0][0][0]=true;
	st.step=0;		//若单独定义step无法与走到的节点处的真实步数保持一致
	q.push(st);

	while(!q.empty()){
		node top=q.front();
		q.pop();
		if(top.x==n-1 && top.y==m-1 && top.z==t-1)
			return top.step;
		for(int i=0;i<6;i++){
			int nx=top.x+X[i];
			int ny=top.y+Y[i];
			int nz=top.z+Z[i];
			int nstep=top.step+1; //不可写成++；
			if(test(nx,ny,nz)){
				node nt;
				nt.x=nx;
				nt.y=ny;
				nt.z=nz;
				nt.step=nstep;
				if(vis[nx][ny][nz]==false){
					vis[nx][ny][nz]=true;
					q.push(nt);
					//cout<<nx<<" "<<ny<<" "<<nz<<" "<<nstep<<endl;
				}
			}
		}
	}
	return -1;
}
int k;
int main(){
#ifdef _DEBUG
	ifstream cin("a.txt");
#endif
	cin>>k;
	while(k--){
		memset(vis,false,sizeof(vis));
		cin>>n>>m>>t>>T;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++)
				for(int z=0;z<t;z++)
					cin>>maze[x][y][z];
		}
	
		int ans=bfs(n,m,t);
		if(ans>T)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}
#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}
