/*
Submitted With (^^) by -> Hossam ^_^
_____________________
|     ___     ___     |
|    (^_^)   (^_^)    |
|   /( | )\_/( | )\   |
|_____|_|_____|_|_____|
*/

#include <bits/stdc++.h>

using namespace std;

inline void prep()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
};

#define X first
#define Y second
#define ll long long
#define inf (0x7fffffffffffffff)
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << (x) << " ";
#define ZXC cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;

const int mod = (int)1e9 + 7;
const int MX = (int)2e5 + 20;

int cnt[MX];
vector<int> g[MX];

int main()
{
    prep();

    int n, m;
    cin >> n >> m;

    int a[n];
    int b[n];
    set<int> st;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i] % m;
        cnt[b[i]]++;
        g[b[i]].push_back(i);
    }

    int each = n / m;

    for(int i = 0; i < m; ++i){
        if(cnt[i] < each)
            st.insert(i);
    }

    ll changes = 0;

    for(int i = 0; i < m; ++i){

        if(cnt[i] <= each) continue; //ok

        if(cnt[i] > each){ //update the next nearest to you

            assert(st.size() > 0);

            int rem = cnt[i] - each;
            cnt[i] = each;

            for(auto idx : g[i]){
                rem--;
                auto it = st.lower_bound((i + 1) % m);
                if(it == st.end()) it = st.begin();
                int diff = (*it - i + m) % m;
                a[idx] += diff;
                changes += diff;
                cnt[*it]++;
                if(cnt[*it] == each) st.erase(it);
                if(rem == 0) break;
            }
        }
    }

    cout << changes << endl;
    for(int i = 0; i < n; ++i){
        cout << a[i] << " \n"[i == n - 1];
    }
    
    // ZXC
    return 0;
}