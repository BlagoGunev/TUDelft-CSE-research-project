Translate this C++ code to Java code. The main class name should be c_478. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

    using namespace std;



    #define FILE "gangsters"

    #define pb push_back

    #define mp make_pair

    #define PI 3.14159265358979323846







    typedef long long ll;

    typedef unsigned long long ull;



    const int INF = 2e9;

    const ll LINF = 2e18;

    const int DINF = numeric_limits<double>::max();



    const int ITER = 300;

    const int MOD = 1e9+7;

    const double EPS = 1e-9;

    const int MAXN = 1e5+5;



    ll r,g,b;



    void solve(){

       cin >> r >> g >> b;

       ll mx = max ( max (r, g) , b );

       ll sum = r + g + b - mx;

       if(sum * 2 >= mx){

            cout << (sum + mx) / 3 << endl;

       }else{

            cout << sum << endl;

       }



    }





    int main() {

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cout.tie(0);

        //freopen(FILE".in", "r", stdin);

        //freopen(FILE".out", "w", stdout);







        int t = 1;

        while(t--) {

            solve();

        }



    }

Here is the plan for the translation from C++ to Java.

### Translation Plan

1.  **Environment Setup**:
    *   C++ uses `bits/stdc++.h` and `using namespace std;`. Java requires explicit imports.
    *   We need to import `java.util.Scanner` or `java.io.BufferedReader` for input/output. Given the simplicity of the logic, `Scanner` is sufficient, though `BufferedReader` is faster. I will use `Scanner` for readability as the constraints ($N=10^5$) are low enough for simple I/O in this specific problem (which only processes a few numbers per test case).
    *   The C++ `#define` macros will be replaced with standard Java variables or helper methods.

2.  **Data Types**:
    *   C++ `long long` maps to Java `long`.
    *   C++ `int` maps to Java `int`.
    *   C++ `double` maps to Java `double`.
    *   C++ `const int INF` etc., will be mapped to `final static` constants in Java.

3.  **Input/Output**:
    *   C++ `cin >>` and `cout <<` will be replaced by Java's `scanner.nextInt()` / `scanner.nextLong()` and `System.out.println()`.
    *   The `ios_base::sync_with_stdio(0);` optimization is not strictly necessary for Java unless strict timing limits exist, but we can ignore it as the logic is trivial.

4.  **Logic Structure**:
    *   The C++ `main` function loops `t` times. The C++ code sets `t = 1`, effectively running the logic once.
    *   The `solve()` function in C++ will become a `solve()` method in Java.
    *   The `#define` macros like `pb`, `mp` are not used in the actual logic, so they can be ignored or removed.
    *   `numeric_limits<double>::max()` maps to `Double.MAX_VALUE`.

5.  **Class Structure**:
    *   The C++ code is a single file with `main`.
    *   The Java code will be a class named `c_478` with a `main` method and a `solve` method.

6.  **Incremental Tasks**:
    *   Step 1: Set up class `c_478` and imports.
    *   Step 2: Define constants (`INF`, `LINF`, `MOD`, `MAXN`, etc.).
    *   Step 3: Implement the `solve` method (reading `r`, `g`, `b`, calculating `mx`, `sum`, and printing the result).
    *   Step 4: Implement `main` to call `solve`.

### Code Translation

```java
import java.util.Scanner;

public class c_478 {
    
    // Mapping C++ constants to Java final static fields
    private static final int INF = 2000000000; // 2e9
    private static final long LINF = 2000000000000000000L; // 2e18
    private static final int MOD = 1000000007; // 1e9+7
    private static final double EPS = 1e-9;
    private static final int MAXN = 100005; // 1e5+5
    private static final double DINF = Double.MAX_VALUE;
    private static final int ITER = 300;

    // Global variables for r, g, b (similar to C++ globals)
    private static long r;
    private static long g;
    private static long b;

    public static void main(String[] args) {
        // In the C++ code, t is initialized to 1, so we run once.
        // If the C++ code were to read t from input, we would do so here.
        // However, the provided C++ code hardcodes t=1.
        int t = 1; 
        
        for (int i = 0; i < t; i++) {
            solve();
        }
    }

    public static void solve() {
        // Mapping C++ cin >> to Java Scanner
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            r = sc.nextLong();
            g = sc.nextLong();
            b = sc.nextLong();
        }

        // Logic translation:
        // C++: ll mx = max ( max (r, g) , b );
        // Java:
        long mx = Math.max(r, g);
        mx = Math.max(mx, b);

        // C++: ll sum = r + g + b - mx;
        long sum = r + g + b - mx;

        // C++: if(sum * 2 >= mx){ ... }
        // Note: In C++, sum * 2 might overflow if sum is large, but here sum <= 3*1e5, so it's safe.
        // In Java, we check the condition.
        if (sum * 2 >= mx) {
            // C++: cout << (sum + mx) / 3 << endl;
            System.out.println((sum + mx) / 3);
        } else {
            // C++: cout << sum << endl;
            System.out.println(sum);
        }
    }
}
```

<CODE>
import java.util.Scanner;

public class c_478 {
    
    // Mapping C++ constants to Java final static fields
    private static final int INF = 2000000000; // 2e9
    private static final long LINF = 2000000000000000000L; // 2e18
    private static final int MOD = 1000000007; // 1e9+7
    private static final double EPS = 1e-9;
    private static final int MAXN = 100005; // 1e5+5
    private static final double DINF = Double.MAX_VALUE;
    private static final int ITER = 300;

    // Global variables for r, g, b (similar to C++ globals)
    private static long r;
    private static long g;
    private static long b;

    public static void main(String[] args) {
        // In the C++ code, t is initialized to 1, so we run once.
        // If the C++ code were to read t from input, we would do so here.
        // However, the provided C++ code hardcodes t=1.
        int t = 1; 
        
        for (int i = 0; i < t; i++) {
            solve();
        }
    }

    public static void solve() {
        // Mapping C++ cin >> to Java Scanner
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            r = sc.nextLong();
            g = sc.nextLong();
            b = sc.nextLong();
        }

        // Logic translation:
        // C++: ll mx = max ( max (r, g) , b );
        // Java:
        long mx = Math.max(r, g);
        mx = Math.max(mx, b);

        // C++: ll sum = r + g + b - mx;
        long sum = r + g + b - mx;

        // C++: if(sum * 2 >= mx){ ... }
        // Note: In C++, sum * 2 might overflow if sum is large, but here sum <= 3*1e5, so it's safe.
        // In Java, we check the condition.
        if (sum * 2 >= mx) {
            // C++: cout << (sum + mx) / 3 << endl;
            System.out.println((sum + mx) / 3);
        } else {
            // C++: cout << sum << endl;
            System.out.println(sum);
        }
    }
}
</CODE>