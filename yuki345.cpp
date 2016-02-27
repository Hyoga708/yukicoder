#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;	cin>>s;
	int ans=INT_MAX;
	for(int i=0;i<s.size();i++){
		if(s[i]!='c')	continue;
		for(int j=i+1;j<s.size();j++){
			if(s[j]!='w')	continue;
			for(int k=j+1;k<s.size();k++){
				if(s[k]!='w')	continue;
				ans=min(ans,k-i+1);
			}
		}
	}
	if(ans==INT_MAX)	ans=-1;
	cout<<ans<<endl;
	return 0;
}
