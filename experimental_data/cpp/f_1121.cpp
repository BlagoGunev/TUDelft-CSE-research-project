#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define pb emplace_back
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define rep(i, j, k) for(i=j; i<k; i++)
#define sep(i, j, k) for(i=j; i>k; i--)
const int N = 1e5+5, inf = 1e9+7;
int n, k, i, j;
int A[N];

struct ST{
    const int inf = 1e9;
    vector<map<int,int>> next;
    vi len,start,link,s;
    int node,pos,N,n;
    ST(): node(0),pos(0),N(0),n(0){
        make_node(0,0);
    }
    ii get_label(int k){
        int l=start[k];
        int r=min(l+len[k]-1,n-1);
        return {l,r};
    }
    int make_node(int _start, int _len)
    {
        next.emplace_back();
        link.emplace_back(0);
        start.emplace_back(_start);
        len.emplace_back(_len);
        return N++;
    }
    void go_edge()
    {
        while(next[node].count(s[n-pos]) && pos > len[next[node][s[n - pos]]])
        {
            node = next[node][s[n - pos]];
            pos -= len[node];
        }
    }
    void add_letter(int c)
    {
        s.pb(c);
        n++;
        pos++;
        int last = 0;
        while(pos > 0)
        {
            go_edge();
            int edge = s[n - pos];
            int &v = next[node][edge];
            int t = s[start[v] + pos - 1];
            if(v == 0)
            {
                v = make_node(n - pos, inf);
                link[last] = node;
                last = 0;
            }
            else if(t == c)
            {
                link[last] = node;
                return;
            }
            else
            {
                int u = make_node(start[v], pos - 1);
                next[u][c] = make_node(n - 1, inf);
                next[u][t] = v;
                start[v] += pos - 1;
                len [v] -= pos - 1;
                v = u;
                link[last] = u;
                last = u;
            }
            if(node == 0)
                pos--;
            else
                node = link[node];
        }
    }
};
ST st;
string s;
int dp[N], B[N];

int dfs(int cur, int p){
    int l = min(st.n - st.start[cur], st.len[cur]),
    sr = st.start[cur], j=0;
    while(j<l && p<n && A[j+sr]==A[p])
        j++, p++;
    if(p==n) return n;
    if(j<l || st.next[cur].count(A[p])==0) return p;
    return dfs(st.next[cur][A[p]], p);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i, j, a, b, c;
    cin>>n>>a>>b;
    cin>>s;
    rep(i, 0, n) A[i] = s[i]-'a'+1;
    st.add_letter(A[0]);
    rep(i, 1, n){
        c = dfs(0, i);
        if(c>i) B[i] = c;
        st.add_letter(A[i]);
    }
    sep(i, n-1, -1){
        dp[i] = dp[i+1]+a;
        if(B[i] > i) dp[i] = min(dp[i], dp[B[i]]+b);
    }
    cout<<dp[0];
}