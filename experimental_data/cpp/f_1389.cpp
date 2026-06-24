#include<bits/stdc++.h>
using namespace std;
int const M=200200;multiset<int> f[2];
struct node{int l,r,c;}a[M];int i,n,Ans;
int read(){
int x=0;char ch=getchar();
while (ch<'0'||ch>'9') ch=getchar();
while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
return x;
}
int main(){ n=read();
for (i=1;i<=n;i++) a[i]={read(),read(),read()-1};
sort(a+1,a+1+n,[](node a,node b){return a.r==b.r?a.l<b.l:a.r<b.r;});
for (i=1;i<=n;i++)
if (f[!a[i].c].lower_bound(a[i].l)==f[!a[i].c].end())
Ans++,f[a[i].c].insert(a[i].r);
else f[!a[i].c].erase(f[!a[i].c].lower_bound(a[i].l));
return printf("%d\n",Ans),0;
}