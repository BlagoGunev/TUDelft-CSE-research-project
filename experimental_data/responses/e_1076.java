Translate this C++ code to Java code. The main class name should be e_1076. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define maxn (400000+5)
#define mod (1000000007)
#define ll long long
#define inf 1000000000
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
#define pa pair<int,int>
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
inline ll readll()
{
	ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long power(long long x,long long y)
{
	long long t=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1)t=t*x%mod;
	return t;
}
struct edge
{
	int go,next;
}e[2*maxn];
vector<pa>G[maxn];
ll s[maxn],ans[maxn];
int n,m,tot,head[maxn],dep[maxn];
void insert(int x,int y)
{
	e[++tot]=(edge){y,head[x]};head[x]=tot;
	e[++tot]=(edge){x,head[y]};head[y]=tot;
}
ll query(int x)
{
	ll ret=0;
	while(x)
	{
		ret+=s[x];
		x-=x&(-x);
	}
	return ret;
}
void add(int x,int y)
{
	for(;x<=n;x+=x&(-x))s[x]+=y;
}
void dfs(int x,int fa)
{
	for(int i=0;i<G[x].size();i++)
	{
		int y=min(n,G[x][i].first+dep[x]),z=G[x][i].second;
		add(y,z);
	}
	ans[x]=query(n)-query(dep[x]-1);
	
	for4(i,x)if(y!=fa)
	{
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
	
	for(int i=0;i<G[x].size();i++)
	{
		int y=min(n,G[x][i].first+dep[x]),z=G[x][i].second;
		add(y,-z);
	}
}
int main()
{
	n=read();
	rep(i,1,n-1)insert(read(),read());
	m=read();
	rep(i,1,m)
	{
		int x=read(),y=read(),z=read();
		G[x].push_back(pa(y,z)); 
	}
	dep[1]=1;
	dfs(1,0);
//	rep(i,1,n)cout<<i<<' '<<dep[i]<<endl;
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}

### Translation Plan

1.  **Header Inclusion**: Replace `#include <bits/stdc++.h>` with specific standard library headers (`iostream`, `vector`, `algorithm`, `cstdio`).
2.  **Macros**:
    *   `rep` and `per` loops are translated to standard `for` loops.
    *   `for4` is a custom macro for adjacency list iteration (specific to C++ linked lists). It is translated to a standard `for` loop iterating over `vector` elements.
    *   `maxn`, `mod`, `ll`, `inf`, `pa` are converted to `const int`, `const long long`, etc.
    *   `upmo`, `mmo`, `upmin`, `upmax` are custom macros. The logic `((a)=((a)+(b))%mo)<0?(a)+=mo:(a))` is simplified to standard arithmetic operations since Java handles signed integers naturally.
3.  **Functions**:
    *   `is_down`, `is_upper`, `is_digit`: Simple boolean logic.
    *   `read`, `readll`: Custom integer reading functions using `getchar`. Translated to use `Scanner` or `BufferedReader` for efficiency. Given the constraints implied by the problem (likely CP), `BufferedReader` with `StringTokenizer` is preferred over `Scanner`.
    *   `gcd`: Translated to `BigInteger.gcd` or a custom iterative method. A custom iterative method is used for `long long`.
    *   `power`: Translated to modular exponentiation using `long long`.
4.  **Structures**:
    *   `edge`: Translated to a class `Edge` implementing a static inner class or just a simple struct-like class.
5.  **Arrays**:
    *   C++ arrays (`s`, `ans`, `head`, `dep`) are translated to `int[]` or `long long[]`.
    *   `G` (vector of pairs) is translated to `ArrayList<Edge>[]` or `ArrayList<Pair>[]`.
6.  **Logic**:
    *   `dfs`: Recursive function remains the same, but variable types change.
    *   `add` / `query`: Fenwick Tree (Binary Indexed Tree) logic remains the same, adapted for Java arrays (1-based indexing).
    *   `main`: Reading input, processing, and printing.
7.  **IO**:
    *   `printf` is replaced by `System.out.print` or `PrintWriter` for speed.
    *   `cout` is replaced by `System.out.println`.

### Code Structure
*   Class name: `e_1076`
*   Inner classes: `Edge`, `Pair`
*   Main method logic: Read $N$, build graph, read $M$, run DFS, print results.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.List;

public class e_1076 {
    // Constants
    static final int MAXN = 400000 + 5;
    static final long MOD = 1000000007L;
    
    // Adjacency list for the graph
    static List<Pair>[] G = new ArrayList[MAXN];
    static int[] head = new int[MAXN];
    static int[] s = new int[MAXN];
    static long[] ans = new long[MAXN];
    static int[] dep = new int[MAXN];
    static int n, m, tot;
    
    // Edge structure for the graph (linked list style or vector style)
    // The C++ code uses a linked list for 'e' in insert, but uses 'G' as a vector of pairs.
    // The 'insert' function updates 'head' and 'e' array.
    static class Edge {
        int go;
        int next;
        
        Edge(int go, int next) {
            this.go = go;
            this.next = next;
        }
    }
    
    static Edge[] e = new Edge[MAXN * 2];
    
    // Initialize ArrayLists for G
    static {
        for (int i = 0; i < MAXN; i++) {
            G[i] = new ArrayList<>();
        }
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        n = in.nextInt();
        
        // rep(i, 1, n-1) insert(read(), read());
        for (int i = 1; i <= n - 1; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            insert(u, v);
        }
        
        m = in.nextInt();
        
        // rep(i, 1, m) { int x=read(),y=read(),z=read(); G[x].push_back(pa(y,z)); }
        for (int i = 1; i <= m; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int z = in.nextInt();
            G[x].add(new Pair(y, z));
        }
        
        dep[1] = 1;
        dfs(1, 0);
        
        // rep(i, 1, n) printf("%lld ",ans[i]);
        for (int i = 1; i <= n; i++) {
            out.print(ans[i] + " ");
        }
        out.println();
        
        out.flush();
    }
    
    // C++: void insert(int x,int y)
    // Logic: Add edge x->y and y->x to the linked list structure 'e'
    static void insert(int x, int y) {
        int idx = ++tot;
        e[idx] = new Edge(y, head[x]);
        head[x] = idx;
        
        idx = ++tot;
        e[idx] = new Edge(x, head[y]);
        head[y] = idx;
    }
    
    // C++: void add(int x,int y)
    // Logic: Fenwick Tree update
    static void add(int x, int y) {
        for (; x <= n; x += x & (-x)) {
            s[x] += y;
        }
    }
    
    // C++: ll query(int x)
    // Logic: Fenwick Tree query
    static long query(int x) {
        long ret = 0;
        for (; x > 0; x -= x & (-x)) {
            ret += s[x];
        }
        return ret;
    }
    
    // C++: void dfs(int x,int fa)
    // Logic: Depth First Search to calculate subtree sums
    static void dfs(int x, int fa) {
        // Iterate over the graph G (vector of pairs)
        for (Pair p : G[x]) {
            int y = Math.min(n, p.first + dep[x]);
            int z = p.second;
            add(y, z);
        }
        
        ans[x] = query(n) - query(dep[x] - 1);
        
        // Iterate over the linked list 'e' to traverse the tree structure
        // C++: for4(i,x)
        // Java equivalent: traverse linked list using head array and e array
        int curr = head[x];
        while (curr != 0) {
            int y = e[curr].go;
            if (y != fa) {
                dep[y] = dep[x] + 1;
                dfs(y, x);
            }
            curr = e[curr].next;
        }
        
        // Backtracking: Remove contributions of children
        for (Pair p : G[x]) {
            int y = Math.min(n, p.first + dep[x]);
            int z = p.second;
            add(y, -z);
        }
    }
    
    // Helper class for Pair<int,int>
    static class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    // Fast IO Reader
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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
            String s = next();
            if (s == null) return 0; // Should not happen based on problem logic
            return Integer.parseInt(s);
        }
        
        long nextLong() {
            String s = next();
            if (s == null) return 0L;
            return Long.parseLong(s);
        }
    }
}
```

### Explanation of Translation
1.  **Class Structure**: The C++ `struct edge` and `pair` are converted to static inner classes `Edge` and `Pair` in Java.
2.  **Arrays**: C++ global arrays (`s`, `ans`, `head`, `dep`, `e`) are converted to static arrays in Java.
3.  **Loop Macros**:
    *   `rep(i,l,r)` is replaced by standard `for(int i=l; i<=r; i++)`.
    *   `for4(i,x)` is a C++ specific macro for iterating through a linked list defined by `head` and `e`. In Java, this is implemented manually using a `while` loop traversing `e[curr].next`.
4.  **Fenwick Tree**: The `add` and `query` functions implement the Binary Indexed Tree logic. The modulo operations in C++ (`upmo`) are handled by standard integer arithmetic in Java (since Java `long` is signed and large enough to handle intermediate sums before modulo).
5.  **Input/Output**: The custom `read` function using `getchar` is replaced by a `FastReader` class using `BufferedReader` and `StringTokenizer` for efficiency, which is standard practice in Java for competitive programming. `printf` is replaced by `PrintWriter`.
6.  **Logic**: The `dfs` function logic is preserved, including the subtree sum calculation and backtracking. The graph construction distinguishes between the "tree" structure (using `head` and `e`) and the "query" structure (using `G` as a vector of pairs).

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.List;

public class e_1076 {
    // Constants
    static final int MAXN = 400000 + 5;
    static final long MOD = 1000000007L;
    
    // Adjacency list for the graph
    static List<Pair>[] G = new ArrayList[MAXN];
    static int[] head = new int[MAXN];
    static int[] s = new int[MAXN];
    static long[] ans = new long[MAXN];
    static int[] dep = new int[MAXN];
    static int n, m, tot;
    
    // Edge structure for the graph (linked list style)
    static class Edge {
        int go;
        int next;
        
        Edge(int go, int next) {
            this.go = go;
            this.next = next;
        }
    }
    
    static Edge[] e = new Edge[MAXN * 2];
    
    // Initialize ArrayLists for G
    static {
        for (int i = 0; i < MAXN; i++) {
            G[i] = new ArrayList<>();
        }
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // Read n
        String nStr = in.next();
        if (nStr != null) {
            n = Integer.parseInt(nStr);
        } else {
            return;
        }
        
        // rep(i, 1, n-1) insert(read(), read());
        for (int i = 1; i <= n - 1; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            insert(u, v);
        }
        
        // Read m
        String mStr = in.next();
        if (mStr != null) {
            m = Integer.parseInt(mStr);
        }
        
        // rep(i, 1, m) { int x=read(),y=read(),z=read(); G[x].push_back(pa(y,z)); }
        for (int i = 1; i <= m; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            int z = in.nextInt();
            G[x].add(new Pair(y, z));
        }
        
        dep[1] = 1;
        dfs(1, 0);
        
        // rep(i, 1, n) printf("%lld ",ans[i]);
        for (int i = 1; i <= n; i++) {
            out.print(ans[i] + " ");
        }
        out.println();
        
        out.flush();
    }
    
    // C++: void insert(int x,int y)
    // Logic: Add edge x->y and y->x to the linked list structure 'e'
    static void insert(int x, int y) {
        int idx = ++tot;
        e[idx] = new Edge(y, head[x]);
        head[x] = idx;
        
        idx = ++tot;
        e[idx] = new Edge(x, head[y]);
        head[y] = idx;
    }
    
    // C++: void add(int x,int y)
    // Logic: Fenwick Tree update
    static void add(int x, int y) {
        for (; x <= n; x += x & (-x)) {
            s[x] += y;
        }
    }
    
    // C++: ll query(int x)
    // Logic: Fenwick Tree query
    static long query(int x) {
        long ret = 0;
        for (; x > 0; x -= x & (-x)) {
            ret += s[x];
        }
        return ret;
    }
    
    // C++: void dfs(int x,int fa)
    // Logic: Depth First Search to calculate subtree sums
    static void dfs(int x, int fa) {
        // Iterate over the graph G (vector of pairs)
        for (Pair p : G[x]) {
            int y = Math.min(n, p.first + dep[x]);
            int z = p.second;
            add(y, z);
        }
        
        ans[x] = query(n) - query(dep[x] - 1);
        
        // Iterate over the linked list 'e' to traverse the tree structure
        // C++: for4(i,x)
        // Java equivalent: traverse linked list using head array and e array
        int curr = head[x];
        while (curr != 0) {
            int y = e[curr].go;
            if (y != fa) {
                dep[y] = dep[x] + 1;
                dfs(y, x);
            }
            curr = e[curr].next;
        }
        
        // Backtracking: Remove contributions of children
        for (Pair p : G[x]) {
            int y = Math.min(n, p.first + dep[x]);
            int z = p.second;
            add(y, -z);
        }
    }
    
    // Helper class for Pair<int,int>
    static class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    // Fast IO Reader
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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
            String s = next();
            if (s == null) return 0; // Should not happen based on problem logic
            return Integer.parseInt(s);
        }
        
        long nextLong() {
            String s = next();
            if (s == null) return 0L;
            return Long.parseLong(s);
        }
    }
}
</CODE>