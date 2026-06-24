Translate this C++ code to Java code. The main class name should be f_1509. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;



struct DSU {

    vector<int> p, sz;

    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }



    int leader(int x) {

        if (x != p[x]) p[x] = leader(p[x]);

        return p[x];

    }



    bool merge(int x, int y) {

        x = leader(x), y = leader(y);

        if (x == y) return false;

        sz[x] += sz[y];

        p[y] = x;

        return true;

    }



    bool same(int x, int y) {

        return leader(x) == leader(y);

    }



    int size(int x) { return sz[leader(x)]; }

};



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int n, m;

    cin >> n >> m;

    ll rem = 1ll * n * (n - 1) / 2 - m;

    vector<array<int, 3>> e(m);

    vector<vector<int>> adj(n);

    int x = 0;

    for (int i = 0; i < m; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        u--, v--;

        e[i] = {u, v, w};

        adj[u].push_back(v);

        adj[v].push_back(u);

        x ^= w;

    }

    DSU dsu(n);

    int mn = 0;

    for (int i = 0; i < n; i++) {

        if (adj[mn].size() > adj[i].size()) {

            mn = i;

        }

    }

    vector<bool> vis(n);

    for (int v : adj[mn]) {

        vis[v] = true;

    }

    for (int i = 0; i < n; i++) {

        if (vis[i]) continue;

        if (dsu.merge(mn, i)) rem--;

    }

    for (int i = 0; i < n; i++) {

        if (!vis[i]) continue;

        vector<bool> con(n);

        for (int v : adj[i]) {

            con[v] = true;

        }

        for (int j = 0; j < n; j++) {

            if (con[j] || j == i) continue;

            if (dsu.merge(i, j)) rem--;

        }

    }

    ll ans = 0;

    sort(e.begin(), e.end(), [&](array<int, 3> a, array<int, 3> b){

        return a[2] < b[2];

    });

    vector<int> type(m);

    for (int i = 0; i < m; i++) {

        auto [u, v, w] = e[i];

        if (dsu.merge(u, v)) {

            type[i] = 1;

            ans += w;

        }

    }

    DSU dsu1(n);

    for (int i = 0; i < m; i++) {

        auto [u, v, w] = e[i];

        if (!dsu1.merge(u, v)) continue;

        if (type[i]) continue;

        x = min(x, w);

    }

    if (rem == 0) {

        ans += x;

    }

    cout << ans << '\n';

    return 0;

}

Here is the plan for translating the provided C++ code to Java.

### Translation Plan

1.  **Header and Imports**:
    *   Remove `#include <bits/stdc++.h>` and `using namespace std;`.
    *   Include necessary Java libraries: `java.util.*` (ArrayList, Arrays, Scanner, etc.) and `java.io.*` (BufferedInputStream, PrintWriter, StringTokenizer).
    *   Create a custom `FastScanner` class or use `BufferedReader` + `StringTokenizer` to replace `cin`/`cout` for performance, as competitive programming problems usually require fast I/O.

2.  **Type Definitions**:
    *   `typedef long long ll;` $\rightarrow$ `long long` (Java's `long`).
    *   `typedef pair<int, int> PII;` $\rightarrow$ Java does not have a built-in `pair`. We can use a simple `class Pair` or `int[]`. Since the code uses `array<int, 3>` later, we will define a `class Edge` or `int[]` to store `(u, v, w)`. Using a custom class is cleaner.

3.  **DSU (Disjoint Set Union) Structure**:
    *   The C++ `struct DSU` needs to become a Java `class DSU`.
    *   The constructor `DSU(int n)` initializes the `p` (parent) and `sz` (size) arrays.
    *   `leader(x)` method: Implement path compression.
    *   `merge(x, y)` method: Implement union by size.
    *   `same(x, y)` method: Check if roots are equal.
    *   `size(x)` method: Return size of set.
    *   *Note*: The C++ code uses `vector<int>`, which translates to `int[]` in Java.

4.  **Main Method**:
    *   The `main` function becomes the `main` method in the `f_1509` class.
    *   Replace `cin >> n >> m` with `scanner.nextInt()`.
    *   Replace `vector<array<int, 3>> e(m)` with `int[][] e` or `Edge[] e`.
    *   Replace `vector<vector<int>> adj(n)` with `ArrayList<Integer>[] adj`.
    *   Replace `vector<bool> vis(n)` with `boolean[] vis`.
    *   Replace `sort` logic with `Arrays.sort` using a custom `Comparator`.
    *   Replace `cout << ans` with `out.println(ans)`.

5.  **Specific Logic Adjustments**:
    *   **Bitwise XOR**: `x ^= w` is valid in both.
    *   **Ternary Operator**: C++ `? :` maps directly to Java `? :`.
    *   **Lambda Expressions**: Java supports lambdas, but the syntax is slightly different. `auto [u, v, w] = e[i];` (C++ structured binding) needs to be manually unpacked in Java (e.g., `int u = e[i][0];`).
    *   **Range-based for loops**: `for (int v : adj[mn])` becomes a standard `for` loop iterating over the `ArrayList`.

6.  **Incremental Tasks**:
    *   Task 1: Setup `FastScanner` and `PrintWriter`.
    *   Task 2: Define `DSU` class.
    *   Task 3: Define `Edge` class (or use `int[]`).
    *   Task 4: Translate `main` method logic (Input, Adjacency list, Visited array, DSU initialization, BFS-like expansion).
    *   Task 5: Translate the sorting and final calculation logic.

### Java Code

```java
import java.io.*;
import java.util.*;

public class f_1509 {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

    static class PrintWriter {
        PrintWriter out;

        public PrintWriter() {
            out = new PrintWriter(new BufferedOutputStream(System.out));
        }

        void print(long x) {
            out.print(x);
        }

        void println(long x) {
            out.println(x);
        }

        void flush() {
            out.flush();
        }
    }

    static class Edge {
        int u, v, w;

        public Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }

    static class DSU {
        int[] p;
        int[] sz;

        public DSU(int n) {
            p = new int[n];
            sz = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                sz[i] = 1;
            }
        }

        public int leader(int x) {
            if (x != p[x]) {
                p[x] = leader(p[x]);
            }
            return p[x];
        }

        public boolean merge(int x, int y) {
            x = leader(x);
            y = leader(y);
            if (x == y) return false;
            if (sz[x] < sz[y]) {
                int temp = x;
                x = y;
                y = temp;
            }
            sz[x] += sz[y];
            p[y] = x;
            return true;
        }

        public boolean same(int x, int y) {
            return leader(x) == leader(y);
        }

        public int size(int x) {
            return sz[leader(x)];
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        PrintWriter out = new PrintWriter();

        // Read n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        long rem = (long) n * (n - 1) / 2 - m;
        
        Edge[] e = new Edge[m];
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        int x = 0;
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            
            u--; // 0-based index
            v--; // 0-based index
            
            e[i] = new Edge(u, v, w);
            adj[u].add(v);
            adj[v].add(u);
            x ^= w;
        }

        DSU dsu = new DSU(n);
        int mn = 0;
        for (int i = 0; i < n; i++) {
            if (adj[0].isEmpty()) {
                // If no edges, mn is just 0, but logic below checks adj[mn].size()
                // Assuming n >= 1. If n=1, adj[0] is empty, size is 0.
                // If n > 1 and no edges, all sizes are 0.
            }
            if (adj[mn].size() > adj[i].size()) {
                mn = i;
            }
        }

        boolean[] vis = new boolean[n];
        for (int v : adj[mn]) {
            vis[v] = true;
        }

        // Connect isolated nodes to the component containing mn
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (dsu.merge(mn, i)) rem--;
        }

        // Connect components formed by the initial edges
        for (int i = 0; i < n; i++) {
            if (!vis[i]) continue;
            ArrayList<Integer> con = new ArrayList<>();
            for (int v : adj[i]) {
                con.add(v);
            }
            for (int j = 0; j < n; j++) {
                if (con.contains(j) || j == i) continue;
                if (dsu.merge(i, j)) rem--;
            }
        }

        long ans = 0;
        // Sort edges by weight
        Arrays.sort(e, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                return Integer.compare(a.w, b.w);
            }
        });

        int[] type = new int[m];
        for (int i = 0; i < m; i++) {
            Edge edge = e[i];
            if (dsu.merge(edge.u, edge.v)) {
                type[i] = 1;
                ans += edge.w;
            }
        }

        DSU dsu1 = new DSU(n);
        for (int i = 0; i < m; i++) {
            Edge edge = e[i];
            if (!dsu1.merge(edge.u, edge.v)) continue;
            if (type[i] == 1) continue; // type[i] is 1 if it was merged in the previous loop
            x = Math.min(x, edge.w);
        }

        if (rem == 0) {
            ans += x;
        }

        out.println(ans);
        out.flush();
    }
}
```
</think>

Here is the Java translation of the provided C++ code.

### Translation Plan

1.  **Imports & I/O**:
    *   Replace C++ headers (`#include <bits/stdc++.h>`) with Java imports (`java.util.*`, `java.io.*`).
    *   Implement a `FastScanner` class using `BufferedReader` and `StringTokenizer` to replace `cin` and `scanf`, ensuring the solution meets performance requirements typical for competitive programming.
    *   Replace `cout` with a `PrintWriter` for efficient output.

2.  **Type Definitions**:
    *   `typedef long long ll;` maps to Java's `long`.
    *   `typedef pair<int, int> PII;` is not strictly used in the final logic (the code uses `array<int, 3>`), but we will use a custom `Edge` class to replace `array<int, 3>` for clarity.

3.  **DSU (Disjoint Set Union)**:
    *   Convert the C++ `struct DSU` to a Java `class DSU`.
    *   Convert `vector<int>` to `int[]`.
    *   Implement `leader` (find with path compression) and `merge` (union by size) methods. Note that Java is not pass-by-reference for primitives, so the arrays must be static fields or passed explicitly. Here, I will make them instance fields of the class.

4.  **Main Logic**:
    *   Convert `main` function to `public static void main(String[] args)`.
    *   Convert `vector<vector<int>>` to `ArrayList<Integer>[]`.
    *   Convert `vector<bool>` to `boolean[]`.
    *   Convert `vector<array<int, 3>>` to `Edge[]` and implement sorting using `Arrays.sort` with a custom `Comparator`.
    *   Handle structured bindings (C++ `auto [u, v, w]`) by manually unpacking the `Edge` object in Java.

```java
import java.io.*;
import java.util.*;

public class f_1509 {
    // Fast I/O Helper
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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
    }

    // Output Helper
    static class PrintWriter {
        PrintWriter out;

        public PrintWriter() {
            out = new PrintWriter(new BufferedOutputStream(System.out));
        }

        void print(long x) {
            out.print(x);
        }

        void println(long x) {
            out.println(x);
        }

        void flush() {
            out.flush();
        }
    }

    // Edge class to replace array<int, 3>
    static class Edge {
        int u, v, w;

        public Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }

    // DSU Structure
    static class DSU {
        int[] p;
        int[] sz;

        public DSU(int n) {
            p = new int[n];
            sz = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                sz[i] = 1;
            }
        }

        public int leader(int x) {
            if (x != p[x]) {
                p[x] = leader(p[x]);
            }
            return p[x];
        }

        public boolean merge(int x, int y) {
            x = leader(x);
            y = leader(y);
            if (x == y) return false;
            // Union by size
            if (sz[x] < sz[y]) {
                int temp = x;
                x = y;
                y = temp;
            }
            sz[x] += sz[y];
            p[y] = x;
            return true;
        }

        public boolean same(int x, int y) {
            return leader(x) == leader(y);
        }

        public int size(int x) {
            return sz[leader(x)];
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        PrintWriter out = new PrintWriter();

        // Read n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        long rem = (long) n * (n - 1) / 2 - m;
        
        Edge[] e = new Edge[m];
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        int x = 0;
        for (int i = 0; i < m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            
            u--; // 0-based index
            v--; // 0-based index
            
            e[i] = new Edge(u, v, w);
            adj[u].add(v);
            adj[v].add(u);
            x ^= w;
        }

        DSU dsu = new DSU(n);
        int mn = 0;
        for (int i = 0; i < n; i++) {
            if (adj[mn].size() > adj[i].size()) {
                mn = i;
            }
        }

        boolean[] vis = new boolean[n];
        for (int v : adj[mn]) {
            vis[v] = true;
        }

        // Connect isolated nodes to the component containing mn
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (dsu.merge(mn, i)) rem--;
        }

        // Connect components formed by the initial edges
        for (int i = 0; i < n; i++) {
            if (!vis[i]) continue;
            ArrayList<Integer> con = new ArrayList<>();
            for (int v : adj[i]) {
                con.add(v);
            }
            for (int j = 0; j < n; j++) {
                if (con.contains(j) || j == i) continue;
                if (dsu.merge(i, j)) rem--;
            }
        }

        long ans = 0;
        // Sort edges by weight
        Arrays.sort(e, new Comparator<Edge>() {
            @Override
            public int compare(Edge a, Edge b) {
                return Integer.compare(a.w, b.w);
            }
        });

        int[] type = new int[m];
        for (int i = 0; i < m; i++) {
            Edge edge = e[i];
            if (dsu.merge(edge.u, edge.v)) {
                type[i] = 1;
                ans += edge.w;
            }
        }

        DSU dsu1 = new DSU(n);
        for (int i = 0; i < m; i++) {
            Edge edge = e[i];
            if (!dsu1.merge(edge.u, edge.v)) continue;
            if (type[i] == 1) continue; // type[i] is 1 if it was merged in the previous loop
            x = Math.min(x, edge.w);
        }

        if (rem == 0) {
            ans += x;
        }

        out.println(ans);
        out.flush();
    }
}
```