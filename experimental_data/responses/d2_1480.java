Translate this C++ code to Java code. The main class name should be d2_1480. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
//Srayan Bhattachrayya JU EE

#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define lld long double

#define rep(i,n) for(ll i=0;i<n;i++)

#define rev(i,n) for(ll i=n;i>=0;i--)

#define rev_a(i,a,n) for(ll i=n;i>=a;i--)

#define rep_a(i,a,n) for(ll i=a;i<n;i++)

typedef pair <ll, ll> pll;

typedef vector <ll> vll;

typedef vector <vll> vvll;

typedef vector <string> vs;

typedef set <ll> sll;

typedef vector <pll> vpll;

typedef vector <long double> vld;

#define st(s) sort(s.begin(),s.end())

#define dst(s) sort(s.begin() , s.end() , greater<int>())

#define all(s) s.begin(), s.end()

#define yes cout << "YES" << "\n"

#define no cout << "NO" << "\n"

#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";

const ll MOD = 1e9 + 7; 

const ll MODS = 998244353; 

const ll NN = 1e7 + 10; 

const ll NS = 1e5 + 10;

const ll LLMAX = 1e18; 

const lld pi = 3.14159265358979323846;

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}

ll mods_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MODS) + MODS) % MODS;}

ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}

ll mod_inv(ll i) {if (i == 1) return 1; return (MOD - ((MOD / i) * mod_inv(MOD % i)) % MOD) % MOD;}

ll mod_pwr(ll a, ll b) { if(b < 0) return 0; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}



vs split(string s, string del = " "){

    vs ans; ll start = 0; ll end = s.find(del);

    while (end != -1) {

        cout << s.substr(start, end - start) << "\n";

        start = end + del.size(); 

        end = s.find(del, start);

    }

    ans.push_back(s.substr(start, end - start)); 

    return ans;

}



vll divisors(ll n){

    vll v;

    for (ll i = 1; i <= (ll)sqrt(n); i++){

        if (n % i == 0){

            v.emplace_back(i);

            if ((n / i) != i) v.emplace_back(n / i);

        }

    }

    return v;

}



vll findPrimeFactors(ll n){

    vll primeFactors;

    while (n%2== 0) primeFactors.push_back(2), n = n/2;

    for (ll i = 3; i*i <= n; i = i+2)

    {

        while (n%i == 0)

        {   

            primeFactors.push_back(i);

            n = n/i;

        }

    }

    if (n > 2) primeFactors.push_back(n);

    return primeFactors;

}



bool isPrime(ll n){

	if (n == 1) return false;

    if(n==2 or n==3) return true;

    if(n%2==0) return false;

    for(ll i=3; i * i <= n; i += 2) if(n % i==0) return false;

    return true;

}



ll *fact;

void calFact(){

    fact = new ll[NN];

    fact[0] = 1;

    fact[1] = 1;

    for (ll i = 2; i < NN; i++)

        fact[i] = mod_mul(fact[i - 1], i);

}

 

ll ncr(ll n, ll r){

    ll ans = fact[n];

    ans = mod_mul(ans, mod_inv(fact[n - r]));

    ans = mod_mul(ans, mod_inv(fact[r]));

    return ans;

}



bool isKthBitSet(ll n, ll k){

    if ((n >> k) & 1)

        return true;

    return false;

}



bool isPalindrome(string S){

    string P = S;

    reverse(all(P));

    if (S == P) return true;

    else return false;

}



ll n;

ll a[NS];

ll pos[NS], nxt[NS];

 

void solve()

{

	cin >> n;

	for (ll i = 1; i <= n; ++i) cin >> a[i];

	for (ll i = 0; i <= n; ++i) pos[i] = n + 1;

	for (ll i = n; i >= 0; --i)

	{

		nxt[i] = pos[a[i]];

		pos[a[i]] = i;

	}

	ll x = 0, y = 0;

	ll res = 0;

	for (ll z = 1; z <= n; ++z)

	{

		if (a[x] == a[z])

		{

			x = z;

		}

		else if (a[y] == a[z]) y = z;

		else if (nxt[x] > nxt[y]){

			res += 1;

			x = z;

		}

		else{

			res += 1;

			y = z;

		}

	}

	cout << res << "\n";

}



int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    ll t = 1;

    //cin >> t;

    while (t--){

        solve();

    }    

    return 0;

}

Here is the plan for translating the C++ code to Java:

1.  **Structure**: The C++ code uses a `main` function and defines helper functions globally. In Java, we will define a class `d2_1480` with a `main` method. We will move the helper functions (like `gcd`, `isPrime`, `solve`) into static methods within the class.
2.  **Data Types**:
    *   C++ `long long` (`ll`) maps to Java `long`.
    *   C++ `long double` (`lld`) maps to Java `double`.
    *   C++ `int` maps to Java `int`.
    *   C++ `string` maps to Java `String`.
    *   C++ `pair<ll, ll>` (`pll`) maps to Java `long[]` or a custom class. Given the usage in `vpll`, an `ArrayList<long[]>` is the most direct translation.
    *   C++ `vector` (`vll`, `vs`, `vvll`) maps to Java `ArrayList` or `List`.
    *   C++ `set` (`sll`) maps to Java `HashSet` or `TreeSet`.
3.  **Standard I/O**:
    *   C++ `iostream` (`cin`, `cout`, `endl`) is replaced by Java's `Scanner` or `BufferedReader` / `PrintWriter` for performance. Given the competitive programming context (indicated by the `bits/stdc++.h` and large arrays), `BufferedReader` and `PrintWriter` (or `System.out`) are preferred for speed.
    *   `cin >> t` and `cin >> a[i]` become `readLong()` or `readInt()`.
4.  **Specific Features & Macros**:
    *   `#define ll long long`: Replaced by using `long` in Java.
    *   `#define rep(i, n)`: Replaced by standard `for` loops.
    *   `#define all(s)`: Replaced by passing collections to sort methods.
    *   `#define yes`/`#define no`: Replaced by `System.out.println("YES")` etc.
    *   `typedef pair <ll, ll> pll`: Replaced by `long[]`.
    *   `typedef vector <ll> vll`: Replaced by `ArrayList<Long>` or `long[]`.
    *   `const ll MOD`: Replaced by `static final long MOD`.
    *   `vector` resizing: C++ vectors resize automatically. Java `ArrayList` does this, but array-based solutions are often faster. However, to keep the logic identical, `ArrayList` is safer for dynamic resizing, though for fixed-size arrays like `pos` and `nxt` in the code, primitive arrays are used.
5.  **Specific Logic Adjustments**:
    *   **`split` function**: The C++ code prints intermediate strings and returns a vector. The Java version should do the same. Note that the C++ code has a potential bug where `end` might be -1 initially, but the logic `s.substr(start, end - start)` would fail if `end` is -1. However, since it is a CP template, we will translate it faithfully. *Correction*: The C++ code prints `s.substr(start, end - start)` inside the loop. If `end` is -1 (delimiter not found), `substr` throws an exception or prints garbage. The logic assumes the delimiter exists.
    *   **`calFact`**: In C++, `fact` is a global pointer. In Java, we use a static array `long[] fact`.
    *   **`solve` function**: This contains the core logic. We need to ensure indices match (C++ uses 1-based indexing for `a`, `pos`, `nxt` sometimes, while Java arrays are 0-based). The C++ code initializes `pos` up to `n+1` and iterates `1` to `n`. We must preserve this logic.
    *   **`mod_mul`**: The C++ code uses `((a * b) % MOD) + MOD) % MOD` to handle overflow before modulo. In Java, `a * b` can overflow `long` if `a` and `b` are close to `MOD` (approx `10^9`). `10^9 * 10^9` is `10^18`, which fits in `long` (max `9*10^18`). So, standard modulo arithmetic works fine in Java without the extra `+ MOD` check unless `MOD` is larger than `sqrt(Long.MAX_VALUE)`. Since `MOD` is `10^9+7`, `MOD * MOD` fits in `long`. We can simplify the modulo logic slightly compared to the C++ version, but to be faithful to the template, we will keep the structure or optimize it if safe. The C++ code adds `+ MOD` before the final `% MOD`, which is redundant if `a` and `b` are already modded, but safe. In Java, `a` and `b` are modded, so `a*b` is positive. `(a*b)%MOD` is sufficient.
    *   **`ncr`**: Calculates combinations.
    *   **`isKthBitSet`**: Checks if the k-th bit is set. Java uses `>>>` for unsigned right shift.
    *   **`isPalindrome`**: Uses `StringBuilder` or `String` manipulation.
6.  **Incremental Tasks**:
    *   Step 1: Define class `d2_1480` and static constants (`MOD`, `NN`, `NS`, `fact` array).
    *   Step 2: Translate utility functions (`gcd`, `ceil_div`, `mod_mul`, `mod_pwr`, `isPrime`).
    *   Step 3: Translate `split` function.
    *   Step 4: Translate `divisors` and `findPrimeFactors`.
    *   Step 5: Translate `ncr`, `isKthBitSet`, `isPalindrome`.
    *   Step 6: Translate `calFact` (initialization of static array).
    *   Step 7: Translate `solve` logic (handling `pos`, `nxt`, and the main loop).
    *   Step 8: Update `main` to handle input/output and call `solve`.

**Note on `split` function**: The C++ code `s.substr(start, end - start)` when `end` is -1 will throw `StringIndexOutOfBoundsException` or print garbage depending on implementation. However, I will translate it as is, assuming the input string contains the delimiter.

**Note on `fact` array**: The C++ code uses `new ll[NN]`. In Java, we use `new long[NN]`.

**Note on `pos` and `nxt` arrays**: C++ uses `ll a[NS]`. Java uses `long[]`.

```java
//Srayan Bhattachrayya JU EE

import java.util.*;
import java.io.*;

public class d2_1480 {
    // Constants
    static final long MOD = 1000000007L; 
    static final long MODS = 998244353L; 
    static final int NN = 10000010; 
    static final int NS = 100010;
    static final long LLMAX = 1000000000000000000L; 

    // Global Fact Array
    static long[] fact;

    // Static Helper Methods
    static long gcd(long a, long b) { 
        if (b == 0) return a; 
        return gcd(b, a % b);
    }

    static long ceil_div(long a, long b) {
        return a % b == 0 ? a / b : a / b + 1;
    }

    static long mod_mul(long a, long b) {
        a = a % MOD; 
        b = b % MOD; 
        return (((a * b) % MOD) + MOD) % MOD;
    }

    static long mod_inv(long i) {
        if (i == 1) return 1;
        return (MOD - ((MOD / i) * mod_inv(MOD % i)) % MOD) % MOD;
    }

    static long mod_pwr(long a, long b) { 
        if(b < 0) return 0; 
        long res = 1; 
        while (b > 0) {
            if (b & 1) res = res * a % MOD; 
            a = a * a % MOD; 
            b >>= 1;
        }
        return res;
    }

    // Function to calculate factorials
    static void calFact() {
        fact = new long[NN];
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i < NN; i++)
            fact[i] = mod_mul(fact[i - 1], i);
    }

    // Function to calculate nCr
    static long ncr(long n, long r) {
        long ans = fact[(int)n];
        ans = mod_mul(ans, mod_inv(fact[(int)(n - r)]));
        ans = mod_mul(ans, mod_inv(fact[(int)r]));
        return ans;
    }

    // Function to check if k-th bit is set
    static boolean isKthBitSet(long n, int k) {
        if ((n >>> k & 1) == 1)
            return true;
        return false;
    }

    // Function to check if string is palindrome
    static boolean isPalindrome(String S) {
        String P = new StringBuilder(S).reverse().toString();
        if (S.equals(P)) return true;
        else return false;
    }

    // Function to split string
    static List<String> split(String s, String del) {
        List<String> ans = new ArrayList<>();
        int start = 0; 
        int end = s.indexOf(del);
        while (end != -1) {
            System.out.println(s.substring(start, end));
            start = end + del.length(); 
            end = s.indexOf(del, start);
        }
        ans.add(s.substring(start, s.length())); 
        return ans;
    }

    // Function to find divisors
    static List<Long> divisors(long n) {
        List<Long> v = new ArrayList<>();
        for (long i = 1; i <= Math.sqrt(n); i++){
            if (n % i == 0){
                v.add(i);
                if ((n / i) != i) v.add(n / i);
            }
        }
        return v;
    }

    // Function to find prime factors
    static List<Long> findPrimeFactors(long n) {
        List<Long> primeFactors = new ArrayList<>();
        while (n % 2 == 0) primeFactors.add(2L), n = n / 2;
        for (long i = 3; i * i <= n; i = i + 2)
        {
            while (n % i == 0)
            {   
                primeFactors.add(i);
                n = n / i;
            }
        }
        if (n > 2) primeFactors.add(n);
        return primeFactors;
    }

    // Function to check if number is prime
    static boolean isPrime(long n) {
        if (n == 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;
        for (long i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
        return true;
    }

    // Main solve function
    static void solve() {
        Scanner sc = new Scanner(System.in); // Using Scanner for simplicity, though BufferedReader is faster
        // Note: The original C++ code uses fast I/O. 
        // To match the exact behavior of the provided snippet without external IO class overhead, 
        // we assume the input is available or use Scanner. 
        // However, looking at the C++ code, it uses cin directly. 
        // Let's implement a simple FastReader to match the CP style.
        
        // Re-implementing IO logic inside solve to match C++ structure exactly 
        // (assuming the C++ code relies on global cin/cout).
        // Since we are in a single class, we can't easily share a Scanner instance across static methods 
        // without passing it. 
        // Let's use a static Scanner for the whole class.
    }

    // Static Scanner for IO
    static Scanner sc = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    // Static arrays
    static long[] a;
    static int[] pos;
    static int[] nxt;
    static int n;

    // Re-declaring solve to use static arrays and IO
    static void solve2() {
        if (!sc.hasNext()) return;
        n = sc.nextInt();
        a = new long[n + 1];
        pos = new int[n + 1];
        nxt = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextLong();
        }

        for (int i = 0; i <= n; i++) pos[i] = n + 1;
        for (int i = n; i >= 0; i--)
        {
            nxt[i] = pos[a[i]];
            pos[a[i]] = i;
        }

        long x = 0, y = 0;
        long res = 0;
        for (int z = 1; z <= n; z++)
        {
            if (a[x] == a[z])
            {
                x = z;
            }
            else if (a[y] == a[z]) y = z;
            else if (nxt[x] > nxt[y]){
                res += 1;
                x = z;
            }
            else{
                res += 1;
                y = z;
            }
        }
        out.println(res);
    }

    public static void main(String[] args) {
        calFact();
        int t = 1;
        // if input has t, read it, else default to 1
        if (sc.hasNext()) t = sc.nextInt();
        
        for (int i = 0; i < t; i++) {
            solve2();
        }
        out.flush();
    }
}
```

Wait, I should refine the `split` function usage. In the original C++ code, `split` is defined but not used in `solve`. It seems to be a utility. I will include it.
Also, I need to make sure the `solve` function logic matches exactly.
The C++ code:
```cpp
    ll x = 0, y = 0;
    ll res = 0;
    for (ll z = 1; z <= n; ++z)
    {
        if (a[x] == a[z])
        {
            x = z;
        }
        else if (a[y] == a[z]) y = z;
        else if (nxt[x] > nxt[y]){
            res += 1;
            x = z;
        }
        else{
            res += 1;
            y = z;
        }
    }
```
In Java, `a` is `long[]`. `x` and `y` are `int` indices. `nxt` is `int[]`.
The logic holds.

One detail: `nxt[x]` accesses `nxt` array. `x` is an index. `nxt` is size `n+1`.
In C++, `nxt` is initialized up to `n`. `pos` up to `n`.
In Java, arrays are 0-indexed.
The C++ code: `ll pos[NS];` ... `for (ll i = 0; i <= n; ++i) pos[i] = n + 1;`.
This implies `pos` is size `NS` (100010) which covers `n`.
In Java, I allocated `pos = new int[n + 1]`. This is sufficient for indices `0` to `n`.

Let's do a final check on `mod_mul`.
C++: `((a * b) % MOD) + MOD) % MOD`.
If `a` and `b` are modded (`a < MOD`, `b < MOD`), `a*b` is positive. `(a*b)%MOD` is positive. Adding `MOD` makes it `> MOD`. `% MOD` brings it back.
In Java, `long` is 64-bit signed. `MOD` is `10^9+7`. `MOD * MOD` is approx `10^18`. `Long.MAX_VALUE` is approx `9*10^18`. So `a*b` does not overflow `long`.
So `((a * b) % MOD)` is sufficient. The `+ MOD` is redundant but harmless. I will keep it to be faithful to the template.

Also, `split` function in C++:
```cpp
    vs ans; ll start = 0; ll end = s.find(del);
    while (end != -1) {
        cout << s.substr(start, end - start) << "\n";
        start = end + del.size(); 
        end = s.find(del, start);
    }
    ans.push_back(s.substr(start, end - start)); 
    return ans;
```
If `s.find(del)` returns `-1`, `s.substr(0, -1)` throws exception.
I will keep the logic as is, assuming valid input.

One small correction: The C++ code uses `cin >> t` commented out.
`//cin >> t;`
`ll t = 1;`
So it runs once.
In Java, I should handle the `t` input if present.
`int t = 1; if (sc.hasNext()) t = sc.nextInt();`
Wait, if the input file has `t` at the beginning, `sc.hasNext()` will be true.
If the input file does not have `t`, `sc.hasNext()` is false.
The C++ code `ll t = 1; while(t--)` implies it runs once regardless, unless `cin >> t` is uncommented.
The C++ code has `//cin >> t;`. So it runs once.
I will follow the C++ code logic: `int t = 1; while(t--)`.
However, to be robust against a test case file that *does* contain `t`, I should probably check `sc.hasNext()`. But strictly translating the C++ code means ignoring the `cin >> t` line.
I will set `t = 1` and loop once.

Wait, looking at the C++ code again:
```cpp
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while (t--){
        solve();
    }    
    return 0;
}
```
It explicitly sets `t=1` and ignores `cin >> t`. So the program runs exactly once per execution.
I will replicate this.

One detail: `split` function uses `cout << ...`.
The `solve` function uses `cout << res << "\n";`.
In Java, I should use `System.out.println` or `out.println`.
Since `split` is a utility, it's fine to use `System.out`.
However, mixing `System.out` and `PrintWriter` might cause flushing issues.
I will use `System.out` for `split` and `out.println` for `solve`?
Better to be consistent. I will use `System.out` for everything to match the C++ `cout`.
Or I can use `PrintWriter` for everything. `PrintWriter` is safer for CP.
I will use `PrintWriter` for `solve` and `split`. For `split`, I will use `out.println`.

Wait, `split` function in C++ prints to `cout`.
If I use `out` in Java, I need to ensure `out` is flushed at the end.
I will use `out.println` for `split` and `solve` and `out.flush()` at the end.

Final check on `fact` array size.
C++: `const ll NN = 1e7 + 10;` -> `10000010`.
Java: `static final int NN = 10000010;`
`fact` array size `NN`.
Indices `0` to `NN-1`.
`fact` is initialized up to `NN`.
`ncr` uses `fact[n]`. `n` can be up to `NN-1`.
In `solve`, `n` is read. Is `n` limited by `NN`?
The C++ code `const ll NN = 1e7 + 10`.
If `n` in `solve` is larger than `NN`, `fact` access will throw.
But `solve` does not use `ncr`. `ncr` is defined but not called in `solve`.
`solve` uses `a`, `pos`, `nxt`.
So `NN` is not used in `solve`.
Wait, `calFact` is called in `main`.
If `solve` is not called, `fact` is not used.
But `calFact` is called.
If `n` in `solve` is large, `fact` might not be large enough.
But `solve` does not use `fact`.
So it's fine.

```java
//Srayan Bhattachrayya JU EE

import java.util.*;
import java.io.*;

public class d2_1480 {
    // Constants
    static final long MOD = 1000000007L; 
    static final long MODS = 998244353L; 
    static final int NN = 10000010; 
    static final int NS = 100010;
    static final long LLMAX = 1000000000000000000L; 

    // Global Fact Array
    static long[] fact;

    // Static Helper Methods
    static long gcd(long a, long b) { 
        if (b == 0) return a; 
        return gcd(b, a % b);
    }

    static long ceil_div(long a, long b) {
        return a % b == 0 ? a / b : a / b + 1;
    }

    static long mod_mul(long a, long b) {
        a = a % MOD; 
        b = b % MOD; 
        return (((a * b) % MOD) + MOD) % MOD;
    }

    static long mod_inv(long i) {
        if (i == 1) return 1;
        return (MOD - ((MOD / i) * mod_inv(MOD % i)) % MOD) % MOD;
    }

    static long mod_pwr(long a, long b) { 
        if(b < 0) return 0; 
        long res = 1; 
        while (b > 0) {
            if (b & 1) res = res * a % MOD; 
            a = a * a % MOD; 
            b >>= 1;
        }
        return res;
    }

    // Function to calculate factorials
    static void calFact() {
        fact = new long[NN];
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i < NN; i++)
            fact[i] = mod_mul(fact[i - 1], i);
    }

    // Function to calculate nCr
    static long ncr(long n, long r) {
        long ans = fact[(int)n];
        ans = mod_mul(ans, mod_inv(fact[(int)(n - r)]));
        ans = mod_mul(ans, mod_inv(fact[(int)r]));
        return ans;
    }

    // Function to check if k-th bit is set
    static boolean isKthBitSet(long n, int k) {
        if ((n >>> k & 1) == 1)
            return true;
        return false;
    }

    // Function to check if string is palindrome
    static boolean isPalindrome(String S) {
        String P = new StringBuilder(S).reverse().toString();
        if (S.equals(P)) return true;
        else return false;
    }

    // Function to split string
    static List<String> split(String s, String del) {
        List<String> ans = new ArrayList<>();
        int start = 0; 
        int end = s.indexOf(del);
        while (end != -1) {
            System.out.println(s.substring(start, end));
            start = end + del.length(); 
            end = s.indexOf(del, start);
        }
        ans.add(s.substring(start, s.length())); 
        return ans;
    }

    // Function to find divisors
    static List<Long> divisors(long n) {
        List<Long> v = new ArrayList<>();
        for (long i = 1; i <= Math.sqrt(n); i++){
            if (n % i == 0){
                v.add(i);
                if ((n / i) != i) v.add(n / i);
            }
        }
        return v;
    }

    // Function to find prime factors
    static List<Long> findPrimeFactors(long n) {
        List<Long> primeFactors = new ArrayList<>();
        while (n % 2 == 0) primeFactors.add(2L), n = n / 2;
        for (long i = 3; i * i <= n; i = i + 2)
        {
            while (n % i == 0)
            {   
                primeFactors.add(i);
                n = n / i;
            }
        }
        if (n > 2) primeFactors.add(n);
        return primeFactors;
    }

    // Function to check if number is prime
    static boolean isPrime(long n) {
        if (n == 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;
        for (long i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
        return true;
    }

    // Main solve function
    static void solve() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNext()) return;
        n = sc.nextInt();
        a = new long[n + 1];
        pos = new int[n + 1];
        nxt = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextLong();
        }

        for (int i = 0; i <= n; i++) pos[i] = n + 1;
        for (int i = n; i >= 0; i--)
        {
            nxt[i] = pos[a[i]];
            pos[a[i]] = i;
        }

        long x = 0, y = 0;
        long res = 0;
        for (int z = 1; z <= n; z++)
        {
            if (a[x] == a[z])
            {
                x = z;
            }
            else if (a[y] == a[z]) y = z;
            else if (nxt[x] > nxt[y]){
                res += 1;
                x = z;
            }
            else{
                res += 1;
                y = z;
            }
        }
        System.out.println(res);
    }

    // Static Scanner for IO
    static Scanner sc = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    // Static arrays
    static long[] a;
    static int[] pos;
    static int[] nxt;
    static int n;

    public static void main(String[] args) {
        calFact();
        int t = 1;
        //cin >> t;
        while (t--){
            solve();
        }    
        out.flush();
    }
}
```
Wait, I used `System.out` inside `solve` but `out` in `main`.
I should use `out` inside `solve` to be consistent with `out.flush()`.
Also, `split` uses `System.out`. I should use `out` there too.
If I use `out` inside `split`, I need to flush `out` or just flush at the end.
Since `split` is called inside `solve`? No, `split` is not called in `solve`.
`solve` prints to `System.out`.
I will change `solve` to use `out.println`.
And `split` to use `out.println`.
Wait, `split` is not called in `solve`. So it doesn't matter much.
But for consistency, I will use `out` in `solve`.

Also, `split` function in C++:
```cpp
    vs ans; ll start = 0; ll end = s.find(del);
    while (end != -1) {
        cout << s.substr(start, end - start) << "\n";
        start = end + del.size(); 
        end = s.find(del, start);
    }
    ans.push_back(s.substr(start, end - start)); 
    return ans;
```
Note: `s.find(del)` returns index.
If `del` is not found, `end` is -1.
`s.substr(start, end - start)` -> `s.substr(0, -1)` -> Exception.
I will keep this logic as is, assuming the caller ensures `del` is present.

One more thing: `a` is `long[]`. `x` and `y` are `int` indices.
Comparison `a[x] == a[z]` works.
`nxt[x]` works.
`nxt` is `int[]`.
`pos` is `int[]`.
This is correct.

I will update `solve` to use `out` instead of `System.out` to be consistent with `out.flush()`.
And `split` to use `out`.

Wait, the C++ code uses `cout` directly.
If I use `PrintWriter`, I must ensure I don't mix `System.out` and `PrintWriter` if they are not synchronized.
I will use `out` for all output.
I need to make sure `out` is initialized before `solve` is called.
`out = new PrintWriter(System.out);` is in `main`.
So `solve` can use `out`.

One issue: `split` function is defined but not used.
I will keep it as is.

Final check on `mod_mul`.
In C++, `a` and `b` are modded.
`a * b` can be `~10^18`.
`long` in Java is `~9*10^18`.
So `a * b` does not overflow.
`(a * b) % MOD` is positive.
`+ MOD` makes it `> MOD`.
`% MOD` brings it back.
So `mod_mul` is safe.

One detail: `nxt[x] > nxt[y]`.
If `x` or `y` are 0, `nxt[0]` is accessed.
`nxt` is size `n+1`. `nxt[0]` is valid.
`pos[0]` is `n+1`.
So `nxt[0]` will be `n+1` initially.
If `a[0]` is accessed, it's fine.
In `solve`, `a` is size `n+1`. `a[0]` is read?
`for (ll i = 1; i <= n; ++i) cin >> a[i];`
So `a[0]` is not read. It is 0 (default).
`pos[0]` is initialized to `n+1`.
`nxt[0]` is set to `pos[a[0]]` -> `pos[0]` -> `n+1`.
So `nxt[0]` is `n+1`.
In loop `z` from 1 to `n`.
`x` starts at 0. `a[x]` is `a[0]` (0).
`y` starts at 0. `a[y]` is `a[0]` (0).
`nxt[x]` is `n+1`. `nxt[y]` is `n+1`.
`nxt[x] > nxt[y]` is false.
Else `res += 1`, `y = z`.
So `y` becomes 1. `x` remains 0.
Next `z=2`.
`a[x] == a[2]`? `a[0] == a[2]`?
If not, `a[y] == a[2]`? `a[1] == a[2]`?
If not, `nxt[x] > nxt[y]`?
`nxt[0]` is `n+1`. `nxt[1]` is `pos[a[1]]`.
If `n+1 > nxt[1]`, then `res++`, `x=2`.
This logic seems consistent with the C++ code.

I will finalize the code now.
I will replace `System.out` with `out` in `solve` and `split` to be consistent.
I will ensure `out` is flushed.

One detail: `split` function takes `String del`.
In C++, `del` is default `" "`.
In Java, `String del` parameter.
I will keep the default value logic?
Java doesn't support default arguments in method calls easily without overloading or wrapper.
I will keep the signature `split(String s, String del)` and call it with `split(s, " ")`.
Or I can make `del` optional? No, Java doesn't support optional args.
I will just use `split(s, " ")`.

Wait, `split` function in C++:
```cpp
vs split(string s, string del = " "){
```
This is a default argument.
In Java, I can't have default arguments.
I will define `split(String s, String del)` and call it with `split(s, " ")`.
Or I can overload `split(String s)`.
I will overload `split(String s)`.
If `del` is null, use `" "`.
This is a better translation.

```java
    static List<String> split(String s) {
        return split(s, " ");
    }
    
    static List<String> split(String s, String del) {
        List<String> ans = new ArrayList<>();
        int start = 0; 
        int end = s.indexOf(del);
        while (end != -1) {
            out.println(s.substring(start, end));
            start = end + del.length(); 
            end = s.indexOf(del, start);
        }
        ans.add(s.substring(start, s.length())); 
        return ans;
    }
```
This is good.

I will also make sure to import `java.util.*` and `java.io.*`.

One last check: `mod_mul` uses `MOD`.
In `mod_mul`, `a` and `b` are modded.
`a * b` can be up to `MOD^2`.
`MOD = 10^9 + 7`. `MOD^2` approx `10^18`.
`Long.MAX_VALUE` approx `9*10^18`.
So `a * b` fits in `long`.
`((a * b) % MOD) + MOD) % MOD` is safe.

I will write the code now.
</think>

```java
//Srayan Bhattachrayya JU EE

import java.util.*;
import java.io.*;

public class d2_1480 {
    // Constants
    static final long MOD = 1000000007L; 
    static final long MODS = 998244353L; 
    static final int NN = 10000010; 
    static final int NS = 100010;
    static final long LLMAX = 1000000000000000000L; 

    // Global Fact Array
    static long[] fact;

    // Static Helper Methods
    static long gcd(long a, long b) { 
        if (b == 0) return a; 
        return gcd(b, a % b);
    }

    static long ceil_div(long a, long b) {
        return a % b == 0 ? a / b : a / b + 1;
    }

    static long mod_mul(long a, long b) {
        a = a % MOD; 
        b = b % MOD; 
        return (((a * b) % MOD) + MOD) % MOD;
    }

    static long mod_inv(long i) {
        if (i == 1) return 1;
        return (MOD - ((MOD / i) * mod_inv(MOD % i)) % MOD) % MOD;
    }

    static long mod_pwr(long a, long b) { 
        if(b < 0) return 0; 
        long res = 1; 
        while (b > 0) {
            if (b & 1) res = res * a % MOD; 
            a = a * a % MOD; 
            b >>= 1;
        }
        return res;
    }

    // Function to calculate factorials
    static void calFact() {
        fact = new long[NN];
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i < NN; i++)
            fact[i] = mod_mul(fact[i - 1], i);
    }

    // Function to calculate nCr
    static long ncr(long n, long r) {
        long ans = fact[(int)n];
        ans = mod_mul(ans, mod_inv(fact[(int)(n - r)]));
        ans = mod_mul(ans, mod_inv(fact[(int)r]));
        return ans;
    }

    // Function to check if k-th bit is set
    static boolean isKthBitSet(long n, int k) {
        if ((n >>> k & 1) == 1)
            return true;
        return false;
    }

    // Function to check if string is palindrome
    static boolean isPalindrome(String S) {
        String P = new StringBuilder(S).reverse().toString();
        if (S.equals(P)) return true;
        else return false;
    }

    // Function to split string
    static List<String> split(String s) {
        return split(s, " ");
    }
    
    static List<String> split(String s, String del) {
        List<String> ans = new ArrayList<>();
        int start = 0; 
        int end = s.indexOf(del);
        while (end != -1) {
            out.println(s.substring(start, end));
            start = end + del.length(); 
            end = s.indexOf(del, start);
        }
        ans.add(s.substring(start, s.length())); 
        return ans;
    }

    // Function to find divisors
    static List<Long> divisors(long n) {
        List<Long> v = new ArrayList<>();
        for (long i = 1; i <= Math.sqrt(n); i++){
            if (n % i == 0){
                v.add(i);
                if ((n / i) != i) v.add(n / i);
            }
        }
        return v;
    }

    // Function to find prime factors
    static List<Long> findPrimeFactors(long n) {
        List<Long> primeFactors = new ArrayList<>();
        while (n % 2 == 0) primeFactors.add(2L), n = n / 2;
        for (long i = 3; i * i <= n; i = i + 2)
        {
            while (n % i == 0)
            {   
                primeFactors.add(i);
                n = n / i;
            }
        }
        if (n > 2) primeFactors.add(n);
        return primeFactors;
    }

    // Function to check if number is prime
    static boolean isPrime(long n) {
        if (n == 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;
        for (long i = 3; i * i <= n; i += 2) if (n % i == 0) return false;
        return true;
    }

    // Main solve function
    static void solve() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNext()) return;
        n = sc.nextInt();
        a = new long[n + 1];
        pos = new int[n + 1];
        nxt = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextLong();
        }

        for (int i = 0; i <= n; i++) pos[i] = n + 1;
        for (int i = n; i >= 0; i--)
        {
            nxt[i] = pos[a[i]];
            pos[a[i]] = i;
        }

        long x = 0, y = 0;
        long res = 0;
        for (int z = 1; z <= n; z++)
        {
            if (a[x] == a[z])
            {
                x = z;
            }
            else if (a[y] == a[z]) y = z;
            else if (nxt[x] > nxt[y]){
                res += 1;
                x = z;
            }
            else{
                res += 1;
                y = z;
            }
        }
        out.println(res);
    }

    // Static Scanner for IO
    static Scanner sc = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    // Static arrays
    static long[] a;
    static int[] pos;
    static int[] nxt;
    static int n;

    public static void main(String[] args) {
        calFact();
        int t = 1;
        //cin >> t;
        while (t--){
            solve();
        }    
        out.flush();
    }
}
```