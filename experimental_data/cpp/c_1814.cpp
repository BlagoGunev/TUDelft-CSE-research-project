/* /\_/\
  (=・_・)　
  / >  \> ..........
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

//*find_by_order
//order_of_key
template <typename T> using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//DEBUG
#ifndef ONLINE_JUDGE
#include "Shiva.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
//END

#define TEST int T;cin>>T;cin.ignore();while(T--)
#define skip continue
#define pb push_back 
#define pf push_front
#define __bp(x) __builtin_popcountll(x)
#define FOR(n) for(int i=0;i<n;i++)
#define loop(i,a,b,c) for(int i=a;i<b;i+=c)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ppb pop_back 
#define ppf pop_front
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define cl cout<<"\n";
#define ll long long
#define int long long                       /*Shiva*/
#define ull unsigned ll
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define inf LLONG_MAX
#define ninf LLONG_MIN
#define all(l) l.begin(),l.end()
#define rall(l) l.rbegin(),l.rend()
#define rev(l) reverse(l.begin(),l.end())
#define rsort(l) sort(l.rbegin(),l.rend())
#define Cout(x) cout<<((x)?"YES\n":"NO\n");
#define sum(l) accumulate(l.begin(),l.end(),0ll)
#define vecin(l,n) vector<int>l(n);for(int &Ele:l){cin>>Ele;}
#define vecinp(l,n,d) vector<d>l(n);for(auto &Ele:l){cin>>Ele;}
#define iShowSpeed ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define CerrTime cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<" ms\n";

//Functions
// vector<string>vec_splitter(string s,string a=":"){s+=a;vector<string>res;while(!s.empty())
// {int ind=s.find(a);res.push_back(s.substr(0,ind));s=s.substr(ind+1);}return res;}
template<class T>map<T,int> Counter(vector<T>&l){map<T,int>d;for(T &i:l){d[i]++;}return d;}
map<char,int> Counter(string &s){map<char,int>d;for(char &i:s){d[i]++;}return d;}
template<class T>unordered_map<T,int> uCounter(vector<T>&l){unordered_map<T,int>d;for(T &i:l){d[i]++;}return d;}
int bpow(int n,int x,int mod=1e9+7){int ans=1;while(x>0){if(x&1){ans=(ans*n%mod)%mod;}n=(n*n%mod)%mod;x>>=1;}return ans;}
unordered_map<char,int> uCounter(string &s){unordered_map<char,int>d;for(char &i:s){d[i]++;}return d;}
string reverse(string &s){string s1(rall(s));return s1;}
bool ispali(string &s){return s==reverse(s);}
template<class T>void sort(T &l){sort(begin(l),end(l));}
bool isprime(int n){if(n<=1){return false;}if(n<=3){return true;}if(n%2==0 || n%3==0){return false;}
for(int i=5;i*i<=n;i+=6){if(n%i==0 || n%(i+2)==0){return false;}}return true;}
string genStr(int n,string s){string s1;for(int i=0;i<n;i++)s1+=s;return s1;}
string genStr(int n,char s){string s1;for(int i=0;i<n;i++)s1+=s;return s1;}
template<class T> T __lcm(T a,T b){return (a*(b/__gcd(a,b)));}
template<class T> T max(vector<T>&l){return *max_element(all(l));}
template<class T> T min(vector<T>&l){return *min_element(all(l));}
template<class T>void printl(T &l,string sep=" "){for(auto &i:l){cout<<i<<sep;}}
template<class T>void minmax(T &a,T &b){T temp=min(a,b);b=max(a,b);a=temp;}
int mod_add(int a,int b,int m=1e9+7){a%=m;b%=m; return(((a+b)%m)+m)%m;}
int mod_mul(int a,int b,int m=1e9+7){a%=m;b%=m; return(((a*b)%m)+m)%m;} //modulo arithmetic
int mod_sub(int a,int b,int m=1e9+7){a%=m;b%=m; return(((a-b)%m)+m)%m;}
string bin(int n){return bitset<3>(n).to_string();}
string bit(int n){if(n==0)return "0";string t=bitset<64>(n).to_string();return t.substr(t.find('1'));}
int b2d(string s){int ans=0;for(int i=s.size()-1,j=0;i>=0;i--,j++){if(s[i]=='1') ans+=(1ll<<j);}return ans;}
/*********************************************************************************************************************************/
void Shiva(){

    TEST {
        int n,s1,s2;
        cin>>n>>s1>>s2;
        vecin(l,n);

        vector<pair<ll, ll>>p;

        for(int i=1;i<=n;i++) {
            p.pb({l[i-1],i});
        }
        sort(p); debug(p)

        vector<int>a;
        vector<int>b;

        int time=0;

        while(!p.empty()) {
            time++;

            if(time%s1==0 and time%s2==0) {
                if(p.size()>1) {
                    a.pb(p.back().ss); p.ppb();
                    b.pb(p.back().ss);  p.ppb();
                }
                else {
                    a.pb(p.back().ss); p.ppb();
                }
            }
            else if(time%s1==0) {
                a.pb(p.back().ss); p.ppb();
            }
            else if(time%s2==0) {
                b.pb(p.back().ss); p.ppb();
            }
        }
        cout<<a.size()<<" "; printl(a); cl;
        cout<<b.size()<<" "; printl(b); cl;
    }
}
signed main(){
#ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
#endif
    iShowSpeed;
    // TEST
    Shiva();
    // CerrTime;
}