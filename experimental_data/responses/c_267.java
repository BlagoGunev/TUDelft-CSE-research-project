Translate this C++ code to Java code. The main class name should be c_267. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n	105
#define m	5005
#define DB	double

int		N,M,x[m],y[m],w[m];
DB		F[n],A[n][n];

void	GTXY(){
		for	(int i=1,j;i<=N;i++){
			for	(j=i;j<=N&&!A[j][i];j++);
			if	(j>N)	continue;
			if	(j^i)	for	(int k=i;k<=N+1;k++)	swap(A[i][k],A[j][k]);

			for	(int j=i+1;j<=N;j++){
				DB	t=A[j][i]/A[i][i];
				for	(int k=i;k<=N+1;k++)	A[j][k]-=t*A[i][k];
			}
		}
		for	(int i=N;i;i--){
			for	(int j=i+1;j<=N;j++)	A[i][N+1]-=F[j]*A[i][j];
			if	(A[i][i])	F[i]=A[i][N+1]/A[i][i];
		}
}

int		main(){
		scanf("%d%d",&N,&M);
		for	(int i=1;i<=M;i++){
			scanf("%d%d%d",&x[i],&y[i],&w[i]);
			if	(x[i]!=1&&x[i]!=N)	A[x[i]][y[i]]--,A[x[i]][x[i]]++;
			if	(y[i]!=1&&y[i]!=N)	A[y[i]][x[i]]--,A[y[i]][y[i]]++;
		}	A[1][1]=A[N][N]=A[N][N+1]=1;	GTXY();

		DB	Min=1e16,Ans=0;
		for	(int i=1;i<=M;i++){
			DB	t=F[y[i]]-F[x[i]];
			Min=min(Min,abs(w[i]/t));
		}
		if	(Min>10000000.0)	Min=0;
		
		for	(int i=1;i<=M;i++)
			if	(x[i]==1||y[i]==1)	Ans+=F[y[i]*x[i]]*Min;
		printf("%.7lf\n",Ans);
		for	(int i=1;i<=M;i++)
			printf("%.7lf\n",(F[y[i]]-F[x[i]])*Min);
}

Here is the plan for the translation from C++ to Java.

### Translation Plan

1.  **Language Features Mapping**:
    *   **Headers**: `<cmath>` (Math), `<cstdio>` (IO), `<cstring>` (String - unused), `<algorithm>` (Algorithms) are replaced by Java standard library classes (`java.lang.Math`, `java.io.BufferedReader`, `java.io.InputStreamReader`, `java.util.StringTokenizer`).
    *   **`using namespace std`**: Removed. Namespaces are explicit in Java.
    *   **`#define`**: Preprocessor macros are replaced by `public static final` constants. `n` becomes `N`, `m` becomes `M`, `DB` becomes `double`.
    *   **Global Variables**: C++ globals are translated into `static` fields of the main class to maintain the same scope (though in Java, using static fields is the direct equivalent for global state).
    *   **`scanf`/`printf`**: Replaced by `BufferedReader` and `StringTokenizer` for input, and `PrintWriter` or `System.out.printf` for output. This is standard for competitive programming in Java to ensure fast I/O.
    *   **`swap`**: C++ `swap` is replaced by a helper method `swap(double a, double b)`.
    *   **`min`**: Replaced by `Math.min()`.
    *   **`abs`**: Replaced by `Math.abs()`.
    *   **`continue`/`break`**: Java `for` loops support these keywords directly.
    *   **`double`**: Used directly as `double`.
    *   **`^` operator**: In C++, `^` is XOR. In the code `if (j^i)`, since `i` and `j` are `int`, this is a bitwise XOR. However, looking at the logic `if (j^i)` inside the loop `for (int j=i;j<=N...`, `j` starts at `i`. The condition `j^i` will only be true if `j != i`. Since `j` starts at `i` and increments, `j != i` is the intended logic for swapping rows. In Java, `j^i` works for bitwise XOR, but usually, logical inequality `j != i` is clearer. However, to be faithful to the C++ source, I will keep the bitwise XOR operator `^` (which behaves as inequality for positive integers where bits don't overlap in a way that changes the sign, or simply because `j` starts at `i` so `j^i` is 0 if `j==i` and non-zero otherwise). Actually, `j` starts at `i`, so `j^i` is 0 when `j==i`. The loop continues until `!A[j][i]`. If `j==i`, `A[i][i]` is non-zero (diagonal), so `A[j][i]` is non-zero, so `!A[j][i]` is false, so `j` increments. So `j` will eventually become `> i`. Thus `j != i`. I will use `j != i` for clarity, or keep `j^i` if strict translation is preferred. Given the context of swapping rows, `j != i` is semantically identical and safer in Java. I will use `j != i` for clarity but `j^i` works too.
    *   **`min(Min, ...)`**: `Math.min`.
    *   **`printf`**: `System.out.printf`.
    *   **`main` function**: Converted to `public static void main(String[] args)`.
    *   **`GTXY` function**: Converted to a `static` method `GTXY`.
    *   **`abs`**: `Math.abs`.

2.  **Incremental Tasks**:
    *   **Task 1**: Define the class structure, constants, and static variables.
    *   **Task 2**: Implement the `GTXY` method (Gaussian Elimination).
    *   **Task 3**: Implement the `main` method with input parsing and logic execution.
    *   **Task 4**: Combine and finalize.

### Java Code

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Locale;

public class c_267 {
    // Constants
    private static final int N = 105;
    private static final int M = 5005;
    
    // Data structures
    // x[m], y[m], w[m] -> arrays of size M+1 to use 1-based indexing
    private static int[] x = new int[M + 1];
    private static int[] y = new int[M + 1];
    private static int[] w = new int[M + 1];
    
    // F[n] -> array of size N+1
    private static double[] F = new double[N + 1];
    // A[n][n] -> array of size (N+1)x(N+1) to handle 1-based indexing and the extra column (N+1)
    private static double[][] A = new double[N + 1][N + 1];

    // Helper to swap two doubles
    private static void swap(double a, double b) {
        double temp = a;
        a = b;
        b = temp;
    }

    // Gaussian Elimination
    private static void GTXY() {
        // Forward elimination
        for (int i = 1; i <= N; i++) {
            int j = i;
            while (j <= N && A[j][i] == 0) {
                j++;
            }
            if (j > N) {
                continue;
            }
            // Swap rows if j != i
            if (j != i) {
                for (int k = i; k <= N + 1; k++) {
                    swap(A[i][k], A[j][k]);
                }
            }

            // Eliminate below
            for (int j = i + 1; j <= N; j++) {
                double t = A[j][i] / A[i][i];
                for (int k = i; k <= N + 1; k++) {
                    A[j][k] -= t * A[i][k];
                }
            }
        }

        // Backward substitution
        for (int i = N; i >= 1; i--) {
            for (int j = i + 1; j <= N; j++) {
                A[i][N + 1] -= F[j] * A[i][j];
            }
            if (A[i][i] != 0) {
                F[i] = A[i][N + 1] / A[i][i];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        // Read N and M
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) {
            line = br.readLine();
        }
        if (line == null) return;
        
        st = new StringTokenizer(line);
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // Initialize arrays if necessary (Java initializes to 0/0.0, but good to be explicit if logic relies on it)
        // Arrays are already initialized to 0.0 and 0.

        // Read M lines
        for (int i = 1; i <= M; i++) {
            // Read next line if tokenizer is empty
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
            w[i] = Integer.parseInt(st.nextToken());

            if (x[i] != 1 && x[i] != N) {
                A[x[i]][y[i]]--;
                A[x[i]][x[i]]++;
            }
            if (y[i] != 1 && y[i] != N) {
                A[y[i]][x[i]]--;
                A[y[i]][y[i]]++;
            }
        }
        
        // Set boundary conditions
        A[1][1] = 1.0;
        A[N][N] = 1.0;
        A[N][N + 1] = 1.0;
        
        // Run Gaussian Elimination
        GTXY();

        double Min = 1e16;
        double Ans = 0.0;

        for (int i = 1; i <= M; i++) {
            double t = F[y[i]] - F[x[i]];
            // Avoid division by zero if t is 0, though problem constraints might prevent it or handle it.
            // Original code: min(Min, abs(w[i]/t));
            // If t is 0, abs(w[i]/t) is infinity.
            // Assuming valid t based on context or handled by logic.
            // In Java, we should handle potential division by zero if t is 0.
            // However, following the exact logic:
            if (t != 0) {
                Min = Math.min(Min, Math.abs(w[i] / t));
            }
        }
        
        if (Min > 10000000.0) {
            Min = 0.0;
        }

        for (int i = 1; i <= M; i++) {
            if (x[i] == 1 || y[i] == 1) {
                Ans += F[y[i] * x[i]] * Min; // Note: Original code: F[y[i]*x[i]] which is likely F[y[i]]*x[i] or typo?
                // Wait, original: F[y[i]*x[i]]. If y[i] and x[i] are ints, this is multiplication.
                // But F is indexed by 1..N. If y[i]*x[i] > N, it throws IndexOutOfBounds.
                // Let's look at the original C++ code: F[y[i]*x[i]].
                // In competitive programming, sometimes this is a typo for F[y[i]] * x[i] or similar.
                // However, strictly translating: F[y[i]*x[i]].
                // But wait, F is size N+1. If x[i], y[i] are ~N, product is ~N^2. Array out of bounds.
                // Let's re-read the C++ code carefully:
                // F[y[i]*x[i]]
                // If this is strictly C++, and C++ allows out of bounds (undefined behavior), Java throws exception.
                // BUT, usually in these problems (looks like a max flow or shortest path variant),
                // maybe it's F[y[i]] * x[i]?
                // Or maybe the original code meant F[y[i]] * x[i]?
                // Let's check the logic: F is potential values.
                // If I strictly translate, I must keep F[y[i]*x[i]].
                // However, if the C++ code is buggy, the Java code should reflect the logic.
                // BUT, looking at the context of "GTXY" (Gaussian), F is likely potentials.
                // If F is potentials, F[y[i]*x[i]] makes no sense dimensionally.
                // Is it possible the original code meant F[y[i]] * x[i]?
                // Or maybe F[y[i]] + F[x[i]]?
                // Let's assume the provided C++ code is correct and I should translate it literally.
                // However, if x[i] and y[i] are indices, F[y[i]*x[i]] is likely a typo in the source for F[y[i]]*x[i] or similar.
                // But wait, if x[i] is 1 or y[i] is 1 (checked in next loop), then y[i]*x[i] might be valid?
                // No, x[i] and y[i] are up to N. Product is up to N^2. F is size N+1.
                // If I translate literally, Java will crash.
                // Let's look closer at the C++ code:
                // F[y[i]*x[i]]
                // Is it possible it is F[y[i]] * x[i]?
                // If it is multiplication, it should be F[y[i]] * x[i].
                // Let's assume the user wants a functional Java program.
                // If the C++ code has a bug, the Java code should probably fix it or replicate the bug.
                // Given the prompt "Translate this C++ code", I should replicate the logic.
                // However, if the logic is nonsensical (array out of bounds), I should probably check if it's a typo.
                // Let's look at the second loop:
                // if (x[i]==1||y[i]==1) Ans+=F[y[i]*x[i]]*Min;
                // This looks like a specific condition.
                // If x[i]=1, y[i]*x[i] = y[i]. This is valid index.
                // If y[i]=1, x[i]*y[i] = x[i]. This is valid index.
                // So the condition `x[i]==1||y[i]==1` ensures the product is one of the indices (1 or the other node).
                // So `F[y[i]*x[i]]` is actually `F[y[i]]` if `x[i]==1` and `F[x[i]]` if `y[i]==1`.
                // So it is a valid index!
                // Example: x=1, y=5 -> 1*5 = 5. F[5]. Valid.
                // Example: x=5, y=1 -> 5*1 = 5. F[5]. Valid.
                // Example: x=2, y=3 -> 2*3 = 6. If N=5, F[6] is out of bounds.
                // But the loop `if (x[i]==1||y[i]==1)` prevents this case.
                // So the translation is safe.
                
                // Wait, operator precedence. F[y[i]*x[i]] vs F[y[i]]*x[i].
                // In C++, function call `F[...]` has higher precedence than `*`? No, `[]` has higher precedence than `*`.
                // So `F[y[i]*x[i]]` means `F[ (y[i]*x[i]) ]`.
                // So the logic holds: it accesses F at the product index.
                // Since the loop restricts to cases where one is 1, the product is the other index.
                // So F[y[i]*x[i]] is equivalent to F[y[i]] when x[i]==1, and F[x[i]] when y[i]==1.
                // So the code is valid.
                
                // However, in Java, array indices must be int.
                // y[i] and x[i] are int.
                // So F[y[i]*x[i]] is valid syntax.
                
                Ans += F[y[i] * x[i]] * Min;
            }
        }
        
        // Output Ans
        System.out.printf(Locale.US, "%.7lf\n", Ans);
        
        // Output distances
        for (int i = 1; i <= M; i++) {
            System.out.printf(Locale.US, "%.7lf\n", (F[y[i]] - F[x[i]]) * Min);
        }
    }
}
```

### Explanation of Changes
1.  **Class Structure**: Created `public class c_267` with `static` fields for arrays `x`, `y`, `w`, `F`, `A` to mimic C++ global variables.
2.  **Constants**: Replaced `#define` macros with `private static final int` and `double`.
3.  **I/O**: Replaced `scanf` and `printf` with `BufferedReader`, `StringTokenizer`, and `System.out.printf`. Added `Locale.US` to ensure `.` is used as the decimal separator (standard for competitive programming).
4.  **Logic**:
    *   **`GTXY`**: Translated the nested loops and matrix operations. Replaced C++ `swap` with a Java helper method.
    *   **`main`**: Translated `scanf` to token parsing. Replaced `min` with `Math.min`. Replaced `abs` with `Math.abs`.
    *   **Array Indexing**: Ensured arrays are sized `N+1` and `M+1` to accommodate 1-based indexing.
    *   **Math**: Used `Math.abs` and `Math.min`.
    *   **Specific Logic**: Kept the logic `F[y[i]*x[i]]` as is. Analyzed that due to the condition `x[i]==1||y[i]==1`, the index `y[i]*x[i]` will always be equal to either `y[i]` or `x[i]`, keeping it within the bounds of `F` (size `N+1`).
5.  **Formatting**: Added `Locale.US` to `printf` to ensure the output format matches standard C++ behavior (dot for decimal).

```java
<CODE>
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Locale;

public class c_267 {
    // Constants
    // n corresponds to 105, m to 5005
    private static final int N = 105;
    private static final int M = 5005;
    
    // Data structures
    // x[m], y[m], w[m] -> arrays of size M+1 to use 1-based indexing
    private static int[] x = new int[M + 1];
    private static int[] y = new int[M + 1];
    private static int[] w = new int[M + 1];
    
    // F[n] -> array of size N+1
    private static double[] F = new double[N + 1];
    // A[n][n] -> array of size (N+1)x(N+1) to handle 1-based indexing and the extra column (N+1)
    private static double[][] A = new double[N + 1][N + 1];

    // Helper to swap two doubles
    private static void swap(double a, double b) {
        double temp = a;
        a = b;
        b = temp;
    }

    // Gaussian Elimination
    private static void GTXY() {
        // Forward elimination
        for (int i = 1; i <= N; i++) {
            int j = i;
            // Find pivot row
            while (j <= N && A[j][i] == 0) {
                j++;
            }
            if (j > N) {
                continue;
            }
            // Swap rows if j != i
            if (j != i) {
                for (int k = i; k <= N + 1; k++) {
                    swap(A[i][k], A[j][k]);
                }
            }

            // Eliminate below
            for (int j = i + 1; j <= N; j++) {
                double t = A[j][i] / A[i][i];
                for (int k = i; k <= N + 1; k++) {
                    A[j][k] -= t * A[i][k];
                }
            }
        }

        // Backward substitution
        for (int i = N; i >= 1; i--) {
            for (int j = i + 1; j <= N; j++) {
                A[i][N + 1] -= F[j] * A[i][j];
            }
            if (A[i][i] != 0) {
                F[i] = A[i][N + 1] / A[i][i];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        // Read N and M
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) {
            line = br.readLine();
        }
        if (line == null) return;
        
        st = new StringTokenizer(line);
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        // Read M lines
        for (int i = 1; i <= M; i++) {
            // Read next line if tokenizer is empty
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
            w[i] = Integer.parseInt(st.nextToken());

            if (x[i] != 1 && x[i] != N) {
                A[x[i]][y[i]]--;
                A[x[i]][x[i]]++;
            }
            if (y[i] != 1 && y[i] != N) {
                A[y[i]][x[i]]--;
                A[y[i]][y[i]]++;
            }
        }
        
        // Set boundary conditions
        A[1][1] = 1.0;
        A[N][N] = 1.0;
        A[N][N + 1] = 1.0;
        
        // Run Gaussian Elimination
        GTXY();

        double Min = 1e16;
        double Ans = 0.0;

        for (int i = 1; i <= M; i++) {
            double t = F[y[i]] - F[x[i]];
            // Avoid division by zero if t is 0
            if (t != 0) {
                Min = Math.min(Min, Math.abs(w[i] / t));
            }
        }
        
        if (Min > 10000000.0) {
            Min = 0.0;
        }

        for (int i = 1; i <= M; i++) {
            if (x[i] == 1 || y[i] == 1) {
                // Logic from C++: F[y[i]*x[i]]
                // Since x[i] or y[i] is 1, the product is the other index.
                // Example: x=1, y=5 -> 1*5 = 5. F[5]. Valid.
                // Example: x=5, y=1 -> 5*1 = 5. F[5]. Valid.
                Ans += F[y[i] * x[i]] * Min;
            }
        }
        
        // Output Ans
        System.out.printf(Locale.US, "%.7f\n", Ans);
        
        // Output distances
        for (int i = 1; i <= M; i++) {
            System.out.printf(Locale.US, "%.7f\n", (F[y[i]] - F[x[i]]) * Min);
        }
    }
}
</CODE>
```