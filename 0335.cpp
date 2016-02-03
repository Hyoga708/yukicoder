#include <bits/stdc++.h>
using namespace std;
bool isKadomatsu(int a,int b,int c){
	if(a==b||b==c||c==a)	return false;
	int m=max(a,max(b,c)),M=min(a,min(b,c));
	if(b==m||b==M)	return true;
	return false;
}
struct segtree{
	vector<int> big,sml;
	int n;
	segtree(int x){
		n=1;
		while(n<x)	n<<=1;
	}
	void assign(vector<int> a){
		big.clear();	big.assign(2*n-1,INT_MIN);
		sml.clear();	sml.assign(2*n-1,INT_MAX);
		for(int i=0;i<(int)a.size();i++){
			int t=n-1+i;
			big[t]=sml[t]=a[i];
		}
		for(int i=n-2;i>=0;i--){
			big[i]=max(big[2*i+1],big[2*i+2]);
			sml[i]=min(sml[2*i+1],sml[2*i+2]);
		}
	}
	int maximum(int l,int r,int a,int b,int k){
		if(r<=a||b<=l)	return INT_MIN;
		if(a<=l&&r<=b)	return big[k];
		int vr=maximum(l,(l+r)/2,a,b,2*k+1);
		int vl=maximum((l+r)/2,r,a,b,2*k+2);
		return max(vr,vl);
	}
	int minimum(int l,int r,int a,int b,int k){
		if(r<=a||b<=l)	return INT_MAX;
		if(a<=l&&r<=b)	return sml[k];
		int vl=minimum(l,(l+r)/2,a,b,2*k+1);
		int vr=minimum((l+r)/2,r,a,b,2*k+2);
		return min(vl,vr);
	}
};
int main(){
	int n,m;	cin>>n>>m;
	int ans=0,score=0;
	segtree seg(n);
	for(int i=0;i<m;i++){
		vector<int> a(n);
		for(int j=0;j<n;j++)	cin>>a[j];
		seg.assign(a);
		int tmp=0;
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				int add=0;
				int p;
				if(0<j){
					p=seg.maximum(0,seg.n,0,j,0);
					if(isKadomatsu(p,a[j],a[k])){
						add=max(max(a[j],a[k]),max(add,p));
					}
					p=seg.minimum(0,seg.n,0,j,0);
					if(isKadomatsu(p,a[j],a[k])){
						add=max(add,max(a[j],a[k]));
					}
				}
				if(j+1<k){
					p=seg.maximum(0,seg.n,j+1,k,0);
					if(isKadomatsu(a[j],p,a[k])){
						add=max(max(a[j],a[k]),max(add,p));
					}
					p=seg.minimum(0,seg.n,j+1,k,0);
					if(isKadomatsu(a[j],p,a[k])){
						add=max(add,max(a[j],a[k]));
					}
				}
				if(k+1<n){
					p=seg.maximum(0,seg.n,k+1,n,0);
					if(isKadomatsu(a[j],a[k],p)){
						add=max(max(a[j],a[k]),max(add,p));
					}
					p=seg.minimum(0,seg.n,k+1,n,0);
					if(isKadomatsu(a[j],a[k],p)){
						add=max(add,max(a[j],a[k]));
					}
				}
				tmp+=add;
			}
		}
		if(score<tmp){
			ans=i;	score=tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}
