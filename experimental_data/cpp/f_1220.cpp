#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

struct ver{
    int val,l,up;
};
int main()
{
	int n,cnt=0,aa;
	scanf("%i",&n);
	if(n==1)
    {
        printf("1 0\n");
        return 0;
    }
	deque<int> a(n);
	vector<int> koliko(n+1);
	for(int i=0;i<n;i++)
        scanf("%i",&a[i]),a[i]=n-a[i]+1,koliko[a[i]]=i;
    while(a[0]!=n)
        aa=a[0],a.pop_front(),a.pb(aa),cnt++;
    a.pb(n);
    int sol=0;
    vector<ver> stk;
    vector<int> solL(n+1),solR(n+1);
    for(int i=1;i<n;i++)
    {
        int mxLevo=0;
        while(stk.size()&&stk.back().val<a[i])
            mxLevo=max(mxLevo+1,stk.back().l+1),stk.pop_back();
        ver tr={a[i],mxLevo,stk.size()};
        stk.pb(tr);
        sol=max(sol,tr.l+tr.up+1);
        solL[i]=sol;
    }
    sol=0;
    stk.clear();
    for(int i=n-1;i>0;i--)
    {
        int mxLevo=0;
        while(stk.size()&&stk.back().val<a[i])
            mxLevo=max(mxLevo+1,stk.back().l+1),stk.pop_back();
        ver tr={a[i],mxLevo,stk.size()};
        stk.pb(tr);
        sol=max(sol,tr.l+tr.up+1);
        solR[i]=sol;
    }
    int best=INT_MAX,gde;
    for(int i=0;i<n;i++)
    {
        int trsol=1+max(solL[i],solR[i+1]);
        if(trsol<best)
            best=trsol,gde=a[i+1];
    }
    printf("%i %i\n",best,koliko[gde]);
    return 0;
}
/*
7
7 2 4 1 5 6 3
*/