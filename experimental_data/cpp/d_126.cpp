#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <ctime>
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define next ssdfgh
#define prev aslpkfh
#define y1 sldkjghs
#define ws lsdkghjns
#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif
//#pragma comment(linker, "/STACK:100000000000")
#define sz(a) ((int)(a).size())
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
const ld E=1e-10;
const ll inf=(ll)2e18;
#define TASK_NAME "a"
const int maxn=200;
 
ll f[maxn];
int a[maxn];
ll dp[maxn][2];
int main()
{
    int tt=0;
    scanf("%d", &tt);
    f[0]=1, f[1]=1;
    int fn=2;
    for(int i=2;f[i-1]<inf;i++) f[i]=f[i-1]+f[i-2], fn++;
    while(tt --> 0)
    {
        ll n;
        scanf(I64, &n);
        for(int i=fn-1;i>=0;i--)
        {
            if(n>=f[i]) a[i-1]=1, n-=f[i];
            else a[i-1]=0;
        }
        assert(n==0);
        int k=0;
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=0;i<fn;i++) if(a[i])
        {
            dp[i+1][0]=(i-k)/2 * dp[k][1] + (i-k+1)/2 * dp[k][0];
            dp[i+1][1]=dp[k][0]+dp[k][1];
            k=i+1;
        }
        printf(I64"\n", dp[k][0]+dp[k][1]); 
    }   
    #ifdef home
        cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}