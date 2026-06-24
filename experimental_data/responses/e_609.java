Translate this C++ code to Java code. The main class name should be e_609. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge{
	int a,b,v,n;
}e[210001];
struct edge2{
	int t,next,v;
}g[410001];
ll mc,ans[210001];
bool v[210001];
int h[210001],dep[210001],fa[210001],lca[210001][21],i,j,k,n,m,f[210001],lv[210001][21],tot;
void addedge(int x,int y,int z){
	g[++tot].t=y;g[tot].next=h[x];h[x]=tot;g[tot].v=z;
	g[++tot].t=x;g[tot].next=h[y];h[y]=tot;g[tot].v=z;
}
bool cmp(edge a,edge b){
	return a.v<b.v;
}
int getfa(int x){
	return (f[x])?f[x]=getfa(f[x]):x;
}
bool merge(int x,int y){
	int i=getfa(x),j=getfa(y);
	if (i==j) return 0;
	f[j]=i;return 1;
}
void dfs(int x){
	int i;
	for (i=1;lca[x][i-1];i++) lca[x][i]=lca[lca[x][i-1]][i-1],lv[x][i]=max(lv[x][i-1],lv[lca[x][i-1]][i-1]);
	for (i=h[x];i;i=g[i].next)
	 if (lca[x][0]!=g[i].t) lca[g[i].t][0]=x,lv[g[i].t][0]=g[i].v,dep[g[i].t]=dep[x]+1,dfs(g[i].t);
}
int getlca(int x,int y){
	int i;
	if (dep[x]>dep[y]) swap(x,y);
	for (i=20;dep[y]>dep[x];y=lca[y][i])
	 for (;dep[lca[y][i]]<dep[x];i--);
	for (i=20;x!=y;x=lca[x][i],y=lca[y][i])
	 for (;i&&lca[x][i]==lca[y][i];i--);
	return x;
}
int query(int x,int d){
	int i,res=0;
	for (i=20;d;x=lca[x][i],d-=(1<<i)){
		for (;(1<<i)>d;i--);
		res=max(res,lv[x][i]);
	}
	return res;
}
int work(int x,int y){
	int k=getlca(x,y);
	return max(query(x,dep[x]-dep[k]),query(y,dep[y]-dep[k]));
}
int main(){
	scanf("%d%d",&n,&m);memset(f,0,sizeof(f));memset(h,0,sizeof(h));memset(lca,0,sizeof(lca));memset(lv,0,sizeof(lv));
	for (i=1;i<=m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].v),e[i].n=i;
	sort(e+1,e+1+m,cmp);
	for (i=1,k=mc=0;k<n-1;i++)
	 if (merge(e[i].a,e[i].b)){
		addedge(e[i].a,e[i].b,e[i].v);mc+=e[i].v;k++;v[e[i].n]=1;
	 }else v[e[i].n]=0;
	dep[1]=1;dep[0]=0;dfs(1);
	for (i=1;i<=m;i++){
		if (v[e[i].n]) ans[e[i].n]=mc;else ans[e[i].n]=mc-work(e[i].a,e[i].b)+e[i].v;
	}
	for (i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}

<think>

</think>

### Translation Plan

1.  **Headers & Namespaces**:
    *   Replace `#include <bits/stdc++.h>` with specific headers: `<cstdio>`, `<cstring>`, `<algorithm>`, `<vector>`.
    *   Remove `using namespace std;` and use explicit `std::` prefixes where necessary, or keep it local to avoid conflicts (though in competitive programming contexts, keeping it is common practice, I will use explicit namespaces for clarity in Java).
    *   Replace `typedef long long ll;` with Java's `long` type.

2.  **Structures**:
    *   C++ `struct` maps directly to Java `class` (or `record` in modern Java, but `class` is safer for older versions).
    *   C++ arrays (`e[210001]`) map to Java arrays (`new int[210001]`) or `ArrayList`. Given the fixed size and performance needs, fixed-size arrays are preferred.
    *   The adjacency list implementation uses a "head array + next array" linked list approach (common in C++ for graph problems). This will be translated directly to Java arrays `h`, `next`, and `v`.

3.  **Functions & Logic**:
    *   C++ `void` functions map to Java `void` methods.
    *   C++ `bool` functions map to Java `boolean` methods.
    *   C++ `int` functions map to Java `int` methods.
    *   **Recursion**: C++ `dfs` maps to Java `dfs` (recursive method).
    *   **Pointers/References**: C++ pass-by-reference (implicit in structs) maps to Java pass-by-value (returning results or modifying fields directly).
    *   **Standard Library**:
        *   `scanf`/`printf` -> `Scanner` or `BufferedReader` + `StringTokenizer`. `BufferedReader` is faster and preferred for large inputs typical in such graph problems.
        *   `memset` -> `Arrays.fill()`.
        *   `sort` -> `Arrays.sort()` with a custom `Comparator`.
        *   `swap` -> Manual swap or `Collections.swap` (though manual is easier for primitives).
        *   `max` -> `Math.max()`.

4.  **Main Class**:
    *   Rename to `e_609` as requested.
    *   Ensure the `main` method signature is `public static void main(String[] args)`.

5.  **Incremental Tasks**:
    *   Define data structures (`Edge`, `Edge2` equivalent via arrays).
    *   Implement input reading.
    *   Implement DSU (`getfa`, `merge`).
    *   Implement Graph building (`addedge`).
    *   Implement DFS for LCA and depths.
    *   Implement `query` and `work` (LCA distance logic).
    *   Implement `main` logic flow.
    *   Implement output.

### Java Code

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class e_609 {

    // Global arrays matching C++ sizes
    // e: edge list, max size 210001
    // g: adjacency list, max size 410001 (2 * 210001)
    // ans: answer array, max size 210001
    // v: visited/active flag, max size 210001
    // h, dep, fa, lca, lv: LCA related arrays, max size 210001
    // f: DSU parent array, max size 210001
    static final int MAXN = 210001;
    static final int MAXG = 410001;

    static class Edge implements Comparable<Edge> {
        int a, b, v, n;

        public int compareTo(Edge o) {
            return Integer.compare(this.v, o.v);
        }
    }

    static Edge[] e = new Edge[MAXN];
    static int[] h = new int[MAXN];
    static int[] next = new int[MAXG];
    static int[] v = new int[MAXN]; // Using int as boolean (0 or 1)
    static int[] dep = new int[MAXN];
    static int[] fa = new int[MAXN];
    static int[][] lca = new int[MAXN][21];
    static int[][] lv = new int[MAXN][21];
    static int[] f = new int[MAXN];
    static int[] ans = new int[MAXN];
    static int tot;

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();

        // Initialize arrays
        Arrays.fill(f, 0);
        Arrays.fill(h, 0);
        for (int i = 0; i < 21; i++) {
            Arrays.fill(lca[i], 0);
            Arrays.fill(lv[i], 0);
        }
        Arrays.fill(v, 0);

        // Read edges
        for (int i = 1; i <= m; i++) {
            e[i] = new Edge();
            e[i].a = sc.nextInt();
            e[i].b = sc.nextInt();
            e[i].v = sc.nextInt();
            e[i].n = i;
        }

        // Sort edges by weight
        Arrays.sort(e, 1, m + 1);

        int mc = 0;
        int k = 0;

        // Kruskal's Algorithm part
        for (int i = 1; i <= m; i++) {
            if (merge(e[i].a, e[i].b)) {
                addedge(e[i].a, e[i].b, e[i].v);
                mc += e[i].v;
                k++;
                v[e[i].n] = 1;
            } else {
                v[e[i].n] = 0;
            }
        }

        // DFS for LCA and depths
        if (k < n - 1) {
            // If the graph is not connected, the problem logic might assume connectivity or handle components.
            // The original C++ code assumes connectivity implicitly by calling dfs(1).
            // We proceed assuming the MST covers the relevant nodes or the graph is connected.
            // If k < n-1, node 1 might not be part of the main component if the graph was disconnected initially.
            // However, standard MST problems on trees usually imply connectivity.
            // We will run DFS from 1 as per original logic.
        }

        dep[1] = 1;
        dep[0] = 0;
        dfs(1);

        // Calculate answers
        for (int i = 1; i <= m; i++) {
            if (v[i]) {
                ans[i] = mc;
            } else {
                ans[i] = mc - work(i) + e[i].v;
            }
        }

        // Output results
        for (int i = 1; i <= m; i++) {
            out.println(ans[i]);
        }

        out.flush();
    }

    static boolean merge(int x, int y) {
        int i = getfa(x);
        int j = getfa(y);
        if (i == j) return false;
        f[j] = i;
        return true;
    }

    static int getfa(int x) {
        if (f[x] == 0) return x;
        f[x] = getfa(f[x]);
        return f[x];
    }

    static void addedge(int x, int y, int z) {
        tot++;
        next[tot] = h[x];
        h[x] = tot;
        // We need to store the value z. Since Java doesn't allow parallel arrays easily in this structure without a class,
        // and the C++ code uses a struct 'g', we can use an array 'gVal' or store in a class.
        // To keep it simple and efficient like the C++ array 'g', let's use a separate array for values.
        // However, the C++ code has 'g' as an array of structs. Let's allocate a parallel array 'gVal'.
        // But wait, the C++ code defines 'g' globally. We can simulate the struct with parallel arrays.
        // Let's add 'gVal' array.
        // Actually, looking at the C++ code: g[tot].v = z.
        // We will use a static array for this.
        gVal[tot] = z;
    }
    
    // Parallel array for g values since Java arrays are objects
    static int[] gVal = new int[MAXG];

    static void dfs(int x) {
        // Precompute LCA and max depth (lv) using binary lifting
        // lca[x][i-1] must be computed before lca[x][i]
        // In C++, lca[x][i-1] is accessed. In Java, we iterate i from 1 to 20.
        // Base case: lca[x][0] is set by the loop over children.
        
        // Compute lca[x][i] and lv[x][i] based on lca[x][i-1]
        for (int i = 1; i < 21; i++) {
            int parent = lca[x][i - 1];
            lca[x][i] = lca[parent][i - 1];
            lv[x][i] = Math.max(lv[x][i - 1], lv[parent][i - 1]);
        }

        // Traverse children
        for (int i = h[x]; i != 0; i = next[i]) {
            int child = 0;
            // Find child node. In the linked list representation:
            // We need to extract the node index from the edge.
            // The C++ code: g[i].t. We need to find the node corresponding to edge i.
            // Since we stored values in gVal, we need the node.
            // Wait, the C++ code structure:
            // struct edge2 { int t, next, v; } g[];
            // addedge fills g[tot].t, g[tot].next, g[tot].v.
            // To retrieve 't' in Java, we need to store it.
            // Let's add an array 'gHead' or similar? No, 'next' stores the index of the next edge.
            // We need to store 't'.
            // Let's add 'gNode' array.
            int nodeT = gNode[i];
            
            if (lca[x][0] != nodeT) {
                lca[nodeT][0] = x;
                lv[nodeT][0] = gVal[i];
                dep[nodeT] = dep[x] + 1;
                dfs(nodeT);
            }
        }
    }
    
    static int[] gNode = new int[MAXG];

    static int getlca(int x, int y) {
        if (dep[x] < dep[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        
        // Lift x to same depth as y
        for (int i = 20; i >= 0; i--) {
            if (dep[x] - (1 << i) >= dep[y]) {
                x = lca[x][i];
            }
        }
        
        if (x == y) return x;
        
        for (int i = 20; i >= 0; i--) {
            if (lca[x][i] != lca[y][i]) {
                x = lca[x][i];
                y = lca[y][i];
            }
        }
        
        return lca[x][0];
    }

    static int query(int x, int d) {
        int res = 0;
        for (int i = 20; i >= 0; i--) {
            if ((1 << i) <= d) {
                res = Math.max(res, lv[x][i]);
                x = lca[x][i];
                d -= (1 << i);
            }
        }
        return res;
    }

    static int work(int x, int y) {
        int k = getlca(x, y);
        int d1 = dep[x] - dep[k];
        int d2 = dep[y] - dep[k];
        return Math.max(query(x, d1), query(y, d2));
    }

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
            if (s == null) return 0; // Should not happen with valid input
            return Integer.parseInt(s);
        }
    }
}
</CODE>