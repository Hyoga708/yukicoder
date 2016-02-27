#include <bits/stdc++.h>
using namespace std;
#define fst first
#define sec second
int dist[1000][1000];
int lr[1000][1000],ud[1000][1000];
int main(){
	int w,h,n;	cin>>w>>h>>n;
	for(int i=0;i<n;i++){
		int m;	cin>>m;
		vector<pair<int,int>> b;
		for(int j=0;j<m+1;j++){
			int num;	cin>>num;
			b.push_back(make_pair(num/w,num%w));//y,x
		}
		for(int j=1;j<=m;j++){
			if(b[j].fst==b[j-1].fst){//横方向の移動
				int sml=min(b[j].sec,b[j-1].sec);
				int big=max(b[j].sec,b[j-1].sec);
				lr[b[j].fst][sml]++;	lr[b[j].fst][big]--;
			}
			else{
				int sml=min(b[j].fst,b[j-1].fst);
				int big=max(b[j].fst,b[j-1].fst);
				ud[sml][b[j].sec]++;	ud[big][b[j].sec]--;
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++)	lr[i][j]+=lr[i][j-1];
	}
	for(int i=1;i<h;i++){
		for(int j=0;j<w;j++)	ud[i][j]+=ud[i-1][j];
	}
	for(int i=0;i<h;i++)	for(int j=0;j<w;j++)	dist[i][j]=INT_MAX;
	dist[0][0]=0;
	priority_queue<tuple<int,int,int>> pq;
	pq.push(make_tuple(-0,0,0));
	while(!pq.empty()){
		auto it=pq.top();	pq.pop();
		int cost=-get<0>(it);
		int y=get<1>(it),x=get<2>(it);
		if(cost>dist[y][x])	continue;
		if(y==h-1&&x==w-1){
			cout<<cost<<endl;
			return 0;
		}
		cost++;
		if(lr[y][x]>0&&dist[y][x+1]>cost){
			dist[y][x+1]=cost;
			pq.push(make_tuple(-cost,y,x+1));
		}
		if(x>0&&lr[y][x-1]>0&&dist[y][x-1]>cost){
			dist[y][x-1]=cost;
			pq.push(make_tuple(-cost,y,x-1));
		}
		if(ud[y][x]>0&&dist[y+1][x]>cost){
			dist[y+1][x]=cost;
			pq.push(make_tuple(-cost,y+1,x));
		}
		if(y>0&&ud[y-1][x]>0&&dist[y-1][x]>cost){
			dist[y-1][x]=cost;
			pq.push(make_tuple(-cost,y-1,x));
		}
	}
	cout<<"Odekakedekinai.."<<endl;
	return 0;
}
