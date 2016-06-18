#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int n,k;	cin>>n>>k;
	
	map<int,multiset<int>> mp;
	for(int i=0;i<n;i++){
		int a;	cin>>a;
		for(int j=2;a>1&&j*j<=a;j++){
			int add=0;
			while(a%j==0){
				add++;
				a/=j;
			}
			if(add)	mp[j].insert(add);
		}
		if(a)	mp[a].insert(1);
	}
	long long ans=1;
	for(auto i:mp){
		auto it=i.second;
		int cnt=0;
		int p=0;
		for(auto j=it.rbegin();j!=it.rend();j++){
			p+=*j;	cnt++;
			if(cnt==k)	break;
		}
		long long multi=i.first;
		while(p){
			if(p&1)	(ans*=multi)%=mod;
			(multi*=multi)%=mod;
			p/=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
