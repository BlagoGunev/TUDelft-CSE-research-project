Translate this C++ code to Java code. The main class name should be b_1736. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;



int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);



    ll t;

    cin >> t;

    while (t--)

    {

        bool ans = true;

        ll n;

        cin >> n;

        vector<ll> nums(n);

        for (ll i = 0; i < n; i++)

        {

            cin >> nums[i];

        }

        

        vector<ll> lcmVect(n+1);

        lcmVect[0] = nums[0];

        lcmVect[n] = nums[n-1];

        for (ll i = 1; i <= n-1; i++)

        {

            lcmVect[i] = lcm(nums[i-1], nums[i]);

        }

        for (ll i = 0; i < n; i++)

        {

            if(__gcd(lcmVect[i], lcmVect[i+1]) != nums[i])

            {

                ans = false;

                break;

            }

        }

        cout << ((ans)? "YES" : "NO") << endl;

    }



    return 0;

}

Here is the plan for the translation:

1.  **Headers and Namespaces**: The C++ code uses `#include <bits/stdc++.h>` and `using namespace std;`. In Java, we need to import specific classes from the `java.util` package (e.g., `Scanner`, `ArrayList`, `Collections`). Since `std::vector` is used, `ArrayList` is the equivalent.
2.  **Data Types**: The C++ code uses `long long` (aliased as `ll`) to handle potentially large numbers. In Java, this maps to `long`.
3.  **I/O Optimization**: The C++ code uses `ios_base::sync_with_stdio(false);` and `cin.tie(NULL);` for performance. In Java, standard `Scanner` can be slow for large inputs. However, without a specific requirement for a custom `FastReader` class, I will use standard `Scanner` for clarity, but given the constraints of competitive programming (implied by `bits/stdc++.h` and `MOD`), using `BufferedReader` and `StringTokenizer` is the standard Java equivalent for fast I/O. I will implement a simple `FastReader` class to ensure the translation is robust and performs similarly to the C++ version.
4.  **Mathematical Functions**:
    *   `std::gcd` (C++17): Maps to `Collections.gcd` in Java.
    *   `std::lcm` (C++17): There is no direct `lcm` in `java.util`. It must be implemented manually using the formula: `lcm(a, b) = (a * b) / gcd(a, b)`. Note: Since the numbers can be large, `(a * b)` might overflow `long`. We should perform multiplication modulo `MOD` or check for overflow. Looking at the logic, `lcmVect` stores the LCM of adjacent elements. If the input numbers are up to `MOD` (implied by the context of `MOD` constant), the LCM can exceed `Long.MAX_VALUE`. However, usually in these problems, the check `gcd(lcm, ...) != nums[i]` implies we are checking divisibility. Let's look closer: `gcd(lcm(a, b), c) == gcd(a, b)`. Actually, the condition `gcd(lcm(a, b), c) == c` is equivalent to checking if `c` divides `lcm(a, b)`. If `c` divides `lcm(a, b)`, then `c` divides `a` or `c` divides `b`? No, that's not right.
    *   Logic check: `gcd(lcm(a, b), c) == c` means `c` divides `lcm(a, b)`.
    *   Wait, the code calculates `lcmVect` where `lcmVect[i] = lcm(nums[i-1], nums[i])`. Then it checks `gcd(lcmVect[i], lcmVect[i+1]) != nums[i]`.
    *   `lcmVect[i]` is `lcm(nums[i-1], nums[i])`.
    *   `lcmVect[i+1]` is `lcm(nums[i], nums[i+1])`.
    *   `gcd(lcm(nums[i-1], nums[i]), lcm(nums[i], nums[i+1]))`.
    *   This expression simplifies. `gcd(A, B)` where `A` is a multiple of `X` and `B` is a multiple of `X` will be a multiple of `X`. So `gcd(...)` will be a multiple of `nums[i]`.
    *   The condition `!= nums[i]` checks if the GCD is strictly greater than `nums[i]`.
    *   To implement this in Java, we need a GCD function. We also need an LCM function. Since the values are `long`, `a*b` can overflow. We should use modular arithmetic if the result is only needed for comparison, or use `BigInteger`.
    *   However, looking at the logic `gcd(lcm(a,b), lcm(b,c)) == b`. If `b` divides `a` and `b` divides `c`, then `b` divides `lcm(a,b)` and `b` divides `lcm(b,c)`. Then `b` divides their GCD. So the GCD will be a multiple of `b`. If the GCD is strictly greater than `b`, it implies there is a common factor greater than `b` shared by `lcm(a,b)` and `lcm(b,c)`.
    *   Actually, `gcd(lcm(a,b), lcm(b,c))` is always a multiple of `b`. So checking `!= b` is checking if it's a *strict* multiple.
    *   Given the `MOD` constant is defined but not used in the snippet, it suggests this might be part of a larger problem or the constraints are within `long` range. If the inputs are small enough (e.g., <= 10^9), `lcm` can exceed `long`.
    *   Let's check the constraints implied. If `nums` contains values up to `10^9`, `lcm` can be `10^18`. This fits in `long`. If inputs are larger, we need `BigInteger`.
    *   Since the C++ code uses `long long` and doesn't use `__int128` or `BigInteger`, it assumes the values fit in `long long`. The LCM of two numbers up to `10^9` can be `10^18`, which fits in `long long` (max `9e18`). So standard `long` logic is likely sufficient, but we must be careful about overflow during `a*b`.
    *   Actually, `lcm(a, b) = (a / gcd(a, b)) * b`. This order of operations prevents overflow if the result fits in `long long`.
5.  **Structure**:
    *   Create class `b_1736`.
    *   Implement `main` method.
    *   Implement `gcd` method.
    *   Implement `lcm` method.
    *   Implement `FastReader` class (or use `Scanner` if performance isn't critical, but `FastReader` is safer for competitive programming translations).
6.  **Incremental Tasks**:
    *   Task 1: Setup class structure and imports.
    *   Task 2: Implement Fast I/O.
    *   Task 3: Implement `gcd` and `lcm` helper methods.
    *   Task 4: Translate the main logic loop and output.

```java
import java.util.Scanner;
import java.math.BigInteger;
// Or use custom GCD to avoid BigInteger overhead if possible, but BigInteger is safer for LCM logic.
// Given the C++ code uses long long, let's stick to long logic where possible, 
// but for LCM calculation, BigInteger is the safest way to avoid overflow 
// if the logic implies checking exact equality without modulo arithmetic.
// However, the check is gcd(...) != nums[i]. 
// If we use BigInteger for LCM, we can compute exact values.

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class b_1736 {
    
    // Fast I/O Reader
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
            if (s == null) return 0; // Handle EOF
            return Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            if (s == null) return 0; // Handle EOF
            return Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        // Check if input exists
        String tStr = sc.next();
        if (tStr == null) return;
        
        int t = Integer.parseInt(tStr);
        
        while (t-- > 0) {
            solve(sc);
        }
    }

    private static void solve(FastReader sc) {
        // Read n
        String nStr = sc.next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);

        // Read nums
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextLong();
        }

        // Logic translation
        // C++: vector<ll> lcmVect(n+1);
        // Java: long[] lcmVect = new long[n+1];
        
        // Note: In C++, lcm is std::lcm. 
        // Java doesn't have a built-in lcm for primitive types that handles overflow automatically.
        // We need to implement it carefully.
        // lcm(a, b) = (a * b) / gcd(a, b).
        // To avoid overflow in (a*b), we do (a / gcd(a,b)) * b.
        
        long[] lcmVect = new long[n + 1];
        
        // C++: lcmVect[0] = nums[0];
        // C++: lcmVect[n] = nums[n-1];
        // C++: for (ll i = 1; i <= n-1; i++) lcmVect[i] = lcm(nums[i-1], nums[i]);
        
        lcmVect[0] = nums[0];
        lcmVect[n] = nums[n-1];

        for (int i = 1; i < n; i++) {
            // Safe LCM calculation
            long g = gcd(nums[i-1], nums[i]);
            lcmVect[i] = (nums[i-1] / g) * nums[i];
        }

        // Check condition
        // C++: for (ll i = 0; i < n; i++) if(__gcd(lcmVect[i], lcmVect[i+1]) != nums[i])
        // Java: Collections.gcd is available in Java 8+ for BigInteger, but not for primitives.
        // We must use our custom gcd method.
        
        boolean ans = true;
        for (int i = 0; i < n; i++) {
            long g = gcd(lcmVect[i], lcmVect[i+1]);
            if (g != nums[i]) {
                ans = false;
                break;
            }
        }

        System.out.println(ans ? "YES" : "NO");
    }

    // Helper method for GCD
    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
```

Wait, I should double check the `lcm` overflow issue.
If `nums[i-1]` and `nums[i]` are both close to `10^9`, their LCM can be `10^18`. `long` in Java is `64-bit signed`, max value `~9e18`. So it fits.
However, if `nums` contains `0`, `lcm` is `0`.
If `nums` contains `1`, `lcm` is `1`.
The logic seems sound.

One detail: `__gcd` in C++ works with `long long`. `Collections.gcd` works with `BigInteger` or `int`. Since we are using `long`, we need a custom `gcd` method as implemented above.

Let's refine the code to be clean and strictly follow the C++ logic.

**Plan:**
1.  **Class Structure**: Define `public class b_1736`.
2.  **Imports**: `java.util.*`, `java.io.*`.
3.  **Fast I/O**: Create a `FastReader` class using `BufferedReader` to replace `cin`/`cout` optimization.
4.  **Helper Functions**:
    *   `gcd(long a, long b)`: Recursive or iterative GCD implementation.
    *   `lcm(long a, long b)`: `(a / gcd(a, b)) * b` to prevent overflow before multiplication.
5.  **Main Logic**:
    *   Read `t`.
    *   Loop `t` times.
    *   Read `n`.
    *   Read `nums` array.
    *   Compute `lcmVect` array.
        *   `lcmVect[0] = nums[0]`
        *   `lcmVect[n] = nums[n-1]`
        *   Loop `1` to `n-1` to fill rest.
    *   Verify condition: `gcd(lcmVect[i], lcmVect[i+1]) != nums[i]` for all `i` from `0` to `n-1`.
    *   Print "YES" or "NO".

**Incremental Steps:**
1.  Define class and imports.
2.  Implement `FastReader`.
3.  Implement `gcd` and `lcm` methods.
4.  Implement `main` method logic.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class b_1736 {
    
    // Fast I/O Reader to replace cin/cout optimization
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
                    return null;
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            return (s == null) ? 0 : Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            return (s == null) ? 0L : Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        
        // Read number of test cases
        String tStr = sc.next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        while (t-- > 0) {
            solve(sc);
        }
    }

    private static void solve(FastReader sc) {
        // Read n
        String nStr = sc.next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);

        // Read nums array
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextLong();
        }

        // Create LCM vector
        // In C++: vector<ll> lcmVect(n+1);
        long[] lcmVect = new long[n + 1];
        
        // In C++: lcmVect[0] = nums[0];
        lcmVect[0] = nums[0];
        
        // In C++: lcmVect[n] = nums[n-1];
        lcmVect[n] = nums[n-1];
        
        // In C++: for (ll i = 1; i <= n-1; i++) lcmVect[i] = lcm(nums[i-1], nums[i]);
        for (int i = 1; i < n; i++) {
            lcmVect[i] = lcm(nums[i-1], nums[i]);
        }

        // Check condition
        // In C++: for (ll i = 0; i < n; i++) if(__gcd(lcmVect[i], lcmVect[i+1]) != nums[i])
        boolean ans = true;
        for (int i = 0; i < n; i++) {
            if (gcd(lcmVect[i], lcmVect[i+1]) != nums[i]) {
                ans = false;
                break;
            }
        }

        // Output result
        // In C++: cout << ((ans)? "YES" : "NO") << endl;
        System.out.println(ans ? "YES" : "NO");
    }

    // Helper method for GCD
    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper method for LCM
    // Calculated as (a * b) / gcd(a, b)
    // To prevent overflow, we do (a / gcd(a, b)) * b
    private static long lcm(long a, long b) {
        if (a == 0 || b == 0) return 0;
        long g = gcd(a, b);
        return (a / g) * b;
    }
}
```

Wait, I need to make sure the class name is exactly `b_1736`.
Also, I should check if `lcm` overflow is possible.
If `nums[i]` are large primes, `lcm` is `nums[i-1] * nums[i]`. If `nums[i]` is up to `10^9`, product is `10^18`. `long` max is `9e18`. It fits.
If inputs are larger than `10^9` (e.g. `Long.MAX_VALUE`), it would overflow. But typically in such problems (implied by `bits/stdc++.h` and `MOD`), numbers fit in `long long` (64-bit).
However, if the problem is from a contest where numbers can be larger (e.g. modulo arithmetic is involved in the actual problem this snippet belongs to), `lcm` might need `BigInteger`.
But looking at the snippet: `const int MOD = 1e9 + 7;`. This suggests the numbers might be related to modulo or the problem involves modulo. But the code itself does not use `MOD` in the calculation. It just stores LCM.
If the problem is "check if array is LCM chain", usually numbers are small enough or the logic holds.
Given the C++ code uses `long long`, I will assume `long` in Java is sufficient. If `nums` contains values such that `lcm` exceeds `Long.MAX_VALUE`, the C++ code would also overflow/UB. So `long` is the correct translation.

One small detail: `__gcd` is a GCC extension. In standard C++17, `std::gcd` is available. The code uses `__gcd` which suggests it might be compiled with GCC. In Java, we implement it manually.

Final check on logic:
C++: `lcmVect` size `n+1`.
Indices `0` to `n`.
`lcmVect[0]` = `nums[0]`.
`lcmVect[n]` = `nums[n-1]`.
Loop `1` to `n-1`: `lcmVect[i] = lcm(nums[i-1], nums[i])`.
This fills `lcmVect[1]` to `lcmVect[n-1]`.
Total filled: `0` to `n-1` (via loop) and `n` (via assignment).
Wait.
`lcmVect[0]` is `nums[0]`.
`lcmVect[1]` is `lcm(nums[0], nums[1])`.
...
`lcmVect[n-1]` is `lcm(nums[n-2], nums[n-1])`.
`lcmVect[n]` is `nums[n-1]`.
The loop runs for `i` from `0` to `n-1`.
Inside loop: `gcd(lcmVect[i], lcmVect[i+1]) != nums[i]`.
If `i=0`: `gcd(lcmVect[0], lcmVect[1])` -> `gcd(nums[0], lcm(nums[0], nums[1]))`.
Since `nums[0]` divides `lcm(nums[0], nums[1])`, the GCD is `nums[0]`.
Condition `nums[0] != nums[0]` is false. So `ans` remains true.
If `i=n-1`: `gcd(lcmVect[n-1], lcmVect[n])` -> `gcd(lcm(nums[n-2], nums[n-1]), nums[n-1])`.
Since `nums[n-1]` divides `lcm(..., nums[n-1])`, GCD is `nums[n-1]`.
Condition `nums[n-1] != nums[n-1]` is false. So `ans` remains true.
So the check is effectively verifying the "chain" property for the middle elements.
The translation looks correct.

One edge case: `n=1`.
`lcmVect` size 2.
`lcmVect[0] = nums[0]`.
`lcmVect[1] = nums[0]`.
Loop `i` from `0` to `0`.
Check `gcd(lcmVect[0], lcmVect[1]) != nums[0]`.
`gcd(nums[0], nums[0])` is `nums[0]`.
`nums[0] != nums[0]` is false. `ans` true.
Output YES.
Correct.

The code seems solid.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class b_1736 {
    
    // Fast I/O Reader to replace cin/cout optimization
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
                    return null;
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            return (s == null) ? 0 : Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            return (s == null) ? 0L : Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        
        // Read number of test cases
        String tStr = sc.next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        while (t-- > 0) {
            solve(sc);
        }
    }

    private static void solve(FastReader sc) {
        // Read n
        String nStr = sc.next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);

        // Read nums array
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextLong();
        }

        // Create LCM vector
        // In C++: vector<ll> lcmVect(n+1);
        long[] lcmVect = new long[n + 1];
        
        // In C++: lcmVect[0] = nums[0];
        lcmVect[0] = nums[0];
        
        // In C++: lcmVect[n] = nums[n-1];
        lcmVect[n] = nums[n-1];
        
        // In C++: for (ll i = 1; i <= n-1; i++) lcmVect[i] = lcm(nums[i-1], nums[i]);
        for (int i = 1; i < n; i++) {
            lcmVect[i] = lcm(nums[i-1], nums[i]);
        }

        // Check condition
        // In C++: for (ll i = 0; i < n; i++) if(__gcd(lcmVect[i], lcmVect[i+1]) != nums[i])
        boolean ans = true;
        for (int i = 0; i < n; i++) {
            if (gcd(lcmVect[i], lcmVect[i+1]) != nums[i]) {
                ans = false;
                break;
            }
        }

        // Output result
        // In C++: cout << ((ans)? "YES" : "NO") << endl;
        System.out.println(ans ? "YES" : "NO");
    }

    // Helper method for GCD
    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper method for LCM
    // Calculated as (a * b) / gcd(a, b)
    // To prevent overflow, we do (a / gcd(a, b)) * b
    private static long lcm(long a, long b) {
        if (a == 0 || b == 0) return 0;
        long g = gcd(a, b);
        return (a / g) * b;
    }
}
```
</think>

Here is the plan for the translation:

1.  **Headers and Imports**: The C++ code uses `#include <bits/stdc++.h>` which includes everything. In Java, we need to explicitly import `java.util.*` and `java.io.*`.
2.  **Data Types**: The C++ code uses `long long` (aliased as `ll`) to store numbers. In Java, this maps to the `long` primitive type.
3.  **I/O Optimization**: The C++ code uses `ios_base::sync_with_stdio(false)` and `cin.tie(NULL)` to speed up input/output. In Java, the `Scanner` class can be too slow for large inputs. To maintain the performance characteristics of the C++ code, I will implement a `FastReader` class using `BufferedReader` and `StringTokenizer`.
4.  **Mathematical Functions**:
    *   `std::gcd`: This corresponds to a custom `gcd` method in Java (since `Collections.gcd` only works with `BigInteger` or `int`).
    *   `std::lcm`: Java does not have a built-in `lcm` function for primitives. I will implement it using the formula `lcm(a, b) = (a * b) / gcd(a, b)`. To prevent integer overflow during the multiplication `a * b`, I will calculate it as `(a / gcd(a, b)) * b`.
5.  **Logic Structure**:
    *   The C++ `main` function handles test cases. In Java, this translates to a loop in `main` calling a `solve` method.
    *   The `vector<ll> lcmVect` translates to a `long[] lcmVect` array in Java.
    *   The logic for filling `lcmVect` and checking the condition `gcd(lcmVect[i], lcmVect[i+1]) != nums[i]` will be directly translated.
6.  **Class Name**: The class name will be set to `b_1736`.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class b_1736 {
    
    // Fast I/O Reader to replace cin/cout optimization
    // This ensures the Java code performs similarly to the optimized C++ code.
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
                    return null;
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            return (s == null) ? 0 : Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            return (s == null) ? 0L : Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        
        // Read number of test cases
        String tStr = sc.next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        while (t-- > 0) {
            solve(sc);
        }
    }

    private static void solve(FastReader sc) {
        // Read n
        String nStr = sc.next();
        if (nStr == null) return;
        int n = Integer.parseInt(nStr);

        // Read nums array
        // C++: vector<ll> nums(n);
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextLong();
        }

        // Create LCM vector
        // C++: vector<ll> lcmVect(n+1);
        long[] lcmVect = new long[n + 1];
        
        // C++: lcmVect[0] = nums[0];
        lcmVect[0] = nums[0];
        
        // C++: lcmVect[n] = nums[n-1];
        lcmVect[n] = nums[n-1];
        
        // C++: for (ll i = 1; i <= n-1; i++) lcmVect[i] = lcm(nums[i-1], nums[i]);
        for (int i = 1; i < n; i++) {
            lcmVect[i] = lcm(nums[i-1], nums[i]);
        }

        // Check condition
        // C++: for (ll i = 0; i < n; i++) if(__gcd(lcmVect[i], lcmVect[i+1]) != nums[i])
        boolean ans = true;
        for (int i = 0; i < n; i++) {
            if (gcd(lcmVect[i], lcmVect[i+1]) != nums[i]) {
                ans = false;
                break;
            }
        }

        // Output result
        // C++: cout << ((ans)? "YES" : "NO") << endl;
        System.out.println(ans ? "YES" : "NO");
    }

    // Helper method for GCD
    // C++: __gcd or std::gcd
    private static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper method for LCM
    // C++: std::lcm
    // Calculated as (a * b) / gcd(a, b)
    // To prevent overflow, we do (a / gcd(a, b)) * b
    private static long lcm(long a, long b) {
        if (a == 0 || b == 0) return 0;
        long g = gcd(a, b);
        return (a / g) * b;
    }
}
```