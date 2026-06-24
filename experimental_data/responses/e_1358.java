Translate this C++ code to Java code. The main class name should be e_1358. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <unordered_set>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <random>
#include <cfloat>
#include <chrono>
#include <bitset>
#include <complex>
#include <immintrin.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    int32_t n;
    std::cin >> n;

    int32_t* arr = new int32_t[n];
    std::mt19937 rng;
    for(int32_t i = 0; i < (n + 1) / 2; i++)
        std::cin >> arr[i];

    std::cin >> arr[(n + 1) / 2];
    for(int32_t i = (n + 1) / 2 + 1; i < n; i++)
        arr[i] = arr[i - 1];

    int64_t* pref_sums = new int64_t[n + 1];
    pref_sums[0] = 0;
    for(int32_t i = 1; i <= n; i++)
        pref_sums[i] = pref_sums[i - 1] + arr[i - 1];

    int32_t k = 1;
    while(true) {
        int32_t old_k = k;
        for(int32_t i = 0; i < n; i++) {
            while(i < n - k && pref_sums[i + k] - pref_sums[i] <= 0)
                k++;
            while(i >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0)
                k++;
        }

        bool ok = true;
        for(int32_t i = 0; i < n; i++) {
            if(i <= n - k && pref_sums[i + k] - pref_sums[i] <= 0)
                ok = false;
            if(i + 1 >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0)
                ok = false;
        }

        if(ok && old_k == k) {
            std::cout << k;
            return 0;
        }
        if(!ok && old_k == k) {
            std::cout << -1;
            return 0;
        }
    }
    return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Language Differences & Translation Strategy**:
    *   **Main Entry Point**: C++ uses `int main()`. Java uses `public static void main(String[] args)`.
    *   **I/O Handling**: C++ uses `std::cin`/`std::cout` with manual synchronization (`std::ios::sync_with_stdio(false)`). Java uses `Scanner` or `BufferedReader`/`StringTokenizer`. For competitive programming (suggested by the code structure), `BufferedReader` is preferred for speed. I will use `BufferedReader` and `StringTokenizer` to handle the input stream efficiently.
    *   **Dynamic Arrays**: C++ uses `new int32_t[n]`. Java uses arrays `int[n]` or `long[n]`. Note that Java arrays are objects, so we don't need `new` explicitly if we declare `int[]` or `long[]`.
    *   **Integer Types**: C++ uses `int32_t` and `int64_t`. Java uses `int` (32-bit signed) and `long` (64-bit signed).
    *   **Random Number Generator**: C++ uses `std::mt19937`. In Java, `java.util.Random` is the equivalent. However, the provided code initializes `rng` but never uses it. I will keep the declaration for fidelity but can omit the instantiation if it serves no purpose to reduce clutter, though keeping it maintains the exact logic flow.
    *   **Includes**: C++ headers (`<iostream>`, `<vector>`, etc.) are replaced by Java imports (`java.io.*`, `java.util.*`).
    *   **Logic**: The logic loops and array indexing are identical. Java arrays are 0-indexed, matching C++ behavior here.
    *   **Output**: `std::cout` is replaced by `System.out.println` or `PrintWriter`.
    *   **Bitwise/Complexity**: `std::bitset` and `std::complex` are unused in the logic, but I will import necessary standard libraries.

2.  **Incremental Tasks**:
    *   Step 1: Setup class structure and imports.
    *   Step 2: Implement `FastScanner` (Reader/Tokenizer) for input.
    *   Step 3: Implement array reading and initialization logic.
    *   Step 4: Implement the prefix sum calculation.
    *   Step 5: Implement the `while(true)` loop logic (binary search simulation or iterative search).
    *   Step 6: Output result.

3.  **Specific Code Adjustments**:
    *   `int32_t` becomes `int`.
    *   `int64_t` becomes `long`.
    *   `std::vector` usage is minimal (only raw arrays here), so standard arrays are sufficient.
    *   `std::ios::sync_with_stdio(false)` is simulated by using `BufferedReader`.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Random;

public class e_1358 {
    
    public static void main(String[] args) {
        // Fast I/O setup
        FastScanner scanner = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        // Read n
        int n = scanner.nextInt();
        
        // Read array arr
        // C++: int32_t* arr = new int32_t[n];
        int[] arr = new int[n];
        
        // C++: std::mt19937 rng; // Unused in logic, keeping declaration for fidelity
        Random rng = new Random();
        
        // Read first half
        for(int i = 0; i < (n + 1) / 2; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Read middle element
        int middleIdx = (n + 1) / 2;
        arr[middleIdx] = scanner.nextInt();
        
        // Read remaining elements (copying previous)
        // C++: for(int32_t i = (n + 1) / 2 + 1; i < n; i++) arr[i] = arr[i - 1];
        for(int i = middleIdx + 1; i < n; i++) {
            arr[i] = arr[i - 1];
        }
        
        // Calculate prefix sums
        // C++: int64_t* pref_sums = new int64_t[n + 1];
        long[] pref_sums = new long[n + 1];
        pref_sums[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            // C++: pref_sums[i] = pref_sums[i - 1] + arr[i - 1];
            pref_sums[i] = pref_sums[i - 1] + arr[i - 1];
        }
        
        // Search logic
        int k = 1;
        while(true) {
            int old_k = k;
            
            // Check if k can be increased
            // C++: for(int32_t i = 0; i < n; i++) { while(i < n - k && pref_sums[i + k] - pref_sums[i] <= 0) k++; ... }
            for(int i = 0; i < n; i++) {
                while(i < n - k && pref_sums[i + k] - pref_sums[i] <= 0) {
                    k++;
                }
                // Note: The inner while loop modifies k. This is a side effect that persists across iterations of the outer for loop.
                // In C++, this is valid. In Java, it works the same way.
                while(i >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0) {
                    k++;
                }
            }
            
            // Check validity
            // C++: bool ok = true;
            boolean ok = true;
            for(int i = 0; i < n; i++) {
                // C++: if(i <= n - k && pref_sums[i + k] - pref_sums[i] <= 0) ok = false;
                if(i <= n - k && pref_sums[i + k] - pref_sums[i] <= 0) {
                    ok = false;
                }
                // C++: if(i + 1 >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0) ok = false;
                if(i + 1 >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0) {
                    ok = false;
                }
            }
            
            if(ok && old_k == k) {
                out.println(k);
                out.flush();
                return;
            }
            if(!ok && old_k == k) {
                out.println(-1);
                out.flush();
                return;
            }
        }
    }
    
    // Helper class for Fast I/O
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
            if (s == null) return 0; // Should not happen based on problem constraints
            return Integer.parseInt(s);
        }
    }
}
```

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Random;

public class e_1358 {
    
    public static void main(String[] args) {
        // Fast I/O setup
        FastScanner scanner = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        // Read n
        int n = scanner.nextInt();
        
        // Read array arr
        // C++: int32_t* arr = new int32_t[n];
        int[] arr = new int[n];
        
        // C++: std::mt19937 rng; // Unused in logic, keeping declaration for fidelity
        Random rng = new Random();
        
        // Read first half
        for(int i = 0; i < (n + 1) / 2; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Read middle element
        int middleIdx = (n + 1) / 2;
        arr[middleIdx] = scanner.nextInt();
        
        // Read remaining elements (copying previous)
        // C++: for(int32_t i = (n + 1) / 2 + 1; i < n; i++) arr[i] = arr[i - 1];
        for(int i = middleIdx + 1; i < n; i++) {
            arr[i] = arr[i - 1];
        }
        
        // Calculate prefix sums
        // C++: int64_t* pref_sums = new int64_t[n + 1];
        long[] pref_sums = new long[n + 1];
        pref_sums[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            // C++: pref_sums[i] = pref_sums[i - 1] + arr[i - 1];
            pref_sums[i] = pref_sums[i - 1] + arr[i - 1];
        }
        
        // Search logic
        int k = 1;
        while(true) {
            int old_k = k;
            
            // Check if k can be increased
            // C++: for(int32_t i = 0; i < n; i++) { while(i < n - k && pref_sums[i + k] - pref_sums[i] <= 0) k++; ... }
            for(int i = 0; i < n; i++) {
                while(i < n - k && pref_sums[i + k] - pref_sums[i] <= 0) {
                    k++;
                }
                // Note: The inner while loop modifies k. This is a side effect that persists across iterations of the outer for loop.
                // In C++, this is valid. In Java, it works the same way.
                while(i >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0) {
                    k++;
                }
            }
            
            // Check validity
            // C++: bool ok = true;
            boolean ok = true;
            for(int i = 0; i < n; i++) {
                // C++: if(i <= n - k && pref_sums[i + k] - pref_sums[i] <= 0) ok = false;
                if(i <= n - k && pref_sums[i + k] - pref_sums[i] <= 0) {
                    ok = false;
                }
                // C++: if(i + 1 >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0) ok = false;
                if(i + 1 >= k && pref_sums[i + 1] - pref_sums[i + 1 - k] <= 0) {
                    ok = false;
                }
            }
            
            if(ok && old_k == k) {
                out.println(k);
                out.flush();
                return;
            }
            if(!ok && old_k == k) {
                out.println(-1);
                out.flush();
                return;
            }
        }
    }
    
    // Helper class for Fast I/O
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
            if (s == null) return 0; // Should not happen based on problem constraints
            return Integer.parseInt(s);
        }
    }
}
</CODE>