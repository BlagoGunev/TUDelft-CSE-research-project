#include<bits/stdc++.h>
#define lb long double 
using namespace std;

const int N=105;
const int M=1e4+5;

int x;	
lb n,sum,m,ans,c[N],f[N][M];

signed main(){
	cin>>n>>m;
	m*=0.5; 
	c[0]=f[0][0]=1;
	for(int i=1;i<=n;++i){
	    cin>>x;
	    sum+=x;
	    c[i]=c[i-1]*(n-i+1)/i;
	    for(int j=i;j;--j){
	    	for(int k=sum;k>=x;--k){
	    		f[j][k]+=f[j-1][k-x];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=sum;++j){
			ans+=min((n/i+1)*m,(lb)j/i)*f[i][j]/c[i];
		}
	}
	printf("%.10Lf",ans);
	return 0;
}