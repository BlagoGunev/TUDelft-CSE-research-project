Translate this C++ code to Java code. The main class name should be c_786. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
#define all(x) x.begin(), x.end()

const int maxn = 200100;
int a[maxn];
int VER;
vector<int> pos[maxn];

const int base = 1 << 17;
int t[base * 2];
vector<int> qs[maxn];
int ans[maxn];

int get(int x, int v = 1, int cl = 0, int cr = base) {
    if (x >= t[v])
        return cr;
    if (cl + 1 == cr)
        return cl;
    int cc = (cl + cr) / 2;
    if (x >= t[v * 2])
        return get(x - t[v * 2], v * 2 + 1, cc, cr);
    else
        return get(x, v * 2, cl, cc);
}

void put(int v, int val) {
    v += base;
    t[v] = val;
    while (v > 1) {
        v >>= 1;
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        scanf("%d", a + i);
        --a[i];
        pos[a[i]].push_back(i);
    }
    forn (i, n) {
        reverse(all(pos[i]));
        if (!pos[i].empty())
            t[pos[i].back() + base]++;
    }
    for (int i = base - 1; i > 0; --i)
        t[i] = t[i * 2] + t[i * 2 + 1];
    forn (i, n)
        qs[0].push_back(i + 1);
    forn (i, n) {
        for (auto k: qs[i]) {
            int to = get(k);
            ++ans[k];
            if (to < n)
                qs[to].push_back(k);
        }
        qs[i].clear();

        put(i, 0);
        int x = a[i];
        pos[x].pop_back();
        if (!pos[x].empty())
            put(pos[x].back(), 1);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}

Here is the plan for translating the C++ code to Java.

### Translation Plan

1.  **Language Differences & Mapping**:
    *   **Input/Output**: C++ uses `cin`, `cout`, `scanf`, `printf`. Java uses `Scanner` or `BufferedReader`/`StringTokenizer` and `PrintWriter`. Given the constraints implied by competitive programming (large inputs), `BufferedReader` and `PrintWriter` are preferred for performance.
    *   **Macros**:
        *   `sz(x)` -> `x.size()`.
        *   `forn(i, n)` -> `for (int i = 0; i < n; i++)`.
        *   `all(x)` -> `x` (Java doesn't have iterators like C++ iterators directly in lists, usually accessed via index or enhanced for loop).
        *   `reverse(all(x))` -> `Collections.reverse(x)` (for `ArrayList`).
    *   **Types**:
        *   `long long` -> `long` in Java.
        *   `int` -> `int` in Java.
        *   `vector<int>` -> `ArrayList<Integer>`.
    *   **Pointers/Arrays**: C++ arrays (`int a[maxn]`) are translated directly to Java arrays (`int[] a`).
    *   **Const**: `const` is ignored or handled via `final` (though not strictly necessary for primitive arrays).

2.  **Specific Logic Translation**:
    *   **`main` function**: Java requires a `main` method with a `public static void main(String[] args)` signature.
    *   **`get` function**: C++ uses recursion. Java supports recursion natively. The logic remains identical, but types must be `int` and return `int`.
    *   **`put` function**: Similar to `get`, this is a recursive update function. Note that Java arrays are objects, so passing them or updating them works similarly to C++ references in this context (since arrays are objects passed by reference).
    *   **`#ifdef LOCAL`**: Java doesn't have preprocessor directives. This logic needs to be converted to an `if` statement checking for a system property or a flag. Since the provided code uses `c.in`, I will assume a simple `BufferedReader` reading from `c.in` if a specific property is set or just standard `System.in` for the general case, but to be safe and functional, I will implement the standard input reading logic (from `c.in` if specified, otherwise `System.in`) or just standard `System.in` if the flag isn't strictly required for the solution to work. I will implement the standard `BufferedReader` reading from `c.in` to match the C++ intent, assuming the file exists or handling standard input if not. *Correction*: To make the code runnable without specific file setup, I will switch to standard `System.in` reading but keep the structure. However, to be faithful to the C++ code which expects `c.in`, I will add a check or simply use standard `System.in` for the "else" block which is the default execution.
    *   **`qs` vector**: `vector<int> qs[maxn]` becomes `ArrayList<Integer>[] qs`. Java does not support generic arrays directly, so we must suppress the unchecked warning or use a raw type.
    *   **`reverse`**: `Collections.reverse()` requires an `ArrayList`.
    *   **`all(x)`**: Since `qs[i]` is an `ArrayList`, we iterate over it.

3.  **Incremental Tasks**:
    *   Step 1: Define constants and arrays (`a`, `t`, `pos`, `qs`, `ans`).
    *   Step 2: Implement `get` and `put` helper methods.
    *   Step 3: Implement `main` method with I/O.
    *   Step 4: Integrate logic (looping, `get`, `put`, `reverse`).

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.List;

public class c_786 {

    // Constants
    static final int maxn = 200100;
    static final int base = 1 << 17;
    
    // Global Arrays/Lists
    static int[] a = new int[maxn];
    static int[] t = new int[base * 2];
    static int[] ans = new int[maxn];
    static ArrayList<Integer>[] pos = new ArrayList[maxn];
    static ArrayList<Integer>[] qs = new ArrayList[maxn];

    // Initialize lists in pos and qs
    static {
        for (int i = 0; i < maxn; i++) {
            pos[i] = new ArrayList<>();
            qs[i] = new ArrayList<>();
        }
    }

    // Helper function get
    // Logic: Recursive descent to find the position in the segment tree
    static int get(int x, int v, int cl, int cr) {
        if (x >= t[v])
            return cr;
        if (cl + 1 == cr)
            return cl;
        int cc = (cl + cr) / 2;
        if (x >= t[v * 2])
            return get(x - t[v * 2], v * 2 + 1, cc, cr);
        else
            return get(x, v * 2, cl, cc);
    }

    // Helper function put
    // Logic: Update segment tree
    static void put(int v, int val) {
        v += base;
        t[v] = val;
        while (v > 1) {
            v >>= 1;
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    public static void main(String[] args) throws IOException {
        // C++ code uses #ifdef LOCAL to read from c.in.
        // Since we cannot use preprocessor directives in Java, 
        // we will implement a standard fast I/O.
        // If the user intended to use c.in, they should rename the file to c.in 
        // or pass a property. For standard execution, we read from System.in.
        
        // To mimic the C++ behavior exactly, we check if the file "c.in" exists 
        // or simply use System.in. To make it strictly compatible with the provided C++ logic 
        // without external dependencies, we will use System.in (equivalent to the #else branch).
        // If the local environment expects c.in, the user can manually redirect input.
        
        // Using BufferedReader for fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        StringTokenizer st = new StringTokenizer("");

        try {
            // Read n
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) return;
                st = new StringTokenizer(line);
            }
            int n = Integer.parseInt(st.nextToken());

            // Read array a
            for (int i = 0; i < n; i++) {
                while (!st.hasMoreTokens()) {
                    String line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
                a[i] = Integer.parseInt(st.nextToken());
                a[i]--; // --a[i]
                pos[a[i]].add(i);
            }

            // Reverse pos[i]
            for (int i = 0; i < n; i++) {
                Collections.reverse(pos[i]);
                if (!pos[i].isEmpty()) {
                    t[pos[i].get(pos[i].size() - 1) + base]++;
                }
            }

            // Build initial segment tree
            for (int i = base - 1; i > 0; i--)
                t[i] = t[i * 2] + t[i * 2 + 1];

            // Initialize qs[0]
            for (int i = 0; i < n; i++) {
                qs[0].add(i + 1);
            }

            // Main Logic Loop
            for (int i = 0; i < n; i++) {
                // Process queries
                for (int k : qs[i]) {
                    int to = get(k);
                    ans[k]++;
                    if (to < n)
                        qs[to].add(k);
                }
                qs[i].clear();

                // Update segment tree
                put(i, 0);
                int x = a[i];
                pos[x].remove(pos[x].size() - 1);
                if (!pos[x].isEmpty()) {
                    put(pos[x].get(pos[x].size() - 1), 1);
                }
            }

            // Output results
            for (int i = 1; i <= n; i++)
                out.print(ans[i] + " ");
            out.println();

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.flush();
            out.close();
            br.close();
        }
    }
}
```

```java
<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.List;

public class c_786 {

    // Constants
    static final int maxn = 200100;
    static final int base = 1 << 17;
    
    // Global Arrays/Lists
    static int[] a = new int[maxn];
    static int[] t = new int[base * 2];
    static int[] ans = new int[maxn];
    static ArrayList<Integer>[] pos = new ArrayList[maxn];
    static ArrayList<Integer>[] qs = new ArrayList[maxn];

    // Initialize lists in pos and qs
    static {
        for (int i = 0; i < maxn; i++) {
            pos[i] = new ArrayList<>();
            qs[i] = new ArrayList<>();
        }
    }

    // Helper function get
    // Logic: Recursive descent to find the position in the segment tree
    static int get(int x, int v, int cl, int cr) {
        if (x >= t[v])
            return cr;
        if (cl + 1 == cr)
            return cl;
        int cc = (cl + cr) / 2;
        if (x >= t[v * 2])
            return get(x - t[v * 2], v * 2 + 1, cc, cr);
        else
            return get(x, v * 2, cl, cc);
    }

    // Helper function put
    // Logic: Update segment tree
    static void put(int v, int val) {
        v += base;
        t[v] = val;
        while (v > 1) {
            v >>= 1;
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    public static void main(String[] args) throws IOException {
        // C++ code uses #ifdef LOCAL to read from c.in.
        // Since we cannot use preprocessor directives in Java, 
        // we will implement a standard fast I/O.
        // If the user intended to use c.in, they should rename the file to c.in 
        // or pass a property. For standard execution, we read from System.in.
        
        // Using BufferedReader for fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        StringTokenizer st = new StringTokenizer("");

        try {
            // Read n
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) return;
                st = new StringTokenizer(line);
            }
            int n = Integer.parseInt(st.nextToken());

            // Read array a
            for (int i = 0; i < n; i++) {
                while (!st.hasMoreTokens()) {
                    String line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
                a[i] = Integer.parseInt(st.nextToken());
                a[i]--; // --a[i]
                pos[a[i]].add(i);
            }

            // Reverse pos[i]
            for (int i = 0; i < n; i++) {
                Collections.reverse(pos[i]);
                if (!pos[i].isEmpty()) {
                    t[pos[i].get(pos[i].size() - 1) + base]++;
                }
            }

            // Build initial segment tree
            for (int i = base - 1; i > 0; i--)
                t[i] = t[i * 2] + t[i * 2 + 1];

            // Initialize qs[0]
            for (int i = 0; i < n; i++) {
                qs[0].add(i + 1);
            }

            // Main Logic Loop
            for (int i = 0; i < n; i++) {
                // Process queries
                for (int k : qs[i]) {
                    int to = get(k);
                    ans[k]++;
                    if (to < n)
                        qs[to].add(k);
                }
                qs[i].clear();

                // Update segment tree
                put(i, 0);
                int x = a[i];
                pos[x].remove(pos[x].size() - 1);
                if (!pos[x].isEmpty()) {
                    put(pos[x].get(pos[x].size() - 1), 1);
                }
            }

            // Output results
            for (int i = 1; i <= n; i++)
                out.print(ans[i] + " ");
            out.println();

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.flush();
            out.close();
            br.close();
        }
    }
}
</CODE>
```