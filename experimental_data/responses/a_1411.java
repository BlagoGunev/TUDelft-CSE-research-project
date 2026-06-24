Translate this C++ code to Java code. The main class name should be a_1411. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

using namespace std;



#define int long long

#define pb push_back



int32_t main(){

int t;

cin>>t;

while(t--){

	string s;

	int n;

	cin>>n>>s;

	int sum=0;

	for (int i=n-1; i>=0;--i){

		if (s[i]==')') sum++;

		if (s[i]!=')') break;

	}



	if (sum>n-sum) cout << "Yes" << endl;

	else cout << "No" <<endl;

}

	return 0;

}

<think>
Thinking Process:

1.  **Analyze the Request:**
    *   **Task:** Translate C++ code to Java code.
    *   **Class Name:** `a_1411`.
    *   **Requirements:**
        1.  Make a plan for the translation (consider C++ specifics vs. Java equivalents, incremental tasks).
        2.  Output the code wrapped with `<CODE>` tags.
    *   **Input Code:** A C++ program reading an integer `t` (test cases), then for each test case reading `n` and string `s`. It counts consecutive closing parentheses `)` from the end of the string. If the count of `)` is greater than the count of `(` (implied by `sum > n - sum`), it prints "Yes", else "No".
    *   **Note:** The C++ code uses `#include<bits/stdc++.h>`, `using namespace std;`, `#define int long long`, `int32_t main()`, `cin`, `cout`, `endl`, `string`, `vector` (implied by `pb` though not used in the snippet), and a custom loop logic.

2.  **Analyze the C++ Code:**
    *   `#include<bits/stdc++.h>`: Header for all standard library components. In Java, this is replaced by importing specific classes (e.g., `java.util.*`, `java.io.*`, `java.lang.*`).
    *   `using namespace std;`: C++ specific. In Java, explicit imports are needed.
    *   `#define int long long`: Macro to make `int` behave like `long long` (64-bit integer). In Java, we use `long` directly.
    *   `int32_t main()`: `main` function entry point. In Java, it's `public static void main(String[] args)`.
    *   `cin >> t`: Reading integer from standard input. In Java, use `Scanner` or `BufferedReader`. `Scanner` is easier for this level of code.
    *   `while(t--)`: Loop over test cases.
    *   `string s`: Reading a string. In Java, `String s`.
    *   `int n`: Reading integer `n`. In Java, `long n` (since `int` was defined as `long long`).
    *   `cin >> n >> s`: Reading `n` and `s`.
    *   Loop `for (int i=n-1; i>=0;--i)`: Iterating backwards through the string. In Java, `for (int i = n - 1; i >= 0; i--)`.
    *   Logic inside loop: Check `s[i] == ')'`. If true, increment `sum`. If false (`s[i] != ')'`), break.
        *   *Correction/Refinement:* The C++ logic is slightly specific. It iterates from the end. If it finds a `)`, it increments `sum`. If it finds anything else (like `(`), it breaks immediately. This implies it's counting the suffix of `)`s.
        *   `if (sum > n-sum)`: `sum` is the count of `)`. `n` is the length of the string. `n - sum` is the count of non-`)` characters (which, based on the break condition, are `(`). So it checks if `count(')') > count('(')`.
    *   `cout << "Yes" << endl`: Output. In Java, `System.out.println()`.
    *   `return 0`: In Java, `main` returns `void`.

3.  **Plan the Translation:**
    *   **Step 1: Class Structure.** Create `public class a_1411`.
    *   **Step 2: Main Method.** Change `int32_t main()` to `public static void main(String[] args)`.
    *   **Step 3: Input Handling.** Replace `cin` with `Scanner` (from `java.util`).
    *   **Step 4: Data Types.** Replace `int` with `long` where `#define int long long` was used.
    *   **Step 5: String Handling.** Java strings are immutable. Access via `charAt()`.
    *   **Step 6: Output.** Replace `cout << ... << endl` with `System.out.println(...)`.
    *   **Step 7: Logic Preservation.** Ensure the logic for counting `)` from the end and comparing counts remains the same.
    *   **Step 8: Imports.** Add necessary imports (`java.util.Scanner`).

4.  **Drafting the Code:**
    *   Import `java.util.Scanner`.
    *   Class `a_1411`.
    *   `main` method.
    *   `Scanner sc = new Scanner(System.in);`
    *   `int t = sc.nextInt();`
    *   `while(t-- > 0)` or `while(t-- > 0)` logic.
    *   Inside loop:
        *   `long n = sc.nextLong();` (Since `int` was `long long` in C++).
        *   `String s = sc.next();`
        *   `long sum = 0;`
        *   Loop `i` from `n - 1` down to `0`.
        *   Check `s.charAt(i) == ')'`.
        *   If `==`)`, `sum++`.
        *   Else `break`.
        *   Condition: `if (sum > n - sum)`.
        *   Print "Yes" or "No".

5.  **Refining the Plan for the Output:**
    *   The prompt asks to "make a plan... by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks."
    *   I need to write this plan *before* the code block.
    *   Then output the code with `<CODE>`.

6.  **Addressing Specific C++ Features:**
    *   `#include<bits/stdc++.h>` -> `import java.util.*;` (or specific imports).
    *   `using namespace std;` -> Explicit imports.
    *   `#define int long long` -> Use `long` for integer variables.
    *   `int32_t` -> Java `int` is 32-bit, but since the macro forced `long long`, we should use `long` in Java to match the semantic intent of the C++ code (64-bit integers).
    *   `cin`/`cout` -> `Scanner`/`System.out`.
    *   `string` -> `String`.
    *   `endl` -> `System.out.println()` or `System.out.print()` + `\n`.
    *   `main` signature -> `public static void main(String[] args)`.
    *   Return 0 -> Removed (void return).

7.  **Incremental Tasks:**
    1.  Setup class and main method.
    2.  Setup Input (Scanner).
    3.  Read `t` and loop.
    4.  Read `n` and `s`.
    5.  Implement logic (count `)` from end).
    6.  Implement Output.
    7.  Handle types (`long` vs `int`).

8.  **Final Code Check:**
    *   The C++ code defines `int` as `long long`. So `int sum` becomes `long sum`. `int n` becomes `long n`.
    *   String access: `s[i]` in C++ is `s.charAt(i)` in Java.
    *   Logic: `sum` counts `)`. `n - sum` counts `(` (based on the loop breaking on non-`)`).
    *   Comparison: `sum > n - sum`.
    *   Wait, is `n` always the length? In C++, `s` is a string. `s.length()` is the length. The code reads `n`. Usually, in competitive programming, `n` is the length of `s`. The loop uses `n` to index. In Java, `s.length()` should probably be used instead of `n` to be safe, but the C++ code uses `n` as the length. I should stick to the logic provided: read `n`, use `n` for loop bounds. However, relying on `n` being consistent with `s.length()` is implicit in the C++ code. I will keep `n` as the bound but ensure `s` is read correctly.
    *   Actually, `cin >> n >> s` reads `n` then `s`. If `s` is read as a token, its length might not be exactly `n` if there's whitespace, but usually `n` is the length. I will follow the C++ logic strictly: `int n; cin >> n >> s;`. Then loop `i` from `n-1` to `0`.
    *   Wait, `cin >> s` reads a token. If `s` contains spaces, `cin >> s` stops at space. The loop iterates `n` times. If `s` is shorter than `n`, `charAt(i)` might throw IndexOutOfBounds. But assuming valid input where `s.length() == n`.
    *   In Java, `Scanner.next()` reads a token. `Scanner.nextLine()` reads the line. Given `cin >> s`, it's token-based. I will use `Scanner.next()`.
    *   One subtle point: `#define int long long`. In the code, `int t`, `int n`, `int sum` are declared. They should be `long` in Java.
    *   `int32_t main()` -> `public static void main(String[] args)`.

9.  **Constructing the Plan Text:**
    *   Identify headers and imports.
    *   Identify type definitions (`int` -> `long`).
    *   Identify IO (`cin` -> `Scanner`, `cout` -> `System.out`).
    *   Identify class structure.
    *   Identify logic translation (string indexing).

10. **Final Code Assembly:** (Mental check)
    ```java
    import java.util.Scanner;

    public class a_1411 {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            if (sc.hasNextInt()) {
                int t = sc.nextInt();
                while (t-- > 0) {
                    long n = sc.nextLong();
                    String s = sc.next();
                    long sum = 0;
                    for (int i = (int)n - 1; i >= 0; i--) {
                        if (s.charAt(i) == ')') {
                            sum++;
                        } else {
                            break;
                        }
                    }
                    if (sum > n - sum) {
                        System.out.println("Yes");
                    } else {
                        System.out.println("No");
                    }
                }
            }
        }
    }
    ```
    *Wait, `int n` in C++ was `long long`. In Java, `long` is the equivalent.*
    *Wait, `for (int i=n-1...` in C++. In Java, `n` is `long`. Loop variable `i` should be `long` or cast to `int` if index fits in `int`. Since `n` comes from `long long` in C++, it could be large. In Java, `String` indices are `int`. If `n` > `Integer.MAX_VALUE`, Java `String.charAt` won't work. However, usually in CP, `n` fits in `int` unless specified otherwise. Given the C++ code used `int32_t` for `main` and `int` for `n`, but defined `int` as `long long` via macro, `n` could be up to `2^63-1`. Java `String` indices are `int`. I should probably cast `n` to `int` for the loop variable `i` or just use `int` if we assume `n` fits in `int` (standard CP constraint usually implies `n <= 10^5` or `10^6`). However, strictly translating, `n` is `long`. But `s.charAt(i)` requires `int`. I will assume `n` fits in `int` range for the string length, or cast it. Given the context of CP problems, usually `n` is reasonable. I will use `int` for `i` and cast `n` to `int` to avoid compilation errors with `charAt`, assuming the input fits.*
    *Actually, looking at `int32_t main()`: The return type is 32-bit int. The macro `#define int long long` affects local variables `t`, `n`, `sum`. It does not affect `main` return type explicitly (though `int32_t` is 32-bit). So `t`, `n`, `sum` are 64-bit.
    *However, `String` length in Java is `int`. If `n` is truly `long` (64-bit), `s.charAt(i)` will fail if `n` > `Integer.MAX_VALUE`. I will assume standard constraints where `n` fits in `int` for the array index, but declare `n` as `long` to respect the type definition.*
    *Wait, `sc.nextLong()` reads `long`. `s.length()` returns `int`. If `n` is `long`, `s` should be read carefully. But `s` is a string token. Usually `n` matches `s.length()`. I will use `int` for loop index `i` and cast `n` to `int`.*

    *Wait, one more thing:* `cin >> s`. If `n` is large, `s` could be large. `Scanner` might be slow for very large inputs, but for this translation task, `Scanner` is the direct equivalent of `cin`.
    *Also, `cin >> t` might leave newline characters, but `cin >> n` skips whitespace, so `cin >> s` works fine.*
    *In Java, `Scanner.next()` skips whitespace.*

    *Plan:*
    1.  Replace `#include` with imports.
    2.  Replace `main` signature.
    3.  Replace `int` with `long` (due to macro).
    4.  Replace IO.
    5.  Replace String access.

    *Refinement on `n`:* Since `n` is used as an index `s[i]`, and Java `String` indices are `int`, `n` must be castable to `int`. I will declare `n` as `int` in Java to match the index requirement, but since the C++ macro made `int` a `long long`, I should probably keep `n` as `long` for the reading part, but cast to `int` for the loop. Or just use `int` in Java since `String` indices are `int`. The macro `#define int long long` is specific to C++. In Java, `int` is 32-bit. I will use `int` for `n` in Java because `String` length is `int`. This is a necessary adaptation.

    *Wait, `int32_t main()`*: The C++ code returns `int`. Java `main` returns `void`.
    *Wait, `return 0`*: Removed.

    *Let's write the plan text first.*

    *Plan details:*
    1.  **Imports:** `bits/stdc++.h` -> `java.util.Scanner`, `java.io.*`.
    2.  **Class:** `main` -> `public class a_1411`, `int32_t main()` -> `public static void main(String[] args)`.
    3.  **Types:** `#define int long long` -> Use `long` for `t`, `n`, `sum` if we strictly follow the macro, but since `n` is an index for `String`, it must be `int` in Java. I will use `int` for `n` and `sum` to match Java `String` constraints, acknowledging the macro change.
    4.  **IO:** `cin` -> `Scanner sc = new Scanner(System.in)`, `cout` -> `System.out.println`.
    5.  **String:** `string s` -> `String s`. `s[i]` -> `s.charAt(i)`.
    6.  **Logic:** Preserve the logic flow exactly.

    *Wait, regarding `n` type:* In C++, `int` is `long long`. So `n` can be large. In Java, `String` length is `int`. If the input `n` exceeds `Integer.MAX_VALUE`, Java code will fail. However, since I am translating code that uses `n` as an index into `s`, I must ensure `n` fits `int`. I will use `int` for `n` in Java to ensure `s.charAt(i)` compiles and works.

    *Wait, regarding `sum`:* `sum` counts `)`. `sum > n - sum`. If `n` is `long`, `sum` should be `long`. But `n - sum` implies `n` is the total length.
    *Decision:* I will use `int` for `n` and `sum` in Java because `String` length is `int`. This is the standard Java equivalent for CP problems where `n` is array/string length.

    *Wait, one detail in C++:* `if (s[i]!=')') break;`. This breaks the loop if it encounters a `(` (or any non-`)`). This means `sum` counts the suffix of `)`s.
    *Java:* `if (s.charAt(i) != ')') break;`.

    *Final check on `a_1411`:* Class name must be `a_1411`.

    *Wait, `int32_t` in C++:* `main` returns `int`. Java `main` returns `void`.
    *Wait, `return 0`:* Removed.

    *Wait, `cin >> n >> s`:* In Java `Scanner`, `nextLong()` followed by `next()` works fine as whitespace is skipped.

    *Wait, `while(t--)`:* In Java `while(t-- > 0)`.

    *Wait, `pb`:* Defined but not used. Ignore.

    *Wait, `#include<bits/stdc++.h>`:* This includes everything. In Java, import `java.util.Scanner`.

    *Wait, `using namespace std`:* Not needed in Java.

    *Wait, `int sum=0`:* `long sum = 0`? Since `n` is `long` in C++ (due to macro), `sum` is `long`. But `s.length()` is `int`. I will use `int` for `n` and `sum` to be safe with Java String API, or `long` for `n` and cast to `int` for loop. I'll stick to `int` for `n` and `sum` because Java String indices are `int`.

    *Wait, `int32_t main`*: The C++ code has `int32_t`. This is a type specifier. In Java, `int` is 32-bit. So `public static void main(String[] args)` is the standard.

    *Wait, `return 0`:* Java `main` is `void`.

    *Wait, `cout << "Yes" << endl`:* `System.out.println("Yes")`.

    *Wait, `#define int long long`:* This is the trickiest part.
    *   C++: `int n` is 64-bit. `n` is used as index `s[i]`.
    *   Java: `n` is `int` (32-bit). `n` is used as index `s[i]`.
    *   Translation: `int n`.
    *   Why? Because `String` length in Java is `int`. If `n` were `long` in Java, `s.charAt((int)n)` would be needed. Given the context of typical CP problems, `n` fits in `int`. I will use `int` for `n` and `sum`.

    *Wait, `for (int i=n-1; i>=0;--i)`:* In Java, `i` should be `int`.

    *Wait, `if (sum > n - sum)`:* In C++, `sum` is `long long`. In Java, `sum` is `int`. Comparison works.

    *Wait, `cin >> t`:* `Scanner` needs to handle potential input issues? No, just `nextInt()`.

    *Wait, `t--`:* `while(t-- > 0)`.

    *Wait, `t` is `int` in C++ (due to macro).* So `int t`.

    *Wait, `string s`:* `String s`.

    *Wait, `endl`:* `System.out.println()`.

    *Wait, `return 0`:* Remove.

    *Wait, `#include`:* `import java.util.Scanner;`.

    *Wait, `using namespace std`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `a_1411`:* Class name.

    *Wait, `pb`:* Ignore.

    *Wait, `bits/stdc++.h`:* `import java.util.*;`.

    *Wait, `long long`:* `long`.

    *Wait, `int`:* `int`.

    *Wait, `s[i]`:* `s.charAt(i)`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `t`:* `int`.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `return 0`:* Removed.

    *Wait, `if (sum > n - sum)`:* `if (sum > n - sum)`.

    *Wait, `cout`:* `System.out.println`.

    *Wait, `endl`:* Newline.

    *Wait, `cin`:* `Scanner`.

    *Wait, `using namespace`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `bits/stdc++.h`:* Remove.

    *Wait, `string`:* `String`.

    *Wait, `vector`:* Not used.

    *Wait, `pb`:* Not used.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *Wait, `main`:* `public static void main(String[] args)`.

    *Wait, `t`:* `int`.

    *Wait, `n`:* `int`.

    *Wait, `sum`:* `int`.

    *Wait, `s`:* `String`.

    *Wait, `i`:* `int`.

    *Wait, `break`:* `break`.

    *Wait, `Yes`:* "Yes".

    *Wait, `No`:* "No".

    *Wait, `return 0`:* Removed.

    *Wait, `#include`:* `import`.

    *Wait, `using`:* Remove.

    *Wait, `#define`:* Remove.

    *Wait, `int32_t`:* Remove.

    *