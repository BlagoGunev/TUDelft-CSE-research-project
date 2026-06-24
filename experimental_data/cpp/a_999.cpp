#include<bits/stdc++.h>
using namespace std;
using std::string;
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define FORR(i,l,r) for(int (i)=l;(i)<(r);++(i))
#define mod 1000000007
#define pb push_back
#define pf push_front
#define ins insert
#define mp make_pair
#define bitcount __builtin_popcount
#define all(v) v.begin(),v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define pii pair<int,int>
#define pll pair<long long,long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int>
#define vll vector<long long>
#define mii map<int,int>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define EPSILON 1e-9
#define MAX 100002
#define PI 3.1415926535897932384626433832795028841971693993751
typedef long long  ll;
typedef unsigned long long llu;
typedef long double  ldb;
typedef double  db ;
int a[102];
/*ll power(ll b,ll p)
{
    if(p==0)
        return 1;
    ll ans=1;
    while(p>1)
    {
        if(p%2==0)
        {
            b*=b;
            b%=mod;
            p/=2;
        }
        else
        {
            ans*=b;
            ans%=mod;
            p-=1;
        }
    }
    ans*=b;
    ans%=mod;
    return ans;
}*/
int main()
{
   //\ freopen("in.txt","r",stdin);
    int n,k,cnt=0;
    cin>>n>>k;
    int last=n;
    FOR(i,n)
    cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]<=k)
            cnt++;
        else
        {
           // cout<<a[i]<<endl;
            last=i;
            break;
        }
    }// cout<<cnt<<endl;
    for(int i=n-1;i>last;i--)
    {//cout<<last<<endl;
       if(a[i]<=k)
         {
             //cout<<a[i];
             cnt++;
         }
         else
            break;
    }
    cout<<cnt<<endl;
}