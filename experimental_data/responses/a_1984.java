Translate this C++ code to Java code. The main class name should be a_1984. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (a[1] == a[n]) {printf("NO\n"); continue;}
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            if (i == 2) printf("B");
            else printf("R");
        }
        printf("\n");
    }

    return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Language Differences**:
    *   **I/O**: C++ uses `cin`/`cout` and `printf`. Java uses `Scanner` or `BufferedReader`/`PrintWriter`. Given the constraints usually implied by competitive programming (though not explicitly stated here, `MN` suggests large arrays), `BufferedReader` and `StringTokenizer` are preferred for performance over `Scanner`. The `printf` calls in C++ map directly to `System.out.println` or `PrintWriter.print`.
    *   **Data Types**: C++ uses `long long` for `int` (via `#define int ll`). In Java, we must use `long` explicitly.
    *   **Arrays**: C++ arrays are 0-indexed by default, but the logic uses 1-based indexing (`a[1]` to `a[n]`). Java arrays are 0-indexed. We need to adjust indices: `a[i]` in C++ becomes `a[i-1]` in Java.
    *   **`main` function**: C++ `main` returns `int`. Java `main` is `public static void main(String[] args)`.
    *   **Macros**: C++ macros (`#define`, `using namespace std`) are not available in Java. They must be replaced with explicit code or constants. `boost()` (optimizing I/O) is replaced by initializing `BufferedReader` and `PrintWriter`.

2.  **Incremental Tasks**:
    *   Set up the class structure and imports.
    *   Handle the `t` (test cases) loop.
    *   Implement the input reading logic inside the loop.
    *   Implement the logic: Check `a[1] == a[n]`. If true, print "NO". Else, print "YES" and the alternating pattern "BRBR...".
    *   Handle array indexing adjustments.

3.  **Code Structure**:
    *   Class `a_1984`.
    *   `BufferedReader` for input.
    *   `PrintWriter` for output.
    *   `long` for array elements (replacing `int`).
    *   Logic implementation.

Here is the Java code:

<CODE>
import java.io.*;
import java.util.StringTokenizer;

public class a_1984 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static StringTokenizer st;

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
        if (s == null) return 0; // Or throw exception
        return Integer.parseInt(s);
    }

    static long nextLong() throws IOException {
        String s = next();
        if (s == null) return 0;
        return Long.parseLong(s);
    }

    public static void main(String[] args) throws IOException {
        // boost() equivalent: I/O setup is done above
        // cin.tie(0), cin.sync_with_stdio(0) is implicit in BufferedReader/PrintWriter

        String tStr = next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);

        while (t-- > 0) {
            String nStr = next();
            if (nStr == null) break;
            int n = Integer.parseInt(nStr);

            long[] a = new long[n]; // C++ array size was MN, but we only need n elements
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }

            // C++ logic: if (a[1] == a[n])
            // Java logic: if (a[0] == a[n-1])
            if (a[0] == a[n - 1]) {
                out.println("NO");
            } else {
                out.println("YES");
                for (int i = 0; i < n; i++) {
                    // C++ logic: if (i == 2) printf("B"); else printf("R");
                    // Note: In C++ loop 'i' started at 1.
                    // If i=1 (first element), print R. If i=2 (second element), print B.
                    // In Java loop 'i' starts at 0.
                    // If i=0 (first element), print R. If i=1 (second element), print B.
                    if (i == 1) {
                        out.print("B");
                    } else {
                        out.print("R");
                    }
                }
                out.println();
            }
        }
        out.flush();
    }
}
</CODE>