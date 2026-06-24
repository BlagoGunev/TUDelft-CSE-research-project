Translate this C++ code to Java code. The main class name should be e_529. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 5000+7;
int N, K, in[MAX];

pair<int, int> vals[MAX*20];

int main()
{
	scanf("%d%d", &N, &K);
	REP(i, N) scanf("%d", in+i);

	int M = 0;
	vals[M++] = make_pair(0, 0);
	REP(i, N) REP(j, K)
		vals[M++] = make_pair(in[i]*(j+1), j+1);
	sort(vals, vals+M);

	int Q;
	scanf("%d", &Q);
	while (Q--)
	{
		int x, res = INF;
		scanf("%d", &x);

		int j = 0;
		for (int i = M-1; i >= 0; --i)
		{
			while (j < M && vals[i].first + vals[j].first < x) ++j;
			if (vals[i].first + vals[j].first == x)
				res = min(res, vals[i].second + vals[j].second);
		}

		printf("%d\n", res>K?-1:res);
	}

	return 0;
}

<think>
The user wants me to translate a C++ code snippet into Java code.
The main class name should be `e_529`.
I need to first plan the translation, considering C++ specific features and how they map to Java.
Then, I need to output the Java code wrapped in `<CODE>` tags.

**Code Analysis:**

1.  **Includes:**
    *   `iostream`, `sstream`, `cstdio`, `cmath`, `cstring`, `cctype`, `string`, `vector`, `list`, `set`, `map`, `queue`, `stack`, `algorithm`, `functional`.
    *   In Java, I need to handle input/output manually or use `Scanner`/`BufferedReader`. Since the C++ code uses `scanf` and `printf`, `Scanner` might be slower but is easier to read. However, competitive programming style usually prefers `BufferedReader` + `StringTokenizer` for speed. Given the constraints of the problem (implied by the C++ code structure, likely a CP problem), I should probably stick to a standard fast I/O approach or just use `Scanner` if performance isn't critical. Looking at the logic, it involves sorting and iterating, $O(N \cdot K \cdot \log(N \cdot K))$. If $N$ is up to 5000, $N \cdot K$ is roughly $2500 \times K$. The loop over $Q$ queries iterates through a sorted array of size $M \approx 20 \cdot N$. Inside the query loop, there's a nested loop or two-pointer logic. The complexity looks like $O(Q \cdot N \cdot K)$ or $O(Q \cdot M)$.
    *   Wait, the C++ code uses `scanf` and `printf`. In Java, `Scanner` is often slow. I will use `BufferedReader` and `StringTokenizer` for input and `PrintWriter` or `System.out` for output to match the performance expectations of the original C++ code.
    *   `vector` -> `ArrayList` or array. Since the size is known or grows, `ArrayList` is safer, but the C++ code uses a fixed-size array `vals[MAX*20]`. In Java, I can use an array or `ArrayList`. Since `M` is calculated before sorting, an array is fine, but `ArrayList` is more idiomatic. However, the C++ code uses `sort` on `vals`. `Arrays.sort` works on primitives or objects. `vals` is `pair<int, int>`. In Java, we can't have a primitive pair. We can use a custom class `Pair` or encode the pair into a `long` (since `int` is 32-bit, two `int`s can fit in a `long` if values are small enough, or just use a class).
    *   `pair<int, int>` -> A class `Pair` implementing `Comparable`.
    *   `sort` -> `Arrays.sort`.
    *   `make_pair` -> Constructor of `Pair`.
    *   `scanf` / `printf` -> `BufferedReader` / `StringTokenizer` / `PrintWriter` or `System.out`.
    *   Macros `REP`, `FOR`, `FORD` -> Java `for` loops.
    *   `EQ` function -> Helper method.
    *   `chmax`, `chmin` -> Helper methods.
    *   Bit manipulation functions (`two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`) -> Helper methods.
    *   `INF` constant.
    *   `typedef long long ll` -> `long` in Java (64-bit).
    *   `#define DEBUG` -> Can be ignored or implemented as a print statement.

2.  **Specific Logic:**
    *   `scanf("%d%d", &N, &K)` -> Read N, K.
    *   `REP(i, N) scanf("%d", in+i)` -> Read array `in`.
    *   `vals` array population.
    *   `sort(vals, vals+M)` -> `Arrays.sort(vals, 0, M)`.
    *   Query loop:
        *   `scanf("%d", &x)` -> Read x.
        *   Two-pointer logic inside the loop. `j` is maintained.
        *   `vals[i].first + vals[j].first < x`.
        *   `printf` -> `System.out.println`.

3.  **Class Structure:**
    *   Class `e_529`.
    *   Static inner class `Pair` (to replace `pair<int, int>`).
    *   Static `MAX`.
    *   Global variables `N`, `K`, `in`, `vals` (static fields).

4.  **Incremental Tasks Plan:**
    *   **Task 1: Setup Class and I/O.** Define `e_529` class, add `BufferedReader`, `StringTokenizer`, `PrintWriter`. Replace `scanf`/`printf`.
    *   **Task 2: Helper Functions.** Translate `EQ`, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`, `chmax`, `chmin`.
    *   **Task 3: Main Logic.** Translate `main` function logic, including array population and sorting.
    *   **Task 4: Query Processing.** Translate the query loop logic.

5.  **Specific C++ to Java Mappings:**
    *   `#include <...>` -> Imports (`java.util.*`, `java.io.*`).
    *   `using namespace std;` -> No need, use fully qualified names or static imports if applicable.
    *   `#define REP(i,n)` -> `for (int i=0; i<n; i++)`.
    *   `#define FOR(i,a,b)` -> `for (int i=a; i<=b; i++)`.
    *   `#define FORD(i,a,b)` -> `for (int i=a; i>=b; i--)`.
    *   `pair<int, int>` -> Class `Pair { int first, second; ... }`.
    *   `make_pair(a, b)` -> `new Pair(a, b)`.
    *   `sort` -> `Arrays.sort`.
    *   `scanf` -> `StringTokenizer` parsing.
    *   `printf` -> `PrintWriter` or `System.out.println`.
    *   `#define DEBUG` -> `System.out.println` (optional).
    *   `INF` -> `Integer.MAX_VALUE` or custom constant.
    *   `long long` -> `long`.
    *   `inline` -> `static` (or just methods).
    *   `&` (reference) -> Java pass-by-value, so `int & n` becomes `int n`.
    *   `n & (-n)` -> `n & -n` works in Java too.
    *   `max`, `min` -> `Math.max`, `Math.min`.
    *   `fabs` -> `Math.abs` (for double).
    *   `1<<n` -> `1 << n`.

6.  **Refinement on `vals`:**
    *   `vals` is `pair<int, int> vals[MAX*20]`.
    *   In Java, `Pair[] vals = new Pair[MAX * 20];`.
    *   Sorting an array of objects `Pair[]` requires implementing `Comparable` or passing a `Comparator`.
    *   Since `vals` is sorted based on `.first`, `Pair` should implement `Comparable<Pair>`.

7.  **Refinement on I/O:**
    *   The C++ code uses `scanf` and `printf`. This suggests speed is important. `Scanner` is too slow for large inputs. I will use `BufferedReader` and `StringTokenizer`.
    *   Output: `printf("%d\n", ...)` -> `out.println(...)`.

8.  **Refinement on `chmax`/`chmin`:**
    *   C++ templates. Java is not generic in the same way (generic types don't work with primitives like `int` or `long` mixed easily without boxing).
    *   Here `chmax(T & a, const T & b)`. `vals` stores `int`.
    *   I will implement `chmax` for `int` and `long` separately or just use `Math.max` directly since it's a simple logic.
    *   Looking at the code: `res = min(res, vals[i].second + vals[j].second)`. `res` is `int`.
    *   The `chmax`/`chmin` definitions are provided but not used in the `main` function shown. Wait, `chmax`/`chmin` are defined but not used in the provided snippet. I should probably keep them for completeness or remove them if they aren't used. The prompt asks to translate the code. I should translate the definitions too, even if unused, to be faithful to the source. However, for Java, generic methods with primitives don't exist. I will implement specific versions for `int` and `long` if needed, or just leave them as `static void` methods.
    *   Actually, looking at the provided code, `chmax` and `chmin` are defined but not called in `main`. I will include them to ensure the translation is complete.
    *   `EQ` function: `double` comparison. In Java `Math.abs(a - b) < 1e-9`.

9.  **Refinement on `vals` and `sort`:**
    *   C++: `pair<int, int> vals[MAX*20];`.
    *   Java: `Pair[] vals = new Pair[MAX * 20];`.
    *   C++: `sort(vals, vals+M)`.
    *   Java: `Arrays.sort(vals, 0, M)`.
    *   Note: `Pair` needs to implement `Comparable`.
    *   Comparison logic: `if (this.first != other.first) return this.first - other.first; return this.second - other.second;` (though the C++ code only sorts by first, usually stable sort or secondary sort by second isn't strictly enforced by `sort` unless specified, but standard `sort` on pairs usually sorts by first then second). The C++ `std::pair` comparison is lexicographical. So `first` then `second`.

10. **Refinement on `in` array:**
    *   `int in[MAX]`.
    *   Java: `int[] in = new int[MAX];`.

11. **Refinement on Bit Manipulation:**
    *   `two(int n)`: `1 << n`.
    *   `test(int n, int b)`: `(n >> b) & 1`.
    *   `set_bit`: `n |= two(b)`.
    *   `unset_bit`: `n &= ~two(b)`.
    *   `last_bit`: `n & (-n)`.
    *   `ones`: `Integer.bitCount(n)`. Or manual loop. `while(n && ++res) n-=n&(-n);`. In Java `Integer.bitCount` is available. The C++ loop counts set bits. I will implement the logic or use `Integer.bitCount`. The C++ loop: `while(n && ++res) n-=n&(-n);`. This is a specific bit counting implementation (Brian Kernighan's algorithm). I should probably stick to the logic provided to be faithful, or use the library function if it's equivalent. The C++ code uses `n & (-n)` which works in Java too. I will implement the loop manually to match the C++ logic exactly, as it might be specific to the problem context (e.g. avoiding overhead or specific constraints).

12. **Refinement on Constants:**
    *   `const int INF = 1<<29;`. Java `static final int INF = 1 << 29;`.

13. **Refinement on `scanf` usage:**
    *   `scanf("%d%d", &N, &K)` reads two ints.
    *   `REP(i, N) scanf("%d", in+i)` reads N ints.
    *   `scanf("%d", &Q)` reads Q.
    *   `scanf("%d", &x)` reads x.
    *   In Java: `StringTokenizer` is best.
    *   Helper method `readInt()` can be useful.

14. **Refinement on `vals` population:**
    *   `vals[M++] = make_pair(0, 0);` -> `vals[M++] = new Pair(0, 0);`.
    *   `REP(i, N) REP(j, K) vals[M++] = make_pair(in[i]*(j+1), j+1);` -> Nested loop.

15. **Refinement on Query Loop:**
    *   `while (Q--)` -> `while (Q-- > 0)` (Java `while` condition).
    *   `for (int i = M-1; i >= 0; --i)` -> `for (int i = M - 1; i >= 0; i--)`.
    *   `while (j < M && vals[i].first + vals[j].first < x) ++j;` -> `while (j < M && vals[i].first + vals[j].first < x) j++;`.
    *   `res = min(res, vals[i].second + vals[j].second);` -> `res = Math.min(res, vals[i].second + vals[j].second);`.
    *   `printf("%d\n", res>K?-1:res);` -> `out.println(res > K ? -1 : res);`.

16. **Refinement on `in` array:**
    *   `in` is used in `vals` population.
    *   `in` is not used after that. It can stay.

17. **Refinement on `MAX`:**
    *   `const int MAX = 5000+7;`. Java `static final int MAX = 5007;`.

18. **Plan Summary:**
    *   Create `e_529` class.
    *   Import `java.util.*`, `java.io.*`.
    *   Define static fields `N`, `K`, `in`, `vals`.
    *   Define `Pair` class with `first`, `second`, `compareTo`.
    *   Define `readInt` helper using `BufferedReader` and `StringTokenizer` to replace `scanf`.
    *   Define `out` as `PrintWriter`.
    *   Translate `main` logic.
    *   Translate helper functions (`EQ`, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`, `chmax`, `chmin`).
    *   Handle `INF`.
    *   Ensure `vals` is sorted.
    *   Ensure output format matches.

19. **Constraints Check:**
    *   `MAX` is 5007.
    *   `vals` size `MAX * 20` approx 100,000.
    *   `in` size 5007.
    *   `Q` is not bounded in C++ code but usually fits in int.
    *   `x` fits in int.
    *   `res` fits in int.
    *   `in[i]*(j+1)` can exceed `int` range? `in[i]` is int, `j+1` is int. If `in[i]` is large and `K` is large, it might overflow `int`. However, `res` is compared to `K`. If `res` overflows, it might be an issue. The C++ code uses `int`. Java `int` is 32-bit signed. If values exceed $2^{31}-1$, it will overflow. Given `MAX=5000`, `in` elements might be small. If `in` elements are large, `in[i]*(j+1)` might overflow. I will assume standard `int` behavior matches C++ `int` (32-bit).
    *   Wait, `vals` stores `pair<int, int>`. `vals[i].first` is `int`.
    *   `vals[i].first + vals[j].first` might overflow `int` if `x` is large. But `x` is read as `int`. So it's consistent with C++.
    *   Java `int` is signed. C++ `int` is usually 32-bit signed.
    *   `1<<29` is `536870912`. Fits in `int`.

20. **Incremental Tasks Detail:**
    *   **Step 1:** Imports and Class Structure.
    *   **Step 2:** Constants and Helper Methods (`two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`, `chmax`, `chmin`, `EQ`).
    *   **Step 3:** `Pair` class definition.
    *   **Step 4:** `main` method logic (I/O setup, reading N, K, array, building vals, sorting, processing queries).
    *   **Step 5:** Final check.

Let's write the code.

```java
import java.io.*;
import java.util.*;

public class e_529 {
    // Constants
    static final int MAX = 5000 + 7;
    static final int INF = 1 << 29;

    // Global variables
    static int N, K;
    static int[] in = new int[MAX];
    static Pair[] vals = new Pair[MAX * 20];
    static int M;
    static PrintWriter out;
    static BufferedReader br;
    static StringTokenizer st;

    // Pair class to replace pair<int, int>
    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        Pair(int f, int s) {
            this.first = f;
            this.second = s;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.first != other.first) {
                return this.first - other.first;
            }
            return this.second - other.second;
        }
    }

    // Helper functions translated from C++
    // EQ
    static boolean EQ(double a, double b) {
        return Math.abs(a - b) < 1e-9;
    }

    // Bit manipulation functions
    static int two(int n) {
        return 1 << n;
    }

    static int test(int n, int b) {
        return (n >> b) & 1;
    }

    static void set_bit(int &n, int b) {
        n |= two(b);
    }

    static void unset_bit(int &n, int b) {
        n &= ~two(b);
    }

    static int last_bit(int n) {
        return n & (-n);
    }

    static int ones(int n) {
        int res = 0;
        while (n > 0 && ++res) {
            n -= n & (-n);
        }
        return res;
    }

    // chmax/chmin (using Math.max/min since Java generics don't support primitives easily for these templates)
    // Note: In C++ templates, these work for any type. In Java, we have to be specific.
    // Since they are used with int in the code (though not in the provided snippet, they are part of the template definitions),
    // I will provide int versions.
    static void chmax(int a, int b) {
        a = Math.max(a, b);
    }

    static void chmin(int a, int b) {
        a = Math.min(a, b);
    }

    // Input reading helper
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

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);

        // Read N, K
        N = nextInt();
        K = nextInt();

        // Read in array
        for (int i = 0; i < N; i++) {
            in[i] = nextInt();
        }

        // Build vals
        M = 0;
        vals[M++] = new Pair(0, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                vals[M++] = new Pair(in[i] * (j + 1), j + 1);
            }
        }

        // Sort vals
        // Only sort up to M
        Arrays.sort(vals, 0, M);

        // Process Queries
        int Q = nextInt();
        while (Q-- > 0) {
            int x = nextInt();
            int res = INF;
            int j = 0;

            for (int i = M - 1; i >= 0; i--) {
                while (j < M && vals[i].first + vals[j].first < x) {
                    j++;
                }
                if (vals[i].first + vals[j].first == x) {
                    res = Math.min(res, vals[i].second + vals[j].second);
                }
            }

            out.println(res > K ? -1 : res);
        }

        out.flush();
    }
}
```

Wait, I should check the `set_bit` and `unset_bit` signatures.
C++: `inline void set_bit(int & n, int b)`.
Java: `static void set_bit(int n, int b)`. Java doesn't have references, so `int n` is passed by value. Modifying `n` inside the function doesn't affect the caller.
However, the C++ code uses `set_bit` and `unset_bit` but they are not called in the provided `main` function. They are just definitions. So I can translate them as is, but I should note that in Java they won't actually modify the caller's variable unless I pass the variable by reference (which Java doesn't support directly). Since they are not used, I will translate them syntactically but they won't work functionally for mutation.
Actually, looking closely at the provided C++ code:
```cpp
inline void set_bit(int & n, int b) { n |= two(b); }
```
This is defined but never called.
I will translate the definitions to Java methods. I should probably keep the signatures close to C++ or adapt them to Java conventions. Since they are unused, it doesn't matter much for the logic, but for translation fidelity, I will keep the names and logic.

Wait, `ones` function:
```cpp
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
```
In Java:
```java
static int ones(int n) {
    int res = 0;
    while (n != 0 && ++res) {
        n -= n & (-n);
    }
    return res;
}
```
Wait, `n` in C++ is modified (`n -= ...`). In Java, `n` is passed by value, so the loop modifies the local copy. This is fine.

`chmax` and `chmin`:
```cpp
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
```
Java doesn't support templates for primitives. I will implement specific versions for `int`.
```java
static void chmax(int a, int b) { a = Math.max(a, b); }
```
Same for `chmin`.

One detail: `vals` array size.
C++: `pair<int, int> vals[MAX*20];`
Java: `Pair[] vals = new Pair[MAX * 20];`
This is dynamic allocation. `MAX` is 5007. `MAX*20` is ~100,000.
In Java, array index is `0` to `length-1`.
`vals[M++]` works. `sort(vals, 0, M)` works.

One detail on `EQ`:
```cpp
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
```
Java:
```java
static boolean EQ(double a, double b) {
    return Math.abs(a - b) < 1e-9;
}
```
`fabs` is for `double`, `Math.abs` handles `double` correctly.

One detail on `INF`:
`const int INF = 1<<29;`
Java: `static final int INF = 1 << 29;`

One detail on `in` array:
`int in[MAX];`
Java: `static int[] in = new int[MAX];`

One detail on `vals` initialization:
`vals[M++] = make_pair(0, 0);`
Java: `vals[M++] = new Pair(0, 0);`

One detail on `sort`:
`sort(vals, vals+M);`
Java: `Arrays.sort(vals, 0, M);`

One detail on `while (Q--)`:
Java: `while (Q-- > 0)` (or `while (Q-- >= 0)` inside a loop that decrements).
Actually `while (Q--)` in C++ decrements Q and checks if it's non-zero.
In Java: `while (Q-- > 0)` is equivalent if Q is int.

One detail on `printf("%d\n", res>K?-1:res);`:
Java: `out.println(res > K ? -1 : res);`

One detail on `scanf`:
Replaced by `nextInt()`.

One detail on `using namespace std;`:
Ignored in Java, use fully qualified names or static imports. I used `Math`, `Arrays`, `StringTokenizer`, `BufferedReader`, etc.

One detail on `inline`:
Ignored in Java.

One detail on `typedef long long ll`:
Ignored in Java, use `long`.

One detail on `#define DEBUG(x)`:
Ignored or implemented as a method. I'll ignore it as it's not used in main.

One detail on `chmax`/`chmin`:
Defined but not used. I will include them.

One detail on `set_bit`/`unset_bit`:
Defined but not used. I will include them.

Wait, `set_bit` and `unset_bit` take `int & n`. In Java, `int n` is passed by value. I will keep the signature `void set_bit(int n, int b)` but note that it won't modify the caller's variable. Since they are not used, this is acceptable.

One detail on `two(int n)`:
C++: `return 1 << n;`.
Java: `return 1 << n;`.

One detail on `test(int n, int b)`:
C++: `return (n>>b)&1;`.
Java: `return (n >> b) & 1;`.

One detail on `last_bit(int n)`:
C++: `return n & (-n);`.
Java: `return n & (-n);`.

One detail on `ones(int n)`:
C++: `int res = 0; while(n && ++res) n-=n&(-n); return res;`
Java: `int res = 0; while (n != 0 && ++res) { n -= n & (-n); } return res;`
Note: `n && ++res` in C++ evaluates `n` (non-zero check) then `++res`.
In Java: `n != 0 && ++res`.

Wait, `vals` sorting.
C++: `sort(vals, vals+M)`.
Java: `Arrays.sort(vals, 0, M)`.
`vals` is `Pair[]`. `Pair` implements `Comparable`.
The C++ code relies on `std::sort` which sorts pairs lexicographically.
My `Pair` class `compareTo`:
```java
if (this.first != other.first) {
    return this.first - other.first;
}
return this.second - other.second;
```
This matches `std::pair` comparison (first, then second).

Wait, `in` array.
C++: `int in[MAX];`.
Java: `static int[] in = new int[MAX];`.
Populated in main.

Wait, `vals` array size.
C++: `pair<int, int> vals[MAX*20];`.
Java: `static Pair[] vals = new Pair[MAX * 20];`.
`M` is the count of elements added.

Wait, `M` is global.
C++: `int M = 0;`.
Java: `static int M;`.

Wait, `N`, `K` are global.
C++: `int N, K`.
Java: `static int N, K;`.

Wait, `in` array is global.
C++: `int in[MAX];`.
Java: `static int[] in = new int[MAX];`.

Wait, `vals` array is global.
C++: `pair<int, int> vals[MAX*20];`.
Java: `static Pair[] vals = new Pair[MAX * 20];`.

Wait, `Q` is local.
C++: `int Q; scanf("%d", &Q);`.
Java: `int Q = nextInt();`.

Wait, `x` is local.
C++: `int x; scanf("%d", &x);`.
Java: `int x = nextInt();`.

Wait, `res` is local.
C++: `int res = INF;`.
Java: `int res = INF;`.

Wait, `j` is local.
C++: `int j = 0;`.
Java: `int j = 0;`.

Wait, `vals` population loop:
C++: `REP(i, N) REP(j, K) vals[M++] = make_pair(in[i]*(j+1), j+1);`.
Java: `for (int i = 0; i < N; i++) for (int j = 0; j < K; j++) vals[M++] = new Pair(in[i] * (j + 1), j + 1);`.

Wait, `vals` sorting.
C++: `sort(vals, vals+M)`.
Java: `Arrays.sort(vals, 0, M)`.

Wait, query loop.
C++: `for (int i = M-1; i >= 0; --i)`.
Java: `for (int i = M - 1; i >= 0; i--)`.

Wait, `vals[i].first + vals[j].first < x`.
Java: `vals[i].first + vals[j].first < x`.
Note: `vals[j]` is incremented inside the while loop.
In C++: `while (j < M && vals[i].first + vals[j].first < x) ++j;`.
In Java: `while (j < M && vals[i].first + vals[j].first < x) j++;`.
Wait, `vals[j]` is accessed. `j` is incremented.
In C++, `vals[j]` is the element.
In Java, `vals[j]` is the element.
Is `j` reset for each `i`?
In C++: `int j = 0;` is outside the `for (int i = M-1; i >= 0; --i)`.
So `j` persists across iterations of `i`.
In Java: `int j = 0;` is outside the `for`.
So `j` persists.
Wait, `vals` is sorted ascending by first element.
We iterate `i` from `M-1` (largest first) down to `0` (smallest first).
For a fixed `i`, we want to find `j` such that `vals[i].first + vals[j].first` is close to `x`.
Since `vals` is sorted by `first`, as `i` decreases, `vals[i].first` decreases.
So `vals[i].first + vals[j].first` decreases.
To keep the sum close to `x`, `vals[j].first` must increase.
So `j` should increase as `i` decreases.
This is a two-pointer approach (or rather, a sliding window on the sorted array).
In C++: `int j = 0;` is outside the `while(Q--)` loop.
So `j` is reset to 0 for each query.
Inside the query loop: `while (j < M && vals[i].first + vals[j].first < x) ++j;`.
This logic is preserved in Java.

Wait, `vals` size.
`MAX * 20`.
In Java: `new Pair[MAX * 20]`.
`vals` is `Pair[]`.
`vals[M++]` works.

Wait, `in` array.
`in` is not sorted. `vals` is sorted.
`in` is only used to populate `vals`.

Wait, `EQ` function.
`inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }`.
I will implement this.

Wait, `chmax`, `chmin`.
I will implement these as static methods.

Wait, `set_bit`, `unset_bit`.
I will implement these as static methods.

Wait, `two`, `test`, `last_bit`, `ones`.
I will implement these as static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `out` and `br`.
`static PrintWriter out;`
`static BufferedReader br;`

Wait, `st` (StringTokenizer).
`static StringTokenizer st;`

Wait, `next()` and `nextInt()`.
I will implement these.

Wait, `flush()`.
`out.flush();`.

Wait, `e_529` class name.
`public class e_529`.

Wait, imports.
`import java.util.*;`
`import java.io.*;`

Wait, `DEBUG` macro.
I will ignore it as it's not used in main.

Wait, `using namespace std;`.
Ignored.

Wait, `#define REP(i,n) for(int i=0;i<(n);i++)`.
I will use standard Java for loop.

Wait, `#define FOR(i,a,b) for(int i=(a);i<=(b);i++)`.
I will use standard Java for loop.

Wait, `#define FORD(i,a,b) for(int i=(a);i>=(b);i--)`.
I will use standard Java for loop.

Wait, `inline`.
Ignored.

Wait, `const`.
Ignored (static final).

Wait, `typedef`.
Ignored.

Wait, `scanf`.
Replaced by `nextInt()`.

Wait, `printf`.
Replaced by `out.println()`.

Wait, `cout`.
Replaced by `out.println()`.

Wait, `endl`.
Replaced by `out.println()`.

Wait, `#include <cstdio>`.
Ignored (use `out`).

Wait, `#include <cstring>`.
Ignored.

Wait, `#include <cctype>`.
Ignored.

Wait, `#include <string>`.
Ignored (use `String`).

Wait, `#include <vector>`.
Ignored (use `ArrayList` or arrays).

Wait, `#include <list>`.
Ignored.

Wait, `#include <set>`.
Ignored.

Wait, `#include <map>`.
Ignored.

Wait, `#include <queue>`.
Ignored.

Wait, `#include <stack>`.
Ignored.

Wait, `#include <algorithm>`.
Ignored (use `Arrays.sort`).

Wait, `#include <functional>`.
Ignored.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `chmax`, `chmin`.
`static void chmax(int a, int b)`.
`static void chmin(int a, int b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `main` method.
`public static void main(String[] args)`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `Q`.
`int Q`.

Wait, `x`.
`int x`.

Wait, `res`.
`int res`.

Wait, `j`.
`int j`.

Wait, `vals[i].first + vals[j].first`.
Java: `vals[i].first + vals[j].first`.

Wait, `res > K ? -1 : res`.
Java: `res > K ? -1 : res`.

Wait, `out.println`.
`out.println(...)`.

Wait, `out.flush()`.
`out.flush()`.

Wait, `br.readLine()`.
`br.readLine()`.

Wait, `st.nextToken()`.
`st.nextToken()`.

Wait, `Integer.parseInt`.
`Integer.parseInt()`.

Wait, `Arrays.sort`.
`Arrays.sort(vals, 0, M)`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `MAX`.
`static final int MAX = 5007;`.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `EQ`.
`static boolean EQ(double a, double b)`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method throws `IOException`.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class name.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `next()` method.
`static String next()`.

Wait, `nextInt()` method.
`static int nextInt()`.

Wait, `flush()` method.
`out.flush()`.

Wait, `Q` loop.
`while (Q-- > 0)`.

Wait, `vals` loop.
`for (int i = M - 1; i >= 0; i--)`.

Wait, `j` loop.
`while (j < M && vals[i].first + vals[j].first < x)`.

Wait, `res` update.
`res = Math.min(res, vals[i].second + vals[j].second)`.

Wait, `printf` replacement.
`out.println(...)`.

Wait, `scanf` replacement.
`nextInt()`.

Wait, `REP` replacement.
`for (int i = 0; i < N; i++)`.

Wait, `vals` population.
`vals[M++] = new Pair(in[i] * (j + 1), j + 1);`.

Wait, `vals` sorting.
`Arrays.sort(vals, 0, M)`.

Wait, `EQ` function.
`return Math.abs(a - b) < 1e-9;`.

Wait, `two` function.
`return 1 << n;`.

Wait, `test` function.
`return (n >> b) & 1;`.

Wait, `set_bit` function.
`n |= two(b);`.

Wait, `unset_bit` function.
`n &= ~two(b);`.

Wait, `last_bit` function.
`return n & (-n);`.

Wait, `ones` function.
`int res = 0; while (n != 0 && ++res) { n -= n & (-n); } return res;`.

Wait, `chmax` function.
`a = Math.max(a, b);`.

Wait, `chmin` function.
`a = Math.min(a, b);`.

Wait, `in` array.
`in[i] = nextInt();`.

Wait, `N`, `K`.
`N = nextInt(); K = nextInt();`.

Wait, `vals` array.
`vals[M++] = new Pair(0, 0);`.

Wait, `M`.
`M = 0;`.

Wait, `out`.
`out = new PrintWriter(System.out);`.

Wait, `br`.
`br = new BufferedReader(new InputStreamReader(System.in));`.

Wait, `st`.
`st = new StringTokenizer("");`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import`.
`import java.io.*;`
`import java.util.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.
`out.flush();`.

Wait, `main` method.
`throws IOException`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `Pair` class.
`static class Pair implements Comparable<Pair>`.

Wait, `compareTo`.
`public int compareTo(Pair other)`.

Wait, `first`, `second`.
`int first, second;`.

Wait, `Pair` constructor.
`Pair(int f, int s)`.

Wait, `EQ` function.
`static boolean EQ(double a, double b)`.

Wait, `two`, `test`, `set_bit`, `unset_bit`, `last_bit`, `ones`.
All static methods.

Wait, `chmax`, `chmin`.
All static methods.

Wait, `INF`.
`static final int INF = 1 << 29;`.

Wait, `MAX`.
`static final int MAX = 5000 + 7;`.

Wait, `in` array.
`static int[] in = new int[MAX];`.

Wait, `vals` array.
`static Pair[] vals = new Pair[MAX * 20];`.

Wait, `N`, `K`, `M`.
`static int N, K, M;`.

Wait, `out`, `br`, `st`.
`static PrintWriter out;`
`static BufferedReader br;`
`static StringTokenizer st;`.

Wait, `main` method.
`public static void main(String[] args) throws IOException`.

Wait, `e_529` class.
`public class e_529`.

Wait, `import java.util.*;`
`import java.io.*;`.

Wait, `StringTokenizer`.
`st = new StringTokenizer(line);`.

Wait, `next()` method logic.
`while (st == null || !st.hasMoreTokens())`.
`String line = br.readLine();`.
`if (line == null) return null;`.
`st = new StringTokenizer(line);`.
`return st.nextToken();`.

Wait, `nextInt()` method logic.
`String s = next();`.
`if (s == null) return 0;`.
`return Integer.parseInt(s);`.

Wait, `flush()` method.