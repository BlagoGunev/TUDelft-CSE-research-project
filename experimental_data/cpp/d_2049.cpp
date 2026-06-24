#include<bits/stdc++.h>
using namespace std;
long long tt,n,m,kp,a[205][205],f[205][205][205],mn[205][205];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>tt;
	for(int o=1;o<=tt;o++){
		cin>>n>>m>>kp;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
            	cin>>a[i][j];
            	mn[i][j]=1e18;
            	for(int k=0;k<m;k++){
            		f[i][j][k]=1e18;
				}
			}
        }
        for(int j=2;j<=m;j++){
        	mn[0][j]=1e18;
		}
        for(int i=1;i<=n;i++){
        	for(int j=1;j<=m;j++){
        		for(long long k=0;k<m;k++){
        			f[i][j][k]=min(f[i][j][k],f[i][(j-2+m)%m+1][k]+a[i][(j+k-1)%m+1]);
        			f[i][j][k]=min(f[i][j][k],mn[i-1][j]+a[i][(j+k-1)%m+1]+kp*k);
				}
			}
			for(int j=1;j<=m;j++){
        		for(long long k=0;k<m;k++){
        			f[i][j][k]=min(f[i][j][k],f[i][(j-2+m)%m+1][k]+a[i][(j+k-1)%m+1]);
        			f[i][j][k]=min(f[i][j][k],mn[i-1][j]+a[i][(j+k-1)%m+1]+kp*k);
        			mn[i][j]=min(mn[i][j],f[i][j][k]);
				}
			}
		}
		cout<<mn[n][m]<<"\n";
	}
}