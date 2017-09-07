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
const int maxn=1010;
int a[maxn]={};
int main(){

#ifdef _DEBUG
	ifstream cin("a.txt");
#endif
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0,tmp=0;
	for(int i=0;i<n;i++){
		tmp+=a[i];
		if(tmp>=m){
			cnt++;
			tmp=0;
		}
	}
	if(tmp>0 && tmp<m)//最后正好分完的话tmp=0，则人数不加一
		cnt+=1;
	cout<<cnt<<endl;

#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}


