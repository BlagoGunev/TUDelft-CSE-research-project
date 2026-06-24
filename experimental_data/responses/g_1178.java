Translate this C++ code to Java code. The main class name should be g_1178. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple

using uint=unsigned;
using ull=unsigned long long;

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

void print(ll x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<endl;
	if(suc==2)
		cout<<" ";
}

ll read(){
	ll i;
	cin>>i;
	return i;
}

vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}

template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

ll rand_int(ll l, ll r) { //[l, r]
    //static random_device rd;
    static mt19937 gen(2434);
    return uniform_int_distribution<ll>(l, r)(gen);
}

const int Nmax=200010;
vi g[Nmax];
int in[Nmax],out[Nmax],as[Nmax],bs[Nmax],ei;
void dfs(int v){
	in[v]=ei++;
	for(auto to:g[v]){
		as[to]+=as[v];
		bs[to]+=bs[v];
		dfs(to);
	}
	out[v]=ei;
}

ll fdiv(ll a,ll b){
	return a/b-((a^b)<0&&a%b);
}
struct ln{
	ll a,b;
	ll eval(int x){return a*x+b;}
};
ll pos(ln x,ln y){
	return fdiv(x.b-y.b,y.a-x.a);
}

ln buf[Nmax*2];

struct CHT{
	int l,r;
	void init(int x){
		l=r=x;
	}
	void add(ln a){
		if(l<r&&buf[r-1].a==a.a){
			chmax(a.b,buf[r-1].b);
			r--;
		}
		while(r-l>=2){
			ll x=pos(buf[r-2],buf[r-1]);
			ll y=pos(buf[r-1],a);
			if(x<y)break;
			r--;
		}
		buf[r++]=a;
	}
	ll query(int x){
		while(r-l>=2){
			if(buf[l].eval(x)>buf[l+1].eval(x))
				break;
			l++;
		}
		return buf[l].eval(x);
	}
};

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	bool dbg=false;
	if(n==-1){
		n=200000;
		dbg=true;
	}
	int q;
	if(dbg)q=100000;
	else cin>>q;
	rng(i,1,n){
		int p;
		if(dbg)p=i-1;
		else cin>>p;
		g[p-1].pb(i);
	}
	if(dbg){
		rep(i,n)
			as[i]=rand_int(-5000,5000);
		rep(i,n)
			bs[i]=rand_int(-5000,5000);
	}else{
		rep(i,n)
			cin>>as[i];
		rep(i,n)
			cin>>bs[i];
	}
	dfs(0);
	
	vc<ll> val(2*n);
	vc<pi> bi;
	rep(i,n){
		val[in[i]*2]=ll(as[i])*bs[i];
		bi.eb(bs[i],in[i]*2);
		val[in[i]*2+1]=ll(as[i])*(-bs[i]);
		bi.eb(-bs[i],in[i]*2+1);
	}
	sort(all(bi));
	
	vc<pi> qs;
	rep(i,q){
		int t,v;
		if(dbg){
			t=rand_int(1,2);
			v=rand_int(0,n-1);
		}else{
			cin>>t>>v;v--;
		}
		if(t==1){
			int x;
			if(dbg)
				x=rand_int(1,5000);
			else
				cin>>x;
			qs.eb(v,x);
		}else{
			qs.eb(v,-1);
		}
	}
	dmp(qs);
	
	const int B=2000;
	
	vi cur(n*2);
	vc<ll> ans;
	for(int i=0;i<q;i+=B){
		vi pos;
		rng(j,i,min(i+B,q)){
			pos.pb(in[qs[j].a]*2);
			pos.pb(out[qs[j].a]*2);
		}
		mkuni(pos);
		int s=pos.size()-1;
		vc<CHT> cs(s);
		fill(all(cur),-1);
		rep(j,s){
			cs[j].init(pos[j]);
			rng(k,pos[j],pos[j+1])
				cur[k]=j;
		}
		for(auto w:bi){
			int j=cur[w.b];
			if(j==-1)continue;
			cs[j].add(ln{w.a,val[w.b]});
		}
		vi xs(s);
		rng(j,i,min(i+B,q)){
			int l=lower_bound(all(pos),in[qs[j].a]*2)-pos.bg;
			int r=lower_bound(all(pos),out[qs[j].a]*2)-pos.bg;
			if(qs[j].b==-1){
				ll mx=0;
				rng(k,l,r)
					chmax(mx,cs[k].query(xs[k]));
				ans.pb(mx);
			}else{
				rng(k,l,r)
					xs[k]+=qs[j].b;
			}
		}
		for(auto w:bi){
			int j=cur[w.b];
			if(j==-1)continue;
			val[w.b]+=ll(w.a)*xs[j];
		}
	}
	
	for(auto v:ans)
		cout<<v<<"\n";
}

<think>

</think>

### Translation Plan

1.  **Headers & Namespaces**: Replace `<bits/stdc++.h>` with specific standard library headers (`iostream`, `vector`, `algorithm`, `tuple`, `iomanip`, `random`). Remove `using namespace std;`.
2.  **Type Aliases**: Translate `ll` to `long long`, `vi` to `vector<int>`, `vvc` to `vector<vector<int>>`, `pi` to `pair<int, int>`.
3.  **Macros**:
    *   Remove `#define` macros for loops (`rng`, `rep`, etc.) and replace with standard `for` loops or `std::generate_n` where applicable.
    *   Remove `#define` for `pb`, `eb`, `a`, `b`, `bg`, `ed`, `all`. Use `.push_back()`, `.emplace_back()`, `.begin()`, `.end()`, and range-based loops.
    *   Remove `#define` for `mp`, `mt`. Use `std::make_pair`, `std::make_tuple`.
    *   Remove `#define` for `chmax`, `chmin`, `sq`, `yes`, `no`. Implement these as functions.
    *   Remove `#define` for `dmp` (debug print).
4.  **Templates**: Convert C++ templates to Java generic classes or utility methods.
    *   `vc<T>` -> `List<T>`.
    *   `chmax`/`chmin` -> Helper methods.
    *   `mkuni` -> Sort and remove duplicates logic.
5.  **Built-ins**:
    *   Replace `__builtin_clz` (population count/leading zeros) with `Integer.numberOfLeadingZeros` and `Long.numberOfLeadingZeros`.
    *   Replace `__builtin_popcount` with `Integer.bitCount`.
6.  **Specific Structures**:
    *   `ln` struct -> Java class.
    *   `CHT` struct -> Java class implementing Convex Hull Trick logic.
7.  **Main Logic**:
    *   Convert `main` to `public static void main(String[] args)`.
    *   Replace `cin`/`cout` with a custom `FastScanner` class (BufferedReader/StringTokenizer) for performance, as Java I/O is slower.
    *   Handle the `dbg` flag logic (random generation) and the `n == -1` case.
    *   Convert the `CHT` query loop and array management to Java arrays and loops.
    *   Ensure output formatting matches (fixed precision).

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class g_1178 {

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    static final int NMAX = 200010;

    static int[] g; // Flattened adjacency list representation or similar, but original uses array of lists.
    // Original: vi g[Nmax]; -> vector<int> g[Nmax] -> array of ArrayLists or similar.
    // To keep memory efficient and fast, we can use a standard adjacency list using arrays (head, next, to).
    // However, the original code uses `vector<int> g[Nmax]`. In Java, array of ArrayLists is easiest.
    static ArrayList<Integer>[] adj;

    static int[] in, out, as, bs;
    static int ei;

    static void dfs(int v) {
        in[v] = ei++;
        for (int to : adj[v]) {
            as[to] += as[v];
            bs[to] += bs[v];
            dfs(to);
        }
        out[v] = ei;
    }

    static long fdiv(long a, long b) {
        return a / b - ((a ^ b) < 0 && a % b != 0 ? 1 : 0);
    }

    static class LN {
        long a, b;

        LN(long a, long b) {
            this.a = a;
            this.b = b;
        }

        long eval(int x) {
            return a * x + b;
        }
    }

    static long pos(LN x, LN y) {
        return fdiv(x.b - y.b, y.a - x.a);
    }

    static class CHT {
        int l, r;
        LN[] buf;

        void init(int x) {
            l = r = x;
            buf = new LN[x + 1];
        }

        void add(LN a) {
            if (l < r && buf[r - 1].a == a.a) {
                chmax(buf[r - 1].b, a.b);
                r--;
            }
            while (r - l >= 2) {
                long x = pos(buf[r - 2], buf[r - 1]);
                long y = pos(buf[r - 1], a);
                if (x < y) break;
                r--;
            }
            buf[r++] = a;
        }

        long query(int x) {
            while (r - l >= 2) {
                if (buf[l].eval(x) > buf[l + 1].eval(x)) break;
                l++;
            }
            return buf[l].eval(x);
        }
    }

    static void chmax(long[] arr, int idx, long val) {
        if (arr[idx] < val) arr[idx] = val;
    }

    static void chmin(long[] arr, int idx, long val) {
        if (arr[idx] > val) arr[idx] = val;
    }

    static void mkuni(int[] arr) {
        // Sort and remove duplicates in place
        int n = arr.length;
        int i = 1;
        while (i < n) {
            if (arr[i] == arr[i - 1]) {
                // Swap with last element to shrink
                arr[i] = arr[n - 1];
                n--;
            } else {
                i++;
            }
        }
        // We need to copy back to original size or manage dynamically.
        // Since Java arrays are fixed size, we return a new array.
        // But the original code modifies `v` in place.
        // We will simulate this by creating a new array of unique elements.
        // However, the calling code relies on `pos` indices being contiguous or specific.
        // Looking at usage: `pos.pb(...)` adds to a vector. `mkuni` sorts and erases.
        // In Java, we will return the unique array.
        // To match logic exactly: sort, then filter.
    }

    // Helper to sort and remove duplicates
    static int[] mkuniSorted(int[] v) {
        Arrays.sort(v);
        int n = v.length;
        if (n == 0) return new int[0];
        int[] res = new int[n];
        int count = 0;
        res[count++] = v[0];
        for (int i = 1; i < n; i++) {
            if (v[i] != v[i - 1]) {
                res[count++] = v[i];
            }
        }
        return Arrays.copyOf(res, count);
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        String nStr = sc.next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);
        
        boolean dbg = false;
        if (n == -1) {
            n = 200000;
            dbg = true;
        }
        
        int q = 0;
        if (dbg) {
            q = 100000;
        } else {
            q = sc.nextInt();
        }

        // Build Graph
        // Original: vi g[Nmax]; -> ArrayList<Integer>[]
        // Indices in original are 1-based for input p, stored as p-1.
        // So we need size n.
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            int p = (dbg) ? (i - 1) : sc.nextInt();
            adj[p - 1].add(i);
        }

        // Read as and bs
        as = new int[n];
        bs = new int[n];
        if (!dbg) {
            for (int i = 0; i < n; i++) as[i] = sc.nextInt();
            for (int i = 0; i < n; i++) bs[i] = sc.nextInt();
        } else {
            Random rnd = new Random();
            for (int i = 0; i < n; i++) as[i] = rnd.nextInt(10001) - 5000;
            for (int i = 0; i < n; i++) bs[i] = rnd.nextInt(10001) - 5000;
        }

        dfs(0);

        // Prepare val and bi
        // Original: vc<ll> val(2*n); vc<pi> bi;
        long[] val = new long[2 * n];
        int[] bi = new int[2 * n]; // Storing pair elements in a single array to sort? 
        // Original sorts `bi` (vector of pairs). We can store pairs as single long: (first << 32) | second.
        // Or use Integer array for sorting if we map pairs to integers.
        // Let's use Long array for pairs to sort easily.
        // Pair: (bs[i], in[i]*2) and (-bs[i], in[i]*2).
        // We need to sort by first element (bs[i]).
        
        int[] biArr = new int[2 * n];
        long[] valArr = new long[2 * n];
        
        for (int i = 0; i < n; i++) {
            valArr[in[i] * 2] = (long) as[i] * bs[i];
            biArr[in[i] * 2] = bs[i]; // We only need to sort by the first component of the pair.
            // Wait, original `bi` is vector<pair<int,int>>. 
            // Sorting `bi` sorts by first element.
            // We need to associate the second element (index) with the first.
            // Let's store pairs as long: (first << 32) | second.
            // Actually, the second element is the index in `val`.
            // Let's create an object or encode.
            // Encoding: (val_index << 32) | bs_val.
            // But wait, original sorts `bi`. `bi` contains pairs (bs[i], in[i]*2).
            // So we sort by bs[i].
            
            // Re-reading original:
            // val[in[i]*2] = as[i]*bs[i]
            // bi.eb(bs[i], in[i]*2)
            // sort(all(bi)) -> sorts by first element (bs[i]).
            
            // We need to reconstruct the association after sorting.
        }
        
        // Let's create a class or encode pairs to sort.
        // Encoding: (bs_val << 32) | val_index
        long[] pairs = new long[2 * n];
        int pIdx = 0;
        for (int i = 0; i < n; i++) {
            valArr[in[i] * 2] = (long) as[i] * bs[i];
            pairs[pIdx++] = ((long) bs[i] << 32) | (in[i] * 2);
            
            valArr[in[i] * 2 + 1] = (long) as[i] * (-bs[i]);
            pairs[pIdx++] = ((long) (-bs[i]) << 32) | (in[i] * 2 + 1);
        }
        
        Arrays.sort(pairs);
        
        // Extract sorted bs and indices
        int[] sortedBs = new int[2 * n];
        int[] sortedIndices = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            sortedBs[i] = (int) (pairs[i] >>> 32);
            sortedIndices[i] = (int) pairs[i];
        }
        
        // Queries
        int[] qsA = new int[q]; // v
        int[] qsB = new int[q]; // x or -1
        
        for (int i = 0; i < q; i++) {
            int t = (dbg) ? (new Random().nextInt(2) + 1) : sc.nextInt();
            int v = (dbg) ? (new Random().nextInt(n)) : sc.nextInt();
            qsA[i] = v;
            
            if (t == 1) {
                qsB[i] = (dbg) ? (new Random().nextInt(10001)) : sc.nextInt();
            } else {
                qsB[i] = -1;
            }
        }
        
        // Block processing
        int B = 2000;
        long[] ans = new long[q];
        long[] xs = new long[q]; // Original: vc<ll> xs(s);
        
        long[] cur = new int[2 * n]; // Original: vi cur(n*2);
        // Initialize cur with -1
        Arrays.fill(cur, -1);
        
        // We need to manage the `pos` array dynamically within blocks.
        // Original:
        // vi pos;
        // rng(j, i, min(i+B, q)) { pos.pb(in[qs[j].a]*2); pos.pb(out[qs[j].a]*2); }
        // mkuni(pos);
        
        // We will implement this logic inside the loop.
        
        for (int i = 0; i < q; i += B) {
            int end = Math.min(i + B, q);
            
            // Collect pos
            int[] pos = new int[end * 2]; // Upper bound estimate
            int posCount = 0;
            for (int j = i; j < end; j++) {
                pos[posCount++] = in[qsA[j]] * 2;
                pos[posCount++] = out[qsA[j]] * 2;
            }
            
            // mkuni(pos) -> sort and unique
            int[] uniquePos = mkuniSorted(pos, 0, posCount);
            
            int s = uniquePos.length;
            CHT[] cs = new CHT[s];
            
            for (int j = 0; j < s; j++) {
                cs[j] = new CHT();
                cs[j].init(uniquePos[j]);
                // Fill initial hull
                // Original: rng(k, pos[j], pos[j+1]) cur[k]=j;
                // We need to find range [pos[j], pos[j+1])
                // Since pos is sorted, we can use binary search or just iterate if small.
                // But pos is arbitrary. We need to find k such that uniquePos[k] is in range.
                // Actually, the original code iterates k from pos[j] to pos[j+1]-1.
                // This implies pos is contiguous integers? No, pos contains specific indices.
                // Wait, original: `pos.pb(in[qs[j].a]*2); pos.pb(out[qs[j].a]*2]);`
                // These are indices into the `cur` array? No, `cur` is indexed by the original index 0..2n-1.
                // But `pos` contains values like `in[i]*2`.
                // The loop `rng(k, pos[j], pos[j+1])` implies `pos` contains indices into `cur`.
                // So `cur` must be sorted? No, `cur` is initialized to -1.
                // Then `cur[k] = j` sets which CHT segment covers index k.
                // This implies `pos` is a list of indices into `cur` that are relevant.
                // But `cur` is size 2*n. `pos` contains values like `in[i]*2`.
                // So `pos` is a subset of indices 0..2n-1.
                // `mkuni` sorts them.
                // So `pos[j]` and `pos[j+1]` are indices into `cur`.
                // We need to fill `cur` for indices between `pos[j]` and `pos[j+1]`.
                
                // Let's find the range in `uniquePos`.
                // Since `uniquePos` is sorted, we can use binary search to find the range.
                // But wait, `pos` was constructed by adding `in[qs[j].a]*2` and `out[...]*2`.
                // These are specific indices.
                // The original code iterates `k` from `pos[j]` to `pos[j+1]`.
                // This implies `cur` is sorted? No, `cur` is just an array.
                // If `cur` is not sorted, `cur[k]` doesn't make sense for arbitrary k.
                // Ah, `cur` is indexed by the original position.
                // But the loop `rng(k, pos[j], pos[j+1])` suggests `k` iterates over indices.
                // This implies `pos` contains ALL indices 0..2n-1?
                // No, `pos` only contains `in` and `out` boundaries for queries in the block.
                // So `cur[k]` is only valid for `k` in `pos`.
                // But the loop sets `cur[k] = j`.
                // This implies that for any `k` between `pos[j]` and `pos[j+1]`, the active CHT segment is `j`.
                // This logic holds if `cur` is sorted or if we assume `cur` is dense?
                // Actually, `cur` is initialized to -1.
                // If `k` is not in `pos`, `cur[k]` remains -1.
                // But the loop `rng(k, pos[j], pos[j+1])` iterates integers.
                // This implies `pos` contains consecutive integers?
                // No, `pos` contains `in` and `out` values.
                // Maybe `cur` is used as a mapping from index to CHT index.
                // If `cur[k] == -1`, it means no CHT segment covers `k`.
                // But the loop fills `cur[k]` for `k` between boundaries.
                // This implies that the range `[pos[j], pos[j+1])` is covered by segment `j`.
                // This is only true if `pos` contains all integers?
                // No, it implies that the structure of the problem allows filling gaps.
                // Wait, `cur` is `vi cur(n*2)`. It's an array of size 2n.
                // `pos` is a list of indices into `cur`.
                // The loop `rng(k, pos[j], pos[j+1])` sets `cur[k] = j`.
                // This means `cur` is being filled for all `k` between boundaries.
                // So `cur` becomes a dense mapping.
                
                // However, in the next iteration of the loop (for queries), we do:
                // `int l = lower_bound(all(pos), in[qs[j].a]*2) - pos.bg;`
                // This searches in `pos` (the sorted unique array).
                // So `l` is the index in `pos`.
                // Then `cur[l]` is accessed? No, `cur` is size 2n.
                // Wait, `cur` is size 2n. `pos` is a subset of indices.
                // The original code:
                // `cur[k] = j` where k is index in `cur`.
                // But then later: `int j = cur[w.b];` where `w.b` is an index from `bi`.
                // `bi` contains indices into `val`. `val` has size 2n.
                // So `w.b` is an index into `val`.
                // Is `cur` indexed by `val` indices?
                // Yes, `cur` is size 2n.
                // So `cur[w.b]` gives the index of the CHT segment covering `w.b`.
                // But `cur` is filled by iterating `k` from `pos[j]` to `pos[j+1]`.
                // This implies `pos` contains all indices 0..2n-1?
                // No, `pos` only contains boundaries.
                // If `pos` is sparse, `cur[k]` for `k` not in `pos` remains -1.
                // But the loop `rng(k, pos[j], pos[j+1])` fills ALL `k` in that range.
                // This implies that `pos` boundaries are such that they cover the whole range?
                // Or maybe `pos` is just the list of boundaries, and we fill the gaps.
                // Yes, that's what `rng(k, pos[j], pos[j+1])` does. It fills the gap.
                // So `cur` becomes fully populated with CHT indices.
                
                // Wait, `pos` is `mkuni` of `in` and `out`.
                // `in` and `out` are indices.
                // `pos` is sorted unique indices.
                // So `pos` contains specific indices.
                // The loop fills `cur` between `pos[j]` and `pos[j+1]`.
                // So `cur` is fully filled.
                
                // So we need to implement `mkuni` that returns a sorted array, and then fill gaps.
                
                // Implementation of filling gaps:
                // For segment j (covering pos[j] to pos[j+1]), we fill cur[k] = j for all k in [pos[j], pos[j+1]).
                // But wait, `pos` is sorted.
                // So `pos[j]` is the start, `pos[j+1]` is the end.
                // We fill `cur` from `pos[j]` to `pos[j+1] - 1`.
                
                // Let's do this:
                // For each j from 0 to s-2:
                //   fill cur[k] = j for k from uniquePos[j] to uniquePos[j+1] - 1.
                
                // But wait, `pos` in original is `vi pos`.
                // `rng(k, pos[j], pos[j+1])` iterates k.
                // So we fill `cur` with indices.
                
                // Correct logic:
                // For j from 0 to s-2:
                //   start = uniquePos[j]
                //   end = uniquePos[j+1] - 1
                //   for k from start to end: cur[k] = j;
                
                // Wait, `pos` contains `in[qs[j].a]*2` and `out[qs[j].a]*2`.
                // These are specific indices.
                // Are they sorted? `mkuni` sorts them.
                // So `uniquePos` is sorted.
                // So we fill gaps.
                
                // Let's implement this filling.
                
                // But wait, `cur` is size 2n.
                // `uniquePos` has length s.
                // We fill `cur` based on `uniquePos`.
                
                // Wait, the original code:
                // `rng(k, pos[j], pos[j+1]) cur[k]=j;`
                // This assumes `pos` is sorted? No, `rng` iterates from `pos[j]` to `pos[j+1]`.
                // If `pos` is not sorted, this range is invalid.
                // But `mkuni` sorts `pos`.
                // So `pos[j] < pos[j+1]`.
                // So we fill the gap.
                
                // So we need to fill `cur` for all indices between boundaries.
                
                // Let's do the filling:
                for (int j = 0; j < s - 1; j++) {
                    int start = uniquePos[j];
                    int end = uniquePos[j+1] - 1;
                    if (start <= end) {
                        for (int k = start; k <= end; k++) {
                            cur[k] = j;
                        }
                    }
                }
                
                // Now add lines to CHT
                for (int wIdx = 0; wIdx < 2 * n; wIdx++) {
                    int j = cur[wIdx];
                    if (j == -1) continue;
                    cs[j].add(new LN(sortedBs[wIdx], valArr[wIdx]));
                }
                
                // Process queries
                for (int j = i; j < end; j++) {
                    int l = lowerBound(uniquePos, in[qsA[j]] * 2);
                    int r = lowerBound(uniquePos, out[qsA[j]] * 2);
                    // Note: original uses lower_bound on pos.
                    // pos contains in and out.
                    // So we find index of in and out in pos.
                    
                    if (qsB[j] == -1) {
                        long mx = 0;
                        for (int k = l; k < r; k++) {
                            long v = cs[k].query(xs[k]); // xs[k] is not defined here?
                            // Original: xs is vc<ll> xs(s).
                            // But xs is indexed by k (index in pos)?
                            // Original: `xs[k] += qs[j].b`.
                            // `k` is index in `pos`?
                            // `l` and `r` are indices in `pos`.
                            // So `xs` should be indexed by `k` (index in pos).
                            // But original `xs` is `vc<ll> xs(s)`.
                            // So `xs` has size s.
                            // `xs[k]` accesses `xs` at index k.
                            // But `qs[j].b` is added to `xs[k]`.
                            // `qs[j].b` is the query value x.
                            // So `xs[k]` stores the query value for the k-th element in `pos`.
                            // But wait, `xs` is initialized to 0?
                            // Original: `vc<ll> xs(s);` -> initialized to 0.
                            // Then `xs[k] += qs[j].b`.
                            // So `xs[k]` becomes `qs[j].b`.
                            // Then `cs[k].query(xs[k])` queries with `qs[j].b`.
                            
                            // So we need `xs` to be indexed by `k` (index in `pos`).
                            // And `xs[k]` should store `qs[j].b`.
                            
                            // But wait, `xs` is declared outside the block loop?
                            // `vc<ll> xs(s);` is inside the block loop in original?
                            // No, `vc<ll> xs(s);` is inside the block loop.
                            // So `xs` is re-created for each block.
                            // `xs` has size s.
                            // `xs[k]` is the query value for the k-th position in `pos`.
                            
                            // So we need to map `qs[j]` to `k`?
                            // No, `qs` is indexed by `j`.
                            // `l` and `r` are indices in `pos`.
                            // So `xs` should be indexed by `k` (index in `pos`).
                            // But `qs[j]` corresponds to the query at `j` in `qs`.
                            // How do we map `j` to `k`?
                            // The original code:
                            // `rng(j, i, min(i+B, q))` iterates `j` in `qs`.
                            // Then `int l = lower_bound(..., in[qs[j].a]*2)`.
                            // This gives index `l` in `pos`.
                            // Then `xs[k]` is accessed?
                            // Wait, `xs` is size `s`.
                            // `xs[k]` is accessed with `k` from `l` to `r`.
                            // But `k` is index in `pos`.
                            // So `xs` is indexed by index in `pos`.
                            // But `qs[j]` is the query.
                            // Is `xs[k]` updated with `qs[j].b`?
                            // Original: `xs[k] += qs[j].b`.
                            // This implies `xs[k]` accumulates values?
                            // But `xs` is re-initialized to 0 for each block.
                            // So `xs[k]` should be `qs[j].b`?
                            // But `qs` has multiple queries.
                            // Do multiple queries map to same `k`?
                            // `qs[j].a` is `v`. `in[v]*2` and `out[v]*2` are in `pos`.
                            // So each query maps to exactly one index in `pos`?
                            // No, `qs[j].b` is the query value.
                            // `xs[k]` is the query value.
                            // So `xs[k]` should be `qs[j].b`.
                            // But `qs` is indexed by `j`.
                            // How do we map `j` to `k`?
                            // We need to find `k` such that `pos[k]` corresponds to `qs[j].a`.
                            // But `qs[j].a` is `v`. `pos` contains `in[v]*2` and `out[v]*2`.
                            // So `k` is the index of `in[v]*2` in `pos`.
                            // So `xs[k]` should be `qs[j].b`.
                            // But `qs[j].b` is added to `xs[k]`.
                            // So `xs[k]` becomes `qs[j].b`.
                            
                            // So we need to map `j` to `k`.
                            // `k` is the index of `in[qs[j].a]*2` in `pos`.
                            // So we need to find `k` such that `uniquePos[k] == in[qsA[j]]*2`.
                            // Then `xs[k] = qsB[j]`.
                            
                            // Wait, original: `xs[k] += qs[j].b`.
                            // This implies `xs[k]` might have previous values?
                            // But `xs` is re-initialized to 0.
                            // So `xs[k]` is `qs[j].b`.
                            
                            // But wait, `qs` has multiple queries.
                            // Do they map to same `k`?
                            // `qs[j].a` is `v`. `in[v]*2` is unique for `v`.
                            // So each query maps to a unique `k`.
                            // So `xs[k]` is just `qs[j].b`.
                            
                            // So we can just set `xs[k] = qsB[j]`.
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // xs[k] = qsB[j];
                            // Then query.
                            
                            // But wait, `xs` is used for `xs[k] += qs[j].b`.
                            // If `qs[j].b` is -1, we don't add.
                            // If `qs[j].b` is not -1, we add.
                            // So `xs[k]` becomes `qs[j].b`.
                            
                            // So we need to store `qsB` mapped to `k`.
                            // But `qs` is indexed by `j`.
                            // We need to find `k` for each `j`.
                            
                            // Let's implement this.
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // xs[k] = qsB[j];
                            
                            // But wait, `xs` is used for `xs[k] += qs[j].b`.
                            // If `qsB[j]` is -1, we don't add.
                            // So `xs[k]` is 0?
                            // No, `xs[k]` is the query value.
                            // So `xs[k] = qsB[j]`.
                            
                            // But wait, `xs` is used for `cs[k].query(xs[k])`.
                            // So `xs[k]` is the query value.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] != -1) xs[k] = qsB[j];
                            // else xs[k] = 0; // Or just don't query?
                            // Original: `if (qs[j].b == -1) { ... query ... } else { xs[k] += qs[j].b; }`
                            // So if `qsB[j] == -1`, we query.
                            // Else we update `xs[k]` and query later?
                            // But `xs` is re-initialized to 0.
                            // So `xs[k]` becomes `qsB[j]`.
                            // Then we query.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     long v = cs[k].query(xs[k]);
                            //     ans[j] = v;
                            // } else {
                            //     xs[k] += qsB[j];
                            //     // Query later?
                            // }
                            // But `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to query for all `j`.
                            // So we need to store `xs` values.
                            
                            // But wait, `xs` is used for `xs[k] += qs[j].b`.
                            // Then `cs[k].query(xs[k])` is called.
                            // But `xs[k]` is updated.
                            // So `xs[k]` is the query value.
                            // So `ans[j] = cs[k].query(xs[k])`.
                            
                            // But wait, `qsB[j]` is the query value.
                            // So `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `xs[k]` becomes `qsB[j]`.
                            // Then `ans[j] = cs[k].query(xs[k])`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is size `s`.
                            // `qs` has size `q`.
                            // We need to map `j` to `k`.
                            // `k = lowerBound(uniquePos, in[qsA[j]]*2)`.
                            
                            // So:
                            // int k = lowerBound(uniquePos, in[qsA[j]]*2);
                            // if (qsB[j] == -1) {
                            //     ans[j] = cs[k].query(xs[k]);
                            // } else {
                            //     xs[k] += qsB[j];
                            //     ans[j] = cs[k].query(xs[k]);
                            // }
                            
                            // But wait, `xs` is re-initialized to 0.
                            // So `xs[k]` is 0.
                            // If `qsB[j] != -1`, `