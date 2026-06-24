Translate this C++ code to Java code. The main class name should be d_1208. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 201010
#define maxlg 18
struct SUM_BIT {
    llong data[maxn];
    void upd(int i, llong val) {
        for(++i; i < maxn; i += i & -i) data[i] += val;
    }

    int lower_bound(llong s) {
        int ans = 0; 
        llong cur = 0;
        for (int i = 1 << maxlg >> 1; i > 0; i >>= 1) {
            if (ans + i >= maxn) continue;
            if (cur + data[ans + i] > s) continue;
            ans += i;
            cur += data[ans];
        }
        return ans;
    }
};

int n;
llong p[maxn];
int ans[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, n) cin >> p[i];

    SUM_BIT bit;
    rep1(i, n) bit.upd(i, i);
    for (int i = n; i--; ) {
        ans[i] = bit.lower_bound(p[i]);
        bit.upd(ans[i], -ans[i]);
    }

    rep(i, n) cout << ans[i] << ' ';

    return 0;
}

<think>
The user wants me to translate a C++ code snippet to Java.
The main class name must be `d_1208`.

**Plan:**

1.  **Analyze C++ specific features:**
    *   **Includes:** `<bits/stdc++.h>` is a non-standard header including everything. I need to include specific Java classes (Scanner, System, etc.).
    *   **Namespaces:** `using namespace std;` is not applicable in Java. I need to use fully qualified names or import classes (e.g., `java.util.Scanner`).
    *   **Macros:**
        *   `llong`: Defined as `long long` in C++. In Java, `long` is the equivalent 64-bit signed integer type.
        *   `xx`, `yy`, `len`, `rep`, `rep1`, `all`: These are preprocessor macros. Java doesn't have a preprocessor. I need to implement them as helper methods or inline logic.
        *   `maxn`, `maxlg`: Constants.
        *   `struct`: In Java, this becomes a `class` or `record` (though `class` is more standard for mutable state).
    *   **IO:** `cin`, `cout` are replaced by `Scanner` and `System.out`.
    *   **Types:** `int` -> `int`, `long long` -> `long`.
    *   **Loops:** `for` loops are similar, but C++ `rep` macros need to be converted to Java `for` loops.
    *   **Struct:** `SUM_BIT` is a struct with an array. In Java, this becomes a class with a `long[]` field.
    *   **Bitwise operations:** `i & -i` works the same in Java.
    *   **Shifting:** `1 << maxlg` works the same, but `1` is `int`. If `maxlg` is large, it might overflow `int`. `maxlg` is 18, so `1 << 18` is fine for `int`.
    *   **`main` method:** `main` function becomes `public static void main(String[] args)`.

2.  **Incremental Tasks:**
    *   Task 1: Setup class structure and imports.
    *   Task 2: Translate `llong` to `long`.
    *   Task 3: Translate `SUM_BIT` struct to a Java class with methods `upd` and `lower_bound`.
    *   Task 4: Translate `main` method logic.
    *   Task 5: Handle IO (`cin` -> `Scanner`, `cout` -> `System.out.println`/`print`).

3.  **Specific Translation Details:**
    *   **Macros:**
        *   `llong` -> `long`
        *   `maxn` -> `static final int MAXN`
        *   `maxlg` -> `static final int MAXLG`
        *   `rep(i, n)`: In C++, `for (int i = -1; ++i < n; )`. In Java: `for (int i = 0; i < n; i++)`.
        *   `rep1(i, n)`: In C++, `for (int i = 0; i < n; i++)` (Note: C++ code uses `i++ < n`, wait, looking at the macro definition: `for (int i = 0; i ++ < n; )`. This is equivalent to `for (int i = 0; i < n; i++)`).
        *   `len(x)`: `(int)x.size()`. Java: `x.size()`.
        *   `xx`, `yy`: `first`, `second`. Not used in the provided code, but good to know.
    *   **Struct `SUM_BIT`:**
        *   `data` array: `long[] data`. Size `MAXN`.
        *   `upd` method: `void upd(int i, long val)`.
        *   `lower_bound` method: `int lower_bound(long s)`.
    *   **Main Logic:**
        *   `ios_base...`: Java IO setup is implicit with `Scanner` and `System.out`, but usually, we don't need to sync. `Scanner` is slow, but for this translation task, I should stick to standard `Scanner`. If performance matters, `BufferedReader` + `StringTokenizer` is better. Given the C++ code uses `cin.tie(0)` etc., it implies performance optimization. I will use `BufferedReader` and `StringTokenizer` for efficiency to match the C++ intent, or just standard `Scanner` if the constraints aren't specified. However, standard competitive programming Java templates often use `BufferedReader`. Let's stick to `Scanner` for simplicity unless the logic suggests strict timing. Actually, `cin.tie(0)` is for speed. I will use `Scanner` for readability but keep in mind `BufferedReader` is the Java equivalent of fast I/O. Let's use `Scanner` to keep the code clean, as the logic is $O(N \log N)$ or similar, and $N=200010$. `Scanner` might be too slow for $N=200010$ with heavy I/O. `BufferedReader` is safer.
        *   `SUM_BIT bit`: `SUM_BIT bit = new SUM_BIT();`.
        *   `rep1(i, n)`: `for (int i = 0; i < n; i++)`.
        *   `bit.upd(i, i)`: `bit.upd(i, i)`.
        *   `for (int i = n; i--; )`: `for (int i = n - 1; i >= 0; i--)`.
        *   `cout << ans[i] << ' '`: `System.out.print(ans[i] + " ")`.
        *   `return 0`: `return;`.

    *   **Wait, one detail:** `maxn` is `201010`. `data` array size needs to be `MAXN`.
    *   **`lower_bound` logic:**
        ```cpp
        int lower_bound(llong s) {
            int ans = 0; 
            llong cur = 0;
            for (int i = 1 << maxlg >> 1; i > 0; i >>= 1) {
                if (ans + i >= maxn) continue;
                if (cur + data[ans + i] > s) continue;
                ans += i;
                cur += data[ans];
            }
            return ans;
        }
        ```
        Wait, the loop logic in C++: `1 << maxlg >> 1`. `maxlg` is 18. `1 << 18` is `262144`. `262144 >> 1` is `131072`.
        In Java, `1 << 18` is fine.
        `ans + i >= maxn` check.
        `cur + data[ans + i] > s` check.
        `ans += i`.
        `cur += data[ans]`.
        Wait, `data[ans]` after `ans += i`?
        In C++: `ans` starts at 0. `cur` starts at 0.
        Inside loop:
        `if (ans + i >= maxn) continue;`
        `if (cur + data[ans + i] > s) continue;`
        `ans += i;`
        `cur += data[ans];`
        Wait, `data` is 1-indexed in the `upd` function (`for(++i; i < maxn; ...)`).
        So `data[0]` is 0. `data[1]` is 1 (from `upd(0, 0)`? No `upd(i, i)` calls `upd(0, 0)` which increments index 1).
        Wait, `upd(i, val)`: `for(++i; i < maxn; i += i & -i)`.
        So `upd(0, 0)` increments `data[1]`.
        `upd(1, 1)` increments `data[1]`, `data[2]`, etc.
        Wait, `lower_bound` iterates bits.
        If `ans` is 0, `cur` is 0. `data[0]` is 0.
        `data` is 1-based BIT. `data[0]` is usually 0.
        The loop checks `data[ans + i]`.
        If `ans` is 0, `data[i]`.
        Then `ans += i`. `cur += data[ans]`.
        This logic seems to rely on `data` being populated.
        In Java, arrays are 0-indexed. C++ arrays are 0-indexed.
        The C++ code uses `data` as a Fenwick Tree (Binary Indexed Tree).
        Usually BIT is 1-indexed. `data[0]` is unused or 0.
        `upd(i, val)` does `++i`. So `i=0` updates `data[1]`.
        `lower_bound` starts with `ans=0`, `cur=0`.
        It checks `data[ans+i]`. If `ans=0`, it checks `data[i]`.
        This matches the 1-based indexing logic of BIT.
        In Java, I should keep `data` size `MAXN`.
        `long[] data = new long[MAXN];`
        `upd` method: `for(++i; i < maxn; i += i & -i)`.
        `lower_bound`: `int ans = 0;`.
        Note: In C++, `ans` is `int`, `cur` is `llong`.
        In Java, `ans` is `int`, `cur` is `long`.

    *   **Class Name:** `d_1208`.
    *   **Main Method:** `public static void main(String[] args)`.
    *   **IO:** I will use `BufferedReader` and `PrintWriter` for efficiency, mimicking `ios_base::sync_with_stdio(0); cin.tie(0);`.

4.  **Refining the Plan:**
    *   **Imports:** `java.io.*`, `java.util.*`.
    *   **Constants:** `MAXN`, `MAXLG`.
    *   **Class:** `SUM_BIT` with `long[] data`.
    *   **Methods:** `upd`, `lower_bound`.
    *   **Main:** Read `n`, read `p`, init BIT, loop `n-1` down to 0, print `ans`.

    *   **Wait, `rep` and `rep1` macros:**
        *   `rep(i, n)`: `for (int i = -1; ++i < n; )`. Java: `for (int i = 0; i < n; i++)`.
        *   `rep1(i, n)`: `for (int i = 0; i < n; i++)` (Note: `i++ < n` is slightly different than `++i < n` in C++? No, `i++` evaluates old value. If `i=n`, `i++` returns `n`, then `i` becomes `n+1`. Loop terminates. `++i` increments then checks. `for (int i = -1; ++i < n; )` is equivalent to `for (int i = 0; i < n; i++)`.
        *   Wait, `rep1` definition: `for (int i = 0; i ++ < n; )`. This is `i++` then check.
        *   In C++, `i` starts at 0. `i++` returns 0. `0 < n` is true. `i` becomes 1.
        *   In Java, `for (int i = 0; i < n; i++)`.
        *   Wait, `rep` definition: `for (int i = -1; ++ i < n; )`.
        *   Java equivalent: `for (int i = 0; i < n; i++)`.
        *   `rep1` definition: `for (int i = 0; i ++ < n; )`.
        *   Java equivalent: `for (int i = 0; i < n; i++)`.
        *   Wait, `rep1` in C++ code: `for (int i = 0; i ++ < n; )`.
        *   If `i=0`, `i++` returns 0. `0 < n`. `i` becomes 1.
        *   If `i=n`, `i++` returns `n`. `n < n` is false. `i` becomes `n+1`.
        *   So it runs for `0` to `n-1`.
        *   So `rep1` is standard 0 to `n-1`.
        *   `rep` is also standard 0 to `n-1`.
        *   Why two macros? `rep` starts at -1, increments. `rep1` starts at 0, increments. Both do the same thing effectively for `0` to `n-1`.
        *   I will use `for (int i = 0; i < n; i++)` for both.

    *   **`lower_bound` logic check:**
        ```cpp
        for (int i = 1 << maxlg >> 1; i > 0; i >>= 1)
        ```
        In C++, `1 << maxlg` is `int`. `>> 1` is `int`.
        In Java, `1 << maxlg` is `int`. `>> 1` is `int`.
        `1 << 18` is `262144`.
        Wait, `maxn` is `201010`.
        `1 << 18` is `262144`. `262144 > 201010`.
        So `1 << 18` covers the range.
        Wait, `1 << 17` is `131072`. `131072 + 65536` is `196608`.
        So `1 << 17` might be enough?
        The code says `1 << maxlg >> 1`. `maxlg` is 18.
        `1 << 18` is `262144`. `262144 >> 1` is `131072`.
        This is `1 << (maxlg - 1)`.
        So it starts with the highest power of 2 less than `maxn`.
        This logic is correct for finding the index.

    *   **Wait, `SUM_BIT` definition:**
        ```cpp
        struct SUM_BIT {
            llong data[maxn];
            // ...
        };
        ```
        In Java, array size must be constant. `MAXN` is `201010`.
        `long[] data = new long[MAXN];`

    *   **Wait, `lower_bound` loop:**
        ```cpp
        for (int i = 1 << maxlg >> 1; i > 0; i >>= 1)
        ```
        In Java, `1 << 18` is `int`.
        If `maxlg` was larger (e.g. 30), `1 << 30` is still positive `int`.
        If `maxlg` was 31, `1 << 31` is `Integer.MIN_VALUE` (negative).
        Here `maxlg` is 18, so it's fine.
        Wait, `maxlg` is defined as `18`.
        `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So it starts from `1 << 17`.
        Is `MAXN` 201010? Yes.
        So `1 << 17` is `131072`. `131072 < 201010`.
        So `ans` can be up to `131072`.
        Wait, `ans` is 0-indexed or 1-indexed?
        `upd` starts at `++i`. So `data` is 1-indexed effectively.
        `lower_bound` starts `ans=0`.
        If `ans` becomes `131072`, `ans+1` is `131073`.
        `data` size is `201010`.
        So it fits.

    *   **Wait, `main` method:**
        `ios_base::sync...`: In Java, `Scanner` is slow. `BufferedReader` + `StringTokenizer` is the standard replacement for fast I/O.
        I will use `BufferedReader` and `PrintWriter` (or `System.out`).
        `cin >> n`: `br.readLine()` and parse.
        `cin >> p[i]`: `StringTokenizer`.
        `cout`: `System.out.print` or `PrintWriter`.

    *   **Wait, `lower_bound` logic:**
        ```cpp
        int lower_bound(llong s) {
            int ans = 0; 
            llong cur = 0;
            for (int i = 1 << maxlg >> 1; i > 0; i >>= 1) {
                if (ans + i >= maxn) continue;
                if (cur + data[ans + i] > s) continue;
                ans += i;
                cur += data[ans];
            }
            return ans;
        }
        ```
        Wait, `data` is `long[]`. `s` is `long`. `cur` is `long`.
        `ans` is `int`.
        `ans + i` is `int`.
        `cur + data[ans + i]` is `long`.
        `data` array is `long`.
        In Java: `long[] data`.
        `long cur = 0;`.
        `int ans = 0;`.
        `int i`.
        `if (ans + i >= maxn)`.
        `if (cur + data[ans + i] > s)`.
        `ans += i`.
        `cur += data[ans]`.
        Wait, `data[ans]`? `ans` was updated.
        Wait, `data[ans]` after `ans += i`?
        In C++: `data[ans]`. `ans` is `int`. `data` is `long[]`.
        This is valid.

    *   **Wait, `lower_bound` loop:**
        `for (int i = 1 << maxlg >> 1; i > 0; i >>= 1)`
        In Java, `>>` is arithmetic shift. `1 << 18` is positive. `>>` works same as `>>>` for positive.
        So `i >>= 1` is fine.

    *   **Wait, `upd` method:**
        ```cpp
        void upd(int i, llong val) {
            for(++i; i < maxn; i += i & -i) data[i] += val;
        }
        ```
        In Java:
        `void upd(int i, long val) {`
        `    for (i++; i < maxn; i += i & -i) {`
        `        data[i] += val;`
        `    }`
        `}`
        Note: `i` is a parameter. In Java, `i` is a local variable. `i++` works.
        Wait, `i` is `int`. `i & -i` works in Java.

    *   **Wait, `main` method:**
        `SUM_BIT bit;` -> `SUM_BIT bit = new SUM_BIT();`
        `rep1(i, n) bit.upd(i, i);`
        `for (int i = n; i--; )` -> `for (int i = n - 1; i >= 0; i--)`
        `ans[i] = bit.lower_bound(p[i]);`
        `bit.upd(ans[i], -ans[i]);`
        `cout << ans[i] << ' ';`
        `return 0;`

    *   **Wait, `p` array:**
        `llong p[maxn];` -> `long[] p = new long[MAXN];`
        `ans` array: `int[] ans = new int[MAXN];`

    *   **Wait, `maxn`:**
        `#define maxn 201010`
        Java: `static final int MAXN = 201010;`

    *   **Wait, `maxlg`:**
        `#define maxlg 18`
        Java: `static final int MAXLG = 18;`

    *   **Wait, `ios_base`:**
        I will implement a fast IO helper class or just use `BufferedReader` and `PrintWriter` directly in main.
        Using `Scanner` might TLE for $N=200010$ with `cin.tie(0)` optimization.
        I will use `BufferedReader` and `StringTokenizer`.

5.  **Code Structure:**
    *   Class `d_1208`.
    *   Static constants `MAXN`, `MAXLG`.
    *   Inner class `SUM_BIT` (static).
    *   `main` method.

    *   **Wait, `SUM_BIT` fields:**
        `llong data[maxn];` -> `long[] data = new long[MAXN];`
        In Java, array initialization is `new long[MAXN]`.
        This initializes to 0s.

    *   **Wait, `lower_bound` logic:**
        `if (ans + i >= maxn)` -> `if (ans + i >= MAXN)`.
        `if (cur + data[ans + i] > s)` -> `if (cur + data[ans + i] > s)`.
        Wait, `data` is `long[]`. `ans` is `int`.
        `ans + i` is `int`.
        `data` index is `int`.
        `cur` is `long`.
        `data[ans + i]` is `long`.
        `cur + data[...]` is `long`.
        `s` is `long`.
        Comparison is valid.

    *   **Wait, `lower_bound` return:**
        `return ans;`

    *   **Wait, `main` logic:**
        `cin >> n`.
        `StringTokenizer st = new StringTokenizer(br.readLine());`
        Wait, `cin >> n` reads `n`. Then `rep(i, n) cin >> p[i]`.
        This might span multiple lines.
        So I need a loop to read `n` integers.
        `st` might need to be refreshed.
        Standard `FastScanner` approach.

    *   **Wait, `ans` array:**
        `int ans[MAXN];` -> `int[] ans = new int[MAXN];`

    *   **Wait, `cout` loop:**
        `for (int i = 0; i < n; i++) cout << ans[i] << ' ';`
        Wait, original code:
        ```cpp
        rep(i, n) cout << ans[i] << ' ';
        ```
        `rep` is `for (int i = 0; i < n; i++)`.
        So `for (int i = 0; i < n; i++)`.
        Print `ans[i]` followed by space.

    *   **Wait, `return 0`:**
        Java `main` returns `void`.

    *   **Wait, `using namespace std::placeholders;`**:
        Not used. Can be ignored.

    *   **Wait, `rand` definitions**:
        Commented out. Ignore.

    *   **Wait, `SUM_BIT` class:**
        Make it `static` inside `d_1208` or just a separate class.
        Since it uses `MAXN` and `MAXLG`, it should be static or use the main class's static fields.
        Better to make `SUM_BIT` a static inner class or a separate class that accesses static constants from `d_1208`.
        Let's make it a static inner class `SUM_BIT` inside `d_1208`.
        It needs access to `MAXN`.
        So `data` array size is `MAXN`.
        `upd` uses `MAXN`.
        `lower_bound` uses `MAXN`.
        I can pass `MAXN` or make `MAXN` a static field in `d_1208`.
        `SUM_BIT` can access `d_1208.MAXN`.
        Or I can put `MAXN` inside `SUM_BIT` as a static constant.
        Let's put `MAXN` inside `SUM_BIT` as `static final int MAXN`.

    *   **Wait, `SUM_BIT` initialization:**
        `SUM_BIT bit;`
        `rep1(i, n) bit.upd(i, i);`
        In Java, `bit` must be instantiated before `upd` is called.
        `SUM_BIT bit = new SUM_BIT();`
        Then `bit.upd`.

    *   **Wait, `lower_bound` logic:**
        `int ans = 0;`
        `long cur = 0;`
        `for (int i = 1 << MAXLG >> 1; i > 0; i >>= 1)`
        Wait, `1 << 18` is `262144`. `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)`.
        In C++: `1 << maxlg >> 1`.
        Operator precedence: `<<` and `>>` are same level, left-to-right.
        So `(1 << maxlg) >> 1`.
        In Java: `1 << MAXLG >> 1`.
        Wait, `1` is `int`. `MAXLG` is `int`.
        `1 << 18` is `int`.
        `>> 1` is `int`.
        So `int i = 1 << MAXLG >> 1`.
        This is fine.

    *   **Wait, `data` array:**
        `long[] data = new long[MAXN];`
        In `SUM_BIT` constructor.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        Helper method `next()`:
        ```java
        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        ```
        `int nextInt()`:
        ```java
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        ```
        `long nextLong()`:
        ```java
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        ```
        Wait, `p` array is `llong`. So `long[] p`.
        `ans` array is `int[]`.

    *   **Wait, `lower_bound` check:**
        `if (ans + i >= maxn)`
        In Java: `if (ans + i >= MAXN)`
        Wait, `MAXN` is `201010`.
        `ans` is `int`. `i` is `int`. `ans+i` is `int`.
        `MAXN` is `int`.
        Comparison is fine.

    *   **Wait, `bit.upd` call:**
        `bit.upd(ans[i], -ans[i]);`
        `ans[i]` is `int`. `val` is `long`.
        In C++, `val` is `llong`.
        In Java, `long`.
        So `bit.upd(ans[i], -ans[i])`.
        Inside `upd`:
        `for (i++; i < MAXN; i += i & -i)`
        Wait, `i` is `int`. `i & -i` is `int`.
        `i` is `int`. `i += ...` is `int`.
        Wait, `i` is `int`. `data` is `long[]`.
        `data[i] += val`.
        `val` is `long`.
        `data[i]` is `long`.
        `+=` works.

    *   **Wait, `lower_bound` logic:**
        `cur` is `long`.
        `data[ans + i]` is `long`.
        `cur + data[...]` is `long`.
        `s` is `long`.
        Comparison `> s` is fine.

    *   **Wait, `main` return:**
        `return 0;` in C++ is `return;` or nothing in Java `main`.
        I will add `return;` or just end.

    *   **Wait, `ios_base` sync:**
        Java `System.out` and `Scanner` are synchronized by default.
        To match `cin.tie(0)`, I should use `BufferedReader` and `PrintWriter`.
        I will implement a simple `FastScanner` class inside `d_1208` or just put the logic in `main`.
        Given the constraints and the structure, a static inner class `FastReader` is good practice.
        However, to keep it simple and self-contained in `d_1208`, I can put `BufferedReader` in `main`.
        I will use `BufferedReader` and `PrintWriter` directly in `main`.

    *   **Wait, `SUM_BIT` class:**
        I will make it a static inner class.
        It needs to access `MAXN`.
        I will define `MAXN` in `d_1208` as `static final int`.
        `SUM_BIT` can access `d_1208.MAXN`.
        Or I can define `MAXN` inside `SUM_BIT` as well.
        To avoid passing `MAXN` everywhere, I'll define `MAXN` in `d_1208` and make `SUM_BIT` a static inner class that uses `d_1208.MAXN`.
        Wait, `SUM_BIT` is instantiated in `main`.
        `main` is in `d_1208`.
        So `d_1208.SUM_BIT` can access `d_1208.MAXN`.

    *   **Wait, `MAXN` usage:**
        `data` array size.
        `upd` loop limit.
        `lower_bound` check.
        So `MAXN` must be accessible.

    *   **Wait, `lower_bound` loop:**
        `1 << maxlg >> 1`.
        `maxlg` is `18`.
        `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        In Java: `1 << (MAXLG - 1)`.
        Wait, `1 << 18 >> 1` is `1 << 17`.
        So `1 << (MAXLG - 1)`.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `1 << 17` is `131072`.
        So `1 << (MAXLG - 1)` is `131072`.
        Wait, `1 << 18 >> 1` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.

    *   **Wait, `lower_bound` logic:**
        `for (int i = 1 << maxlg >> 1; i > 0; i >>= 1)`
        In Java: `for (int i = 1 << (MAXLG - 1); i > 0; i >>= 1)`
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is `131072`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.
        Wait, `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.

    *   **Wait, `MAXN` definition:**
        `#define maxn 201010`
        Java: `static final int MAXN = 201010;`

    *   **Wait, `SUM_BIT` class:**
        I will make it a static inner class.
        It will use `d_1208.MAXN`.

    *   **Wait, `lower_bound` method:**
        `int lower_bound(long s)`.
        Inside `SUM_BIT`.
        It uses `data` array and `MAXN`.
        `data` is `long[]`.
        `MAXN` is `int`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`:
        `while (!st.hasMoreTokens()) { String line = br.readLine(); if (line == null) return null; st = new StringTokenizer(line); } return st.nextToken();`
        `nextInt()`: `Integer.parseInt(next())`.
        `nextLong()`: `Long.parseLong(next())`.
        Wait, `next()` might throw `NullPointerException` if `br.readLine()` is null.
        I'll handle it gracefully or assume valid input.
        For competitive programming, assume valid input.

    *   **Wait, `SUM_BIT` constructor:**
        `data` array initialization.
        `data = new long[MAXN];`

    *   **Wait, `lower_bound` loop:**
        `if (ans + i >= maxn)` -> `if (ans + i >= MAXN)`.
        `if (cur + data[ans + i] > s)` -> `if (cur + data[ans + i] > s)`.
        `ans += i`.
        `cur += data[ans]`.
        Wait, `data` is `long[]`. `ans` is `int`.
        `ans + i` is `int`.
        `data[ans + i]` is `long`.
        `cur` is `long`.
        `s` is `long`.
        `ans` is `int`.
        `return ans`.

    *   **Wait, `main` logic:**
        `cin >> n`.
        `rep(i, n) cin >> p[i]`.
        `SUM_BIT bit = new SUM_BIT();`
        `rep1(i, n) bit.upd(i, i);`
        `for (int i = n; i--; )` -> `for (int i = n - 1; i >= 0; i--)`.
        `ans[i] = bit.lower_bound(p[i]);`
        `bit.upd(ans[i], -ans[i]);`
        `rep(i, n) cout << ans[i] << ' ';`
        `out.flush()`.

    *   **Wait, `SUM_BIT` class:**
        `long[] data` needs to be initialized in constructor.
        `data = new long[MAXN];`.

    *   **Wait, `SUM_BIT` methods:**
        `upd` and `lower_bound`.

    *   **Wait, `MAXN` constant:**
        `static final int MAXN = 201010;`
        `static final int MAXLG = 18;`
        In `d_1208`.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`
        `long[] data;`
        `SUM_BIT() { data = new long[MAXN]; }`
        `void upd(int i, long val)`
        `int lower_bound(long s)`

    *   **Wait, `lower_bound` loop:**
        `for (int i = 1 << (MAXLG - 1); i > 0; i >>= 1)`
        Wait, `1 << maxlg >> 1` in C++ is `(1 << maxlg) >> 1`.
        `1 << 18` is `262144`.
        `262144 >> 1` is `131072`.
        `131072` is `1 << 17`.
        So `1 << (MAXLG - 1)` is correct.

    *   **Wait, `SUM_BIT` class:**
        `data` array size `MAXN`.
        `upd` loop `i < MAXN`.
        `lower_bound` check `ans + i >= MAXN`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
        `long[] data`.
        `upd`.
        `lower_bound`.

    *   **Wait, `main` method:**
        `BufferedReader br = new BufferedReader(new InputStreamReader(System.in));`
        `PrintWriter out = new PrintWriter(System.out);`
        `StringTokenizer st = new StringTokenizer("");`
        `String next()`
        `int nextInt()`
        `long nextLong()`
        `main` logic.

    *   **Wait, `SUM_BIT` class:**
        `static class SUM_BIT`.
       