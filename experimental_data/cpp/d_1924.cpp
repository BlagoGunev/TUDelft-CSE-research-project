#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=1e9+7,P=6e3+10;
int C[P+1][P+1];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);for(int i=0;i<=P;i++){C[i][0]=1;for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%M; }
	int t,n,m,k;cin>>t;while(t--){cin>>n>>m>>k;cout<<(C[n+m][min(k,min(n,m))]-C[n+m][min(k-1,min(n,m))]+M)%M<<'\n';}
}