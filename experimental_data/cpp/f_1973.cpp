#include "bits/stdc++.h"
using namespace std;
#define all(x) x.begin(),x.end()
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define ASSERT(...) 42
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int oo = 1e9;
struct tensor {
    vi d;
    vector<ll> got;
    tensor(vi dims) : d(dims) {
        auto sz = accumulate(all(dims),1,[](int a, int b) {return a*b;});
        got.assign(sz,0);
    }
    ll& operator[](vi v) {
        assert(v.size()==d.size());
        int id=0;
        for(int i=0;i<(int)v.size();++i) {
            id*=d[i];
            id+=v[i];
        }
        return got[id];
    }
    void suffixsums() {
        int cur=1;
        for(int j=d.size()-1;j>=0;--j) {
            auto dd = d[j];
            for(int i=got.size()-1;i>=0;--i) {
                int g=(i/cur)%dd;
                if(g!=dd-1) {
                    got[i]+=got[i+cur];
                }
            }
            cur*=dd;
        }
    }
};
vector<pi> factor(int a) {
    vector<pi> ps;
    for(int j=2;j*j<=a;++j) {
        if(a%j==0) {
            int e=0;
            while(a%j==0) {
                e++;
                a/=j;
            }
            ps.push_back({j,e});
        }
    }
    if(a!=1) ps.push_back({a,1});
    return ps;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    vi a(n),b(n),c(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    for(auto& i : c) cin >> i;
    vector<pair<ll,int>> ans;
    for(int rep=0;rep<2;++rep) {
       
        const auto pa = factor(a[0]), pb = factor(b[0]);
        vi myid;
        myid.reserve(pa.size()+pb.size());
        vector<pair<int,vi>> haveb,havea;
        auto rec2 = [&havea,&myid](auto&& self, int at, ll prod, const vector<pi>& ps) {
            if(at==ps.size()) {
                havea.push_back({prod,myid});
                return;
            }
            myid.push_back(0);

            while(myid.back()<=ps[at].second) {
                self(self,at+1,prod,ps);
                myid.back()++;
                prod*=ps[at].first;
            }
            myid.pop_back();
        };
        rec2(rec2,0,1,pb);
        swap(havea,haveb);
        rec2(rec2,0,1,pa);
        sort(all(havea));
        sort(all(haveb));
        vi dims;
        for(auto& [k,v] : pa) dims.push_back(v+1);
        for(auto& [k,v] : pb) dims.push_back(v+1);
        tensor pref(dims);
        tensor pref2(dims);
        auto index = [&](int d, int e, tensor& t) -> ll& {
            int l = gcd(d,a[0]);
            int r = gcd(e,b[0]);
            vi lv = lower_bound(all(havea),pair<int,vi>{l,{}})->second;
            vi rv =  lower_bound(all(haveb),pair<int,vi>{r,{}})->second;
            lv.insert(lv.end(),all(rv));
            return t[lv];
            
        };
        for(int i=1;i<n;++i) {
            int d = a[i], e = b[i];
            pref2.got.back()++;
            index(d,e,pref2)--;
            index(e,d,pref2)--;
            index(e,d,pref)+=c[i];
            index(gcd(d,e),gcd(d,e),pref)-=c[i];
            index(gcd(d,e),gcd(d,e),pref2)++;
            
        }
        if(rep==1) {
            pref.got.back()+=c[0];
        }
        pref.suffixsums();
        pref2.suffixsums();
       
        auto rec = [&](auto&& self, int at, ll ga=1,ll gb=1) -> void {
            if(at==(int)dims.size()) {
                if(!pref2[myid]) {
                    ans.push_back({pref[myid],ga+gb});
                }
                return;
            }
            myid.push_back(0);
            while(myid.back()<dims[at]) {
                self(self,at+1,ga,gb);
                myid.back()++;
                if(at<pa.size()) {
                    ga*=pa[at].first;
                } else gb*=pb[at-pa.size()].first;
            }
            myid.pop_back();
        };
        rec(rec,0);
        swap(a[0],b[0]);
    }
    sort(all(ans));
    int best=-oo;
    for(auto& [k,v] : ans) {
        best=max(best,v);
        v=best;
    }
    while(q--) {
        ll d; cin >> d;
        auto it = upper_bound(all(ans),make_pair(d,oo));
        cout << prev(it)->second << ' ';

    }

}