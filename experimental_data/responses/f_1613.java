Translate this C++ code to Java code. The main class name should be f_1613. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

namespace FFT {

const int LN = 21;
const int N = 1 << LN;

const int MOD = 998244353;
const int PRIMITIVE_ROOT = 3;

int root[N];

void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, (MOD-1) >> LN);
  root[0] = 1;
  for (int i = 1; i < N; ++i) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}

// n is the length of polynom
void fft(int n, vector<int> &a, bool invert) {
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = (invert ? root[N - N/len] : root[N/len]);
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len >> 1; ++j) {
        int u = a[i + j], v = 1LL * a[i + j + len/2] * w % MOD;

        a[i + j] = (u + v) % MOD;
        a[i + j + len/2] = (u - v + MOD) % MOD;
        w = 1LL * w * wlen % MOD;
      }
    }
  }

  if (invert) {
    int inv = power(n, MOD-2);
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * inv % MOD;
  }
}

}

vector<int> multiply_small(vector<int> a, vector<int> b) {
  vector<int> c(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      c[i+j] = (1LL * a[i] * b[j] + c[i+j]) % MOD;
    }
  }
  return c;
}

vector<int> multiply_large(vector<int> a, vector<int> b) {
  int deg = a.size() + b.size() - 2;
  int len = (deg == 0 ? 1 : 1 << (32 - __builtin_clz(deg)));
  a.resize(len); b.resize(len);
  FFT::fft(len, a, false); FFT::fft(len, b, false);
  a.resize(len);
  for (int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % MOD; 
  FFT::fft(len, a, true);
  a.resize(deg + 1);
  return a;
}

vector<int> operator * (vector<int> a, vector<int> b) {
  if (1LL * a.size() * b.size() <= 5000) return multiply_small(a, b);
  return multiply_large(a, b);
}

using Poly = vector<int>;

const int N = 250005;

int n;

vector<int> adj[N];
int child[N];
void dfs(int u, int p=-1) {
  for (int v : adj[u]) {
    if (v == p) continue;
    ++child[u];
    dfs(v, u);
  }
}

int fact[N];
int ifact[N];
int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * ifact[k] * ifact[n - k] % MOD * fact[n] % MOD;
}

void init() {
  FFT::init_fft();
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[N - 1] = power(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
}

int main() {
  init();

  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, 0);

  vector<int> cnt(n + 1);
  for (int i = 0; i < n; ++i) {
    ++cnt[child[i]];
  }

  Poly p = {1};
  for (int i = n; i > 0; --i) {
    if (cnt[i] == 0) continue;
    Poly q(cnt[i] + 1);
    for (int j = 0; j <= cnt[i]; ++j) q[j] = 1LL * C(cnt[i], j) * power(i, j) % MOD;
    p = p * q;
  }

  int ans = 0;
  for (int i = 0; i < p.size(); ++i) {
    int add = 1LL * p[i] * fact[n - i] % MOD;
    if (i & 1) ans = (ans - add + MOD) % MOD;
    else ans = (ans + add) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}

Here is the plan for translating the C++ code to Java:

### Translation Plan

1.  **Namespace and Class Structure**:
    *   The C++ code uses a `namespace FFT`. In Java, this corresponds to a separate inner class `FFT` inside the main class `f_1613`.
    *   Global variables like `MOD`, `N`, `root`, `fact`, `ifact` and `adj` are moved to static members of the main class or the `FFT` class as appropriate.

2.  **Templates and Generics**:
    *   The C++ `vector` is mapped to Java's `ArrayList` or `int[]`. Since the size is dynamic and we perform resizing (`resize`), `ArrayList<Integer>` is the most direct translation, though `int[]` is more performant. However, to keep the logic identical to the C++ code (which uses `vector`), `ArrayList<Integer>` is safer for direct mapping, especially for the `multiply` functions which return new vectors.
    *   Note: C++ `vector` allows `operator*`, which is custom overloaded in the code. In Java, this becomes a static method `multiply`.

3.  **Specific C++ Features**:
    *   `__builtin_clz`: This is a GCC specific intrinsic that counts leading zeros. In Java, this can be calculated using `Integer.numberOfLeadingZeros`.
    *   `scanf`/`printf`: Replaced by `java.util.Scanner` or `java.io.BufferedReader` + `java.util.StringTokenizer`. `Scanner` is easier to read and sufficient for competitive programming unless I/O is extremely tight. Given the complexity of the algorithm (FFT), `BufferedReader` is preferred for performance.
    *   `swap`: Replaced by standard array swapping or `Collections.swap`.
    *   `1LL`: Replaced by `1L` (long literal).
    *   `vector` resizing: Handled by creating a new list or resizing an existing one.
    *   `1 << LN`: `1 << 21` is `2097152`.
    *   `__builtin_clz(deg)`: If `deg` is 0, `clz` returns 32. The logic `1 << (32 - clz)` works for powers of 2. We need to ensure we handle the `deg == 0` case explicitly as done in C++.

4.  **Algorithm Logic**:
    *   **FFT**: The logic remains the same, but we must ensure modulo arithmetic is handled correctly with `long` to prevent overflow before modulo.
    *   **Combinatorics**: Factorials and inverse factorials are calculated similarly. Modular inverse uses Fermat's Little Theorem (`power(base, MOD-2)`).
    *   **DFS**: Standard recursive DFS. Java handles recursion depth, but for $N=250005$, it might hit the default stack limit. However, we will stick to the recursive structure as requested, as iterative DFS changes the logic significantly.
    *   **Main Logic**: The polynomial multiplication and the final summation loop are direct translations.

5.  **Incremental Tasks**:
    *   Step 1: Define constants and main class structure.
    *   Step 2: Implement `power` function.
    *   Step 3: Implement `FFT` class (`init_fft`, `fft`).
    *   Step 4: Implement polynomial multiplication (`multiply_small`, `multiply_large`).
    *   Step 5: Implement combinatorial helpers (`C`, `init`).
    *   Step 6: Implement `dfs` and `main` method.
    *   Step 7: Wire everything together in `main`.

### Java Code

```java
import java.io.*;
import java.util.*;

public class f_1613 {
    static final int MOD = 998244353;
    static final int LN = 21;
    static final int N = 1 << LN; // 2^21 = 2097152

    // FFT Namespace equivalent
    static class FFT {
        static int[] root = new int[N];
        static int[] fact;
        static int[] ifact;

        public static void initFFT() {
            int UNITY = power(3, (MOD - 1) >> LN);
            root[0] = 1;
            for (int i = 1; i < N; ++i) {
                root[i] = (int) ((1L * UNITY * root[i - 1]) % MOD);
            }
        }

        // n is the length of polynomial
        public static void fft(int n, int[] a, boolean invert) {
            // Bit reversal
            for (int i = 1, j = 0; i < n; ++i) {
                int bit = n >> 1;
                for (; j & bit; bit >>= 1) j ^= bit;
                j ^= bit;
                if (i < j) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }

            // Butterfly operations
            for (int len = 2; len <= n; len <<= 1) {
                int wlen = (invert ? root[N - n / len] : root[n / len]);
                for (int i = 0; i < n; i += len) {
                    int w = 1;
                    for (int j = 0; j < len >> 1; ++j) {
                        int u = a[i + j];
                        int v = (int) ((1L * a[i + j + len / 2] * w) % MOD);

                        a[i + j] = (u + v) % MOD;
                        a[i + j + len / 2] = (u - v + MOD) % MOD;
                        w = (int) ((1L * w * wlen) % MOD);
                    }
                }
            }

            if (invert) {
                int inv = power(n, MOD - 2);
                for (int i = 0; i < n; ++i) {
                    a[i] = (int) ((1L * a[i] * inv) % MOD);
                }
            }
        }
    }

    // Helper to calculate power
    static int power(int x, int y) {
        long ret = 1;
        long base = x;
        while (y > 0) {
            if ((y & 1) == 1) ret = (ret * base) % MOD;
            base = (base * base) % MOD;
            y >>= 1;
        }
        return (int) ret;
    }

    // Multiply small polynomials (Naive O(N^2))
    static ArrayList<Integer> multiply_small(ArrayList<Integer> a, ArrayList<Integer> b) {
        ArrayList<Integer> c = new ArrayList<>(a.size() + b.size() - 1);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                c.set(i + j, (int) ((1L * a.get(i) * b.get(j)) % MOD + c.get(i + j)) % MOD);
            }
        }
        return c;
    }

    // Multiply large polynomials (FFT O(N log N))
    static ArrayList<Integer> multiply_large(ArrayList<Integer> a, ArrayList<Integer> b) {
        int deg = a.size() + b.size() - 2;
        int len = (deg == 0 ? 1 : 1 << (32 - Integer.numberOfLeadingZeros(deg)));
        
        // Resize logic in C++ was: a.resize(len); b.resize(len);
        // In Java ArrayList, we create new lists or ensure they are large enough.
        // The original C++ code reuses the same lists. To be safe and simple,
        // we create new lists of size 'len' filled with 0.
        // However, to strictly follow the C++ logic of reusing memory (if it were a vector),
        // we would just ensure capacity. But since we return a new vector in Java
        // (or modify existing and return), let's create a new buffer to be safe 
        // and avoid side effects, then copy. 
        // Wait, looking at C++: a.resize(len); b.resize(len); modifies the passed vectors.
        // Then it returns 'a' after modification.
        // To replicate this exactly:
        
        // Create new lists to hold the padded values
        ArrayList<Integer> aPad = new ArrayList<>(len);
        ArrayList<Integer> bPad = new ArrayList<>(len);
        
        for(int i=0; i<a.size(); i++) aPad.set(i, a.get(i));
        for(int i=0; i<b.size(); i++) bPad.set(i, b.get(i));
        
        // Fill rest with 0 (ArrayList default is null, need to handle or assume 0)
        // C++ vector default constructor fills with 0.
        // We must fill the rest with 0 explicitly.
        for(int i=aPad.size(); i<len; i++) aPad.set(i, 0);
        for(int i=bPad.size(); i<len; i++) bPad.set(i, 0);

        FFT.fft(len, aPad, false);
        FFT.fft(len, bPad, false);
        
        // Point-wise multiplication
        for (int i = 0; i < len; ++i) {
            aPad.set(i, (int) ((1L * aPad.get(i) * bPad.get(i)) % MOD));
        }
        
        FFT.fft(len, aPad, true);
        
        // Resize to degree + 1
        ArrayList<Integer> res = new ArrayList<>(deg + 1);
        for (int i = 0; i <= deg; ++i) res.add(aPad.get(i));
        
        return res;
    }

    // Operator overloading equivalent
    static ArrayList<Integer> operatorMultiply(ArrayList<Integer> a, ArrayList<Integer> b) {
        if (1L * a.size() * b.size() <= 5000) return multiply_small(a, b);
        return multiply_large(a, b);
    }

    // Precomputed factorials
    static final int MAX_N = 250005;
    static int[] fact = new int[MAX_N];
    static int[] ifact = new int[MAX_N];

    static void init() {
        FFT.initFFT();
        fact[0] = 1;
        for (int i = 1; i < MAX_N; ++i) fact[i] = (int) ((1L * fact[i - 1] * i) % MOD);
        
        ifact[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2);
        for (int i = MAX_N - 2; i >= 0; --i) ifact[i] = (int) ((1L * ifact[i + 1] * (i + 1)) % MOD);
    }

    static int C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return (int) ((1L * ifact[k] * ifact[n - k]) % MOD * fact[n] % MOD);
    }

    // Adjacency list
    static ArrayList<Integer>[] adj;
    static int[] child;
    static int n;

    static void dfs(int u, int p) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u].get(i);
            if (v == p) continue;
            child[u]++;
            dfs(v, u);
        }
    }

    public static void main(String[] args) throws IOException {
        init();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n + 1];
        child = new int[n + 1];
        for (int i = 0; i <= n; ++i) adj[i] = new ArrayList<>();

        for (int i = 1; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            --u; --v; // 0-indexed

            adj[u].add(v);
            adj[v].add(u);
        }

        dfs(0, 0);

        int[] cnt = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            cnt[child[i]]++;
        }

        // Using ArrayList for Poly
        ArrayList<Integer> p = new ArrayList<>();
        p.add(1);

        for (int i = n; i > 0; --i) {
            if (cnt[i] == 0) continue;
            ArrayList<Integer> q = new ArrayList<>(cnt[i] + 1);
            // q[j] = C(cnt[i], j) * i^j
            for (int j = 0; j <= cnt[i]; ++j) {
                long val = (1L * C(cnt[i], j) * power(i, j)) % MOD;
                q.add((int) val);
            }
            p = operatorMultiply(p, q);
        }

        long ans = 0;
        for (int i = 0; i < p.size(); ++i) {
            long add = (1L * p.get(i) * fact[n - i]) % MOD;
            if ((i & 1) == 1) {
                ans = (ans - add + MOD) % MOD;
            } else {
                ans = (ans + add) % MOD;
            }
        }

        System.out.println(ans);
    }
}
```

```java
<CODE>
import java.io.*;
import java.util.*;

public class f_1613 {
    static final int MOD = 998244353;
    static final int LN = 21;
    static final int N = 1 << LN; // 2^21 = 2097152

    // FFT Namespace equivalent
    static class FFT {
        static int[] root = new int[N];
        static int[] fact;
        static int[] ifact;

        public static void initFFT() {
            int UNITY = power(3, (MOD - 1) >> LN);
            root[0] = 1;
            for (int i = 1; i < N; ++i) {
                root[i] = (int) ((1L * UNITY * root[i - 1]) % MOD);
            }
        }

        // n is the length of polynomial
        public static void fft(int n, int[] a, boolean invert) {
            // Bit reversal
            for (int i = 1, j = 0; i < n; ++i) {
                int bit = n >> 1;
                for (; j & bit; bit >>= 1) j ^= bit;
                j ^= bit;
                if (i < j) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }

            // Butterfly operations
            for (int len = 2; len <= n; len <<= 1) {
                int wlen = (invert ? root[N - n / len] : root[n / len]);
                for (int i = 0; i < n; i += len) {
                    int w = 1;
                    for (int j = 0; j < len >> 1; ++j) {
                        int u = a[i + j];
                        int v = (int) ((1L * a[i + j + len / 2] * w) % MOD);

                        a[i + j] = (u + v) % MOD;
                        a[i + j + len / 2] = (u - v + MOD) % MOD;
                        w = (int) ((1L * w * wlen) % MOD);
                    }
                }
            }

            if (invert) {
                int inv = power(n, MOD - 2);
                for (int i = 0; i < n; ++i) {
                    a[i] = (int) ((1L * a[i] * inv) % MOD);
                }
            }
        }
    }

    // Helper to calculate power
    static int power(int x, int y) {
        long ret = 1;
        long base = x;
        while (y > 0) {
            if ((y & 1) == 1) ret = (ret * base) % MOD;
            base = (base * base) % MOD;
            y >>= 1;
        }
        return (int) ret;
    }

    // Multiply small polynomials (Naive O(N^2))
    static ArrayList<Integer> multiply_small(ArrayList<Integer> a, ArrayList<Integer> b) {
        ArrayList<Integer> c = new ArrayList<>(a.size() + b.size() - 1);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                c.set(i + j, (int) ((1L * a.get(i) * b.get(j)) % MOD + c.get(i + j)) % MOD);
            }
        }
        return c;
    }

    // Multiply large polynomials (FFT O(N log N))
    static ArrayList<Integer> multiply_large(ArrayList<Integer> a, ArrayList<Integer> b) {
        int deg = a.size() + b.size() - 2;
        // __builtin_clz(deg) counts leading zeros. 
        // In Java, Integer.numberOfLeadingZeros(0) returns 32.
        // The formula 1 << (32 - clz) gives the next power of 2 >= deg.
        // If deg=0, clz=32, result=1.
        // If deg=1, clz=31, result=2.
        // If deg=2, clz=30, result=4.
        // This logic holds for powers of 2.
        int len = (deg == 0 ? 1 : 1 << (32 - Integer.numberOfLeadingZeros(deg)));
        
        // Resize logic in C++ was: a.resize(len); b.resize(len);
        // In Java ArrayList, we create new lists to avoid modifying input lists 
        // and to handle the "resize" (filling with 0).
        ArrayList<Integer> aPad = new ArrayList<>(len);
        ArrayList<Integer> bPad = new ArrayList<>(len);
        
        for(int i=0; i<a.size(); i++) aPad.set(i, a.get(i));
        for(int i=0; i<b.size(); i++) bPad.set(i, b.get(i));
        
        // Fill rest with 0
        for(int i=aPad.size(); i<len; i++) aPad.set(i, 0);
        for(int i=bPad.size(); i<len; i++) bPad.set(i, 0);

        FFT.fft(len, aPad, false);
        FFT.fft(len, bPad, false);
        
        // Point-wise multiplication
        for (int i = 0; i < len; ++i) {
            aPad.set(i, (int) ((1L * aPad.get(i) * bPad.get(i)) % MOD));
        }
        
        FFT.fft(len, aPad, true);
        
        // Resize to degree + 1
        ArrayList<Integer> res = new ArrayList<>(deg + 1);
        for (int i = 0; i <= deg; ++i) res.add(aPad.get(i));
        
        return res;
    }

    // Operator overloading equivalent
    static ArrayList<Integer> operatorMultiply(ArrayList<Integer> a, ArrayList<Integer> b) {
        if (1L * a.size() * b.size() <= 5000) return multiply_small(a, b);
        return multiply_large(a, b);
    }

    // Precomputed factorials
    static final int MAX_N = 250005;
    static int[] fact = new int[MAX_N];
    static int[] ifact = new int[MAX_N];

    static void init() {
        FFT.initFFT();
        fact[0] = 1;
        for (int i = 1; i < MAX_N; ++i) fact[i] = (int) ((1L * fact[i - 1] * i) % MOD);
        
        ifact[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2);
        for (int i = MAX_N - 2; i >= 0; --i) ifact[i] = (int) ((1L * ifact[i + 1] * (i + 1)) % MOD);
    }

    static int C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return (int) ((1L * ifact[k] * ifact[n - k]) % MOD * fact[n] % MOD);
    }

    // Adjacency list
    static ArrayList<Integer>[] adj;
    static int[] child;
    static int n;

    static void dfs(int u, int p) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u].get(i);
            if (v == p) continue;
            child[u]++;
            dfs(v, u);
        }
    }

    public static void main(String[] args) throws IOException {
        init();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n + 1];
        child = new int[n + 1];
        for (int i = 0; i <= n; ++i) adj[i] = new ArrayList<>();

        for (int i = 1; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            --u; --v; // 0-indexed

            adj[u].add(v);
            adj[v].add(u);
        }

        dfs(0, 0);

        int[] cnt = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            cnt[child[i]]++;
        }

        // Using ArrayList for Poly
        ArrayList<Integer> p = new ArrayList<>();
        p.add(1);

        for (int i = n; i > 0; --i) {
            if (cnt[i] == 0) continue;
            ArrayList<Integer> q = new ArrayList<>(cnt[i] + 1);
            // q[j] = C(cnt[i], j) * i^j
            for (int j = 0; j <= cnt[i]; ++j) {
                long val = (1L * C(cnt[i], j) * power(i, j)) % MOD;
                q.add((int) val);
            }
            p = operatorMultiply(p, q);
        }

        long ans = 0;
        for (int i = 0; i < p.size(); ++i) {
            long add = (1L * p.get(i) * fact[n - i]) % MOD;
            if ((i & 1) == 1) {
                ans = (ans - add + MOD) % MOD;
            } else {
                ans = (ans + add) % MOD;
            }
        }

        System.out.println(ans);
    }
}
</CODE>
```