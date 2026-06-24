Translate this C++ code to Java code. The main class name should be f_946. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define pi complex<ld>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
inline int read()
{
 int x = 0, f = 1; char ch = getchar();
 while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
 while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
 return x * f;
}
inline ll read1()
{
 ll x = 0, f = 1; char ch = getchar();
 while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
 while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
 return x * f;
}
const int N = 200010;
const int P = 1e9 + 7;

int dp[110][110][110];
int pw[110];
int Add(int a, int b)
{
 a += b;
 return a >= P ? a - P : a;
}

char ch[110];

int main()
{
 int n, x;
 n = read();
 x = read();
 scanf("%s", ch + 1);
 rep(i, 1, n)
  dp[ch[i] - '0'][i][i] = 1;
 pw[0] = pw[1] = 2;

 rep(i, 2, x)
 {
  pw[i] = (ll)(pw[i - 1]) * pw[i - 2] % P;
  rep(l, 1, n)
   rep(r, l, n)
   {
    dp[i][l][r] = Add((ll)(dp[i - 1][l][r]) * (r == n ? pw[i - 2] : 1) % P, (ll)(dp[i - 2][l][r]) * (l == 1 ? pw[i - 1] : 1) % P);
    rep(m, l, r - 1)
     dp[i][l][r] = Add(dp[i][l][r], (ll)(dp[i - 1][l][m]) * dp[i - 2][m + 1][r] % P);
   }
 }
 cout << dp[x][1][n] << endl;
 return 0;
}

<think>

</think>

### Translation Plan

1.  **Headers and Namespace**:
    *   Replace `#include <bits/stdc++.h>` with specific headers: `<iostream>`, `<cstdio>`, `<vector>`, `<string>`, `<utility>`, and `<complex>`.
    *   Remove `using namespace std;` and explicitly use `std::` prefixes for standard library components to avoid conflicts with custom types like `dp` or `pw`.

2.  **Macros and Constants**:
    *   **Loops**: Replace `rep` and `rrep` with standard `for` loops. This is a common practice in Java to avoid macro overhead and improve readability.
    *   **Types**: Replace C++ specific type aliases (`ll`, `ull`, `db`, `ld`, `vi`, `pii`, `pi`) with Java equivalents (`long`, `double`, `long double` is not native but `BigDecimal` or `double` can be used; here `double` suffices for logic, `long` for integers).
    *   **Vectors/Pairs**: Remove `pb`, `mp`, `sz`, `ALL`. Use `ArrayList` or `StringBuilder` where appropriate. Pairs are replaced by custom classes or arrays/tuples logic.
    *   **Constants**: Keep `N` and `P` as static final constants.

3.  **Input/Output**:
    *   Replace the custom `read()` and `read1()` functions with a standard `Scanner` or a custom `BufferedReader` based fast I/O class. Given the constraints implied by competitive programming (N=200010), a `BufferedReader` + `StringTokenizer` implementation is preferred for performance over `Scanner`.
    *   Replace `scanf` and `cout` with `BufferedReader` and `PrintWriter` / `System.out`.

4.  **Logic Conversion (DP and Math)**:
    *   **Global Arrays**: C++ global arrays are translated to Java static arrays or instance variables. Since `dp` is accessed in `main`, it will be a static member of the class.
    *   **Add Function**: The modular addition function `Add` is converted to a standard Java method `add(a, b)`.
    *   **Complex Types**: `complex<ld>` is not directly available in standard Java without external libraries. Since the code uses `pi` only for definition but doesn't seem to perform complex arithmetic operations on it in the provided snippet (it's used in `#define`), we can remove the unused definition or keep it as a placeholder if strictly needed for compilation, but logically it's not used in the `main` logic shown.
    *   **Bitwise Shifts**: `ls` and `rs` macros (`rt << 1`) are removed as the segment tree logic isn't explicitly expanded in the provided snippet, but if `rt` were used elsewhere, it would need a method or variable. In this specific snippet, `ls` and `rs` are defined but `rt` is not used in `main`. They can be safely removed or kept as unused constants.
    *   **String Handling**: `scanf("%s", ch + 1)` is replaced by reading a string line and adjusting indices.

5.  **Class Structure**:
    *   Create a class `f_946`.
    *   Move global variables (`dp`, `pw`, `ch`) to static fields.
    *   Move `Add` function to a static method.
    *   Implement the `main` logic inside the `main` method.

### Incremental Tasks
1.  Define the Java class `f_946` and static fields.
2.  Implement the Fast I/O helper class/method to replace `read()` and `scanf`.
3.  Translate the `Add` function.
4.  Translate the `main` method logic, adapting loops and array accesses.
5.  Ensure all C++ specific syntax (semicolons, braces, types) is corrected to Java syntax.

### Code Translation

<CODE>
import java.io.*;
import java.util.*;

public class f_946 {
    // Constants
    static final int N = 200010;
    static final int P = 1000000007;
    static final double EPS = 1e-8;

    // DP Array: dp[i][l][r]
    static int[][][] dp = new int[110][110][110];
    // Power Array: pw[i]
    static int[] pw = new int[110];

    // Character array equivalent (using String for simplicity in Java, mapped to int)
    static int[] ch = new int[110];

    // Fast I/O
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            if (st == null || !st.hasMoreElements()) {
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

    // Modular Addition
    static int add(int a, int b) {
        a += b;
        if (a >= P) {
            return a - P;
        }
        return a;
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();

        // Read n and x
        int n = sc.nextInt();
        int x = sc.nextInt();

        // Read string ch. In C++, ch[1] starts the string. In Java, we store 1-based indexing logic.
        // We read the string token and fill ch from index 1.
        String s = sc.next();
        for (int i = 0; i < s.length(); i++) {
            ch[i + 1] = s.charAt(i) - '0';
        }

        // Initialize DP base cases
        for (int i = 1; i <= n; i++) {
            dp[ch[i]][i][i] = 1;
        }

        // Initialize power array
        pw[0] = 2;
        pw[1] = 2;

        // Compute DP
        for (int i = 2; i <= x; i++) {
            // Calculate pw[i]
            // pw[i] = pw[i-1] * pw[i-2] % P
            long val = (long) pw[i - 1] * pw[i - 2] % P;
            pw[i] = (int) val;

            // Iterate over all ranges [l, r]
            for (int l = 1; l <= n; l++) {
                for (int r = l; r <= n; r++) {
                    // Base term for dp[i][l][r]
                    // Add (dp[i-1][l][r] * (r == n ? pw[i-2] : 1))
                    long term1 = (long) dp[i - 1][l][r];
                    if (r == n) {
                        term1 = (term1 * pw[i - 2]) % P;
                    } else {
                        term1 = (term1 * 1) % P;
                    }
                    
                    // Add (dp[i-2][l][r] * (l == 1 ? pw[i-1] : 1))
                    long term2 = (long) dp[i - 2][l][r];
                    if (l == 1) {
                        term2 = (term2 * pw[i - 1]) % P;
                    } else {
                        term2 = (term2 * 1) % P;
                    }

                    dp[i][l][r] = add((int) term1, (int) term2);

                    // Iterate over split point m
                    for (int m = l; m < r; m++) {
                        long termSplit = (long) dp[i - 1][l][m] * dp[i - 2][m + 1][r] % P;
                        dp[i][l][r] = add(dp[i][l][r], (int) termSplit);
                    }
                }
            }
        }

        // Output result
        System.out.println(dp[x][1][n]);
    }
}
</CODE>