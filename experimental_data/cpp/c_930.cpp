#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
int n,m,ans;
int c[N],w[N],f[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline void add(int x,int f) {
    while(x<=n) c[x]=max(c[x],f),x+=(x&-x);
}
inline int query(int x) {
    int ret=0;
    while(x) ret=max(ret,c[x]),x-=(x&-x);
    return ret;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
 ++w[gi()],--w[gi()+1];
    for(int i=1;i<=m;i++) w[i]+=w[i-1];
    ++n;
    for(int i=1;i<=m;i++) {
 f[i]=query(++w[i])+1;
 add(w[i],f[i]);
    }
    memset(c,0,sizeof(c));
    for(int i=m;i;i--) {
 int t=query(w[i])+1;
 ans=max(ans,t+f[i]-1),add(w[i],t);
    }
    cout<<ans;
    return 0;
}