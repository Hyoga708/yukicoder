#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}

int main(){
	int n;	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	int g=a[0];
	for(int i=1;i<n;i++)	g=gcd(g,a[i]);
	int ans=0;
	for(int i=0;i<n;i++)	ans+=a[i]/g;
	cout<<ans<<endl;
	return 0;
}
