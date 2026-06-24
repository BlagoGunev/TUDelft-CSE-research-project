Translate this C++ code to Java code. The main class name should be c_1538. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  read(tt);
  while (tt--) {
    int n, l, r;
    read(n),read(l),read(r);
    vector<int> a(n);
    for (int i = 0; i < n; i++) read(a[i]);
    long long ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
      int L = -1, R = -1,ll = i + 1, rr = n - 1;
      while (ll <= rr) {
        int j = ll + rr >> 1;
        if (a[i] + a[j] >= l) 
          L = j,rr = j - 1;
         else ll = j + 1;      
      }
      ll = i + 1, rr = n - 1;
      while (ll <= rr) {
        int j = ll + rr >> 1;
        if (a[i] + a[j] <= r) {
          R = j,ll = j + 1;
        } else   rr = j - 1;
      }
      if (L != -1 && R != -1 && L <= R) ans += (R - L + 1);
      
    }
    print(ans,'\n');
  }
  return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Headers and Imports**:
    *   C++: `#include <bits/stdc++.h>`
    *   Java: `import java.util.*;` (to cover `Scanner`, `Arrays`, etc.)
    *   C++: `using namespace std;`
    *   Java: Not needed (Java is namespace agnostic).

2.  **Type Definitions**:
    *   C++: `typedef unsigned long long ull;`
    *   Java: No direct equivalent, but `long` is used for `ans` which is `long long` in C++. The `ull` typedef isn't strictly used in the logic (variables are `int` or `long long`), so we can ignore it or map it to `long` if needed, but the code uses `long long` for `ans`.
    *   C++: `typedef pair<int, int> pii;`
    *   Java: Java doesn't have a built-in `pair`. We will create a helper class `Pair` or simply use a `long` to store the pair (e.g., `((long)x << 32) | y`) if needed. However, looking at the code, `pii` is defined but **never used** in `main`. So, we can ignore this typedef.

3.  **Input Reading Logic (`read` function)**:
    *   C++: Custom fast I/O using `getchar()` and bitwise operations.
    *   Java: `Scanner` is slow. We should implement a custom `FastReader` class using `BufferedReader` and `StringTokenizer` to match the performance characteristics of the C++ code. The logic for parsing integers (handling signs) needs to be ported.

4.  **Output Logic (`print` function)**:
    *   C++: Custom fast output using `putchar`.
    *   Java: `System.out.println()` is generally fast enough when `System.out` is buffered or when using `PrintWriter`. Given the custom logic in C++, I will use `PrintWriter` for efficiency.

5.  **Main Logic**:
    *   `main` function: C++ `int main()` -> Java `public static void main(String[] args)`.
    *   `ios::sync_with_stdio(false); cin.tie(nullptr);`: This is C++ specific. In Java, the `BufferedReader` + `PrintWriter` approach implicitly handles this performance requirement.
    *   `vector<int> a(n)`: C++ `vector` -> Java `ArrayList` or `int[]`. Since the size is fixed `n`, `int[]` is more efficient.
    *   `sort(a.begin(), a.end())`: C++ `std::sort` -> Java `Arrays.sort()`.
    *   `print(ans, '\n')`: Java `pw.println(ans)`.
    *   **Binary Search**: The C++ code performs two binary searches.
        *   `ll + rr >> 1` is equivalent to `(ll + rr) / 2`.
        *   The logic for finding `L` and `R` based on `a[i] + a[j]` relative to `l` and `r` must be preserved.

6.  **Code Structure**:
    *   Class name: `c_1538`.
    *   Inner class for `FastReader` to encapsulate the input reading logic.

7.  **Incremental Tasks**:
    *   Task 1: Define the `FastReader` class.
    *   Task 2: Define the `main` class structure and the `solve` logic.
    *   Task 3: Implement the sorting and binary search loops.
    *   Task 4: Implement the output logic.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1538 {

    // FastReader class to replace C++ read() and handle fast I/O
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
            if (s == null) return 0; // Or throw exception
            return Integer.parseInt(s);
        }
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // Read number of test cases
        // In C++, read(tt) reads an integer. 
        // Note: C++ read() handles whitespace skipping. 
        // StringTokenizer handles whitespace skipping automatically.
        // We need to handle the case where input might be empty or malformed gracefully,
        // though competitive programming inputs are usually well-formed.
        String s = in.next();
        if (s == null) return;
        int tt = Integer.parseInt(s);

        while (tt-- > 0) {
            int n = in.nextInt();
            int l = in.nextInt();
            int r = in.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            // Sort the array
            Arrays.sort(a);

            long ans = 0;

            for (int i = 0; i < n - 1; i++) {
                int L = -1;
                int R = -1;

                // First Binary Search for L (lower bound)
                // Find first j > i such that a[i] + a[j] >= l
                // Range [i+1, n-1]
                int low = i + 1;
                int high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2; // Equivalent to (ll + rr) >> 1
                    if (a[i] + a[mid] >= l) {
                        L = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }

                // Second Binary Search for R (upper bound)
                // Find last j > i such that a[i] + a[j] <= r
                // Range [i+1, n-1]
                low = i + 1;
                high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[i] + a[mid] <= r) {
                        R = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                // Check validity
                if (L != -1 && R != -1 && L <= R) {
                    ans += (R - L + 1);
                }
            }

            out.println(ans);
        }
        out.flush();
    }
}
```

### Explanation of Translation

1.  **Input/Output**:
    *   The C++ code uses a custom `read` function with `getchar` and bitwise operations for fast I/O. In Java, `Scanner` is too slow for large inputs. I replaced this with a `FastReader` class using `BufferedReader` and `StringTokenizer`.
    *   The C++ `print` function manually writes characters. In Java, `PrintWriter` is used which buffers output efficiently.

2.  **Data Structures**:
    *   C++ `vector<int> a(n)` is translated to Java `int[] a = new int[n]`.
    *   C++ `sort(a.begin(), a.end())` is translated to Java `Arrays.sort(a)`.

3.  **Logic**:
    *   The C++ code iterates `i` from `0` to `n-2`. The loop condition `i < n - 1` is preserved.
    *   The C++ code uses `ll` and `rr` as bounds for binary search. In Java, I used `low` and `high`.
    *   The bitwise shift `ll + rr >> 1` in C++ corresponds to integer division `(low + high) / 2` in Java.
    *   The logic for finding the range `[L, R]` satisfying the sum constraints is preserved exactly.
    *   The `ull` typedef is unused in the logic (variables are `int` or `long long`), so it was omitted.

4.  **Class Structure**:
    *   The class is named `c_1538` as requested.
    *   The `main` method is `public static void main(String[] args)`.

5.  **Corner Cases**:
    *   The `read` function in C++ handles negative numbers via `fu`. The `FastReader` in Java parses strings directly, which handles signs correctly via `Integer.parseInt`.
    *   The C++ code initializes `L = -1, R = -1`. The check `if (L != -1 && R != -1 && L <= R)` ensures valid ranges are counted. This is preserved.

This translation maintains the time complexity $O(T \cdot N \log N)$ and space complexity $O(N)$ of the original C++ solution.

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1538 {

    // FastReader class to replace C++ read() and handle fast I/O
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
            if (s == null) return 0; // Or throw exception
            return Integer.parseInt(s);
        }
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // Read number of test cases
        // In C++, read(tt) reads an integer. 
        // Note: C++ read() handles whitespace skipping. 
        // StringTokenizer handles whitespace skipping automatically.
        // We need to handle the case where input might be empty or malformed gracefully,
        // though competitive programming inputs are usually well-formed.
        String s = in.next();
        if (s == null) return;
        int tt = Integer.parseInt(s);

        while (tt-- > 0) {
            int n = in.nextInt();
            int l = in.nextInt();
            int r = in.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            // Sort the array
            Arrays.sort(a);

            long ans = 0;

            for (int i = 0; i < n - 1; i++) {
                int L = -1;
                int R = -1;

                // First Binary Search for L (lower bound)
                // Find first j > i such that a[i] + a[j] >= l
                // Range [i+1, n-1]
                int low = i + 1;
                int high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2; // Equivalent to (ll + rr) >> 1
                    if (a[i] + a[mid] >= l) {
                        L = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }

                // Second Binary Search for R (upper bound)
                // Find last j > i such that a[i] + a[j] <= r
                // Range [i+1, n-1]
                low = i + 1;
                high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[i] + a[mid] <= r) {
                        R = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                // Check validity
                if (L != -1 && R != -1 && L <= R) {
                    ans += (R - L + 1);
                }
            }

            out.println(ans);
        }
        out.flush();
    }
}
</CODE>