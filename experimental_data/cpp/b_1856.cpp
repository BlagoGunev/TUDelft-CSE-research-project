#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl "\n"

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//greater<int>  =>  descending order
//less<int>  =>  ascending order
//less_equal<int>  =>  multiset
//p.order_of_key(k) => no of elements strictly smaller than k
//*p.find_by_order(k) => k th element in set(counting from zero)

//set<int,greater<int>>s;(descending)
//map<int,string,greater<int>>b;(descending)
//priority_queue<int,vector<int>,greater<int>>p;(ascending)

const int INF=1e18;
const int MAXN=3e3+1;
const int MOD=1e9+7;
const int MOD2=998244353;
const int N=1e5+3;


int gcd(int a, int b){return b?gcd(b,a%b):a;}
int lcm(int a, int b){return a/gcd(a,b)*b;}
int powm(int a,int b,int mod=MOD){a%=mod;int res=1;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b=b>>1;}return res;}
int inverse(int x,int m){return powm(x,m-2,m);}

//Euler Totient Function Φ(n)
//no of coprimes of n between i to n inclusive
//O(sqrt(n))
int phi(int n){int result=n;for(int i=2;i*i<=n;i++){if (n%i==0){while(n%i==0)n/=i;result-=result/i;}}if (n>1)result-=result/n;return result;}

//(a/b)%M=(a%M*inverse(b,M))%M   ;only when gcd(a,M)=1
//(a/b)%M=(a%M*powm(b,M-2,M))%M   ;only when gcd(a,M)=1

//(a^b^c)%M = powm(a,powm(b,c,M-1),M)

//nCr
/*
int nCr(int n,int r) {
    int p=1,k=1;
    if (n-r<r) {r=n-r;}
    if (r!=0){
        while(r){p*=n;k*=r;int m=__gcd(p, k);p/=m;k/=m;n--;r--;}
    }else{p=1;}
    return p;
}
*/

//Sieve
/*
vector<bool>is_prime(N+1,true);
vector<int>lp(N,0),hp(N,0);
void sieve(){
is_prime[0]=is_prime[1]=false;
for(int i=2;i<=N;i++){
    if(is_prime[i]){lp[i]=hp[i]=i;
        for(int j=2*i;j<N;j+=i){
            is_prime[j]=false;hp[j]=i;
            if(lp[j]==0){lp[j]=i;}
        }
    }
}
}
*/

//Count Divisors of N in O(sqrt(N))
//int countDivisors(int n){int cnt=0;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if(n/i==i)cnt++;else cnt=cnt+2;}}return cnt;}




void solve(){
    int n;cin>>n;int s=0;
    vector<int>a(n);int o=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=((a[i]==1)?0:a[i]);
        o+=(a[i]==1);
    }//cout<<s<<" "<<o<<endl;
    cout<<((n==1||s-(n-o)<o)?"NO":"YES")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    //sieve();
    while(t--){
        solve();
    }
    return 0;
}