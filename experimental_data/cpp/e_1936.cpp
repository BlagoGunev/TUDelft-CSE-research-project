#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define O_O
using namespace std;
template <typename T>
using bstring = basic_string<T>;
template <typename T>
using matrix = vector<vector<T>>;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef double dbl;
typedef long double dbll; 
const ll INFL = 4e18+25;
const int INF = 1e9+42;
const double EPS = 1e-7;
const int MOD = (1<<23)*17*7 + 1; // 998244353
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
const int MAXN = 1e6+1;

/*
from https://github.com/defnotmee/definitely-not-a-lib

Implements integers in Z_MOD.
At all points it is assumed that 0 <= x < MOD and that MOD*MOD + MOD fits unsigned long long

If you want non-const MOD, use beegmod.cpp

*** If you only want to one value of MOD, check the "mint" alias at the bottom of the code. ***
*/

#ifndef O_O
#include"template.cpp"
#endif

template<ull M> 
struct modint{
    const static ull MOD = M; // in case we need to use it somewhere else (for example, combi.cpp)

    ull x;

    // It is assumed -M <= v. Extra mod is taken for safety.
    constexpr modint(ll v = 0) : x((v+M)%M){};

    constexpr modint(ll v, ll raw) : x(v){};

    // only on C++20
    bool operator<=>(const modint&) const = default;

    // Example on how to implement operators if youre lazy:
    // modint operator+(modint b){
    //     return modint((x+b.x));
    // }

    modint operator+(modint b){
        return modint(min(x+b.x, x+b.x-M),1);
    }

    modint operator-(modint b){
        return modint(min(x-b.x, x-b.x+M),1);
    }

    modint operator*(modint b){
        return modint((x*b.x%M),1);
    };

    modint inverse(){
        ll x = this->x, y = M;

        complex<ll> cx = {1,0}, cy = {0,1};

        while(x){
            ll curdiv = y/x;
            y-=curdiv*x;
            cy-=curdiv*cx;
            swap(cx, cy);
            swap(x, y);
        }

        return modint(cy.real());
    }

    modint operator/(modint b){
        return *this*b.inverse();
    }

    void operator+=(modint b){
        x = min(x+b.x, x+b.x-M);
    }

    void operator-=(modint b){
        x = min(x-b.x, x-b.x+M);
    }
    
    void operator*=(modint b){
        (x*=b.x)%=M;
    }

    void operator/=(modint b){
        *this = *this/b;
    }
};

using mint = modint<MOD>;

/*
from https://github.com/defnotmee/definitely-not-a-lib

Calculates factorials and binomials modulo p for all 
numbers from 0 to n-1. By default creates the struct
for n = MAXN and names it combi.

Idea for O(n) inverse of each number from this blog:
https://codeforces.com/blog/entry/83075
*/


#ifndef O_O
#include"template.cpp"
#include"modint.hpp"
#endif

template<ull M = MOD>
struct Combi{
    using mint = modint<M>;

    // note that inv[0] = 1 in this impl
    vector<mint> fac, inv, invfac;

    Combi(int n = MAXN){
        fac = inv = invfac = vector<mint>(n,1);

        for(int i = 2; i < n; i++){
            fac[i] = fac[i-1]*i;
            inv[i] = inv[M%i]*(M-M/i);
            invfac[i] = invfac[i-1]*inv[i];
        }
    }

    mint choose(int n, int k){
        if(n < k)
            return 0;
        return fac[n]*invfac[k]*invfac[n-k];
    }
};

Combi c;

/*
from https://github.com/defnotmee/definitely-not-a-lib

Thanks -is-this-fft- for your blog https://codeforces.com/blog/entry/111371

References for implementation: 
https://cp-algorithms.com/algebra/fft.html
http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf
https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransform.h
*/

#ifndef O_O
#include"template.cpp"
#include"modint.hpp"
#endif

using cdl = complex<dbll>;
using cd = complex<double>; // change this to long double if WA and pray

void fft(vector<cd>& v, bool inverse = 0){
    int n = v.size();
    int lg = log2(n);

    static vector<cdl> loots;
    static vector<cd> roots;

    if(loots.size() < n){
        loots.resize(n,1);
        roots.resize(n,1);
    }
    

    for(static int len = 2; len < n; len<<=1){
        cdl z = polar(1.0l, acos(-1.0l)/len);
        for(int i = len; i < 2*len; i++){
            roots[i] = loots[i] = loots[i/2] * ((i&1) ? z : 1);
        }
    }

    vector<int> rev(n);

    for(int i = 1; i < n; i++){
        rev[i] = (rev[i>>1]>>1)+((i&1)<<lg-1);
        if(rev[i] > i)
            swap(v[i],v[rev[i]]);
    }
    
    for(int len = 1; len < n; len<<=1){
        for(int block = 0; block < n; block+=2*len){
            for(int l = block; l < block+len; l++){
                cd cur = roots[l-block+len]*v[l+len];
                tie(v[l], v[l+len]) =
                    make_pair(v[l]+cur, v[l]-cur);
            }
        }
    }

    if(inverse){
        reverse(1+all(v));
        for(auto& i : v)
            i/=n;
    }
}


vector<ll> convolution(vector<ll>& a, vector<ll>& b){
    int mx = max(a.size(),b.size());
    int n = 1;

    while(n+1 < a.size()+b.size())
        n<<=1;

    vector<cd> in(n);

    for(int i = 0; i < a.size(); i++)
        in[i].real(a[i]);
    for(int i = 0; i < b.size(); i++)
        in[i].imag(b[i]);

    fft(in);

    vector<cd> newin(n);

    for(int i = 0; i < n; i++){
        int opos = (n-i)&(n-1);
        newin[i] = (in[opos]+conj(in[i]))
        *(in[opos]-conj(in[i]))*cd(0, -0.25/n);
    }
    
    fft(newin);

    vector<ll> ret(a.size()+b.size()-1);
    for(int i = 0; i < a.size()+b.size()-1; i++){
        ret[i] = round(newin[i].real());
    }

    return ret;

}

template<ull M = MOD>
vector<modint<M>> convolutionmod(vector<modint<M>>& a, vector<modint<M>>& b){
    
    const int len = sqrt(M);
    int n = 1;
    while(n+1 < a.size()+b.size())
        n<<=1;

    vector<cd> ca(n), cb(n);

    for(int i = 0; i < a.size(); i++)
        ca[i] = cd(a[i].x%len, a[i].x/len);
    
    for(int i = 0; i < b.size(); i++)
        cb[i] = cd(b[i].x%len, b[i].x/len);

    fft(ca), fft(cb);

    vector<cd> p1(n), p2(n);

    for(int i = 0; i < n; i++){
        int opos = (n-i)&(n-1);

        // also inverting for fft inverse
        p1[i] = (ca[opos]+conj(ca[i]))*cb[opos]*cd(0.5/n);
        p2[i] = (ca[opos]-conj(ca[i]))*cb[opos]*cd(0,-0.5/n);
    }

    fft(p1), fft(p2);

    vector<modint<M>> ret(a.size()+b.size()-1);

    for(int i = 0; i < ret.size(); i++){
        modint<M> small = round(p1[i].real()),
            mid = (ll)round(p1[i].imag()) + (ll)round(p2[i].real()),
            big = round(p2[i].imag());

        ret[i] = small + mid*len + big*len*len;

    }

    return ret;
}

#define rep(i,j,k) for(int i = j; i < k; i++)
#define sz(x) x.size()
typedef vector<ll> vl;
using C = cd;
template<int M> vl convMod(const vl &a, const vl &b) {
    
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i,0,n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i,0,sz(res)) {
		ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
		ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v(n);

        for(int& i : v)
            cin >> i, i--;

        vector<int> ids = {0};
        for(int i = 1; i < n; i++){
            v[i] = max(v[i],v[i-1]);
            if(v[i] != v[i-1])
                ids.push_back(i);
        }
        ids.push_back(n);
    
        vector<mint> f(n);
        f[0] = 0;

        auto solve =[&](int idl, int idr, auto solve)-> void {
            int l = ids[idl], r = ids[idr+1]-1;
            // cerr << idl << ' ' << idr << ' ' << l << ' ' << r << '\n';
            if(idl == idr){
                // cerr << f[l].x << '\n';
                f[l]+=c.fac[v[l]]*(l+1);
                f[l]*=c.invfac[v[l]-l];
                for(int i = l+1; i <= r; i++){
                   f[i]+=c.fac[v[i]];
                   f[i]*=c.invfac[v[i]-i];
                }
                return;
            }

            int idm = (idl+idr)>>1;
            int m = ids[idm+1]-1;
            solve(idl,idm,solve);
            vector<ll> left(m-l+1);
            for(int i = l; i <= m; i++)
                left[i-l] = f[i].x;
            
            vector<ll> lefty = left;
            for(int i = l; i <= m; i++){
                (lefty[i-l] *= i)%=MOD;
            }

            int bigdiff = v[r]-l, smalldiff = v[m+1]-m;

            // sum(v[r]-v[m+1]+m-l) = O(n); 
            vector<ll> diff(bigdiff-smalldiff+1);

            for(int i = smalldiff; i <= bigdiff; i++){
                diff[i-smalldiff] = c.fac[i-1].x;
            }

            // cerr << idl << ' ' << idr << ' ' << l << ' ' << r << ' ' << smalldiff << ' ' << bigdiff << '\n';

            vector<ll> ressame = convMod<MOD>(left,diff), resdiff = convMod<MOD>(lefty,diff);

            int smallres = l + smalldiff;


            for(int i = m+1; i <= r; i++){
                // cerr << "sum " << i << ' ' << (ressame[v[i]-smallres]*i - resdiff[v[i]-smallres]).x << '\n';
                if(v[i] != v[i-1])
                    f[i] -= ressame[v[i]-smallres]*i - resdiff[v[i]-smallres];
                else f[i] -= ressame[v[i]-smallres];
            }

            solve(idm+1,idr,solve);

        };
        
        solve(0,ids.size()-2,solve);

        cout << f.back().x << '\n';
        // for(mint i : f)
        //     cerr << i.x << ' ' << (i*-1).x << '\n';

    }
    
    return 0;

}