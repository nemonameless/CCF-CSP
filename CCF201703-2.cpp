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
int tmp[maxn]={};
int id2pos[maxn]={},pos2id[maxn]={};
int main(){
#ifdef _DEBUG
	ifstream cin("a.txt");
#endif

	int n,m;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		id2pos[i]=i;
		pos2id[i]=i;
	}
	while(m--){
		int p,w;
		cin>>p>>w;
		int pos=id2pos[p];
		if(w>0){
			int i=0;
			for(i=1;i<pos;i++){
				tmp[i]=pos2id[i];
			}
			for(i=pos;i<pos+w;i++){
				tmp[i]=pos2id[i+1];
			}
			tmp[i]=p;
			for(i=pos+w+1;i<=n;i++){
				tmp[i]=pos2id[i];
			}

			for(int j=1;j<=n;j++){
				pos2id[j]=tmp[j];
				id2pos[pos2id[j]]=j;
			}
			for(int j=1;j<=n;j++){
				tmp[j]=0;
			}
		}else{
			w*=-1;
			int i=0;
			for(i=1;i<pos-w;i++){
				tmp[i]=pos2id[i];
			}
			tmp[i]=p;
			for(i=pos;i>=pos-w+1;i--){    //´ÓºóÍùÇ°£¬>=
				tmp[i]=pos2id[i-1];
			}
			
			for(i=pos+1;i<=n;i++){
				tmp[i]=pos2id[i];
			}

			for(int j=1;j<=n;j++){
				pos2id[j]=tmp[j];
				id2pos[pos2id[j]]=j;
			}
			for(int j=1;j<=n;j++){
				tmp[j]=0;
			}
		}

		/*for(int i=1;i<=n;i++){
			if(i!=1)
				cout<<" ";
			cout<<pos2id[i];
		}
		cout<<endl;*/
	}

	for(int i=1;i<=n;i++){
		if(i!=1)
			cout<<" ";
		cout<<pos2id[i];
	}
	cout<<endl;

#ifdef _DEBUG
	cin.close();
#endif
	return 0;
}


