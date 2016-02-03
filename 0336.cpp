//0,0,4,10,32,122,544,2770
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2020][2020];
ll ans[2020];
const int mod=1000000007;
int mdpow(ll a){
	int n=mod-2;
	ll ret=1;
	while(n){
		if(n&1)	ret=(ret*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	int n;	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<2020;i++){
		for(int j=0;j<=i;j++){
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
		}
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	ll md2=mdpow(2);
	ans[0]=ans[1]=1;
	ans[2]=2;	ans[3]=4;	ans[4]=10;
	for(int i=5;i<=n;i++){//i個の順列。iを除いた0〜(i-1)までの順列を利用。
		for(int right=0;right<i;right++){
			int left=i-1-right;
			ll multi=(((ans[left]*ans[right])%mod)*dp[i-1][left])%mod;
			if(right>=2)	multi=(multi*md2)%mod;
			if(left>=2)	multi=(multi*md2)%mod;
			ans[i]=(ans[i]+multi)%mod;
		}
	}
	cout<<ans[n]<<endl;
	return 0;
}
