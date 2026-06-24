Translate this C++ code to Java code. The main class name should be c_1077. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define RI(x) x = rit()
#define RII(a,b) a = rit(), b = rit()
#define RIII(a,b,c) a = rit(), b = rit(), c = rit()
#define REP(I, N) for(int I=0;I<(N);I++)
#define REPP(I, N) for(int I=1;I<=(N);I++)
#define SZ(x) (int)(x).size()
#define P pair<int, int>
#define F first
#define S second
#define PB(x) push_back(x)
#define endl "\n"
#define ll long long
#define DBAC(x,y) cout << x << " " << y << endl
#define int long long

//===================================================//

#define N 200000
#define modn 1000000007
#define INF 2147483647

using namespace std;
inline int rit(){
    int f=0,key=1;
    char ch;
    do{
        ch = getchar();
        if(ch=='-') key=-1;
    }while(ch<'0'||ch>'9');
    do{
        f = f*10+ch-'0';
        ch = getchar();
    }while(ch>='0'&&ch<='9');
    return f*key;
}
int n;
int arr[N+5], brr[N+5], sum ;
bool bye[1000005];
int32_t main(void){
    RI(n);
    REP(i,n){
        RI(arr[i]);
        sum+=arr[i];
        brr[i] = arr[i];
    }
    sort(arr, arr+n);
    REP(i,n-1){
        if( sum - arr[i] - arr[n-1] == arr[n-1] ){
            bye[ arr[i] ] = true;
        }
    }
    if( sum - arr[n-1] - arr[n-2] == arr[n-2] ) bye[ arr[n-1] ] = true;
    int cnt = 0;
    REP(i,n){
        if( bye[ brr[i] ] ) cnt++;
    }
    printf("%lld\n",cnt);
    REP(i,n) if( bye[ brr[i] ] ) printf("%lld%c",i+1," \n"[i==n-1]);
	return 0;
}

Here is the plan for the translation and the resulting Java code.

### Translation Plan

1.  **Dependencies and Imports**:
    *   The C++ code uses `<bits/stdc++.h>`, which includes all standard libraries. In Java, we must explicitly import `java.util.*` and `java.io.*` to handle arrays, sorting, and fast I/O.

2.  **Fast I/O (`rit` function)**:
    *   The C++ code uses a custom `rit()` function for fast integer reading, bypassing `cin` synchronization.
    *   **Translation**: Create a static method `read()` in Java. It will read characters from `System.in` (via `InputStream` or `BufferedReader`) and parse integers, handling negative numbers.

3.  **Macros and Constants**:
    *   `IOS`: C++ uses `ios::sync_with_stdio(0), cin.tie(0)`. In Java, we can achieve similar performance by using `BufferedReader` and `PrintWriter`/`BufferedWriter` directly.
    *   `RI`, `RII`, `RIII`, `REP`, `REPP`, `SZ`, `P`, `F`, `S`, `PB`, `DBAC`: These are C++ specific macros for loops, pairs, and printing. We will replace these with standard Java loops and `System.out` or `PrintWriter`.
    *   `ll` (`long long`): C++ `long long` maps to Java `long`.
    *   `int`: In the provided C++ code, `#define int long long` changes all `int` types to `long long`. We must ensure all integer variables in Java are `long` to match this logic.

4.  **Variables**:
    *   `n`, `arr`, `brr`, `sum`: These correspond to Java arrays (`long[]`) and variables. Note that `arr` and `brr` are size `N+5` (200005).
    *   `bye`: A boolean array. In C++, this is `bool`. In Java, it is `boolean[]`.
    *   `INF`: `2147483647` (fits in `int` or `long`, here used as `long`).

5.  **Logic Implementation**:
    *   **Reading `n`**: Call `read()`.
    *   **Reading Array**: Loop `n` times, read into `arr`, update `sum`, copy to `brr`.
    *   **Sorting**: C++ uses `std::sort`. Java uses `Arrays.sort()`.
    *   **Logic**: The logic inside `main` remains the same, but syntax changes (e.g., `arr[i]` instead of `arr[i]`, `==` instead of `==` for comparison).
    *   **Output**: C++ uses `printf` with `%lld`. Java uses `PrintWriter` or `System.out.println` with `long` values.

6.  **Class Structure**:
    *   The main class name must be `c_1077`.
    *   The method `main` becomes `public static void main(String[] args)`.

### Incremental Tasks
1.  Define the `FastScanner` class/method to replace `rit()`.
2.  Translate variable declarations (`n`, arrays, `sum`, `bye`).
3.  Translate the input reading loop.
4.  Translate the sorting logic.
5.  Translate the logic checking `sum` conditions and marking `bye`.
6.  Translate the counting and printing logic.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1077 {
    // Constants
    static final int N = 200000;
    static final long modn = 1000000007L;
    static final long INF = 2147483647L;

    // Global variables matching C++ scope
    static int n;
    static long[] arr = new long[N + 5];
    static long[] brr = new long[N + 5];
    static long sum = 0;
    static boolean[] bye = new boolean[1000005];

    // Fast Input Reader replacing 'rit' function
    static int read() {
        int f = 0;
        int key = 1;
        int ch = 0;
        try {
            InputStream is = System.in;
            InputStreamReader isr = new InputStreamReader(is, "UTF-8");
            java.io.BufferedReader br = new java.io.BufferedReader(isr);
            // Peek logic is hard with standard BufferedReader, so we read char by char or use StringTokenizer.
            // To match the exact logic of 'rit' (which reads char by char), we implement a simple parser.
            // However, standard Java IO usually buffers. Let's implement a standard FastScanner style logic
            // that mimics the behavior of reading integers efficiently.
            // Since the C++ code uses 'getchar', we simulate reading bytes.
            // Using a simple approach with a buffer to be safe and fast.
        } catch (IOException e) {
            e.printStackTrace();
        }
        return 0; 
    }
    
    // Better implementation of read() to match the C++ 'rit' logic (handling whitespace and negative)
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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
            if (s == null) return 0;
            int c = s.charAt(0);
            int f = 0;
            int key = 1;
            // Check for negative
            if (c == '-') {
                key = -1;
            } else {
                f = c - '0';
            }
            // Skip whitespace before number if logic strictly follows 'do-while' structure
            // But standard StringTokenizer handles whitespace. 
            // The C++ 'rit' logic is specific: it skips non-digit chars until digit, then reads digits.
            // StringTokenizer handles this naturally.
            int res = 0;
            for (int i = 1; i < s.length(); i++) {
                res = res * 10 + (s.charAt(i) - '0');
            }
            return res * key;
        }
        
        long nextLong() {
            String s = next();
            if (s == null) return 0;
            int key = 1;
            if (s.charAt(0) == '-') {
                key = -1;
            }
            long res = 0;
            for (int i = 1; i < s.length(); i++) {
                res = res * 10 + (s.charAt(i) - '0');
            }
            return res * key;
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // RI(n); -> Read n
        // Note: The C++ code defines 'int' as 'long long'. So n should be long.
        // However, N is 200000, so int is fine for index, but the variable 'n' itself might be large?
        // The problem statement implies 'n' is count, likely fits in int. But let's check usage.
        // arr is long, sum is long.
        // Let's read n as int for array sizing, but treat it as long if needed.
        // The C++ code: int n; -> long long n.
        // We will use long for n to be safe and consistent with C++ 'int' definition.
        
        String nStr = sc.next();
        if (nStr == null) return;
        n = Integer.parseInt(nStr);

        // REP(i,n) -> Loop 0 to n-1
        for (int i = 0; i < n; i++) {
            // RI(arr[i]);
            arr[i] = sc.nextLong();
            // sum += arr[i];
            sum += arr[i];
            // brr[i] = arr[i];
            brr[i] = arr[i];
        }

        // sort(arr, arr+n) -> Arrays.sort
        // In C++, sort is on long long. In Java, Arrays.sort(long[]) sorts primitives.
        // However, Arrays.sort(long[]) is Dual-Pivot Quicksort.
        Arrays.sort(arr, 0, n);

        // Logic part
        // REP(i, n-1) -> Loop 0 to n-2
        // Logic: if (sum - arr[i] - arr[n-1] == arr[n-1])
        for (int i = 0; i < n - 1; i++) {
            long currentSum = sum - arr[i] - arr[n - 1];
            if (currentSum == arr[n - 1]) {
                bye[arr[i]] = true;
            }
        }

        // Special check for last element
        // if (sum - arr[n-1] - arr[n-2] == arr[n-2])
        if (n >= 2) {
            long currentSum = sum - arr[n - 1] - arr[n - 2];
            if (currentSum == arr[n - 2]) {
                bye[arr[n - 1]] = true;
            }
        }

        // Count
        long cnt = 0;
        // REP(i,n)
        for (int i = 0; i < n; i++) {
            if (bye[brr[i]]) cnt++;
        }

        // printf("%lld\n", cnt);
        out.println(cnt);

        // REP(i,n) if (bye[brr[i]]) printf("%lld%c", i+1, " \n"[i==n-1]);
        for (int i = 0; i < n; i++) {
            if (bye[brr[i]]) {
                out.print((i + 1));
                if (i == n - 1) {
                    out.println();
                } else {
                    out.print(" ");
                }
            }
        }

        out.flush();
    }
}
```

Wait, looking at the C++ code `int n;` followed by `#define int long long`.
This means `n` is effectively `long long`.
In Java, `n` is `int` in my code above because `N` is `200000`.
If the input `n` is larger than `200000`, the array `arr[N+5]` would throw an IndexOutOfBoundsException in C++ if `n` was larger than `N`.
However, the problem statement says `N` is 200000. So `n` is bounded by `N`.
Therefore, `int n` in Java is sufficient.
But to be strictly faithful to `#define int long long`, I should declare `n` as `long`.
Let's adjust `n` to `long`.

Also, the C++ `sort(arr, arr+n)` sorts the whole array up to `n`.
In Java `Arrays.sort(arr, 0, n)` does exactly that.

One detail: `bye` array size is `1000005`. This implies values in `arr` are up to `1000000`.
If `n` is up to `200000`, and values are up to `1000000`, `arr` needs to be `long[]` (which it is). `bye` needs to be indexed by value.
If `arr` values are `long`, `bye` index must be `long`? No, `bye` is `bool[1000005]`. This implies values fit in `int` range (up to 1000004).
Wait, if `arr` is `long[]`, but `bye` is indexed by `arr[i]`, then `arr[i]` must fit in the index range of `bye`.
So `arr` values are `int` range (up to 1000000).
However, `sum` is `long`. `sum - arr[i] - arr[n-1]` is `long`.
Comparing `long` with `arr[n-1]` (which is `long` in C++ due to `#define int long long`).
So `arr` elements are `long` values.
But `bye` is `bool[1000005]`. This suggests values are small enough to be `int` indices.
In C++, `int` is `long long` (64-bit). So `arr[i]` is `long long`.
So `bye` array index is `long long`.
In Java, array indices must be `int`.
So `bye` array size `1000005` implies the maximum value stored in `arr` is less than `1000005`.
This fits in `int`.
So `arr` values are effectively `int` range, even though `sum` is `long`.
Wait, if `arr` is `long[]`, and `bye` is `boolean[1000005]`, accessing `bye[arr[i]]` requires casting `arr[i]` to `int`.
Since `arr[i]` values are bounded by `1000005` (based on `bye` size), casting to `int` is safe.

Let's refine the Java code to be precise.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1077 {
    // Constants
    static final int N = 200000;
    static final long modn = 1000000007L;
    static final long INF = 2147483647L;

    // Global variables
    // In C++: int n; -> #define int long long -> n is long long
    // In Java: long n
    static long n;
    
    // In C++: int arr[N+5], brr[N+5] -> #define int long long -> arr, brr are long[]
    static long[] arr = new long[N + 5];
    static long[] brr = new long[N + 5];
    
    // In C++: bool bye[1000005]; -> Java: boolean[]
    // Since C++ int is long long, but array size is fixed 1000005, 
    // it implies the values in arr are <= 1000005. 
    // So casting long to int for index is safe.
    static boolean[] bye = new boolean[1000005];
    
    // In C++: int32_t main -> Java: public static void main
    // sum is declared as int in C++ but used with long long?
    // C++: int sum; -> #define int long long -> sum is long long
    static long sum = 0;

    // Fast Input Reader
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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

        long nextLong() {
            String s = next();
            if (s == null) return 0;
            long res = 0;
            // Handle negative
            if (s.charAt(0) == '-') {
                res = -1;
            } else {
                res = 0;
            }
            // Parse digits
            for (int i = 0; i < s.length(); i++) {
                if (Character.isDigit(s.charAt(i))) {
                    res = res * 10 + (s.charAt(i) - '0');
                } else {
                    break;
                }
            }
            // Logic correction: The C++ 'rit' reads char by char.
            // If s is "-123", it reads '-', then '1', '2', '3'.
            // My tokenizer approach gets "-123" as one string.
            // The C++ logic:
            // do { ch=getchar(); } while (not digit); -> skips leading non-digits
            // do { f=f*10+ch; ch=getchar(); } while (digit);
            // So it handles negative sign separately.
            // If string is "-123", s.charAt(0) is '-'.
            // res starts at -1. Loop continues for '1','2','3'.
            // Wait, if s is "-123", res starts at -1.
            // i=0: char is '-'. Not digit. Break?
            // No, the C++ code logic:
            // 1. Skip non-digits until digit found.
            // 2. If char was '-', key = -1.
            // 3. Read digits.
            // If input is "-123", first char is '-'. It skips it?
            // No, 'rit' logic:
            // do { ch=getchar(); if(ch=='-') key=-1; } while(ch<'0'||ch>'9');
            // So it reads '-', sets key=-1. Then loop continues until it finds a digit.
            // So "-123" -> ch='-', key=-1. ch='1' (digit). Loop breaks.
            // Then second loop reads '1', '2', '3'.
            // So "-123" -> key=-1, f=123. Result -123.
            // My tokenizer approach:
            // If string is "-123".
            // res = -1.
            // i=0: '-'. Not digit.
            // This logic is flawed for tokenizer.
            // Let's implement a custom char-by-char reader to match C++ exactly.
            // Or simpler: parse the string manually.
            // If string starts with '-', ignore it, parse rest as positive.
            // But what if input is "1-2"? C++ 'rit' reads '1', then stops at '-'.
            // So 'rit' reads one integer at a time skipping whitespace.
            // Tokenizer splits by whitespace. So "-123" is one token.
            // If token is "-123", we parse it as -123.
            // If token is "123", we parse as 123.
            // If token is "1-2", C++ would read '1', then stop. Next call reads '-2'.
            // Since standard inputs are usually well-formed integers separated by whitespace,
            // parsing the token as a Long is safe enough for competitive programming unless specific edge cases exist.
            // Given the C++ code reads char by char skipping non-digits,
            // we can assume tokens are clean integers.
            // So Long.parseLong is sufficient.
            return Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // RI(n);
        String nStr = sc.next();
        if (nStr == null) return;
        n = Long.parseLong(nStr);

        // REP(i,n)
        for (int i = 0; i < n; i++) {
            // RI(arr[i]);
            arr[i] = sc.nextLong();
            // sum += arr[i];
            sum += arr[i];
            // brr[i] = arr[i];
            brr[i] = arr[i];
        }

        // sort(arr, arr+n)
        Arrays.sort(arr, 0, (int)n); // Cast n to int for array index

        // REP(i, n-1)
        // Loop 0 to n-2
        for (int i = 0; i < n - 1; i++) {
            // if( sum - arr[i] - arr[n-1] == arr[n-1] )
            if (sum - arr[i] - arr[(int)n - 1] == arr[(int)n - 1]) {
                // bye[ arr[i] ] = true;
                // arr[i] is long. bye is boolean[].
                // We must cast to int.
                // Assuming arr[i] fits in int range (based on bye array size).
                bye[(int)arr[i]] = true;
            }
        }

        // Special check
        // if( sum - arr[n-1] - arr[n-2] == arr[n-2] )
        // Need n >= 2
        if (n >= 2) {
            if (sum - arr[(int)n - 1] - arr[(int)n - 2] == arr[(int)n - 2]) {
                bye[(int)arr[(int)n - 1]] = true;
            }
        }

        // Count
        long cnt = 0;
        // REP(i,n)
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) cnt++;
        }

        // printf("%lld\n", cnt);
        out.println(cnt);

        // REP(i,n) if (bye[brr[i]]) printf("%lld%c", i+1, " \n"[i==n-1]);
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) {
                out.print((i + 1));
                if (i == n - 1) {
                    out.println();
                } else {
                    out.print(" ");
                }
            }
        }

        out.flush();
    }
}
```

Wait, `FastReader` logic with `Long.parseLong` is risky if the C++ code reads char-by-char and there are weird whitespaces or negative signs inside the token logic.
However, `StringTokenizer` splits by whitespace.
The C++ `rit` function:
```cpp
    do{
        ch = getchar();
        if(ch=='-') key=-1;
    }while(ch<'0'||ch>'9');
    do{
        f = f*10+ch-'0';
        ch = getchar();
    }while(ch>='0'&&ch<='9');
```
This logic skips all non-digit characters until the first digit is found.
If the input is `1 2`, it reads `1`. Then next call reads `2`.
If the input is `-1 2`, it reads `-1`. Then next call reads `2`.
If the input is `1-2` (no space), it reads `1`, stops at `-`. Next call reads `-2`.
`StringTokenizer` splits by whitespace. So `1-2` is one token.
If I use `Long.parseLong("1-2")`, it throws exception.
But in standard competitive programming inputs, numbers are separated by whitespace.
So `Long.parseLong` is safe.

However, to be strictly faithful to the "plan", I should implement the `read` logic in Java to mimic the C++ `rit` function exactly.
The C++ `rit` function is a custom parser.
I will implement a `read()` method that mimics `getchar` behavior.

```java
    static int readChar() throws IOException {
        // We can use a buffer to simulate getchar
        // But for simplicity and speed, we can just read bytes from System.in
        // Or use a standard FastScanner that reads int.
        // Let's stick to the standard FastScanner approach but ensure it handles the 'rit' logic.
        // Actually, the C++ 'rit' logic is: skip non-digits, handle sign, read digits.
        // This is exactly what a standard integer parser does.
        // I will use a standard FastReader that reads integers.
        return 0; 
    }
```
Actually, implementing a byte-by-byte reader in Java is tedious and prone to errors compared to `StringTokenizer`.
Given the constraints and typical CP environment, `StringTokenizer` is the standard Java equivalent for `rit`.
I will proceed with `StringTokenizer`.

One small correction: `n` is `long` in C++ (due to `#define int long long`).
But `arr` is `long[N+5]`. `N` is `200000`.
So `n` fits in `int` (up to 200000).
But the type definition is `long long`.
So in Java, `n` should be `long`.
When using `n` as array index `arr[n]`, it must be cast to `int`.
`arr` size is `N+5` which is `200005`.
So `n` must be `<= 200005`.
So `(int)n` is safe.

Final check on `bye` array size.
`bye` is `bool[1000005]`.
This means `arr[i]` values are expected to be `<= 1000004`.
If `arr[i]` is `long`, casting to `int` is safe if values are small.
If `arr[i]` is large (e.g. `10^9`), casting to `int` would be wrong or cause OOB.
But the array `bye` is fixed size `1000005`.
This implies the problem guarantees `arr[i] <= 1000004`.
So `(int)arr[i]` is safe.

One detail: `sum` is `long`. `arr` is `long`.
`sum - arr[i] - arr[n-1]` is `long`.
Comparison `== arr[n-1]` is `long`.
So logic is preserved.

The class name must be `c_1077`.

One detail: `RII`, `RIII` macros are defined but not used in the code provided.
The code uses `RI` for `n`, `arr[i]`.
So I only need `read()` and `readLong()`.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1077 {
    // Constants
    static final int N = 200000;
    static final long modn = 1000000007L;
    static final long INF = 2147483647L;

    // Global variables
    // C++: int n; #define int long long -> n is long
    static long n;
    
    // C++: int arr[N+5] -> #define int long long -> arr is long[]
    static long[] arr = new long[N + 5];
    static long[] brr = new long[N + 5];
    
    // C++: bool bye[1000005]
    static boolean[] bye = new boolean[1000005];
    
    // C++: int sum; -> #define int long long -> sum is long
    static long sum = 0;

    // Fast Input Reader
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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

        long nextLong() {
            String s = next();
            if (s == null) return 0;
            return Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // RI(n);
        String nStr = sc.next();
        if (nStr != null) {
            n = Long.parseLong(nStr);
        }

        // REP(i,n)
        for (int i = 0; i < n; i++) {
            // RI(arr[i]);
            arr[i] = sc.nextLong();
            // sum += arr[i];
            sum += arr[i];
            // brr[i] = arr[i];
            brr[i] = arr[i];
        }

        // sort(arr, arr+n)
        // C++ sort(arr, arr+n) sorts elements from index 0 to n-1
        Arrays.sort(arr, 0, (int)n);

        // REP(i, n-1)
        // Loop 0 to n-2
        for (int i = 0; i < n - 1; i++) {
            // if( sum - arr[i] - arr[n-1] == arr[n-1] )
            if (sum - arr[i] - arr[(int)n - 1] == arr[(int)n - 1]) {
                // bye[ arr[i] ] = true;
                bye[(int)arr[i]] = true;
            }
        }

        // Special check
        // if( sum - arr[n-1] - arr[n-2] == arr[n-2] )
        // Need n >= 2
        if (n >= 2) {
            if (sum - arr[(int)n - 1] - arr[(int)n - 2] == arr[(int)n - 2]) {
                bye[(int)arr[(int)n - 1]] = true;
            }
        }

        // Count
        long cnt = 0;
        // REP(i,n)
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) cnt++;
        }

        // printf("%lld\n", cnt);
        out.println(cnt);

        // REP(i,n) if (bye[brr[i]]) printf("%lld%c", i+1, " \n"[i==n-1]);
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) {
                out.print((i + 1));
                if (i == n - 1) {
                    out.println();
                } else {
                    out.print(" ");
                }
            }
        }

        out.flush();
    }
}
```
This looks complete and correct.

One minor thing: `n` is `long`. `N` is `int`.
`arr` is `long[N+5]`.
If `n` > `N`, `arr` access will fail.
The problem statement defines `N` as 200000.
It is implied that `n` <= `N`.
So `arr` size is sufficient.

Final check on the `bye` array indexing.
`bye` is `bool[1000005]`.
If `arr[i]` > `1000004`, `bye[(int)arr[i]]` will throw ArrayIndexOutOfBoundsException.
However, since `bye` is declared with this size, it is guaranteed that `arr[i]` values fit within this range.
So the cast `(int)arr[i]` is safe.

I will remove the comments about C++ specific features from the final output to keep it clean, as requested ("output the code of the resulting program").
Wait, the prompt says "First, make a plan... Then, output the code...".
So I should output the plan text first, then the code block.

One detail: `#define int long long`.
In C++, `int` becomes 64-bit.
In Java, `int` is 32-bit.
So I must use `long` everywhere `int` was used in C++.
My code uses `long` for `n`, `sum`, `arr`, `brr`. This is correct.

Also `printf("%lld\n", cnt)` uses `long long`.
My code uses `out.println(cnt)` where `cnt` is `long`. This is correct.

One detail: `printf("%lld%c", i+1, " \n"[i==n-1]);`
The C++ code prints `i+1` followed by space or newline.
My code:
```java
out.print((i + 1));
if (i == n - 1) {
    out.println();
} else {
    out.print(" ");
}
```
This matches the logic.

One detail: `RII` and `RIII` are defined but not used.
`RI` is used.
My code uses `sc.nextLong()` which is equivalent to `RI`.

The plan text should be included before the code block.

One more check: `sort(arr, arr+n)` in C++ sorts the whole array up to `n`.
My code `Arrays.sort(arr, 0, (int)n)` sorts indices `0` to `(int)n - 1`.
This is correct.

Wait, `sum` is `int` in C++ (due to `#define int long long`), so `sum` is `long`.
`sum` is used in comparisons.
`sum - arr[i] - arr[n-1] == arr[n-1]`
All are `long`.
This is correct.

I will formulate the response now.
</think>

### Translation Plan

1.  **Environment and Imports**:
    *   The C++ code relies on `<bits/stdc++.h>` which is not available in Java. We will import `java.util.*` and `java.io.*` to handle arrays (`Arrays`), input parsing (`BufferedReader`, `StringTokenizer`), and output (`PrintWriter`).

2.  **Type Definitions**:
    *   The C++ code uses `#define int long long`. This means every `int` variable (like `n`, `sum`, `arr`, `brr`, `cnt`) is effectively a 64-bit integer (`long long`).
    *   **Translation**: In Java, we will replace all `int` types with `long` to match the C++ behavior.
    *   `bool` becomes `boolean`.

3.  **Macros**:
    *   `IOS`, `REP`, `REPP`, `SZ`, `P`, `F`, `S`, `PB`, `DBAC`: These are C++ specific macros for I/O synchronization, loops, and pairs. We will ignore the unused ones and replace the used ones (`RI`, `REP`) with standard Java loops and input reading methods.
    *   `printf` and `cout`: We will use `PrintWriter` or `System.out` for output to achieve similar performance and formatting.

4.  **Input Reading (`rit` function)**:
    *   The C++ code uses a custom `rit()` function to read integers efficiently, skipping whitespace and handling negative signs manually.
    *   **Translation**: We will implement a `FastReader` class in Java using `BufferedReader` and `StringTokenizer`. This is the standard Java equivalent for fast I/O.

5.  **Variables and Arrays**:
    *   `n`: `long`.
    *   `arr`, `brr`: `long[]` with size `N+5` (200005).
    *   `sum`: `long`.
    *   `bye`: `boolean[]` with size `1000005`.
    *   **Indexing**: Since `arr` is `long[]` but `bye` is indexed by value (which fits in `int` range based on `bye`'s size), we must cast `arr[i]` to `int` when accessing `bye`.

6.  **Logic**:
    *   **Sorting**: `std::sort(arr, arr+n)` is replaced by `Arrays.sort(arr, 0, (int)n)`.
    *   **Loops**: `REP(I, N)` loops from `0` to `N-1`.
    *   **Conditions**: Direct translation of `if` conditions, ensuring types are `long`.

7.  **Output**:
    *   `printf("%lld\n", cnt)` becomes `out.println(cnt)`.
    *   The loop printing indices with spaces/newlines is implemented using `PrintWriter`.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1077 {
    // Constants
    // N is defined as 200000
    static final int N = 200000;
    // modn is 1000000007
    static final long modn = 1000000007L;
    // INF is 2147483647
    static final long INF = 2147483647L;

    // Global variables
    // C++: int n; #define int long long -> n is long
    static long n;
    
    // C++: int arr[N+5], brr[N+5] -> #define int long long -> arr, brr are long[]
    static long[] arr = new long[N + 5];
    static long[] brr = new long[N + 5];
    
    // C++: bool bye[1000005];
    static boolean[] bye = new boolean[1000005];
    
    // C++: int sum; -> #define int long long -> sum is long
    static long sum = 0;

    // Fast Input Reader to replace 'rit' function
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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

        long nextLong() {
            String s = next();
            if (s == null) return 0;
            return Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // RI(n); -> Read n
        String nStr = sc.next();
        if (nStr != null) {
            n = Long.parseLong(nStr);
        }

        // REP(i,n) -> Loop 0 to n-1
        for (int i = 0; i < n; i++) {
            // RI(arr[i]);
            arr[i] = sc.nextLong();
            // sum += arr[i];
            sum += arr[i];
            // brr[i] = arr[i];
            brr[i] = arr[i];
        }

        // sort(arr, arr+n) -> Arrays.sort
        // In C++, sort is on long long. In Java, Arrays.sort(long[]) sorts primitives.
        // We sort from 0 to n (exclusive of n, so 0 to n-1)
        Arrays.sort(arr, 0, (int)n);

        // REP(i, n-1) -> Loop 0 to n-2
        for (int i = 0; i < n - 1; i++) {
            // if( sum - arr[i] - arr[n-1] == arr[n-1] )
            if (sum - arr[i] - arr[(int)n - 1] == arr[(int)n - 1]) {
                // bye[ arr[i] ] = true;
                // arr[i] is long. bye is boolean[].
                // We must cast to int. Assuming arr[i] fits in int range (based on bye array size).
                bye[(int)arr[i]] = true;
            }
        }

        // Special check for last element
        // if( sum - arr[n-1] - arr[n-2] == arr[n-2] )
        // Need n >= 2
        if (n >= 2) {
            if (sum - arr[(int)n - 1] - arr[(int)n - 2] == arr[(int)n - 2]) {
                bye[(int)arr[(int)n - 1]] = true;
            }
        }

        // Count
        long cnt = 0;
        // REP(i,n)
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) cnt++;
        }

        // printf("%lld\n", cnt);
        out.println(cnt);

        // REP(i,n) if (bye[brr[i]]) printf("%lld%c", i+1, " \n"[i==n-1]);
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) {
                out.print((i + 1));
                if (i == n - 1) {
                    out.println();
                } else {
                    out.print(" ");
                }
            }
        }

        out.flush();
    }
}
```

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1077 {
    // Constants
    // N is defined as 200000
    static final int N = 200000;
    // modn is 1000000007
    static final long modn = 1000000007L;
    // INF is 2147483647
    static final long INF = 2147483647L;

    // Global variables
    // C++: int n; #define int long long -> n is long
    static long n;
    
    // C++: int arr[N+5], brr[N+5] -> #define int long long -> arr, brr are long[]
    static long[] arr = new long[N + 5];
    static long[] brr = new long[N + 5];
    
    // C++: bool bye[1000005];
    static boolean[] bye = new boolean[1000005];
    
    // C++: int sum; -> #define int long long -> sum is long
    static long sum = 0;

    // Fast Input Reader to replace 'rit' function
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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

        long nextLong() {
            String s = next();
            if (s == null) return 0;
            return Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // RI(n); -> Read n
        String nStr = sc.next();
        if (nStr != null) {
            n = Long.parseLong(nStr);
        }

        // REP(i,n) -> Loop 0 to n-1
        for (int i = 0; i < n; i++) {
            // RI(arr[i]);
            arr[i] = sc.nextLong();
            // sum += arr[i];
            sum += arr[i];
            // brr[i] = arr[i];
            brr[i] = arr[i];
        }

        // sort(arr, arr+n) -> Arrays.sort
        // In C++, sort is on long long. In Java, Arrays.sort(long[]) sorts primitives.
        // We sort from 0 to n (exclusive of n, so 0 to n-1)
        Arrays.sort(arr, 0, (int)n);

        // REP(i, n-1) -> Loop 0 to n-2
        for (int i = 0; i < n - 1; i++) {
            // if( sum - arr[i] - arr[n-1] == arr[n-1] )
            if (sum - arr[i] - arr[(int)n - 1] == arr[(int)n - 1]) {
                // bye[ arr[i] ] = true;
                // arr[i] is long. bye is boolean[].
                // We must cast to int. Assuming arr[i] fits in int range (based on bye array size).
                bye[(int)arr[i]] = true;
            }
        }

        // Special check for last element
        // if( sum - arr[n-1] - arr[n-2] == arr[n-2] )
        // Need n >= 2
        if (n >= 2) {
            if (sum - arr[(int)n - 1] - arr[(int)n - 2] == arr[(int)n - 2]) {
                bye[(int)arr[(int)n - 1]] = true;
            }
        }

        // Count
        long cnt = 0;
        // REP(i,n)
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) cnt++;
        }

        // printf("%lld\n", cnt);
        out.println(cnt);

        // REP(i,n) if (bye[brr[i]]) printf("%lld%c", i+1, " \n"[i==n-1]);
        for (int i = 0; i < n; i++) {
            if (bye[(int)brr[i]]) {
                out.print((i + 1));
                if (i == n - 1) {
                    out.println();
                } else {
                    out.print(" ");
                }
            }
        }

        out.flush();
    }
}
</CODE>