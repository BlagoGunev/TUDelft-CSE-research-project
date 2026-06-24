Translate this C++ code to Java code. The main class name should be f_1102. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
int main() {
    //freopen('","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0 ;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }
    int gr[n][n];
    int dp[n][1 << n][n];
    int from_to[n][n];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            gr[i][j] = 1000000000;
            from_to[i][j] = 1000000000;
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            for(int u = 0;u < (1 << n);u++) {
                dp[i][u][j] = 0;
            }
            for(int k = 0;k < m;k++) {
                gr[i][j] = min(gr[i][j],abs(a[i][k] - a[j][k]));
                if (k > 0) from_to[i][j] = min(from_to[i][j],abs(a[i][k - 1] - a[j][k]));
            }
        }
    }
    for(int i = 0;i < n;i++) {
        dp[i][1 << i][i] = 1000000000;
    }
    for(int mask = 2;mask < (1 << n);mask++) {
        for(int from = 0;from < n;from++) {
            if ((mask & (1 << from)) > 0) {
                for(int to = 0;to < n;to++) {
                    if (to != from && (mask & (1 << to)) > 0) {
                        int mx = 0;
                        for(int i = 0;i < n;i++) {
                            if (i != from && (mask & (1 << i)) > 0) mx = max(mx,min(gr[from][i],dp[i][mask - (1 << from)][to]));
                        }
                        dp[from][mask][to] = mx;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if (i != j || n == 1) ans = max(ans,min(dp[i][(1 << n) - 1][j],from_to[i][j]));
        }
    }
    cout << ans;
 }

Here is the plan for the translation and the resulting Java code.

### Translation Plan

1.  **Headers and Namespace**:
    *   C++ includes (`bits/stdc++.h`) map to Java standard libraries (`java.util.*`, `java.io.*`).
    *   `using namespace std;` is implicit in Java; we import specific classes.

2.  **Data Types**:
    *   `typedef long long ll;` in C++ becomes `long` in Java (since `long long` is at least 64-bit, and Java's `long` is 64-bit signed).
    *   `typedef vector<vector<bool>> vvb;` etc., are replaced by `int[][]` or `boolean[][]` as appropriate. Since the C++ code uses `int dp[n][1 << n][n]`, we will use `int[][][]`.

3.  **I/O Operations**:
    *   C++ `cin`/`cout` and `ios_base::sync_with_stdio(0)` are replaced by Java's `Scanner` or `BufferedReader`.
    *   To match the performance implied by `ios_base::sync_with_stdio(0)` and `cin.tie(0)`, `BufferedReader` and `StringTokenizer` are preferred over `Scanner` to avoid Time Limit Exceeded (TLE) on large inputs.
    *   `freopen` calls are commented out (as they are in the C++ source) or removed, as Java does not support file redirection in this manner.

4.  **Memory Allocation**:
    *   C++ `int a[n][m]` is a stack allocation. In Java, arrays are objects allocated on the heap. We will use `int[][] a = new int[n][m]`.
    *   Multi-dimensional arrays in C++ (`dp[n][1 << n][n]`) map to `int[][][] dp` in Java.
    *   We must manually compute the array dimensions: `1 << n` creates a bitmask of size $2^n$.

5.  **Logic Translation**:
    *   C++ `min`/`max` functions map to Java `Math.min`/`Math.max`.
    *   C++ `abs` maps to `Math.abs`.
    *   Bitwise operations (`&`, `<<`, `~`) translate directly.
    *   Loop structures (`for`, `if`) translate directly.

6.  **Incremental Tasks**:
    *   Step 1: Set up the class structure and fast I/O reader.
    *   Step 2: Translate variable declarations and input reading.
    *   Step 3: Translate the initialization of `gr` and `from_to`.
    *   Step 4: Translate the computation of `gr` and `from_to`.
    *   Step 5: Translate the initialization of `dp`.
    *   Step 6: Translate the main DP loop.
    *   Step 7: Translate the final answer calculation and output.

### Java Code

```java
import java.io.*;
import java.util.*;

public class f_1102 {
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
            if (s == null) return 0; // Should not happen based on problem logic
            return Integer.parseInt(s);
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        
        // Read n and m
        // Note: In Java, we cannot allocate int[n][m] on stack, so we use heap.
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[][] a = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        // Initialize gr and from_to
        // Java arrays are initialized to 0 by default, so we must fill them manually.
        // Using a constant for infinity
        int INF = 1000000000;
        
        int[][] gr = new int[n][n];
        int[][] from_to = new int[n][n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                gr[i][j] = INF;
                from_to[i][j] = INF;
            }
        }

        // Compute gr[i][j] and from_to[i][j]
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // gr[i][j] is min over all columns k of abs(a[i][k] - a[j][k])
                // Note: In the original C++ code, the loops for gr calculation are inside the loop for 
                // calculating from_to, or rather, they iterate k from 0 to m.
                // However, looking closely at the C++ code:
                // for(int k = 0; k < m; k++) { ... gr[i][j] = min(...) ... }
                // This calculates the minimum absolute difference across all columns for the pair (i, j).
                
                int currentDiff = 0;
                for(int k = 0; k < m; k++) {
                    int diff = Math.abs(a[i][k] - a[j][k]);
                    if(diff < currentDiff) currentDiff = diff;
                    // Optimization: if we find 0, we can stop for gr[i][j] since abs diff >= 0
                    if(currentDiff == 0) break; 
                }
                gr[i][j] = currentDiff;

                // from_to[i][j] is min over k > 0 of abs(a[i][k-1] - a[j][k])
                // This represents a specific transition cost between column k-1 and k.
                for(int k = 1; k < m; k++) {
                    int diff = Math.abs(a[i][k - 1] - a[j][k]);
                    if(diff < from_to[i][j]) from_to[i][j] = diff;
                }
            }
        }

        // Initialize DP table
        // dp[i][mask][j]
        // Dimensions: n x (1<<n) x n
        int[][][] dp = new int[n][1 << n][n];
        
        // Initialize dp with 0 (default in Java), but the logic requires specific initialization?
        // Looking at C++: dp[i][1 << i][i] = 1000000000;
        // Other entries are implicitly 0 in C++ if not touched? 
        // Actually, in C++, global/static arrays are 0. Local arrays are uninitialized (garbage).
        // The code initializes dp[i][1 << i][i] explicitly to INF.
        // It does NOT explicitly initialize other dp entries to 0 in the loop provided.
        // However, in the logic: dp[from][mask][to] = mx;
        // where mx is derived from min(gr, dp[i][mask - ...][to]).
        // If dp entries are garbage, the logic is undefined. 
        // Standard competitive programming practice: assume 0 or fill with INF if needed.
        // Let's fill the whole table with 0 first, then set the base cases to INF.
        // Actually, looking at the loop:
        // dp[from][mask][to] = mx;
        // It overwrites the value. So initialization of the rest to 0 is fine, 
        // or we can just fill the whole table with 0 (Java default) and set base cases.
        
        // Let's explicitly set base cases to INF as per C++ code
        for(int i = 0; i < n; i++) {
            dp[i][1 << i][i] = INF;
        }
        
        // The C++ code does not initialize the rest of the dp array. 
        // In Java, int arrays are 0. We assume the logic works with 0 as "unreachable" or 
        // the logic overwrites everything.
        // However, to be safe and strictly follow the C++ logic (which relies on uninitialized memory being 0 or whatever),
        // we will keep the rest as 0. 
        // But wait, if dp[i][mask][to] is 0, and we take min(gr, dp...), it might pick 0.
        // Let's check the logic:
        // int mx = 0;
        // ... mx = max(mx, min(gr, dp...));
        // dp[from][mask][to] = mx;
        // If dp[...] is 0, min(gr, 0) is 0. max(0, 0) is 0.
        // This implies the code assumes previous states are valid (0) or it's a specific property.
        // Given the constraints usually imply valid paths, and 0 is the default in Java, 
        // we will rely on Java's default initialization of 0 for the array, 
        // and only explicitly set the base cases (mask == 1<<i) to INF.
        
        // Wait, re-reading C++:
        // int dp[n][1 << n][n]; // Uninitialized garbage in local scope!
        // for(int i = 0;i < n;i++) { dp[i][1 << i][i] = 1000000000; }
        // This is risky in C++ if the compiler doesn't zero-init. 
        // But in Java, it is zero-init. So we are safe.
        
        // Main DP Loop
        for(int mask = 2; mask < (1 << n); mask++) {
            for(int from = 0; from < n; from++) {
                if ((mask & (1 << from)) > 0) {
                    for(int to = 0; to < n; to++) {
                        if (to != from && (mask & (1 << to)) > 0) {
                            int mx = 0;
                            for(int i = 0; i < n; i++) {
                                if (i != from && (mask & (1 << i)) > 0) {
                                    // Logic: mx = max(mx, min(gr[from][i], dp[i][mask - (1<<from)][to]))
                                    // In Java, we need to be careful about array bounds.
                                    // mask - (1 << from) is a valid integer.
                                    // We need to check if that sub-mask is valid?
                                    // The loop iterates i in mask.
                                    
                                    int prevMask = mask & ~(1 << from);
                                    int val = Math.min(gr[from][i], dp[i][prevMask][to]);
                                    if (val > mx) mx = val;
                                }
                            }
                            dp[from][mask][to] = mx;
                        }
                    }
                }
            }
        }

        int ans = 0;
        int fullMask = (1 << n) - 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (i != j || n == 1) {
                    int val = Math.min(dp[i][fullMask][j], from_to[i][j]);
                    if (val > ans) ans = val;
                }
            }
        }
        
        System.out.println(ans);
    }
}
```