//cf1678b2

#include<bits/stdc++.h>

#define INF 0x7fffffff

#define debug puts("sto shs orz")

#ifdef ONLINE_JUDGE

const int open = 21;

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

char buf[1<<21],*p1=buf,*p2=buf;

#endif

template <typename T>

inline void read(T& r) {

   r=0;bool w=0; char ch=getchar();

   while(ch<'0'||ch>'9') w=ch=='-'?1:0,ch=getchar();

   while(ch>='0'&&ch<='9') r=r*10+(ch^48), ch=getchar();

   r=w?-r:r;

}

bool s[200005];

void solve(){

    int n;

    read(n);

   // getchar();

    for(int i=1;i<=n;i++){

        char ch=getchar();

        s[i]=ch-'0';

    }

    int ans1=0,ans2=0;

    int last=-1;

    for(int i=1;i<=n;i+=2){

        if(s[i+1]!=s[i])ans1++;

        else if(s[i]!=last)ans2++,last=s[i];

    }

    printf("%d %d\n",ans1,ans2==0?1:ans2);

}

signed main(){

    int t;

    read(t);

    while(t--)solve();

}

/*

5

10

1110011000

0000

8

11001111

2

00

2

11

6

000010

*/