Translate this C++ code to Java code. The main class name should be b_1418. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <algorithm>
#define N 123
template <typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) { if (c == '-')	flag = true; c = getchar(); }
	while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
int h[N];
int lk[N];
int stk[N], stop;
int main() {
	int _; read(_);
	while (_--) {
		stop = 0;
		int n; read(n); for (int i = 1; i <= n; ++i)	read(h[i]);
		for (int i = 1; i <= n; ++i) {
			read(lk[i]);
			if (!lk[i])	stk[++stop] = h[i];
		}
		sort(stk + 1, stk + 1 + stop);
		for (int i = 1; i <= n; ++i) {
			if (lk[i])	printf("%d ", h[i]);
			else	printf("%d ", stk[stop--]);
		}
		puts("");
	}
	return 0;
}

Here is the plan for translating the C++ code to Java.

### Translation Plan

1.  **Header Inclusion**: The C++ code uses `<iostream>`, `<cstdio>`, `<cstring>`, `<cstdlib>`, `<cmath>`, `<string>`, `<algorithm>`, and `<ctime>`.
    *   In Java, we will use `java.util.Scanner` for input and `java.io.PrintWriter` (or `System.out`) for output. `PrintWriter` is generally faster and preferred for competitive programming contexts to avoid TLE (Time Limit Exceeded), though `System.out` is sufficient for this specific logic.
    *   The C++ `#define N 123` becomes a `static final int N = 123`.

2.  **Input Reading (`read` function)**:
    *   The C++ `read` function is a custom template for fast I/O. It reads an integer manually, handling negative signs and skipping whitespace.
    *   In Java, `Scanner.nextInt()` handles whitespace skipping automatically. We can implement a custom `readInt` method using `BufferedReader` and `StringTokenizer` to mimic the C++ custom read function if high performance is needed, but `Scanner` is likely sufficient given the small constraint $N=123$. However, to strictly adhere to the "translation" spirit of the fast I/O template, I will implement a custom `readInt` using `BufferedReader`.

3.  **Data Structures**:
    *   C++ `int h[N]`, `lk[N]`, `stk[N]` map to Java `int[] h`, `int[] lk`, `int[] stk`.
    *   Since the size is fixed at 123, arrays are allocated with size `N`.

4.  **Logic Translation**:
    *   **Main Loop**: The C++ `while (_--)` loop translates directly to a `while (_-- > 0)` or `for` loop in Java.
    *   **Reading Arrays**: The loops `for (int i = 1; i <= n; ++i)` translate to Java `for` loops. Note that C++ arrays are 0-indexed, but the loops start from 1. This implies the array size should be `n + 1` or the logic should handle 1-based indexing. In Java, `int[]` is 0-indexed. To match the C++ logic exactly (where index `i` corresponds to the $i$-th element), I will allocate arrays of size `n + 1` inside the test case loop to accommodate the 1-based indexing used in the C++ code (`i <= n`).
    *   **Stack Logic**:
        *   `stop` acts as the stack pointer. In C++, `++stop` increments the index. In Java, we can use an `int stop = 0` and increment it. The stack is implicitly defined by the range `1` to `stop`.
        *   `stk[++stop] = h[i]` becomes `stk[++stop] = h[i]` (since arrays are 0-indexed, we must ensure `stop` starts at 0, and we access `stk[1]` first).
        *   `sort(stk + 1, stk + 1 + stop)` translates to `Arrays.sort(stk, 1, stop + 1)`.
        *   `stk[stop--]` translates to `stk[stop--]` (post-decrement).
    *   **Output**: `printf` calls are replaced by `sb.append()` or `PrintWriter.println()`. `puts("")` becomes `println()`.

5.  **Class Structure**:
    *   The class name is `b_1418`.
    *   The `main` method is standard `public static void main(String[] args)`.

6.  **Incremental Tasks**:
    *   Step 1: Define the class and the static constant `N`.
    *   Step 2: Implement the `readInt` method (fast I/O).
    *   Step 3: Implement the `main` method logic, adapting array sizes and indices for 1-based indexing.
    *   Step 4: Implement sorting logic using `Arrays.sort`.
    *   Step 5: Implement output logic.

### Java Code

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class b_1418 {

    // Static arrays to store data. 
    // Although N is small (123), we allocate based on n inside the loop 
    // or a sufficiently large buffer to match the C++ logic of dynamic n.
    // To strictly follow the C++ logic where N is fixed at 123 but n varies,
    // we can use a fixed size array or allocate new arrays. 
    // Given the C++ code uses `h[N]`, we allocate `h` with size N + 1 to support 1-based indexing.
    // However, inside the loop, we only read up to n. 
    // We will allocate `h`, `lk`, `stk` with size `n + 1` inside the loop for efficiency,
    // or use a large enough buffer. Let's use a large buffer or dynamic allocation 
    // to match the logic `h[N]` (which implies max N).
    // Since the C++ code declares `int h[N]` globally, we will do the same here to be faithful.
    
    // We will use a fixed size buffer larger than 123 just to be safe, 
    // or strictly follow N=123. Let's use N+1 to handle 1-based indexing easily.
    private static final int MAX_N = 123;
    private static int[] h = new int[MAX_N + 1];
    private static int[] lk = new int[MAX_N + 1];
    private static int[] stk = new int[MAX_N + 1];
    private static int stop;

    // Fast Input Reader to replicate C++ read() function
    // Reads an integer, handling negative signs and skipping whitespace.
    public static int readInt() throws IOException {
        int c = (int) System.in.read();
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = (int) System.in.read();
        }
        if (c == -1 || (c == '-' && (c = (int) System.in.read()) == -1))) {
            return 0; // Should not happen based on problem constraints
        }
        int res = 0;
        if (c == '-') {
            res = -1;
            c = (int) System.in.read();
        }
        while (c != -1 && Character.isDigit(c)) {
            res = res * 10 + (c - '0');
            c = (int) System.in.read();
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        // We need a tokenizer because readInt consumes characters one by one
        // which might skip the newline after the first integer if not handled carefully.
        // Actually, the custom readInt above consumes characters. 
        // Let's stick to the custom readInt for the first integer to match C++ behavior,
        // but we need to handle the loop structure.
        
        // Re-implementation of readInt logic using BufferedReader for safety and standard practice
        // while maintaining the "fast I/O" spirit.
        // Note: The C++ code uses getchar() which reads char by char.
        // We will use a standard fast I/O pattern.
        
        // Re-declaring reader for main logic
        // We need to read the first integer (number of test cases)
        // The logic in C++: read(_);
        // We will implement a robust integer reader.
        
        // Let's use a simpler StringTokenizer approach for the first integer 
        // and then switch to custom reading if necessary, OR just use one consistent reader.
        // Given the simplicity, we can use StringTokenizer for the first integer 
        // and then a custom reader for the rest to ensure we don't skip newlines incorrectly 
        // if we mix them. But to be consistent with the provided C++ code structure:
        
        // Let's create a helper class or method that mimics the C++ read() exactly.
        // The C++ read() skips whitespace.
        
        // To make it robust:
        StringTokenizer st = new StringTokenizer("");
        
        // Read number of test cases
        // We need a method to get next token or char.
        // Let's use a custom FastReader class inside to encapsulate the logic cleanly.
        
        // However, to keep it single-file and simple:
        // We will implement the read logic inside main or a helper.
        
        // Let's use the BufferedReader approach to read integers manually as per C++ read()
        // to handle the exact whitespace skipping logic (though Scanner is easier, 
        // the C++ code is a custom fast I/O implementation).
        
        // Re-implementing the read logic for the specific variable '_'
        // C++: int _; read(_);
        // We'll just use a helper method.
        
        // Since the C++ code uses getchar(), we must handle buffering.
        // Let's use a standard fast I/O buffer.
        
        // Re-defining the read method logic to be used in main
        // We need to read '_' first.
        // Then inside while loop, read 'n', then read 'h' array, then 'lk' array.
        
        // Let's use a static buffer for input reading.
        int inputBuffer = 0;
        boolean needRead = true;
        
        // Helper to read next int
        // We'll use a simple StringTokenizer for the whole input as it handles whitespace robustly
        // and matches the C++ logic of skipping non-digits.
        // Wait, the C++ code uses a custom read that skips *any* non-digit (except -).
        // This is exactly what Scanner does.
        // However, the C++ code is likely from a competitive programming context where custom read is used for speed.
        // We will use a FastScanner class.
        
        // Let's simplify: Use BufferedReader and StringTokenizer.
        // The C++ read() function is essentially `Scanner.nextInt()`.
        // We will implement a simple `next()` method.
        
        // Re-reading the C++ code:
        // It uses `getchar()` in a loop. This is very fast.
        // Let's implement a simple `readInt` using `BufferedReader` that mimics `getchar`.
        
        // We need to read the first integer `_`.
        // Then loop `_` times.
        // Inside loop: read `n`.
        // Then read `n` integers into `h`.
        // Then read `n` integers into `lk`.
        // Process.
        
        // Let's write a robust FastScanner.
        
        // Since I cannot easily instantiate a new class inside main in this single block 
        // without clutter, I will put the FastScanner logic in a static inner class or methods.
        
        // Let's use the logic provided in the thought block for the final code.
    }
    
    // --- Fast I/O Implementation ---
    // To match the C++ `read` function which skips whitespace and reads integers.
    private static int read() throws IOException {
        int c = (int) System.in.read();
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = (int) System.in.read();
        }
        if (c == -1) return 0; // End of stream
        if (c == '-') {
            c = (int) System.in.read();
        }
        int res = 0;
        while (c != -1 && Character.isDigit(c)) {
            res = (res << 1) + (res << 3) + (c - '0'); // Equivalent to res * 10
            c = (int) System.in.read();
        }
        if (c == -1 && (c == '-' || Character.isDigit(c))) {
             // This logic is slightly tricky with EOF. 
             // In C++, if the loop breaks, it stops. 
             // We assume valid input.
        }
        // Handling the sign
        // If we read a '-' before, we need to know. 
        // The C++ code checks `flag` before the loop.
        // Let's refactor the read method to be cleaner.
        return res; // Placeholder, will fix in final code
    }
}
```

Wait, the thought block above is just planning. I need to write the actual code.

**Refined Plan for Code:**
1.  **Class**: `b_1418`.
2.  **Arrays**: `h`, `lk`, `stk` of size `124` (to accommodate `N=123` and 1-based indexing).
3.  **Input**:
    *   The C++ code uses a custom `read` function that reads integers by skipping whitespace and handling negative signs.
    *   In Java, `Scanner` does this, but it is slow. To match the C++ intent (and ensure speed), I will implement a custom `readInt` method using `System.in.read()`.
    *   The C++ code reads `_` first.
    *   Then loops `_` times.
    *   Inside loop: reads `n`. Reads `n` integers into `h`. Reads `n` integers into `lk`.
    *   Logic: If `lk[i] != 0`, push `h[i]` to stack. Sort stack.
    *   Output: If `lk[i] != 0`, print `h[i]`. Else, pop from stack.
4.  **Output**: Use `PrintWriter` for buffered output.

**Specific C++ to Java Mapping:**
*   `#define N 123` -> `static final int N = 123;`
*   `read(T &x)` -> `static int readInt()` (returns int).
*   `getchar()` -> `System.in.read()`.
*   `isdigit(c)` -> `Character.isDigit(c)`.
*   `printf` -> `PrintWriter.println` or `sb.append`.
*   `sort(stk + 1, stk + 1 + stop)` -> `Arrays.sort(stk, 1, stop + 1)`.
*   `stk[++stop] = h[i]` -> `stk[++stop] = h[i]` (Note: Java arrays are 0-indexed, but we can use 1-based indexing by allocating size `N+1` and using index `stop` starting at 0. The C++ code increments `stop` before assignment, so `stk[1]` is the first element. In Java, `int[]` starts at 0. So `stk[1]` is valid if size is `N+1`).
*   `stk[stop--]` -> `stk[stop--]`.

**Code Structure:**
```java
import java.io.*;
import java.util.*;

public class b_1418 {
    static final int N = 123;
    static int[] h = new int[N + 1];
    static int[] lk = new int[N + 1];
    static int[] stk = new int[N + 1];
    static int stop;

    public static void main(String[] args) throws IOException {
        // Use fast I/O to match C++ read()
        // We need to read the first integer `_`
        // Then loop `_` times.
        
        // Custom Reader
        // ...
    }
}
```

Let's refine the `readInt` logic to exactly match the C++ `read` function behavior (skipping whitespace, handling `-`).

C++ `read`:
```cpp
x = 0; char c = getchar(); bool flag = false;
while (!isdigit(c)) { if (c == '-') flag = true; c = getchar(); }
while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
if (flag) x = -x;
```
Note: `c ^ 48` is `c - '0'`. `(x << 1) + (x << 3)` is `2x + 8x = 10x`.
So it's standard integer parsing.

Java `readInt`:
```java
int c = System.in.read();
while (c != -1 && !Character.isDigit(c) && c != '-') { c = System.in.read(); }
if (c == -1) return 0; // Or throw exception
if (c == '-') { c = System.in.read(); } // Consume '-'
int res = 0;
while (c != -1 && Character.isDigit(c)) {
    res = (res << 1) + (res << 3) + (c - '0');
    c = System.in.read();
}
return res;
```
Wait, the C++ code logic:
`while (!isdigit(c))` reads until it finds a digit or end. If it finds '-', it sets flag and reads next char.
If the first char is a digit, it skips the first while loop.
If the first char is '-', it enters the loop, sets flag, reads next char (which should be digit).
So the logic holds.

One detail: `c` in C++ is a `char`. In Java `System.in.read()` returns `int` (byte value).
The logic `c ^ 48` is `c - '0'`.

Final check on `stop`:
C++: `stop` is global. `stk` is global.
Inside loop: `stop = 0`.
`stk[++stop] = h[i]`.
This means `stop` becomes 1, `stk[1]` gets value.
Java: `stop = 0`. `stk[++stop]` -> `stk[1]`.
Correct.

Output:
C++: `printf("%d ", h[i])`.
Java: `out.print(val + " ")`.
C++: `puts("")`.
Java: `out.println()`.

Let's write the code.

```java
import java.io.*;
import java.util.*;

public class b_1418 {
    // Define N as per C++
    static final int N = 123;
    
    // Arrays declared with size N+1 to support 1-based indexing used in loops (1 to n)
    static int[] h = new int[N + 1];
    static int[] lk = new int[N + 1];
    static int[] stk = new int[N + 1];
    static int stop;

    // Fast I/O to replicate C++ read() function
    // Reads an integer from System.in, handling whitespace and negative signs.
    public static int read() throws IOException {
        int c = System.in.read();
        // Skip whitespace
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = System.in.read();
        }
        if (c == -1) return 0; // End of stream
        
        // Check for negative sign
        if (c == '-') {
            c = System.in.read();
        }
        
        int res = 0;
        // Read digits
        while (c != -1 && Character.isDigit(c)) {
            res = (res << 1) + (res << 3) + (c - '0'); // Equivalent to res = res * 10 + (c - '0')
            c = System.in.read();
        }
        
        // If we read a '-' at the start, negate the result
        // We need to track if '-' was read. 
        // The C++ code uses a 'flag'. 
        // In our logic, if the first char read was '-', we consumed it.
        // We need to know if it was there. 
        // Let's adjust the logic slightly to track the sign.
        
        // Re-evaluating the read function logic for Java:
        // C++: 
        //   char c = getchar(); 
        //   while (!isdigit(c)) { if (c == '-') flag = true; c = getchar(); }
        //   ...
        //   if (flag) x = -x;
        
        // To implement this in Java with a single return value, we can return a special value 
        // or use a class wrapper, OR we can just implement the logic inside main to avoid 
        // the complexity of returning a boolean flag from a single int return type 
        // (unless we return a long or object).
        // However, since the input format is guaranteed (integers), 
        // we can just check the first character read.
        
        // Let's rewrite read() to return the int and we handle the sign inside the loop 
        // by checking the first character read before calling read().
        // But wait, the C++ read() is a template function.
        // It's easier to implement a FastReader class.
        
        return res;
    }
    
    // Actually, to keep it simple and faithful to the single function structure:
    // We can't easily return a boolean flag from an int method without using a wrapper or 
    // relying on the fact that the first character read determines the sign.
    // But the C++ code logic is: skip non-digits, if '-' found set flag, then read digits.
    // Let's implement a robust version.
    
    public static int readInt() throws IOException {
        int c = (int) System.in.read();
        boolean flag = false;
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = (int) System.in.read();
        }
        if (c == -1) return 0;
        if (c == '-') {
            flag = true;
            c = (int) System.in.read();
        }
        int res = 0;
        while (c != -1 && Character.isDigit(c)) {
            res = (res << 1) + (res << 3) + (c - '0');
            c = (int) System.in.read();
        }
        if (flag) res = -res;
        return res;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        
        // Read number of test cases
        int _ = readInt();
        
        while (_-- > 0) {
            stop = 0;
            int n = readInt();
            
            // Read h array (1 to n)
            for (int i = 1; i <= n; ++i) {
                h[i] = readInt();
            }
            
            // Read lk array (1 to n)
            for (int i = 1; i <= n; ++i) {
                lk[i] = readInt();
                if (lk[i] == 0) {
                    // C++: if (!lk[i]) stk[++stop] = h[i];
                    // Java: ++stop is pre-increment
                    stop++;
                    stk[stop] = h[i];
                }
            }
            
            // C++: sort(stk + 1, stk + 1 + stop);
            // Java: Arrays.sort(stk, 1, stop + 1);
            Arrays.sort(stk, 1, stop + 1);
            
            // Output loop
            for (int i = 1; i <= n; ++i) {
                if (lk[i] != 0) {
                    out.print(h[i] + " ");
                } else {
                    // C++: stk[stop--];
                    // Java: post-decrement
                    out.print(stk[stop--] + " ");
                }
            }
            out.println();
        }
        
        out.flush();
    }
}
```

Wait, one logic check:
C++: `if (!lk[i]) stk[++stop] = h[i];`
Java: `if (lk[i] == 0) { stop++; stk[stop] = h[i]; }`
This is correct.

Also, `readInt` logic check:
If the first char is `-`, `flag` becomes true, `c` becomes next char.
Then loop reads digits.
If `flag` is true, `res = -res`.
This matches the C++ logic perfectly.

One minor thing: `System.in.read()` returns `int`. `Character.isDigit(int)` expects `int`.
The logic `c ^ 48` in C++ is `c - '0'` in Java (since '0' is 48).
The bit shift `x << 1` is `x*2`, `x << 3` is `x*8`. Sum is `10x`.
So `res = res * 10 + (c - '0')` is correct.

One detail: `read` in C++ is a template. `read(_)` reads `int`. `read(h[i])` reads `int`.
My `readInt()` handles `int`. This is sufficient.

Wait, `System.in.read()` might block if input is not ready, but in CP problems, input is piped.
It should be fine.

Final check on class name: `b_1418`.

```java
import java.io.*;
import java.util.*;

public class b_1418 {
    static final int N = 123;
    static int[] h = new int[N + 1];
    static int[] lk = new int[N + 1];
    static int[] stk = new int[N + 1];
    static int stop;

    public static int readInt() throws IOException {
        int c = System.in.read();
        boolean flag = false;
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = System.in.read();
        }
        if (c == -1) return 0;
        if (c == '-') {
            flag = true;
            c = System.in.read();
        }
        int res = 0;
        while (c != -1 && Character.isDigit(c)) {
            res = (res << 1) + (res << 3) + (c - '0');
            c = System.in.read();
        }
        if (flag) res = -res;
        return res;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        int _ = readInt();
        while (_-- > 0) {
            stop = 0;
            int n = readInt();
            for (int i = 1; i <= n; ++i) {
                h[i] = readInt();
            }
            for (int i = 1; i <= n; ++i) {
                lk[i] = readInt();
                if (lk[i] == 0) {
                    stop++;
                    stk[stop] = h[i];
                }
            }
            Arrays.sort(stk, 1, stop + 1);
            for (int i = 1; i <= n; ++i) {
                if (lk[i] != 0) {
                    out.print(h[i] + " ");
                } else {
                    out.print(stk[stop--] + " ");
                }
            }
            out.println();
        }
        out.flush();
    }
}
```
This looks correct and faithful to the C++ logic.

One small optimization/correction:
In the C++ code: `while (!isdigit(c))`.
In Java: `while (c != -1 && !Character.isDigit(c) && c != '-')`.
This handles the case where `c` is `-` correctly (it enters the loop, sets flag, reads next).
If `c` is whitespace, it skips.
If `c` is EOF (`-1`), it stops.
This is correct.

Wait, `c` in C++ is `char`. In Java `int`.
`c == -1` is EOF.
In C++, `getchar()` returns `int` (EOF is -1).
So `c != -1` check is necessary in Java.

One edge case: `c` could be `EOF` inside the loop.
`while (c != -1 && Character.isDigit(c))` handles this.

The code seems solid.

One detail: `N` is 123.
In C++, `int h[N]`.
In Java, `new int[N + 1]`.
The loop `i <= n`. If `n` is 123, `h[123]` is accessed.
`new int[123 + 1]` gives indices `0..123`.
This is safe.

Final check on imports: `java.io.*`, `java.util.*`.
The class name is `b_1418`.
The token `<CODE>` at start and end.

One minor thing: `readInt` reads from `System.in`.
If `readInt` is called for `_`, then `while(_--)`, then inside loop `readInt` for `n`, then `n` times for `h`, then `n` times for `lk`.
This consumes the entire input stream correctly.

One detail: The C++ code uses `read(T &x)`.
In Java, we pass `int` by value.
So `readInt()` returns `int`.
This is fine.

The plan is ready.

```java
<CODE>
import java.io.*;
import java.util.*;

public class b_1418 {
    // Define N as per C++
    static final int N = 123;
    
    // Arrays declared with size N+1 to support 1-based indexing used in loops (1 to n)
    static int[] h = new int[N + 1];
    static int[] lk = new int[N + 1];
    static int[] stk = new int[N + 1];
    static int stop;

    // Fast I/O to replicate C++ read() function
    // Reads an integer from System.in, handling whitespace and negative signs.
    public static int readInt() throws IOException {
        int c = System.in.read();
        boolean flag = false;
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = System.in.read();
        }
        if (c == -1) return 0;
        if (c == '-') {
            flag = true;
            c = System.in.read();
        }
        int res = 0;
        while (c != -1 && Character.isDigit(c)) {
            res = (res << 1) + (res << 3) + (c - '0'); // Equivalent to res = res * 10 + (c - '0')
            c = System.in.read();
        }
        if (flag) res = -res;
        return res;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        
        // Read number of test cases
        int _ = readInt();
        
        while (_-- > 0) {
            stop = 0;
            int n = readInt();
            
            // Read h array (1 to n)
            for (int i = 1; i <= n; ++i) {
                h[i] = readInt();
            }
            
            // Read lk array (1 to n)
            for (int i = 1; i <= n; ++i) {
                lk[i] = readInt();
                if (lk[i] == 0) {
                    // C++: if (!lk[i]) stk[++stop] = h[i];
                    // Java: ++stop is pre-increment
                    stop++;
                    stk[stop] = h[i];
                }
            }
            
            // C++: sort(stk + 1, stk + 1 + stop);
            // Java: Arrays.sort(stk, 1, stop + 1);
            Arrays.sort(stk, 1, stop + 1);
            
            // Output loop
            for (int i = 1; i <= n; ++i) {
                if (lk[i] != 0) {
                    out.print(h[i] + " ");
                } else {
                    // C++: stk[stop--];
                    // Java: post-decrement
                    out.print(stk[stop--] + " ");
                }
            }
            out.println();
        }
        
        out.flush();
    }
}
</CODE>
```
Wait, I should double check the `readInt` logic regarding the first character.
In C++: `char c = getchar();`
If `c` is whitespace, it loops.
If `c` is `-`, it sets flag and loops.
If `c` is digit, it skips loop and starts reading digits.
My Java code:
`int c = System.in.read();`
`while (c != -1 && !Character.isDigit(c) && c != '-') { c = System.in.read(); }`
This is identical.
If `c` is `-`, it exits the loop (condition `c != '-'` is false).
Then `if (c == '-') { flag = true; c = System.in.read(); }`.
This is identical.
Then `while (c != -1 && Character.isDigit(c))`.
If `c` was `-`, it read the next char.
If next char is digit, it enters loop.
If next char is whitespace/EOF, it exits loop.
If `flag` is true, it negates.
This is identical.

One small edge case: `c` could be `-` and then EOF immediately.
`c = System.in.read()` -> `-`.
`while` loop exits.
`if (c == '-')` -> `flag = true`. `c = System.in.read()` -> `-1`.
`while (c != -1 ...)` -> exits.
`if (flag) res = -res` (0). Returns 0.
This handles the edge case gracefully (though unlikely in valid test cases).

The logic is sound.

Final check on `N`.
C++: `#define N 123`.
Java: `static final int N = 123;`.
Arrays: `new int[N + 1]`.
Loop: `i <= n`.
If `n > N`, `ArrayIndexOutOfBoundsException` would occur.
But usually `n <= N` in such problems.
The problem statement doesn't explicitly say `n <= N`, but `h[N]` is declared.
It implies `n` fits in `N`.
If `n` is larger, the C++ code would crash too.
So `new int[N + 1]` is the correct translation of `int h[N]`.

The code is ready.

One tiny thing: `out.print(stk[stop--] + " ");`
In C++: `printf("%d ", stk[stop--]);`
This prints the number then a space.
Java: `out.print(stk[stop--] + " ");`
This prints the number then a space.
Correct.

The output format matches.

One detail: `readInt` is static. `stop` is static. `h`, `lk`, `stk` are static.
This is fine for a single threaded program.

Wait, `stop` is reset in `while (_--) { stop = 0; ... }`.
This is correct.

Looks good.

```java
import java.io.*;
import java.util.*;

public class b_1418 {
    // Define N as per C++
    static final int N = 123;
    
    // Arrays declared with size N+1 to support 1-based indexing used in loops (1 to n)
    // This corresponds to C++: int h[N];
    static int[] h = new int[N + 1];
    static int[] lk = new int[N + 1];
    static int[] stk = new int[N + 1];
    static int stop;

    // Fast I/O to replicate C++ read() function
    // Reads an integer from System.in, handling whitespace and negative signs.
    public static int readInt() throws IOException {
        int c = System.in.read();
        boolean flag = false;
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = System.in.read();
        }
        if (c == -1) return 0;
        if (c == '-') {
            flag = true;
            c = System.in.read();
        }
        int res = 0;
        while (c != -1 && Character.isDigit(c)) {
            res = (res << 1) + (res << 3) + (c - '0'); // Equivalent to res = res * 10 + (c - '0')
            c = System.in.read();
        }
        if (flag) res = -res;
        return res;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        
        // Read number of test cases
        int _ = readInt();
        
        while (_-- > 0) {
            stop = 0;
            int n = readInt();
            
            // Read h array (1 to n)
            // C++: for (int i = 1; i <= n; ++i) read(h[i]);
            for (int i = 1; i <= n; ++i) {
                h[i] = readInt();
            }
            
            // Read lk array (1 to n)
            // C++: for (int i = 1; i <= n; ++i) { read(lk[i]); if (!lk[i]) stk[++stop] = h[i]; }
            for (int i = 1; i <= n; ++i) {
                lk[i] = readInt();
                if (lk[i] == 0) {
                    stop++;
                    stk[stop] = h[i];
                }
            }
            
            // C++: sort(stk + 1, stk + 1 + stop);
            // Java: Arrays.sort(stk, 1, stop + 1);
            Arrays.sort(stk, 1, stop + 1);
            
            // Output loop
            // C++: for (int i = 1; i <= n; ++i) { if (lk[i]) printf("%d ", h[i]); else printf("%d ", stk[stop--]); }
            for (int i = 1; i <= n; ++i) {
                if (lk[i] != 0) {
                    out.print(h[i] + " ");
                } else {
                    out.print(stk[stop--] + " ");
                }
            }
            out.println();
        }
        
        out.flush();
    }
}
```
This is the final code.
I will wrap it with `<CODE>` and `</CODE>`.

Wait, I should check if `readInt` consumes the newline after `_`.
`_ = readInt()`.
Then `while (_-- > 0)`.
Then `n = readInt()`.
`readInt` skips whitespace. So it will skip the newline after `_`.
This is correct.
Same for `h` and `lk` arrays.
So the input parsing is robust.

One final check: The C++ code uses `read(T &x)`.
My Java `readInt` returns `int`.
This is sufficient.

Okay, generating output.

```java
<CODE>
...
</CODE>
```
No, the instruction says "output the code of the resulting program with token "<CODE>" at the beginning and at the end."
So:
```
<CODE>
...
</CODE>
```
Wait, the instruction says "token "<CODE>" at the beginning and at the end."
Does it mean the literal string `<CODE>`?
"output the code of the resulting program with token "<CODE>" at the beginning and at the end."
Usually this means:
```
<CODE>
... code ...
</CODE>
```
Or:
```
<CODE>
... code ...
</CODE>
```
I will use the standard markdown code block style with `<CODE>` as the wrapper text if that's what is meant, 
but usually it means wrap the code block in `<CODE>` tags.
Actually, looking at the instruction: "output the code of the resulting program with token "<CODE>" at the beginning and at the end."
It might mean literally:
`<CODE>`
`...`
`</CODE>`
I will do that.

Wait, is it `</CODE>` or just `<CODE>`?
"token "<CODE>" at the beginning and at the end."
Usually implies start and end markers.
So `<CODE>` at start, `</CODE>` at end.
I will follow this.

Wait, the prompt says "token "<CODE>" at the beginning and at the end."
It might mean just `<CODE>` at the start and `<CODE>` at the end?
Or start `<CODE>` and end `</CODE>`?
Usually, XML/HTML tags imply a pair.
I will assume standard XML-like tags: `<CODE>` and `</CODE>`.

Actually, re-reading: "with token "<CODE>" at the beginning and at the end."
It could mean the string `<CODE>` appears at the beginning and the string `<CODE>` appears at the end.
Or it could mean `<CODE>` and `</CODE>`.
Given standard practice for these types of prompts, it usually means wrapping the code in `<CODE>` and `</CODE>`.
I will use `<CODE>` and `</CODE>`.

Wait, looking at the instruction again: "token "<CODE>" at the beginning and at the end."
It might literally mean the text `<CODE>` at the start and `<CODE>` at the end.
But that would be weird for a code block.
I'll stick to `<CODE>` and `</CODE>`.

Wait, if I look at the instruction literally: "token "<CODE>" at the beginning and at the end."
Token is `<CODE>`.
So beginning: `<CODE>`.
End: `<CODE>`.
This is ambiguous.
However, often prompts ask for `<CODE>` and `</CODE>`.
I will use `<CODE>` and `</CODE>` to be safe as it's a common convention.
If it strictly means `<CODE>` at both ends, I will adjust.
But "token" usually implies the delimiter.
I'll use `<CODE>` and `</CODE>`.

Wait, I'll check the instruction one more time.
"output the code of the resulting program with token "<CODE>" at the beginning and at the end."
It does not say `</CODE>`.
It says token `<CODE>`.
So maybe:
`<CODE>`
`...`
`<CODE>`
But that looks ugly.
I will assume it means the standard code block tags `<CODE>` and `</CODE>`.
Actually, I'll just use `<CODE>` and `</CODE>`.

Wait, I should check if I missed anything.
The plan was:
1. Class `b_1418`.
2. `read` function translation.
3. Array translation.
4. Logic translation.
5. Output translation.

I have all of these.

One detail: `stop` is declared as `int stop;` in C++.
In Java, I declared `static int stop;`.
This is correct.

I will write the code now.
</think>

<CODE>
import java.io.*;
import java.util.*;

public class b_1418 {
    // Define N as per C++
    static final int N = 123;
    
    // Arrays declared with size N+1 to support 1-based indexing used in loops (1 to n)
    // This corresponds to C++: int h[N];
    static int[] h = new int[N + 1];
    static int[] lk = new int[N + 1];
    static int[] stk = new int[N + 1];
    static int stop;

    // Fast I/O to replicate C++ read() function
    // Reads an integer from System.in, handling whitespace and negative signs.
    public static int readInt() throws IOException {
        int c = System.in.read();
        boolean flag = false;
        while (c != -1 && !Character.isDigit(c) && c != '-') {
            c = System.in.read();
        }
        if (c == -1) return 0;
        if (c == '-') {
            flag = true;
            c = System.in.read();
        }
        int res = 0;
        while (c != -1 && Character.isDigit(c)) {
            res = (res << 1) + (res << 3) + (c - '0'); // Equivalent to res = res * 10 + (c - '0')
            c = System.in.read();
        }
        if (flag) res = -res;
        return res;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        
        // Read number of test cases
        int _ = readInt();
        
        while (_-- > 0) {
            stop = 0;
            int n = readInt();
            
            // Read h array (1 to n)
            // C++: for (int i = 1; i <= n; ++i) read(h[i]);
            for (int i = 1; i <= n; ++i) {
                h[i] = readInt();
            }
            
            // Read lk array (1 to n)
            // C++: for (int i = 1; i <= n; ++i) { read(lk[i]); if (!lk[i]) stk[++stop] = h[i]; }
            for (int i = 1; i <= n; ++i) {
                lk[i] = readInt();
                if (lk[i] == 0) {
                    stop++;
                    stk[stop] = h[i];
                }
            }
            
            // C++: sort(stk + 1, stk + 1 + stop);
            // Java: Arrays.sort(stk, 1, stop + 1);
            Arrays.sort(stk, 1, stop + 1);
            
            // Output loop
            // C++: for (int i = 1; i <= n; ++i) { if (lk[i]) printf("%d ", h[i]); else printf("%d ", stk[stop--]); }
            for (int i = 1; i <= n; ++i) {
                if (lk[i] != 0) {
                    out.print(h[i] + " ");
                } else {
                    out.print(stk[stop--] + " ");
                }
            }
            out.println();
        }
        
        out.flush();
    }
}
</CODE>