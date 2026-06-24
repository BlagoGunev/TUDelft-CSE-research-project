Translate this C++ code to Java code. The main class name should be g_914. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cstdio>
#include <cstring>
#include <algorithm>

#define DEBUG(args...) fprintf(stderr, args)

#define FOR(i, l, r) for(int i = (l), i##_end = (r); i <= i##_end; ++i)
#define REP(i, l, r) for(int i = (l), i##_end = (r); i <  i##_end; ++i)
#define DFR(i, l, r) for(int i = (l), i##_end = (r); i >= i##_end; --i)
#define DRP(i, l, r) for(int i = (l), i##_end = (r); i >  i##_end; --i)

typedef long long LL;

template<class T>T Min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T Max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool Chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool Chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

class fast_input {
private:
 static const int SIZE = 1 << 15 | 1;
 char buf[SIZE], *front, *back;

 void Next(char &c) {
     if(front == back) back = (front = buf) + fread(buf, 1, SIZE, stdin);
  c = front == back ? (char)EOF : *front++;
 }

public :
 template<class T>void operator () (T &x) {
  char c, f = 1;
  for(Next(c); c > '9' || c < '0'; Next(c)) if(c == '-') f = -1;
  for(x = 0; c >= '0' && c <= '9'; Next(c)) x = x * 10 + c - '0';
  x *= f;
 }
 void operator () (char &c, char l = 'a', char r = 'z') {
  for(Next(c); c > r || c < l; Next(c)) ;
 }
}input;

const int SN = 1000000 + 47;
const int SX = 1 << 17 | 1;
const int MAX_BIT = 17;
const int MOD = 1000000007;
const int NI = 500000004;

const int AND = 0;
const int OR = 1;
const int XOR = 2;

int f[SX], g[SX], h[SX], s[SX];
int a[SN], fib[SX], n;
int t[SX], tt[SX];
int dp[MAX_BIT + 1][SX], sz[SX], dp2[MAX_BIT + 1][SX];

void FWT(int *, int, int);
void IFWT(int *, int, int);
int F(int);
int DF(int);

int main() {

#ifdef Cai
 freopen("s.in", "r", stdin);
#endif

 int x, y, z;

 input(n);
 FOR(i, 1, n) input(a[i]);

 fib[0] = 0, fib[1] = 1;
 REP(i, 2, SX) fib[i] = F(fib[i - 1] + fib[i - 2]);

 REP(i, 0, 1 << MAX_BIT) sz[i] = sz[i >> 1] + (i & 1);
 
 FOR(i, 1, n) ++dp[sz[a[i]]][a[i]];
 REP(i, 0, MAX_BIT + 1) FWT(dp[i], MAX_BIT, OR);
 REP(i, 0, MAX_BIT + 1) FOR(j, 0, i) REP(k, 0, 1 << MAX_BIT)
  dp2[i][k] = (dp2[i][k] + 1LL * dp[j][k] * dp[i - j][k]) % MOD;
 REP(i, 0, MAX_BIT + 1) IFWT(dp2[i], MAX_BIT, OR);
 REP(i, 0, 1 << MAX_BIT) f[i] = 1LL * dp2[sz[i]][i] * fib[i] % MOD;

 FOR(i, 1, n) g[a[i]] = F(g[a[i]] + fib[a[i]]);

 FOR(i, 1, n) ++h[a[i]];
 FWT(h, MAX_BIT, XOR);
 REP(i, 0, 1 << MAX_BIT) h[i] = 1LL * h[i] * h[i] % MOD;
 IFWT(h, MAX_BIT, XOR);
 REP(i, 0, 1 << MAX_BIT) h[i] = 1LL * h[i] * fib[i] % MOD;

 FWT(f, MAX_BIT, AND), FWT(g, MAX_BIT, AND), FWT(h, MAX_BIT, AND);
 REP(i, 0, 1 << MAX_BIT) s[i] = 1LL * f[i] * g[i] % MOD * h[i] % MOD;
 IFWT(s, MAX_BIT, AND);
 
 int ans = 0;
 for(int i = 1; i < 1 << MAX_BIT; i <<= 1) ans = F(ans + s[i]);

 printf("%d\n", ans);

 return 0;

}

void FWT(int *x, int max_bit, int opt) {
 int p, q;
 FOR(i, 1, max_bit) for(int j = 0; j < 1 << max_bit; j += 1 << i)
  REP(k, 0, 1 << i - 1) {
   p = x[j + k], q = x[j + k + (1 << i - 1)];
   if(opt == AND) 
    x[j + k] = F(p + q);
   else if(opt == OR)
    x[j + k + (1 << i - 1)] = F(p + q);
   else if(opt == XOR)
    x[j + k] = F(p + q), x[j + k + (1 << i - 1)] = DF(p - q);
  }
}

void IFWT(int *x, int max_bit, int opt) {
 int p, q;
 FOR(i, 1, max_bit) for(int j = 0; j < 1 << max_bit; j += 1 << i)
  REP(k, 0, 1 << i - 1) {
   p = x[j + k], q = x[j + k + (1 << i - 1)];
   if(opt == AND)
    x[j + k] = DF(p - q);
   else if(opt == OR)
    x[j + k + (1 << i - 1)] = DF(q - p);
   else if(opt == XOR) {
    x[j + k] = 1LL * NI * (p + q) % MOD;
    x[j + k + (1 << i - 1)] = 1LL * NI * (p - q + MOD) % MOD;
   }
  }
}

int F(int x) {
 return x >= MOD ? x - MOD : x;
}

int DF(int x) {
 return x < 0 ? x + MOD : x;
}

Here is the plan for the translation from C++ to Java.

### Translation Plan

1.  **Header and Imports**:
    *   C++ headers like `<cstdio>`, `<cstring>`, and `<algorithm>` are not needed in Java as Java has built-in I/O and utility classes.
    *   The `#define` macros for loops (`FOR`, `REP`, `DFR`, `DRP`) need to be replaced with Java `for` loops.
    *   The `#define` macros for `Min`, `Max`, `Chkmin`, `Chkmax` are not used in the provided code, so they can be ignored.
    *   The `#ifdef Cai` preprocessor directive needs to be converted to a Java `if` statement checking a static boolean flag or simply removing it if it's not needed (the code logic remains the same).

2.  **Fast Input Class (`fast_input`)**:
    *   The C++ class uses `fread` and pointers (`*front`, `*back`) for fast I/O.
    *   In Java, we can implement a similar logic using a `BufferedReader` and a `char` buffer.
    *   The `operator()` method overloading for reading integers needs to be converted to a method `nextInt()`.
    *   The logic for reading characters (skipping whitespace) needs to be preserved.

3.  **Constants and Arrays**:
    *   C++ global arrays (`f`, `g`, `h`, etc.) will be mapped to Java arrays.
    *   `const int` values remain the same.
    *   The `SZ` constant is defined as `1 << 17 | 1` which is `131072`. In Java, array sizes must be integers, which is fine.
    *   The `NI` constant is `500000004`, which is the modular inverse of 2 modulo $10^9 + 7$.

4.  **Main Logic**:
    *   The `main` function will remain the entry point.
    *   The `freopen` call will be removed (or commented out) as Java does not allow redirecting `System.in` easily in competitive programming contexts without specific stream manipulation, but usually, standard `Scanner` or `BufferedReader` is sufficient. However, to strictly follow the logic, we will use a custom `BufferedReader` implementation similar to the C++ `fast_input` to ensure performance.
    *   The `fib` array calculation and DP updates will be translated directly.

5.  **Functions (`FWT`, `IFWT`, `F`, `DF`)**:
    *   The Fast Walsh Transform functions will be converted to standard Java `void` methods.
    *   The `F` function (modulo operation) and `DF` function (subtraction with modulo) will be translated directly.

6.  **Incremental Tasks**:
    *   Step 1: Define the `FastScanner` class.
    *   Step 2: Define constants and arrays.
    *   Step 3: Implement `FWT` and `IFWT`.
    *   Step 4: Implement `F` and `DF`.
    *   Step 5: Implement `main` method.

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class g_914 {

    static final int MOD = 1000000007;
    static final int NI = 500000004;
    static final int MAX_BIT = 17;
    static final int SX = 1 << 17 | 1;
    static final int SN = 1000000 + 47;
    
    static int[] f = new int[SX];
    static int[] g = new int[SX];
    static int[] h = new int[SX];
    static int[] s = new int[SX];
    static int[] a = new int[SN];
    static int[] fib = new int[SX];
    static int[] t = new int[SX];
    static int[] tt = new int[SX];
    static int[] dp = new int[MAX_BIT + 1][SX];
    static int[] dp2 = new int[MAX_BIT + 1][SX];
    static int[] sz = new int[SX];
    
    // Constants for operations
    static final int AND = 0;
    static final int OR = 1;
    static final int XOR = 2;

    // Fast I/O
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        char[] buf;
        int bufLen;
        int front;
        int back;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            buf = new char[1 << 15 | 1];
            front = 0;
            back = 0;
        }

        private void nextChar(char c) throws IOException {
            if (front == back) {
                int len = br.read(buf);
                if (len == -1) {
                    c = (char) -1; // EOF
                    return;
                }
                front = 0;
                back = len;
            }
            c = buf[front++];
        }

        public int nextInt() throws IOException {
            int x = 0;
            boolean f = 1;
            char c = 0;
            nextChar(c);
            while (c > '9' || c < '0') {
                nextChar(c);
                if (c == '-') f = -1;
            }
            while (c >= '0' && c <= '9') {
                x = x * 10 + (c - '0');
                nextChar(c);
            }
            return x * f;
        }

        public char nextCharSkipWhitespace() throws IOException {
            char c = 0;
            while (true) {
                nextChar(c);
                if (c >= 'a' && c <= 'z') return c;
            }
        }
    }

    // FWT function
    static void FWT(int[] x, int maxBit, int opt) {
        for (int i = 1; i <= maxBit; i++) {
            int len = 1 << (i - 1);
            int block = 1 << i;
            for (int j = 0; j < block; j += block / 2) {
                for (int k = 0; k < len; k++) {
                    int p = x[j + k];
                    int q = x[j + k + len];
                    if (opt == AND) {
                        x[j + k] = F(p + q);
                    } else if (opt == OR) {
                        x[j + k + len] = F(p + q);
                    } else if (opt == XOR) {
                        x[j + k] = F(p + q);
                        x[j + k + len] = DF(p - q);
                    }
                }
            }
        }
    }

    // IFWT function
    static void IFWT(int[] x, int maxBit, int opt) {
        for (int i = 1; i <= maxBit; i++) {
            int len = 1 << (i - 1);
            int block = 1 << i;
            for (int j = 0; j < block; j += block / 2) {
                for (int k = 0; k < len; k++) {
                    int p = x[j + k];
                    int q = x[j + k + len];
                    if (opt == AND) {
                        x[j + k] = DF(p - q);
                    } else if (opt == OR) {
                        x[j + k + len] = DF(q - p);
                    } else if (opt == XOR) {
                        x[j + k] = (int) ((1L * NI * (p + q)) % MOD);
                        x[j + k + len] = (int) ((1L * NI * (p - q + MOD)) % MOD);
                    }
                }
            }
        }
    }

    // Helper functions
    static int F(int x) {
        return x >= MOD ? x - MOD : x;
    }

    static int DF(int x) {
        return x < 0 ? x + MOD : x;
    }

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        
        // Check for Cai flag if needed, though usually not strictly required for logic
        // if (System.getProperty("Cai") != null) {
        //     // Logic for file redirection if needed
        // }

        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }

        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i < SX; i++) {
            fib[i] = F(fib[i - 1] + fib[i - 2]);
        }

        for (int i = 0; i < SX; i++) {
            sz[i] = sz[i >> 1] + (i & 1);
        }

        for (int i = 1; i <= n; i++) {
            dp[sz[a[i]]][a[i]]++;
        }

        for (int i = 0; i <= MAX_BIT; i++) {
            FWT(dp[i], MAX_BIT, OR);
        }

        for (int i = 0; i <= MAX_BIT; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k < SX; k++) {
                    dp2[i][k] = (int) ((1L * dp2[i][k] + 1L * dp[j][k] * dp[i - j][k]) % MOD);
                }
            }
        }

        for (int i = 0; i <= MAX_BIT; i++) {
            IFWT(dp2[i], MAX_BIT, OR);
        }

        for (int i = 0; i < SX; i++) {
            f[i] = (int) ((1L * dp2[sz[i]][i] * fib[i]) % MOD);
        }

        for (int i = 1; i <= n; i++) {
            g[a[i]] = F(g[a[i]] + fib[a[i]]);
        }

        for (int i = 1; i <= n; i++) {
            h[a[i]]++;
        }

        FWT(h, MAX_BIT, XOR);

        for (int i = 0; i < SX; i++) {
            h[i] = (int) ((1L * h[i] * h[i]) % MOD);
        }

        IFWT(h, MAX_BIT, XOR);

        for (int i = 0; i < SX; i++) {
            h[i] = (int) ((1L * h[i] * fib[i]) % MOD);
        }

        FWT(f, MAX_BIT, AND);
        FWT(g, MAX_BIT, AND);
        FWT(h, MAX_BIT, AND);

        for (int i = 0; i < SX; i++) {
            s[i] = (int) ((1L * f[i] * g[i]) % MOD * h[i] % MOD);
        }

        IFWT(s, MAX_BIT, AND);

        int ans = 0;
        for (int i = 1; i < (1 << MAX_BIT); i <<= 1) {
            ans = F(ans + s[i]);
        }

        System.out.println(ans);
    }
}
</CODE>