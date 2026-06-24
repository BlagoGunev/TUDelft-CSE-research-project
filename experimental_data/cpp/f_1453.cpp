#include<bits/stdc++.h>

using namespace std;

const int N=3145;int n,a[N],f[N][N]; 

int main(){int t;cin>>t;while(t--){

	scanf("%d",&n);memset(f,0,sizeof(0));

	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=i;

	for(int i=2;i<=n;i++){

		for(int j=i;j<=n;j++)f[i][j]=1e9;

		int c=0;

		for(int j=i-1;j>=1;j--){

			if(a[j]<i)continue;

			f[i][a[j]]=min(f[i][a[j]],f[j][i-1]+c);c++;

		}for(int j=i+1;j<=n;j++)f[i][j]=min(f[i][j],f[i][j-1]);

	}printf("%d\n",f[n][n]);

}}