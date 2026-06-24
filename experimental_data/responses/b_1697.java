Translate this C++ code to Java code. The main class name should be b_1697. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl '\n'

#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=2e5+10,mod=1e9+7;

signed main()

{

	_

	int n,q;

	cin>>n>>q;

	vector<int> a(n+1),s(n+1);

	int res=0;

	for (int i=1;i<=n;i++) cin>>a[i],res+=a[i];

	sort(a.begin()+1,a.end(),greater());

	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

	while(q--)

	{

		int l,r;

		cin>>l>>r;

		cout<<s[l]-s[l-r]<<endl;

	}

	return 0; 

}

<think>
The user wants me to translate a C++ program to Java.
The main class name should be `b_1697`.

**Plan:**
1.  **Analyze the C++ code:**
    *   `#include <bits/stdc++.h>`: Standard header for competitive programming (includes everything). In Java, we don't need explicit imports for standard IO, but we do need `java.util.Scanner` or `java.io.BufferedReader` / `java.io.StringTokenizer` for input.
    *   `using namespace std;`: Namespace in C++. In Java, we use explicit class names (e.g., `System.out`, `java.util.Arrays`).
    *   `#define int long long`: This defines `int` as `long long`. In Java, we should use `long` instead of `int` where the C++ code uses `int` (since `long long` maps to `long` in Java).
    *   `#define endl '\n'`: Just a newline character. In Java, `System.out.println()` or `PrintWriter.println()`.
    *   `#define _`: Optimizes IO. In Java, this usually means using `BufferedReader` and `StringTokenizer` instead of `Scanner` for performance, or just using `Scanner` if the constraints allow. Given `N=2e5+10`, `Scanner` might be too slow, so `BufferedReader` + `StringTokenizer` is the standard Java translation for competitive programming IO.
    *   `const int N=2e5+10,mod=1e9+7;`: Constants. In Java, `final` variables. `mod` is defined but not used in the logic provided (only `N` is used for array sizing).
    *   `signed main()`: Entry point. In Java, this is `public static void main(String[] args)`.
    *   `vector<int> a(n+1),s(n+1);`: Dynamic arrays. In Java, `int[]`.
    *   `cin>>...`: Input reading. In Java, `BufferedReader` + `StringTokenizer`.
    *   `sort(...)`: Sorting. In Java, `Arrays.sort()`. Note that `Arrays.sort()` sorts in ascending order by default. The C++ code uses `greater()`, so it sorts descending.
    *   `while(q--)`: Loop. In Java, standard `while` loop.
    *   `cout<<...<<endl`: Output. In Java, `System.out.println()`.
    *   `return 0;`: Return statement. In Java, void methods don't need it.

2.  **Specific Translations:**
    *   **IO:** Replace `cin`, `cout` with `BufferedReader` and `PrintWriter` (or `System.out`). `StringTokenizer` is needed for tokenizing input lines.
    *   **Types:** Replace `int` with `long` (since `int` in C++ is mapped to `long long` via the macro).
    *   **Arrays:** `vector<int>` becomes `long[]`. Size `n+1` becomes `n+1`.
    *   **Sorting:** C++ `sort(..., greater())` sorts descending. Java `Arrays.sort(...)` sorts ascending. To get descending, we can sort ascending and iterate backwards, or use `Collections.reverseOrder()` with `Long` objects (which is slower due to boxing). Since the array is primitive `long[]`, we cannot use `Collections.reverseOrder()`. The standard trick is to sort ascending and then access elements from `n` down to `1`.
        *   C++: `sort(a.begin()+1, a.end(), greater())`. This sorts indices `1` to `n` in descending order.
        *   Java: `Arrays.sort(a, 1, n + 1)`. This sorts `a[1]` to `a[n]` in ascending order.
        *   Logic check: The code calculates prefix sums `s`. `s[i]` stores sum of `a[1]...a[i]`.
        *   C++ Logic: `s[i] = s[i-1] + a[i]`. This implies `a` is sorted descending. `s[l] - s[l-r]` calculates sum of `a[l-r+1]...a[l]`.
        *   If `a` is sorted descending in C++, `a[1]` is the largest, `a[n]` is the smallest.
        *   In Java, if we sort ascending, `a[1]` is the smallest, `a[n]` is the largest.
        *   The query is `s[l] - s[l-r]`. This calculates sum of `a[l-r+1]` to `a[l]`.
        *   In the C++ version, `a` is sorted descending. So `a[1] >= a[2] >= ... >= a[n]`.
        *   The sum `s[l] - s[l-r]` is the sum of the largest `r` elements among the top `l` elements.
        *   Wait, let's look closer. `a` is sorted descending. `s` is prefix sum.
        *   `s[l]` is sum of `a[1]...a[l]`. `s[l-r]` is sum of `a[1]...a[l-r]`.
        *   `s[l] - s[l-r]` is sum of `a[l-r+1]...a[l]`.
        *   Since `a` is sorted descending, `a[1]` is max, `a[l]` is the `l`-th largest.
        *   The query asks for the sum of the `r` largest elements from the first `l` elements.
        *   If I sort `a` ascending in Java: `a[1]` is min, `a[n]` is max.
        *   To simulate the logic of "largest `r` elements from first `l` elements" where "first `l`" refers to the largest available elements in the original array `a`:
            *   In C++, `a` is sorted descending. The "first `l`" elements are `a[1]...a[l]`.
            *   In Java, if I sort `a` ascending, `a[1]` is the smallest.
            *   To keep the logic identical, I need to access the "top `l`" elements. In the sorted array (descending), these are indices `1` to `l`. In an ascending array, these are indices `n-l+1` to `n`.
            *   However, simply sorting ascending and iterating backwards is the easiest way to map the indices.
            *   Let's check the query: `s[l] - s[l-r]`.
            *   In C++: `s` is prefix sum of descending `a`. `s[l]` is sum of `a[1]..a[l]`. `s[l-r]` is sum of `a[1]..a[l-r]`. Difference is sum of `a[l-r+1]..a[l]`. These are the `r` largest elements among the top `l`.
            *   In Java: Sort `a` ascending. `a[n]` is largest.
            *   To get the sum of the `r` largest elements among the top `l` (which are now at the end of the array):
                *   The "top `l`" elements are `a[n-l+1]` to `a[n]`.
                *   The "top `r`" elements among those are `a[n-r+1]` to `a[n]`.
                *   Wait, the query asks for sum of `a[l-r+1]...a[l]`.
                *   In the C++ version, indices `1` to `l` contain the largest elements.
                *   In the Java version (ascending sort), indices `n-l+1` to `n` contain the largest elements.
                *   So, the range `[l-r+1, l]` in C++ (1-based) corresponds to `[n-l+1, n]` in Java? No.
                *   Let's trace:
                    *   C++: `a` sorted desc. `a[1]` is max. `a[l]` is `l`-th max. `a[l-r+1]` is `(l-r+1)`-th max.
                    *   Query: Sum of `a[l-r+1]...a[l]`. This is the sum of the `r` largest elements within the set of the first `l` elements.
                    *   Java: `a` sorted asc. `a[n]` is max. `a[n-l+1]` is `l`-th max. `a[n-r+1]` is `(l-r+1)`-th max.
                    *   So the sum should be `sum(a[n-r+1]...a[n])`.
                    *   We need a suffix sum array for this, or just calculate it directly.
                    *   The C++ code uses a prefix sum `s`. `s[i]` stores sum of `a[1]...a[i]`.
                    *   In Java, if we sort ascending, `s[i]` usually stores sum of `a[1]...a[i]` (smallest to largest).
                    *   To match the C++ logic (which selects the largest `r` from top `l`), we need to map indices.
                    *   Actually, we can just reverse the array after sorting to keep the logic identical to C++. Or we can adjust the prefix sum calculation.
                    *   Let's keep it simple: Sort ascending. Then reverse the array (or just iterate backwards).
                    *   Actually, `Arrays.sort` sorts ascending. `a[1]` is smallest. `a[n]` is largest.
                    *   To match C++ `a[1]` being largest: We can reverse `a` after sorting.
                    *   Then `a[1]` is largest. `s` is prefix sum.
                    *   `s[i]` = sum of `a[1]...a[i]`.
                    *   Query `s[l] - s[l-r]` will work exactly as in C++.
                    *   Wait, `s` is defined as `s[i] = s[i-1] + a[i]`.
                    *   If we reverse `a`, `a[1]` is largest.
                    *   So, plan:
                        1. Read `n`, `q`.
                        2. Read `a`.
                        3. Sort `a` (ascending).
                        4. Reverse `a` (so `a[1]` is max).
                        5. Compute prefix sums `s`.
                        6. Process queries.
    *   **Modulo:** `mod` is defined but not used in the snippet. I should keep it or ignore it. The logic doesn't apply modulo. I will keep the constant definition for completeness but not apply it.
    *   **Class Name:** `b_1697`.
    *   **Imports:** `java.util.*`, `java.io.*`.
    *   **Fast IO:** Use `BufferedReader` and `StringTokenizer`.

3.  **Incremental Tasks:**
    *   Step 1: Set up class structure and imports.
    *   Step 2: Implement Fast IO helper or inline logic.
    *   Step 3: Read `n`, `q`.
    *   Step 4: Read array `a`.
    *   Step 5: Sort `a` and compute prefix sums `s`.
    *   Step 6: Implement query loop.
    *   Step 7: Output results.

4.  **Constraints:**
    *   `N=2e5+10`. `long` is sufficient.
    *   `q` is not bounded explicitly but usually `<= N`.
    *   `a[i]` values are not bounded explicitly but `res` is `long`.

5.  **Refinement on Sorting/Indices:**
    *   C++: `vector<int> a(n+1)`. Indices 0 to `n`. Loop `1` to `n`.
    *   Java: `long[] a = new long[n + 1]`. Indices 0 to `n`.
    *   C++: `sort(a.begin()+1, a.end(), greater())`. This sorts `a[1]...a[n]` descending.
    *   Java: `Arrays.sort(a, 1, n + 1)`. This sorts `a[1]...a[n]` ascending.
    *   To match C++ behavior (descending order in `a`), we need to reverse the sorted array `a[1]...a[n]`.
    *   Alternatively, we can calculate suffix sums if we sort ascending, but reversing is closer to the C++ logic (prefix sums on descending array).
    *   Let's reverse `a[1]...a[n]`.
    *   `s` array: `s[i] = s[i-1] + a[i]`.
    *   Query: `s[l] - s[l-r]`.

6.  **Code Structure:**
    *   Class `b_1697`.
    *   `main` method.
    *   `BufferedReader` for input.
    *   `StringTokenizer` for parsing.
    *   `PrintWriter` or `System.out` for output.
    *   `long` for `int` variables.
    *   `Arrays.sort`.
    *   Manual reverse for the array part.

7.  **Edge Cases:**
    *   `l-r` could be 0. `s[0]` should be 0.
    *   C++ code initializes `s` with `s(n+1)`, so `s[0]` is 0 by default.
    *   Java `long[] s = new long[n+1]` initializes to 0.

8.  **Implementation Details:**
    *   Imports: `java.io.*`, `java.util.*`.
    *   Input reading: `BufferedReader` wrapping `InputStreamReader(System.in)`.
    *   `StringTokenizer` for whitespace handling.
    *   `PrintWriter` wrapping `System.out`.
    *   Array reversal: `long temp; for(int i=1; i<=n/2; i++) ...`
    *   Actually, since Java `Arrays.sort` is ascending, `a[1]` is smallest. C++ `a[1]` is largest.
    *   So `a[1]` in C++ corresponds to `a[n]` in Java (after sort).
    *   `a[l]` in C++ corresponds to `a[n - (l - 1)]` in Java?
    *   Let's check indices.
        *   C++: `a` sorted desc. `a[1]` is max. `a[n]` is min.
        *   Java: `a` sorted asc. `a[1]` is min. `a[n]` is max.
        *   Mapping: C++ `a[i]` corresponds to Java `a[n - i + 1]`.
        *   C++ `s[i]` corresponds to Java sum of `a[n - i + 1]...a[n]`.
        *   Wait, `s` in C++ is prefix sum of the sorted array.
        *   In Java, if we keep the array sorted ascending, `s` would be prefix sum of ascending array.
        *   If we reverse `a` to match C++ logic (descending), then `s` is prefix sum of descending array.
        *   Then indices match directly.
        *   Let's reverse `a[1]` to `a[n]`.
        *   `a[1]` becomes `a[n]` (largest).
        *   `a[n]` becomes `a[1]` (smallest).
        *   This matches C++ `a` layout.
        *   Then `s` calculation is identical.
        *   Then query logic is identical.

    *   Wait, is `l-r` valid? `l >= r`? The problem implies `l >= r` usually, or `s[0]` handles `l-r=0`.
    *   If `l < r`, `l-r` is negative. `s` array index out of bounds?
    *   C++ `s` is size `n+1`. Indices `0` to `n`.
    *   If `l-r` is negative, `s[l-r]` would throw in C++ (since `s` is `vector<int> s(n+1)`).
    *   Usually `l >= r` is guaranteed in such problems.
    *   Wait, `s[l-r]` accesses index `l-r`. If `l < r`, index is `< 0`.
    *   In the provided C++ code: `s` is size `n+1`. `l` and `r` are read.
    *   If `l < r`, `l-r` is negative. `s[negative]` is undefined behavior in C++ (segmentation fault or garbage).
    *   However, usually `l >= r` is guaranteed for this type of problem (sum of last `r` elements of first `l`).
    *   Assuming `l >= r` holds based on problem context (likely Codeforces style).
    *   Wait, looking at the code `s[l-r]`. If `l < r`, this is bad.
    *   I will assume `l >= r` is true.

    *   Wait, one more thing: `mod` is defined but not used. I will leave it in or remove it? Better to leave it as it was part of the source, or remove unused variables. I'll keep it to be faithful to the source code structure, but I won't use it in calculation.
    *   Actually, `res` is `long long` in C++ (via macro). In Java `long`.
    *   `res` is calculated but never used in the queries. It seems to be calculating the total sum initially, but the queries use `s` array.
    *   Wait, `res` is calculated: `for (int i=1;i<=n;i++) cin>>a[i],res+=a[i];`.
    *   `s` is calculated: `for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];`.
    *   So `s[n]` is equal to `res`.
    *   `res` is unused. I can remove it or keep it. I will keep the logic to match the C++ code exactly.

    *   Wait, `signed main` -> `public static void main`.
    *   `ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);` -> Fast IO setup.
    *   `endl` -> `System.out.println()` or `out.println()`.

    *   **Sorting Implementation:**
        *   `Arrays.sort(a, 1, n + 1)` sorts `a[1]` to `a[n]` ascending.
        *   C++ sorts descending.
        *   To make `a[1]` the largest element (matching C++), we must reverse the sorted array.
        *   `long temp; for(int i=1; i<=n/2; i++) { temp = a[i]; a[i] = a[n - i + 1]; a[n - i + 1] = temp; }`
        *   Wait, `n` is `2e5`. `n/2` is `1e5`.
        *   Indices `1` to `n`.
        *   `i` goes from `1` to `n/2`. `n - i + 1` goes from `n` down to `n/2 + 1`.
        *   Correct.

    *   **Output:**
        *   `cout` -> `out.println()`.
        *   `endl` -> `println()`.

    *   **IO Class:**
        *   Can use a static inner class `FastReader` or just methods in main.
        *   Given the constraints and the request to translate, keeping it simple in `main` is better unless it gets messy.
        *   I will use `BufferedReader` and `StringTokenizer` directly in `main` to keep it self-contained.

    *   **Variable Names:**
        *   `n`, `q`, `a`, `s`, `l`, `r`, `res`.
        *   `mod` constant.

    *   **Wait, `int` vs `long`:**
        *   C++: `#define int long long`.
        *   Java: `long`.

    *   **Wait, `vector<int> a(n+1)`**:
        *   Java: `long[] a = new long[n + 1];`.

    *   **Wait, `s` array:**
        *   Java: `long[] s = new long[n + 1];`.

    *   **Wait, `sort` range:**
        *   C++: `a.begin()+1` to `a.end()`. Indices `1` to `n`.
        *   Java: `Arrays.sort(a, 1, n + 1)`.

    *   **Wait, `while(q--)`:**
        *   Java: `while(q-- > 0)`.

    *   **Wait, `res`:**
        *   It's computed but not used. I will keep it to match the C++ code exactly.

    *   **Wait, `mod`:**
        *   Defined but not used. I will keep it.

    *   **Wait, `ios` optimization:**
        *   Java doesn't need `ios::sync_with_stdio`. We just use `BufferedReader` which is fast enough.

    *   **Wait, `return 0`:**
        *   Java `main` returns `void`.

    *   **Wait, `signed main`:**
        *   Java `main` is `public static void main(String[] args)`.

    *   **Wait, `using namespace std`:**
        *   Java uses explicit imports.

    *   **Wait, `#define endl '\n'`:**
        *   Java `System.out.println()` handles newline.

    *   **Wait, `cin >> ...`:**
        *   Java `st.nextToken()`.

    *   **Wait, `vector`:**
        *   Java `long[]`.

    *   **Wait, `sort` with `greater`:**
        *   Java `Arrays.sort` is ascending. We reverse.

    *   **Wait, `s[l] - s[l-r]`:**
        *   Java `s[l] - s[l-r]`.

    *   **Wait, `l-r`**:
        *   If `l < r`, `l-r` is negative.
        *   C++ `vector` access with negative index is UB.
        *   Assuming `l >= r`.

    *   **Wait, `N=2e5+10`:**
        *   `int` is fine for `N`.

    *   **Wait, `mod=1e9+7`:**
        *   `long`.

    *   **Wait, `res`:**
        *   `long`.

    *   **Wait, `q`:**
        *   `int` (C++ `int` -> `long long`). Wait, `q` is `int` in code `int n,q;`. But `#define int long long` applies to `n` and `q`. So `q` should be `long` in Java.
        *   `n` is `long`.
        *   `l`, `r` are `int` in code? `int l,r;`. But `#define int long long` applies to them too.
        *   So `l`, `r` should be `long` in Java.
        *   Wait, `l` and `r` are used as indices. `n` is `2e5`. Indices fit in `int` (Java `int` is 32-bit, max `2e9`).
        *   But the macro `#define int long long` makes them `long long` in C++.
        *   In Java, I should use `long` to match the type semantics of `int` in the provided C++ code (which is `long long`).
        *   So `long n`, `long q`, `long l`, `long r`.
        *   Wait, array indices in Java must be `int`.
        *   So `l` and `r` must be cast to `int` when used as indices.
        *   `a` and `s` are `long[]`.
        *   `s[l]` -> `s[(int)l]`.

    *   **Wait, `Arrays.sort`**:
        *   Requires `int[]` or `long[]`. `Arrays.sort(long[])` is available.
        *   Range `1` to `n+1`.

    *   **Wait, `s` calculation**:
        *   `s[i] = s[i-1] + a[i]`.
        *   Loop `1` to `n`.

    *   **Wait, `reverse`**:
        *   Need to reverse `a` after sorting.

    *   **Wait, `out`**:
        *   `PrintWriter`.

    *   **Wait, `BufferedReader`**:
        *   `new BufferedReader(new InputStreamReader(System.in))`.

    *   **Wait, `StringTokenizer`**:
        *   `new StringTokenizer(br.readLine())`.
        *   Need a loop to handle lines if tokens are split.
        *   Standard FastReader pattern.

    *   **Wait, `mod`**:
        *   Not used. I will leave it as a constant.

    *   **Wait, `res`**:
        *   Calculated but unused. I will keep it.

    *   **Wait, `N`**:
        *   `final int N = 200010;` (2e5+10).
        *   But `n` is read from input. `N` is not used in the code logic provided (only array size).
        *   I will keep `N` definition.

    *   **Wait, `signed main`**:
        *   Java `main` doesn't return `int`.

    *   **Wait, `return 0`**:
        *   Remove.

    *   **Wait, `ios::sync...`**:
        *   Just use `BufferedReader`.

    *   **Wait, `endl`**:
        *   `System.out.println()`.

    *   **Wait, `vector`**:
        *   `long[]`.

    *   **Wait, `sort`**:
        *   `Arrays.sort`.

    *   **Wait, `greater`**:
        *   Manual reverse.

    *   **Wait, `l` and `r`**:
        *   `long` in C++ (due to macro). In Java, cast to `int` for array indexing.

    *   **Wait, `l-r`**:
        *   `l` and `r` are `long`. `l-r` is `long`.
        *   `s` is `long[]`. Index must be `int`.
        *   `s[(int)l] - s[(int)(l-r)]`.

    *   **Wait, `res`**:
        *   `long`.

    *   **Wait, `q`**:
        *   `long`. `while(q-- > 0)`.

    *   **Wait, `n`**:
        *   `long`.

    *   **Wait, `a`**:
        *   `long[]`.

    *   **Wait, `s`**:
        *   `long[]`.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `BufferedReader`**:
        *   Need to handle `null` or empty lines?
        *   Standard FastReader logic.

    *   **Wait, `StringTokenizer`**:
        *   Need to check for null.

    *   **Wait, `PrintWriter`**:
        *   `PrintWriter out = new PrintWriter(System.out);`.

    *   **Wait, `flush`**:
        *   `out.flush()` at end.

    *   **Wait, `s[l] - s[l-r]`**:
        *   Check if `l-r` is negative.
        *   Assume `l >= r`.

    *   **Wait, `s` array size**:
        *   `n+1`.

    *   **Wait, `a` array size**:
        *   `n+1`.

    *   **Wait, `res`**:
        *   `long`.

    *   **Wait, `q`**:
        *   `long`.

    *   **Wait, `n`**:
        *   `long`.

    *   **Wait, `l`**:
        *   `long`.

    *   **Wait, `r`**:
        *   `long`.

    *   **Wait, `s`**:
        *   `long[]`.

    *   **Wait, `a`**:
        *   `long[]`.

    *   **Wait, `Arrays.sort`**:
        *   `long[]`.

    *   **Wait, `reverse`**:
        *   `long[]`.

    *   **Wait, `s` loop**:
        *   `1` to `n`.

    *   **Wait, `while` loop**:
        *   `q--`.

    *   **Wait, `out.println`**:
        *   `long`.

    *   **Wait, `return 0`**:
        *   Removed.

    *   **Wait, `ios`**:
        *   Removed (replaced by BufferedReader).

    *   **Wait, `endl`**:
        *   Replaced by `println`.

    *   **Wait, `using namespace std`**:
        *   Removed (explicit imports).

    *   **Wait, `#define`**:
        *   Replaced by `final` constants.

    *   **Wait, `vector`**:
        *   Replaced by `long[]`.

    *   **Wait, `sort`**:
        *   Replaced by `Arrays.sort`.

    *   **Wait, `greater`**:
        *   Replaced by reverse.

    *   **Wait, `cin`**:
        *   Replaced by `StringTokenizer`.

    *   **Wait, `cout`**:
        *   Replaced by `PrintWriter`.

    *   **Wait, `main`**:
        *   Replaced by `public static void main`.

    *   **Wait, `return 0`**:
        *   Removed.

    *   **Wait, `signed`**:
        *   Removed.

    *   **Wait, `const`**:
        *   Replaced by `final`.

    *   **Wait, `int`**:
        *   Replaced by `long`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++) { long temp = a[i]; a[i] = a[n - i + 1]; a[n - i + 1] = temp; }`.

    *   **Wait, `q` loop**:
        *   `while(q-- > 0)`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `s` access**:
        *   `s[(int)l] - s[(int)(l-r)]`.

    *   **Wait, `out.println`**:
        *   `out.println(...)`.

    *   **Wait, `out.flush`**:
        *   `out.flush()`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   Helper method.

    *   **Wait, `nextInt`**:
        *   Helper method.

    *   **Wait, `nextLong`**:
        *   Helper method.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `1e9+7` is `1000000007L`.

    *   **Wait, `N`**:
        *   `2e5+10` is `200010`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `mod`**:
        *   `final long mod = 1000000007L;`.

    *   **Wait, `N`**:
        *   `final int N = 200010;`.

    *   **Wait, `res`**:
        *   `long res = 0;`.

    *   **Wait, `a`**:
        *   `long[] a = new long[n + 1];`.

    *   **Wait, `s`**:
        *   `long[] s = new long[n + 1];`.

    *   **Wait, `s` loop**:
        *   `s[i] = s[i-1] + a[i];`.

    *   **Wait, `reverse`**:
        *   `for (int i = 1; i <= n / 2; i++)`.

    *   **Wait, `q`**:
        *   `long q`.

    *   **Wait, `l`**:
        *   `long l`.

    *   **Wait, `r`**:
        *   `long r`.

    *   **Wait, `out`**:
        *   `PrintWriter out`.

    *   **Wait, `br`**:
        *   `BufferedReader br`.

    *   **Wait, `st`**:
        *   `StringTokenizer st`.

    *   **Wait, `next`**:
        *   `StringTokenizer st = new StringTokenizer(br.readLine())`.

    *   **Wait, `nextLong`**:
        *   `Long.parseLong(st.nextToken())`.

    *   **Wait, `main`**:
        *   `public static void main(String[] args)`.

    *   **Wait, `b_1697`**:
        *   Class name.

    *   **Wait, `