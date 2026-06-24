// LUOGU_RID: 97403218
#include<bits/stdc++.h>
using namespace std;
int t,n,p[6001],lp[6001],rp[6001],top;
short f[6001][6001];
vector<int> v[6001];
int main(){
ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
cin>>t;
while (t--){
cin>>n; top=0;
for (int i=1;i<=n;++i) cin>>lp[i]>>rp[i],p[++top]=lp[i],p[++top]=rp[i];
sort(p+1,p+top+1); top=unique(p+1,p+top+1)-p-1;
for (int i=1;i<=n;++i) lp[i]=lower_bound(p+1,p+top+1,lp[i])-p,rp[i]=lower_bound(p+1,p+top+1,rp[i])-p;
for (int i=1;i<=top;++i) vector<int>().swap(v[i]);
for (int i=1;i<=n;++i) v[lp[i]].push_back(rp[i]);
for (int i=1;i<=top;++i) sort(v[i].begin(),v[i].end());
for (int len=0;len<top;++len) for (int l=1;l+len<=top;++l){
int r=len+l;
f[l][r]=max(f[l+1][r],f[l][r-1]);
for (int to:v[l]){
if (to<r) f[l][r]=max(short(f[l][to]+f[to+1][r]),f[l][r]);
if (to==r) ++f[l][r];
}
}
cout<<f[1][top]<<'\n';
for (int i=1;i<=top;++i) for (int j=1;j<=top;++j) f[i][j]=0;
}
return 0;
}