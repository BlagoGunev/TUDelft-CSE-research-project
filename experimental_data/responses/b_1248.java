Translate this C++ code to Java code. The main class name should be b_1248. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
int n;
int a[100005];
int main()
{
    scanf("%d",&n);
    ll sum1=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum1+=a[i];
    }
    sort(a,a+n);
    int t=n/2;
    ll sum=0;
    for(int i=0;i<t;i++)
        sum+=a[i];
    ll ans=sum*sum+(sum1-sum)*(sum1-sum);
    printf("%lld\n",ans);
    return 0;
}

<think>
Thinking Process:

1.  **Analyze the Request:**
    *   **Task:** Translate the provided C++ code to Java code.
    *   **Main Class Name:** `b_1248`.
    *   **Pre-requisite:** Make a plan for the translation (considering C++ specific features, Java equivalents, incremental tasks).
    *   **Output Format:** Code wrapped in `<CODE>` tags at the beginning and end.

2.  **Analyze the C++ Code:**
    *   **Includes:** `<iostream>`, `<algorithm>`, `<cstdio>`.
    *   **Namespace:** `using namespace std;`.
    *   **Types:** `int`, `ll` (defined as `long long`).
    *   **Global Variables:** `n` (int), `a[100005]` (int array).
    *   **Input:** `scanf("%d",&n);`, loop reading `a[i]`.
    *   **Logic:**
        *   Sum all elements (`sum1`).
        *   Sort the array (`sort(a, a+n)`).
        *   Calculate `t = n/2`.
        *   Sum the first `t` elements (`sum`).
        *   Calculate `ans = sum*sum + (sum1-sum)*(sum1-sum)`.
        *   Print `ans`.
    *   **Output:** `printf("%lld\n",ans);`.
    *   **Return:** `0`.

3.  **Plan the Translation:**
    *   **Includes:** Replace C++ headers with Java imports.
        *   `iostream`, `cstdio` -> `java.util.Scanner` (or `java.io.BufferedReader` for speed, but `Scanner` is easier for translation). Given the constraints usually associated with competitive programming (implied by `long long` and array size), `BufferedReader` and `StringTokenizer` is better for performance, but standard `Scanner` is safer for a direct translation unless time limits are tight. However, `scanf` is fast. Let's use `java.util.Scanner` for simplicity as it maps directly to `cin`/`scanf` conceptually, or `BufferedReader` for robustness. Given the prompt asks for translation, `Scanner` is often the direct equivalent for beginners, but `BufferedReader` is the Java equivalent of `scanf`/`printf` for CP. Let's stick to `Scanner` for readability unless the array size suggests otherwise. `a[100005]` suggests N up to 100,000. `Scanner` might be slow. `BufferedReader` is safer. However, for a direct structural translation, `Scanner` is often expected. Let's use `java.util.Scanner` to keep the logic clear, but acknowledge `printf` becomes `System.out.println`.
        *   `algorithm` -> Java doesn't have a direct `sort` for arrays in the same way (Arrays.sort exists for primitives).
    *   **Types:**
        *   `int` -> `int`.
        *   `ll` (`long long`) -> `long`.
    *   **Global Variables:** Java doesn't support global variables in the same way (static members or instance variables). Move `n` and `a` to be static fields or local variables inside `main`. Since `a` is an array, a `static int[] a` or just `int[] a` inside `main` works. Moving `n` to `main` is cleaner.
    *   **Input/Output:**
        *   `scanf` -> `Scanner.nextInt()` or `BufferedReader` parsing.
        *   `printf` -> `System.out.println()`.
        *   `scanf("%d", &n)` -> `n = sc.nextInt()`.
        *   `scanf("%d", &a[i])` -> `a[i] = sc.nextInt()`.
        *   `printf("%lld\n", ans)` -> `System.out.println(ans)`.
    *   **Sorting:**
        *   `std::sort(a, a+n)` -> `Arrays.sort(a)`. Note: `Arrays.sort` on `int[]` uses Dual-Pivot Quicksort.
    *   **Logic:**
        *   `sum1` (long long) -> `sum1` (`long`).
        *   `sum` (long long) -> `sum` (`long`).
        *   `ans` (long long) -> `ans` (`long`).
    *   **Structure:**
        *   Class `b_1248`.
        *   `public static void main(String[] args)`.
        *   Logic inside `main`.

4.  **Incremental Tasks:**
    *   Step 1: Setup class structure and imports.
    *   Step 2: Handle input (`n` and array `a`).
    *   Step 3: Compute `sum1`.
    *   Step 4: Sort array.
    *   Step 5: Compute `sum` (first half).
    *   Step 6: Compute `ans` and print.

5.  **Drafting the Code:**
    *   Imports: `java.util.Scanner`, `java.util.Arrays`.
    *   Class: `public class b_1248`.
    *   Variables: `int n`, `int[] a`.
    *   Input: `Scanner sc = new Scanner(System.in);`. Read `n`. Read `a`.
    *   Logic: `long sum1`, `long sum`.
    *   Sort: `Arrays.sort(a)`.
    *   Calculation: `t = n/2`, loop `0` to `t`, `sum += a[i]`. `ans = sum*sum + (sum1-sum)*(sum1-sum)`.
    *   Output: `System.out.println(ans)`.

    *Refinement on Input:* `Scanner` can be slow for large inputs. `n` is up to 100,000. Reading 100,000 integers with `Scanner` might TLE in strict CP environments. However, since the task is "Translate", using `Scanner` is the most direct semantic equivalent to `scanf` for code readability, unless specified otherwise. But `BufferedReader` is the standard "Java equivalent of C++ IO". Given the instruction is just "Translate", I will use `Scanner` for simplicity as it maps closer to the C++ `scanf` usage pattern for beginners, but I will ensure `long` is used for `long long`. Actually, to be safe and professional (as this looks like a CP problem), `BufferedReader` + `StringTokenizer` is often preferred. However, `Scanner` is the direct mapping of `cin`. `scanf` is fast. Let's use `Scanner` because it's more readable for a direct translation task, but I should be aware of potential performance. Actually, `printf` is used in C++, implying fast I/O might be intended. In Java, `System.out.println` is slower than `PrintWriter`. `Scanner` is slower than `BufferedReader`.
    Let's stick to a standard, robust translation. `Scanner` is the standard translation for `cin`/`scanf` in simple contexts. If I use `BufferedReader`, I need to parse integers manually. To keep the translation clean and recognizable, `Scanner` is usually acceptable for "Translate this code" tasks unless performance constraints are explicitly mentioned. I will use `Scanner` to keep the code structure similar to the C++ logic (streaming input).
    Wait, `long long` in C++ maps to `long` in Java. `int` maps to `int`.
    Array size `100005` -> `new int[100005]`.
    `sort` -> `Arrays.sort`.
    `printf` -> `System.out.println`.

    Let's review the prompt requirements: "make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks."
    I need to write the plan *before* the code block.

    **Plan Details:**
    1.  **Headers:** `iostream`, `algorithm`, `cstdio` -> `java.util.Scanner`, `java.util.Arrays`. `cstdio` is not needed if using `Scanner`.
    2.  **Types:** `ll` (`long long`) -> `long`. `int` -> `int`.
    3.  **Global Variables:** Move `n` and `a` to class scope or inside `main`. Inside `main` is cleaner for Java.
    4.  **Input:** Replace `scanf` with `Scanner.nextInt()`.
    5.  **Sorting:** Replace `std::sort` with `Arrays.sort()`.
    6.  **Output:** Replace `printf` with `System.out.println()`.
    7.  **Class:** Create `public class b_1248`.

6.  **Writing the Code:**
    *   Class `b_1248`.
    *   `Scanner sc`.
    *   `int n`.
    *   `int[] a = new int[100005]`.
    *   `long sum1`.
    *   Loop to read and sum.
    *   `Arrays.sort(a)`.
    *   Loop to sum first half.
    *   Calculate `ans`.
    *   Print `ans`.

    *Wait, one detail:* `n` is global in C++. In Java, I can make it local to `main`.
    *Array size:* C++ uses a fixed size array `a[100005]`. Java uses dynamic arrays `new int[100005]`.
    *Indexing:* C++ arrays are 0-indexed. Java arrays are 0-indexed.
    *Loop:* `for(int i=0;i<n;i++)`. In Java, `for(int i=0; i<n; i++)`.
    *Sort:* `Arrays.sort(a)`. This sorts the whole array. Since `n` is read first, we only need to sort up to `n`. But `Arrays.sort` on the whole array `a` (assuming `a` is sized 100005) might be slower if `n` is small. However, the C++ code passes `a` and `a+n` to sort, which sorts the first `n` elements. In Java, `Arrays.sort(a, 0, n)` is the equivalent.
    *Sum calculation:* `sum1` accumulates all. `sum` accumulates first `t` (where `t = n/2`).
    *Logic:* `ans = sum*sum + (sum1-sum)*(sum1-sum)`.
    *Output:* `System.out.println(ans)`.

    *Refinement on I/O:* Since `n` can be 100,000, `Scanner` might be too slow for Java in competitive programming contexts compared to `BufferedReader`. However, translating `scanf` usually maps to `Scanner` in these contexts unless specified. I will use `Scanner` for clarity of translation, but I'll make sure to import `java.util.Scanner` and `java.util.Arrays`.

    *Wait, `long long` vs `long`:* In Java, `long` is 64-bit signed integer, equivalent to C++ `long long`.
    *`int` vs `int`:* 32-bit.
    *`ll` defined as `long long`:* `long` in Java.

    *Plan Section:* I need to write the plan text first, then the code block.

    **Plan:**
    1.  **Imports:** Map `<iostream>`, `<algorithm>`, `<cstdio>` to `java.util.Scanner` and `java.util.Arrays`.
    2.  **Variables:**
        *   `int n`: Local variable in `main`.
        *   `int a[]`: Local variable in `main` (Java doesn't support global arrays easily in the same way, usually static or local).
        *   `ll`: Map to `long`.
        *   `sum1`, `sum`, `ans`: Map to `long`.
    3.  **Input:** Replace `scanf` with `Scanner.nextInt()`.
    4.  **Sorting:** Replace `std::sort` with `Arrays.sort`. Note that `std::sort` takes pointers (ranges), `Arrays.sort` takes array and indices. Use `Arrays.sort(a, 0, n)`.
    5.  **Output:** Replace `printf` with `System.out.println`.
    6.  **Class Structure:** Wrap logic in `public class b_1248` with `public static void main(String[] args)`.
    7.  **Incremental Steps:**
        *   Setup class and imports.
        *   Setup input reading.
        *   Setup logic (sum, sort, calc).
        *   Setup output.

    **Code Construction:**
    ```java
    import java.util.Scanner;
    import java.util.Arrays;

    public class b_1248 {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            int[] a = new int[100005];
            long sum1 = 0;
            for(int i=0; i<n; i++) {
                a[i] = sc.nextInt();
                sum1 += a[i];
            }
            Arrays.sort(a, 0, n);
            int t = n / 2;
            long sum = 0;
            for(int i=0; i<t; i++) {
                sum += a[i];
            }
            long ans = sum * sum + (sum1 - sum) * (sum1 - sum);
            System.out.println(ans);
        }
    }
    ```
    Check constraints: `n` up to 100,000. `sum1` can be large (100,000 * 100,000 approx 10^10), fits in `long` (max 9*10^18). `ans` fits in `long`.
    Memory: `int[100005]` is fine.

    Wait, one detail in C++: `ll` is defined as `long long`. In Java, `long` is 64-bit. `long long` in C++ is at least 64-bit. So `long` is correct.
    C++ `int` is usually 32-bit. Java `int` is 32-bit.
    C++ `scanf` reads into reference `&n`. Java `sc.nextInt()` returns value.
    C++ `printf` prints `ans` (`long long`). Java `System.out.println` prints `long`.

    One thing: `a` is declared as `int a[100005]`. In Java, `new int[100005]` creates an array of size 100005.
    The loop `for(int i=0; i<n; i++)` works fine.
    `Arrays.sort(a, 0, n)` sorts the first `n` elements.
    The rest of the array is untouched.
    The C++ code does `sort(a, a+n)`. This sorts the subarray `a[0...n-1]`.
    So `Arrays.sort(a, 0, n)` is the correct translation.

    Wait, `scanf("%d",&n)` reads `n`.
    `scanf("%d",&a[i])` reads `a[i]`.
    `printf` prints `ans`.

    Looks good.

    Wait, check the prompt again: "The main class name should be b_1248."
    Check the prompt again: "output the code of the resulting program with token "<CODE>" at the beginning and at the end."
    Check the prompt again: "First, make a plan for the translation... Then, output the code..."

    So the structure should be:
    1. Plan text.
    2. `<CODE>`
    3. Java Code
    4. `</CODE>`

    Let's refine the plan text to be clear and address the specific C++ to Java mapping points.

    **Plan Points:**
    1.  **Headers:** `iostream`, `algorithm`, `cstdio` -> `java.util.Scanner`, `java.util.Arrays`. `cstdio` is not needed as we use `Scanner`.
    2.  **Namespace:** Remove `using namespace std;`. Use explicit imports.
    3.  **Types:** `ll` (long long) -> `long`. `int` -> `int`.
    4.  **Variables:** Global `n` and `a` -> Local variables in `main` (Java doesn't support global variables in the same scope).
    5.  **Input:** `scanf` -> `Scanner`.
    6.  **Sorting:** `std::sort` -> `Arrays.sort`. Note range sorting `a` vs `a+n`.
    7.  **Output:** `printf` -> `System.out.println`.
    8.  **Class:** Create `public class b_1248`.

    **Incremental Tasks:**
    1.  Define class and imports.
    2.  Setup Scanner and read `n`.
    3.  Setup array and read elements.
    4.  Compute `sum1`.
    5.  Sort array.
    6.  Compute `sum` (first half).
    7.  Compute `ans` and print.

    One check: `sum1` is `long long`. `sum` is `long long`. `ans` is `long long`.
    In Java: `long sum1`, `long sum`, `long ans`.
    The calculation `sum*sum` might overflow `int` if `sum` is `int`, but since `sum1` is `long`, `sum` is `long`, so `sum*sum` is `long` arithmetic. In C++, `sum` is `ll`, so it's safe. In Java, `sum` is `long`, so it's safe.
    Wait, in the C++ code: `ll sum1=0;`. `ll sum=0;`. `ll ans=...`.
    In Java: `long sum1 = 0;`. `long sum = 0;`. `long ans = ...`.
    This ensures arithmetic is done in 64-bit.

    Wait, `sum1` is calculated before sorting.
    `sum` is calculated after sorting (sum of first `n/2` elements).
    `sum1 - sum` is sum of remaining elements.
    Logic is preserved.

    Final check on class name: `b_1248`.
    Final check on tags: `<CODE>` and `</CODE>`.

    Wait, regarding `Scanner` performance. For 100,000 integers, `Scanner` is often considered slow in Java CP. However, for a direct translation task, `Scanner` is the semantic equivalent of `cin`/`scanf`. Using `BufferedReader` + `StringTokenizer` is an optimization that changes the implementation style significantly. Given the instruction "Translate this C++ code", preserving the logic flow is priority. `Scanner` is the direct mapping for `scanf`/`cin`. I will stick with `Scanner` to maintain the "translation" feel, even if it's not the most performant CP solution. But wait, `scanf` is fast. `Scanner` is slow. Is it better to use `BufferedReader`?
    If I use `Scanner`, it's a direct translation of the API usage.
    If I use `BufferedReader`, it's a translation of the *intent* (fast I/O).
    Usually, for "Translate to Java", `Scanner` is the standard expectation for `cin`/`scanf` unless specified "optimize". I will use `Scanner` to keep the code structure recognizable as a translation of the provided snippet.
    However, `a` is declared as `int a[100005]`. In Java `new int[100005]`.
    The C++ code reads `n` then reads `n` elements.
    The array size is fixed at 100005.
    I will allocate `new int[100005]`.

    Wait, `t = n/2`. If `n=1`, `t=0`. Loop `0` to `0` (exclusive) -> `sum=0`. Correct.
    If `n=2`, `t=1`. Loop `0` to `1` -> `sum=a[0]`. `sum1-sum` is `a[1]`. Correct.

    Ready to write.

    Wait, one more check on `printf`. `printf("%lld\n", ans)`.
    Java `System.out.println` prints `long` as decimal string. `println` is fine.
    `printf` with `%lld` is specific to C/C++. `System.out.println` is the Java equivalent.

    Wait, one detail on imports. `cstdio` is not needed in Java. `algorithm` is not needed in Java (Arrays is in `util`). `iostream` is not needed (System is in `lang`).
    So imports: `java.util.Scanner`, `java.util.Arrays`.

    Let's assemble the plan text.
    1. Identify C++ specific features: `scanf`, `printf`, `std::sort`, `long long`, global variables.
    2. Map to Java: `Scanner`, `System.out.println`, `Arrays.sort`, `long`, instance/static variables.
    3. Structure: Class definition, main method.
    4. Incremental steps: Imports, Class, Input, Logic, Output.

    Let's write it.
</think>

### Translation Plan

1.  **Headers and Imports:**
    *   C++ `#include <iostream>`, `<algorithm>`, `<cstdio>` are mapped to Java imports.
    *   `iostream` functionality (cin/cout) is replaced by `java.util.Scanner` for input and `java.lang.System.out` for output.
    *   `algorithm` functionality (`std::sort`) is replaced by `java.util.Arrays.sort`.
    *   `cstdio` functionality (`scanf`, `printf`) is replaced by `Scanner` methods and `System.out.println`.

2.  **Data Types:**
    *   C++ `int` maps to Java `int`.
    *   C++ `ll` (defined as `long long`) maps to Java `long`.
    *   Variables `n`, `a`, `sum1`, `sum`, `ans` are declared accordingly.

3.  **Scope and Structure:**
    *   C++ allows global variables (`int n;`, `int a[100005];`). In Java, these are moved to be local variables inside the `main` method or static class members. Moving them to `main` keeps the scope local and cleaner.
    *   The class structure changes to `public class b_1248` with a `public static void main(String[] args)` method.

4.  **Input/Output Logic:**
    *   `scanf("%d",&n)` becomes `sc.nextInt()`.
    *   `scanf("%d",&a[i])` becomes `a[i] = sc.nextInt()`.
    *   `printf("%lld\n",ans)` becomes `System.out.println(ans)`.

5.  **Sorting:**
    *   `std::sort(a, a+n)` becomes `Arrays.sort(a, 0, n)`. This is crucial because Java's `Arrays.sort` takes an array and range indices, whereas C++ sorts the pointer range.

6.  **Incremental Tasks:**
    *   **Step 1:** Define the class `b_1248` and import necessary Java utilities (`Scanner`, `Arrays`).
    *   **Step 2:** Implement the `main` method and initialize the `Scanner`.
    *   **Step 3:** Read `n` and initialize the array `a`.
    *   **Step 4:** Read array elements into `a` and calculate `sum1` simultaneously.
    *   **Step 5:** Sort the array `a` up to index `n`.
    *   **Step 6:** Calculate `sum` for the first half of the sorted array.
    *   **Step 7:** Compute `ans` and print it.
    *   **Step 8:** Close resources (optional for `Scanner` in CP context, but good practice) and return.

<CODE>
import java.util.Scanner;
import java.util.Arrays;

public class b_1248 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] a = new int[100005];
            long sum1 = 0;
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                sum1 += a[i];
            }
            Arrays.sort(a, 0, n);
            int t = n / 2;
            long sum = 0;
            for (int i = 0; i < t; i++) {
                sum += a[i];
            }
            long ans = sum * sum + (sum1 - sum) * (sum1 - sum);
            System.out.println(ans);
        }
    }
}
</CODE>