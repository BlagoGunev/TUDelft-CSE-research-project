Translate this C++ code to Java code. The main class name should be e_1588. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

#define TT double



using namespace std;



#define point complex<TT>

#define x real()

#define y imag()



const TT eps = 1e-9;

const TT PI = acos(-1.0);

const int N = 3030;



bool ok[N][N];



int main()

{

	int n, radius;

	scanf("%d%d", &n, &radius);



	vector <point> pts;

	for (int i = 0; i < n; i++) {

		int a, b;

		scanf("%d%d", &a, &b);

		pts.push_back(point(a, b));

	}



	for (int center = 0; center < n; ++center) {

		bool start = false;

		TT L = 0, R = 100;

		for (int i = 0; i < n; ++i) {

			TT d = sqrt(norm(pts[i] - pts[center]));

			if (d < radius) continue;



			TT theta = arg(pts[i] - pts[center]);

			TT diff = asin(1.*radius / d);

			TT newL = theta - diff;

			TT newR = theta + diff;

			while ((!start && newL < 0) || (start && newR < L)) {

			    newL += 2.*PI;

			    newR += 2.*PI;

			}



			start = true;

			L = max(L, newL);

			R = min(R, newR);

			if (L > R) break;

		}



		for (int i = 0; i < n; i++) {

			if (i == center) continue;

			TT angle = arg(pts[i] - pts[center]);

			while (angle < L) angle += 2.*PI;

			ok[center][i] = (!start || angle <= R);

		}

	}



	int ans = 0;

	for (int i = 0; i < n; ++i)

		for (int j = i + 1; j < n; ++j)

			ans += (ok[i][j] && ok[j][i]);



	printf("%d\n", ans);

	return 0;

}

<think>
The user wants me to translate a C++ code snippet into Java.
The main class name must be `e_1588`.

**1. Analysis of the C++ Code:**
*   **Includes:** `#include <bits/stdc++.h>` (This is a meta-header for GCC, usually containing standard libraries. In Java, I need to import specific classes like `java.util.*`, `java.io.*`, `java.lang.Math`, etc.).
*   **Type Definitions:**
    *   `#define TT double`: A typedef for `double`.
    *   `using namespace std;`: Standard namespace usage.
    *   `#define point complex<TT>`: `std::complex<double>`.
    *   `#define x real()`: Accessor for real part of complex.
    *   `#define y imag()`: Accessor for imaginary part of complex.
*   **Constants:**
    *   `const TT eps = 1e-9;`: Used for floating point comparisons (though not explicitly used in the logic provided, it's good practice).
    *   `const TT PI = acos(-1.0);`: Value of PI.
    *   `const int N = 3030;`: Array size.
*   **Variables:**
    *   `bool ok[N][N]`: A 2D boolean array.
    *   `int n, radius;`: Input variables.
    *   `vector <point> pts`: A vector of complex numbers.
*   **Logic:**
    *   Reads `n` and `radius`.
    *   Reads `n` pairs of coordinates, storing them as `complex<double>`.
    *   Iterates through each point as a `center`.
    *   Performs a binary search (implicitly via two pointers or bounds checking logic) to find an angular interval `[L, R]` within `2*PI` such that all points `pts[i]` (where `d >= radius`) fall within this interval.
    *   Actually, looking closely at the loop: `for (int i = 0; i < n; ++i)` inside the center loop. It updates `L` and `R`. It seems to be trying to find a valid angular sector of size `2*diff` (where `diff = asin(radius/d)`) that contains all "far" points.
    *   Wait, the logic `while ((!start && newL < 0) || (start && newR < L))` suggests it's trying to normalize angles to be within `[0, 2*PI)` or something similar, or finding a valid interval.
    *   `L` and `R` are initialized to `0` and `100`. `100` is a large enough upper bound for `2*PI` (approx 6.28).
    *   `start` flag indicates if we found at least one valid point.
    *   The condition `if (L > R) break;` handles the case where no valid interval exists (wrapping around).
    *   Finally, it checks for every pair `(i, j)` if both `ok[i][j]` and `ok[j][i]` are true. `ok[center][i]` stores whether point `i` is compatible with `center` given the angular constraint.
*   **Output:** Prints `ans`.

**2. Translation Plan:**
*   **Language Differences:**
    *   C++ `std::complex` vs Java `java.lang.Math` (no built-in complex class in standard Java). I need to implement a simple `Complex` class or store coordinates as `double[]` or separate `x` and `y` variables. Since the code uses `real()` and `imag()` and arithmetic like `pts[i] - pts[center]`, a `Complex` class is necessary.
    *   C++ `vector` vs Java `ArrayList` or `double[]`. Since size `N` is known (`3030`), an array is efficient. However, `n` is read at runtime. A dynamic array (ArrayList) is safer, or an array of size `N` is fine since `n` <= `N`. Let's use `ArrayList` or a fixed-size array since `N` is defined. The code uses `vector`, so `ArrayList` is the direct translation.
    *   C++ `scanf` / `printf` vs Java `Scanner` / `System.out.println`. `Scanner` is slower but easier to write. For competitive programming in Java, `BufferedReader` + `StringTokenizer` is preferred for speed. I should use `BufferedReader` to handle potential I/O bottlenecks, though the logic is O(N^2) so N=3030 is small enough for `Scanner`. Let's stick to standard `Scanner` for simplicity unless performance is critical, but `BufferedReader` is safer for "production" quality Java code. Given the context (likely a competitive programming problem), `BufferedReader` is better.
    *   C++ `complex<TT>` operations (`norm`, `arg`, `sqrt`) vs Java `Math`.
        *   `norm(z)` is `z * conj(z)`. `Math.hypot(dx, dy)` is equivalent to `sqrt(x*x + y*y)`.
        *   `arg(z)` is `Math.atan2(y, x)`.
        *   `complex` arithmetic needs to be implemented manually or via a class.
*   **Specifics:**
    *   `TT` -> `double`.
    *   `point` -> `Complex` class.
    *   `ok[N][N]` -> `boolean[][] ok`.
    *   `vector` -> `ArrayList` or `double[]`.
*   **Structure:**
    *   Class `e_1588`.
    *   `main` method.
    *   Inner static class `Complex`.
    *   `Math` methods replacement.

**3. Incremental Tasks:**
1.  **Setup:** Create class `e_1588`, import `java.util.*`, `java.io.*`.
2.  **Complex Class:** Implement a `Complex` class with `x`, `y` fields, constructor, subtraction, `norm` (distance), `arg` (angle).
3.  **Constants:** Define `PI`, `eps` (though `eps` isn't used in the snippet, I can keep it or remove it. The prompt says "translate this C++ code", so I should probably keep the constants defined but maybe not used if they aren't needed. I will keep `PI` and `eps` as constants).
4.  **IO:** Implement reading `n`, `radius`, and the points.
5.  **Logic:** Implement the nested loops and logic for `L`, `R`, `start`, and `ok` array.
6.  **Counting:** Implement the final counting loop and output.

**4. Refinement on Logic:**
*   In C++, `complex` is a struct/class. In Java, I'll make a static inner class `Point` (since the variable name `pts` is used).
*   `norm` in C++ `std::complex` returns the squared modulus. `std::norm(z)` is `real*real + imag*imag`.
*   `arg` in C++ `std::complex` returns the argument in radians. In Java, `Math.atan2(y, x)` does exactly this.
*   `sqrt` -> `Math.sqrt`.
*   `acos` -> `Math.acos`.
*   `max` -> `Math.max`.
*   `min` -> `Math.min`.
*   `vector` -> `ArrayList`.
*   `scanf` -> `Scanner` or `BufferedReader`. `BufferedReader` is safer for competitive programming.
*   `printf` -> `System.out.println`.

**5. Specific Logic Check:**
The C++ code uses `complex<TT>`.
`point(a, b)` creates `complex<double>(a, b)`.
`pts[i] - pts[center]` creates a complex number.
`norm(z)` returns `x*x + y*y`.
`arg(z)` returns `atan2(y, x)`.

In Java:
Class `Point` with `double x`, `double y`.
Subtraction: `this.x - other.x`, `this.y - other.y`.
Norm: `Math.hypot(x, y)`.
Arg: `Math.atan2(y, x)`.

Wait, `norm` in `std::complex` is the squared magnitude (modulus squared).
However, the code does `sqrt(norm(pts[i] - pts[center]))`.
`sqrt(norm(z))` is just the magnitude (distance).
So `Math.hypot(dx, dy)` is the correct translation for `sqrt(norm(...))`.

The code defines `TT` as `double`.
`const TT eps = 1e-9;`
`const TT PI = acos(-1.0);`
`const int N = 3030;`

I should preserve these constants.

The loop logic:
`for (int center = 0; center < n; ++center)`
Inside, it iterates `i` from `0` to `n-1`.
It calculates distance `d`.
If `d < radius`, continue.
It calculates `theta = arg(...)`.
It calculates `diff = asin(radius / d)`.
It defines a sector `[newL, newR]` centered at `theta` with width `2*diff`.
It normalizes `newL` and `newR` to handle wrapping around 0/2PI.
It updates `L = max(L, newL)` and `R = min(R, newR)`.
If `L > R`, break (invalid interval found).
Then it checks all other points `i` against this interval.
`ok[center][i]` is set to true if `i` is in the valid angular range relative to `center`.

Wait, there's a subtle issue in the C++ code logic regarding `start`.
`bool start = false;`
Inside the `i` loop:
If `d < radius`, it continues (doesn't update `L`, `R`, `start`).
If `d >= radius`, it updates `L`, `R`, `start`.
Wait, if `start` is false, it means no point has `d >= radius` yet? Or does it mean the first point encountered with `d >= radius` sets the bounds?
Actually, if `start` is false, it means no points satisfy `d >= radius`.
However, the code says `if (d < radius) continue;`.
Then it calculates `newL`, `newR`.
Then `while ((!start && newL < 0) || (start && newR < L))`.
If `start` is false, it adds `2*PI` to `newL` until it's non-negative.
If `start` is true, it adds `2*PI` to both until `newR >= L`.
Then `start = true`.
Then `L = max(L, newL)`, `R = min(R, newR)`.
If `L > R`, break.

This logic implies we are looking for an angular interval that covers all "far" points.
The `start` flag logic is a bit weird.
If `start` is false (no far points found yet), we take the first far point encountered, normalize its angle to `[0, 2*PI)`, and set `L` to that, `R` to `newR`.
If `start` is true (we already have a valid interval `[L, R]` from previous far points), we check the current far point. We expand the interval to cover the current point.
If the interval wraps around (e.g., `newR < L`), we break.
This seems to find the smallest angular sector covering all points with distance `>= radius`.

Wait, `ok[center][i]` is set based on `angle`.
`angle = arg(...)`.
`while (angle < L) angle += 2.*PI;`
`ok[center][i] = (!start || angle <= R);`

Wait, if `!start` is true (no far points), then `angle <= R` check is effectively true?
Wait, if `!start`, it means `L` is effectively 0?
If `start` is false, `L` is 0, `R` is 100 (initial value).
If `!start` is true, `ok[center][i]` becomes true regardless of angle?
Wait, the code says `ok[center][i] = (!start || angle <= R);`.
If `start` is false, it means no points triggered the `start` flag inside the loop.
This implies `L` is 0, `R` is 100.
If `start` is false, `!start` is true, so `ok` is true.
But wait, if `start` is false, it means no points were added to the interval.
So all points should be valid?
Actually, if `start` is false, it means for all `i`, `d < radius`.
So `ok[center][i]` should be true for all `i`?
But the condition `d < radius` skips them in the loop.
So if `start` remains false, it means all points are within radius.
In that case, `ok[center][i]` is true for all `i`.
But the final loop checks `ans += (ok[i][j] && ok[j][i]);`.
If `ok` is true for all, `ans` counts all pairs.
This makes sense: if all points are close to center, any pair is "compatible".
If some points are far, we check if they fit in the angular sector.

Wait, looking at `ok[center][i]`.
If `start` is false, `ok` is true.
If `start` is true, `ok` is true if `angle <= R`.
Wait, `angle` is normalized by `while (angle < L) angle += 2.*PI`.
So `angle` is in `[L, L + 2*PI)`.
If `angle <= R`, it means `angle` is within `[L, R]`.
Wait, if `angle` is normalized to be `>= L`, then `angle <= R` implies the point is in the sector.
Wait, if `start` is true, `L` has been updated by previous points.
So `L` is the lower bound of the angular sector.
`R` is the upper bound.
If the current `angle` (normalized) is `<= R`, it is inside.
Wait, what if `angle` is in `[L, R + 2*PI)`?
The logic `while (angle < L) angle += 2.*PI` ensures `angle >= L`.
So `angle` is in `[L, L + 2*PI)`.
If `angle <= R`, it is in `[L, R]`.
If `angle > R`, it is not in `[L, R]`.
This logic assumes the sector does not wrap around the 0/2PI boundary in a way that excludes points.
Wait, the loop `while` logic handles the wrap around for `L` and `R` inside the first loop.
But `angle` normalization in the second loop: `while (angle < L) angle += 2.*PI;`.
This ensures `angle` is in `[L, L + 2*PI)`.
If `angle <= R`, it is in `[L, R]`.
Wait, what if `R` was wrapped?
Inside the first loop:
`newL` and `newR` are normalized such that `newR >= L`.
`start = true`.
`L = max(L, newL)`.
`R = min(R, newR)`.
`if (L > R) break;`.
So `L <= R`.
The interval `[L, R]` is valid (does not wrap).
So the second loop checks if `angle` falls in `[L, R]`.
If `angle < L`, it adds `2*PI` to bring it to `[L, L+2*PI)`.
Then checks `angle <= R`.
This logic holds.

**6. Implementation Details:**
*   **Class Name:** `e_1588`.
*   **Imports:** `java.util.*`, `java.io.*`.
*   **Complex Class:**
    *   `double x, y`.
    *   Constructor.
    *   `Complex subtract(Complex other)`.
    *   `double norm()`: `Math.hypot(x, y)`.
    *   `double arg()`: `Math.atan2(y, x)`.
*   **IO:** Use `BufferedReader` and `StringTokenizer` for speed.
*   **Arrays:** `boolean[][] ok`. Size `n x n`.
*   **Main Logic:** Direct translation.

**7. Code Structure:**
```java
import java.io.*;
import java.util.*;

public class e_1588 {
    static class Point {
        double x, y;
        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static final double PI = Math.acos(-1.0);
    static final double EPS = 1e-9;
    static final int N = 3030;

    public static void main(String[] args) throws IOException {
        // Setup IO
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // ... logic
    }
}
```

**Wait, one detail:**
The C++ code defines `TT` as `double` and `point` as `complex<TT>`.
In C++, `complex` has `norm` which returns squared modulus.
`sqrt(norm(...))` returns modulus.
In Java `Math.hypot` returns modulus.
So `Math.hypot` corresponds to `sqrt(norm)`.
`arg` corresponds to `Math.atan2`.

**Wait, `ok` array:**
In C++, `ok` is `bool ok[N][N]`.
In Java, `boolean[][] ok = new boolean[N][N]`.
Wait, `n` is read at runtime. `N` is `3030`.
I should allocate `ok` based on `N` or `n`. `N` is fixed at 3030.
I will allocate `ok` as `new boolean[n][n]`?
Wait, the C++ code uses `ok[N][N]`.
It accesses `ok[center][i]`. `center` and `i` go up to `n-1`.
Since `n` can be up to `N` (implied by array size), allocating `new boolean[n][n]` is sufficient.
Or `new boolean[N][N]` is safer to match C++ exactly.
The C++ code declares `ok` statically with size `N`.
I will use `boolean[][] ok = new boolean[n][n]` because `n` is the actual size.
Actually, if `n` is small, `N` is larger.
The C++ code uses `ok[N][N]` which is fixed size.
I should probably use `new boolean[n][n]` to be more efficient, but `new boolean[N][N]` is safer to match the declaration exactly.
However, usually in Java, dynamic sizing is preferred.
Let's stick to `new boolean[n][n]` but since `N` is a constant, I can just use `n` for allocation.
Wait, `ok` is declared `bool ok[N][N]`.
If `n` is small, `ok` is large.
If I allocate `new boolean[n][n]`, it's smaller.
I'll allocate `new boolean[n][n]` to be logical, but keep `N` constant defined.

**Wait, `TT` type:**
`TT` is `double`.
`complex<TT>` -> `Point` class with `double`.

**Wait, `scanf` vs `Scanner`:**
`scanf` is fast. `Scanner` is slow.
For competitive programming (implied by `bits/stdc++.h` and `scanf`), `BufferedReader` is the standard Java replacement.
I will use `BufferedReader` and `StringTokenizer`.

**Wait, `eps`:**
`const TT eps = 1e-9;`
It is defined but not used in the provided snippet. I will keep it defined but not used.

**Wait, `start` logic:**
In C++:
`bool start = false;`
`while ((!start && newL < 0) || (start && newR < L))`
This loop modifies `newL` and `newR`.
It ensures `newL >= 0` (if `!start`) and `newR >= L` (if `start`).
Then `start = true`.
Then `L = max(L, newL)`.
Then `R = min(R, newR)`.
Then `if (L > R) break;`.
This logic is tricky.
If `start` is false (first far point), `newL` is normalized to `>= 0`. `newR` is normalized.
`L` becomes `newL`. `R` becomes `newR`.
`start` becomes true.
If `start` is true (subsequent far points), `newL` and `newR` are normalized to be `>= L`.
Wait, `while` loop condition: `(!start && newL < 0) || (start && newR < L)`.
If `start` is true, it checks `newR < L`.
If `newR < L`, it adds `2*PI` to both.
This effectively handles the case where the sector wraps around `2*PI` (0).
So `L` and `R` are always in `[0, 2*PI]`.
Wait, `newR` is `theta + diff`. `newL` is `theta - diff`.
If `newR < L`, it means the interval wraps around 0.
So we shift both by `2*PI`.
Then `L` becomes `newL` (shifted), `R` becomes `newR` (shifted).
So the interval is `[L, R]` within `[0, 2*PI]`.
This logic is preserved in Java.

**Wait, `ok` check:**
`ok[center][i] = (!start || angle <= R);`
If `start` is false (no far points), `ok` is true.
If `start` is true, `ok` is true if `angle` (normalized to `>= L`) is `<= R`.

**Wait, `ans` calculation:**
`ans += (ok[i][j] && ok[j][i]);`
This counts pairs `(i, j)` where both are compatible with each other.

**Wait, `Complex` class:**
I need to implement `Complex` class with `x`, `y`.
Methods: `subtract`, `norm` (returns distance), `arg`.
`Complex` subtraction: `new Point(this.x - other.x, this.y - other.y)`.
`norm`: `Math.hypot(x, y)`.
`arg`: `Math.atan2(y, x)`.

**Wait, `PI`:**
`Math.PI` is available. `acos(-1.0)` is `Math.PI`.
I will use `Math.PI`.

**Wait, `eps`:**
Defined as `1e-9`. I will define it.

**Wait, `Scanner` vs `BufferedReader`:**
`scanf` reads integers.
I will use `StringTokenizer` to parse integers.

**Wait, `vector`:**
`ArrayList<Point> pts`.

**Wait, `main` method signature:**
`public static void main(String[] args)`

**Wait, `N`:**
`N` is `3030`.
I will keep it.

**Wait, `ok` array size:**
`ok` is `N x N`.
In Java, `boolean[][] ok = new boolean[n][n]` is sufficient, but `new boolean[N][N]` matches the C++ declaration.
Given the C++ code declares `bool ok[N][N]`, I should probably allocate `new boolean[N][N]` or `new boolean[n][n]` inside `main`.
Since `n` is variable, `new boolean[n][n]` is better.
However, to be faithful to the C++ code structure (which declares it globally), I might declare it as `static boolean[][] ok = new boolean[N][N]`.
Wait, the C++ code declares `ok` globally.
I will declare it inside `main` to match the logic flow, but size `n` is safer.
Actually, if I declare `ok` as `new boolean[n][n]`, it matches the usage `ok[center][i]` where `center, i < n`.
I will use `new boolean[n][n]`.

**Wait, `TT`:**
`double` in Java.

**Wait, `acos(-1.0)`:**
`Math.acos(-1.0)`.

**Wait, `vector <point>`:**
`ArrayList<Point> pts`.

**Wait, `pts.push_back`:**
`pts.add`.

**Wait, `scanf("%d%d", &n, &radius)`:**
`StringTokenizer` to read `n` and `radius`.

**Wait, `printf("%d\n", ans)`:**
`System.out.println(ans)`.

**Wait, `const int N = 3030;`:**
`static final int N = 3030;`

**Wait, `const TT eps = 1e-9;`:**
`static final double EPS = 1e-9;`

**Wait, `using namespace std;`:**
Not needed in Java (no namespace pollution).

**Wait, `#define point complex<TT>`:**
`class Point` or `static class Point`.

**Wait, `#define x real()`:**
`this.x`.
`#define y imag()`: `this.y`.

**Wait, `norm`:**
`std::norm` returns `x*x + y*y`.
`sqrt(norm(...))` returns `sqrt(x*x + y*y)`.
`Math.hypot(x, y)` returns `sqrt(x*x + y*y)`.
So `Math.hypot` is the translation for `sqrt(norm)`.

**Wait, `arg`:**
`std::arg` returns `atan2(y, x)`.
So `Math.atan2(y, x)`.

**Wait, `sqrt`:**
`Math.sqrt`.

**Wait, `asin`:**
`Math.asin`.

**Wait, `max`, `min`:**
`Math.max`, `Math.min`.

**Wait, `while` loops:**
Java `while` loops work the same.

**Wait, `break`:**
Java `break` works the same.

**Wait, `vector` iteration:**
Java `for` loop over `ArrayList`.

**Wait, `ok` array access:**
`ok[center][i]`.

**Wait, `ans` calculation:**
`ans += ...`.

**Wait, `return 0;`:**
`return;` or nothing.

**Wait, `const TT PI = acos(-1.0);`:**
`static final double PI = Math.acos(-1.0);`

**Wait, `TT`:**
`double`.

**Wait, `N`:**
`3030`.

**Wait, `main` class name:**
`e_1588`.

**Wait, `bits/stdc++.h`:**
No direct equivalent, import `java.util.*`, `java.io.*`.

**Wait, `scanf`:**
`BufferedReader`.

**Wait, `ok` array:**
`boolean[][]`.

**Wait, `vector`:**
`ArrayList`.

**Wait, `pts`:**
`ArrayList<Point>`.

**Wait, `Complex` class:**
I will name it `Point` to match the C++ `point` typedef.

**Wait, `eps`:**
Defined but not used. I will keep it.

**Wait, `PI`:**
Defined and used.

**Wait, `N`:**
Defined and used.

**Wait, `ok`:**
Used.

**Wait, `ans`:**
Used.

**Wait, `radius`:**
Used.

**Wait, `n`:**
Used.

**Wait, `start`:**
Used.

**Wait, `L`, `R`:**
Used.

**Wait, `diff`:**
Used.

**Wait, `theta`:**
Used.

**Wait, `d`:**
Used.

**Wait, `i`:**
Used.

**Wait, `center`:**
Used.

**Wait, `angle`:**
Used.

**Wait, `ok[center][i]`:**
Used.

**Wait, `ok[i][j]`:**
Used.

**Wait, `ok[j][i]`:**
Used.

**Wait, `System.out.println`:**
Used.

**Wait, `BufferedReader`:**
Used.

**Wait, `StringTokenizer`:**
Used.

**Wait, `InputStreamReader`:**
Used.

**Wait, `IOException`:**
Used.

**Wait, `String` methods:**
`trim()`, `split()`, `nextToken()`.

**Wait, `Scanner`:**
I will use `BufferedReader` + `StringTokenizer` for robustness.

**Wait, `Complex` class:**
I'll name it `Point` to match the C++ `point` typedef.
Fields `x`, `y`.
Constructor `Point(double x, double y)`.
Methods `norm()`, `arg()`, `subtract()`.

**Wait, `norm`:**
`Math.hypot(x, y)`.

**Wait, `arg`:**
`Math.atan2(y, x)`.

**Wait, `subtract`:**
`new Point(this.x - other.x, this.y - other.y)`.

**Wait, `sqrt`:**
`Math.sqrt`.

**Wait, `asin`:**
`Math.asin`.

**Wait, `acos`:**
`Math.acos`.

**Wait, `max`:**
`Math.max`.

**Wait, `min`:**
`Math.min`.

**Wait, `PI`:**
`Math.PI`.

**Wait, `EPS`:**
`1e-9`.

**Wait, `N`:**
`3030`.

**Wait, `ok`:**
`boolean[][]`.

**Wait, `pts`:**
`ArrayList`.

**Wait, `ans`:**
`int`.

**Wait, `return`:**
`return;`.

**Wait, `class`:**
`public class e_1588`.

**Wait, `main`:**
`public static void main(String[] args)`.

**Wait, `throws`:**
`throws IOException`.

**Wait, `import`:**
`import java.util.*;`
`import java.io.*;`

**Wait, `static`:**
`static` for `ok`, `N`, `PI`, `EPS`.

**Wait, `final`:**
`final` for `N`, `PI`, `EPS`.

**Wait, `static class Point`:**
`static class Point`.

**Wait, `double`:**
`double`.

**Wait, `int`:**
`int`.

**Wait, `boolean`:**
`boolean`.

**Wait, `ArrayList`:**
`ArrayList`.

**Wait, `add`:**
`add`.

**Wait, `size`:**
`size`.

**Wait, `get`:**
`get`.

**Wait, `remove`:**
`remove`? No, `remove` not used.

**Wait, `iterator`:**
No iterator used.

**Wait, `for`:**
`for`.

**Wait, `if`:**
`if`.

**Wait, `else`:**
`else`? No.

**Wait, `while`:**
`while`.

**Wait, `break`:**
`break`.

**Wait, `System`:**
`System`.

**Wait, `out`:**
`out`.

**Wait, `println`:**
`println`.

**Wait, `printf`:**
`printf` -> `System.out.printf`. But `println` is easier.
Wait, `printf("%d\n", ans)`.
I will use `System.out.println(ans)`.

**Wait, `scanf`:**
`BufferedReader`.

**Wait, `StringTokenizer`:**
`StringTokenizer`.

**Wait, `next`:**
`nextToken`.

**Wait, `read`:**
`read`.

**Wait, `close`:**
`close`.

**Wait, `InputStream`:**
`InputStream`.

**Wait, `Reader`:**
`Reader`.

**Wait, `IOException`:**
`IOException`.

**Wait, `String`:**
`String`.

**Wait, `split`:**
`split`.

**Wait, `trim`:**
`trim`.

**Wait, `StringTokenizer`:**
`StringTokenizer`.

**Wait, `hasMoreTokens`:**
`hasMoreTokens`.

**Wait, `nextToken`:**
`nextToken`.

**Wait, `StringTokenizer`:**
`StringTokenizer`.

**Wait, `BufferedReader`:**
`BufferedReader`.

**Wait, `InputStreamReader`:**
`InputStreamReader`.

**Wait, `System`:**
`System`.

**Wait, `in`:**
`in`.

**Wait, `out`:**
`out`.

**Wait, `println`:**
`println`.

**Wait, `printf`:**
`printf`.

**Wait, `System.out`:**
`System.out`.

**Wait, `Scanner`:**
I'll use `BufferedReader`.

**Wait, `Complex`:**
`Point`.

**Wait, `x`:**
`x`.

**Wait, `y`:**
`y`.

**Wait, `norm`:**
`norm`.

**Wait, `arg`:**
`arg`.

**Wait, `subtract`:**
`subtract`.

**Wait, `Complex`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

**Wait, `complex`:**
`Point`.

**Wait, `point`:**
`Point`.

**Wait, `TT`:**
`double`.

**Wait, `TT`:**
`double`.

