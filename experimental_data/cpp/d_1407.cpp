#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn=3e5+5;

inline int read(){

    int x=0,f=1,ch=getchar();

    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}

    return x*f;

}

int n,h[maxn],f[maxn];

int s1[maxn],tp1,s2[maxn],tp2;

int main(){

    // freopen("test.in","r",stdin);

    n=read();

    for(int i=1;i<=n;i++)h[i]=read();

    f[0]=-1;

    for(int i=1;i<=n;i++){

        f[i]=f[i-1]+1;

        while(tp1&&h[s1[tp1]]<h[i])

            f[i]=min(f[i],f[s1[tp1--]]+1);

        if(tp1)f[i]=min(f[i],f[s1[tp1]]+1);

        while(tp1&&h[s1[tp1]]==h[i])tp1--;

        s1[++tp1]=i;

        while(tp2&&h[s2[tp2]]>h[i])

            f[i]=min(f[i],f[s2[tp2--]]+1);

        if(tp2)f[i]=min(f[i],f[s2[tp2]]+1);

        while(tp2&&h[s2[tp2]]==h[i])tp2--;

        s2[++tp2]=i;

    }

    cout<<f[n]<<'\n';

    return 0;

}