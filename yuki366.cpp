#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	int ans=0;
	for(int i=0;i<min(n,k);i++){
		for(int j1=i;j1<n;j1+=k){
			for(int j2=j1+k;j2<n;j2+=k){
				if(a[j2-k]>a[j2]){
					ans++;
					swap(a[j2-k],a[j2]);
				}
			}
		}
	}
	for(auto i:a)	cout<<i<<" ";
	cout<<endl;
	for(int i=1;i<n;i++){
		if(a[i-1]>a[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
