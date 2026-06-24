#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int> mp;
int co[400005];
int k;
vector<int> tree;
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = co[tl];
        return;
    }
    if (tl > tr) return;
    
    int m = (tl + tr) / 2;
    build(2 * v, tl, m);
    build(2 * v + 1, m + 1, tr);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}
 
int range(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return tree[v];
    if (l > r) return LLONG_MIN;
    int tm = (tl + tr) / 2;
    return max(range(2 * v, tl, tm, l, min(r, tm)), range(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int range1(int v, int tl, int tr, int l, int r) {
    if (l==r) return l;
    if (l > r) return LLONG_MIN;
    int tm = (tl + tr) / 2;
    if(range(2 * v, tl, tm, l, min(r, tm))>=(k+1))
    return range1(2 * v, tl, tm, l, min(r, tm));
    else
    return range1(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}
 
void update(int v, int tl, int tr, int l, int val) {
    if(l>tr || l<tl)
    return;         
 
    if (l == tl && l == tr) {
        tree[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, val);
    update(2 * v + 1, tm + 1, tr, l, val);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]); 
}
 
void solve()
{
    int n, m;
    cin>>n;
    mp.clear();
    tree.clear();

    int a[n+1];
    set<int> st;
    st.insert(0);
    st.insert(INT_MAX);
    for(int i=1; i<=n; i++){
    cin>>a[i];
    st.insert(a[i]);
    }

    cin>>m;

    vector<int> q[m+1];
    for(int i=1; i<=m; i++){
        char c;
        cin>>c;
        int k;
        cin>>k;
        if(c=='+'){
        q[i]={1,k};
        st.insert(k);
        }
        else if(c=='-'){
        q[i]={0,k};
        st.insert(k);
        }
        else{
            q[i]={-1,k};
        }
    }

    int x=0;
    int ar[st.size()+1];
    for(auto u: st){
        x++;
        mp[u]=x;
        ar[x]=u;
    }
    tree.resize(4*(x+1));

    st.clear();
    st.insert(0);
    st.insert(INT_MAX);
    for(int i=0; i<=x; i++)
    co[i]=0;
    co[mp[0]]=a[1]-0;
    for(int i=1; i<n; i++){
        co[mp[a[i]]]=a[i+1]-a[i];
        st.insert(a[i]);
    }
    co[mp[a[n]]]=INT_MAX-a[n];
    st.insert(a[n]);
    build(1,1,x);

    for(int i=1; i<=m; i++){
        if(q[i][0]==1){
            st.insert(q[i][1]);
            auto it=st.find(q[i][1]);
            it++;
            int up=*(it);
            it--;
            it--;
            int down=*(it);
            update(1,1,x,mp[q[i][1]],(up-q[i][1]));
            update(1,1,x,mp[down],-(up-q[i][1]));
        }
        else if(q[i][0]==0){
            auto it=st.find(q[i][1]);
            it++;
            int up=*(it);
            it--;
            it--;
            int down=*(it);
            update(1,1,x,mp[q[i][1]],-(up-q[i][1]));
            update(1,1,x,mp[down],(up-q[i][1]));
            st.erase(q[i][1]);
        }
        else{
            k=q[i][1];
            if(range(1,1,x,1,x)>=(k+1)){
                int ans=range1(1,1,x,1,x);
                // for(int j=1; j<=x; j++)
                // cout<<ar[j]<<" ";
                // cout<<"\n";
                // for(int j=1; j<=x; j++)
                // cout<<co[j]<<" ";
                // cout<<"\n";
                cout<<(ar[range1(1,1,x,1,x)]+1)<<" ";
            }
        }
    }

    cout<<"\n";
}
 
signed main()
{
    // freopen("mootube.in","r",stdin);
    // freopen("mootube.out","w",stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--)
        solve();
 
    return 0;
}