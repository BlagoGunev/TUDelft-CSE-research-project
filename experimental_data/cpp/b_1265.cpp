#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
const int N=2e5+10;
int T,n,i,a[N],in[N];
bool vis[N];
int main(){
    for (read(T);T--;){
        read(n);
        for (i=1;i<=n;++i) read(a[i]),in[a[i]]=i,vis[i]=0;
        putchar('1');
        vis[in[1]]=1;
        int cnt=n-1;
        for (i=2;i<=n;++i){
            if (in[i]>1 && vis[in[i]-1]) cnt--;
            if (in[i]<n && vis[in[i]+1]) cnt--;
            vis[in[i]]=1;
            if (cnt==n-i) putchar('1');
            else putchar('0');
        }
        puts("");
    }
    return 0;
}