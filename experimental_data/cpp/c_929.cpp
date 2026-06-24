/*input
12 3
4 6 7 9 10 11 13 15 17 18 20 21
*/


#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
#define ld long double
#define llu long long unsigned
#define sc(t, x) static_cast<t>(x)
#define ar(t) vector < t >
#define pii pair < int, int >
#define pll pair < LL, LL >
#define pil pair < int, LL >
#define pli pair < LL, int >
#define mp make_pair
#define pb(a) push_back(a)
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define lp(loop, start, end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop, start, end) for ( int loop = start; loop > end; --loop )
#define lpi(loop, start, end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop, start, end) for ( int loop = start; loop >= end; --loop )
#define qmax(a, b) (((a)>(b))?(a):(b))
#define qmin(a, b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))
#define vi vector<int>





int main() {
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    int g,d,f;
    cin>>g>>d>>f;
    vector<int> a(g),b(d),c(f),all(g+d+f);
    lp(i,0,g) cin>>a[i],all[i] = a[i];
    lp(i,0,d) cin>>b[i],all[i+g] = b[i];
    lp(i,0,f) cin>>c[i],all[i+g+d] = c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    sort(all.begin(),all.end());
    ll ans = 0;
    lp(i,0,all.size()){
        int l_a = lower_bound(a.begin(),a.end(),all[i]) - a.begin();
        int r_a = upper_bound(a.begin(),a.end(),all[i]*2) - a.begin();
        int l_b = lower_bound(b.begin(),b.end(),all[i]) - b.begin();
        int r_b = upper_bound(b.begin(),b.end(),all[i]*2) - b.begin();
        int l_c = lower_bound(c.begin(),c.end(),all[i]) - c.begin();
        int r_c = upper_bound(c.begin(),c.end(),all[i]*2) - c.begin();
        if(l_a == a.size() || l_b == b.size() || l_c == c.size()) break;
        if(a[l_a] == all[i]){
            ans+=1LL*(r_b-l_b)*(r_b-l_b-1)/2*(r_c-l_c)*(r_c-l_c-1)/2*(r_c-l_c-2)/3;
        }
        if(b[l_b] == all[i]){
            l_b++;
            ans+=1LL*(r_a-l_a)*(r_b-l_b)*(r_c-l_c)*(r_c-l_c-1)/2*(r_c-l_c-2)/3;
        }
        if(c[l_c] == all[i]){
            l_c++;
            ans+=1LL*(r_a-l_a)*(r_b-l_b)*(r_b-l_b-1)/2*(r_c-l_c)*(r_c-l_c-1)/2;
        }
    }
    cout<<ans;
    return 0;
}