#include<bits/stdc++.h>

using namespace std;
inline void read(int &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}
inline void write(int x){
    static const int maxlen=100;
    static char s[maxlen];
        if (x<0)	{	putchar('-'); x=-x;}
    if(!x){ putchar('0'); return; }
    int len=0; for(;x;x/=10) s[len++]=x % 10+'0';
    for(int i=len-1;i>=0;--i) putchar(s[i]);
}

const int MAXN = 300000;
int a[ MAXN ];
long long up[ MAXN ];
long long up_cost[ MAXN ];
long long down[ MAXN ];
long long down_cost[ MAXN ];
int n;

int main(){
    read(n);
    for (int i=1;i<=n;i++)
        read(a[i]);
    up[1]=a[1];
    up_cost[1]=0;
    for (int i=2;i<=n;i++)
        if (a[i]<=up[i-1])
        {
            up[i]=up[i-1]+1;
            up_cost[i]=up_cost[i-1]+up[i]-a[i];
        }
        else
        {
            up[i]=a[i];
            up_cost[i]=up_cost[i-1];
        }
    down[n]=a[n];
    down_cost[n]=0;
    for (int i=n-1;i>=1;i--)
        if (a[i]<=down[i+1])
        {
            down[i]=down[i+1]+1;
            down_cost[i]=down_cost[i+1]+down[i]-a[i];
        }
        else
        {
            down[i]=a[i];
            down_cost[i]=down_cost[i+1];
        }

    long long ans=min( up_cost[n] ,down_cost[ 1 ]);
    for (int i=1;i<n;i++)
        ans=min( ans ,up_cost[i]+down_cost[i+1]+( up[i]==down[i+1]?1:0 ) );
    cout<<ans<<endl;
    return 0;

}