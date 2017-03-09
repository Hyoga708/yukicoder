#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair

bool visit[111][111];
vector<pii> edge[111][111];

int dfs(int r,int c){
	if(visit[r][c])	return 1;
	visit[r][c]=true;
	int ret=0;
	while(edge[r][c].size()){
		int tr=edge[r][c][0].first;
		int tc=edge[r][c][0].second;
		for(int j=0;j<edge[tr][tc].size();j++){
			if(edge[tr][tc][j]==mp(r,c)){
				edge[tr][tc].erase(edge[tr][tc].begin()+j);
				break;
			}
		}
		edge[r][c].erase(edge[r][c].begin());
		ret+=dfs(tr,tc);
	}
	return ret;
}

int main(){
	int n;	cin>>n;
	vector<pii> ls;
	for(int i=0;i<n;i++){
		int ar,ac,br,bc;	cin>>ar>>ac>>br>>bc;
		ls.push_back(mp(ar,ac));
		ls.push_back(mp(br,bc));
		edge[ar][ac].push_back(mp(br,bc));
		edge[br][bc].push_back(mp(ar,ac));
	}
	for(int i=0;i<111;i++)	for(int j=0;j<111;j++)	visit[i][j]=false;
	for(int i=0;i<111;i++)	for(int j=0;j<111;j++){
		if(!visit[i][j]){
			if(dfs(i,j)>=2){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
