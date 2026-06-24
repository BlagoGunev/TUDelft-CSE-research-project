Translate this C++ code to Java code. The main class name should be d_1606. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int T,n,m,mp[1000006],id[500005],ms[4][1000006];
char x[500006];
int main()
{
	scanf("%d",&T);
	bg:
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				scanf("%d",&mp[i*m+j]);
			id[i]=i;
		}
		sort(id,id+n,[](int a,int b){return mp[a*m]<mp[b*m];});
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				ms[0][i*m+j]=max(max(i     ?ms[0][(i-1)*m+j]:0         ,j     ?ms[0][i*m+j-1]:0         ),mp[id[i]*m+j]);
		for(int i=n-1;i>=0;i--)
			for(int j=0;j<m;j++)
				ms[1][i*m+j]=min(min(i!=n-1?ms[1][(i+1)*m+j]:0x3f3f3f3f,j     ?ms[1][i*m+j-1]:0x3f3f3f3f),mp[id[i]*m+j]);
		for(int i=0;i<n;i++)
			for(int j=m-1;j>=0;j--)
				ms[2][i*m+j]=min(min(i     ?ms[2][(i-1)*m+j]:0x3f3f3f3f,j!=m-1?ms[2][i*m+j+1]:0x3f3f3f3f),mp[id[i]*m+j]);
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--)
				ms[3][i*m+j]=max(max(i!=n-1?ms[3][(i+1)*m+j]:0         ,j!=m-1?ms[3][i*m+j+1]:0         ),mp[id[i]*m+j]);
		for(int i=0;i<n-1;i++)
			for(int j=0;j<m-1;j++)
				if(ms[0][i*m+j]<ms[1][(i+1)*m+j]&&ms[2][i*m+j+1]>ms[3][(i+1)*m+j+1])
				{
					printf("YES\n");
					for(int si=0;si<=i;si++)
						x[id[si]]='B';
					for(int si=i+1;si<n;si++)
						x[id[si]]='R';
					x[n]='\0';
					printf("%s %d\n",x,j+1);
					goto bg;
				}
		printf("NO\n");
	}
	return 0;
}

Here is the plan for the translation from C++ to Java:

1.  **Language Differences:**
    *   **I/O:** C++ uses `scanf` and `printf` from `<cstdio>`. Java uses `Scanner` or `BufferedReader` + `StringTokenizer` from `java.util` and `java.io` packages. Given the constraints (potential large I/O due to `n` up to 500,000), `BufferedReader` and `PrintWriter` are preferred for performance, but `Scanner` is easier to read. I will use `BufferedReader` and `PrintWriter` for robustness and speed.
    *   **Arrays:** C++ uses static arrays (`mp[1000006]`, etc.). Java requires dynamic arrays (arrays of objects or primitive types). Since Java arrays are objects, we need to instantiate `int[]` or `int[][]`. The C++ code uses a flattened 1D array `mp[i*m+j]` to represent a 2D grid. We should replicate this logic in Java or use a 2D array `int[n][m]`. The C++ code uses a 2D array `ms[4][1000006]` for the flattened grid. In Java, this translates to `int[][] ms` where `ms[k]` is a 1D array of size `n*m`.
    *   **Sorting:** C++ uses `std::sort` with a lambda function. Java uses `Arrays.sort` with a custom `Comparator`.
    *   **Pointers/Indices:** C++ uses `goto` for loops. Java does not support `goto` (structured programming). We must replace `goto bg` with a `while(true)` loop or a `while(T--)` loop containing a `break`.
    *   **Constants:** C++ uses `0x3f3f3f3f` for infinity. This is a large integer (approx $10^9$), which fits in a standard Java `int`.
    *   **Character Arrays:** C++ uses `char x[500006]`. Java uses `char[]` or `StringBuilder`.

2.  **Incremental Tasks:**
    *   **Setup:** Define class `d_1606`, add imports, setup `BufferedReader` and `PrintWriter`.
    *   **Data Structures:** Define `n`, `m`, `T`, `mp`, `id`, and `ms` (flattened arrays).
    *   **Input Loop:** Implement the reading of `T`, then the loop over test cases.
    *   **Grid Reading:** Implement reading `n` rows and `m` columns into `mp`.
    *   **Index Sorting:** Implement sorting `id` based on `mp`.
    *   **DP Calculation:** Implement the four loops calculating `ms[0]` to `ms[3]`.
    *   **Result Check:** Implement the nested loops checking the condition and printing the result.
    *   **Output Formatting:** Handle the string construction and printing.

3.  **Code Construction:**
    *   Replace `scanf` with `BufferedReader` parsing.
    *   Replace `printf` with `PrintWriter`.
    *   Replace `ms[4][1000006]` with `int[][] ms = new int[4][n*m]`. Note: The C++ code declares `ms` with a fixed size `1000006`. In Java, we must allocate based on `n*m`. Since `n` and `m` change per test case, we reallocate `ms` inside the test case loop.
    *   The sorting logic needs a `Comparator`.
    *   The `goto` logic needs to be converted to a `while` loop with a `break` statement.

4.  **Refinement:**
    *   Ensure `n` and `m` are handled correctly (Java arrays are 0-indexed, logic remains mostly the same).
    *   Ensure the flattened index calculation `i*m + j` is consistent.
    *   Handle the `0x3f3f3f3f` constant as `0x3f3f3f3f` in Java.

Here is the Java code:

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class d_1606 {
    static int T, n, m;
    static int[] mp;
    static int[] id;
    static int[][] ms;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        // Read T
        String line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            // Read n and m
            line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            if (line == null) break;
            st = new StringTokenizer(line);
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            // Allocate arrays based on n and m
            // mp is flattened 1D array of size n*m
            mp = new int[n * m];
            // id is 1D array of size n
            id = new int[n];
            // ms is 2D array where ms[k] is a flattened 1D array of size n*m
            ms = new int[4][n * m];

            // Read mp and initialize id
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    // Need to handle potential newlines between numbers if input format is loose
                    // Assuming standard competitive programming input where numbers are space separated
                    // or newlines are handled by StringTokenizer
                    // However, since we are using StringTokenizer, we need a helper or careful reading.
                    // The original code uses scanf which skips whitespace.
                    // We will implement a simple helper to get next token.
                    mp[i * m + j] = nextInt(br, st);
                }
            }
            
            // Re-initialize StringTokenizer if needed for next loop (though logic inside loop handles it)
            // Actually, the loop structure above consumes tokens. We need a robust way to get tokens.
            // Let's refactor the reading logic to be cleaner.
        }
    }
    
    // Helper to manage StringTokenizer
    static StringTokenizer st = new StringTokenizer("");
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    static int nextInt() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) return 0; // Should not happen based on T
            st = new StringTokenizer(s);
        }
        return Integer.parseInt(st.nextToken());
    }

    // Re-implementing main with the helper
    public static void main(String[] args) throws IOException {
        // Reset static members for safety in logic flow, though main is called once.
        // Wait, the structure above has two main methods. This is invalid.
        // Let's consolidate into one main method and use the helper logic correctly.
    }
}
```

*Self-Correction on Structure:* I cannot have two `main` methods. I need to write the complete class in one go. I will use a static `StringTokenizer` and `BufferedReader` pattern commonly used in Java competitive programming solutions.

*Detailed Logic Check:*
1.  **Input:** `scanf("%d%d",&n,&m)` -> `n = nextInt(); m = nextInt();`
2.  **Arrays:**
    *   `mp` -> `new int[n*m]`
    *   `id` -> `new int[n]`
    *   `ms` -> `new int[4][n*m]`
3.  **Initialization:**
    *   `id[i] = i`
    *   `sort(id, id+n, ...)` -> `Arrays.sort(id, 0, n, comparator)`
4.  **DP Loops:**
    *   `ms[0]` (Top-Left to Current): `i` goes `0` to `n-1`, `j` goes `0` to `m-1`.
    *   `ms[1]` (Bottom-Left to Current): `i` goes `n-1` to `0`, `j` goes `0` to `m-1`.
    *   `ms[2]` (Top-Right to Current): `i` goes `0` to `n-1`, `j` goes `m-1` to `0`.
    *   `ms[3]` (Bottom-Right to Current): `i` goes `n-1` to `0`, `j` goes `m-1` to `0`.
5.  **Check Condition:**
    *   `if (ms[0][idx] < ms[1][idx] && ms[2][idx] > ms[3][idx])` -> Print "YES", construct string, print "YES" + `j+1`, break.
6.  **End:** Print "NO".

*Note on Flattened Arrays:*
The C++ code uses `ms[0][i*m+j]`. In Java, `ms[0]` is an `int[]` of size `n*m`. Access is `ms[0][i*m+j]`.
The C++ code uses `ms[1][(i+1)*m+j]`. In Java, `ms[1][(i+1)*m+j]`.
This logic holds.

*Note on `0x3f3f3f3f`:* This is `1061109567`. Fits in `int`.

*Note on `x` array:* `char x[500006]`. In Java, `char[] x = new char[n+1]`. `x[n] = '\0'`. `String s = new String(x, 0, n)` is not quite right because `x[n]` is the null terminator. `x` should be filled up to `n`. `String.valueOf` or `new String(x, 0, n)` works.

*Refining Input Reading:*
The original code reads `T`, then loops `T` times. Inside, it reads `n, m`. Then it reads `n` lines (or just `n*m` integers). The `scanf` loop `for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&...)` reads `n*m` integers.
The Java code needs to read `n*m` integers.

Let's write the full code.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class d_1606 {
    static int T, n, m;
    static int[] mp;
    static int[] id;
    static int[][] ms;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    static int nextInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return 0;
            st = new StringTokenizer(line);
        }
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        T = nextInt();
        
        while (T-- > 0) {
            n = nextInt();
            m = nextInt();
            
            mp = new int[n * m];
            id = new int[n];
            ms = new int[4][n * m];

            // Read mp
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mp[i * m + j] = nextInt();
                }
                id[i] = i;
            }

            // Sort id based on mp values
            Arrays.sort(id, 0, n, (a, b) -> Integer.compare(mp[a * m], mp[b * m]));

            // Calculate ms[0]: Top-Left (inclusive)
            // ms[0][i*m+j] = max(max(i ? ms[0][(i-1)*m+j]:0, j ? ms[0][i*m+j-1]:0), mp[id[i]*m+j])
            // In Java, we use 0 as the base case for 0, similar to C++ logic where 0 is the identity for max
            // But wait, C++ code uses 0 for i=0 case.
            // If i=0, it takes 0. If j=0, it takes 0.
            // However, the logic is: max(0, 0, value) = value.
            // So we can just initialize the whole array to 0? No, because it accumulates.
            // We must simulate the conditional check.
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[0][(i - 1) * m + j] : 0;
                    int left = (j > 0) ? ms[0][i * m + j - 1] : 0;
                    ms[0][i * m + j] = Math.max(val, Math.max(up, left));
                }
            }

            // Calculate ms[1]: Bottom-Left (inclusive)
            // ms[1][i*m+j] = min(min(i!=n-1?ms[1][(i+1)*m+j]:INF, j?ms[1][i*m+j-1]:INF), mp[id[i]*m+j])
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[1][(i + 1) * m + j] : 0x3f3f3f3f;
                    int left = (j > 0) ? ms[1][i * m + j - 1] : 0x3f3f3f3f;
                    ms[1][i * m + j] = Math.min(val, Math.min(down, left));
                }
            }

            // Calculate ms[2]: Top-Right (inclusive)
            // ms[2][i*m+j] = min(min(i?ms[2][(i-1)*m+j]:INF, j!=m-1?ms[2][i*m+j+1]:INF), mp[id[i]*m+j])
            for (int i = 0; i < n; i++) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[2][(i - 1) * m + j] : 0x3f3f3f3f;
                    int right = (j < m - 1) ? ms[2][i * m + j + 1] : 0x3f3f3f3f;
                    ms[2][i * m + j] = Math.min(val, Math.min(up, right));
                }
            }

            // Calculate ms[3]: Bottom-Right (inclusive)
            // ms[3][i*m+j] = max(max(i!=n-1?ms[3][(i+1)*m+j]:0, j!=m-1?ms[3][i*m+j+1]:0), mp[id[i]*m+j])
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[3][(i + 1) * m + j] : 0;
                    int right = (j < m - 1) ? ms[3][i * m + j + 1] : 0;
                    ms[3][i * m + j] = Math.max(val, Math.max(down, right));
                }
            }

            boolean found = false;
            // Check condition
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) {
                    if (ms[0][i * m + j] < ms[1][(i + 1) * m + j] && ms[2][i * m + j + 1] > ms[3][(i + 1) * m + j + 1]) {
                        out.println("YES");
                        char[] x = new char[n];
                        for (int si = 0; si <= i; si++) {
                            x[id[si]] = 'B';
                        }
                        for (int si = i + 1; si < n; si++) {
                            x[id[si]] = 'R';
                        }
                        out.println(new String(x) + " " + (j + 1));
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) {
                out.println("NO");
            }
        }
        out.flush();
    }
}
```

Wait, I need to check the `ms` array indexing carefully.
In C++: `ms[0][i*m+j]`. `ms` is `int[4][1000006]`.
In Java: `ms` is `int[4][n*m]`.
Accessing `ms[k][index]` is correct.
The logic for `ms[0]` (Top-Left) is `max(max(up, left), val)`.
The logic for `ms[1]` (Bottom-Left) is `min(min(down, left), val)`.
The logic for `ms[2]` (Top-Right) is `min(min(up, right), val)`.
The logic for `ms[3]` (Bottom-Right) is `max(max(down, right), val)`.

Wait, there is a subtle issue in the C++ code regarding `ms` array declaration.
`int ms[4][1000006];`
In C++, `ms[0]` is an array of `1000006`.
In Java, `ms[0]` is an array of `n*m`.
Since `n` and `m` change per test case, and `n*m` can be up to `500000 * 500000` (which is huge) or `n+m` is limited?
Actually, looking at the problem context (likely Codeforces or similar), usually `n*m` is constrained.
However, `id` has size `500005`. `mp` has size `1000006`.
If `n=500000` and `m=2`, `n*m = 1000000`.
If `n=500000` and `m=500000`, `n*m` is `2.5e11`, which is impossible for an array.
The C++ code declares `mp[1000006]`. This implies `n*m` is bounded by `1000006`.
So `n*m` will not exceed `1000006`.
Therefore, `new int[n*m]` is safe in Java, assuming the input constraints respect the C++ static array size.
However, in Java, declaring `ms` as `new int[4][n*m]` inside the loop is safer than a static large array, as it handles variable sizes per test case.

One detail: `0x3f3f3f3f` in Java is `1061109567`.
In the C++ code: `min(..., 0x3f3f3f3f)`.
In Java: `Math.min(..., 0x3f3f3f3f)`.

Wait, there is a potential issue with `Arrays.sort` with a lambda in older Java versions (pre-8). But usually, standard environments support Java 8+. I will use Java 8+ syntax.

One more check on `ms` indices.
C++: `ms[1][(i+1)*m+j]`.
Java: `ms[1][(i+1)*m+j]`.
This is correct.

One detail on `id` sorting.
C++: `sort(id, id+n, [](int a,int b){return mp[a*m]<mp[b*m];});`
Java: `Arrays.sort(id, 0, n, (a, b) -> Integer.compare(mp[a*m], mp[b*m]));`
Wait, `mp` is `int[]`. `mp` is accessed via `id`.
In C++, `mp` is `int[1000006]`.
In Java, `mp` is `int[n*m]`.
Since `id` contains indices `0` to `n-1`, `id[a]` is an index into `mp`.
So `mp[id[a]*m]` is correct.

Wait, `mp` is flattened.
`mp[i*m + j]` corresponds to `grid[i][j]`.
`id[i]` stores the row index `i`.
So `mp[id[i]*m + j]` is `grid[id[i]][j]`.
This logic is correct.

Wait, the C++ code has `ms[4][1000006]`.
If `n` is large and `m` is large, `n*m` could exceed `1000006`.
However, if `n` is up to `500000`, then `m` must be small (e.g., `m <= 2`) for `n*m` to fit in `1000006`.
If `n` is small and `m` is large, `n*m` fits.
So the constraint `n*m <= 1000006` seems to be implicit.
Thus, allocating `new int[n*m]` is safe.

Wait, `ms` is `int[4][...]`.
In C++, `ms[0]` is `int[1000006]`.
In Java, `ms[0]` is `int[n*m]`.
This works.

One edge case: `n` or `m` being 0? The loops `for(int i=0;i<n;i++)` handle `n=0` gracefully (loops don't run).
But `mp` size `n*m` would be 0.
`Arrays.sort(id, 0, 0, ...)` works.
`ms` allocation `new int[4][0]` works.
The logic seems robust.

Final check on `StringTokenizer` usage.
The `nextInt` method needs to handle the case where `br.readLine()` returns null (EOF).
In the loop `while(T-- > 0)`, we expect valid input.
The `st` variable needs to be static or passed around.
I will make `st` static to avoid passing it around.

One small thing: `ms` array size.
In C++, `ms` is `int ms[4][1000006]`.
In Java, `ms` is `int[4][n*m]`.
This is fine.

Double check the `ms` loops.
`ms[0]`: `i` from `0` to `n-1`. `j` from `0` to `m-1`.
`ms[1]`: `i` from `n-1` to `0`. `j` from `0` to `m-1`.
`ms[2]`: `i` from `0` to `n-1`. `j` from `m-1` to `0`.
`ms[3]`: `i` from `n-1` to `0`. `j` from `m-1` to `0`.
This matches the C++ code exactly.

Wait, `ms[1]` logic: `i!=n-1 ? ms[1][(i+1)*m+j] : INF`.
If `i` is `n-1`, it uses `INF`.
Correct.

`ms[2]` logic: `i ? ms[2][(i-1)*m+j] : INF`.
If `i` is `0`, it uses `INF`.
Correct.

`ms[2]` logic: `j!=m-1 ? ms[2][i*m+j+1] : INF`.
If `j` is `m-1`, it uses `INF`.
Correct.

`ms[3]` logic: `i!=n-1 ? ms[3][(i+1)*m+j] : 0`.
If `i` is `n-1`, it uses `0`.
Correct.

`ms[3]` logic: `j!=m-1 ? ms[3][i*m+j+1] : 0`.
If `j` is `m-1`, it uses `0`.
Correct.

Looks good.

One detail: `0x3f3f3f3f` is `1061109567`.
In Java, `int` is signed 32-bit. Max value is `2147483647`.
`1061109567` fits in `int`.

I will write the code now.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class d_1606 {
    static int T, n, m;
    static int[] mp;
    static int[] id;
    static int[][] ms;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    static int nextInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return 0;
            st = new StringTokenizer(line);
        }
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        T = nextInt();
        
        while (T-- > 0) {
            n = nextInt();
            m = nextInt();
            
            // In C++, mp is static int[1000006]. 
            // In Java, we allocate based on n*m. 
            // We assume n*m fits in integer range and is reasonable (<= 10^6 as per C++ static size).
            mp = new int[n * m];
            id = new int[n];
            ms = new int[4][n * m];

            // Read mp
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mp[i * m + j] = nextInt();
                }
                id[i] = i;
            }

            // Sort id based on mp values
            // C++: sort(id, id+n, [](int a,int b){return mp[a*m]<mp[b*m];});
            // Java: Arrays.sort(id, 0, n, comparator)
            Arrays.sort(id, 0, n, (a, b) -> Integer.compare(mp[a * m], mp[b * m]));

            // Calculate ms[0]: Top-Left (inclusive)
            // C++: ms[0][i*m+j] = max(max(i ? ms[0][(i-1)*m+j]:0, j ? ms[0][i*m+j-1]:0), mp[id[i]*m+j]);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[0][(i - 1) * m + j] : 0;
                    int left = (j > 0) ? ms[0][i * m + j - 1] : 0;
                    ms[0][i * m + j] = Math.max(val, Math.max(up, left));
                }
            }

            // Calculate ms[1]: Bottom-Left (inclusive)
            // C++: ms[1][i*m+j] = min(min(i!=n-1?ms[1][(i+1)*m+j]:0x3f3f3f3f, j ? ms[1][i*m+j-1]:0x3f3f3f3f), mp[id[i]*m+j]);
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[1][(i + 1) * m + j] : 0x3f3f3f3f;
                    int left = (j > 0) ? ms[1][i * m + j - 1] : 0x3f3f3f3f;
                    ms[1][i * m + j] = Math.min(val, Math.min(down, left));
                }
            }

            // Calculate ms[2]: Top-Right (inclusive)
            // C++: ms[2][i*m+j] = min(min(i ? ms[2][(i-1)*m+j]:0x3f3f3f3f, j!=m-1?ms[2][i*m+j+1]:0x3f3f3f3f), mp[id[i]*m+j]);
            for (int i = 0; i < n; i++) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[2][(i - 1) * m + j] : 0x3f3f3f3f;
                    int right = (j < m - 1) ? ms[2][i * m + j + 1] : 0x3f3f3f3f;
                    ms[2][i * m + j] = Math.min(val, Math.min(up, right));
                }
            }

            // Calculate ms[3]: Bottom-Right (inclusive)
            // C++: ms[3][i*m+j] = max(max(i!=n-1?ms[3][(i+1)*m+j]:0, j!=m-1?ms[3][i*m+j+1]:0), mp[id[i]*m+j]);
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[3][(i + 1) * m + j] : 0;
                    int right = (j < m - 1) ? ms[3][i * m + j + 1] : 0;
                    ms[3][i * m + j] = Math.max(val, Math.max(down, right));
                }
            }

            boolean found = false;
            // Check condition
            // C++: for(int i=0;i<n-1;i++) for(int j=0;j<m-1;j++)
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) {
                    // ms[0][i*m+j] < ms[1][(i+1)*m+j] && ms[2][i*m+j+1] > ms[3][(i+1)*m+j+1]
                    if (ms[0][i * m + j] < ms[1][(i + 1) * m + j] && ms[2][i * m + j + 1] > ms[3][(i + 1) * m + j + 1]) {
                        out.println("YES");
                        char[] x = new char[n];
                        for (int si = 0; si <= i; si++) {
                            x[id[si]] = 'B';
                        }
                        for (int si = i + 1; si < n; si++) {
                            x[id[si]] = 'R';
                        }
                        out.println(new String(x) + " " + (j + 1));
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) {
                out.println("NO");
            }
        }
        out.flush();
    }
}
```

One final check: The C++ code uses `ms[0][(i-1)*m+j]`.
If `i=0`, it uses `0`.
In Java: `(i > 0) ? ms[0][(i - 1) * m + j] : 0`.
Correct.

The C++ code uses `ms[1][(i+1)*m+j]`.
If `i=n-1`, it uses `0x3f3f3f3f`.
In Java: `(i < n - 1) ? ms[1][(i + 1) * m + j] : 0x3f3f3f3f`.
Correct.

The C++ code uses `ms[2][(i-1)*m+j]`.
If `i=0`, it uses `0x3f3f3f3f`.
In Java: `(i > 0) ? ms[2][(i - 1) * m + j] : 0x3f3f3f3f`.
Correct.

The C++ code uses `ms[3][(i+1)*m+j]`.
If `i=n-1`, it uses `0`.
In Java: `(i < n - 1) ? ms[3][(i + 1) * m + j] : 0`.
Correct.

The C++ code uses `ms[0][i*m+j-1]`.
If `j=0`, it uses `0`.
In Java: `(j > 0) ? ms[0][i * m + j - 1] : 0`.
Correct.

The C++ code uses `ms[1][i*m+j-1]`.
If `j=0`, it uses `0x3f3f3f3f`.
In Java: `(j > 0) ? ms[1][i * m + j - 1] : 0x3f3f3f3f`.
Correct.

The C++ code uses `ms[2][i*m+j+1]`.
If `j=m-1`, it uses `0x3f3f3f3f`.
In Java: `(j < m - 1) ? ms[2][i * m + j + 1] : 0x3f3f3f3f`.
Correct.

The C++ code uses `ms[3][i*m+j+1]`.
If `j=m-1`, it uses `0`.
In Java: `(j < m - 1) ? ms[3][i * m + j + 1] : 0`.
Correct.

Everything seems consistent.

```java
<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class d_1606 {
    static int T, n, m;
    static int[] mp;
    static int[] id;
    static int[][] ms;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    static int nextInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return 0;
            st = new StringTokenizer(line);
        }
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        T = nextInt();
        
        while (T-- > 0) {
            n = nextInt();
            m = nextInt();
            
            mp = new int[n * m];
            id = new int[n];
            ms = new int[4][n * m];

            // Read mp
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mp[i * m + j] = nextInt();
                }
                id[i] = i;
            }

            // Sort id based on mp values
            Arrays.sort(id, 0, n, (a, b) -> Integer.compare(mp[a * m], mp[b * m]));

            // Calculate ms[0]: Top-Left (inclusive)
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[0][(i - 1) * m + j] : 0;
                    int left = (j > 0) ? ms[0][i * m + j - 1] : 0;
                    ms[0][i * m + j] = Math.max(val, Math.max(up, left));
                }
            }

            // Calculate ms[1]: Bottom-Left (inclusive)
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[1][(i + 1) * m + j] : 0x3f3f3f3f;
                    int left = (j > 0) ? ms[1][i * m + j - 1] : 0x3f3f3f3f;
                    ms[1][i * m + j] = Math.min(val, Math.min(down, left));
                }
            }

            // Calculate ms[2]: Top-Right (inclusive)
            for (int i = 0; i < n; i++) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[2][(i - 1) * m + j] : 0x3f3f3f3f;
                    int right = (j < m - 1) ? ms[2][i * m + j + 1] : 0x3f3f3f3f;
                    ms[2][i * m + j] = Math.min(val, Math.min(up, right));
                }
            }

            // Calculate ms[3]: Bottom-Right (inclusive)
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[3][(i + 1) * m + j] : 0;
                    int right = (j < m - 1) ? ms[3][i * m + j + 1] : 0;
                    ms[3][i * m + j] = Math.max(val, Math.max(down, right));
                }
            }

            boolean found = false;
            // Check condition
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) {
                    if (ms[0][i * m + j] < ms[1][(i + 1) * m + j] && ms[2][i * m + j + 1] > ms[3][(i + 1) * m + j + 1]) {
                        out.println("YES");
                        char[] x = new char[n];
                        for (int si = 0; si <= i; si++) {
                            x[id[si]] = 'B';
                        }
                        for (int si = i + 1; si < n; si++) {
                            x[id[si]] = 'R';
                        }
                        out.println(new String(x) + " " + (j + 1));
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) {
                out.println("NO");
            }
        }
        out.flush();
    }
}
</CODE>
```
</think>

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class d_1606 {
    static int T, n, m;
    static int[] mp;
    static int[] id;
    static int[][] ms;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);

    static int nextInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return 0;
            st = new StringTokenizer(line);
        }
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        T = nextInt();
        
        while (T-- > 0) {
            n = nextInt();
            m = nextInt();
            
            // In C++, mp is static int[1000006]. 
            // In Java, we allocate based on n*m. 
            // We assume n*m fits in integer range and is reasonable (<= 10^6 as per C++ static size).
            mp = new int[n * m];
            id = new int[n];
            ms = new int[4][n * m];

            // Read mp
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mp[i * m + j] = nextInt();
                }
                id[i] = i;
            }

            // Sort id based on mp values
            // C++: sort(id, id+n, [](int a,int b){return mp[a*m]<mp[b*m];});
            // Java: Arrays.sort(id, 0, n, comparator)
            Arrays.sort(id, 0, n, (a, b) -> Integer.compare(mp[a * m], mp[b * m]));

            // Calculate ms[0]: Top-Left (inclusive)
            // C++: ms[0][i*m+j] = max(max(i ? ms[0][(i-1)*m+j]:0, j ? ms[0][i*m+j-1]:0), mp[id[i]*m+j]);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[0][(i - 1) * m + j] : 0;
                    int left = (j > 0) ? ms[0][i * m + j - 1] : 0;
                    ms[0][i * m + j] = Math.max(val, Math.max(up, left));
                }
            }

            // Calculate ms[1]: Bottom-Left (inclusive)
            // C++: ms[1][i*m+j] = min(min(i!=n-1?ms[1][(i+1)*m+j]:0x3f3f3f3f, j ? ms[1][i*m+j-1]:0x3f3f3f3f), mp[id[i]*m+j]);
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[1][(i + 1) * m + j] : 0x3f3f3f3f;
                    int left = (j > 0) ? ms[1][i * m + j - 1] : 0x3f3f3f3f;
                    ms[1][i * m + j] = Math.min(val, Math.min(down, left));
                }
            }

            // Calculate ms[2]: Top-Right (inclusive)
            // C++: ms[2][i*m+j] = min(min(i ? ms[2][(i-1)*m+j]:0x3f3f3f3f, j!=m-1?ms[2][i*m+j+1]:0x3f3f3f3f), mp[id[i]*m+j]);
            for (int i = 0; i < n; i++) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int up = (i > 0) ? ms[2][(i - 1) * m + j] : 0x3f3f3f3f;
                    int right = (j < m - 1) ? ms[2][i * m + j + 1] : 0x3f3f3f3f;
                    ms[2][i * m + j] = Math.min(val, Math.min(up, right));
                }
            }

            // Calculate ms[3]: Bottom-Right (inclusive)
            // C++: ms[3][i*m+j] = max(max(i!=n-1?ms[3][(i+1)*m+j]:0, j!=m-1?ms[3][i*m+j+1]:0), mp[id[i]*m+j]);
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    int val = mp[id[i] * m + j];
                    int down = (i < n - 1) ? ms[3][(i + 1) * m + j] : 0;
                    int right = (j < m - 1) ? ms[3][i * m + j + 1] : 0;
                    ms[3][i * m + j] = Math.max(val, Math.max(down, right));
                }
            }

            boolean found = false;
            // Check condition
            // C++: for(int i=0;i<n-1;i++) for(int j=0;j<m-1;j++)
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) {
                    if (ms[0][i * m + j] < ms[1][(i + 1) * m + j] && ms[2][i * m + j + 1] > ms[3][(i + 1) * m + j + 1]) {
                        out.println("YES");
                        char[] x = new char[n];
                        for (int si = 0; si <= i; si++) {
                            x[id[si]] = 'B';
                        }
                        for (int si = i + 1; si < n; si++) {
                            x[id[si]] = 'R';
                        }
                        out.println(new String(x) + " " + (j + 1));
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) {
                out.println("NO");
            }
        }
        out.flush();
    }
}
</CODE>