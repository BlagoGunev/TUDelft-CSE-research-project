Translate this C++ code to Java code. The main class name should be a_243. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#define ldb long double
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define y1 y1HIT
#define x1 x1HUY
const ldb eps = 1e-9;
const int inf = 1 << 28;
const ldb pi = fabsl(atan2l(0.0, -1.0));
using namespace std;

int n, a[123123];
bool was[1 << 20];
int val[20];

void load()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 20; i++)
		val[i] = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		was[a[i]] = 1;
		for (int j = 0; j < 20; j++)
		{
			if (a[i] & (1 << j))
				val[j] = a[i];
			else
				val[j] |= a[i];
			was[val[j]] = 1;
		}
	}
	int res = 0;
	for (int i = 0; i < (1 << 20); i++)
		res += was[i];
	cout << res;
}

void solve()
{

}

#define problem "a"
int main()
{
	#ifndef ONLINE_JUDGE
	freopen(problem".in", "rt", stdin);
	freopen(problem"3.out", "wt", stdout);
	#endif
	load();
	solve();
	return 0;
}

Here is the plan for translating the provided C++ code to Java:

1.  **Namespace and Imports**:
    *   C++ uses `using namespace std;` and headers like `<iostream>`, `<vector>`, `<algorithm>`.
    *   Java requires explicit imports (e.g., `import java.util.*;`, `import java.io.*;`) and fully qualified class names (e.g., `System.out`, `Scanner`).
    *   The global variables in C++ (`n`, `a`, `was`, `val`) need to become static class members or local variables within the `load` method. Given the logic, they are effectively global state for the `load` function.

2.  **Data Types**:
    *   C++ `long double` (`ldb`) is mapped to Java `double`.
    *   C++ `long long` (`ll`) is mapped to Java `long`.
    *   C++ `int` is mapped to Java `int`.
    *   C++ `bool` is mapped to Java `boolean`.

3.  **Input/Output**:
    *   C++ `cin` and `cout` are replaced by Java `Scanner` and `System.out.println`.
    *   C++ `scanf` is replaced by `Scanner.nextInt()`.
    *   C++ `freopen` is replaced by opening files using `BufferedReader` and `PrintWriter` (or `Scanner`), though for competitive programming style, `Scanner` is usually sufficient unless performance is critical. I will use `Scanner` for simplicity and readability, or `BufferedReader` for speed if needed. Given the array size `123123` and bit manipulation, standard `Scanner` might be slow, but usually acceptable for small bitmasks. I will use `Scanner` for standard readability.

4.  **Macros and Constants**:
    *   `#define` macros like `pb`, `mp`, `ff`, `ss` are removed as Java doesn't support them.
    *   `#define ldb long double` becomes `double`.
    *   `const` variables become `final static` constants.
    *   `atan2l` becomes `Math.atan2`.

5.  **Bit Manipulation**:
    *   C++ bitwise operators (`&`, `|`, `<<`) work directly on integers. In Java, they work on `int` and `long`. Since `a[i]` is used as a bitmask up to 20 bits, `int` is sufficient.
    *   The array `a` is accessed via index. In C++, it's a global array. In Java, it's an instance variable or static array.

6.  **Class Structure**:
    *   The C++ `main` function becomes the `main` method of the `a_243` class.
    *   The C++ `load` function becomes a static method (since it uses global state) or an instance method if we move the variables to the class. Moving variables to static members makes the translation closer to the original structure where `load` accesses `a` and `was` directly.

7.  **Incremental Tasks**:
    *   Step 1: Set up the class structure and imports.
    *   Step 2: Translate constants and global variables.
    *   Step 3: Translate the `load` function logic (input reading, loop, bit manipulation, output).
    *   Step 4: Translate the `main` function to call `load`.

**Translation Details:**
*   `int n, a[123123];` -> `static int n; static int[] a;`
*   `bool was[1 << 20];` -> `static boolean[] was;` (Size $2^{20} \approx 1,000,000$).
*   `int val[20];` -> `static int[] val;`
*   `#define ldb long double` -> `final static double eps = 1e-9;`
*   `#define pi` -> `final static double pi = Math.atan2(0.0, -1.0);`
*   `cin >> n` -> `sc.nextInt()`
*   `scanf("%d", &a[i])` -> `sc.nextInt()` (and store in `a[i]`)
*   `cout << res` -> `System.out.println(res)`
*   `freopen` -> Removed (or commented out) as Java `Scanner` reads from `System.in`.

Here is the Java code:

```java
import java.util.Scanner;
import java.util.Arrays;

public class a_243 {
    // Translated global variables
    static int n;
    static int[] a;
    static boolean[] was;
    static int[] val;

    // Translated constants
    // ldb -> double
    final static double eps = 1e-9;
    final static int inf = 1 << 28;
    // pi -> Math.atan2
    final static double pi = Math.atan2(0.0, -1.0);

    // Load function translated to static method
    static void load() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        n = sc.nextInt();
        
        // Allocate array a with size n
        // Note: In C++, size is fixed at 123123. In Java, dynamic sizing is better.
        // However, to strictly follow C++ logic where array is pre-allocated:
        // We will allocate exactly n size or the max size if needed. 
        // Given the loop i < n, allocating n is sufficient.
        a = new int[n];
        
        // Read array a
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize val array
        val = new int[20];
        for (int i = 0; i < 20; i++) {
            val[i] = 0;
        }

        // Logic from C++:
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     was[a[i]] = 1;
        //     for (int j = 0; j < 20; j++)
        //     {
        //         if (a[i] & (1 << j))
        //             val[j] = a[i];
        //         else
        //             val[j] |= a[i];
        //         was[val[j]] = 1;
        //     }
        // }
        
        was = new boolean[1 << 20]; // Size 2^20 = 1048576

        for (int i = n - 1; i >= 0; i--) {
            was[a[i]] = true;
            for (int j = 0; j < 20; j++) {
                // Bitwise operations
                if ((a[i] & (1 << j)) != 0) {
                    val[j] = a[i];
                } else {
                    val[j] = val[j] | a[i];
                }
                was[val[j]] = true;
            }
        }
        
        int res = 0;
        // Iterate through was array
        // In C++, was was declared as bool[1<<20]. Java boolean array is 0 by default.
        for (int i = 0; i < (1 << 20); i++) {
            if (was[i]) {
                res++;
            }
        }
        System.out.println(res);
    }

    // solve function (empty in original)
    static void solve() {
        // Empty
    }

    public static void main(String[] args) {
        // Translated main logic
        // Removed freopen logic as it's not needed for standard input
        load();
        solve();
    }
}
```

<CODE>
import java.util.Scanner;
import java.util.Arrays;

public class a_243 {
    // Translated global variables
    static int n;
    static int[] a;
    static boolean[] was;
    static int[] val;

    // Translated constants
    // ldb -> double
    final static double eps = 1e-9;
    final static int inf = 1 << 28;
    // pi -> Math.atan2
    final static double pi = Math.atan2(0.0, -1.0);

    // Load function translated to static method
    static void load() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        n = sc.nextInt();
        
        // Allocate array a with size n
        a = new int[n];
        
        // Read array a
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize val array
        val = new int[20];
        for (int i = 0; i < 20; i++) {
            val[i] = 0;
        }

        // Logic from C++:
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     was[a[i]] = 1;
        //     for (int j = 0; j < 20; j++)
        //     {
        //         if (a[i] & (1 << j))
        //             val[j] = a[i];
        //         else
        //             val[j] |= a[i];
        //         was[val[j]] = 1;
        //     }
        // }
        
        was = new boolean[1 << 20]; // Size 2^20 = 1048576

        for (int i = n - 1; i >= 0; i--) {
            was[a[i]] = true;
            for (int j = 0; j < 20; j++) {
                // Bitwise operations
                if ((a[i] & (1 << j)) != 0) {
                    val[j] = a[i];
                } else {
                    val[j] = val[j] | a[i];
                }
                was[val[j]] = true;
            }
        }
        
        int res = 0;
        // Iterate through was array
        // In C++, was was declared as bool[1<<20]. Java boolean array is 0 by default.
        for (int i = 0; i < (1 << 20); i++) {
            if (was[i]) {
                res++;
            }
        }
        System.out.println(res);
    }

    // solve function (empty in original)
    static void solve() {
        // Empty
    }

    public static void main(String[] args) {
        // Translated main logic
        // Removed freopen logic as it's not needed for standard input
        load();
        solve();
    }
}
</CODE>

```java
import java.util.Scanner;
import java.util.Arrays;

public class a_243 {
    // Translated global variables
    static int n;
    static int[] a;
    static boolean[] was;
    static int[] val;

    // Translated constants
    // ldb -> double
    final static double eps = 1e-9;
    final static int inf = 1 << 28;
    // pi -> Math.atan2
    final static double pi = Math.atan2(0.0, -1.0);

    // Load function translated to static method
    static void load() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        n = sc.nextInt();
        
        // Allocate array a with size n
        a = new int[n];
        
        // Read array a
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize val array
        val = new int[20];
        for (int i = 0; i < 20; i++) {
            val[i] = 0;
        }

        // Logic from C++:
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     was[a[i]] = 1;
        //     for (int j = 0; j < 20; j++)
        //     {
        //         if (a[i] & (1 << j))
        //             val[j] = a[i];
        //         else
        //             val[j] |= a[i];
        //         was[val[j]] = 1;
        //     }
        // }
        
        was = new boolean[1 << 20]; // Size 2^20 = 1048576

        for (int i = n - 1; i >= 0; i--) {
            was[a[i]] = true;
            for (int j = 0; j < 20; j++) {
                // Bitwise operations
                if ((a[i] & (1 << j)) != 0) {
                    val[j] = a[i];
                } else {
                    val[j] = val[j] | a[i];
                }
                was[val[j]] = true;
            }
        }
        
        int res = 0;
        // Iterate through was array
        // In C++, was was declared as bool[1<<20]. Java boolean array is 0 by default.
        for (int i = 0; i < (1 << 20); i++) {
            if (was[i]) {
                res++;
            }
        }
        System.out.println(res);
    }

    // solve function (empty in original)
    static void solve() {
        // Empty
    }

    public static void main(String[] args) {
        // Translated main logic
        // Removed freopen logic as it's not needed for standard input
        load();
        solve();
    }
}
```