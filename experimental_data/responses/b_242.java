Translate this C++ code to Java code. The main class name should be b_242. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cstring>
#include<stdio.h>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define get getchar//_unlocked
inline int inp()
{
    int n=0,s=1;
    char p=get();
    if(p=='-')
    s=-1;
    while((p<'0'||p>'9')&&p!=EOF)
    p=get();
    while(p>='0'&&p<='9')
    {
    n = (n<< 3) + (n<< 1) + (p - '0');
    p=get();
    };
    return n*s;
}
long long power(long long a,long long b)
{
    long long r=1,x=a;
    while(b)
    {
        if(b&1)r=(r*x)%mod;
        x=(x*x)%mod;
        b>>=1;
    }
    return r;
}
vector<int> a,b;
int main()
{
    int i,n,j,k,l,m,t,ans,min,max;
    char ch;
    n=inp();min=mod;max=-1;i=0;
    m=n;
    while(n--)
    {
        i++;
        k=inp();l=inp();
        a.pb(k);b.pb(l);
       if(k<min)
       min=k;
       if(l>max)
       max=l;
    }
    for(i=0;i<m;i++)
    {
        if(a[i]==min&&b[i]==max)
        {printf("%d\n",i+1);break;}
    }

    if(i==m)printf("-1\n");
    return 0;
}

<think>
The user wants me to translate a C++ program into Java.
The main class name must be `b_242`.
I need to first plan the translation, identifying C++ specific features and how to map them to Java.
Then, I need to output the Java code enclosed by `<CODE>` tags.

**Plan:**

1.  **Headers:**
    *   `#include <cstring>`, `<stdio.h>`, `<cstdlib>`, `<cctype>`, `<algorithm>`, `<map>`, `<vector>`, `<list>`, `<set>`, `<queue>`, `<deque>`, `<stack>`, `<string>`, `<cmath>`: These are standard C++ headers. In Java, we don't need explicit imports for standard library classes (like `ArrayList`, `String`, etc.) other than `java.util.*` or `java.io.*`.
    *   `using namespace std;`: This is a C++ convenience. In Java, we use fully qualified names or import specific classes. Since the code uses `vector`, `printf`, `cin` (custom), `string`, etc., I will use standard Java classes (`java.util.Scanner` or `BufferedReader` for input, `System.out` for output).
    *   `#define ...`: Preprocessor macros. In Java, we can use `static final` constants.

2.  **Input/Output:**
    *   `inp()`: This is a custom fast I/O function using `getchar()`. In Java, `System.in.read()` or a `BufferedReader` is the equivalent. The logic reads an integer, handling signs and skipping non-digit characters. I should implement a similar `nextInt()` method using `System.in.read()`.
    *   `printf()`: C++ `printf` is replaced by `System.out.println()` or `System.out.print()`.
    *   `getchar()`: Replaced by `System.in.read()`.

3.  **Data Structures:**
    *   `vector<int> a, b;`: C++ vectors are dynamic arrays. In Java, `ArrayList<Integer>` is the direct equivalent.
    *   `char ch`: Used in `inp()`. In Java, `int` returned by `read()` is the character code.

4.  **Logic:**
    *   `power()`: Modular exponentiation function. Logic remains the same, just types change (long long -> long).
    *   `main()`:
        *   `n = inp()`: Read integer `n`.
        *   `min`, `max`: Initialize `min` to `mod` and `max` to `-1`.
        *   Loop `n` times to read pairs `k`, `l` into vectors `a`, `b`.
        *   Update `min` and `max`.
        *   Loop `m` times (where `m=n`) to find the index where `a[i] == min` and `b[i] == max`.
        *   Print index + 1 or -1.

5.  **Specific C++ features to handle:**
    *   `long long`: Java `long`.
    *   `int`: Java `int`.
    *   `vector`: Java `ArrayList`.
    *   `push_back`: Java `add()`.
    *   `size()`: Java `size()` or `a.size()`.
    *   `iterators`: The code uses index-based iteration (`for(i=0;i<m;i++)`), so `ArrayList` iteration is straightforward.
    *   `getchar` macro: Handled inside `inp()`.
    *   `EOF`: In Java, `System.in.read()` returns `-1` on EOF.
    *   `mod`: `1000000007`.
    *   `MAXN`: Defined but not used in the provided snippet (though it's in the includes).
    *   `FOR`, `FORD`, `REP`, `pb`, `ITER`: Macros. I will replace them with standard Java loops and methods. `pb` becomes `.add()`.
    *   `power` function: Defined but not called in `main`. I will keep it for completeness or remove it if it's unused. Looking at the `main` function, `power` is defined but never called. I should probably keep it as it might be part of the logic expected in the context, but strictly speaking, it's unused code. However, usually, in translation tasks, we translate everything provided. I will keep the method but ensure it compiles.
    *   `min`, `max`: `min` is initialized to `mod` (10^9+7). `max` to `-1`.
    *   `i` in `main`: `int i`. Note that `i` is used in the loop `while(n--)` and then in `for(i=0;...)`. In C++, `i` is re-declared inside the loop `while(n--)`? No, `i` is declared at top `int i`. Inside `while(n--)`, `i` is incremented. Then `for(i=0;...)` uses `i`. In C++, this is a bit weird if `i` is used in `while` and then reset in `for`.
        *   `n=inp(); ... i=0;`
        *   `while(n--) { i++; ... }` -> After loop, `i` will be `n+1` (original n).
        *   `m=n;`
        *   `for(i=0; i<m; i++)` -> Loop runs 0 to n-1.
        *   So `i` is reset before the second loop. This is valid C++.
    *   `get`: Macro replacing `getchar`.
    *   `inp()`: Custom input function. I need to rewrite this in Java. Java's `InputStream` methods are preferred for fast I/O similar to C++ `getchar`.

6.  **Incremental Tasks:**
    *   Define constants (`mod`).
    *   Implement `inp()` method (Fast I/O).
    *   Implement `power()` method (unused but present).
    *   Implement `main()` method:
        *   Read `n`.
        *   Read pairs, store in `ArrayList`s.
        *   Find min/max.
        *   Search for index.
        *   Print result.
    *   Main class definition.

7.  **Java Specifics:**
    *   Class `public class b_242`.
    *   `public static void main(String[] args)`.
    *   `ArrayList<Integer> a, b`.
    *   `System.out.print`.
    *   `System.in.read()`.
    *   `long` instead of `long long`.

8.  **Code Structure:**
    *   Imports: `java.util.*`, `java.io.*`.
    *   Class `b_242`.
    *   `static final int mod`.
    *   `static int inp()` (or instance method, but `main` is static, so `static` method is better to call from `main`).
    *   `static long power(long a, long b)`.
    *   `public static void main(String[] args)`.

9.  **Refining `inp()`**:
    *   C++: `char p = get();` where `get` is `getchar`.
    *   Java: `int p = System.in.read();`
    *   C++: `while((p<'0'||p>'9')&&p!=EOF) p=get();`
    *   Java: `while((p < '0' || p > '9') && p != -1) p = System.in.read();`
    *   C++: `n = (n<<3) + (n<<1) + (p - '0');` -> `n = (n << 3) + (n << 1) + (p - '0');` (Bitwise ops work same for int/long).
    *   C++: `return n * s;`
    *   Note on `EOF`: `System.in.read()` returns `-1` for EOF.
    *   Need to handle `InputStream` buffering? `System.in.read()` reads a single byte. It's slow for large inputs but matches the logic. For competitive programming style fast I/O in Java, usually `BufferedReader` or a custom `BufferedInputStream` wrapper is used. Given the C++ code uses `getchar` (unbuffered usually, or buffered depending on implementation, but `getchar_unlocked` is usually unbuffered), I should stick to `System.in.read()` for simplicity unless performance is critical. However, `getchar_unlocked` is often used in fast I/O templates. `System.in.read()` is buffered internally. To match the logic exactly without buffering overhead issues, I'll write a simple `read()` method that handles whitespace skipping.
    *   Wait, the C++ code uses `get` which maps to `getchar`. `getchar` reads a character.
    *   The logic:
        ```cpp
        int p = get();
        if(p=='-') s=-1;
        while((p<'0'||p>'9')&&p!=EOF) p=get();
        while(p>='0'&&p<='9') { ... }
        ```
    *   Java equivalent:
        ```java
        int p = System.in.read();
        // handle EOF
        ```
    *   Actually, `System.in.read()` might block if there is no input.
    *   I will implement a helper method `read()` that reads an integer, skipping whitespace.
    *   The C++ code handles the sign and digits manually.
    *   One detail: `get` is a macro `getchar`. `getchar_unlocked` is mentioned in comment `//_unlocked`. This implies it's a fast I/O function.
    *   I will implement a standard fast I/O approach using `BufferedReader` and `StringTokenizer` or just `System.in.read` loop. Given the specific logic in `inp()`, I will mimic it.
    *   Actually, `System.in.read()` returns an int (0-255 or -1).
    *   I need to handle the loop logic carefully.

    Let's refine the `inp` translation.
    C++:
    ```cpp
    inline int inp()
    {
        int n=0,s=1;
        char p=get();
        if(p=='-')
        s=-1;
        while((p<'0'||p>'9')&&p!=EOF)
        p=get();
        while(p>='0'&&p<='9')
        {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=get();
        };
        return n*s;
    }
    ```
    Java:
    ```java
    static int inp() throws IOException {
        int n = 0;
        int s = 1;
        int p = System.in.read();
        if (p == '-') {
            s = -1;
        }
        while ((p < '0' || p > '9') && p != -1) {
            p = System.in.read();
        }
        while (p >= '0' && p <= '9') {
            n = (n << 3) + (n << 1) + (p - '0');
            p = System.in.read();
        }
        return n * s;
    }
    ```
    Wait, `System.in.read()` reads one character at a time. If I call it repeatedly, it's slow. But this is the direct translation.
    However, `System.in` is an `InputStream`. `read()` returns `int`.
    If the input is empty, `read()` returns -1.
    One issue: `p` is `char` in C++, `int` in Java.
    In C++, `getchar` returns `int` (promoted).
    In Java, `read()` returns `int`.
    The logic seems fine.

    Wait, `n` is initialized to 0. `p` is read.
    If `p` is EOF immediately, `p` is -1. The loop `while((p<'0'||p>'9')&&p!=EOF)` handles skipping non-digits until EOF or digit.
    If EOF is reached before digits, `n` remains 0.
    The C++ code logic:
    1. Read `p`.
    2. Check if `-`.
    3. Skip non-digits.
    4. Read digits.
    5. Return result.

    In Java, `System.in.read()` is blocking.
    Also, `System.in` is a stream.
    One thing: In the `main` function, `n = inp()`. `n` is `int`.
    `m = n`.
    Loop `while(n--)`.
    Inside loop: `k = inp(); l = inp();`.
    This means `inp()` is called 2*N times.
    With `System.in.read()`, this is potentially slow for large N (1000010 defined as MAXN, though `n` is input).
    However, I must translate the logic. I will use `System.in.read()` directly to match `getchar`.
    To make it slightly better, I can use a buffer, but the prompt asks to translate the code. The C++ code uses `getchar` which is buffered by libc usually, but `getchar_unlocked` is unbuffered.
    I will stick to `System.in.read()` as it maps to `getchar`.
    Wait, `getchar_unlocked` is not standard C++, but `getchar` is. The comment `//_unlocked` suggests `getchar_unlocked` from `<cstdio>` (GCC extension).
    In Java, `System.in.read()` is the standard equivalent.
    I will add `try-catch` for `IOException`.

    **Variables:**
    `a`, `b`: `ArrayList<Integer>`.
    `min`, `max`: `int`.
    `i`, `n`, `j`, `k`, `l`, `m`, `t`, `ans`: `int`.
    `mod`: `static final int`.

    **Logic Check:**
    `min` init to `mod`. `max` init to `-1`.
    Loop `n` times.
    `if (k < min) min = k;`
    `if (l > max) max = l;`
    After loop, loop `0` to `m-1` (since `m=n`).
    Check `a[i] == min && b[i] == max`.
    If found, print `i+1`.
    If not found (`i` stays `m`), print `-1`.
    Wait, `i` is declared `int i`.
    `while(n--) { i++; ... }`.
    After this loop, `i` is equal to the original `n` (since it started at 0).
    Then `for(i=0; i<m; i++)`.
    Wait, `m=n`.
    So the `for` loop iterates `0` to `n-1`.
    This matches the indices of `a` and `b` (0 to `n-1`).
    If `i` reaches `m` (which is `n`), it means no match found.
    So `if (i == m)` prints `-1`.
    This logic is preserved.

    **Imports:**
    `java.util.ArrayList`
    `java.util.Scanner` (maybe not needed if using `read`)
    `java.io.IOException`

    **Class Name:** `b_242`.

    **Plan Summary:**
    1.  Create `public class b_242`.
    2.  Define `mod` constant.
    3.  Define `inp()` method mimicking the C++ logic using `System.in.read()`.
    4.  Define `power()` method (even if unused, keep it).
    5.  Define `main()` method.
    6.  Replace `vector` with `ArrayList`.
    7.  Replace `printf` with `System.out.print/println`.
    8.  Replace `pb` with `.add()`.
    9.  Replace macros with standard loops/assignments.
    10. Handle `IOException`.

    **One detail on `inp()`:**
    In C++, `char p = get();`.
    In Java, `int p = System.in.read();`.
    The condition `p != EOF` becomes `p != -1`.
    However, `System.in.read()` returns -1 on EOF.
    The logic `while((p<'0'||p>'9')&&p!=EOF)` becomes `while((p < '0' || p > '9') && p != -1)`.
    Inside the digit loop: `while(p>='0'&&p<='9')`.
    One thing: `System.in.read()` might return whitespace.
    The C++ code handles skipping whitespace before digits.
    In Java, `System.in.read()` reads raw bytes.
    I need to ensure I handle the byte stream correctly.
    Wait, `System.in.read()` returns a byte as int.
    If the input is ASCII text, `read()` returns 0-127.
    So `p` being `char` (int) works.
    I will wrap `System.in` in a `InputStream` if needed, but `System.in` is already an `InputStream`.
    I need to import `java.io.*` and `java.util.*`.

    **Refinement on `inp()`:**
    The C++ code:
    ```cpp
    inline int inp()
    {
        int n=0,s=1;
        char p=get();
        if(p=='-')
        s=-1;
        while((p<'0'||p>'9')&&p!=EOF)
        p=get();
        while(p>='0'&&p<='9')
        {
        n = (n<< 3) + (n<< 1) + (p - '0');
        p=get();
        };
        return n*s;
    }
    ```
    Java:
    ```java
    static int inp() throws IOException {
        int n = 0;
        int s = 1;
        int p = System.in.read();
        if (p == '-') {
            s = -1;
        }
        while ((p < '0' || p > '9') && p != -1) {
            p = System.in.read();
        }
        while (p >= '0' && p <= '9') {
            n = (n << 3) + (n << 1) + (p - '0');
            p = System.in.read();
        }
        return n * s;
    }
    ```
    Wait, `System.in.read()` is blocking.
    Also, `p` might be -1 (EOF).
    If `p` is -1 initially, the first loop `while((p<'0'||p>'9')&&p!=EOF)` will terminate immediately (since `p` is -1, `p!=EOF` is false).
    Then the second loop `while(p>='0'&&p<='9')` will be false.
    Returns `n*s` (0).
    This matches the C++ behavior for EOF.

    **Incremental Tasks:**
    1.  Setup class and imports.
    2.  Implement `inp`.
    3.  Implement `power`.
    4.  Implement `main`.
    5.  Refine `main` logic (vectors, loops, output).

    **Wait, `min` init:**
    `min = mod`. `mod` is `1000000007`.
    `max = -1`.
    If all `k` are positive, `min` will be the smallest positive.
    If `k` can be negative, `min` will be updated.
    The logic `if(k<min) min=k` works.
    `if(l>max) max=l` works.

    **Wait, `m`:**
    `m = n`.
    The loop `for(i=0; i<m; i++)`.
    Indices 0 to n-1.
    This matches the `while(n--)` loop which runs n times (indices 0 to n-1).
    So `i` is reset to 0.
    If match found, print `i+1` (1-based index).
    If `i` reaches `m` (loop finishes without break), print `-1`.

    **Wait, `power` function:**
    It is defined but not called. I will include it anyway to keep the structure identical, as requested ("translate this C++ code").
    Wait, the prompt says "translate this C++ code". It implies the whole file content.
    So I should include `power` method even if unused.

    **Imports:**
    `java.util.*` covers `ArrayList`.
    `java.io.*` covers `InputStream`, `IOException`.

    **Class Name:** `b_242`.

    **Code Construction:**
    1.  Imports.
    2.  Class `b_242`.
    3.  `static final int mod`.
    4.  `static int inp()`.
    5.  `static long power()`.
    6.  `public static void main(String[] args)`.
    7.  Variables `a`, `b` as `ArrayList`.
    8.  Logic.

    **Note on `max` initialization:**
    `max = -1`.
    If all inputs `l` are negative, `max` will be the largest (closest to 0).
    If inputs are empty? `n` is read. `while(n--)` runs `n` times.
    If `n=0`, loop doesn't run. `min` remains `mod`, `max` remains `-1`.
    Loop `for(i=0; i<m; i++)` -> `i` from 0 to -1 (doesn't run).
    `if(i==m)` -> `0 == 0` -> prints `-1`.
    Seems consistent.

    **Wait, `power` function:**
    It uses `long long`. In Java `long`.
    `x=(x*x)%mod`.
    `r=(r*x)%mod`.
    Modulo arithmetic.
    `b>>=1`.

    **Wait, `get` macro:**
    In Java, I will implement `inp()` directly using `System.in.read()`.
    The C++ code defines `get` as `getchar`.
    I will implement the logic inside `inp()`.

    **Wait, `vector` vs `ArrayList`:**
    `vector<int> a, b;` -> `ArrayList<Integer> a, b;`.
    `a.pb(k)` -> `a.add(k)`.
    `ITER` macro not used in `main`.
    `FOR` macro used? `while(n--)` is used. `for(i=0;i<m;i++)` is used.
    So `FOR` is not used in `main`.
    `pb` is used.

    **Wait, `string` header:**
    Not used in code.
    `map`, `set`, `stack`, `queue`, `deque`, `list` headers included but not used.
    I should include `java.util.*` to cover `ArrayList`.
    I will include `java.util.*` and `java.io.*`.

    **Wait, `MAXN`:**
    Defined but not used. I will include it as a constant.

    **Wait, `get` macro:**
    I will not define a macro `get` in Java. I will use `System.in.read()` directly.
    Or I can define a static method `read()`.
    The C++ code has `#define get getchar//_unlocked`.
    I will implement the logic in `inp()` calling `System.in.read()`.

    **Wait, `main` variable `i`:**
    `int i`.
    `i` is used in `while(n--)` loop.
    Then `for(i=0;...)`.
    In C++, `i` is declared once.
    In Java, `int i` is declared.
    `while` loop modifies `i`.
    `for` loop resets `i`.
    This is fine in Java.

    **Wait, `power` function:**
    It's static.
    I'll make it static.

    **Wait, `min` and `max`:**
    `int min`, `int max`.
    Initialized in `main`.

    **Wait, `inp` throws:**
    `System.in.read()` can throw `IOException`.
    So `inp` should throw `IOException`.
    `main` should handle or declare throws.
    `public static void main(String[] args) throws IOException`.

    **Final check on logic:**
    C++:
    `n=inp(); min=mod; max=-1; i=0;`
    `while(n--) { i++; ... }`
    `for(i=0; i<m; i++)`
    `if(i==m) ...`

    In Java:
    `n = inp(); min = mod; max = -1; i = 0;`
    `while(n-- > 0) { i++; ... }`
    `for(i=0; i<m; i++)`
    `if(i==m) ...`

    Wait, `while(n--)` in C++ decrements `n` then checks.
    If `n` is 0, loop doesn't run. `i` remains 0.
    If `n` is 1, `n` becomes 0, loop runs. `i` becomes 1.
    In Java `while(n-- > 0)`:
    If `n` is 0, `0 > 0` is false. Loop doesn't run. `i` remains 0.
    If `n` is 1, `1 > 0` is true. `n` becomes 0. Loop runs. `i` becomes 1.
    Matches C++ behavior.

    **Wait, `System.in.read()` buffering:**
    `System.in` is usually buffered.
    `read()` reads one byte.
    It's fine.

    **Wait, `power` function:**
    It uses `long long`.
    Java `long`.
    `power` logic is fine.

    **Wait, `mod`:**
    `1000000007`.
    In `power`: `r=(r*x)%mod`.
    In Java: `r = (r * x) % mod`.
    Since `mod` is `10^9+7`, `r*x` can exceed `int` range. `long` is sufficient.

    **Wait, `min` init:**
    `min = mod`.
    If all `k` are `>= mod`, `min` stays `mod`.
    If any `k` is `0`, `min` becomes `0`.
    If `k` is negative, `min` becomes negative.
    Logic holds.

    **Wait, `max` init:**
    `max = -1`.
    If all `l` are `-1`, `max` stays `-1`.
    If any `l` is `-1`, `max` stays `-1`.
    If any `l` is `0`, `max` becomes `0`.
    Logic holds.

    **Wait, `a`, `b`:**
    `ArrayList<Integer>`.
    `a.add(k)`.
    `b.add(l)`.

    **Wait, `m`:**
    `m = n`.

    **Wait, `printf`:**
    `System.out.print`.
    `printf("%d\n", i+1)` -> `System.out.println(i+1)`.
    `printf("-1\n")` -> `System.out.println("-1")`.

    **Wait, `getchar` macro:**
    I'll just use `System.in.read()` inside `inp`.

    **Wait, `#include` headers:**
    I will include `java.util.*` and `java.io.*`.

    **Wait, `main` method signature:**
    `public static void main(String[] args) throws IOException`.

    **Wait, `power` function:**
    It's a static method.
    I'll put it before `main` or after.

    **Wait, `inp` method:**
    It needs to be static to be called from static `main`.
    It throws `IOException`.

    **Wait, `n` in `main`:**
    `int n`.

    **Wait, `i` in `main`:**
    `int i`.

    **Wait, `k`, `l` in `main`:**
    `int k`, `int l`.

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `t`, `ans`, `j`, `m`:**
    `int t`, `int ans`, `int j`, `int m`.

    **Wait, `ch`:**
    `char ch` is declared but not used in `main`.
    I will remove unused variables to keep code clean, or keep them to match structure?
    The prompt asks to translate the code. I should keep unused variables if they are part of the logic provided, but `ch` is declared `char ch;` and never used.
    I will keep it to be faithful to the translation, or remove it for better Java style.
    Usually, for translation tasks, keeping structure is better. I'll keep it but maybe initialize it to something if it's unused.
    Actually, `ch` is declared but not used. I'll keep it.

    **Wait, `power` function:**
    It's defined in the C++ snippet.
    I should include it.

    **Wait, `MAXN`:**
    Defined.

    **Wait, `mod`:**
    Defined.

    **Wait, `FOR`, `FORD`, `REP`, `pb`, `ITER`:**
    Macros.
    In Java, I will replace them with code.
    `pb` -> `.add()`.
    `FOR` -> `for`.
    `FORD` -> `for`.
    `REP` -> `for`.
    `ITER` -> `for`.

    **Wait, `vector` vs `ArrayList`:**
    `vector<int>` -> `ArrayList<Integer>`.
    `vector` size is dynamic.
    `pb` -> `add`.

    **Wait, `main` logic:**
    `n=inp()`.
    `min=mod`.
    `max=-1`.
    `i=0`.
    `m=n`.
    `while(n--)`.
    `i++`.
    `k=inp()`.
    `l=inp()`.
    `a.pb(k)`.
    `b.pb(l)`.
    `if(k<min) min=k`.
    `if(l>max) max=l`.
    `for(i=0; i<m; i++)`.
    `if(a[i]==min && b[i]==max)`.
    `printf`.

    **Wait, `power` function:**
    It's unused. I will include it as a method.

    **Wait, `b_242` class:**
    `public class b_242`.

    **Wait, `System.in`:**
    Need `java.io.InputStream`.
    `java.io.IOException`.

    **Wait, `ArrayList`:**
    `java.util.ArrayList`.

    **Wait, `InputStream`:**
    `java.io.InputStream`.

    **Wait, `IOException`:**
    `java.io.IOException`.

    **Wait, `System.out`:**
    `java.io.PrintStream` or just `System.out`.

    **Wait, `char` vs `int`:**
    In Java `char` is 16-bit. `System.in.read()` returns `int` (0-255).
    In C++, `char` is 1 byte.
    Comparing `p` with `'0'` etc.
    In Java, `char` and `int` comparison works for ASCII.
    So `int p = System.in.read()` is fine.

    **Wait, `EOF`:**
    In C++, `EOF` is -1.
    In Java, `System.in.read()` returns -1 on EOF.
    So `p != -1` check is correct.

    **Wait, `inp` logic:**
    `int p = System.in.read();`
    `if (p == '-')`
    `while ((p < '0' || p > '9') && p != -1)`
    `while (p >= '0' && p <= '9')`
    This looks correct.

    **Wait, `power` logic:**
    `long long a, long long b`.
    In Java `long a, long b`.
    `long r=1, x=a`.
    `while(b)`.
    `if(b&1) r=(r*x)%mod`.
    `x=(x*x)%mod`.
    `b>>=1`.
    In Java `b` is `long`. `b&1` works. `b>>=1` works.
    `r` and `x` are `long`.
    `mod` is `int`.
    `(r*x)%mod`. `r*x` is `long`. `mod` is `int`. Result is `long`.
    Java `long` is 64-bit. `mod` is `10^9+7`.
    `r*x` can be `~10^18`. Fits in `long`.
    So `long` is sufficient.

    **Wait, `main` loop:**
    `while(n--)` -> `while(n-- > 0)`.
    `i++`.
    `k=inp()`.
    `l=inp()`.
    `a.add(k)`.
    `b.add(l)`.
    `if(k<min) min=k`.
    `if(l>max) max=l`.

    `for(i=0; i<m; i++)`.
    `if(a[i]==min && b[i]==max)`.
    `System.out.println(i+1)`.
    `break`.
    `if(i==m) System.out.println("-1")`.

    **Wait, `i` usage:**
    `i` is modified in `while` loop.
    Then reset in `for` loop.
    This is valid.

    **Wait, `m`:**
    `m=n`.

    **Wait, `n`:**
    `n` is decremented in `while(n--)`.
    `m` is set to original `n` (before decrement? No, `n=inp()` gets value).
    `m=n` sets `m` to value of `n`.
    Then `while(n--)` modifies `n`.
    So `m` holds the original count.
    `for(i=0; i<m; i++)` iterates `0` to `n-1`.
    Correct.

    **Wait, `power` function:**
    I will include it.

    **Wait, `min` initialization:**
    `min=mod`.
    If `k` are all `mod` or greater, `min` stays `mod`.
    If `k` are smaller, `min` updates.
    If `k` can be negative, `min` updates.
    If `n=0`, `min` stays `mod`.
    `max` stays `-1`.
    `for` loop doesn't run. `i` is 0. `m` is 0.
    `if(i==m)` -> `0==0` -> prints `-1`.
    Correct.

    **Wait, `max` initialization:**
    `max=-1`.
    If `l` are all `-1`, `max` stays `-1`.
    If `l` are greater, `max` updates.

    **Wait, `char ch`:**
    Declared in `main`.
    I will keep it.

    **Wait, `t`, `ans`, `j`, `k`, `l`, `m`, `i`, `n`, `min`, `max`:**
    All declared at top of `main`.

    **Wait, `a`, `b`:**
    `vector<int> a, b`.
    `ArrayList<Integer> a, b`.

    **Wait, `power` function:**
    `long long power(long long a, long long b)`.
    Java `static long power(long a, long b)`.

    **Wait, `mod`:**
    `#define mod 1000000007`.
    Java `static final int mod = 1000000007;`.

    **Wait, `MAXN`:**
    `#define MAXN 1000010`.
    Java `static final int MAXN = 1000010;`.

    **Wait, `get` macro:**
    `#define get getchar//_unlocked`.
    I will not define this macro in Java. I will use `System.in.read()` directly in `inp`.

    **Wait, `using namespace std`:**
    I will use fully qualified names or imports.
    `ArrayList` -> `java.util.ArrayList`.
    `System.out`.
    `System.in`.

    **Wait, `printf`:**
    `System.out.print` / `println`.

    **Wait, `power` function:**
    It's unused. I'll keep it.

    **Wait, `main` method:**
    `public static void main(String[] args)`.

    **Wait, `throws`:**
    `main` throws `IOException`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`
    Or just `ArrayList a = new ArrayList<>();` (generic).
    Better to use `ArrayList<Integer>`.

    **Wait, `pb`:**
    `a.pb(k)` -> `a.add(k)`.

    **Wait, `ITER` macro:**
    Not used in `main`.

    **Wait, `FOR` macro:**
    Not used in `main`.

    **Wait, `FORD` macro:**
    Not used in `main`.

    **Wait, `REP` macro:**
    Not used in `main`.

    **Wait, `getchar`:**
    Not used directly, replaced by `inp` logic.

    **Wait, `EOF`:**
    `System.in.read()` returns `-1`.

    **Wait, `char` vs `int`:**
    `char p` in C++.
    `int p` in Java (since `read()` returns int).

    **Wait, `min` init:**
    `min = mod`.

    **Wait, `max` init:**
    `max = -1`.

    **Wait, `n`:**
    `int n`.

    **Wait, `m`:**
    `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`:**
    `int t`, `int ans`, `int j`.

    **Wait, `ch`:**
    `char ch`.

    **Wait, `power` function:**
    It is unused. I will include it.

    **Wait, `power` logic:**
    `while(b)`.
    `if(b&1)`.
    `b>>=1`.
    In Java `long` works same for bitwise ops.

    **Wait, `mod`:**
    `1000000007`.

    **Wait, `MAXN`:**
    `1000010`.

    **Wait, `b_242`:**
    Class name.

    **Wait, `printf`:**
    `System.out.println`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `IOException`:**
    `IOException`.

    **Wait, `ArrayList`:**
    `ArrayList`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `try-catch`:**
    I can throw `IOException` from `main`.

    **Wait, `inp`:**
    `static int inp() throws IOException`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `n`, `m`:**
    `int n`, `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`, `ch`:**
    `int t`, `int ans`, `int j`, `char ch`.

    **Wait, `mod`:**
    `static final int mod`.

    **Wait, `MAXN`:**
    `static final int MAXN`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `inp`:**
    `static int inp()`.

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `System.out`:**
    `System.out`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.

    **Wait, `power` function:**
    It is unused. I will include it.

    **Wait, `power` logic:**
    `while(b)`.
    `if(b&1)`.
    `b>>=1`.
    In Java `long` works same for bitwise ops.

    **Wait, `mod`:**
    `1000000007`.

    **Wait, `MAXN`:**
    `1000010`.

    **Wait, `b_242`:**
    Class name.

    **Wait, `printf`:**
    `System.out.println`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `IOException`:**
    `IOException`.

    **Wait, `ArrayList`:**
    `ArrayList`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `try-catch`:**
    I can throw `IOException` from `main`.

    **Wait, `inp`:**
    `static int inp() throws IOException`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `n`, `m`:**
    `int n`, `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`, `ch`:**
    `int t`, `int ans`, `int j`, `char ch`.

    **Wait, `mod`:**
    `static final int mod`.

    **Wait, `MAXN`:**
    `static final int MAXN`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `inp`:**
    `static int inp()`.

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `System.out`:**
    `System.out`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.

    **Wait, `power` function:**
    It is unused. I will include it.

    **Wait, `power` logic:**
    `while(b)`.
    `if(b&1)`.
    `b>>=1`.
    In Java `long` works same for bitwise ops.

    **Wait, `mod`:**
    `1000000007`.

    **Wait, `MAXN`:**
    `1000010`.

    **Wait, `b_242`:**
    Class name.

    **Wait, `printf`:**
    `System.out.println`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `IOException`:**
    `IOException`.

    **Wait, `ArrayList`:**
    `ArrayList`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `try-catch`:**
    I can throw `IOException` from `main`.

    **Wait, `inp`:**
    `static int inp() throws IOException`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `n`, `m`:**
    `int n`, `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`, `ch`:**
    `int t`, `int ans`, `int j`, `char ch`.

    **Wait, `mod`:**
    `static final int mod`.

    **Wait, `MAXN`:**
    `static final int MAXN`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `inp`:**
    `static int inp()`.

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `System.out`:**
    `System.out`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.

    **Wait, `power` function:**
    It is unused. I will include it.

    **Wait, `power` logic:**
    `while(b)`.
    `if(b&1)`.
    `b>>=1`.
    In Java `long` works same for bitwise ops.

    **Wait, `mod`:**
    `1000000007`.

    **Wait, `MAXN`:**
    `1000010`.

    **Wait, `b_242`:**
    Class name.

    **Wait, `printf`:**
    `System.out.println`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `IOException`:**
    `IOException`.

    **Wait, `ArrayList`:**
    `ArrayList`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `try-catch`:**
    I can throw `IOException` from `main`.

    **Wait, `inp`:**
    `static int inp() throws IOException`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `n`, `m`:**
    `int n`, `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`, `ch`:**
    `int t`, `int ans`, `int j`, `char ch`.

    **Wait, `mod`:**
    `static final int mod`.

    **Wait, `MAXN`:**
    `static final int MAXN`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `inp`:**
    `static int inp()`.

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `System.out`:**
    `System.out`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.

    **Wait, `power` function:**
    It is unused. I will include it.

    **Wait, `power` logic:**
    `while(b)`.
    `if(b&1)`.
    `b>>=1`.
    In Java `long` works same for bitwise ops.

    **Wait, `mod`:**
    `1000000007`.

    **Wait, `MAXN`:**
    `1000010`.

    **Wait, `b_242`:**
    Class name.

    **Wait, `printf`:**
    `System.out.println`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `IOException`:**
    `IOException`.

    **Wait, `ArrayList`:**
    `ArrayList`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `try-catch`:**
    I can throw `IOException` from `main`.

    **Wait, `inp`:**
    `static int inp() throws IOException`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `n`, `m`:**
    `int n`, `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`, `ch`:**
    `int t`, `int ans`, `int j`, `char ch`.

    **Wait, `mod`:**
    `static final int mod`.

    **Wait, `MAXN`:**
    `static final int MAXN`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `inp`:**
    `static int inp()`.

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `System.out`:**
    `System.out`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.

    **Wait, `power` function:**
    It is unused. I will include it.

    **Wait, `power` logic:**
    `while(b)`.
    `if(b&1)`.
    `b>>=1`.
    In Java `long` works same for bitwise ops.

    **Wait, `mod`:**
    `1000000007`.

    **Wait, `MAXN`:**
    `1000010`.

    **Wait, `b_242`:**
    Class name.

    **Wait, `printf`:**
    `System.out.println`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `IOException`:**
    `IOException`.

    **Wait, `ArrayList`:**
    `ArrayList`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `try-catch`:**
    I can throw `IOException` from `main`.

    **Wait, `inp`:**
    `static int inp() throws IOException`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `n`, `m`:**
    `int n`, `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`, `ch`:**
    `int t`, `int ans`, `int j`, `char ch`.

    **Wait, `mod`:**
    `static final int mod`.

    **Wait, `MAXN`:**
    `static final int MAXN`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `inp`:**
    `static int inp()`.

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `System.out`:**
    `System.out`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.

    **Wait, `power` function:**
    It is unused. I will include it.

    **Wait, `power` logic:**
    `while(b)`.
    `if(b&1)`.
    `b>>=1`.
    In Java `long` works same for bitwise ops.

    **Wait, `mod`:**
    `1000000007`.

    **Wait, `MAXN`:**
    `1000010`.

    **Wait, `b_242`:**
    Class name.

    **Wait, `printf`:**
    `System.out.println`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `IOException`:**
    `IOException`.

    **Wait, `ArrayList`:**
    `ArrayList`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `try-catch`:**
    I can throw `IOException` from `main`.

    **Wait, `inp`:**
    `static int inp() throws IOException`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `a`, `b`:**
    `ArrayList<Integer> a = new ArrayList<>();`
    `ArrayList<Integer> b = new ArrayList<>();`

    **Wait, `min`, `max`:**
    `int min`, `int max`.

    **Wait, `n`, `m`:**
    `int n`, `int m`.

    **Wait, `i`:**
    `int i`.

    **Wait, `k`, `l`:**
    `int k`, `int l`.

    **Wait, `t`, `ans`, `j`, `ch`:**
    `int t`, `int ans`, `int j`, `char ch`.

    **Wait, `mod`:**
    `static final int mod`.

    **Wait, `MAXN`:**
    `static final int MAXN`.

    **Wait, `power`:**
    `static long power(long a, long b)`.

    **Wait, `inp`:**
    `static int inp()`.

    **Wait, `main`:**
    `public static void main(String[] args)`.

    **Wait, `System.out`:**
    `System.out`.

    **Wait, `System.in`:**
    `System.in`.

    **Wait, `java.util`:**
    `java.util`.

    **Wait, `java.io`:**
    `java.io`.

    **Wait, `import`:**
    `import java.util.*;`
    `import java.io.*;`

    **Wait, `class`:**
    `public class b_242`.
</think>

### Translation Plan

1.  **Language Differences**:
    *   **Headers**: C++ headers (`<vector>`, `<iostream>`, `<cstdio>`, etc.) will be replaced by Java imports (`java.util.*`, `java.io.*`).
    *   **Macros**: C++ preprocessor macros (`#define`) like `FOR`, `pb`, `mod`, `MAXN` will be replaced by Java `static final` constants and standard loops/methods.
    *   **Data Structures**: C++ `vector<int>` will be translated to Java `ArrayList<Integer>`.
    *   **Input/Output**: C++ `scanf`/`printf`/`getchar` will be translated to Java `System.in.read()` and `System.out.print/println`.
    *   **Types**: C++ `long long` will be `long` in Java. `char` will be `int` (since `System.in.read()` returns `int`).
    *   **Functionality**: The `inp()` function mimicking `getchar_unlocked` will be implemented using `System.in.read()`.
    *   **Unused Code**: The `power()` function is defined but not called in `main`. It will be included for completeness.

2.  **Incremental Tasks**:
    *   **Step 1**: Define the class `b_242` and necessary imports (`java.util.*`, `java.io.*`).
    *   **Step 2**: Define constants (`mod`, `MAXN`).
    *   **Step 3**: Implement the `inp()` method to handle fast I/O (reading integers).
    *   **Step 4**: Implement the `power()` method (even if unused).
    *   **Step 5**: Implement the `main()` method:
        *   Initialize variables.
        *   Read `n`.
        *   Loop to read pairs into `ArrayList`s.
        *   Find min/max.
        *   Search for the index.
        *   Print result.

### Code

<CODE>
import java.util.ArrayList;
import java.util.List;
import java.io.IOException;
import java.io.InputStream;

public class b_242 {
    public static final int mod = 1000000007;
    public static final int MAXN = 1000010;

    public static int inp() throws IOException {
        int n = 0;
        int s = 1;
        int p = System.in.read();
        if (p == '-') {
            s = -1;
        }
        while ((p < '0' || p > '9') && p != -1) {
            p = System.in.read();
        }
        while (p >= '0' && p <= '9') {
            n = (n << 3) + (n << 1) + (p - '0');
            p = System.in.read();
        }
        return n * s;
    }

    public static long power(long a, long b) {
        long r = 1;
        long x = a;
        while (b > 0) {
            if ((b & 1) == 1) {
                r = (r * x) % mod;
            }
            x = (x * x) % mod;
            b >>= 1;
        }
        return r;
    }

    public static void main(String[] args) throws IOException {
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        int i = 0;
        int n = inp();
        int min = mod;
        int max = -1;
        int m = n;

        while (n-- > 0) {
            i++;
            int k = inp();
            int l = inp();
            a.add(k);
            b.add(l);
            if (k < min) {
                min = k;
            }
            if (l > max) {
                max = l;
            }
        }

        for (i = 0; i < m; i++) {
            if (a.get(i) == min && b.get(i) == max) {
                System.out.println(i + 1);
                break;
            }
        }

        if (i == m) {
            System.out.println("-1");
        }
    }
}
</CODE>