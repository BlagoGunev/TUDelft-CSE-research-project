#include <bits/stdc++.h>

using namespace std;

template<typename T>

int SIZE(T (&t)){

    return t.size();

}



template<typename T, size_t N>

int SIZE(T (&t)[N]){

    return N;

}



string to_string(char t){

    return "'" + string({t}) + "'";

}



string to_string(bool t){

    return t ? "true" : "false";

}



string to_string(const string &t, int x1=0, int x2=1e9){

    string ret = "";

    for(int i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){

        ret += t[i];

    }

    return '"' + ret + '"';

}



string to_string(const char* t){

    string ret(t);

    return to_string(ret);

}



template<size_t N>

string to_string(const bitset<N> &t, int x1=0, int x2=1e9){

    string ret = "";

    for(int i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){

        ret += t[i] + '0';

    }

    return to_string(ret);

}



template<typename T, typename... Coords>

string to_string(const T (&t), int x1=0, int x2=1e9, Coords... C);



template<typename T, typename S>

string to_string(const pair<T, S> &t){

    return "(" + to_string(t.first) + ", " + to_string(t.second) + ")";

}



template<typename T, typename... Coords>

string to_string(const T (&t), int x1, int x2, Coords... C){

    string ret = "[";

    x1 = min(x1, SIZE(t));

    auto e = begin(t);

    advance(e,x1);

    for(int i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){

        ret += to_string(*e, C...) + (i != _i ? ", " : "");

        e = next(e);

    }

    return ret + "]";

}



template<int Index, typename... Ts>

struct print_tuple{

    string operator() (const tuple<Ts...>& t) {

        string ret = print_tuple<Index - 1, Ts...>{}(t);

        ret += (Index ? ", " : "");

        return ret + to_string(get<Index>(t));

    }

};



template<typename... Ts>

struct print_tuple<0, Ts...> {

    string operator() (const tuple<Ts...>& t) {

        return to_string(get<0>(t));

    }

};



template<typename... Ts>

string to_string(const tuple<Ts...>& t) {

    const auto Size = tuple_size<tuple<Ts...>>::value;

    return print_tuple<Size - 1, Ts...>{}(t);

}



void dbgr(){;}

template<typename Heads, typename... Tails>

void dbgr(Heads H, Tails... T){

    cout << to_string(H) << " | ";

    dbgr(T...);

}



void dbgs(){;}

template<typename Heads, typename... Tails>

void dbgs(Heads H, Tails... T){

    cout << H << " ";

    dbgs(T...);

}



/*

formatted functions:

*/



/*

consider __VA_ARGS__ as a whole:

dbgv() prints values only

dbg() prints name and values

*/

#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;



#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);

//#define dbg(...)



/*

consider __VA_ARGS__ as a sequence of arguments:

dbgr() prints values only

dbgm() prints names and values

*/

#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;



#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);



struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        // http://xorshift.di.unimi.it/splitmix64.c

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }



    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

};



#define int long long

#define double long double

typedef unsigned int ui;

typedef unsigned long long ull;

typedef pair<int, int> pi;

const int mod=1000000007;

const int N=200001;

const int inf=1e18;

const double eps=1e-11;

string s;

int n, m, k;

vector<vector<int>> adj(N);

vector<int> parents(N), siz(N);

vector<bool> vis(N);

void dfs(int u, int parent) {

	parents[u]=parent;

	vis[u]=true, siz[u]=1;

	for (int v:adj[u]) {

		if (vis[v]) continue;

		dfs(v, u);

		siz[u]+=siz[v];

	}

}



void solve() {

    cin>>n;

    vector<int> out(n+1);

    for (int i=0; i<n; i++) {

    	adj[i].clear();

    	vis[i]=false;	

    }

    

    for (int i=0; i<n-1; i++) {

    	int u, v;

    	cin>>u>>v;

    	adj[u].push_back(v);

    	adj[v].push_back(u);

    }

    

    dfs(0, -1);

    for (int i=0; i<n; i++) vis[i]=false;

    int l=0, r=0, mex=1;

    for (int i=1; i<n; i++) {

    	int u=i;

    	bool ok=false;

    	if (vis[u]) {

    		mex++;

    		continue;	

    	}

    	

    	while (true) {

    		// dbg(u);

    		if (u==l || u==r) {

    			if (u==l) l=i;

    			else r=i;

    			ok=true;

    			break;	

    		}

    		

    		if (vis[u] || u==0) break;

    		vis[u]=true;

    		u=parents[u];

    	}

    	

    	// dbg(vis);

    	if (!ok) break;

    	mex++;

    }

    

    int lpath=l, rpath=r;

    while (parents[lpath]>0) lpath=parents[lpath];

    while (parents[rpath]>0) rpath=parents[rpath];

    int prev=0;

    // dbg(parents);

    // dbg(siz);

    // dbg(lpath);

    // dbg(rpath);

    while (l>0 || r>0) {

    	if (l>r) {

    		swap(l, r);

    		swap(lpath, rpath);

    	}

    	

    	int lsiz=siz[l], rsiz=siz[r];

	    // dbg(l);

	    // dbg(r);

	    // dbg(lsiz);

	    // dbg(rsiz);

    	if (l==0) lsiz=n-siz[rpath];

    	out[mex]=lsiz*rsiz-prev;

    	// dbg(out[mex]);

    	// dbg(prev);

    	// dbg(mex);

    	prev+=out[mex];

    	int u=r;

    	while (u>=r) u=parents[u];

    	mex=r, r=u;

    }

    

    out[1]=n*(n-1)/2;

    for (int u:adj[0]) {

    	out[1]-=siz[u]*(siz[u]-1)/2;

    }

    

    out[1]-=prev;

    prev+=out[1];

    out[0]=n*(n-1)/2-prev;

    for (int num:out) cout<<num<<" ";

    cout<<"\n";

}



int32_t main() {

    std::ios::sync_with_stdio(false);

    cin.tie(NULL);

    int t;

    cin>>t;

    while (t--) {

        solve();

    }

}