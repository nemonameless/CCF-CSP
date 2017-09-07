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

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<n-1;i++){
		if((a[i]-a[i-1])*(a[i]-a[i+1])>0)
			cnt++;
	}
	cout<<cnt<<endl;

#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}


