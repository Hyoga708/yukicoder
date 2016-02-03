#include <bits/stdc++.h>
using namespace std;
bool ok(int a,int b,int c){
	if(a==b||b==c||c==a)	return false;
	int m=max(a,max(b,c)),M=min(a,min(b,c));
	if(b==m||b==M)	return true;
	return false;
}
bool dfs(vector<int> l){
	int n=l.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(ok(l[i],l[j],l[k])){
					vector<int> next=l;
					next.erase(next.begin()+k);
					next.erase(next.begin()+j);
					next.erase(next.begin()+i);
					if(!dfs(next))	return true;
				}
			}
		}
	}
	return false;
}
int main(){
	int n;	cin>>n;
	vector<int> l(n);
	for(int i=0;i<n;i++)	cin>>l[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(ok(l[i],l[j],l[k])){
					vector<int> next=l;
					next.erase(next.begin()+k);
					next.erase(next.begin()+j);
					next.erase(next.begin()+i);
					if(!dfs(next)){
						cout<<i<<" "<<j<<" "<<k<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
