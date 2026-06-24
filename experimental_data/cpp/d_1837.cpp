#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e9+7;

ll binexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * 1LL * a) % M;
        }
        b >>= 1;
        a = (a * 1LL * a) % M;
    }
    return ans;
}

// vector<int> parent;
// vector<int> rank;
// int find_set(int v) {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(parent[v]);
// }

// void make_set(int v) {
//     parent[v] = v;
//     rank[v] = 0;
// }

// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (rank[a] < rank[b])
//             swap(a, b);
//         parent[b] = a;
//         if (rank[a] == rank[b])
//             rank[a]++;
//     }
// }

int setBitNumber(int n)
{
    if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
    return (1 << msb);
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> ans(n);
    stack<char> st;
    bool one = false;
    bool two = false;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c==')'){
            if(!st.empty() && st.top() == '('){
                ans[i] = 1;
                one = true;
                st.pop();
            }else st.push(c),ans[i] = 2,two = true;
        }else{
            if(!st.empty() && st.top() == ')'){
                ans[i] = 2;
                two = true;
                st.pop();
            }else st.push(c),ans[i] = 1,one = true;
        }
    }
    if(st.size()>=1){
        cout << -1 << endl;
        return;
    }
    if(one && two ){
        cout << 2 << endl;
        for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return;
    }
    else cout << 1 << endl;
    for(int i=0;i<n;i++){
        cout << 1 << ' ';
    }
    
    cout << endl;
}

int main() {
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}