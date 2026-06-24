#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <list>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <cstring>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define REP(i,a,b) for(ll i=(ll) a; i<(ll) b; i++)
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define ff first
#define ss second
#define whole(x) x.begin(),x.end()
#define DEBUG(i) cout<<"Pedro "<<i<<endl
#define INF 1000000000000000000LL
#define EPS ((ld)0.00000000001)
#define pi ((ld)3.141592653589793)
#define VV(vvvv,NNNN,xxxx); REP(iiiii,0,NNNN) {vvvv.pb(xxxx);}
ll mod=1000000007;

template<class A=ll> 
void Out(vector<A> a) {REP(i,0,a.size()) {cout<<a[i]<<" ";} cout<<endl;}

template<class A=ll>
void In(vector<A> &a, ll N) {A cur; REP(i,0,N) {cin>>cur; a.pb(cur);}} 



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cout.precision(20);
	ll T; cin>>T;
    REP(t,0,T)
    {
        ll N; cin>>N; vector<ll> p; In(p,N);
        ll val = 0LL; bool ok=true;
        REP(i,0,N)
        {
            val = max(val,p[i]);
            if(val>p[i]+1) {ok=false;}
        }
        if(ok) {cout<<"YES"<<endl;} else {cout<<"NO"<<endl;}
    }
    return 0;
}