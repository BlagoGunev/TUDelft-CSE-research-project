#include <bits/stdc++.h> 
using namespace std; 

#define ffor(i, a, b) for (int i = a ; i <= (int) b ; i++) 
#define rfor(i, a, b) for (int i = (int) a ; i >= b ; i--)  

#define vec vector 
#define PB push_back 

#define MP make_pair 
#define MT make_tuple 
#define F first 
#define S second 

using ll = long long int; // watch out for overflows in your code
using pii = pair<int,int>;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void debug() { cout << "\n"; };
template <typename T, typename... Targs> 
void debug(T t, Targs... args) {
    cout << t << " ";
    debug(args...);
}

template <typename T1, typename T2> 
inline ostream& operator << (ostream& os, const pair<T1,T2>& p) {
    return os << "(" << p.F << ", " << p.S << ")";
}

template <typename T> 
inline ostream& operator << (ostream& os, const vec<T>& v) {
    for(auto& t : v) {
        os << t << " ";
    }
    return os;
}

template <typename T> 
inline ostream& operator << (ostream& os, const vec<vec<T>>& m) {
    for(auto& v : m) {
        for(auto& t : v) {
            os << t << " ";
        }
        os << "\n";
    }
    return os;
}

template <typename T> 
inline ostream& operator << (ostream& os, const set<T>& v) {
    for(auto& t : v) {
        os << t << " ";
    }
    return os;
}

template <typename K, typename V> 
inline ostream& operator << (ostream& os, const map<K,V>& m) {
    for(auto& p : m) {
        os << p.F << " -> " << p.S << "\n";
    }
    return os;
}

////////////////////////////////////////////////////////////////////////

template<typename T>
void consume_vector(vec<T>& I, int lo, int hi) {
    I.assign(hi+2, T());
    ffor(i, lo, hi) {
        cin >> I[i];
    }
}

void consume_adj_list(vec<vec<int>>& G, int V, int E, bool bidirectional=true) {
    G.assign(V+1, vec<int>());
    ffor(i, 1, E) {
        int u, v; cin >> u >> v;
        G[u].PB(v);
        if(bidirectional) {
            G[v].PB(u);
        }
    }
}

////////////////////////////////////////////////////////////////////////

int N;
vec<int> C;

void setup_data() {
    cin >> N;
    C.clear();
    ffor(i,1,N) {
        int c; cin >> c;
        C.PB(c);
    }
}

////////////////////////////////////////////////////////////////////////

bool solve() {
    int i = -1;
    rfor(j, N-1, 0) {
        if(C[j] == 1) {
            i = j;
        }
    }
    if(i == -1) {
        return false;
    }

    int j = (i+1) % N;
    int prv = 1;
    ffor(k, 1, N-1) {
        if(C[j] < 2 || C[j] > prv+1) {
            return false;
        }
        prv = C[j];
        j = (j+1) % N;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    // int T = 1;
    while(T--) {
        setup_data();
        auto ans = solve();
        debug(ans ? "YES" : "NO");
    }
}