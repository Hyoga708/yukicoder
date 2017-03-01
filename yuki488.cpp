#include <bits/stdc++.h>
using namespace std;
bool edge[64][64];
int main(){
	int n,m;	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;	cin>>a>>b;
		edge[a][b]=true;	edge[b][a]=true;
	}
	int ret=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!edge[i][j])	continue;
			for(int k=j+1;k<n;k++){
				if(!edge[i][k])	continue;
				if(edge[j][k])	continue;
				for(int l=i+1;l<n;l++){
					if(!edge[j][l])	continue;
					if(!edge[k][l])	continue;
					if(edge[i][l])	continue;
					ret++;
				}
			}
		}
	}
	cout<<ret<<endl;
	return 0;
}
