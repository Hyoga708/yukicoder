#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s;	cin>>s;
	int n=s.size();
	ll ccnt=0,wcnt=0;
	for(int i=0;i<n;i++)	if(s[i]=='w')	wcnt++;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='c')	ccnt++;
		else if(s[i]=='w'){
			wcnt--;
			ans+=ccnt*wcnt;
		}
	}
	cout<<ans<<endl;
	return 0;
}
