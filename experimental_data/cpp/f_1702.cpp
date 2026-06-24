#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define F first

#define S second

#define debug1(x) cout<<x<<'\n';

#define debug2(x, y) cout<<x<<' '<<y<<'\n';

#define debug3(x, y, z) cout<<x<<' '<<y<<' '<<z<<'\n';

#define debug4(x, y, z, s) cout<<x<<' '<<y<<' '<<z<<' '<<s<<'\n';

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> P;

void debug() {cout << "debug" << '\n';}

void debug(int arr[],int sz) {for(int i=0;i<sz;i++)cout<<arr[i]<<' ';cout<<'\n';}

void debug(ll arr[],int sz) {for(int i=0;i<sz;i++)cout<<arr[i]<<' '; cout<<'\n';}

void debug(bool arr[],int sz) {for(int i=0;i<sz;i++)cout<<arr[i]<<' ';cout<<'\n';}

void debug(vector<int> v) {for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<'\n';}

void debug(vector<ll> v) {for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<'\n';}

void debug(vector<bool> v) {for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<'\n';}

void debug(set<ll> s) {for(auto it=s.begin();it!=s.end();it++)cout<<*it<<' ';cout<<'\n';}

void debug(map<ll, ll> mp) {for(auto it=mp.begin();it!=mp.end(); it++)cout<<it->F<<' '<<it->S<<'\n';cout<<'\n';}

const ll e5 = 1e5 + 7, e7 = 1e7 + 7, e9 = 1e9 + 7;

int dx[]{0,1,0,-1};

int dy[]{1,0,-1,0};

int dx1[]{-1,-1,-1,0,0,1,1,1};

int dy1[]{-1,0,1,1,-1,-1,0,1};



///////// main code below //////////



int main() {

    FASTIO



    int t;

    cin >> t;

    while (t--) {

        int n;

        cin >> n;

        multiset<int> a;

        vector<int> b(n);

        for (int i = 0; i < n; i++) {

            int x;

            cin >> x;

            while ((x & 1) == 0) x >>= 1;

            a.insert(x);

        }

        for (auto& i : b) cin >> i;

        bool f = true;

        for (auto& i : b) {

            while (i && !a.count(i)) i >>= 1;

            if (!i) {

                f = false;

                break;

            }

            a.erase(a.find(i));

        }

        cout << (f ? "YES\n" : "NO\n");

    }

}