#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;
    while((c=getchar())<'0' || c>'9');
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res;
}
//vector<int> v[100010];
int pre[100010];
int find(int x)
{
    if(x==pre[x])return x;
    return find(pre[x]);
}
int main()
{

    int n=in(),k=in();

    for(int i=0;i<=n;i++)pre[i]=i;
    while(k--)
    {
        int t=in();
        int now=in();
        --t;
        while(t--)
        {
            int val=in();
            pre[now]=val;
            now=val;
        }
    }
    int i=1;

    while(pre[i]==i+1)i++;
    //cout<<i<<endl;
    int ans=0;
    for(;i<=n;i++)
    {

        while(pre[i]==i && i<=n)i++,ans++;
        int x=i,j;
        bool have=0;
        while( pre[x]!=x )
        {
            j=pre[x];
            pre[x]=x;
            x=j;
            ans++;
            have=1;
           // cout<<"ans"<<ans<<endl;
            //cout<<"x="<<x<<endl;
        }
            if(have)i--;
        //while(pre[i]==i && i<=n)i++,ans++;


    }
     cout<<ans-2<<endl;
    return 0;
}