#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,b;	cin>>n>>b;
	double f=0,F=0;
	for(int i=0;i<n;i++){
		double a;	cin>>a;
		if(a!=0)	f+=a*pow((double)b,a-1.0);
		if(a==-1.0)	F+=log((double)b);
		else F+=pow((double)b,a+1.0)/(a+1.0);
	}
	printf("%.15lf\n",f);
	printf("%.15lf\n",F);
	return 0;
}
