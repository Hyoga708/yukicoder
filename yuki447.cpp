#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;	cin>>n;
	vector<int> l(n);
	for(int i=0;i<n;i++)	cin>>l[i];
	vector<int> cnt(n,1);
	int t;	cin>>t;
	map<string,vector<int>> mp;
	map<string,pair<int,int>> sum;
	for(int i=0;i<t;i++){
		string s,c;	cin>>s>>c;
		if(mp[s].empty())	mp[s]=vector<int>(n,0);
		int num=c[0]-'A';
		int add=50*l[num]+50*l[num]/(0.8+0.2*cnt[num]++);
		mp[s][num]=add;
		sum[s]=make_pair(sum[s].first+add,-i);
	}
	vector<pair<pair<int,int>,string>> rank;
	for(auto i:sum)	rank.push_back(make_pair(i.second,i.first));
	sort(rank.begin(),rank.end());	reverse(rank.begin(),rank.end());
	int i=1;
	for(auto out:rank){
		cout<<i++<<" "<<out.second;
		for(int i=0;i<n;i++)	cout<<" "<<mp[out.second][i];
		cout<<" "<<out.first.first<<endl;
	}
	return 0;
}
