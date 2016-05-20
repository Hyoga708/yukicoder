#include <iostream>
#include <algorithm> 
using namespace std;
typedef long long ll;
#define rep(i,n)	for(int i=0;i<n;i++)
ll gcd(ll a,ll b){
	return a%b==0?b:gcd(b,a%b);
}
int main(){
	ll n,m;	cin>>n>>m;
	ll g=gcd(n,m);
	n/=g;	m/=g;
	ll mt=0,mf=0;
	while(m%2==0){
		m/=2;
		mt++;
	}
	while(m%5==0){
		m/=5;
		mf++;
	}
	if(n%m!=0){
		cout<<-1<<endl;
		return 0;
	}
	while(n%10==0)	n/=10;
	n%=10000;
	while(mt>mf){
		if(n%2==0)	n/=2;
		else n*=5;
		n%=10000;
		mf++;
	}
	while(mt<mf){
		if(n%5==0)	n/=5;
		else n*=2;
		n%=10000;
		mt++;
	}
	while(n%10==0)	n/=10;
	cout<<n%10<<endl;
	return 0;
}
	
