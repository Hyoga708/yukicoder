#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][101][64];
int main(){
	int gx,gy,n,f;	cin>>gx>>gy>>n>>f;
	for(int i=0;i<=gy;i++){
		for(int j=0;j<=gx;j++){
			dp[i][j][0]=f*(i+j);
			for(int k=1;k<=n;k++)	dp[i][j][k]=1e9;
		}
	}
	for(int k=0;k<n;k++){
		int x,y,c;	cin>>x>>y>>c;
		for(int i=0;i<=gy;i++)	for(int j=0;j<=gx;j++){
			dp[i][j][k+1]=min(dp[i][j][k+1],dp[i][j][k]);
			int nx=x+j,ny=y+i;
			if(nx<=gx&&ny<=gy)	dp[ny][nx][k+1]=min(dp[ny][nx][k+1],dp[i][j][k]+c);
		}
	}
	cout<<dp[gy][gx][n]<<endl;
	return 0;
}
