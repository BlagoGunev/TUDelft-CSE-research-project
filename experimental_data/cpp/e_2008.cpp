#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 200000

int i,j,k,n,m,t,d,f[27][27][2],g[27][27][2],res;
string s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>s; k=1;
		memset(f,-0x3f,sizeof(f)); res=0;
		for(i=1;i<=26;i++)for(j=1;j<=26;j++)f[i][j][0]=0;
		for(auto c:s){
			c-='a'-1; k^=1;
			memcpy(g,f,sizeof(g));
			
			for(i=1;i<=26;i++)for(j=1;j<=26;j++){
				g[i][j][1]=max(g[i][j][1],f[i][j][0]);
				if(k==0){
					if(i==c)g[i][j][0]=max(g[i][j][0],f[i][j][0]+1);
					if(j==c)g[i][j][1]=max(g[i][j][1],f[i][j][1]+1);
				}
				else{
					if(j==c)g[i][j][0]=max(g[i][j][0],f[i][j][0]+1);
					if(i==c)g[i][j][1]=max(g[i][j][1],f[i][j][1]+1);
				}
			}
			memcpy(f,g,sizeof(f));
		}
		for(i=1;i<=26;i++)for(j=1;j<=26;j++){
			if(n&1){
				res=max(res,f[i][j][1]);
			}
			else res=max(res,f[i][j][0]);
		}
		//cout<<"NMSL "<<res<<endl;
		res=n-res;
		cout<<res<<'\n';
	}
}