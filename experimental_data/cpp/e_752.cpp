#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;
int inf_int=1e9;
ll inf_ll=1e18;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
const double pi=3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz size()


#define pi asdafasfasfasfasf
bool debug=0;
const int MAXN=1e6+10,MAX_A=1e7+50;
int mod=1e9;

int a[MAXN];
int suf[MAX_A];
int cnt[MAX_A];
int c,d;
int z=0;

void solve()
{
     int n,k;
     scanf("%d %d",&n,&k);
     ll sum=0;
     int mx=0;
     for(int i=1;i<=n;++i)
     {
         scanf("%d",&a[i]);
         sum+=a[i];
         mx=max(mx,a[i]);

     }
     if(sum<k)
     {
         cout << -1;
         return;
     }
     for(int i=1;i<=n;++i)
     {
         suf[a[i]]++;
         cnt[a[i]]++;
     }
     int c,d;
     for(int i=mx;i>=2;--i)
     {
         suf[i]=suf[i]+suf[i+1];
         if(suf[i]>=k)
         {
             cout << i;
             return;
         }
         if(cnt[i])
         {
             c=i>>1,d=(i>>1)+(i&1);
             suf[c]+=cnt[i];
             cnt[c]+=cnt[i];
             cnt[d]+=cnt[i];
         }

     }
     cout << 1;



}


#define FILE "key"
int main()
{
        #ifdef zxc
            freopen("input.txt","r",stdin);
       //     freopen("output.txt","w",stdout);
        #endif // zxc

    //    freopen(FILE".in","r",stdin);
   //   freopen(FILE".out","w",stdout);

       if(!debug)
       {
      //      ios_base::sync_with_stdio(0);
      //      cin.tie(0);
      //      cout.tie(0);
       }

        int t=1;
         while(t--)
            solve();
        return 0;
}