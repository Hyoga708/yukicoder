#include <bits/stdc++.h>
using namespace std;
int main(){
	int A,B;	cin>>A>>B;
	int ans=INT_MAX;
	for(int a=0;a<=1000;a++){
		for(int b=0;b<=1000;b++){
			if(a+b==0)	continue;
			if(round((double)100*a/(a+b))!=A)	continue;
			if(round((double)100*b/(a+b))!=B)	continue;
			ans=min(ans,a+b);
		}
	}
	cout<<ans<<endl;
	return 0;
}
