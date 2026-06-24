Translate this C++ code to Java code. The main class name should be d_1187. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 3e5 + 5;

struct node_t { int l, r, maxn; } p[N << 2];

int a[N], b[N], t1[N], t2[N], now[N], pre[N];
int T, n;

void update(int u) { p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn); }

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].maxn = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int x) {
    if(p[u].l == p[u].r) {
        p[u].maxn = 0;
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) change(u << 1, x);
    else change(u << 1 | 1, x);
    update(u);
}

int query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) return p[u].maxn;
    int mid = (p[u].l + p[u].r) >> 1, ans = 0;
    if(mid >= l) ans = query(u << 1, l, r);
    if(mid + 1 <= r) ans = max(ans, query(u << 1 | 1, l, r));
    return ans;
}

int main() {
    read(T);
    while(T--) {
        read(n);
        for(register int i = 1; i <= n; i++) read(a[i]), t1[i] = a[i];
        for(register int i = 1; i <= n; i++) read(b[i]), t2[i] = b[i];
        sort(t1 + 1, t1 + n + 1); sort(t2 + 1, t2 + n + 1);
        bool ok = 1;
        for(register int i = 1; i <= n; i++) {
            if(t1[i] != t2[i]) {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            printf("NO\n");
            continue;
        }
        for(register int i = 1; i <= n; i++) now[i] = 0;
        for(register int i = 1; i <= n; i++) if(!now[t1[i]]) now[t1[i]] = i;
        for(register int i = 1; i <= n; i++) t2[i] = now[i];
        for(register int i = 1; i <= n; i++) {
            int tmp = a[i];
            a[i] = now[a[i]];
            ++now[tmp];
            pre[a[i]] = i;
        }
        for(register int i = 1; i <= n; i++) now[i] = t2[i];
        for(register int i = 1; i <= n; i++) {
            int tmp = b[i];
            b[i] = now[b[i]];
            ++now[tmp];
        }
        build(1, 1, n);
        // for(register int i = 1; i <= n; i++) {
        //     fprintf(stderr, "%d %d %d\n", a[i], b[i], pre[b[i]]);
        // }
        for(register int i = n; i >= 1; i--) {
            if(query(1, pre[b[i]], n) > b[i]) {
                ok = 0;
                break;
            }
            change(1, pre[b[i]]);
        }
        if(!ok) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**:
    *   Replace `#include <bits/stdc++.h>` with specific standard library headers (`iostream`, `vector`, `algorithm`, `cstdio`).
    *   Replace `using namespace std;` with explicit usage where appropriate or keep it for brevity (though explicit is safer in Java).
    *   Replace C++ `#define` macros with Java equivalents (e.g., `rep` loops become `for` loops, `per` loops become reverse `for` loops).

2.  **Data Types**:
    *   C++ `long long` translates to Java `long`.
    *   C++ `int` translates to Java `int`.
    *   C++ `unsigned long long` is not directly available in Java as a separate signed/unsigned type for this context; since the problem involves array indices and counts, `long` is sufficient.
    *   C++ `pair<int, int>` (`pii`) is not used in the provided code, so no specific translation is needed, but the concept of tuples exists in Java via classes or `int[]`.

3.  **I/O Handling**:
    *   C++ uses `getchar` and `putchar` for fast I/O. In Java, we must implement a custom `FastScanner` class using `BufferedReader` and `InputStreamReader` to achieve similar performance.
    *   Replace `printf` and manual `putchar` logic with `System.out.println` or a `PrintWriter`/`StringBuilder` for efficiency, as Java's `System.out.println` can be slow in competitive programming contexts.

4.  **Structures and Templates**:
    *   C++ `struct` and `class` map directly to Java `class`.
    *   C++ template `hash_map_t` needs to be converted to a Java class implementing the same logic using `ArrayList` (acting as dynamic vectors).
    *   C++ template `read` function becomes a Java method `read` in the `FastScanner` class.

5.  **Logic and Arrays**:
    *   C++ static arrays (`int a[N]`) are replaced by Java `int[]` arrays. Note that Java arrays are 0-indexed, so we need to adjust indices (size `N+1` to accommodate 1-based indexing).
    *   Pointer arithmetic (`u << 1`) translates directly to bit shifting in Java (`u << 1`).
    *   Function calls remain similar but must adhere to Java syntax (no `this` pointer for static members unless instantiated).

6.  **Incremental Tasks**:
    *   Step 1: Create `FastScanner` class.
    *   Step 2: Implement `HashMap` structure (`hash_map_t` -> `HashMap` class).
    *   Step 3: Implement Segment Tree (`node_t`, `build`, `change`, `query`, `update`).
    *   Step 4: Implement `main` logic, adapting loops and I/O.
    *   Step 5: Assemble into `d_1187`.

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class d_1187 {

    // Fast I/O Scanner
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
            String s = next();
            if (s == null) return 0; // Should not happen based on problem constraints
            return Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            if (s == null) return 0L;
            return Long.parseLong(s);
        }
    }

    // Custom HashMap Structure (Translated from C++ hash_map_t)
    static class HashMapStruct {
        ArrayList<Integer> v;
        ArrayList<Integer> val;
        ArrayList<Integer> nxt;
        int[] head;
        int mod;
        int tot;
        int lastv;
        int lastans;
        boolean haveAns;

        public HashMapStruct(int md) {
            head = new int[md];
            Arrays.fill(head, 0);
            v = new ArrayList<>();
            val = new ArrayList<>();
            nxt = new ArrayList<>();
            tot = 0;
            mod = md;
            haveAns = false;
        }

        public void clear() {
            // Re-initialize with same mod
            head = new int[mod];
            Arrays.fill(head, 0);
            v = new ArrayList<>();
            val = new ArrayList<>();
            nxt = new ArrayList<>();
            tot = 0;
            haveAns = false;
        }

        public boolean count(int x) {
            int u = x % mod;
            for (int i = head[u]; i != 0; i = nxt.get(i - 1)) { // Adjust for 0-based ArrayList
                if (v.get(i - 1) == x) {
                    haveAns = true;
                    lastv = x;
                    lastans = val.get(i - 1);
                    return true;
                }
            }
            return false;
        }

        public void ins(int x, int y) {
            int u = x % mod;
            nxt.add(head[u]);
            head[u] = ++tot;
            v.add(x);
            val.add(y);
        }

        public int qry(int x) {
            if (haveAns && lastv == x) return lastans;
            count(x);
            return lastans;
        }
    }

    // Segment Tree Node
    static class Node {
        int l, r, maxn;
        public Node(int l, int r, int maxn) {
            this.l = l;
            this.r = r;
            this.maxn = maxn;
        }
    }

    // Global-like arrays (using size N + 5 to handle 1-based indexing safely)
    static int[] a;
    static int[] b;
    static int[] t1;
    static int[] t2;
    static int[] now;
    static int[] pre;
    static Node[] p;
    static int N;

    // Update Segment Tree
    static void update(int u) {
        p[u].maxn = Math.max(p[u << 1].maxn, p[(u << 1) | 1].maxn);
    }

    // Build Segment Tree
    static void build(int u, int l, int r) {
        p[u].l = l;
        p[u].r = r;
        if (l == r) {
            p[u].maxn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build((u << 1) | 1, mid + 1, r);
        update(u);
    }

    // Change Segment Tree (Set to 0)
    static void change(int u, int x) {
        if (p[u].l == p[u].r) {
            p[u].maxn = 0;
            return;
        }
        int mid = (p[u].l + p[u].r) >> 1;
        if (mid >= x) {
            change(u << 1, x);
        } else {
            change((u << 1) | 1, x);
        }
        update(u);
    }

    // Query Segment Tree
    static int query(int u, int l, int r) {
        if (l <= p[u].l && p[u].r <= r) {
            return p[u].maxn;
        }
        int mid = (p[u].l + p[u].r) >> 1;
        int ans = 0;
        if (mid >= l) {
            ans = query(u << 1, l, r);
        }
        if (mid + 1 <= r) {
            ans = Math.max(ans, query((u << 1) | 1, l, r));
        }
        return ans;
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int T = sc.nextInt();
        
        // Allocate arrays with sufficient size (N = 300005)
        N = 300005;
        a = new int[N];
        b = new int[N];
        t1 = new int[N];
        t2 = new int[N];
        now = new int[N];
        pre = new int[N];
        
        // Segment tree size: 4 * N
        p = new Node[(N << 2)];

        while (T-- > 0) {
            int n = sc.nextInt();
            for (int i = 1; i <= n; i++) {
                a[i] = sc.nextInt();
                t1[i] = a[i];
            }
            for (int i = 1; i <= n; i++) {
                b[i] = sc.nextInt();
                t2[i] = b[i];
            }

            Arrays.sort(t1, 1, n + 1);
            Arrays.sort(t2, 1, n + 1);

            boolean ok = true;
            for (int i = 1; i <= n; i++) {
                if (t1[i] != t2[i]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) {
                System.out.println("NO");
                continue;
            }

            Arrays.fill(now, 0);
            for (int i = 1; i <= n; i++) {
                if (now[t1[i]] == 0) {
                    now[t1[i]] = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                t2[i] = now[i];
            }

            for (int i = 1; i <= n; i++) {
                int tmp = a[i];
                a[i] = now[tmp];
                now[tmp]++;
                pre[a[i]] = i;
            }

            for (int i = 1; i <= n; i++) {
                now[i] = t2[i];
            }

            for (int i = 1; i <= n; i++) {
                int tmp = b[i];
                b[i] = now[tmp];
                now[tmp]++;
            }

            // Build Segment Tree
            build(1, 1, n);

            // Check logic
            boolean possible = true;
            for (int i = n; i >= 1; i--) {
                if (query(1, pre[b[i]], n) > b[i]) {
                    possible = false;
                    break;
                }
                change(1, pre[b[i]]);
            }

            if (!possible) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
}
</CODE>