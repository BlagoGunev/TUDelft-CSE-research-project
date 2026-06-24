Translate this C++ code to Java code. The main class name should be d_898. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int getint()
{
    char ch=getchar();
    int f=1,x=0;
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
    return f*x;
}

const int N=200200;

int n,m,k;
int a[N];
int q[N];
int hd,tl;
int ans;

void init()
{
    n=getint(),m=getint(),k=getint();
    for(int i=1; i<=n; i++){
        a[i]=getint();
    }
    sort(a+1,a+1+n);
}

int main()
{
    init();
    for(int i=1; i<=n; i++){
        while(hd<tl && a[i]-q[hd]>=m) hd++;
        if(tl-hd>=k-1){
            ans++;
        }else{
            q[tl++]=a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Header Files**:
    *   `<cstdio>` -> `java.io.*` and `java.util.*` (for `Scanner` or `BufferedReader`).
    *   `<cstring>` -> Not strictly needed for the logic provided, but `String` methods will be used.
    *   `<cctype>` -> Not strictly needed as we will use `Scanner` methods.
    *   `<algorithm>` -> `java.util.Arrays` (for `Arrays.sort`).

2.  **Namespace**:
    *   `using namespace std;` -> Remove (Java is object-oriented, no global namespace).

3.  **Input Parsing (`getint`)**:
    *   C++ `getchar()` and manual parsing logic (`isdigit`, loops) are replaced by Java's `Scanner` class or a custom `BufferedReader` parser.
    *   Since the input size is `N=200200`, `Scanner` might be slightly slow but is generally sufficient for competitive programming tasks unless time limits are extremely tight (usually < 0.5s). However, given the logic is simple, `Scanner` is the most direct translation. If strict performance is required, `BufferedReader` + `StringTokenizer` is preferred. I will use `Scanner` for readability as it maps directly to the intent of the C++ code, but I will check if `BufferedReader` is safer. Given the constraints usually implied by `N=200200`, `BufferedReader` is safer to avoid TLE (Time Limit Exceeded). I will implement a fast I/O helper or use `StreamTokenizer` or just `BufferedReader` + `StringTokenizer` to mimic the C++ efficiency.
    *   *Decision*: Use `BufferedReader` and `StringTokenizer` for robustness and speed, mimicking the C++ `getint` logic but in Java.

4.  **Global Variables**:
    *   C++ global variables (`N`, `a`, `q`, `hd`, `tl`, `ans`, `n`, `m`, `k`) are moved to static fields or local variables in `main`.
    *   *Decision*: Keep them as static fields in the class `d_898` to match the global scope of the C++ code.

5.  **`init` Function**:
    *   Logic remains the same: read `n`, `m`, `k`.
    *   Loop to read array `a`.
    *   `sort(a+1, a+1+n)` -> `Arrays.sort(a, 0, n)` (Note: C++ sorts 1-based index range, Java `Arrays.sort` is 0-based. The C++ code does `a[1]` to `a[n]`. In Java, we can map this to indices `0` to `n-1` or keep `1` to `n`. To keep the logic identical and minimize index shifting errors, I will map the input to `0` to `n-1` in Java, but the C++ code uses `1` to `n`.
    *   *Correction*: The C++ code uses `a[1]` to `a[n]`. The loop `for(int i=1; i<=n; i++)` accesses these.
    *   *Java Translation Strategy*: I will keep the array size `N` and use 1-based indexing for `a` and `q` to match the C++ logic exactly, avoiding index confusion. This means reading into `a[i]` for `i=1..n` and sorting `a` from index `1` to `n`.

6.  **`main` Function**:
    *   Calls `init()`.
    *   Iterates `i` from `1` to `n`.
    *   Logic involving `q` (queue) and `ans` remains identical.
    *   `printf("%d\n", ans)` -> `System.out.println(ans)`.
    *   `return 0` -> Not strictly necessary in Java, but good practice.

7.  **Incremental Tasks**:
    *   Task 1: Define class and static variables.
    *   Task 2: Implement `init` with fast I/O.
    *   Task 3: Implement `main` logic.

8.  **Specific C++ to Java Mapping**:
    *   `getint()`: Replaced by a custom `nextInt()` method using `BufferedReader`.
    *   `sort(a+1, a+1+n)`: `Arrays.sort(a, 1, n + 1)`.
    *   `printf`: `System.out.println`.

Here is the Java code:

<CODE>
import java.io.*;
import java.util.*;

public class d_898 {
    static int N = 200200;
    static int n, m, k;
    static int[] a = new int[N];
    static int[] q = new int[N];
    static int hd, tl;
    static int ans;

    // Fast I/O replacement for C++ getint
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = null;

    static int nextInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return 0; // End of input
            st = new StringTokenizer(line);
        }
        return Integer.parseInt(st.nextToken());
    }

    static void init() throws IOException {
        n = nextInt();
        m = nextInt();
        k = nextInt();
        for (int i = 1; i <= n; i++) {
            a[i] = nextInt();
        }
        // C++: sort(a+1, a+1+n);
        // Java: Arrays.sort(a, 1, n + 1);
        Arrays.sort(a, 1, n + 1);
    }

    public static void main(String[] args) throws IOException {
        init();
        hd = 1;
        tl = 1;
        ans = 0;
        
        // C++ logic: for(int i=1; i<=n; i++)
        for (int i = 1; i <= n; i++) {
            // C++: while(hd<tl && a[i]-q[hd]>=m) hd++;
            while (hd < tl && a[i] - q[hd] >= m) {
                hd++;
            }
            // C++: if(tl-hd>=k-1){ ans++; } else { q[tl++]=a[i]; }
            if (tl - hd >= k - 1) {
                ans++;
            } else {
                q[tl++] = a[i];
            }
        }
        System.out.println(ans);
    }
}
</CODE>