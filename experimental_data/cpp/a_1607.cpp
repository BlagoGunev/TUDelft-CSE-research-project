/*                  Robiul Islam Rubel

 */

#include<bits/stdc++.h>
#define ll                long long int
#define ld                long double
#define pb                push_back
#define pf                push_front
#define ppb               pop_back
#define ppf               pop_front
#define sz                size()
#define pi                acos(-1.0)
#define mod               1000000007
#define F                 first
#define S                 second
#define C                 continue
#define min3(a,b,c)       min(a,min(b,c))
#define max3(a,b,c)       max(a,max(b,c))
#define min4(a,b,c,d)     min(a,min(b,min(c,d)))
#define max4(a,b,c,d)     max(a,max(b,max(c,d)))
#define mem(a,b)          memset(a,b,sizeof(a))
#define all(a)            (a).begin(),(a).end()
#define gcd(a,b)          __gcd(a,b)
#define lcm(a,b)          ((a)*((b)/gcd(a,b)))
#define case(a)           cout<<"Case "<<(a)<<": "
#define point(a)          fixed<<setprecision(a)
#define get(a)            for(auto &x:a) cin>>x
#define print(a)          for(auto x:a) cout<<x<<" "; cout<<endl
#define see(x)            cout<<#x<<" = "<<x<<endl
#define uniq(a)           sort(all(a)); (a).erase(unique((a).begin(),(a).end()),(a).end())
#define big(a)            transform((a).begin(),(a).end(),(a).begin(),::toupper)
#define small(a)          transform((a).begin(),(a).end(),(a).begin(),::tolower)
#define ischar(a)         (('a'<=a&&a<='z')('A'<=a&&a<='Z'))
#define isvowel(a)        (a=='a'|a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
#define tc        int test; cin>>test; while(test--)
using namespace std;
void fast()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve()
 {

    ll n,k,a,b,x,y,z,od,ev,sum,cnt=0,d,f;
    tc
    {
        string s,ss;
        cin>>s>>ss;
        ll l1=s.sz;
        ll l2=ss.sz;
        ll q=0;
        ll ar[105];
        for(int i=0;i<l2;i++)
        {
            for(int j=0;j<l1;j++)
            {
                if(ss[i]==s[j])
                {
                    ar[q]=j+1;
                    q++;
                }
            }
        }
        d=0;
        /*for(int i=0;i<l2;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
        */
        for(int i=0;i<l2-1;i++)
        {
            d+=abs(ar[i]-ar[i+1]);
        }
        cout<<d<<endl;

    }
 }
int main()
{

   solve();

       return 0;
}