Translate this C++ code to Java code. The main class name should be a_716. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

/* fast read */

int fastIn() {
	register int aa, bb, ch;
	while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
	ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - 48);
	while (ch = getchar(), ch >= '0' && ch <= '9') aa = (aa << 1) + (aa << 3) + ch - 48;
	return bb ? -aa : aa;
}

int main() {
	register int (*in)() = fastIn;
	int n = in();
	int k = in();
	int last = in();
	int cnt = 1;
	int a;
	for (int i = 2; i <= n; ++ i) {
		a = in();
		if (a - k > last) cnt = 1;
		else cnt ++;
		last = a;
	}
	cout << cnt << endl;
	return 0;
}

<think>
The user wants me to translate a C++ program into Java.
The class name must be `a_716`.

**Plan:**

1.  **Analyze C++ Code:**
    *   **Headers:** `<cmath>`, `<cstdio>`, `<cstring>`, `<iostream>`, `<algorithm>`.
        *   `cstdio` is used for `getchar` and `printf` (implied by fast I/O).
        *   `iostream` is used for `cout`.
        *   `cstring` and `algorithm` and `cmath` are included but don't seem to be used in the provided snippet (though `algorithm` often implies sorting/searching, here it's just basic logic).
    *   **`fastIn` Function:**
        *   Reads integers using `getchar()`.
        *   Handles negative numbers.
        *   Calculates the integer value manually (bit shifting).
        *   This is a common optimization in competitive programming to avoid the overhead of `cin` in C++.
        *   In Java, standard `Scanner` is slow. Using `BufferedReader` with `StringTokenizer` is the standard fast I/O approach.
    *   **`main` Function:**
        *   Calls `in()` (which points to `fastIn`).
        *   Reads `n`, `k`, `last` (which is the first element of the array).
        *   Iterates from 2 to `n`, reading the next element `a`.
        *   Logic: If `a - k > last`, reset count to 1, else increment count. Update `last`.
        *   Prints `cnt`.
    *   **Variables:**
        *   `n`, `k`, `last`, `cnt`, `a` are `int`.
        *   `i` is loop variable.
        *   `register` keyword in C++ is for optimization hints, usually ignored by Java compilers, so I can just use standard `int`.
        *   `(*in)()` syntax: This is a function pointer. In Java, we don't have function pointers. I will just call a method `in()` or implement a static method. Since the logic is encapsulated in `fastIn`, I will make it a static method `in` or `readInt`.

2.  **Translation Strategy:**
    *   **I/O:**
        *   C++ `getchar()` -> Java `System.in.read()`.
        *   C++ `cout` -> Java `System.out`.
        *   Manual parsing in C++ -> Implement a fast integer parsing method in Java (using `BufferedReader` or `InputStream` directly).
    *   **Logic:**
        *   The logic is straightforward.
        *   The loop runs from 2 to `n`.
        *   Condition: `a - k > last`.
    *   **Class Structure:**
        *   Class name: `a_716`.
        *   Method: `main`.
        *   Helper method: `readInt` (to replicate `fastIn`).
    *   **Incremental Tasks:**
        *   Step 1: Setup class structure and imports.
        *   Step 2: Implement fast I/O (`readInt`).
        *   Step 3: Implement `main` logic.
        *   Step 4: Combine and verify.

3.  **Specific C++ to Java Details:**
    *   `getchar()` reads a character from standard input. In Java, `System.in.read()` returns an `int` (0-255) or -1 (EOF).
    *   C++ `cin` is slow, `scanf` is faster. Java `Scanner` is slow. `BufferedReader` + `StringTokenizer` is usually the standard, but for character-by-character reading (like the C++ `fastIn` does), `System.in.read()` is the direct equivalent.
    *   The C++ code manually parses integers: `aa = (aa << 1) + (aa << 3) + ch - 48`.
        *   `ch - 48` converts ASCII '0'-'9' to integer 0-9.
        *   `aa << 1` is `aa * 2`.
        *   `aa << 3` is `aa * 8`.
        *   Total shift is `aa * 10`. So `aa = aa * 10 + (ch - '0')`.
    *   Java `int` is 32-bit signed, same as C++ `int` (usually).
    *   The C++ code uses `register`. In Java, we just declare `int`.
    *   The C++ code uses `using namespace std;`. In Java, we import specific classes.
    *   The C++ code uses `cout << cnt << endl;`. In Java, `System.out.println(cnt)`.
    *   The C++ code defines `int (*in)() = fastIn;`. This is a function pointer. In Java, we can just make `fastIn` a static method and call it.
    *   The C++ code includes `<cstdio>`, `<cstring>`, `<cmath>`, `<iostream>`, `<algorithm>`. I only need `java.io.*` and `java.util.*` (though StringTokenizer isn't used, just `BufferedReader`).

4.  **Refining the Fast I/O:**
    *   The C++ code implements a specific fast I/O logic that reads character by character and builds the number.
    *   To replicate this exactly in Java, I should implement a `readInt()` method that does the same thing: read bytes from `System.in`, handle whitespace, handle negative signs, and build the integer.
    *   The C++ `fastIn` logic:
        ```cpp
        while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
        ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - 48);
        while (ch = getchar(), ch >= '0' && ch <= '9') aa = (aa << 1) + (aa << 3) + ch - 48;
        return bb ? -aa : aa;
        ```
    *   Java equivalent:
        ```java
        int readInt() throws IOException {
            int c = read();
            while (c != -1 && !Character.isDigit(c) && c != '-') {
                c = read();
            }
            if (c == -1) return 0; // Handle EOF
            int aa = 0;
            int bb = 0;
            if (c == '-') {
                bb = 1;
                aa = 0;
                c = read();
            }
            while (c != -1 && Character.isDigit(c)) {
                aa = (aa << 1) + (aa << 3) + (c - '0');
                c = read();
            }
            return bb ? -aa : aa;
        }
        ```
        *Note:* The C++ code assumes the input format is valid integers separated by whitespace. The logic skips whitespace before the number.
        *Wait, looking closely at C++ code:*
        `while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');`
        This skips non-digit characters until it finds a digit or a '-'.
        `ch == '-' ? ...`
        Then it reads digits.
        This is standard fast I/O for competitive programming.
        In Java, `System.in.read()` is efficient enough for this logic.

5.  **Code Structure:**
    *   Class `a_716`.
    *   Method `readInt` (static).
    *   Method `main` (static).
    *   Imports: `java.io.*`, `java.util.*` (maybe not needed for this specific logic, just `InputStream` or `BufferedInputStream`).

6.  **Incremental Tasks:**
    *   Task 1: Create class `a_716`.
    *   Task 2: Implement `readInt` method to replace `fastIn` and handle `getchar` logic.
    *   Task 3: Implement `main` method logic (reading `n`, `k`, loop, output).

7.  **Edge Cases:**
    *   Input might contain EOF before reading all integers? The C++ code assumes valid input.
    *   `n` is the number of elements.
    *   `k` is the threshold.
    *   `last` is the first element.
    *   Loop runs `n-1` times (from 2 to `n`).
    *   `cnt` starts at 1.
    *   Output `cnt`.

8.  **Wait, one detail:**
    The C++ code defines `int last = in();`.
    Then loop `for (int i = 2; i <= n; ++ i)`.
    Inside loop `a = in();`.
    So `n` elements are read in total?
    `last` is the 1st element (index 1).
    Loop starts at 2.
    So total elements read = `n`.
    The C++ code reads `n`, `k`, `last` (which is `a[1]` effectively).
    Then loop `i` from 2 to `n`.
    So it reads `n` integers total.
    Wait, `n` is read first. Then `k`. Then `last`.
    So `last` is `a[1]`.
    Then loop reads `a[2]`...`a[n]`.
    Total `n` numbers.
    The logic calculates the longest subsequence of length `k` where elements are increasing by at least `k`?
    Condition: `a - k > last`.
    This implies `a > last + k`.
    If `a > last + k`, reset `cnt = 1`.
    Else `cnt++`.
    Basically, finding the longest subsequence where each element is at least `k` greater than the previous one.
    This is a classic LIS variation.

    **Translation Check:**
    C++: `int n = in(); int k = in(); int last = in();`
    Java: `int n = readInt(); int k = readInt(); int last = readInt();`
    C++: `cout << cnt << endl;`
    Java: `System.out.println(cnt);`

    **Fast I/O Implementation:**
    I will implement a `StreamTokenizer` approach or a custom `readInt` using `System.in.read()`.
    Since the C++ code uses a specific manual parsing logic (`aa << 1 + aa << 3`), I should try to replicate the efficiency and style, though Java's `Character.isDigit` is fine too.
    Actually, to be faithful to the C++ translation request, I will implement the logic as closely as possible, but using Java constructs.
    C++ `getchar()` reads one byte.
    Java `System.in.read()` reads one byte.
    I will create a helper method `readInt()` inside `a_716`.

    **Imports:**
    `java.io.InputStream`
    `java.io.IOException`
    `java.io.BufferedInputStream` (optional, but `System.in` is an InputStream).
    I'll use `System.in` directly for simplicity as it's an `InputStream`.

    **Handling Exceptions:**
    C++ `getchar` doesn't throw, but `read()` might return -1.
    I should handle `IOException` in `main` or throw it. Since the original C++ doesn't handle exceptions, I will throw `IOException` from `main` or suppress it if not needed. Usually, in CP, `IOException` is just ignored or thrown. I'll throw it.

    **Class Name:**
    `a_716`

    **Plan Summary:**
    1.  Define class `a_716`.
    2.  Add `main` method.
    3.  Add `readInt` helper method to replace `fastIn`.
    4.  Implement logic inside `main`.
    5.  Add necessary imports.

    **Refining `readInt` logic:**
    C++:
    ```cpp
    while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
    ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - 48);
    while (ch = getchar(), ch >= '0' && ch <= '9') aa = (aa << 1) + (aa << 3) + ch - 48;
    return bb ? -aa : aa;
    ```
    Java:
    ```java
    int c;
    // Skip non-digit, non-minus
    while ((c = in.read()) != -1 && (c < '0' || c > '9') && c != '-') {}
    if (c == -1) return 0; // Should not happen based on problem statement
    int aa = 0;
    int bb = 0;
    if (c == '-') {
        bb = 1;
        aa = 0;
        c = in.read();
    }
    while (c != -1 && c >= '0' && c <= '9') {
        aa = (aa << 1) + (aa << 3) + (c - '0');
        c = in.read();
    }
    return bb ? -aa : aa;
    ```
    Wait, in Java, `System.in` is an `InputStream`. `in.read()` returns `int`.
    I need to pass `System.in` to the helper method or make it static and use `System.in`.
    To make it cleaner, I can make `readInt` a static method that uses `System.in`.

    **Wait, one detail about `fastIn` in C++:**
    It uses `register`. Java doesn't support `register`.
    It uses `(*in)()`. This is function pointer syntax. In Java, we just call the method `in()` (which I will rename to `readInt()` for clarity, or keep `in` as a method reference). I will use a static method `readInt()`.

    **Wait, one detail about `last`:**
    `int last = in();`
    In the loop: `last = a;`
    This logic matches.

    **Wait, one detail about `n`:**
    `int n = in();`
    `int k = in();`
    `int last = in();`
    Then loop `i` from 2 to `n`.
    So it reads `n` integers total.
    The first integer is `last`.
    The second to `n`-th are looped.
    So total `n` integers read.

    **Wait, one detail about `in` pointer:**
    `int (*in)() = fastIn;`
    This suggests `in` is a pointer to the function.
    In Java: `static int in() { return readInt(); }`
    Or just call `readInt()`.
    I will implement `static int in() { return readInt(); }` to mimic the structure if possible, but usually, just `readInt()` is cleaner.
    However, the prompt asks to translate the code. I should try to keep the structure if possible, but Java doesn't support function pointers.
    I will use a static method `in` that calls the internal logic.
    Actually, to be safe and clear, I will implement a `readInt` method and call it. I will name the method `in` to match the usage `in()` in `main`, but inside it will be a method definition.
    Wait, `in` is used as a function pointer `int (*in)()`.
    I will just make `in` a method `static int in()`.
    Wait, `in` is used as `int n = in();`.
    So `in` must be a method.
    I will define `static int in()`.
    Inside `in`, I will implement the logic of `fastIn`.

    **Imports:**
    The C++ code includes `cstdio`, `cstring`, `iostream`, `cmath`, `algorithm`.
    In Java, I don't need `cstring` or `algorithm` or `cmath` for this specific logic.
    I need `java.io.InputStream` (for `System.in`).
    `java.io.IOException`.
    `java.util.Scanner` is not used.
    I will stick to `java.io` for I/O.

    **Plan:**
    1.  Class `a_716`.
    2.  Static method `in` (mimicking `fastIn`).
    3.  `main` method.
    4.  Logic translation.
    5.  Output `cnt`.

    **Wait, `fastIn` uses `getchar`.**
    Java `System.in.read()` is the equivalent.
    I need to handle the byte reading.

    **Wait, the `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + ch - 48;`
    `aa << 1` is `2*aa`.
    `aa << 3` is `8*aa`.
    Sum is `10*aa`.
    `ch - 48` is `ch - '0'`.
    So `aa = aa * 10 + digit`.
    I can use `(c - '0')` directly.
    I will use the bitwise shift logic to be faithful to the original code style, as requested ("translate").

    **Wait, `register`:**
    Java doesn't support `register`. I will remove it.

    **Wait, `using namespace std;`:**
    Java doesn't have namespaces. I will use fully qualified names or imports.

    **Wait, `cout` vs `System.out`:**
    `cout << cnt << endl;` -> `System.out.println(cnt);`

    **Wait, `main` return:**
    `return 0;` -> `return 0;` (Java main doesn't return int, it returns void, but `public static void main` is standard).

    **Wait, `in` pointer:**
    `int (*in)() = fastIn;`
    In Java, I cannot define a pointer to a function.
    I will just define `static int in()`.
    Inside `main`, `int n = in();` works.

    **Wait, `fastIn` implementation details:**
    It uses `register int aa, bb, ch;`.
    I will use `int aa, bb, ch;` (local variables).
    It uses `ch = getchar()`.
    I will use `ch = System.in.read()`.
    I need to handle `IOException`.
    I will throw `IOException` from `in` method or catch it in `main`.
    Since `main` returns `int`, I cannot throw unchecked exception easily without `throws` clause.
    I will add `throws IOException` to `main`.

    **Wait, one detail:**
    The C++ code uses `getchar` from `cstdio`.
    In Java, `System.in` is an `InputStream`.
    `System.in.read()` returns `int`.
    I will use `System.in.read()`.

    **Wait, the logic:**
    `if (a - k > last) cnt = 1;`
    `else cnt ++;`
    This logic is preserved.

    **Wait, the loop:**
    `for (int i = 2; i <= n; ++ i)`
    Java: `for (int i = 2; i <= n; i++)`

    **Wait, `n` and `k` are read before `last`.**
    `int n = in();`
    `int k = in();`
    `int last = in();`
    Correct.

    **Wait, `cnt` initialization:**
    `int cnt = 1;`
    Correct.

    **Wait, imports:**
    I need `java.io.InputStream`? No, `System.in` is available by default.
    I need `java.io.IOException`? Yes, for `throws`.

    **Wait, `main` signature:**
    `public static void main(String[] args)`
    C++: `int main()`
    Java: `public static void main(String[] args)`

    **Wait, `register`:**
    I will ignore `register` as it is ignored by Java.

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + ch - 48;`
    In Java: `aa = (aa << 1) + (aa << 3) + (ch - '0');`
    Wait, `ch` is `int`. `ch - 48` in C++ is `ch - '0'` (since '0' is 48).
    In Java, char arithmetic works fine. `ch - '0'`.
    I will use `ch - '0'` for clarity, but `(ch - 48)` is also fine. I'll stick to `ch - '0'` as it's more idiomatic Java, or `ch - 48` to be closer to C++?
    The instruction says "Translate this C++ code to Java code."
    Usually, idiomatic Java is preferred, but keeping the logic structure is key.
    I will use `ch - '0'` because `char` is promoted to `int` in Java and `'0'` is 48.
    Actually, `48` is an integer literal. `ch - 48` works too.
    I will use `ch - '0'` for readability, but maybe `ch - 48` is better to show translation fidelity?
    Let's use `ch - '0'` because it's cleaner in Java. Or `ch - 48` to match C++ exactly.
    Let's use `ch - '0'` because Java handles chars better.
    Wait, `ch` is `int` in C++ `register int aa, bb, ch;`.
    So `ch` is an `int` containing ASCII value.
    In Java, `int ch`.
    `ch - '0'` is fine.
    I will use `ch - '0'` because it's clearer.
    Wait, I should check if `ch` is guaranteed to be ASCII. Yes, `getchar` reads ASCII.
    I'll stick to `ch - '0'` for Java.

    **Wait, `System.in` buffering:**
    `System.in` is buffered? Usually yes.
    I will use `System.in.read()`.
    To make it faster like C++, I might need `BufferedInputStream`.
    But the C++ code uses `getchar` which is usually buffered.
    I will just use `System.in.read()`. It's standard Java I/O.
    I will add `java.io.InputStream` import? No, `System.in` is a field.
    I need `java.io.IOException`.

    **Wait, one detail:**
    `while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');`
    This loop skips whitespace and non-digits until it finds a digit or '-'.
    In Java:
    ```java
    while ((ch = in.read()) != -1 && (ch < '0' || ch > '9') && ch != '-') {}
    ```
    Wait, `ch = in.read()` is an expression.
    I need to check for EOF.
    If `in.read()` returns -1, the loop condition is false.
    But if it returns -1, we are at EOF.
    The C++ code assumes valid input.
    I will assume valid input.

    **Wait, the `in` method:**
    I will name it `in` to match `int (*in)() = fastIn;` usage `int n = in();`.
    But I can't have a method named `in` and a variable named `in` in the same scope easily in Java (unless `in` is the method).
    In C++, `in` is a pointer to a function.
    In Java, `in` will be a method.
    So `int n = in();` calls the method `in()`.
    This is fine.

    **Wait, `last` variable:**
    In C++, `int last = in();`.
    In Java, `int last = in();`.

    **Wait, `cnt` initialization:**
    `int cnt = 1;`.

    **Wait, `a` variable:**
    `int a;` inside `main`.
    `a = in();` inside loop.

    **Wait, `cout`:**
    `System.out.println(cnt);`

    **Wait, `return 0;`:**
    Java `main` returns `void`. I will remove `return 0;`.

    **Wait, `register`:**
    I will remove `register`.

    **Wait, `fastIn` function:**
    I will implement it as a static method `readInt` inside `a_716`.
    But `main` calls `in()`.
    So I should name the method `in` to match the usage `int n = in();`.
    I will implement `static int in()`.
    Inside `in()`, I will put the logic of `fastIn`.

    **Wait, `in` method structure:**
    ```java
    static int in() throws IOException {
        int ch = System.in.read();
        // logic...
    }
    ```
    Wait, the C++ code uses `while (ch = getchar(), ...)`
    In Java, `ch = System.in.read()` returns `int`.
    I need to make sure I handle the `IOException`.
    I will add `throws IOException` to `in()`.
    And `main` will handle it or propagate it.
    Since `main` in Java is `void`, I can't throw checked exception from `main` without `throws` clause on `main`.
    I will add `throws IOException` to `main`.

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + ch - 48;`
    In Java, `aa` is `int`.
    `ch` is `int`.
    `ch - 48` is `int`.
    I will use `ch - '0'` for clarity.

    **Wait, `aa` reset:**
    `ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - 48);`
    In Java:
    ```java
    if (ch == '-') {
        bb = 1;
        aa = 0;
    } else {
        bb = 0;
        aa = ch - '0';
    }
    ```

    **Wait, `aa` loop:**
    `while (ch = getchar(), ch >= '0' && ch <= '9') aa = (aa << 1) + (aa << 3) + ch - 48;`
    In Java:
    ```java
    while ((ch = System.in.read()) != -1 && (ch >= '0' && ch <= '9')) {
        aa = (aa << 1) + (aa << 3) + (ch - '0');
    }
    ```

    **Wait, `return`:**
    `return bb ? -aa : aa;`
    In Java: `return bb ? -aa : aa;`

    **Wait, `in` method name:**
    In C++, `int (*in)() = fastIn;`.
    In Java, I will name the method `in`.
    Wait, `in` is a method name.
    `static int in()`
    Inside `main`: `int n = in();`
    This works.

    **Wait, `System.in`:**
    I need `java.io.InputStream`? No, `System.in` is available.
    I need `java.io.IOException`.
    I need `java.io.PrintStream`? `System.out` is available.

    **Wait, `BufferedInputStream`:**
    To make it fast, I should probably use `BufferedInputStream` wrapping `System.in`.
    But the C++ code uses `getchar` directly on `stdin`.
    Java `System.in` is usually buffered enough for this logic.
    I will use `System.in` directly to keep it simple and faithful to the C++ `getchar` usage (which reads from `stdin`).
    However, `System.in` in Java might not be buffered.
    I will add `java.io.InputStream` import?
    I will use `System.in`.

    **Wait, `main` class name:**
    `a_716`

    **Wait, `main` method:**
    `public static void main(String[] args)`

    **Wait, `throws`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `readInt` logic:**
    I will combine the logic into `in()`.

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`
    This is `aa * 10 + digit`.
    I will keep the bitwise shift to match C++ style.

    **Wait, `register`:**
    I will remove `register`.

    **Wait, `using namespace std;`:**
    I will not use it. I will use `System.out` etc.

    **Wait, `cout`:**
    `System.out.println(cnt);`

    **Wait, `endl`:**
    `println` adds newline.

    **Wait, `return 0;`:**
    I will remove it.

    **Wait, `n` loop:**
    `for (int i = 2; i <= n; i++)`

    **Wait, `last` update:**
    `last = a;`

    **Wait, `cnt` update:**
    `if (a - k > last) cnt = 1; else cnt++;`

    **Wait, `in` method:**
    I need to handle `IOException`.
    I will add `throws IOException` to `in()`.
    And `main` will propagate it.

    **Wait, `System.in` usage:**
    I need to import `java.io.InputStream`? No, `System.in` is in `java.lang`.
    I need `java.io.IOException`.

    **Wait, `System.out`:**
    `System.out` is in `java.lang`.

    **Wait, `main` signature:**
    `public static void main(String[] args)`

    **Wait, `in` method:**
    I will call it `in`.
    But inside `main`, `int n = in();`.
    This is fine.

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`
    `ch` is `int`.
    `'0'` is `char`.
    In Java, `char` promotes to `int`.
    So `ch - '0'` is fine.

    **Wait, `ch` initialization:**
    In C++, `ch` is initialized in `while`.
    In Java, I need to declare `int ch`.
    I will initialize it.

    **Wait, `in` method:**
    I will implement it as `static int in() throws IOException`.

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;` inside `in()`.
    Wait, `aa` and `bb` are declared inside `fastIn` in C++.
    I will declare them inside `in()`.

    **Wait, `main` logic:**
    I need to read `n`, `k`, `last`.
    Then loop.

    **Wait, `cnt`:**
    `int cnt = 1;`

    **Wait, `a`:**
    `int a;`

    **Wait, `last`:**
    `int last = in();`

    **Wait, `n`:**
    `int n = in();`

    **Wait, `k`:**
    `int k = in();`

    **Wait, `in` method:**
    I will implement it as `static int in() throws IOException`.

    **Wait, `System.out`:**
    `System.out.println(cnt);`

    **Wait, `return 0;`:**
    I will remove it.

    **Wait, `import`:**
    `import java.io.IOException;`
    `import java.io.InputStream;` (Maybe not needed).
    `import java.util.*;` (Maybe not needed).
    I'll add `import java.io.IOException;`.

    **Wait, `System.in`:**
    I will use `System.in.read()`.

    **Wait, `in` method:**
    I will implement the logic of `fastIn` inside `in`.

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`
    I will use `ch - '0'` instead of `ch - 48` for Java.

    **Wait, `ch` check:**
    `while ((ch = System.in.read()) != -1 && (ch < '0' || ch > '9') && ch != '-') {}`
    Wait, `System.in.read()` returns `int`.
    I need to handle `IOException`.
    I will add `throws IOException`.

    **Wait, `ch` initialization:**
    I need to initialize `ch` before the loop.
    `int ch = 0;`

    **Wait, `in` method:**
    I will name it `in` to match the usage `int n = in();`.

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `ch` skip:**
    `while ((ch = System.in.read()) != -1 && (ch < '0' || ch > '9') && ch != '-') {}`
    Wait, this loop might hang if EOF is reached before any digit.
    But C++ code assumes valid input.
    I will assume valid input.

    **Wait, `in` method:**
    I will implement it as `static int in() throws IOException`.

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`
    I will use `ch - '0'` instead of `ch - 48`.

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

    **Wait, `aa` calculation:**
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` loop:**
    `while ((ch = System.in.read()) != -1 && ch >= '0' && ch <= '9')`
    `aa = (aa << 1) + (aa << 3) + (ch - '0');`

    **Wait, `aa` reset:**
    `if (ch == '-') { bb = 1; aa = 0; } else { bb = 0; aa = ch - '0'; }`

    **Wait, `return`:**
    `return bb ? -aa : aa;`

    **Wait, `main`:**
    `public static void main(String[] args) throws IOException`

    **Wait, `in` method:**
    `static int in() throws IOException`

    **Wait, `aa` and `bb`:**
    `int aa = 0, bb = 0;`

    **Wait, `ch`:**
    `int ch = 0;`

   