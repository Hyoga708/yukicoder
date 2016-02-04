#include <bits/stdc++.h>
using namespace std;
int dist(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(){
	int n;	cin>>n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++)	cin>>x[i]>>y[i];
	set<pair<int,int>> grd;
	int cnt=0;
	for(int i=0;i<n;i++){
		auto it=grd.lower_bound(make_pair(x[i]-20,y[i]-20));
		bool canput=true;
		while(it!=grd.end()&&it->first<=x[i]+20){
			if(dist(x[i],y[i],it->first,it->second)<400){
				canput=false;
				break;
			}
			if(y[i]+20<it->second){
				it=grd.lower_bound(make_pair(it->first+1,y[i]-20));
			}
			else it++;
		}
		if(canput){
			grd.insert(make_pair(x[i],y[i]));
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
