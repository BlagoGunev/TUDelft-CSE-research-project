#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

typedef long long ll;
#define pb push_back
#define sz(x) static_cast<ll>((x).size())
#define pyes cout << "Yes\n"
#define pno cout << "No\n"
#define ce cout << '\n'
#define endl '\n'
#define fi first
#define se second
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define vll vector<ll>
#define vp vector<pair<long long, long long>>
#define trav(v) for (auto it = v.begin(); it != v.end(); it++)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)

const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;

void vin(vector<ll> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
}

template <typename T>
void pin(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i] << " ";
    }
    ce;
}

ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

const int NUM = 2e5 + 7;
const ll INF = 1e18 + 5;
vp moves = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n<=6||n==9){
            cout<<"NO"<<endl;
        }
        else{
                cout<<"YES"<<endl;
            if(n%3!=0){
                cout<<1<<" "<<2<<" "<<n-3<<endl;
            }
            else{
                cout<<1<<" "<<4<<" "<<n-5<<endl;
            }
        }
    }
    return 0;
}