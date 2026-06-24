Translate this C++ code to Java code. The main class name should be e_1486. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
/**

 *    author:  longvu

 *    created: 07/15/22 13:39:18

**/

#include<bits/stdc++.h>



using namespace std;



#define int long long

#define sz(x) ((int)x.size())

#define all(x) (x).begin(), (x).end()

const int INF = 1e13;

const int naxn = (int)(100001);

const int naxw = (int)(51);

const int mod = 1e9 + 7;



template<class X, class Y>

bool maximize(X& x, const Y y) {

    if (y > x) {x = y; return true;}

    return false;

}

template<class X, class Y>

bool minimize(X& x, const Y y) {

    if (y < x) {x = y; return true;}

    return false;

}



#define Fi first

#define Se second



vector<pair<int, int>> adj[naxn];

int dp[naxn][naxw];

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {

        int u, v, c;

        cin >> u >> v >> c;

        adj[u].push_back({v, c});

        adj[v].push_back({u, c});

    }

    priority_queue<tuple<int, int, int>> dq;

    memset(dp, 0x3f, sizeof dp);

    dp[1][0] = 0;

    dq.push({0, 1, 0});

    while (!dq.empty()) {

        tuple<int, int, int> u = dq.top();

        dq.pop();

        get<0>(u) *= -1;

        if (dp[get<1>(u)][get<2>(u)] != get<0>(u)) {

            continue;

        }

        for (auto v : adj[get<1>(u)]) {

            if (get<2>(u)) {

                if (minimize(dp[v.Fi][0], (v.Se + get<2>(u)) * (v.Se + get<2>(u)) + dp[get<1>(u)][get<2>(u)])) {

                    dq.push({-dp[v.Fi][0], v.Fi, 0});

                }

            } else if (minimize(dp[v.Fi][v.Se], dp[get<1>(u)][0])) {

                dq.push({-dp[v.Fi][v.Se], v.Fi, v.Se});

            }

        }

    }

    for (int i = 1; i <= n; ++i) {

        cout << (dp[i][0] < INF ? dp[i][0] : -1) << " ";

    }

    cout << '\n';

    return 0;

}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**: Replace `#include<bits/stdc++.h>` with specific headers (`iostream`, `vector`, `algorithm`, `tuple`, `cstring`, `queue`). Replace `using namespace std;` with explicit namespace usage or keep it if desired (standard practice in competitive programming often retains it, but we will use it for brevity as in the original).
2.  **Macros**:
    *   `int long long` -> Keep as `long long` (since `int` is already `long long` in the original logic, but in Java we must use `long`).
    *   `sz(x)`, `all(x)` -> Not used in the specific logic provided, so ignored.
    *   `INF` -> Use `long` constant.
    *   `naxn`, `naxw` -> Use `int` constants.
    *   `mod` -> Not used in the logic, but defined.
3.  **Templates**: C++ templates (`maximize`, `minimize`) are replaced by Java static helper methods `maximize` and `minimize` taking mutable references (or returning new values).
4.  **Data Structures**:
    *   `vector<pair<int, int>> adj[naxn]` -> `List<List<Pair>> adj`. Since Java lists are dynamic, we can initialize an array of Lists. `Pair` class or `int[]` can be used; `Pair` class is cleaner.
    *   `int dp[naxn][naxw]` -> `long[][] dp` (since values can reach `INF` which is `1e13`, exceeding `int`).
    *   `priority_queue<tuple<...>>` -> `PriorityQueue<Node>` where `Node` implements `Comparable`.
    *   `tuple` -> Java's `List<Integer>` or a custom class. Given the logic `get<0>`, `get<1>`, `get<2>`, a custom class or a `List<Integer>` wrapper is best. A custom class `State` is most readable.
    *   `memset` -> Java does not have `memset`. We use `Arrays.fill` or a nested loop.
5.  **Main Logic**:
    *   `ios_base::sync_with_stdio(false); cin.tie(0);` -> Removed (Java I/O is generally fast enough for this complexity, or we can use `BufferedReader`/`PrintWriter` for safety).
    *   `cin >>` -> `Scanner` or `BufferedReader`. `Scanner` is simpler to translate directly.
    *   `tuple` operations (`get<0>`, etc.) -> Accessors in the `State` class.
    *   `dq.push` -> `pq.add`.
    *   `dq.top()` / `dq.pop()` -> `pq.peek()` / `pq.poll()`.
    *   Output -> `System.out.print` or `PrintWriter`.

### Incremental Tasks
1.  Define the `Pair` class for edges.
2.  Define the `State` class for the priority queue (distance, u, w).
3.  Translate global constants and array declarations.
4.  Translate `maximize` and `minimize` methods.
5.  Translate `main` method:
    *   Input reading.
    *   Graph construction.
    *   Initialization of DP table (using loops instead of `memset`).
    *   Dijkstra-like loop with `PriorityQueue`.
    *   Relaxation logic (handling the `if` conditions and updates).
    *   Output generation.

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class e_1486 {

    // Constants
    static final long INF = 10000000000000L; // 1e13
    static final int NAXN = 100001;
    static final int NAXW = 51;
    static final int MOD = 1000000007;

    // Pair class for adjacency list
    static class Pair {
        int u, v;
        Pair(int u, int v, int c) {
            this.u = u;
            this.v = v;
            this.c = c;
        }
        Pair(int u, int v) {
            this.u = u;
            this.v = v;
            this.c = 0; // Default weight 0 if not specified, though original uses explicit c
        }
        int c;
    }

    // State class for Priority Queue (Distance, Node, Weight)
    // Distance is stored as negative to simulate Max-Heap for Min-Heap behavior (as in C++ tuple with negative distance)
    static class State implements Comparable<State> {
        long dist;
        int u;
        int w;

        State(long dist, int u, int w) {
            this.dist = dist;
            this.u = u;
            this.w = w;
        }

        @Override
        public int compareTo(State o) {
            // C++ uses max-heap with negative distance to act as min-heap
            return Long.compare(this.dist, o.dist);
        }
    }

    static long[][] dp;
    static List<List<Pair>> adj;

    // Helper to minimize value (similar to C++ minimize template)
    // Returns true if update happened
    static boolean minimize(long[] arr, int index, long val) {
        if (val < arr[index]) {
            arr[index] = val;
            return true;
        }
        return false;
    }

    // Helper to maximize value (similar to C++ maximize template)
    // Returns true if update happened
    static boolean maximize(long[] arr, int index, long val) {
        if (val > arr[index]) {
            arr[index] = val;
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        // Use BufferedReader for fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // Initialize Adjacency List
        adj = new ArrayList<>(NAXN);
        for (int i = 0; i <= NAXN; i++) {
            adj.add(new ArrayList<>());
        }

        // Read edges
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            adj.get(u).add(new Pair(u, v, c));
            adj.get(v).add(new Pair(v, u, c));
        }

        // Initialize DP table
        dp = new long[NAXN][NAXW];
        for (int i = 1; i <= NAXN; i++) {
            Arrays.fill(dp[i], INF);
        }

        // Initial state
        dp[1][0] = 0;
        
        // Priority Queue (Max Heap storing negative distances to simulate Min Heap)
        PriorityQueue<State> pq = new PriorityQueue<>();
        pq.add(new State(0, 1, 0));

        while (!pq.isEmpty()) {
            State current = pq.poll();
            long dist = -current.dist; // Convert back to positive distance
            int u = current.u;
            int w = current.w;

            // Check if this state is outdated (lazy deletion)
            if (dp[u][w] != dist) {
                continue;
            }

            // Iterate over neighbors
            for (Pair edge : adj.get(u)) {
                int v = edge.v;
                int weight = edge.c;

                if (w == 1) {
                    // Case: w is 1 (from previous step w=0 or w=1 logic in original)
                    // Original: if (get<2>(u)) { ... minimize(dp[v.Fi][0], ...) }
                    // In original: if w is true (1), we try to transition to w=0 at v
                    // Cost: (w + c)^2 + dp[u][w]
                    long newCost = (long)(weight + w) * (weight + w) + dp[u][w];
                    
                    if (minimize(dp[v], 0, newCost)) {
                        pq.add(new State(-dp[v][0], v, 0));
                    }
                } else {
                    // Case: w is 0
                    // Original: else if (minimize(dp[v.Fi][v.Se], dp[get<1>(u)][0]))
                    // Transition to w=weight at v
                    // Cost: dp[u][0]
                    if (minimize(dp[v], weight, dp[u][0])) {
                        pq.add(new State(-dp[v][weight], v, weight));
                    }
                }
            }
        }

        // Output results
        PrintWriter out = new PrintWriter(System.out);
        for (int i = 1; i <= n; i++) {
            if (dp[i][0] < INF) {
                out.print(dp[i][0] + " ");
            } else {
                out.print("-1 ");
            }
        }
        out.println();
        out.flush();
    }
}
</CODE>