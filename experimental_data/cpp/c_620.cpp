#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>
#include <time.h>


#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-8


#define pii pair<int,int>
#define FFF freopen("test","r",stdin)
#define all(a) a.begin(),a.end()
using namespace std;


inline i64 myInt()
{
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    int flag=1;
    if(c=='-') flag=-1,c=getchar();
    i64 x=0;
    while(isdigit(c))
    {
        x=(x*10)+(c-'0');
        c=getchar();
    }
    if(-1==flag) return -x;
    return x;
}


const int mod=1000000007;
const int N=300005;



int a[N],n;

int b[N],K;

vector<pair<int,int> > ans;

int main()
{
    n=myInt();
    for(int i=1;i<=n;i++) b[i]=a[i]=myInt();
    sort(b+1,b+n+1);
    int M=unique(b+1,b+n+1)-(b+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+M+1,a[i])-b;
    }
    clr(b,0);
    int pre=1;
    while(pre<=n)
    {
        K++;
        int cur;
        for(cur=pre;cur<=n;cur++)
        {
            int t=a[cur];
            if(b[t]==K)
            {
                ans.pb(MP(pre,cur));break;
            }
            else b[t]=K;
        }
        pre=cur+1;
    }
    if(ans.size()==0)
    {
        puts("-1"); return 0;
    }
    if(ans.back().second!=n)
    {
        ans.back().second=n;
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
}