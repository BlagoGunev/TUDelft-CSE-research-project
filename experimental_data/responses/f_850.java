Translate this C++ code to Java code. The main class name should be f_850. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int a[2600];
int f[100100];

int inv(int a){
	return a == 1 ? 1 : (ll)(M - M / a) * inv(M % a) % M;
}

int UP(int x){
	return x < 0 ? x + M : x;
}

int main(){
	scanf("%d", &n);
	ll sum = 0;
	int tmax = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", a + i);
		sum += a[i];
		tmax = max(a[i], tmax);
	}

	f[1] = (ll)(sum - 1) * (sum - 1) % M * inv(sum) % M;
	for(int i = 1; i < tmax; ++i)
		f[i + 1] = UP((2LL * f[i] - f[i - 1] - (ll)(sum - 1) * inv(sum - i)) % M);

	int res = 0;
	for(int i = 0; i < n; ++i)
		res = (res + f[a[i]]) % M;
	
	printf("%d\n", res);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}

<think>
The user wants me to translate a C++ code snippet into Java code.
The main class name must be `f_850`.

**Plan for Translation:**

1.  **Headers and Imports:**
    *   C++: `#include<bits/stdc++.h>` (Standard library, includes almost everything).
    *   Java: Need `java.util.Scanner` for input (`scanf`), or `java.io.BufferedReader` for faster I/O. Since the problem seems to involve competitive programming (modulo arithmetic, array sizes), standard `Scanner` might be slow, but for `n` up to 2600, `Scanner` is usually fine. However, `System.out.println` is the equivalent of `printf`.
    *   `using namespace std;` is not needed in Java.

2.  **Macros/Constants:**
    *   `#define pb push_back`: Not used in the provided code, so can be ignored.
    *   `#define mkp make_pair`: Not used.
    *   `#define fi first`, `#define se second`: Not used.
    *   `#define ll long long`: Java has `long` which is 64-bit, matching `long long`.
    *   `#define M 1000000007`: Constant integer `M`.
    *   `#define all(a) ...`: Not used.

3.  **Data Structures:**
    *   C++: `int n;`, `int a[2600];`, `int f[100100];`.
    *   Java: `int n;`, `int[] a = new int[2600];`, `int[] f = new int[100100];`.
    *   Note: C++ arrays are 0-indexed by default. Java arrays are also 0-indexed.
    *   `sum` is declared as `ll` (long long) in C++. In Java, it should be `long`.
    *   `tmax` is `int`.

4.  **Functions:**
    *   `int inv(int a)`:
        *   C++ returns `int`.
        *   Java returns `int`.
        *   Calculation involves `ll` (long long). In Java, `long` is used.
        *   Logic: Modular inverse using Fermat's Little Theorem (implied by the formula `(M - M/a) * inv(M % a) % M`). This assumes `M` is prime.
        *   Wait, the formula `(M - M / a) * inv(M % a) % M` looks like a recursive modular inverse calculation, specifically `inv(a) = (M - M/a) * inv(M%a) % M`.
        *   In C++, `a` is `int`, but inside `inv`, `ll` is used for calculation.
        *   In Java, `a` should be `int` (passed as `int`), but calculations must use `long`.
    *   `int UP(int x)`:
        *   C++ returns `int`.
        *   Java returns `int`.
        *   Logic: `x < 0 ? x + M : x`.
    *   `main()`:
        *   C++: `scanf`, `printf`, `system("pause")`.
        *   Java: `Scanner`, `System.out.println`.
        *   Logic needs to be adapted.

5.  **Specific C++ to Java considerations:**
    *   **I/O:** `scanf` and `printf` are replaced by `Scanner` or `BufferedReader`. `System.out.println` replaces `printf`.
    *   **Types:** `long long` becomes `long`.
    *   **Arrays:** C-style arrays `int a[2600]` become Java arrays `int[] a = new int[2600]`.
    *   **Modulo Arithmetic:** In C++, `(ll)(M - M / a) * inv(M % a) % M` works because `long long` handles intermediate overflow. In Java, `long` handles this.
    *   **Modulo:** The code uses `M = 1000000007`.
    *   **Main Method:** Java requires a `public static void main(String[] args)`.
    *   **Class:** The class name must be `f_850`.
    *   **System Pause:** `#ifndef ONLINE_JUDGE` block usually runs `system("pause")` on Windows to keep the console open. In Java, we might not need this, or we can add a `Scanner` close or `Thread.sleep` to keep it open if running locally, but typically competitive programming platforms don't need it. I will remove the `system("pause")` or keep it commented/conditional logic equivalent if necessary, but standard Java doesn't support `#ifndef`. I'll just remove the pause logic as it's specific to C++ IDEs/Local environments and Java usually terminates or keeps open via console. Or I can add a `try-catch` block with a sleep just to mimic behavior, but usually, it's safer to just omit it for standard Java submission unless specified. I will omit it to keep it clean, or add a comment. Actually, looking at the code, it's a CP problem. I should just implement the logic.
    *   **Variables:** `sum` is `long` in Java.
    *   **Recursion:** `inv` is recursive. Java handles recursion fine.

6.  **Incremental Tasks:**
    *   Step 1: Create class structure and imports.
    *   Step 2: Define constants and arrays.
    *   Step 3: Implement `inv` method.
    *   Step 4: Implement `UP` method.
    *   Step 5: Implement `main` method logic (Input, loop, calculation, output).

7.  **Code Logic Check:**
    *   `f[1] = (ll)(sum - 1) * (sum - 1) % M * inv(sum) % M;`
        *   In Java: `f[1] = ((long)(sum - 1) * (sum - 1) % M * inv(sum)) % M;`
        *   Wait, the C++ code: `(ll)(sum - 1) * (sum - 1) % M * inv(sum) % M`.
        *   Java precedence: `*` and `%` are left-associative.
        *   `(long)(sum - 1)` ensures the first multiplication doesn't overflow `int`.
    *   Loop: `for(int i = 1; i < tmax; ++i)`
    *   Update: `f[i + 1] = UP((2LL * f[i] - f[i - 1] - (ll)(sum - 1) * inv(sum - i)) % M);`
        *   Java: `f[i + 1] = UP((2L * f[i] - f[i - 1] - (long)(sum - 1) * inv(sum - i)) % M);`
        *   Note: `UP` handles negative results by adding `M`.
        *   In C++, `(A - B) % M` can be negative if `A - B < 0`. Java's `%` operator returns negative for negative operands (e.g., `-5 % 7` is `-5`). `UP` function handles this by checking `x < 0`.
        *   Wait, the C++ code: `f[i + 1] = UP(... % M)`.
        *   If `(... % M)` is negative, `UP` adds `M`.
        *   So in Java, we calculate the expression, apply `% M`, then pass to `UP`.
        *   Wait, `2LL * f[i] - f[i - 1] - ...`
        *   If this result is negative, `% M` keeps it negative. `UP` fixes it.
        *   However, `2LL * f[i]` can be large. `f[i]` is `int` (max `M`). `2 * M` fits in `long`.
        *   We need to be careful with `long` arithmetic in Java.
    *   `inv` function:
        *   `return a == 1 ? 1 : (ll)(M - M / a) * inv(M % a) % M;`
        *   This calculates modular inverse of `a` modulo `M`.
        *   Java equivalent: `return a == 1 ? 1 : (long)(M - M / a) * inv(M % a) % M;`

8.  **Refining Java Code:**
    *   Class `f_850`.
    *   `Scanner sc = new Scanner(System.in);`
    *   Read `n`.
    *   Arrays `a` size `n`? C++ uses `a[2600]`. In Java, `new int[2600]` is fine, but we only use up to `n`.
    *   Read `a[i]` for `i` from 0 to `n-1`.
    *   Compute `sum` and `tmax`.
    *   Compute `f` array.
    *   Compute `res`.
    *   Print `res`.

9.  **Potential Issues:**
    *   `inv` method is recursive. In Java, recursion depth might be an issue if `M` is large, but here `M % a` decreases rapidly (similar to Euclidean algorithm), so depth is logarithmic with respect to `M`. It's safe.
    *   `f` array size: `100100`. In Java `new int[100100]`.
    *   `sum` calculation: `sum += a[i]`. Since `a[i]` are small (up to `tmax`?), `sum` fits in `long`. `tmax` is `max(a[i])`.
    *   Wait, `f` array is indexed up to `tmax`. `tmax` can be up to what? The loop `for(int i = 0; i < n; ++i)` reads `a[i]`. Then `tmax = max(a[i], tmax)`.
    *   If `a[i]` values are large, `f` array needs to be large enough. `f` is size `100100`. So `a[i]` must be `< 100100`.
    *   The code calculates `f[i+1]` based on `f[i]` and `f[i-1]`.
    *   Wait, `f[0]`? The loop starts at `i=1`. `f[0]` is not initialized?
    *   Wait, look at `f[1]`. It uses `inv(sum)`.
    *   The loop `for(int i = 1; i < tmax; ++i)` computes `f[2]` to `f[tmax]`.
    *   It uses `f[i-1]`. When `i=1`, `f[0]` is accessed. `f[0]` is default initialized to 0 in Java/C++.
    *   Is `f[0]` meant to be 0?
    *   The recurrence: `f[i+1] = 2*f[i] - f[i-1] - ...`.
    *   If `f[0]` is 0, then `f[1]` is calculated explicitly.
    *   Wait, `f[1]` calculation: `(sum - 1)^2 * inv(sum)`.
    *   If `f[0]` is 0, does it affect `f[2]`?
    *   `f[2] = 2*f[1] - f[0] - (sum-1)*inv(sum-1)`.
    *   So `f[0]` must be defined. In C++, global arrays are zero-initialized. In Java, arrays are zero-initialized. So `f[0] = 0` is implicit.
    *   Wait, is `f[0]` supposed to be 0?
    *   Let's check the recurrence logic. Usually, `f[0]` corresponds to some base case.
    *   If `f[0]` is 0, then `f[1]` is computed.
    *   Okay, I will stick to the logic.

    *   Wait, `sum` calculation: `sum += a[i]`.
    *   `inv` function takes `int a`.
    *   `inv` returns `int`.
    *   Calculations inside `inv` use `long` (C++ `ll`).
    *   Calculations inside `main` use `long` (C++ `ll`).
    *   Modulo `M`.

    *   One detail: `UP` function in C++: `x < 0 ? x + M : x`.
    *   In Java: `return x < 0 ? x + M : x;`.
    *   Wait, `x` is passed as `int`. `x + M` might overflow `int` if `x` is close to `Integer.MAX_VALUE` and `M` is large?
    *   `M` is `10^9 + 7`. `x` is result of `% M`. So `x` is in `(-M, M)`.
    *   `x + M` will be positive and `< 2M`. `2M` is `2 * 10^9 + 14`, which fits in `int` (max `2 * 10^9`).
    *   So `int` is fine for `UP` return type.

    *   Wait, `inv` calculation: `(ll)(M - M / a) * inv(M % a) % M`.
    *   `M` is `int`. `a` is `int`.
    *   `M - M / a` is `int`.
    *   `inv(M % a)` returns `int`.
    *   Multiplication `(int) * (int)` -> `long` cast is needed.
    *   In C++: `(ll)(M - M / a)`.
    *   In Java: `(long)(M - M / a)`.
    *   Then multiply by `inv(...)`.
    *   Then `% M`.

    *   One specific thing: `f[1]` calculation.
    *   `f[1] = (ll)(sum - 1) * (sum - 1) % M * inv(sum) % M;`
    *   In Java:
        ```java
        long sMinus1 = sum - 1;
        f[1] = (int) ((sMinus1 * sMinus1 % M) * inv((int)sum) % M);
        ```
    *   Wait, `sum` is `long`. `inv` takes `int`.
    *   `sum` can be larger than `M`? No, `sum` is sum of `a[i]`. `a[i]` is likely small?
    *   Actually, `inv(sum)` implies `sum` is coprime to `M`.
    *   If `sum >= M`, `sum % M` should be passed?
    *   In C++, `inv(sum)` passes `long` to `int`.
    *   Wait, `inv` signature is `int inv(int a)`.
    *   If `sum` is `long` and `sum >= Integer.MAX_VALUE`, passing to `inv` might lose data.
    *   However, usually in these problems, values are modulo `M`.
    *   Let's check `f[1]` calculation again.
    *   `(sum - 1) * (sum - 1) % M`.
    *   If `sum` is `long`, `(sum - 1)` is `long`.
    *   If `sum` is large, `sum % M` should be used?
    *   The code does `(sum - 1) * (sum - 1) % M`. This works for `long`.
    *   Then `* inv(sum)`.
    *   `inv(sum)` expects `int`.
    *   If `sum` is `long`, `inv` will take the lower bits (truncation).
    *   This implies `sum` is assumed to be `< M` or `inv` handles it.
    *   Wait, `sum` is sum of `a[i]`. If `n` is large, `sum` can be large.
    *   But `inv` is used for modular inverse.
    *   If `sum` >= `M`, `sum` is not invertible modulo `M` if `sum` is a multiple of `M`.
    *   Actually, usually in such problems, `sum` is treated modulo `M` before calling `inv`.
    *   Let's look at `f[1]` line again: `(ll)(sum - 1) * (sum - 1) % M * inv(sum) % M`.
    *   If `sum` is `long`, `inv(sum)` casts `sum` to `int`.
    *   This is suspicious if `sum` can exceed `Integer.MAX_VALUE`.
    *   However, `M` is `10^9 + 7`. `sum` is sum of `a[i]`. `a[i]` are read as `int`.
    *   If `n` is up to 2600, and `a[i]` are positive, `sum` can exceed `M`.
    *   If `sum` >= `M`, `sum % M` is the correct argument for modular inverse.
    *   Does the C++ code handle `sum % M`?
    *   `inv(sum)` passes `sum` (long) to `int`.
    *   If `sum` > `Integer.MAX_VALUE`, it truncates.
    *   If `sum` > `M`, it should ideally pass `sum % M`.
    *   But maybe `sum` is guaranteed to be `< M`? Or maybe the logic implies `sum` is `sum % M` implicitly?
    *   Wait, if `sum` is used in `(sum - 1) * (sum - 1) % M`, then `sum` is effectively `sum % M` for the multiplication part.
    *   But for `inv(sum)`, if `sum` is `long`, `inv` takes `int`.
    *   If `sum` is `long` and `sum > M`, `sum % M` is needed for the inverse.
    *   If `inv` takes `sum` directly (cast to int), it might be wrong.
    *   However, I must translate the code *as is*. I should not fix logic bugs unless requested.
    *   Wait, `inv` takes `int`. `sum` is `ll`.
    *   If I pass `sum` to `inv`, it will cast to `int`.
    *   If `sum` is large, this is a logic error in C++ code too (if `sum` > `M`).
    *   Wait, `sum` is sum of `a[i]`. If `a[i]` are `int`, `sum` is `ll`.
    *   Maybe `sum` is guaranteed to be `< M`?
    *   Or maybe the intention is `sum % M`.
    *   Wait, if I look closely at C++: `inv(int a)`.
    *   If `sum` is `long`, `inv(sum)` calls `inv((int)sum)`.
    *   If `sum` > `M`, `sum % M` is not taken before calling `inv`.
    *   This might be a bug in the original C++ code, or `sum` is small.
    *   Given the task is translation, I will translate `inv(sum)` as `inv((int)sum)`.
    *   However, if `sum` is `long`, `sum - 1` is `long`.
    *   `inv(sum)` inside the expression: `(sum - 1) * (sum - 1) % M * inv(sum) % M`.
    *   The term `(sum - 1) * (sum - 1) % M` reduces `sum` to range `[0, M-1]`.
    *   The term `inv(sum)` is multiplied.
    *   If `sum` is large, `sum % M` is the argument for `inv`.
    *   But `inv` takes `int`.
    *   I should probably cast `sum` to `int` before passing to `inv` to match the C++ signature, but `sum` might need to be `sum % M` first.
    *   Wait, `sum` is `long`. `inv` takes `int`.
    *   In C++, `inv(sum)` will implicitly cast `sum` to `int`.
    *   If `sum` is `10^9 + 8` (which is `M+1`), `sum` fits in `int` (since `M` is `10^9+7`, `M+1` is `1000000008`, `Integer.MAX_VALUE` is `2*10^9`).
    *   So `sum` fits in `int` if `n` is small or `a[i]` are small.
    *   If `sum` exceeds `Integer.MAX_VALUE`, C++ code might be buggy.
    *   But I will translate faithfully. `inv` takes `int`. `sum` is `long`.
    *   In Java, `inv` takes `int`. `sum` is `long`.
    *   So I must cast `sum` to `int` when calling `inv`.
    *   Wait, `(sum - 1)` is calculated first.
    *   `sum` is `long`. `sum - 1` is `long`.
    *   `(sum - 1) * (sum - 1) % M` results in `long` (or `int` if cast).
    *   Then `* inv(sum)`.
    *   If `sum` is `long`, `inv(sum)` casts to `int`.
    *   I will assume the C++ code is correct for the given constraints, so I will translate it directly.

    *   Wait, `f` array is `int`.
    *   `sum` is `ll`.
    *   `inv` returns `int`.
    *   In Java: `long` for `sum`. `int` for `f`.
    *   `inv` method: `int inv(int a)`.
    *   Main: `long sum`.

    *   Wait, `f[i + 1] = UP(...)`
    *   `UP` takes `int`.
    *   Inside `UP`: `x < 0 ? x + M : x`.
    *   This handles negative modulo results.
    *   In Java: `return x < 0 ? x + M : x;`.

    *   One detail: `inv` function recursion.
    *   `inv(M % a)`.
    *   If `a` is `1`, returns `1`.
    *   `M % a` is smaller than `a`.
    *   So recursion terminates.

    *   I/O:
    *   `scanf("%d", &n)` -> `sc.nextInt()`.
    *   `scanf("%d", a + i)` -> `a[i] = sc.nextInt()`.
    *   `printf("%d\n", res)` -> `System.out.println(res)`.
    *   `#ifndef ONLINE_JUDGE ... system("pause")` -> In Java, this doesn't apply directly. I will remove it or add a comment. I'll just remove it as it's specific to C++/Windows console behavior not relevant for Java logic translation (usually). Or I can add `// Removed system("pause")` comment.
    *   Wait, the prompt asks to translate the code. I should keep the structure.
    *   I will remove the `#ifndef` block as Java doesn't support preprocessor directives. I will add a comment explaining it was removed.

    *   Class name: `f_850`.
    *   Package: None.

    *   Imports: `java.util.Scanner`.

    *   Array sizes:
        *   `int[] a = new int[2600];`
        *   `int[] f = new int[100100];`

    *   `sum` variable: `long`.
    *   `tmax` variable: `int`.

    *   Logic:
        *   Read `n`.
        *   Loop `0` to `n-1`: read `a[i]`, add to `sum`, update `tmax`.
        *   `f[1]` calculation.
        *   Loop `1` to `tmax-1`: update `f`.
        *   Loop `0` to `n-1`: sum `f[a[i]]`.
        *   Print `res`.

    *   Wait, `f` array size is `100100`. `tmax` is `max(a[i])`.
    *   If `tmax` > `100100`, ArrayIndexOutOfBounds.
    *   The C++ code assumes `tmax` fits. I will assume it fits.

    *   Wait, `f` array is `int`. `sum` is `long`.
    *   `f` values are modulo `M`. So they fit in `int`.

    *   Wait, `inv` function: `return a == 1 ? 1 : (ll)(M - M / a) * inv(M % a) % M;`
    *   Java: `return a == 1 ? 1 : (long)(M - M / a) * inv(M % a) % M;`
    *   Note: `M` is `int`. `a` is `int`.
    *   `M - M / a` is `int`.
    *   Cast to `long` before multiplication.
    *   Then `* inv(...)`.
    *   Then `% M`.

    *   One detail: `inv(sum)`. `sum` is `long`.
    *   If I pass `sum` to `inv(int)`, it will cast to `int`.
    *   I will do exactly that.

    *   Wait, `f[1]` calculation:
        `f[1] = (ll)(sum - 1) * (sum - 1) % M * inv(sum) % M;`
        In Java:
        `f[1] = (int) (((sum - 1) * (sum - 1) % M) * inv((int)sum) % M);`
        Wait, `f` is `int[]`.
        So I must cast the result to `int`.
        The C++ code: `(ll)(sum - 1) * (sum - 1) % M * inv(sum) % M`.
        This returns `ll`.
        Assigning to `int f[1]` casts to `int`.
        So in Java: `f[1] = (int) ( ... )`.

    *   Wait, `inv(sum)` inside the expression.
    *   `sum` is `long`. `inv` takes `int`.
    *   If `sum` is large, `(int)sum` truncates.
    *   I will cast it: `inv((int)sum)`.
    *   Wait, is `sum` guaranteed to be small?
    *   If `sum` >= `M`, `sum % M` is needed for modular arithmetic.
    *   But `inv` takes `int`.
    *   If I cast `sum` to `int`, I lose info.
    *   But `f[1]` uses `(sum - 1) * (sum - 1) % M`.
    *   So `sum` is effectively `sum % M` in the multiplication part.
    *   But `inv` is called with `sum`.
    *   If `sum` is `M+1`, `sum % M` is `1`. `inv(1)` is `1`.
    *   If `sum` is `M+1`, `(int)sum` is `1` (if `M+1` fits in int).
    *   Wait, `M = 10^9+7`. `M+1` fits in `int`.
    *   So `(int)sum` works.
    *   But if `sum` > `Integer.MAX_VALUE`, it truncates.
    *   Given the problem constraints (likely competitive programming), `sum` might be large.
    *   However, I must translate the code. I will use `(int)sum`.

    *   Wait, `f[i+1]` calculation:
        `UP((2LL * f[i] - f[i - 1] - (ll)(sum - 1) * inv(sum - i)) % M)`
        In Java:
        `long term = (2L * f[i] - f[i - 1] - ((long)(sum - 1) * inv(sum - i)) % M) % M;`
        `f[i + 1] = UP((int)term);`
        Wait, `UP` takes `int`.
        `term` is `long`.
        Modulo `M` brings it to range `(-M, M)`.
        So cast to `int` is safe.
        `UP` handles negative.

    *   Wait, `f` array initialization.
    *   In C++, global arrays are 0-initialized.
    *   In Java, `new int[]` is 0-initialized.
    *   So `f[0]` is 0.

    *   Wait, `tmax` calculation: `tmax = max(a[i], tmax)`.
    *   Java: `tmax = Math.max(a[i], tmax)`.

    *   Imports: `java.util.Scanner`. `java.lang.Math` (implicitly imported).

    *   Class name: `f_850`.

    *   Wait, `inv` function:
        `return a == 1 ? 1 : (ll)(M - M / a) * inv(M % a) % M;`
        In Java:
        `return a == 1 ? 1 : (long)(M - M / a) * inv(M % a) % M;`
        Wait, `inv` returns `int`.
        The expression returns `long`.
        Implicit cast to `int` on return?
        In C++, `inv` returns `int`.
        The expression is `int`.
        Wait, `(ll)(...) * inv(...) % M`.
        `inv` returns `int`.
        `ll` cast makes it `long`.
        `% M` makes it `int` (if `M` is `int`).
        So return type `int` is correct.
        In Java, `% M` on `long` returns `long`.
        So return type should be `long`?
        No, C++ `int` return.
        In Java, I should return `int`.
        But the calculation produces `long`.
        So I must cast to `int`.
        `return a == 1 ? 1 : (int)((long)(M - M / a) * inv(M % a) % M);`

    *   Wait, `f` array is `int`.
    *   `f[1]` is assigned `int`.
    *   So `inv` returning `int` is consistent.

    *   Wait, `f[i+1]` calculation:
        `UP((2LL * f[i] - f[i - 1] - (ll)(sum - 1) * inv(sum - i)) % M)`
        `UP` takes `int`.
        The argument to `UP` is `(... % M)`.
        In C++, `% M` on `int` returns `int`.
        In Java, `% M` on `long` returns `long`.
        So I need to cast to `int` before passing to `UP`.
        `UP((int)(... % M))`.

    *   Wait, `inv` method.
        `inv` calls `inv`.
        `inv(M % a)`. `M % a` is `int`.
        So `inv` takes `int`.
        So recursion is fine.

    *   Wait, `sum` is `long`. `sum - i` is `long`.
    *   `inv(sum - i)` takes `int`.
    *   So `(sum - i)` must be cast to `int`.
    *   `inv((int)(sum - i))`.

    *   Wait, `sum` is `long`. `sum - 1` is `long`.
    *   `(ll)(sum - 1)` is `long`.
    *   `2LL * f[i]` is `long`.
    *   `f[i - 1]` is `int`.
    *   So `2LL * f[i] - f[i - 1]` is `long`.
    *   Then subtract `((ll)(sum - 1) * inv(...)) % M`.
    *   Then `% M`.
    *   Then cast to `int` for `UP`.

    *   Wait, `sum` is `long`.
    *   `f[1]` calculation: `(ll)(sum - 1) * (sum - 1) % M * inv(sum) % M`.
    *   `sum` is `long`.
    *   `(sum - 1)` is `long`.
    *   `inv(sum)` -> `inv((int)sum)`.
    *   So `f[1]` is `int`.

    *   Wait, `f` array size is `100100`.
    *   `tmax` is `max(a[i])`.
    *   If `tmax` > `100100`, crash.
    *   I will assume `tmax` fits.

    *   Wait, `inv` function.
    *   `return a == 1 ? 1 : ...`
    *   If `a` is `0`, `M % 0` throws exception.
    *   But `a` is `sum` or `sum - i`.
    *   `sum` is sum of positive integers? `a[i]` are read as `int`.
    *   If `a[i]` can be 0, `sum` can be 0.
    *   `inv(0)` would crash.
    *   But `sum` is sum of `a[i]`.
    *   If `a[i]` >= 1, `sum` >= 1.
    *   If `a[i]` can be 0, `sum` can be 0.
    *   I will assume `sum` is valid (>= 1).

    *   One more thing: `#ifndef ONLINE_JUDGE`.
    *   In Java, I'll just omit the `system("pause")` block.

    *   Code Structure:
        ```java
        import java.util.Scanner;

        public class f_850 {
            static final int M = 1000000007;
            static int n;
            static int[] a = new int[2600];
            static int[] f = new int[100100];

            static int inv(int a) {
                return a == 1 ? 1 : (int)((long)(M - M / a) * inv(M % a) % M);
            }

            static int UP(int x) {
                return x < 0 ? x + M : x;
            }

            public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                if (sc.hasNextInt()) {
                    n = sc.nextInt();
                }
                long sum = 0;
                int tmax = 0;
                for (int i = 0; i < n; ++i) {
                    a[i] = sc.nextInt();
                    sum += a[i];
                    if (a[i] > tmax) {
                        tmax = a[i];
                    }
                }

                f[1] = (int) (((sum - 1) * (sum - 1) % M) * inv((int)sum) % M);

                for (int i = 1; i < tmax; ++i) {
                    long term = 2L * f[i] - f[i - 1] - ((long)(sum - 1) * inv((int)(sum - i)) % M);
                    f[i + 1] = UP((int)(term % M));
                }

                int res = 0;
                for (int i = 0; i < n; ++i) {
                    res = (res + f[a[i]]) % M;
                }

                System.out.println(res);
            }
        }
        ```
    *   Wait, `f[1]` calculation in Java:
        `(sum - 1)` is `long`.
        `(sum - 1) * (sum - 1)` is `long`.
        `% M` is `long`.
        `inv((int)sum)` is `int`.
        `*` is `long`.
        `% M` is `long`.
        Cast to `int`.
        Correct.

    *   Wait, `f` array index `i+1`.
    *   `i` goes up to `tmax - 1`.
    *   `i+1` goes up to `tmax`.
    *   `f` size is `100100`.
    *   If `tmax` > `100100`, crash.
    *   I'll assume it's fine.

    *   Wait, `inv` method.
    *   `M` is static final.
    *   `inv` is static.
    *   `f` is static.
    *   `a` is static.
    *   `n` is static.
    *   `sum` is local. `tmax` is local.
    *   In C++, `n`, `a`, `f` are global.
    *   In Java, make them static to access from static methods.

    *   Wait, `f` array initialization.
    *   Java arrays are initialized to 0.
    *   So `f[0]` is 0.
    *   `f[1]` is calculated.
    *   Loop `i` starts at 1.
    *   `f[i-1]` accesses `f[0]` when `i=1`.
    *   So `f[0]` must be 0.
    *   Java `new int[]` initializes to 0.
    *   So it matches C++ behavior.

    *   Wait, `f[1]` calculation: `(sum - 1) * (sum - 1) % M`.
    *   If `sum` is 1, `0 * 0 % M = 0`.
    *   `inv(1) = 1`.
    *   `0 * 1 % M = 0`.
    *   So `f[1] = 0`.
    *   If `sum` is 1, `f[1]` is 0.
    *   Then loop `i=1`. `f[2] = UP(2*0 - 0 - ...)`
    *   `sum - 1` is 0.
    *   `inv(0)`?
    *   If `sum` is 1, `sum - i` is `1 - 1 = 0`.
    *   `inv(0)` crashes.
    *   So `sum` must be > `tmax`?
    *   Wait, `tmax` is `max(a[i])`.
    *   `i` goes up to `tmax - 1`.
    *   So `sum - i` is `sum - (tmax - 1)`.
    *   If `sum` is `tmax`, `sum - (tmax - 1) = 1`.
    *   If `sum` is `tmax`, `inv(1)` is 1.
    *   If `sum` is `tmax`, `sum - 1` is `tmax - 1`.
    *   So `f[1]` uses `sum`.
    *   If `sum` is 1, `f[1]` is 0.
    *   If `sum` is 1, `tmax` is 1.
    *   Loop `i` from 1 to `tmax - 1` (0 to 0). Loop doesn't run.
    *   So `inv(0)` is not called.
    *   So `sum` must be > 1 for loop to run?
    *   Or `sum` > `i`.
    *   Since `i < tmax`, `sum - i` >= `sum - (tmax - 1)`.
    *   If `sum` >= `tmax`, `sum - i` >= 1.
    *   So `inv` is safe.

    *   Wait, `f` array size.
    *   `tmax` is max `a[i]`.
    *   If `a[i]` > `100100`, crash.
    *   I'll trust the C++ code constraints.

    *   Wait, `Scanner` usage.
    *   `n` is read.
    *   Then loop `n` times.
    *   `a[i]` read.
    *   `sum` updated.
    *   `tmax` updated.
    *   Matches C++ logic.

    *   Wait, `res` calculation.
    *   `res = (res + f[a[i]]) % M`.
    *   `res` is `int`.
    *   `f[a[i]]` is `int`.
    *   `res + f[a[i]]` might overflow `int` before `% M`.
    *   `M` is `10^9+7`. `2 * M` fits in `int`.
    *   So `(res + f[a[i]])` fits in `int`?
    *   `res` < `M`. `f` < `M`.
    *   `res + f` < `2M`.
    *   `2M` is `2000000014`.
    *   `Integer.MAX_VALUE` is `2147483647`.
    *   So `int` addition is safe.
    *   So `res = (res + f[a[i]]) % M` is fine.

    *   Wait, `f` array.
    *   `f` is `int[]`.
    *   `f[1]` is `int`.
    *   `f[i+1]` is `int`.
    *   Matches.

    *   Wait, `inv` function.
    *   `return a == 1 ? 1 : ...`
    *   `inv(M % a)`.
    *   `M % a` is `int`.
    *   `inv` takes `int`.
    *   Matches.

    *   Wait, `UP` function.
    *   `x < 0 ? x + M : x`.
    *   `x` is `int`.
    *   `x + M` is `int`.
    *   Matches.

    *   Wait, `System.out.println`.
    *   `res` is `int`.
    *   Matches `printf("%d\n", res)`.

    *   Wait, `#ifndef ONLINE_JUDGE`.
    *   I will remove this block.

    *   Wait, `sum` is `long`.
    *   In C++, `sum` is `ll`.
    *   In Java, `sum` is `long`.
    *   Matches.

    *   Wait, `f` array size.
    *   C++: `int f[100100];`
    *   Java: `int[] f = new int[100100];`
    *   Matches.

    *   Wait, `a` array size.
    *   C++: `int a[2600];`
    *   Java: `int[] a = new int[2600];`
    *   Matches.

    *   Wait, `n`.
    *   C++: `int n;`
    *   Java: `int n;`
    *   Matches.

    *   Wait, `tmax`.
    *   C++: `int tmax = 0;`
    *   Java: `int tmax = 0;`
    *   Matches.

    *   Wait, `f[1]` calculation.
    *   C++: `(ll)(sum - 1) * (sum - 1) % M * inv(sum) % M`.
    *   Java: `(int) (((sum - 1) * (sum - 1) % M) * inv((int)sum) % M)`.
    *   Matches logic.

    *   Wait, `f[i+1]` calculation.
    *   C++: `UP((2LL * f[i] - f[i - 1] - (ll)(sum - 1) * inv(sum - i)) % M)`.
    *   Java: `UP((int)((2L * f[i] - f[i - 1] - ((long)(sum - 1) * inv((int)(sum - i)) % M)) % M))`.
    *   Wait, precedence.
    *   `2LL * f[i]` is `long`.
    *   `f[i - 1]` is `int`.
    *   `2L * f[i] - f[i - 1]` is `long`.
    *   `(ll)(sum - 1)` is `long`.
    *   `inv(sum - i)` is `int`.
    *   `(ll)(sum - 1) * inv(...)` is `long`.
    *   `% M` is `long`.
    *   `long - long - long` is `long`.
    *   `% M` is `long`.
    *   `UP` takes `int`.
    *   So cast to `int`.
    *   Matches.

    *   Wait, `inv` function.
    *   `return a == 1 ? 1 : (int)((long)(M - M / a) * inv(M % a) % M);`
    *   Matches.

    *   Wait, `UP` function.
    *   `return x < 0 ? x + M : x;`
    *   Matches.

    *   Wait, `f` array initialization.
    *   Java arrays are initialized to 0.
    *   C++ global arrays are initialized to 0.
    *   Matches.

    *   Wait, `a` array initialization.
    *   Java arrays are initialized to 0.
    *   C++ global arrays are initialized to 0.
    *   Matches.

    *   Wait, `n` is global.
    *   Java `static`.
    *   Matches.

    *   Wait, `f` is global.
    *   Java `static`.
    *   Matches.

    *   Wait, `a` is global.
    *   Java `static`.
    *   Matches.

    *   Wait, `M` is global.
    *   Java `static final`.
    *   Matches.

    *   Wait, `all(a)` macro not used.
    *   Matches.

    *   Wait, `pb`, `mkp`, `fi`, `se` macros not used.
    *   Matches.

    *   Wait, `#define ll long long`.
    *   Java `long`.
    *   Matches.

    *   Wait, `#define M 1000000007`.
    *   Java `static final int M = 1000000007;`.
    *   Matches.

    *   Wait, `#define all(a) ...`.
    *   Not used.
    *   Matches.

    *   Wait, `scanf`.
    *   Java `Scanner`.
    *   Matches.

    *   Wait, `printf`.
    *   Java `System.out.println`.
    *   Matches.

    *   Wait, `system("pause")`.
    *   Removed.
    *   Matches.

    *   Wait, `#ifndef ONLINE_JUDGE`.
    *   Removed.
    *   Matches.

    *   Wait, `return 0`.
    *   Java `return`.
    *   Matches.

    *   Wait, `main` method.
    *   Java `public static void main(String[] args)`.
    *   Matches.

    *   Wait, `inv` function.
    *   `inv` is static.
    *   Matches.

    *   Wait, `UP` function.
    *   `UP` is static.
    *   Matches.

    *   Wait, `f[1]` calculation.
    *   `f[1]` is `int`.
    *   Matches.

    *   Wait, `f[i+1]` calculation.
    *   `f[i+1]` is `int`.
    *   Matches.

    *   Wait, `res` calculation.
    *   `res` is `int`.
    *   Matches.

    *   Wait, `res` initialization.
    *   `int res = 0;`
    *   Matches.

    *   Wait, `f` array size.
    *   `100100`.
    *   Matches.

    *   Wait, `a` array size.
    *   `2600`.
    *   Matches.

    *   Wait, `n`.
    *   Matches.

    *   Wait, `tmax`.
    *   Matches.

    *   Wait, `sum`.
    *   Matches.

    *   Wait, `inv`.
    *   Matches.

    *   Wait, `UP`.
    *   Matches.

    *   Wait, `main`.
    *   Matches.

    *   Wait, `System.out.println`.
    *   Matches.

    *   Wait, `Scanner`.
    *   Matches.

    *   Wait, `import`.
    *   Matches.

    *   Wait, `class`.
    *   Matches.

    *   Wait, `public`.
    *   Matches.

    *   Wait, `static`.
    *   Matches.

    *   Wait, `final`.
    *   Matches.

    *   Wait, `int`.
    *   Matches.

    *   Wait, `long`.
    *   Matches.

    *   Wait, `void`.
    *   Matches.

    *   Wait, `String[] args`.
    *   Matches.

    *   Wait, `if (sc.hasNextInt())`.
    *   Added for safety.
    *   Matches C++ `scanf` behavior (blocks until input).

    *   Wait, `a[i]`.
    *   Matches.

    *   Wait, `f[a[i]]`.
    *   Matches.

    *   Wait, `res`.
    *   Matches.

    *   Wait, `f` array index.
    *   Matches.

    *   Wait, `f[1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[0]`.
    *   Matches.

    *   Wait, `f[i-1]`.
    *   Matches.

    *   Wait, `f[i]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i+1]`.
    *   Matches.

    *   Wait, `f[i