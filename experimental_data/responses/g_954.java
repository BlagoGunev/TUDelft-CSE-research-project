Translate this C++ code to Java code. The main class name should be g_954. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
#define N 500005
#define LL long long
#define mod 1000000007
#define pr pair<int,int>
#define mp(x,y) make_pair(x,y)
using namespace std;

LL read(){
	char c=getchar();
	LL t=0,f=1;
	while(c>'9'||c<'0') f=(c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9') t=t*10+c-'0',c=getchar();
	return t*f;
}

int n,r;
LL a[N],K,ad[N],dc[N],inf;

bool check(LL v){
	LL tmp=0,used=0;
	memset(dc,0,sizeof dc);
	for(int i=1;i<=n;i++){
		if(a[i]+tmp<v){
			LL dt=v-a[i]-tmp;
			if((used+=dt)>K) return 0;
			tmp+=dt,dc[min(n,i+(r<<1))]+=dt;
		}
		tmp-=dc[i];
	}
	return 1;
}

int main(){
	n=read(),r=read(),K=read();
	for(int i=1;i<=n;i++) inf+=(a[i]=read()),ad[max(i-r,1)]+=a[i],dc[min(i+r,n)]+=a[i],a[i]=0;
	LL L=0,R=inf+K,mid,ans=0,tmp=0;
	for(int i=1;i<=n;i++) tmp+=ad[i],a[i]=tmp,tmp-=dc[i];
	while(L<=R) (check(mid=(L+R)>>1))?(L=(ans=mid)+1):(R=mid-1);
	printf("%lld\n",ans);
}

Here is the plan for translating the C++ code to Java.

### Translation Plan

1.  **Headers and Namespace**:
    *   Remove `#include<bits/stdc++.h>`, `using namespace std;`.
    *   Include necessary Java classes: `java.util.Scanner`, `java.io.PrintWriter` (or `System.out`), `java.io.BufferedReader`, `java.io.InputStreamReader`, `java.io.BufferedInputStream`.
    *   `std` namespace usage is implicit in Java (classes must be fully qualified or imported).

2.  **Data Types**:
    *   C++ `int` -> Java `int`.
    *   C++ `long long` -> Java `long`.
    *   C++ `mod` (constant) -> Java `static final long MOD`.

3.  **Constants and Arrays**:
    *   C++ `#define N 500005` -> Java `static final int N = 500005`.
    *   C++ `LL` -> Java `long`.
    *   C++ global arrays (`a[N]`, `ad[N]`, `dc[N]`, `inf`) -> Java static arrays inside the class.
    *   C++ global variables (`n`, `r`, `K`) -> Java static fields or local variables in `main`.

4.  **Input/Output**:
    *   C++ `read()` function (fast I/O) -> Java `Scanner` or `BufferedReader` + `StringTokenizer`. Since the C++ code uses a custom `read` for integers, a `Scanner` is sufficient for this logic, but a custom `BufferedReader` parser is faster and safer for competitive programming constraints. I will implement a simple `BufferedReader` based input reader to mimic the C++ `read` function's speed.
    *   C++ `printf` -> Java `System.out.println` or `PrintWriter`.

5.  **Logic Conversion**:
    *   C++ `memset` -> Java `Arrays.fill`.
    *   C++ `pair` (`pr`) -> Not explicitly used in the logic, but defined. It is unused in the provided snippet, so I will omit it to keep the code clean, or define it if strictly required by context (it's not used).
    *   C++ `make_pair` -> Not used.
    *   C++ `min`, `max` -> Java `Math.min`, `Math.max`.
    *   C++ `<<` (bitwise shift) -> Java `<<`.
    *   C++ `sizeof` -> Java array length `arr.length`.

6.  **Incremental Tasks**:
    *   **Step 1**: Setup class structure, imports, and constants.
    *   **Step 2**: Implement the input reading mechanism (mimicking `read()`).
    *   **Step 3**: Implement the `check` function (binary search predicate).
    *   **Step 4**: Implement `main` logic (parsing input, initializing arrays, binary search).
    *   **Step 5**: Combine and finalize.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class g_954 {
    // C++ N 500005 -> Java static final constant
    static final int N = 500005;
    // C++ LL long long -> Java long
    static final long MOD = 1000000007;

    // Global arrays corresponding to C++ a[N], ad[N], dc[N]
    static long[] a = new long[N];
    static long[] ad = new long[N];
    static long[] dc = new long[N];

    static int n, r;
    static long K;

    // Fast Input Reader to mimic C++ read()
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
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        
        // Read n, r, K
        // Note: The C++ read() function handles negative numbers and whitespace skipping.
        // StringTokenizer handles whitespace automatically.
        // However, the C++ read logic specifically checks for '-' and digits.
        // To be safe and strictly mimic the C++ behavior (handling potential negative inputs or specific formats),
        // we can implement a custom parser or rely on StringTokenizer. 
        // Given the problem type (likely competitive programming), StringTokenizer is standard.
        
        // Let's implement a custom read logic inside main to strictly match the C++ `read` function behavior
        // regarding the loop structure `while(c>'9'||c<'0') ...`
        
        // Since Java's StringTokenizer is safer for standard whitespace, but the C++ code is a custom integer parser,
        // we will implement a simple version of the C++ read logic to ensure compatibility if inputs are weird,
        // though standard whitespace separation is assumed.
        
        // Re-implementing read() logic for integers to match C++ exactly
        int nVal = readInt(sc);
        int rVal = readInt(sc);
        long KVal = readLong(sc);
        
        n = nVal;
        r = rVal;
        K = KVal;

        // Reading array 'a' and updating 'ad' and 'dc'
        // C++: for(int i=1;i<=n;i++) inf+=(a[i]=read()),ad[max(i-r,1)]+=a[i],dc[min(i+r,n)]+=a[i],a[i]=0;
        long inf = 0;
        
        for (int i = 1; i <= n; i++) {
            long val = readLong(sc);
            a[i] = val;
            inf += val;
            // max(i-r, 1) -> Math.max(i-r, 1)
            // min(i+r, n) -> Math.min(i+r, n)
            ad[Math.max(i - r, 1)] += val;
            dc[Math.min(i + r, n)] += val;
            a[i] = 0; // Resetting a[i] as per C++ code
        }

        // Reconstructing the array 'a' with prefix sums logic
        // C++: LL tmp=0; for(int i=1;i<=n;i++) tmp+=ad[i],a[i]=tmp,tmp-=dc[i];
        long tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp += ad[i];
            a[i] = tmp;
            tmp -= dc[i];
        }

        // Binary Search
        // C++: LL L=0,R=inf+K,mid,ans=0,tmp=0;
        long L = 0;
        long R = inf + K;
        long mid;
        long ans = 0;
        
        // C++: while(L<=R) (check(mid=(L+R)>>1))?(L=(ans=mid)+1):(R=mid-1);
        while (L <= R) {
            mid = (L + R) >>> 1; // Unsigned shift for safety, though (L+R)/2 works for positive
            if (check(mid)) {
                ans = mid;
                L = ans + 1;
            } else {
                R = mid - 1;
            }
        }

        // Output
        // C++: printf("%lld\n",ans);
        System.out.println(ans);
    }

    // Helper to mimic C++ read()
    // C++: char c=getchar(); ...
    // Java: We need to read character by character or parse manually to match the specific logic
    // of the C++ read function which handles negative signs and specific skipping.
    // However, standard StringTokenizer is usually preferred. 
    // To strictly follow the prompt "translate this C++ code", we should mimic the logic of the custom `read` function.
    // The C++ `read` function reads a char, checks if it is a digit or sign, skips non-digits, 
    // reads digits, and returns the number.
    
    static int readInt(BufferedReader br) throws IOException {
        int c = br.read();
        int t = 0;
        int f = 1;
        while (c > '9' || c < '0') {
            if (c == '-') f = -1;
            c = br.read();
        }
        while (c >= '0' && c <= '9') {
            t = t * 10 + (c - '0');
            c = br.read();
        }
        return t * f;
    }

    static long readLong(BufferedReader br) throws IOException {
        int c = br.read();
        long t = 0;
        int f = 1;
        while (c > '9' || c < '0') {
            if (c == '-') f = -1;
            c = br.read();
        }
        while (c >= '0' && c <= '9') {
            t = t * 10 + (c - '0');
            c = br.read();
        }
        return (long) t * f;
    }

    // Function check()
    // C++: bool check(LL v){ ... }
    static boolean check(long v) {
        long tmp = 0;
        long used = 0;
        // C++: memset(dc,0,sizeof dc);
        // Java: Arrays.fill(dc, 0);
        Arrays.fill(dc, 0);
        
        // C++: for(int i=1;i<=n;i++){ ... }
        for (int i = 1; i <= n; i++) {
            // C++: if(a[i]+tmp<v){ ... }
            if (a[i] + tmp < v) {
                long dt = v - a[i] - tmp;
                // C++: if((used+=dt)>K) return 0;
                used += dt;
                if (used > K) return false;
                
                // C++: tmp+=dt,dc[min(n,i+(r<<1))]+=dt;
                tmp += dt;
                // C++: min(n, i + (r << 1)) -> min(n, i + r*2)
                dc[Math.min(n, i + (r << 1))] += dt;
            }
            // C++: tmp-=dc[i];
            tmp -= dc[i];
        }
        return true;
    }
}
```

### Explanation of Translation

1.  **Class Structure**: The C++ code is a single-file program. In Java, this becomes a `public class g_954`. Global variables in C++ (like `n`, `r`, arrays `a`, `ad`, `dc`) are converted to `static` fields in the Java class.
2.  **Input/Output**: The C++ code uses a custom `read()` function to parse integers, likely for speed. I have replicated this logic in Java methods `readInt` and `readLong` using `BufferedReader`. This reads character by character, handling whitespace and negative signs as the C++ version does. `printf` is replaced by `System.out.println`.
3.  **Arrays**: C++ global arrays are mapped to Java `static long[]` arrays. `memset` is replaced by `Arrays.fill`.
4.  **Logic**:
    *   `#define` macros are converted to `static final` constants.
    *   `min` and `max` functions are replaced by `Math.min` and `Math.max`.
    *   The bitwise shift `r<<1` becomes `r << 1` (or `r * 2`).
    *   The ternary operator `cond ? true_val : false_val` in the binary search loop is translated to an `if-else` block for clarity, or kept as a ternary if desired (kept as `if-else` logic here for readability).
    *   The `check` function logic is preserved exactly, including the `memset` equivalent and the loop structure.
5.  **Specific Logic Details**:
    *   The binary search condition `while(L<=R)` is preserved.
    *   The update logic `L=(ans=mid)+1` is preserved (equivalent to `ans = mid; L = ans + 1;`).
    *   The array reconstruction logic in `main` is preserved.

```java
<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class g_954 {
    // C++ N 500005 -> Java static final constant
    static final int N = 500005;
    
    // C++ LL long long -> Java long
    // mod is defined but not used in the logic provided, kept for completeness if needed
    static final long MOD = 1000000007;

    // Global arrays corresponding to C++ a[N], ad[N], dc[N]
    static long[] a = new long[N];
    static long[] ad = new long[N];
    static long[] dc = new long[N];

    static int n, r;
    static long K;

    // Helper to mimic C++ read() function which reads integer char by char
    static int readInt() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = br.read();
        int t = 0;
        int f = 1;
        // Skip non-digit characters
        while (c > '9' || c < '0') {
            if (c == '-') f = -1;
            c = br.read();
        }
        // Read digits
        while (c >= '0' && c <= '9') {
            t = t * 10 + (c - '0');
            c = br.read();
        }
        return t * f;
    }

    // Helper to mimic C++ read() function for long long
    static long readLong() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int c = br.read();
        long t = 0;
        int f = 1;
        while (c > '9' || c < '0') {
            if (c == '-') f = -1;
            c = br.read();
        }
        while (c >= '0' && c <= '9') {
            t = t * 10 + (c - '0');
            c = br.read();
        }
        return (long) t * f;
    }

    // Function check() translated from C++
    static boolean check(long v) {
        long tmp = 0;
        long used = 0;
        // C++: memset(dc,0,sizeof dc);
        Arrays.fill(dc, 0);
        
        for (int i = 1; i <= n; i++) {
            if (a[i] + tmp < v) {
                long dt = v - a[i] - tmp;
                used += dt;
                if (used > K) return false;
                
                tmp += dt;
                // C++: min(n, i + (r << 1)) -> min(n, i + r*2)
                int limit = Math.min(n, i + (r << 1));
                dc[limit] += dt;
            }
            // C++: tmp-=dc[i];
            tmp -= dc[i];
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        // Read n, r, K
        int nVal = readInt();
        int rVal = readInt();
        long KVal = readLong();
        
        n = nVal;
        r = rVal;
        K = KVal;

        long inf = 0;
        
        // Reading array 'a' and updating 'ad' and 'dc'
        // C++: for(int i=1;i<=n;i++) inf+=(a[i]=read()),ad[max(i-r,1)]+=a[i],dc[min(i+r,n)]+=a[i],a[i]=0;
        for (int i = 1; i <= n; i++) {
            long val = readLong();
            a[i] = val;
            inf += val;
            // max(i-r, 1) -> Math.max(i-r, 1)
            // min(i+r, n) -> Math.min(i+r, n)
            ad[Math.max(i - r, 1)] += val;
            dc[Math.min(i + r, n)] += val;
            a[i] = 0; // Resetting a[i] as per C++ code
        }

        // Reconstructing the array 'a' with prefix sums logic
        // C++: LL tmp=0; for(int i=1;i<=n;i++) tmp+=ad[i],a[i]=tmp,tmp-=dc[i];
        long tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp += ad[i];
            a[i] = tmp;
            tmp -= dc[i];
        }

        // Binary Search
        // C++: LL L=0,R=inf+K,mid,ans=0,tmp=0;
        long L = 0;
        long R = inf + K;
        long mid;
        long ans = 0;
        
        // C++: while(L<=R) (check(mid=(L+R)>>1))?(L=(ans=mid)+1):(R=mid-1);
        while (L <= R) {
            mid = (L + R) >>> 1; // Unsigned right shift for safe division by 2
            if (check(mid)) {
                ans = mid;
                L = ans + 1;
            } else {
                R = mid - 1;
            }
        }

        // Output
        // C++: printf("%lld\n",ans);
        System.out.println(ans);
    }
}
</CODE>
```