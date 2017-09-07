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
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=-1e9;
	for(int i=0;i<n;i++){
		if(i>0){
			if(abs(a[i]-a[i-1])>max){
				max=abs(a[i]-a[i-1]);
			}
		}
	}
	
	cout<<max<<endl;

#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}


