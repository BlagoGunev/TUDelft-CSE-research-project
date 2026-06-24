Translate this C++ code to Java code. The main class name should be c_1711. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h> 

//#include <ext/pb_ds/assoc_container.hpp>

//#include <ext/pb_ds/tree_policy.hpp>

 

using namespace std;

//using namespace __gnu_pbds;

 

typedef long long ll;

typedef long double ld;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define db1(x) cout<<#x<<"="<<x<<"\n"

#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'

#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'

#define rep(i,n) for(int i=0;i<(n);++i)

#define repA(i,a,n) for(int i=a;i<=(n);++i)

#define repD(i,a,n) for(int i=a;i>=(n);--i)

#define MOD 1000000007

#define gcd(a,b) __gcd(a,b)

#define tolowecase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::tolower)

#define touppercase(s1) transform(s1.begin(),s1.end(),s1.begin(), ::toupper)

#define MOD1 998244353

#define eps 1e-12

#define INF 2e18

#define all(x) (x).begin(), (x).end()

#define sz(x) ((ll)(x).size())

#define PI 3.141592653589793238462

#define total_set_bits __builtin_popcountll

#define endl '\n'





ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3 // return x, y, gcd

ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b

ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}

void google(int t) {cout << "Case #" << t << ": ";}

vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))

    

                /*******************************************************************************/







int main(){

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int t;

    cin>>t;

    while(t--){

        	

        ll n, m, k;

        cin >> n >> m >> k;



        vector<ll> pigment(k);

        rep(i, k) cin >> pigment[i];



        sort(all(pigment), greater<ll>());



        auto rowWise = [&]() -> bool {



        	ll column = 0;

        	bool val = (m % 2 == 0 ? true : false);



        	for(int i = 0; i < k; i++){



        		ll curr = pigment[i];

        		if(curr / n >= 2) column += curr / n;

        		if(curr / n >= 3) val = true;

        	}



        	return column >= m and val;

        };





        auto colWise = [&]() -> bool {



        	ll row = 0;

        	bool val = (n % 2 == 0 ? true : false);



        	for(int i = 0; i < k; i++){



        		ll curr = pigment[i];

        		if(curr / m >= 2) row += curr / m;

        		if(curr / m >= 3) val = true;

        	}



        	return row >= n and val;

        };





        cout << ((rowWise() or colWise()) ? "Yes\n" : "No\n");

    }

    return 0;

}

Here is the plan for translating the provided C++ code to Java.

### Translation Plan

1.  **Language Specifics & Mapping**:
    *   **Includes/Namespaces**: C++ uses `#include` and `using namespace std;`. Java requires explicit class definitions and imports. We will remove the `bits/stdc++.h` header and replace standard library usage with `java.util.*` (e.g., `Scanner`, `Arrays`).
    *   **Types**: `long long` in C++ maps to `long` in Java. `long double` maps to `double` or `BigDecimal` (though `double` is sufficient here based on usage). `int` maps to `int`.
    *   **Macros**: C++ macros (`#define`) are replaced by helper methods or standard Java syntax.
        *   `rep(i, n)`: Replaced by a simple `for` loop.
        *   `all(x)`, `sz(x)`: Replaced by `x` and `x.length`.
        *   `sort(...)`: Replaced by `Arrays.sort()`.
        *   `greater<ll>()`: Replaced by `Collections.reverseOrder()` or a custom comparator.
        *   `__builtin_popcountll`: Replaced by `Long.bitCount()`.
        *   `transform`: Replaced by Java Streams or manual loops.
        *   `__gcd`: Replaced by `java.math.BigInteger.gcd()` or a custom implementation.
    *   **Input/Output**: C++ `cin`/`cout` is replaced by Java `Scanner` and `System.out.println`. We will keep `ios::sync_with_stdio(0)` logic in mind (though Java `Scanner` is inherently slower, we will use standard `Scanner` for simplicity unless `BufferedReader` is strictly required for performance, but given the logic, `Scanner` is acceptable for this logic).
    *   **Pointers/Arrays**: C++ `int*arr = new int[n + 1]()` is replaced by Java arrays `int[] arr = new int[n + 1]`.
    *   **Lambdas**: C++ lambdas (`auto rowWise = [&]() -> bool`) are replaced by Java `Function` interfaces or anonymous classes.

2.  **Incremental Tasks**:
    *   **Step 1: Setup**: Create the class `c_1711` and set up the `main` method.
    *   **Step 2: Helper Functions**: Translate `expo`, `extendgcd`, `mminv`, `mminvprime`, `combination`, `sieve`, `phin`, `mod_*`, `gcd`, `towlowercase`, `touppercase`.
    *   **Step 3: Main Logic**: Translate the reading of `t`, `n`, `m`, `k`, and the `pigment` array.
    *   **Step 4: Logic Implementation**: Translate `rowWise` and `colWise` logic into Java methods.
    *   **Step 5: Output**: Translate the final decision logic.
    *   **Step 6: Cleanup**: Remove unused macros and ensure proper imports.

### Code Translation

```java
import java.util.Scanner;
import java.util.Arrays;
import java.util.function.Function;
import java.util.function.IntFunction;

public class c_1711 {

    // Constants
    static final long MOD = 1000000007L;
    static final long MOD1 = 998244353L;
    static final double EPS = 1e-12;
    static final double INF = 2e18;
    static final double PI = 3.141592653589793238462;

    // Helper: Modular Exponentiation
    // C++: ll expo(ll a, ll b, ll mod)
    public static long expo(long a, long b, long mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    // Helper: Extended GCD
    // C++: void extendgcd(ll a, ll b, ll*v)
    public static void extendgcd(long a, long b, long[] v) {
        if (b == 0) {
            v[0] = 1;
            v[1] = 0;
            v[2] = a;
            return;
        }
        extendgcd(b, a % b, v);
        long x = v[1];
        v[1] = v[0] - v[1] * (a / b);
        v[0] = x;
    }

    // Helper: Modular Inverse (Non-prime)
    // C++: ll mminv(ll a, ll b)
    public static long mminv(long a, long b) {
        long[] arr = new long[3];
        extendgcd(a, b, arr);
        return arr[0];
    }

    // Helper: Modular Inverse (Prime)
    // C++: ll mminvprime(ll a, ll b)
    public static long mminvprime(long a, long b) {
        return expo(a, b - 2, b);
    }

    // Helper: Combination
    // C++: ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
    public static long combination(long n, long r, long m, long[] fact, long[] ifact) {
        long val1 = fact[(int)n];
        long val2 = ifact[(int)(n - r)];
        long val3 = ifact[(int)r];
        return (((val1 * val2) % m) * val3) % m;
    }

    // Helper: Sieve of Eratosthenes
    // C++: vector<ll> sieve(int n)
    public static long[] sieve(int n) {
        // In C++: int*arr = new int[n + 1]();
        // In Java: Arrays.fill(arr, 0);
        int[] arr = new int[n + 1];
        Arrays.fill(arr, 0);
        java.util.List<Long> vect = new java.util.ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (arr[i] == 0) {
                vect.add((long)i);
                for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
            }
        }
        return vect.stream().mapToLong(Long::longValue).toArray();
    }

    // Helper: Euler's Totient Function
    // C++: ll phin(ll n)
    public static long phin(long n) {
        long number = n;
        if (n % 2 == 0) {
            number /= 2;
            while (n % 2 == 0) n /= 2;
        }
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                while (n % i == 0) n /= i;
                number = (number / i) * (i - 1);
            }
        }
        if (n > 1) number = (number / n) * (n - 1);
        return number;
    }

    // Helper: Modulo Add
    // C++: ll mod_add(ll a, ll b, ll m)
    public static long mod_add(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a + b) % m) + m) % m;
    }

    // Helper: Modulo Multiply
    // C++: ll mod_mul(ll a, ll b, ll m)
    public static long mod_mul(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a * b) % m) + m) % m;
    }

    // Helper: Modulo Subtract
    // C++: ll mod_sub(ll a, ll b, ll m)
    public static long mod_sub(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a - b) % m) + m) % m;
    }

    // Helper: Modulo Divide
    // C++: ll mod_div(ll a, ll b, ll m)
    public static long mod_div(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return mod_mul(a, mminvprime(b, m), m);
    }

    // Helper: GCD
    // C++: ll gcd(a,b) __gcd(a,b)
    public static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // C++: ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        // In Java, Scanner is used directly. For large inputs, BufferedReader is preferred, 
        // but we stick to Scanner to match the structure unless specified otherwise.
        
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                long n = sc.nextLong();
                long m = sc.nextLong();
                long k = sc.nextLong();

                long[] pigment = new long[(int)k];
                for (int i = 0; i < k; i++) {
                    pigment[i] = sc.nextLong();
                }

                // C++: sort(all(pigment), greater<ll>());
                // Java: Arrays.sort(pigment);
                // Note: C++ sorted descending. Arrays.sort sorts ascending.
                // We need to reverse it to match C++ behavior.
                Arrays.sort(pigment);
                for (int i = 0; i < k / 2; i++) {
                    long temp = pigment[i];
                    pigment[i] = pigment[k - 1 - i];
                    pigment[k - 1 - i] = temp;
                }

                // C++: auto rowWise = [&]() -> bool { ... }
                // Java: Function<Long, Boolean> rowWise
                java.util.function.Function<Long, Boolean> rowWise = (nVal) -> {
                    long column = 0;
                    // C++: bool val = (m % 2 == 0 ? true : false);
                    boolean val = (m % 2 == 0);

                    for (int i = 0; i < k; i++) {
                        long curr = pigment[i];
                        // C++: if(curr / n >= 2) column += curr / n;
                        if (curr / nVal >= 2) column += (curr / nVal);
                        // C++: if(curr / n >= 3) val = true;
                        if (curr / nVal >= 3) val = true;
                    }

                    // C++: return column >= m and val;
                    return column >= m && val;
                };

                // C++: auto colWise = [&]() -> bool { ... }
                // Java: Function<Long, Boolean> colWise
                java.util.function.Function<Long, Boolean> colWise = (nVal) -> {
                    long row = 0;
                    // C++: bool val = (n % 2 == 0 ? true : false);
                    boolean val = (n % 2 == 0);

                    for (int i = 0; i < k; i++) {
                        long curr = pigment[i];
                        // C++: if(curr / m >= 2) row += curr / m;
                        if (curr / nVal >= 2) row += (curr / nVal);
                        // C++: if(curr / m >= 3) val = true;
                        if (curr / nVal >= 3) val = true;
                    }

                    // C++: return row >= n and val;
                    return row >= n && val;
                };

                // C++: cout << ((rowWise() or colWise()) ? "Yes\n" : "No\n");
                boolean result = rowWise.apply((Long)n) || colWise.apply((Long)n);
                
                if (result) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            }
        }
    }
}
```

<CODE>
import java.util.Scanner;
import java.util.Arrays;
import java.util.function.Function;

public class c_1711 {

    // Constants
    static final long MOD = 1000000007L;
    static final long MOD1 = 998244353L;
    static final double EPS = 1e-12;
    static final double INF = 2e18;
    static final double PI = 3.141592653589793238462;

    // Helper: Modular Exponentiation
    public static long expo(long a, long b, long mod) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    // Helper: Extended GCD
    public static void extendgcd(long a, long b, long[] v) {
        if (b == 0) {
            v[0] = 1;
            v[1] = 0;
            v[2] = a;
            return;
        }
        extendgcd(b, a % b, v);
        long x = v[1];
        v[1] = v[0] - v[1] * (a / b);
        v[0] = x;
    }

    // Helper: Modular Inverse (Non-prime)
    public static long mminv(long a, long b) {
        long[] arr = new long[3];
        extendgcd(a, b, arr);
        return arr[0];
    }

    // Helper: Modular Inverse (Prime)
    public static long mminvprime(long a, long b) {
        return expo(a, b - 2, b);
    }

    // Helper: Combination
    public static long combination(long n, long r, long m, long[] fact, long[] ifact) {
        long val1 = fact[(int)n];
        long val2 = ifact[(int)(n - r)];
        long val3 = ifact[(int)r];
        return (((val1 * val2) % m) * val3) % m;
    }

    // Helper: Sieve of Eratosthenes
    public static long[] sieve(int n) {
        int[] arr = new int[n + 1];
        java.util.Arrays.fill(arr, 0);
        java.util.List<Long> vect = new java.util.ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (arr[i] == 0) {
                vect.add((long)i);
                for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
            }
        }
        return vect.stream().mapToLong(Long::longValue).toArray();
    }

    // Helper: Euler's Totient Function
    public static long phin(long n) {
        long number = n;
        if (n % 2 == 0) {
            number /= 2;
            while (n % 2 == 0) n /= 2;
        }
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                while (n % i == 0) n /= i;
                number = (number / i) * (i - 1);
            }
        }
        if (n > 1) number = (number / n) * (n - 1);
        return number;
    }

    // Helper: Modulo Add
    public static long mod_add(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a + b) % m) + m) % m;
    }

    // Helper: Modulo Multiply
    public static long mod_mul(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a * b) % m) + m) % m;
    }

    // Helper: Modulo Subtract
    public static long mod_sub(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return (((a - b) % m) + m) % m;
    }

    // Helper: Modulo Divide
    public static long mod_div(long a, long b, long m) {
        a = a % m;
        b = b % m;
        return mod_mul(a, mminvprime(b, m), m);
    }

    // Helper: GCD
    public static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                long n = sc.nextLong();
                long m = sc.nextLong();
                long k = sc.nextLong();

                long[] pigment = new long[(int)k];
                for (int i = 0; i < k; i++) {
                    pigment[i] = sc.nextLong();
                }

                // Sort descending (C++ sort with greater<ll>)
                java.util.Arrays.sort(pigment);
                for (int i = 0; i < k / 2; i++) {
                    long temp = pigment[i];
                    pigment[i] = pigment[k - 1 - i];
                    pigment[k - 1 - i] = temp;
                }

                // Lambda for rowWise
                java.util.function.Function<Long, Boolean> rowWise = (nVal) -> {
                    long column = 0;
                    boolean val = (m % 2 == 0);

                    for (int i = 0; i < k; i++) {
                        long curr = pigment[i];
                        if (curr / nVal >= 2) column += (curr / nVal);
                        if (curr / nVal >= 3) val = true;
                    }

                    return column >= m && val;
                };

                // Lambda for colWise
                java.util.function.Function<Long, Boolean> colWise = (nVal) -> {
                    long row = 0;
                    boolean val = (n % 2 == 0);

                    for (int i = 0; i < k; i++) {
                        long curr = pigment[i];
                        if (curr / nVal >= 2) row += (curr / nVal);
                        if (curr / nVal >= 3) val = true;
                    }

                    return row >= n && val;
                };

                boolean result = rowWise.apply((Long)n) || colWise.apply((Long)n);
                
                if (result) {
                    System.out.println("Yes");
                } else {
                    System.out.println("No");
                }
            }
        }
    }
}
</CODE>