#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) (a.begin()),(a.end())
#define ZERO(a) meset(a,0,sizeof(a))
#define FOR(x,val,to) for(int x=(val);x<int((to));x++)
#define FORE(x,val,to) for(auto x=(val);x<=(to);x++)
#define FORR(x,arr) for(auto &x: arr)
#define FORRC(x,arr) for(auto const &x: arr)
#define PRINT(arr) {copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GETVEC(vec,amount) copy_n(istream_iterator<int>(cin),(n),back_inserter((vec)))
#define GET(arr) for(auto &i: (arr)) cin>>i
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET) - memset(arr,MEMSET_INF,size)
#define INF 2139062143 //for comparison #define ULL_INF 18446744073709551614 //for comparison #define f first
#define s second
#define whatis(x) cerr << #x << " is " << x << endl;
#define alive cerr << "STH" << endl;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]";
  return os;
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
  os<<"("<<P.first<<","<<P.second<<")";
  return os;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    int ratio, lmax, nbad, init;
    cin >> init >> ratio >> lmax >> nbad;
    vi bad(nbad);
    GET(bad);
    sort(all(bad));
    ll ans=0;
    if(abs(init)>lmax)
        REE(0)
    if(init == 0)
        if(binary_search(all(bad),0))
            REE(0)
        else
            REE("inf");
    if(ratio == 0){
        if(binary_search(all(bad),init)){
            if(binary_search(all(bad),0))
                REE(0)
            else
                REE("inf");
        }
        else{
            if(binary_search(all(bad),0))
                REE(1)
            else
                REE("inf");
        }
    }
    if(ratio == 1){
        if(binary_search(all(bad),init))
            REE(0)
        else
            REE("inf");
    }
    if(ratio == -1){
        if(binary_search(all(bad),init) && binary_search(all(bad), -init))
            REE(0)
        else
            REE("inf");
    }
    for(ll cur = init; abs(cur) <= lmax; cur*=ratio){
        whatis(cur);
        whatis(ans);
        if(binary_search(all(bad),cur))
            continue;
        ans++;
    }
    REE(ans);
}