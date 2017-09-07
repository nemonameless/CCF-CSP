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
	int n,lcnt=0,rcnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);

	int mid=n/2;
	lcnt=mid;
	rcnt=n-mid-1;
	for(int i=mid-1;i>=0;i--){
		if(a[mid]==a[i])
			lcnt--;
		else
			break;
	}
	for(int i=mid+1;i<n;i++){
		if(a[mid]==a[i])
			rcnt--;
		else
			break;
	}
	if(lcnt==rcnt)
		cout<<a[mid]<<endl;
	else
		cout<<"-1"<<endl;

#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}


