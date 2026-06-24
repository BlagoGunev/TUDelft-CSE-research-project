Translate this C++ code to Java code. The main class name should be a_251. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<cstdio>
#include<cstring>
#define rep(i,n) for (int i=0;i<n;i++)
int n,d,j,a[100005]; long long ans;
int main()
{
	scanf("%d%d",&n,&d);
	rep(i,n) scanf("%d",a+i);
	rep(i,n){
		if (j<i) j++;
		while (j<n && a[j]-a[i]<=d) j++;
		ans+=1LL*(j-i-1)*(j-i-2)/2;
		}
	printf("%I64d\n",ans);
	return 0;
}

<think>

</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several differences between the two languages:

1.  **Input/Output**:
    *   C++ uses `scanf` and `printf` from `<cstdio>`.
    *   Java uses `Scanner` (from `java.util`) for input and `System.out.println` for output.
    *   *Note*: `scanf` is generally faster than `Scanner`, but for competitive programming tasks of this magnitude (reading up to 100,000 integers), `Scanner` might be slightly slow. However, given the logic complexity is low (O(N^2) worst case due to the nested loops), standard `Scanner` is acceptable for typical time limits unless the constraints are extremely tight. If strict optimization were needed, `BufferedReader` and `StringTokenizer` would be used. Here, we stick to `Scanner` for clarity unless performance becomes a bottleneck, but given the array size `100005`, `Scanner` is usually acceptable for N=10^5 if the inner loop logic is efficient. Actually, looking at the logic, the inner `while` loop advances `j` monotonically. This is a sliding window approach, making the overall complexity O(N). Therefore, `Scanner` is perfectly fine.

2.  **Data Types**:
    *   C++ uses `long long` for `ans`.
    *   Java uses `long` (64-bit signed integer), which corresponds directly to C++'s `long long`.

3.  **Arrays**:
    *   C++ uses a static array `int a[100005]`.
    *   Java uses `int[]` or `ArrayList`. Since the size is known at compile time (roughly), an array of size `100005` is appropriate.

4.  **Macros**:
    *   The `#define rep(i,n)` macro is used for loops.
    *   In Java, this translates directly to a standard `for` loop: `for (int i = 0; i < n; i++)`.

5.  **Main Class Structure**:
    *   Java requires a class definition. The problem specifies the class name must be `a_251`.
    *   The `main` method must be `public static void main(String[] args)`.

6.  **Incremental Tasks**:
    *   Step 1: Define the class structure and imports.
    *   Step 2: Declare variables (`n`, `d`, `j`, `a`, `ans`) matching C++ types.
    *   Step 3: Implement input reading logic replacing `scanf`.
    *   Step 4: Implement the sliding window logic (replacing the `rep` macro).
    *   Step 5: Implement output logic replacing `printf`.

### Java Code

```java
import java.util.Scanner;

public class a_251 {
    // Global variables to match C++ scope
    int n, d, j;
    int[] a;
    long ans;

    public static void main(String[] args) {
        a_251 solver = new a_251();
        Scanner scanner = new Scanner(System.in);

        // Read n and d
        if (scanner.hasNextInt()) {
            solver.n = scanner.nextInt();
            solver.d = scanner.nextInt();

            // Initialize array with sufficient size (100005 as per C++)
            solver.a = new int[100005];
            solver.j = 0;
            solver.ans = 0;

            // Read array elements
            for (int i = 0; i < solver.n; i++) {
                solver.a[i] = scanner.nextInt();
            }

            // Process the sliding window logic
            for (int i = 0; i < solver.n; i++) {
                if (solver.j < i) {
                    solver.j++;
                }
                // Ensure j is at least i+1 to have a valid range, 
                // though the logic implies j starts before i and increments.
                // The condition a[j] - a[i] <= d checks the window constraint.
                // Since the array is sorted (implied by the logic a[j]-a[i]), 
                // we advance j while the condition holds.
                while (solver.j < solver.n && (long)solver.a[solver.j] - solver.a[i] <= solver.d) {
                    solver.j++;
                }
                
                // Calculate combinations: C(j - i - 1, 2)
                // In C++: 1LL * (j-i-1) * (j-i-2) / 2
                // In Java: use long arithmetic
                long count = solver.j - i - 1;
                if (count > 0) {
                    long ways = count * (count - 1) / 2;
                    solver.ans += ways;
                }
            }

            // Output result
            System.out.println(solver.ans);
        }
        
        scanner.close();
    }
}
```

<CODE>
import java.util.Scanner;

public class a_251 {
    int n, d, j;
    int[] a;
    long ans;

    public static void main(String[] args) {
        a_251 solver = new a_251();
        Scanner scanner = new Scanner(System.in);

        if (scanner.hasNextInt()) {
            solver.n = scanner.nextInt();
            solver.d = scanner.nextInt();

            solver.a = new int[100005];
            solver.j = 0;
            solver.ans = 0;

            for (int i = 0; i < solver.n; i++) {
                solver.a[i] = scanner.nextInt();
            }

            for (int i = 0; i < solver.n; i++) {
                if (solver.j < i) {
                    solver.j++;
                }
                while (solver.j < solver.n && (long)solver.a[solver.j] - solver.a[i] <= solver.d) {
                    solver.j++;
                }
                
                long count = solver.j - i - 1;
                if (count > 0) {
                    long ways = count * (count - 1) / 2;
                    solver.ans += ways;
                }
            }

            System.out.println(solver.ans);
        }
        
        scanner.close();
    }
}
</CODE>