#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define debug(x) cerr<<#x<<" = "<<x<<endl
#define endl '\n'
mt19937 rnd(time(0));
const int mod=1e9+7;int N;
 
void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
struct maxQueue{
    stack<pair<int,int>> s1,s2;
    int getmax(){
        if(s1.empty() && s2.empty()){
            return -INT_MAX;
        }
        else if(s1.empty()){
            return s2.top().second;
        }
        else if(s2.empty()){
            return s1.top().second;
        }
        return max(s1.top().second,s2.top().second);
    }
    void add(int v){
        if(s2.empty()){
            s2.push({v,v});
        }
        else{
            s2.push({v,max(v,s2.top().second)});
        }
    }
    void rmv(){
        if(s1.empty()){
            while(!s2.empty()){
                if(s1.empty()){
                    s1.push({s2.top().first,s2.top().first});
                }
                else{
                    s1.push({s2.top().first,max(s2.top().first,s1.top().second)});
                }
                s2.pop();
            }
        }
        s1.pop();
    }
};
 
struct DSU{
    vector<int> par;
    vector<int> siz;
    vector<int> comp;
    void init(int n){
        par.resize(n);
        siz.resize(n);
        comp.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int get_par(int a){
        vector<int> compress(0);
        while(par[a]!=a){
            compress.push_back(a);
            a=par[a];
        }
        for(int i=0;i<compress.size();i++){
            par[compress[i]]=a;
        }
        return a;
    }
    int get_size(int a){
        a=get_par(a);
        return comp[a];
    }
    bool same(int a,int b){
        a=get_par(a);
        b=get_par(b);
        if(a==b){
            return 1;
        }
        return 0;
    }
    void add(int a,int b){
        a=get_par(a);
        b=get_par(b);
        if(!same(a,b)){
            comp[a]=comp[a]+comp[b];
            comp[b]=comp[a];
        }
        if(siz[a]>=siz[b]){
            par[b]=a;
            siz[a]=max(siz[a],siz[b]+1);
        }
        else{
            par[a]=b;
            siz[b]=max(siz[a]+1,siz[b]);
        }
    }
};
 
struct trie {
    trie* left=nullptr;
    trie* right=nullptr;
    void insert(int x){
        trie* curr=this;
        for(int i=20;i>=0;i--){
            if(x&(1<<i)){
                if(!(curr->right)){
                    curr->right=new trie();
                }
                curr=curr->right;
            }
            else{
                if(!(curr->left)){
                    curr->left=new trie();
                }
                curr=curr->left;
            }
        }
    }
    int minxor(int x){
        trie* curr=this;
        int ans=0;
        for(int i=20;i>=0;i--){
            if(x&(1<<i)){
                if(curr->right!=nullptr){
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                    ans+=(1<<i);
                }
            }
            else{
                if(curr->left!=nullptr){
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                    ans+=(1<<i);
                }
            }
        }
        return ans;
    }
    int maxxor(int x){
        trie* curr=this;
        int ans=0;
        for(int i=20;i>=0;i--){
            if(x&(1<<i)){
                if(curr->left!=nullptr){
                    curr=curr->left;
                    ans+=(1<<i);
                }
                else{
                    curr=curr->right;
                }
            }
            else{
                if(curr->right!=nullptr){
                    curr=curr->right;
                    ans+=(1<<i);
                }
                else{
                    curr=curr->left;
                }
            }
        }
        return ans;
    }
    ~trie() {
        delete left;
        delete right;
    }
};
 
struct mass_segtree{
    int sz;
    vector<int> arr;
    vector<int> oper;
    void init(int n){
        sz=1;
        while(sz<n) sz*=2;
        arr.resize(2*sz,0);
        oper.resize(2*sz,0);
    }
    void set(int l,int r,int v,int x,int lx,int rx){
        if(lx>=r || l>=rx) return;
        if(lx>=l && rx<=r){
            arr[x]+=v;
            oper[x]+=v;
            return;
        } 
        int m=(lx+rx)/2;
        set(l,r,v,2*x+1,lx,m);
        set(l,r,v,2*x+2,m,rx);
        arr[x]=min(arr[2*x+1],arr[2*x+2])+oper[x];
    }
    void set(int l,int r,int v){
        set(l,r+1,v,0,0,sz);
    }
    int op(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx) return INT_MAX;
        else if(lx>=l && rx<=r) return arr[x];
        int m=(lx+rx)/2;
        int a1=op(l,r,2*x+1,lx,m);
        int a2=op(l,r,2*x+2,m,rx);
        return min(a1,a2)+oper[x];
    }
    int op(int l,int r){
        return op(l,r+1,0,0,sz);
    }
};
 
struct segtree{
    int sz;
    vector<int> arr;
    void init(int n){
        sz=1;
        while(sz<n) sz*=2;
        arr.resize(2*sz,0);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            arr[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if( m > i ){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        //operation here
        arr[x]=arr[2*x+1]+arr[2*x+2];
    }
    void set(int i,int v){
        set(i,v,0,0,sz);
    }
    int op(int l,int r,int x,int lx,int rx){
        if(lx>=r || l>=rx) return 0;
        else if(lx>=l && rx<=r) return arr[x];
        int m=(lx+rx)/2;
        //operation here
        return op(l,r,2*x+1,lx,m)+op(l,r,2*x+2,m,rx);
    }
    int op(int l,int r){
        return op(l,r+1,0,0,sz);
    }
};
 
class funcs{
    public:
    	int power(int x, int y) {
            int res = 1;
            x = x % mod;
            while (y > 0) {
                if (y & 1)
                    res = (res * x) % mod;
                y = y >> 1;
                x = (x * x) % mod;
            }
            return res;
        }
        
        int modInverse(int n) {
            return power(n, mod - 2);
        }
        
        vector<int> fac;
        
        void calc() {
            fac.resize(N + 1);
            fac[0] = 1;
            for (int i = 1; i <= N; i++) {
                fac[i] = (fac[i - 1] * i) % mod;
            }
        }
        
        int nCr(int n, int r) {
            if (r > n) return 0;
            int numerator = fac[n];
            int denominator = (fac[r] * fac[n - r]) % mod;
            return (numerator * modInverse(denominator)) % mod;
        }

    	vector<int> z_function(string s) {
         	int n = s.size();
            vector<int> z(n);
            int l = 0, r = 0;
            for(int i = 1; i < n; i++) {
                if(i < r) {
                    z[i] = min(r - i, z[i - l]);
                }
                while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    z[i]++;
                }
                if(i + z[i] > r) {
                    l = i;
                    r = i + z[i];
                }
            }
            return z;
        }//returns a vector which tells the length of substring of s starting from i that matches the prefix of s
        
        void compress(vector<vector<int>>& v){
            int n=v.size();
            set<int> myset;
            map<int,int> mymap;
            for(int i=0;i<n;i++){
                myset.insert(v[i][0]);
                myset.insert(v[i][1]);
            }
            int cnt=1;
            for(auto it:myset){
                mymap[it]=cnt;
                cnt++;
            }
            for(int i=0;i<n;i++){
                v[i][0]=mymap[v[i][0]];
                v[i][1]=mymap[v[i][1]];
            }
        }//compresses the coordinates of segments where v[i][0] and v[i][1] are segment coordinates inclusive

        void print(vector<int> v){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        
        void print(bool pos){
            if(pos) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
};

/*----------- START HERE (^_^) -----------*/
signed main() {
    FAST();
    funcs f;
    
    int tc;
    cin>>tc;
    while(tc--){
        int a,b;
        cin>>a>>b;
        if(a>=b){
            cout<<a<<endl;
        }
        else{
            cout<<max(0ll,a-(b-a))<<endl;
        }
    }
    return 0;
}