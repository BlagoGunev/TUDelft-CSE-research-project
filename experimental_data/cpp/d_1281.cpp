#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
#define maxm 200005
#define INF 1234567890
#define eps 1e-15
#define p 1000000007
const double pi=acos(-1);
template<class T>inline bool read(T &x)
{
    x=0;register char c=getchar();register bool f=0;
    while(!isdigit(c)){if(c==EOF)return false;f^=c=='-',c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    if(f)x=-x;
    return true;
}
template<class T>inline bool readc(T &x)
{
    register char c=getchar();
    while(c==' '||c=='\n'||c=='\r'||c=='\t')c=getchar();
    if(c==EOF)return false;
    x=c;
    return true;
}
template<class T>inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^48);
}
template<class T>inline void prints(T x){for(register ll i=0;x[i]!='\0';i++)putchar(x[i]);}
template<class T>inline void print(T x,char c){print(x),putchar(c);}
template<class T>inline void prints(T x,char c){prints(x),putchar(c);}
template<class T,class ...S>inline bool read(T &x,S &...y){return read(x)&&read(y...);}
ll t,n,m,row[100],col[100],tot,flag;
char x[100][100];
int main()
{
    //freopen("test.in","r",stdin);
    read(t);
    while(t--)
    {
        read(n,m);
        tot=flag=0;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
            {
                readc(x[i][j]);
                if(x[i][j]=='A')
                {
                    row[i]++;
                    col[j]++;
                    tot++;
                }
            }
        if(!tot)
        {
            prints("MORTAL",'\n');
            continue;
        }
        if(tot==n*m)
        {
            print(0,'\n');
            continue;
        }
        if(row[1]==m||row[n]==m||col[1]==n||col[m]==n)
        {
            print(1,'\n');
            continue;
        }
        for(ll i=2;i<n;i++)
        {
            if(row[i]==m)
            {
                print(2,'\n');
                flag=1;
                break;
            }
        }
        if(flag)continue;
        for(ll i=2;i<m;i++)
        {
            if(col[i]==n)
            {
                print(2,'\n');
                flag=1;
                break;
            }
        }
        if(flag)continue;
        if(x[1][1]=='A'||x[1][m]=='A'||x[n][1]=='A'||x[n][m]=='A')
        {
            print(2,'\n');
            continue;
        }
        if(row[1]+row[n]+col[1]+col[m]>=1)
        {
            print(3,'\n');
            continue;
        }
        print(4,'\n');
    }
    return 0;
}