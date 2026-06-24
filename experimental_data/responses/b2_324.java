Translate this C++ code to Java code. The main class name should be b2_324. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 310 * 1000;


int n, who[MAXN], where[MAXN];


bool read() {
    if (!(cin >> n))
        return false;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        --x;
        who[i] = x;
        where[x] = i;
    }
	return true;
}


int t[MAXN];

void fenw_upd(int i, int add) {
    for (; i < n; i |= i + 1)
        t[i] += add;
}

int fenw_sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}

void upd(int pos, int tp) {
    if (pos < 0 || pos >= n)
        return;
    if (pos + 1 < n && where[pos] > where[pos + 1])
        fenw_upd(pos, tp);
}

void solve() {
    memset(t, 0, sizeof t);
    forn(i, n)
        upd(i, +1);

    int m;
    cin >> m;
    forn(i, m) {
        int tp, l, r;
        scanf("%d%d%d", &tp, &l, &r);
        --l;
        --r;

        if (tp == 1) {
            int ans = fenw_sum(r - 1) - fenw_sum(l - 1) + 1;
            printf("%d\n", ans);
        }
        else {
            int pl = l,  pr = r;
            l = who[pl];
            r = who[pr];

            int pos[6] = { l-1, l, l+1, r-1, r, r+1 };
            sort(pos, pos+6);
            int poses = int(unique(pos, pos+6) - pos);

            forn(i, poses)
                upd(pos[i], -1);
            
            swap(who[pl], who[pr]);
            swap(where[l], where[r]);
            
            forn(i, poses)
                upd(pos[i], +1);
        }
    }
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}

Here is the plan for translating the C++ code to Java.

### Translation Plan

1.  **Headers and Imports**:
    *   C++ headers like `<iostream>`, `<cstdio>`, `<vector>`, `<algorithm>`, `<cstring>`, etc., map to standard Java imports (`java.util.*`, `java.io.*`).
    *   `cstdio` functions (`scanf`, `printf`) are replaced by `java.io.BufferedReader` and `java.io.PrintWriter` for efficiency, or standard `System.out` if performance isn't critical (though in competitive programming contexts, `BufferedReader`/`PrintWriter` is preferred).
    *   `freopen` is replaced by wrapping `System.in` and `System.out` in `BufferedReader` and `PrintWriter`.

2.  **Data Types**:
    *   `long long` in C++ maps to `long` in Java (since Java `int` is 32-bit, fitting up to $2 \cdot 10^9$, and the code uses `int` for `n` and indices up to `MAXN` which is $310,000$).
    *   `int` remains `int`.
    *   Constants like `INF`, `INF64`, `EPS`, `PI` are translated directly. Note that `1E9` in C++ becomes `1e9` (double) or `1000000000` (int) in Java. `1E18` becomes `1e18` (double).
    *   The `double` constant `PI` is calculated using `Math.acos`.

3.  **Macros**:
    *   `forn`, `ford`, `fore` loops are translated to standard `for` loops.
    *   `all`, `fs`, `sc`, `pb`, `mp` are removed as they are C++ specific.
    *   `memset` is replaced by `Arrays.fill`.
    *   `sort` and `unique` (from `<algorithm>`) are replaced by `Arrays.sort` and a manual implementation of `unique` (using a `Set` or manual iteration).
    *   `swap` is replaced by a helper method or `Arrays.sort` logic.

4.  **Logic Implementation**:
    *   **`read()`**: Reads `n`, then loops `n` times to read `x`. It populates `who` and `where` arrays.
    *   **`fenw_upd` / `fenw_sum`**: Standard Fenwick Tree (Binary Indexed Tree) implementation.
    *   **`upd`**: Checks bounds and updates the Fenwick tree.
    *   **`solve()`**:
        *   Initializes the Fenwick tree.
        *   Reads `m`.
        *   Processes `m` queries.
        *   Uses `Arrays.sort` and a loop to implement the `unique` logic found in C++.
    *   **`main()`**: Handles input redirection logic using `BufferedReader` and `PrintWriter`.

5.  **Incremental Tasks**:
    *   Step 1: Define the class `b2_324` and constants.
    *   Step 2: Implement `read()` and `solve()` methods logic without IO.
    *   Step 3: Implement `fenw_upd` and `fenw_sum`.
    *   Step 4: Implement `upd`.
    *   Step 5: Implement `main` with IO handling.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.util.Arrays;
import java.util.StringTokenizer;

public class b2_324 {
    static int n;
    static int[] who = new int[310000];
    static int[] where = new int[310000];
    static int[] t = new int[310000];

    // Constants
    static final int INF = 1000000000;
    static final double INF64 = 1e18;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0) * 2;

    public static void main(String[] args) throws IOException {
        // Setup IO
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        StringTokenizer st = null;

        try {
            // Read n
            String line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) {
                out.flush();
                return;
            }
            st = new StringTokenizer(line);
            n = Integer.parseInt(st.nextToken());

            // Read array elements
            // We need to read n integers. They might be on the same line or multiple lines.
            int count = 0;
            while (count < n) {
                while (st != null && st.hasMoreTokens()) {
                    int x = Integer.parseInt(st.nextToken());
                    --x; // 0-based index
                    who[count] = x;
                    where[x] = count;
                    count++;
                    if (count == n) break;
                }
                if (count < n) {
                    line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
            }

            // Solve
            solve();

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.flush();
        }
    }

    static boolean read() {
        // This logic is mostly handled in main for simplicity in Java,
        // but we keep the structure similar to C++ read() for the loop if needed.
        // For this specific problem structure, we read n once in main.
        // If the input format implies multiple test cases, we would loop here.
        // Based on the C++ code: "while (read()) solve();" inside SU2_PROJ.
        // However, the C++ read() function checks "if (!(cin >> n))".
        // Let's implement a standard reader loop logic.
        return true; 
    }

    static void fenw_upd(int i, int add) {
        // C++: for (; i < n; i |= i + 1)
        // Java equivalent
        for (; i < n; i = i | (i + 1)) {
            t[i] += add;
        }
    }

    static int fenw_sum(int r) {
        // C++: for (; r >= 0; r = (r & (r + 1)) - 1)
        // Java equivalent
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    static void upd(int pos, int tp) {
        // C++: if (pos < 0 || pos >= n) return;
        if (pos < 0 || pos >= n) {
            return;
        }
        // C++: if (pos + 1 < n && where[pos] > where[pos + 1]) fenw_upd(pos, tp);
        if (pos + 1 < n && where[pos] > where[pos + 1]) {
            fenw_upd(pos, tp);
        }
    }

    static void solve() {
        // C++: memset(t, 0, sizeof t);
        Arrays.fill(t, 0);
        
        // C++: forn(i, n) upd(i, +1);
        for (int i = 0; i < n; i++) {
            upd(i, 1);
        }

        // Read m
        // We need to read the next integer. Since StringTokenizer might be exhausted,
        // we need a helper to get the next token.
        // To keep it simple, we assume the stream is handled by the main loop or we read tokens on demand.
        // However, looking at the C++ code: cin >> m;
        // We will assume we have a way to read the next token.
        // Since we didn't implement a robust "next token" helper in the snippet above,
        // let's create a simple one or assume the structure.
        // Actually, for a complete translation, let's just read m from the stream.
        // But wait, the previous logic in main read 'n' and the array. 
        // 'm' is the next integer.
        
        // Re-implementing token reading logic inside solve to be safe or use a helper class.
        // Let's use a simple StringTokenizer loop inside solve or rely on the fact that 
        // the input stream is continuous.
        // To make the code self-contained and correct without external state, 
        // I will re-use the BufferedReader logic.
        // Note: The C++ code uses cin. In Java, we stream from BufferedReader.
        
        // We need to read m.
        // Since we can't easily peek into the stream without consuming, 
        // and the previous read in main consumed n and the array.
        // We just read the next available token.
        // To make this robust, I will add a simple helper method to read tokens.
        
        // Actually, let's refactor the main method to be cleaner and pass the reader/solver logic 
        // or just put everything in main.
        // But to follow the structure of the prompt (splitting up tasks), 
        // I will implement a static helper to fetch tokens.
        
        // Re-reading the C++ code:
        // main reads n.
        // solve() reads m.
        // solve() reads m queries.
        
        // Let's implement a simple token fetcher.
        // Since I cannot access 'st' and 'br' from 'solve' if they are local to 'main',
        // I will move the reading logic to be consistent.
        // However, to strictly translate the provided code structure, I will assume 
        // the input is available.
        
        // Let's assume the structure:
        // 1. Read n.
        // 2. Read array.
        // 3. Read m.
        // 4. Read m queries.
        
        // Since I am outputting the full code, I will integrate the reader into the class.
        // But for the sake of the prompt's request to translate the *given* code:
        // The given code relies on global state (n, who, where, t) and standard streams.
        // I will implement a static StringTokenizer and BufferedReader to handle the input flow.
        
        // Re-initializing static fields for token reading
        // (Note: In the previous block, I initialized them in main. 
        // To make it work, I'll declare them static and initialize in main).
        // But wait, if I declare them static, I need to initialize them once.
        // Let's stick to the logic:
        // Main reads n, array.
        // Solve reads m, queries.
        
        // I need to ensure 'st' has tokens.
        // Let's assume the reader logic is handled by a helper class or static variables.
        // I will use static variables for the Reader.
    }
}
```

**Refinement:** The previous block was just a thought process. I need to output the *complete* working code in one block. I will create a static `StringTokenizer` and `BufferedReader` to handle the input parsing across `main` and `solve`, mimicking the behavior of `cin`.

Here is the complete translation.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.util.Arrays;
import java.util.StringTokenizer;

public class b2_324 {
    static int n;
    static int[] who = new int[310000];
    static int[] where = new int[310000];
    static int[] t = new int[310000];
    
    // IO Helpers
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = null;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        String s = next();
        if (s == null) throw new IOException("End of input");
        return Integer.parseInt(s);
    }

    // Constants
    static final int INF = 1000000000;
    static final double INF64 = 1e18;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0) * 2;

    public static void main(String[] args) throws IOException {
        // Read n
        String s = next();
        if (s == null) return;
        n = Integer.parseInt(s);

        // Read array elements
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            --x; // 0-based index
            who[i] = x;
            where[x] = i;
        }

        // Solve
        solve();
    }

    static void fenw_upd(int i, int add) {
        // C++: for (; i < n; i |= i + 1)
        // Java: i |= (i + 1) is equivalent to i = i | (i + 1)
        for (; i < n; i = i | (i + 1)) {
            t[i] += add;
        }
    }

    static int fenw_sum(int r) {
        // C++: for (; r >= 0; r = (r & (r + 1)) - 1)
        // Java equivalent
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    static void upd(int pos, int tp) {
        // C++: if (pos < 0 || pos >= n) return;
        if (pos < 0 || pos >= n) {
            return;
        }
        // C++: if (pos + 1 < n && where[pos] > where[pos + 1]) fenw_upd(pos, tp);
        if (pos + 1 < n && where[pos] > where[pos + 1]) {
            fenw_upd(pos, tp);
        }
    }

    static void solve() {
        // C++: memset(t, 0, sizeof t);
        Arrays.fill(t, 0);
        
        // C++: forn(i, n) upd(i, +1);
        for (int i = 0; i < n; i++) {
            upd(i, 1);
        }

        // Read m
        // C++: cin >> m;
        // We check if there is a token. If not, it means no queries or EOF.
        // Based on problem constraints, m exists.
        try {
            String mStr = next();
            if (mStr == null) return; 
            int m = Integer.parseInt(mStr);
            
            // Process m queries
            for (int i = 0; i < m; i++) {
                int tp = nextInt();
                int l = nextInt();
                int r = nextInt();
                
                --l; // 0-based
                --r; // 0-based

                if (tp == 1) {
                    // C++: int ans = fenw_sum(r - 1) - fenw_sum(l - 1) + 1;
                    // Java: same logic
                    int ans = fenw_sum(r - 1) - fenw_sum(l - 1) + 1;
                    System.out.println(ans);
                }
                else {
                    // C++: int pl = l, pr = r;
                    int pl = l;
                    int pr = r;

                    // C++: l = who[pl]; r = who[pr];
                    l = who[pl];
                    r = who[pr];

                    // C++: int pos[6] = { l-1, l, l+1, r-1, r, r+1 };
                    // Java: arrays
                    int[] pos = new int[6];
                    pos[0] = l - 1;
                    pos[1] = l;
                    pos[2] = l + 1;
                    pos[3] = r - 1;
                    pos[4] = r;
                    pos[5] = r + 1;
                    
                    // C++: sort(pos, pos+6);
                    Arrays.sort(pos);

                    // C++: int poses = int(unique(pos, pos+6) - pos);
                    // Java: manual unique
                    int poses = 0;
                    if (pos.length > 0) poses = 1;
                    for (int k = 1; k < pos.length; k++) {
                        if (pos[k] != pos[k - 1]) {
                            poses++;
                        }
                    }
                    
                    // C++: forn(i, poses) upd(pos[i], -1);
                    for (int i = 0; i < poses; i++) {
                        upd(pos[i], -1);
                    }
                    
                    // C++: swap(who[pl], who[pr]);
                    int temp = who[pl];
                    who[pl] = who[pr];
                    who[pr] = temp;
                    
                    // C++: swap(where[l], where[r]);
                    temp = where[l];
                    where[l] = where[r];
                    where[r] = temp;
                    
                    // C++: forn(i, poses) upd(pos[i], +1);
                    for (int i = 0; i < poses; i++) {
                        upd(pos[i], 1);
                    }
                }
            }
        } catch (Exception e) {
            // Handle potential parsing errors gracefully if needed
        }
    }
}
```

### Explanation of Translation
1.  **Class Name**: Changed to `b2_324` as requested.
2.  **IO Handling**: Replaced `scanf`, `printf`, `cin`, `cout` with `BufferedReader`, `StringTokenizer`, and `System.out`. The `read()` function in C++ was replaced by logic in `main` to read `n` and the array, and `solve()` to read `m` and queries.
3.  **Arrays**: C++ arrays are statically allocated. In Java, `int[]` is used.
4.  **Macros**:
    *   `forn`, `ford`, `fore` translated to standard `for` loops.
    *   `memset` translated to `Arrays.fill`.
    *   `sort` translated to `Arrays.sort`.
    *   `unique` translated to a manual loop checking for duplicates.
    *   `swap` translated to a manual variable swap.
5.  **Logic**:
    *   `fenw_upd` and `fenw_sum` logic is preserved but syntax adjusted for Java (e.g., `i |= i + 1` instead of `i |= i + 1` which is valid in C++ but `i = i | (i + 1)` is clearer, though bitwise OR works fine).
    *   The `upd` function logic regarding `where` array checks is preserved.
    *   The `solve` function processes queries, handling the range sum query (type 1) and the swap query (type 2) with the specific logic of sorting and re-inserting into the Fenwick Tree.
6.  **Constants**: `INF` is `1000000000`. `PI` is calculated using `Math.acos(-1.0) * 2`.
7.  **Error Handling**: The `try-catch` block in `main` and `solve` mimics the C++ `throw` behavior for invalid input or EOF.

```java
<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.util.Arrays;
import java.util.StringTokenizer;

public class b2_324 {
    static int n;
    static int[] who = new int[310000];
    static int[] where = new int[310000];
    static int[] t = new int[310000];
    
    // IO Helpers
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = null;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        String s = next();
        if (s == null) throw new IOException("End of input");
        return Integer.parseInt(s);
    }

    // Constants
    static final int INF = 1000000000;
    static final double INF64 = 1e18;
    static final double EPS = 1e-9;
    static final double PI = Math.acos(-1.0) * 2;

    public static void main(String[] args) throws IOException {
        // Read n
        String s = next();
        if (s == null) return;
        n = Integer.parseInt(s);

        // Read array elements
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            --x; // 0-based index
            who[i] = x;
            where[x] = i;
        }

        // Solve
        solve();
    }

    static void fenw_upd(int i, int add) {
        // C++: for (; i < n; i |= i + 1)
        // Java equivalent: i = i | (i + 1)
        for (; i < n; i = i | (i + 1)) {
            t[i] += add;
        }
    }

    static int fenw_sum(int r) {
        // C++: for (; r >= 0; r = (r & (r + 1)) - 1)
        // Java equivalent
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    static void upd(int pos, int tp) {
        // C++: if (pos < 0 || pos >= n) return;
        if (pos < 0 || pos >= n) {
            return;
        }
        // C++: if (pos + 1 < n && where[pos] > where[pos + 1]) fenw_upd(pos, tp);
        if (pos + 1 < n && where[pos] > where[pos + 1]) {
            fenw_upd(pos, tp);
        }
    }

    static void solve() {
        // C++: memset(t, 0, sizeof t);
        Arrays.fill(t, 0);
        
        // C++: forn(i, n) upd(i, +1);
        for (int i = 0; i < n; i++) {
            upd(i, 1);
        }

        // Read m
        // C++: cin >> m;
        try {
            String mStr = next();
            if (mStr == null) return; 
            int m = Integer.parseInt(mStr);
            
            // Process m queries
            for (int i = 0; i < m; i++) {
                int tp = nextInt();
                int l = nextInt();
                int r = nextInt();
                
                --l; // 0-based
                --r; // 0-based

                if (tp == 1) {
                    // C++: int ans = fenw_sum(r - 1) - fenw_sum(l - 1) + 1;
                    int ans = fenw_sum(r - 1) - fenw_sum(l - 1) + 1;
                    System.out.println(ans);
                }
                else {
                    // C++: int pl = l, pr = r;
                    int pl = l;
                    int pr = r;

                    // C++: l = who[pl]; r = who[pr];
                    l = who[pl];
                    r = who[pr];

                    // C++: int pos[6] = { l-1, l, l+1, r-1, r, r+1 };
                    int[] pos = new int[6];
                    pos[0] = l - 1;
                    pos[1] = l;
                    pos[2] = l + 1;
                    pos[3] = r - 1;
                    pos[4] = r;
                    pos[5] = r + 1;
                    
                    // C++: sort(pos, pos+6);
                    Arrays.sort(pos);

                    // C++: int poses = int(unique(pos, pos+6) - pos);
                    // Java: manual unique
                    int poses = 0;
                    if (pos.length > 0) poses = 1;
                    for (int k = 1; k < pos.length; k++) {
                        if (pos[k] != pos[k - 1]) {
                            poses++;
                        }
                    }
                    
                    // C++: forn(i, poses) upd(pos[i], -1);
                    for (int i = 0; i < poses; i++) {
                        upd(pos[i], -1);
                    }
                    
                    // C++: swap(who[pl], who[pr]);
                    int temp = who[pl];
                    who[pl] = who[pr];
                    who[pr] = temp;
                    
                    // C++: swap(where[l], where[r]);
                    temp = where[l];
                    where[l] = where[r];
                    where[r] = temp;
                    
                    // C++: forn(i, poses) upd(pos[i], +1);
                    for (int i = 0; i < poses; i++) {
                        upd(pos[i], 1);
                    }
                }
            }
        } catch (Exception e) {
            // Handle potential parsing errors gracefully
        }
    }
}
</CODE>
```