Translate this C++ code to Java code. The main class name should be c_1419. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

#define int long long

#define endl '\n'

using namespace std;

void solve()

{

    int n,x;cin>>n>>x;

    int a[n],f=0,sum=0,q=0;

    for(int i=0;i<n;i++)

    {

        cin>>a[i];

        f+=(a[i]!=x);

        sum+=x-a[i];

        q|=(a[i]==x);

    }

    if(f==0)cout<<0<<endl;else

    if(sum==0||q)cout<<1<<endl;

    else cout<<2<<endl;

}

int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);cout.tie(nullptr);

    int ut=1;

    cin>>ut;

    while(ut--)solve();

}

<think>
Thinking Process:

1.  **Analyze the Request:**
    *   **Task:** Translate C++ code to Java code.
    *   **Class Name:** `c_1419`.
    *   **Pre-requisite:** Plan the translation (identify C++ specifics, Java equivalents, incremental tasks).
    *   **Output Format:** Start with `<CODE>` and end with `</CODE>`.

2.  **Analyze the C++ Code:**
    *   **Headers:** `#include <bits/stdc++.h>` (Standard header in competitive programming, includes almost everything).
    *   **Macros:**
        *   `#define int long long` (Important: All `int` variables are 64-bit integers).
        *   `#define endl '\n'` (Standard output newline).
        *   `using namespace std;` (Standard namespace usage).
    *   **Function `solve()`:**
        *   Reads `n` and `x`.
        *   Creates array `a` of size `n`.
        *   Iterates `i` from `0` to `n-1`, reading `a[i]`.
        *   Calculates `f` (count of elements not equal to `x`).
        *   Calculates `sum` (sum of `x - a[i]`).
        *   Calculates `q` (bitmask/boolean flag indicating if any element equals `x`).
        *   Logic:
            *   If `f == 0` (all elements equal `x`), print `0`.
            *   Else if `sum == 0` or `q` is true (at least one element equals `x`), print `1`.
            *   Else print `2`.
    *   **Function `main()`:**
        *   `ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);` (IO optimization).
        *   Reads `ut` (number of test cases).
        *   Loops `ut` times, calling `solve()`.
        *   Returns `int32_t`.

3.  **Identify C++ Specifics & Java Translations:**
    *   `#include <bits/stdc++.h>` -> No direct equivalent. Java doesn't need explicit includes for `Scanner` or `System`.
    *   `#define int long long` -> Java `long` (since `int` is 32-bit, `long` is 64-bit). Need to change all `int` to `long` or `long long` equivalent (`long`).
    *   `using namespace std;` -> Not needed in Java (explicit classes).
    *   `cin >> var` -> `scanner.nextLong()` or `scanner.nextInt()`.
    *   `cout << val << endl` -> `System.out.println(val)`.
    *   `ios_base::sync...` -> Java IO is usually slower, but for competitive programming, `BufferedReader` and `StringTokenizer` are preferred for speed over `Scanner`. However, `Scanner` is often sufficient for small constraints unless specified. Given the logic is simple, `Scanner` is fine, but `BufferedReader` is safer for "competitive programming" style translation to ensure performance matches the C++ intent. Let's stick to a standard `Scanner` for simplicity unless performance is critical, but given the C++ `ios_base` optimization, I should probably use `BufferedReader` + `StringTokenizer` to mimic the speed, or just use `Scanner` if the constraints aren't known. Actually, standard practice for translating CP C++ to Java often implies using `Scanner` for simplicity unless strict time limits exist. However, to be robust, I will use `Scanner` but ensure types match `long`. Wait, the C++ code uses `ios_base` optimization. In Java, `Scanner` is slow. To truly translate the *intent* of optimized I/O, I should use `BufferedReader` and `StringTokenizer`.
    *   `main` structure -> `public static void main(String[] args)`.
    *   `solve()` function -> Method inside the class.
    *   `int32_t` -> `int` (Java `int` is 32-bit signed).
    *   `int a[n]` -> `long[] a = new long[n]`.
    *   `f`, `sum`, `q` -> `long` (for `f`, `sum`) and `boolean` (for `q`). Note: `f` is a count, `sum` is a sum. `q` is a flag.
    *   `q |=(a[i]==x)` -> `q = q | (a[i] == x)` (Bitwise OR). In Java, boolean logic is `true | false`? No, `q` is declared as `int` in C++ (`int q=0`). So `q` is actually a bitmask or integer flag. `q |=(...)` sets bits. So `q` should be `int` (or `long`) in Java.
    *   `if(f==0)...` -> Standard `if` statements.
    *   `while(ut--)` -> `while (ut > 0) { ut--; ... }`.

4.  **Plan for Translation:**
    *   **Step 1: Imports.** Remove `<bits/stdc++.h>`. Add `java.util.Scanner` or `java.io.*` + `java.util.*`. Given the optimization in C++, `BufferedReader` is better, but `Scanner` is easier to read. I will use `Scanner` for readability but keep in mind that `long` is used for `int`. Actually, to match the `ios_base` optimization spirit, `BufferedReader` is safer for large inputs. However, for this specific logic (simple array reading), `Scanner` is usually acceptable. Let's use `Scanner` for clarity unless the problem implies strict limits. The prompt asks to translate the code. I will use `java.util.Scanner` for simplicity as it maps closer to `cin` conceptually, even if less performant, unless I want to be pedantic about the `ios` optimization. Let's use `Scanner` but cast correctly. Actually, `BufferedReader` is the standard Java equivalent for CP `cin`. I'll use `Scanner` to keep the code structure closer to the C++ logic (streaming input), but ensure `long` is used for `int`.
    *   **Step 2: Class Structure.** Create `public class c_1419`.
    *   **Step 3: Types.** Change all `int` to `long`.
    *   **Step 4: I/O.** Replace `cin` with `scanner.nextLong()`. Replace `cout` with `System.out.println()`.
    *   **Step 5: Logic.** Copy logic, adjust for Java syntax (e.g., `a[n]` -> `new long[n]`, `while(ut--)` -> `while(ut > 0)`).
    *   **Step 6: Main Method.** Standard `public static void main(String[] args)`.

    *Refinement on IO:* The C++ code explicitly optimizes IO (`ios_base::sync_with_stdio(false); cin.tie(nullptr);`). In Java, `Scanner` is not optimized. To be faithful to the C++ optimization intent, I should use `BufferedReader` and `StringTokenizer`. However, the prompt asks to translate the *code*. Often, simply replacing `cin` with `Scanner` is expected unless specified otherwise. But `ios_base` is specific. I will use `Scanner` for readability but note that for large inputs, `BufferedReader` is better. Actually, to be safe and professional regarding the C++ optimization hint, I will use `BufferedReader` and `StringTokenizer`. It's the direct Java equivalent of fast I/O.

    *Refinement on `q`:* `int q=0; q|=(a[i]==x);`. In C++, `a[i]==x` is `int` (1 or 0). `q` is `int`. In Java, `a[i] == x` is `boolean`. `q |=` expects bitwise OR on integers. So `q` must be `int` in Java. `a[i] == x` needs to be cast to `int` (1 or 0) before OR-ing, or just `q |= (a[i] == x ? 1 : 0)`.

    *Refinement on `sum`:* `sum += x - a[i]`. `sum` is `long`. `x` is `long`. `a[i]` is `long`. This works fine.

5.  **Drafting the Code:**
    *   Class: `c_1419`.
    *   Method: `solve()`.
    *   Variables: `n` (long), `x` (long), `a` (long[]), `f` (long), `sum` (long), `q` (int).
    *   IO: `Scanner` or `BufferedReader`. I'll use `Scanner` for simplicity as it maps 1:1 to `cin` logic, but I will acknowledge the optimization context by ensuring no `System.out.print` buffering issues (though `println` handles it). Actually, standard CP translation usually implies `BufferedReader`. I'll stick to `Scanner` for clarity unless the code is meant to be high-performance. Given the C++ code has explicit IO optimization, using `Scanner` defeats the purpose of that optimization in Java. I will use `BufferedReader` and `StringTokenizer` to respect the `ios_base` optimization intent.

    *Wait, one detail:* `#define int long long`. This means `n`, `x`, `a[i]`, `f`, `sum` are all `long` in Java. `q` is `int` (bitmask). `ut` is `int` (or `long`? `int ut=1`). `int` in C++ is `long long` here. So `ut` should be `long`.
    *Wait, `q` logic:* `q |=(a[i]==x)`. In C++, `a[i]==x` returns `int` (1 or 0). In Java, `a[i]==x` returns `boolean`. `q` is `int`. So `q |= (a[i] == x ? 1 : 0)`.

    *Wait, `main` logic:* `int ut=1; cin>>ut;`. `ut` is `long` (because `int` is `long long`). So `long ut`.

    *Wait, `f` logic:* `f += (a[i]!=x)`. In C++, `a[i]!=x` is `int` (0 or 1). In Java, `a[i]!=x` is `boolean`. So `f += (a[i] != x ? 1 : 0)`.

6.  **Incremental Tasks Plan:**
    1.  Define Class `c_1419`.
    2.  Setup `main` method.
    3.  Implement IO (BufferedReader/StringTokenizer to match C++ optimization).
    4.  Implement `solve` method.
    5.  Translate variable types (`int` -> `long`).
    6.  Translate logic (arrays, loops, conditions).
    7.  Translate output (`cout` -> `System.out.println`).
    8.  Handle test cases loop.

7.  **Final Code Construction:**
    *   Imports: `java.util.*`, `java.io.*`.
    *   Class: `public class c_1419`.
    *   IO: `BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); StringTokenizer st;`
    *   `solve`:
        *   Read `n`, `x`.
        *   Read array `a`.
        *   Loop `0` to `n-1`.
        *   Update `f`, `sum`, `q`.
        *   Print result based on conditions.
    *   `main`:
        *   Setup IO.
        *   Read `ut`.
        *   Loop `ut`.

    *Wait, checking the `q` logic again:* `q |=(a[i]==x)`. In C++, `int` comparison returns `int` (0 or 1). `q` is `int`. `q |= 1` sets the bit. In Java, `a[i] == x` is boolean. `q` is `int`. `q |= (a[i] == x ? 1 : 0)`.
    *Checking `f` logic:* `f += (a[i]!=x)`. In Java, `f` is `long`. `a[i] != x` is boolean. `f += (a[i] != x ? 1 : 0)`.

    *Checking `sum` logic:* `sum += x - a[i]`. `sum` is `long`. `x`, `a[i]` are `long`. This is fine.

    *Checking `if` logic:*
    `if(f==0) cout<<0<<endl; else if(sum==0||q) cout<<1<<endl; else cout<<2<<endl;`
    Note: In C++, `else` attaches to the nearest `if`.
    Java: `if (f == 0) { ... } else { if (sum == 0 || q) { ... } else { ... } }`.

    *Wait, `ut` type:* `int ut=1;`. In C++, `int` is `long long`. So `ut` should be `long`.

    *Wait, `n` size:* `int a[n]`. In Java, `long[] a = new long[n]`.

    *Wait, `ios_base` optimization:* I will use `BufferedReader` and `StringTokenizer` to ensure the performance characteristics of the C++ code are preserved in Java.

8.  **Final Review:**
    *   Class name `c_1419`.
    *   `long` for `int`.
    *   `long` for `f`, `sum`, `n`, `x`, `ut`.
    *   `int` for `q` (since it's a bitmask/flag).
    *   `boolean` logic converted to `int` logic for bitwise OR.
    *   Output format matches.

    *Wait, one edge case:* `sum==0 || q`. In C++, `q` is `int`. If `q` is non-zero (i.e., 1), it's true. In Java, `q` is `int`. So `q != 0` is the check. But `q` is initialized to 0. `q |= (a[i] == x ? 1 : 0)`. So `q` will be 1 if found, 0 otherwise. So `q != 0` is equivalent to `q`. Or just `q > 0`.
    Wait, `if(sum==0||q)`. In C++, `q` is `int`. If `q` is 1, it's true. If `q` is 0, it's false.
    In Java, `q` is `int`. `if (sum == 0 || q != 0)`.

    Let's write the plan and then the code.

    **Plan:**
    1.  **Class Definition:** Create `public class c_1419`.
    2.  **Imports:** Add `java.util.Scanner` or `java.io.*` + `java.util.StringTokenizer`. Since C++ uses `ios` optimization, `BufferedReader` is the correct Java equivalent for speed.
    3.  **Type Conversion:**
        *   C++ `int` (macro `long long`) -> Java `long`.
        *   C++ `int32_t` -> Java `int`.
        *   C++ `bool` (implicit in `==`) -> Java `boolean`.
        *   C++ `int` (for `q`) -> Java `int` (since it stores 0 or 1).
    4.  **IO Translation:**
        *   `cin >> var` -> `tokenizer.nextToken()` (parsed as `long`).
        *   `cout << val << endl` -> `System.out.println(val)`.
        *   `ios_base` sync -> `BufferedReader` usage.
    5.  **Logic Translation:**
        *   Array `a[n]` -> `long[] a = new long[n]`.
        *   Loop `0` to `n` -> `for (int i = 0; i < n; i++)`.
        *   `f += (cond)` -> `f += (cond ? 1 : 0)`.
        *   `q |= (cond)` -> `q |= (cond ? 1 : 0)`.
        *   `if` chain -> Java `if-else` chain.
    6.  **Main Method:** Wrap `solve` in `main` loop `while (ut-- > 0)`.

    **Wait, one nuance:** The C++ code uses `ios_base::sync_with_stdio(false);`. This is crucial for CP. In Java, `Scanner` is slow. `BufferedReader` is fast. I will use `BufferedReader`.
    **Another nuance:** `cin.tie(nullptr);` decouples `cin` from `cout`. In Java, `System.out` is not tied to `System.in`. So standard `System.out.println` is fine.

    **Code Structure:**
    ```java
    import java.io.*;
    import java.util.*;

    public class c_1419 {
        public static void main(String[] args) throws IOException {
            // IO setup
            // Read ut
            // Loop
            // solve
        }

        public static void solve() {
            // Read n, x
            // Read array
            // Logic
            // Print
        }
    }
    ```
    Wait, `solve` method in C++ reads from `cin`. In Java, passing `Scanner` or `BufferedReader` to `solve` is better to avoid static state, but the C++ code uses global/static IO state implicitly (via `cin`). In Java, it's better to pass the IO object to `solve` or make `solve` static and use a static IO object. I will use a static `BufferedReader` instance for simplicity to match the C++ structure where `cin` is global.

    **Wait, `q` variable:** `int q=0; q|=(a[i]==x);`.
    If `a[i] == x`, `a[i] == x` is `true` (1). `q |= 1`.
    If `a[i] != x`, `a[i] == x` is `false` (0). `q |= 0`.
    So `q` is 1 if any element equals `x`.

    **Wait, `f` variable:** `f += (a[i]!=x);`.
    If `a[i] != x`, `a[i] != x` is `true` (1). `f += 1`.
    If `a[i] == x`, `a[i] != x` is `false` (0). `f += 0`.
    So `f` is the count of elements NOT equal to `x`.

    **Wait, `sum` variable:** `sum += x - a[i]`.
    If `a[i] == x`, `x - a[i]` is 0. `sum += 0`.
    If `a[i] != x`, `x - a[i]` is non-zero.

    **Condition:**
    1. `f == 0`: All elements equal `x`. Output `0`.
    2. `sum == 0 || q`: `sum` is 0 implies all `a[i] == x` (since `x - a[i]` sums to 0). `q` is 1 implies at least one `a[i] == x`.
       If `f == 0`, `sum` is 0 and `q` is 1.
       So `f == 0` is checked first.
       If not `f == 0`, then there is at least one element != `x`.
       If `sum == 0` OR `q == 1` (at least one element == `x`): Output `1`.
       Else (all elements != `x` AND sum != 0): Output `2`.

    Wait, logic check:
    If `f == 0`: All `a[i] == x`. Output `0`.
    Else (`f > 0`): Some `a[i] != x`.
      If `sum == 0` (All `a[i] == x`? No, `f > 0` means some `a[i] != x`. If `sum == 0`, then `x - a[i]` must be 0 for all `i`. This implies `a[i] == x` for all `i`. Contradiction with `f > 0`. Wait.
      `sum` is sum of `x - a[i]`.
      If `f > 0`, there is at least one `a[i] != x`. So `x - a[i] != 0` for that `i`.
      So `sum` cannot be 0 if `f > 0`?
      Unless `x - a[i]` is positive for some and negative for others?
      `sum += x - a[i]`.
      If `a[i] > x`, `x - a[i]` is negative.
      If `a[i] < x`, `x - a[i]` is positive.
      So `sum` can be 0 even if `f > 0` (e.g., `x=5`, `a={4, 6}`. `x-a[0]=1`, `x-a[1]=-1`. Sum=0. `f=2`).
      So `sum == 0` allows for `f > 0`.
      `q` is 1 if any `a[i] == x`.
      So if `sum == 0` OR `q == 1`, output `1`.
      Else (sum != 0 AND q == 0), output `2`.

    Okay, logic holds.

    **Translation Details:**
    *   `int` -> `long`.
    *   `bool` -> `boolean` (but used in arithmetic `f += ...` -> ternary).
    *   `int32_t` -> `int`.
    *   `cin` -> `br.readLine()` + `StringTokenizer`.
    *   `cout` -> `System.out.println`.
    *   `ios` -> `BufferedReader`.

    **Class Name:** `c_1419`.

    **Plan Section:**
    I will write the plan first as requested, then the code.
    Wait, the prompt says: "First, make a plan for the translation... Then, output the code...".
    So I should output the plan text, then the code block.
    Wait, "output the code of the resulting program with token '<CODE>' at the beginning and at the end."
    Does it mean the whole response should be the plan and then the code? Or just the code?
    "First, make a plan... Then, output the code...".
    Usually, this means I write the plan in text, then the code block.
    But the instruction says "output the code... with token...".
    It might mean the final output should contain the code block.
    I will provide the plan in text, then the code block.

    Wait, looking closely: "First, make a plan... Then, output the code...".
    Okay, I will write the plan, then the code block.
    However, often these prompts want ONLY the code block if specified "output the code...".
    But it says "First, make a plan...".
    I will include the plan as text before the code block.

    Wait, re-reading: "Then, output the code of the resulting program with token '<CODE>' at the beginning and at the end."
    This implies the final output should contain the code block. I can include the plan before it.

    Let's refine the Java IO.
    Using `Scanner` is safer for translation fidelity unless performance is key.
    But `ios_base` optimization is explicit.
    I'll use `BufferedReader` + `StringTokenizer` to respect the optimization.
    I'll create a `FastReader` class or just put logic in `main`.
    Since the C++ code uses a `solve()` function that reads from `cin`, I should make `solve` accept the IO object or use a static IO object.
    To keep it simple and close to C++ structure (where `cin` is global), I will use a static `BufferedReader` in the class `c_1419`.

    Wait, `q` is `int`. `q |=(a[i]==x)`.
    In Java: `int q = 0; q |= (a[i] == x ? 1 : 0);`.

    Wait, `f` is `long`. `f += (a[i]!=x)`.
    In Java: `long f = 0; f += (a[i] != x ? 1 : 0);`.

    Wait, `sum` is `long`. `sum += x - a[i]`.
    In Java: `long sum = 0; sum += x - a[i];`.

    Wait, `n` is `long`. `int a[n]` -> `long[] a = new long[(int)n]`.
    Wait, `n` is `long`. Array size must be `int` in Java.
    So `long n` -> `int n` for array indexing?
    In C++, `int a[n]` is a VLA (Variable Length Array), `n` is `long long` due to macro.
    In Java, array size must be `int`.
    So `n` must be cast to `int` for `new long[n]`.
    `long n` -> `long`. `long[] a = new long[(int)n]`.
    Loop `i` from 0 to `n`. `i` should be `int` for array index.
    So `int i`.
    Wait, `n` is `long` in C++.
    If `n` is very large (larger than `Integer.MAX_VALUE`), Java `long[]` is not possible.
    But `n` is `long long`.
    In Java, we can't create an array of size `Long.MAX_VALUE`.
    However, standard CP constraints usually limit `n` to `10^5` or `10^6`.
    I will assume `n` fits in `int`.
    So I will change `int a[n]` to `long[] a = new long[(int)n]`.
    Loop `for(int i=0; i<n; i++)` -> `for(int i=0; i<n; i++)`. (Java `int` index).
    Since `n` is `long`, `i` should be `int` or `long`. If `n` fits in `int`, `int` is fine.
    Given the C++ macro `int long long`, `n` is 64-bit.
    If I use `int` for `n` in Java, it limits `n` to `2*10^9`.
    I will cast `n` to `int` for array creation and loop index, assuming valid input size.

    Wait, `ut` is `int` (1). `cin >> ut`.
    `int ut` in C++ is `long long`.
    So `long ut`.
    Loop `while(ut--)`.
    In Java: `while (ut-- > 0)`.

    Okay, ready to write.

    **Plan:**
    1.  **Class Structure:** Create `public class c_1419`.
    2.  **Imports:** Add `java.io.*` and `java.util.*` to support `BufferedReader`, `StringTokenizer`, `InputStreamReader`.
    3.  **IO Handling:** Replace `ios_base` optimization and `cin`/`cout` with `BufferedReader` and `StringTokenizer`. Use `System.out.println` for output.
    4.  **Type Conversion:**
        *   Replace `int` (defined as `long long`) with Java `long`.
        *   Replace `int32_t` with Java `int`.
        *   Replace C++ `bool` logic (implicit in `==`, `!=`) with Java `boolean` expressions, casting to `int` (0/1) where needed for bitwise operations (`f +=`, `q |=`).
        *   Handle Array Declaration: `int a[n]` becomes `long[] a = new long[(int)n]`.
    5.  **Logic Translation:**
        *   `solve()` method inside class.
        *   `main()` method calls `solve()` inside a loop.
        *   Adjust `if-else` logic to Java syntax.
    6.  **Incremental Tasks:**
        *   Step 1: Define class and imports.
        *   Step 2: Implement `main` with IO setup.
        *   Step 3: Implement `solve` with variable declarations.
        *   Step 4: Implement reading loop and logic.
        *   Step 5: Implement output logic.
        *   Step 6: Combine and test mentally.

    **Code Structure:**
    ```java
    import java.io.*;
    import java.util.*;

    public class c_1419 {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer st = new StringTokenizer("");

        public static void main(String[] args) throws IOException {
            // ...
        }

        static void solve() {
            // ...
        }
    }
    ```
    Wait, `solve` reads from `cin`. In Java, I need to pass the tokenizer or read from the static `st`.
    I'll make a helper `next()` method.

    **Wait, one more thing:** `cin.tie(nullptr)`. In Java, `System.out` is not tied to `System.in`. So `println` is fine.
    **`ios_base::sync_with_stdio(false)`**: In Java, `BufferedReader` is already fast.

    **Wait, `q` logic:** `q |=(a[i]==x)`.
    If `a[i] == x`, `a[i] == x` is `true`. `q |= 1`.
    If `a[i] != x`, `a[i] == x` is `false`. `q |= 0`.
    So `q` becomes 1 if any match.
    In Java: `q |= (a[i] == x ? 1 : 0)`.

    **Wait, `f` logic:** `f += (a[i]!=x)`.
    In Java: `f += (a[i] != x ? 1 : 0)`.

    **Wait, `sum` logic:** `sum += x - a[i]`.
    In Java: `sum += x - a[i]`.

    **Wait, `if` logic:**
    `if(f==0) cout<<0<<endl; else if(sum==0||q) cout<<1<<endl; else cout<<2<<endl;`
    In Java:
    ```java
    if (f == 0) {
        System.out.println(0);
    } else if (sum == 0 || q != 0) {
        System.out.println(1);
    } else {
        System.out.println(2);
    }
    ```

    **Wait, `n` type:**
    `int n` in C++ is `long long`.
    In Java, array size must be `int`.
    I will cast `n` to `int`. `long n`. `long[] a = new long[(int)n]`.
    Loop `int i`. `i < n`.
    This assumes `n` fits in `int`. If `n` exceeds `Integer.MAX_VALUE`, this fails.
    But standard CP problems usually fit in `int`. I'll proceed with this assumption.

    **Wait, `ut`:** `int ut=1`. `cin>>ut`.
    In C++, `int` is `long long`. So `long ut`.
    In Java: `long ut`.
    Loop `while (ut-- > 0)`.

    **Wait, `st` handling:**
    Need to handle `nextToken()` properly.
    ```java
    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    ```
    Need to handle `null` if EOF.
    But `ut` controls the loop.

    Okay, ready to generate.
</think>

### Translation Plan

1.  **Class Structure:**
    *   Define the Java class `c_1419`.
    *   Create a `main` method as the entry point.
    *   Implement the `solve` method to encapsulate the logic for a single test case.

2.  **Imports:**
    *   Replace `#include <bits/stdc++.h>` with standard Java imports: `java.io.*` and `java.util.*` to handle Input/Output (`BufferedReader`, `StringTokenizer`, `InputStreamReader`) and other utilities.

3.  **Type Mapping:**
    *   **`int` (C++)**: The C++ code uses `#define int long long`. In Java, `int` is 32-bit. To match the C++ semantics, all variables defined as `int` (like `n`, `x`, `f`, `sum`, `ut`, `a`) must be mapped to Java's `long` (64-bit).
    *   **`int32_t` (C++)**: Mapped to Java's `int` (32-bit).
    *   **`bool` (C++)**: C++ `bool` expressions (like `a[i] == x`) return `int` (0 or 1) in arithmetic contexts. In Java, this returns `boolean`. We must explicitly cast to `int` (0 or 1) when used in arithmetic or bitwise operations (e.g., `f += ...`, `q |= ...`).
    *   **`endl` (C++)**: Mapped to `System.out.println()` in Java.

4.  **Input/Output (IO) Optimization:**
    *   The C++ code uses `ios_base::sync_with_stdio(false); cin.tie(nullptr);` for fast I/O.
    *   In Java, `java.util.Scanner` is slow. To maintain performance parity, we use `BufferedReader` and `StringTokenizer`.
    *   `cin >> var` is replaced by a helper method `nextLong()` that reads from `BufferedReader`.
    *   `cout << val << endl` is replaced by `System.out.println(val)`.

5.  **Logic Translation:**
    *   **Array Declaration**: `int a[n]` (C++) is a Variable Length Array. Java requires explicit size at declaration. Since `n` is `long`, we cast it to `int` for array sizing: `long[] a = new long[(int)n]`.
    *   **Loop**: `for(int i=0;i<n;i++)` becomes `for(int i=0; i<n; i++)`.
    *   **Bitwise/Arithmetic Logic**:
        *   `f += (a[i]!=x)` becomes `f += (a[i] != x ? 1 : 0)`.
        *   `q |=(a[i]==x)` becomes `q |= (a[i] == x ? 1 : 0)`.
        *   `sum += x - a[i]` remains similar but with `long` types.
    *   **Control Flow**: The `if-else` chain is translated directly to Java `if-else if-else` structure.
    *   **Main Loop**: `while(ut--)` becomes `while (ut-- > 0)`.

6.  **Incremental Tasks:**
    *   Step 1: Set up imports and class definition.
    *   Step 2: Implement `main` method with `BufferedReader` setup.
    *   Step 3: Implement `solve` method with variable declarations.
    *   Step 4: Implement input reading loop inside `solve`.
    *   Step 5: Implement calculation logic (`f`, `sum`, `q`).
    *   Step 6: Implement output logic and test case loop in `main`.

<CODE>
import java.io.*;
import java.util.*;

public class c_1419 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");

    static String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static long nextLong() throws IOException {
        String s = next();
        if (s == null) return 0; // Should not happen based on problem logic
        return Long.parseLong(s);
    }

    static void solve() throws IOException {
        long n = nextLong();
        long x = nextLong();

        long[] a = new long[(int)n];
        long f = 0;
        long sum = 0;
        int q = 0;

        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
            f += (a[i] != x ? 1 : 0);
            sum += x - a[i];
            q |= (a[i] == x ? 1 : 0);
        }

        if (f == 0) {
            System.out.println(0);
        } else if (sum == 0 || q != 0) {
            System.out.println(1);
        } else {
            System.out.println(2);
        }
    }

    public static void main(String[] args) throws IOException {
        long ut = 1;
        String s = next();
        if (s != null) {
            ut = Long.parseLong(s);
        }
        while (ut-- > 0) {
            solve();
        }
    }
}
</CODE>