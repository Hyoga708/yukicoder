#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int main(){
	int h,w;	cin>>h>>w;
	vector<string> s(h);
	vector<pair<int,int>> a;
	for(int i=0;i<h;i++){
		cin>>s[i];
		for(int j=0;j<w;j++){
			if(s[i][j]=='*')	a.push_back(make_pair(i,j));
		}
	}
	if((a[0].first!=a[1].first)&&(a[0].second!=a[1].second)){
		s[a[0].first][a[1].second]='*';
	}
	else if(a[0].first!=a[1].first){
		if(a[0].second==0)	s[a[0].first][1]='*';
		else 	s[a[0].first][0]='*';
	}
	else{
		if(a[0].first==0)	s[1][a[0].second]='*';
		else 	s[0][a[0].second]='*';
	}
	for(int i=0;i<h;i++)	cout<<s[i]<<endl;
	return 0;
}
