#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	int ans=n;
	for(int i=n-1;i>=0;i--){
		if(a[i]==n){
			n--;
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
