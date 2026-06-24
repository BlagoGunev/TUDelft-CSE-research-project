#include <bits/stdc++.h>

using namespace std;



#define ll long long

#define ld long double

#define fr(i,a,b) for(ll i=a;i<b;i++)

#define frd(i,a,b) for(ll i=b-1;i>=a;i--)

#define pb push_back

#define ppb pop_back

#define ff first

#define ss second

#define pll pair<ll,ll>

#define mp make_pair

#define m1 1000000007

#define m2 998244353



#ifndef ONLINE_JUDGE

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#else

#define debug(x)

#endif



void _print(ll t) {cerr << t;}

void _print(int t) {cerr << t;}

void _print(string t) {cerr << t;}

void _print(char t) {cerr << t;}

void _print(double t) {cerr << t;}



template <class T, class V> void _print(pair <T, V> p);

template <class T> void _print(vector <T> v);

template <class T> void _print(set <T> v);

template <class T, class V> void _print(map <T, V> v);

template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



void init_code(){

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE

}

 

void solve() {

    string l="abcdefghijklmnopqrstuvwxyz";

    int n,k;

    cin>>n>>k;

    string s;

    cin>>s;

    sort(s.begin(),s.end());

    map<char,int> m;

    fr(i,0,n){

        m[s[i]]++;

    }

    auto itr=l.begin();

    for(int i=0;i<26;i++){

        if(m.find(*itr)==m.end()){

            m[*itr]=0;

        }

        itr++;

    }

    string ans;

    int cnt=0,tim =0,max=0;

    int rp=n/k;

    debug(m);

    while(k--){

        int opn=0;

        while(cnt!=rp){

            for(auto &it: m){

                if(tim>0){

                    while(cnt!=rp && max>0){

                        max--;

                        cnt++;

                    }

                    if(cnt==rp) break;

                }







            if(cnt==rp){

                if(opn==0){

                    ans.pb(it.first);



                    // debug(1);

                    // debug(ans);

                } 

                

                break;

            }

            else if(it.second>0){

                it.second--;

                debug(it.second);

                if(it.second>max){

                    max=it.second;

                    it.second=max;

                }  

                debug(max);

                cnt++;

            }

            else if(it.second==0){

                if(opn==0) ans.pb(it.first);

                // debug(ans);

                // debug(2);

                opn=1;



            }



            // if(cnt==rp && opn==1) break;

        }

            tim++;

        }

        tim=0;

        cnt=0;

        debug(ans);

        debug(m);

    }

    cout<<ans<<endl;





 

 

 

}

 

int main() {

 

#ifndef ONLINE_JUDGE

  freopen("Error.txt","w",stderr);

#endif

 

init_code();

ios_base::sync_with_stdio(false);

cin.tie(0);cout.tie(0);

    ll tc;

    tc=1;

    cin>>tc;

    while(tc--){

        solve();

    }

return 0;

}