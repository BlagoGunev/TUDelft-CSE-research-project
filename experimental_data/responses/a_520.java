Translate this C++ code to Java code. The main class name should be a_520. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>

#include <algorithm>



using namespace std;



void LowerCase(string &s){

	for (long i = 0; i < s.length(); i++){

		if (s[i] >= 'A' && s[i] <= 'Z') s[i] +=32;

	}

}



int main(){

	string s;

	string x = "hello";

	long d[10000] = {};

	long n;

	long is = 0, ix = 0;

	cin >> n;

	cin >> s;

	LowerCase(s);

	for (long i = 0; i < s.length(); i++){

		d[s[i]] = 1;

 	}

 	for (long i = 'a'; i <= 'z'; i++){

 		if (d[i] == 0){

 			cout << "NO";

 			return 0;

		 }

	 }

	 cout << "YES";

	

	

	return 0;

}

Here is the plan for translating the C++ code to Java:

1.  **Main Class and Entry Point**:
    *   The C++ `main` function becomes the `main` method inside a class named `a_520`.
    *   Java requires an explicit class definition and a `public static void main(String[] args)` method.

2.  **Standard I/O**:
    *   C++ uses `iostream` (`cin`, `cout`).
    *   Java uses `java.util.Scanner` for input and `System.out` for output.
    *   Note: The C++ code reads `n` and `s`. In the provided logic, `n` is read but never actually used in the logic (it is read, then `s` is read). The code then iterates through `s` and checks specific characters. We will preserve this logic exactly as written, even if `n` seems unused in the snippet.

3.  **String Handling**:
    *   C++ `string` is a class with `length()` and index access `s[i]`.
    *   Java `String` is immutable. We cannot modify characters in place.
    *   The `LowerCase` function modifies the string in place. In Java, we must create a `StringBuilder` to perform the transformation, convert it to a String, and assign it back.
    *   C++ `s[i]` returns a `char`. In Java, `sb.charAt(i)` returns an `int` (Unicode value). We need to handle character comparison (e.g., `'A'`, `'Z'`, `'a'`, `'z'`) as integer comparisons.

4.  **Array Handling**:
    *   C++ uses a static array `long d[10000] = {};`.
    *   Java does not support static arrays of primitives with dynamic sizing easily inside the method scope like C++. We will use a `long[]` array of size 10000.
    *   *Correction on logic*: In C++, `d` is initialized with zeros. `d[s[i]] = 1` sets indices corresponding to characters. In Java, arrays are initialized to 0 by default, so `long[] d = new long[10000]` works similarly. However, `s[i]` is a `char` (int value). We must ensure the index is within bounds. The C++ code assumes `s` contains characters within the range of the array (likely 'a'-'z').

5.  **Incremental Tasks**:
    *   **Step 1**: Set up the class `a_520` and `Scanner` for input.
    *   **Step 2**: Implement the `LowerCase` logic using `StringBuilder`.
    *   **Step 3**: Implement the frequency counting logic using the array `d`.
    *   **Step 4**: Implement the check loop ('a' to 'z') and output "NO" or "YES".

6.  **Specific Translation Details**:
    *   `string &s` -> `String s` (passed by value in Java effectively for this scope).
    *   `s.length()` -> `s.length()`.
    *   `s[i]` -> `sb.charAt(i)`.
    *   `d[s[i]] = 1` -> `d[sb.charAt(i)] = 1`. Note: Since `d` is `long[]`, this is fine.
    *   `cout << "NO"` -> `System.out.println("NO")`.

7.  **Refinement**:
    *   The C++ code defines `d` as `long d[10000]`. In Java, we define `long[] d = new long[10000]`.
    *   The C++ code uses `long` for indices. In Java, `int` is sufficient for string indices and character codes (max 65535), but `long` is also valid. We will use `int` for array indices and loop counters as is standard Java practice, but keep the logic identical.
    *   The C++ code initializes `d` with `{}`. Java initializes arrays to 0 automatically.
    *   The C++ code logic `s[i] >= 'A' && s[i] <= 'Z'` works on integer values of characters. Java `char` promotes to `int` in comparisons.

```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read n (unused in logic, but kept to match input stream)
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
        }
        
        // Read s
        if (sc.hasNext()) {
            String s = sc.next();
            
            // Implement LowerCase logic
            // C++: string &s (mutable)
            // Java: String is immutable, use StringBuilder
            StringBuilder sb = new StringBuilder(s);
            
            for (int i = 0; i < sb.length(); i++) {
                char c = sb.charAt(i);
                if (c >= 'A' && c <= 'Z') {
                    sb.setCharAt(i, Character.toLowerCase(c));
                    // Or manually: sb.setCharAt(i, (char)(c + 32));
                }
            }
            s = sb.toString();
            
            // Array logic
            // C++: long d[10000] = {};
            // Java: long[] d = new long[10000]; (Java initializes to 0 by default)
            long[] d = new long[10000];
            
            for (int i = 0; i < s.length(); i++) {
                d[s.charAt(i)] = 1;
            }
            
            for (int i = 'a'; i <= 'z'; i++) {
                if (d[i] == 0) {
                    System.out.println("NO");
                    return;
                }
            }
            
            System.out.println("YES");
        }
        
        sc.close();
    }
}
```

Wait, looking closer at the C++ code: `cin >> n; cin >> s;`.
If `n` is not used, it is just consumed.
The C++ code: `long d[10000] = {};`.
In Java, `long[] d = new long[10000];` creates an array of zeros.
The C++ code: `for (long i = 'a'; i <= 'z'; i++)`.
In Java, `for (int i = 'a'; i <= 'z'; i++)`.
One edge case: `s` might contain characters outside 'a'-'z' range? The C++ code assumes `s[i]` is a valid index for `d`. Since `d` is size 10000, and ASCII 'z' is 122, this is safe.
However, if `s` contains uppercase letters before lowercasing, `s[i]` in the loop `for (long i = 0; i < s.length(); i++)` is executed *after* `LowerCase(s)`. So `s` is guaranteed to be lowercase.
Then `d[s[i]]` is safe.

One detail: `cin >> n` consumes the token. If `n` is large, `s` follows.
The C++ code: `cin >> n; cin >> s;`.
If `n` is not read, the `cin >> s` might fail if the first token is not `n`.
So we must read `n`.

Wait, `cin >> s` reads a string delimited by whitespace.
If `n` is read, `cin >> s` reads the next token.

Let's refine the Java code to be strictly equivalent.

```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n. In C++, this is long. In Java, long is fine.
        // We check hasNext to prevent NoSuchElementException if input is empty, 
        // though competitive programming inputs are usually well-formed.
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
        }
        
        // Read s
        if (scanner.hasNext()) {
            String s = scanner.next();
            
            // C++: void LowerCase(string &s)
            // Java: String is immutable. We create a StringBuilder.
            // The logic: if char is 'A'-'Z', add 32.
            StringBuilder sb = new StringBuilder(s);
            for (int i = 0; i < sb.length(); i++) {
                char c = sb.charAt(i);
                if (c >= 'A' && c <= 'Z') {
                    sb.setCharAt(i, (char)(c + 32));
                }
            }
            s = sb.toString();
            
            // C++: long d[10000] = {};
            // Java: long[] d = new long[10000];
            long[] d = new long[10000];
            
            // C++: for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }
            // Java: for (int i = 0; i < s.length(); i++){ d[s.charAt(i)] = 1; }
            for (int i = 0; i < s.length(); i++) {
                d[s.charAt(i)] = 1;
            }
            
            // C++: for (long i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
            // Java: for (int i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
            for (int i = 'a'; i <= 'z'; i++) {
                if (d[i] == 0) {
                    System.out.println("NO");
                    return;
                }
            }
            
            System.out.println("YES");
        }
        
        scanner.close();
    }
}
```
Double check: `d` is `long[]`. `s[i]` is `int` (char). `d[s[i]]` works in Java because `int` is auto-cast to `long` index.
Wait, `d` size is 10000. `s[i]` is char. If `s` contains characters > 10000, it throws IndexOutOfBoundsException.
In C++, `long d[10000]` is fixed size. If `s[i]` is large, it's undefined behavior or buffer overflow.
Assuming valid input (string contains only lowercase letters 'a'-'z'), max index is 122. Safe.

One small logic check: The C++ code initializes `d` with `= {}`.
In Java, `new long[10000]` initializes all elements to 0. Correct.

The C++ code `cin >> n` is followed by `cin >> s`.
If the input is just `n` and no string, `cin >> s` might block or fail.
However, usually in these problems, the input format is `n s`.
The C++ code does not check if `s` exists after `n`.
We will assume the input stream contains `n` and then `s`.

Final check on class name: `a_520`.

```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
        }
        
        // Read s
        if (scanner.hasNext()) {
            String s = scanner.next();
            
            // C++: void LowerCase(string &s)
            // Java: String is immutable, use StringBuilder
            StringBuilder sb = new StringBuilder(s);
            for (int i = 0; i < sb.length(); i++) {
                char c = sb.charAt(i);
                if (c >= 'A' && c <= 'Z') {
                    sb.setCharAt(i, (char)(c + 32));
                }
            }
            s = sb.toString();
            
            // C++: long d[10000] = {};
            // Java: long[] d = new long[10000];
            // Java arrays are initialized to 0 by default, matching C++ {}
            long[] d = new long[10000];
            
            // C++: for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }
            // Java: for (int i = 0; i < s.length(); i++){ d[s.charAt(i)] = 1; }
            for (int i = 0; i < s.length(); i++) {
                d[s.charAt(i)] = 1;
            }
            
            // C++: for (long i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
            // Java: for (int i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
            for (int i = 'a'; i <= 'z'; i++) {
                if (d[i] == 0) {
                    System.out.println("NO");
                    return;
                }
            }
            
            System.out.println("YES");
        }
        
        scanner.close();
    }
}
```
One nuance: `long n` is read but not used. The C++ code does `cin >> n`.
Then `cin >> s`.
Then `LowerCase(s)`.
Then loop `s`.
Then loop `d`.
Then output.

The C++ code: `long d[10000] = {};`
The C++ code: `for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }`
If `s` is "hello", `d['h']`, `d['e']`, etc. become 1.
Then loop `i` from 'a' to 'z'. Check if `d[i] == 0`.
If any missing, print "NO", else "YES".

This logic is preserved.

One detail: `if (scanner.hasNextLong())` is good practice, but strictly speaking, if the input doesn't match C++ behavior (which might wait for input), we might just do `long n = scanner.nextLong();`. However, adding `hasNext` checks is safer for Java. But to be *exact* translation of behavior, we should probably just call `nextLong()` assuming valid input as per C++.
Actually, if I add `if (scanner.hasNextLong())` and the input is empty, the C++ code would wait indefinitely for `n`.
If I don't check `hasNext` and input is empty, Java throws `NoSuchElementException`.
Standard competitive programming translation usually assumes valid input.
I will remove the `if` checks to make it a direct translation of the control flow, assuming valid input as implied by the C++ code structure.

Revised Code:
```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // C++: cin >> n;
        long n = scanner.nextLong();
        
        // C++: cin >> s;
        String s = scanner.next();
        
        // C++: LowerCase(s);
        // Java: String is immutable, use StringBuilder
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                sb.setCharAt(i, (char)(c + 32));
            }
        }
        s = sb.toString();
        
        // C++: long d[10000] = {};
        long[] d = new long[10000];
        
        // C++: for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }
        for (int i = 0; i < s.length(); i++) {
            d[s.charAt(i)] = 1;
        }
        
        // C++: for (long i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
        for (int i = 'a'; i <= 'z'; i++) {
            if (d[i] == 0) {
                System.out.println("NO");
                return;
            }
        }
        
        System.out.println("YES");
    }
}
```
This looks correct and robust.

Wait, `long` in C++ is at least 32-bit. `int` in Java is 32-bit.
Using `int` for loop counters `i` is fine.
Using `int` for array index `s[i]` is fine.
The C++ code uses `long` for `i` and `d`. Java `int` is sufficient and preferred for indices.
The C++ code `long n` is read. `long` in Java is 64-bit. `long n = scanner.nextLong()` is correct.

One detail: `s` in C++ is `string`. `cin >> s` reads a word.
In Java `scanner.next()` reads a token.
This matches.

Final check on the provided C++ code logic:
`d[s[i]] = 1`.
If `s` has length 5, `i` goes 0..4. `s[i]` is char. `d[char]` is accessed.
Then loop `i` from 'a' to 'z'.
If `d[i] == 0`, print NO.
This checks if every letter from 'a' to 'z' appears in `s`.
This is a "check if string contains all lowercase letters" logic.

The translation is solid.

One minor thing: `import <iostream>` -> `import java.util.Scanner;`.
`using namespace std;` -> Not needed explicitly in Java, but `System` is used.
`string` -> `String`.
`long` -> `long` (Java long is 64-bit, C++ long is usually 32-bit or 64-bit).
`cin` -> `scanner.nextLong()`, `scanner.next()`.
`cout` -> `System.out.println()`.
`return 0` -> `return`.

I will write the final code block now.

```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // C++: cin >> n;
        // Reading n as long
        long n = scanner.nextLong();
        
        // C++: cin >> s;
        // Reading s as String
        String s = scanner.next();
        
        // C++: LowerCase(s);
        // In Java, String is immutable. We use StringBuilder to modify characters.
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            // C++: if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            // In Java, char promotes to int. We modify the character in the builder.
            if (c >= 'A' && c <= 'Z') {
                sb.setCharAt(i, (char)(c + 32));
            }
        }
        // Update s reference to the modified StringBuilder content
        s = sb.toString();
        
        // C++: long d[10000] = {};
        // Java initializes arrays to 0 by default.
        long[] d = new long[10000];
        
        // C++: for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }
        // Java: for (int i = 0; i < s.length(); i++){ d[s.charAt(i)] = 1; }
        // Note: Using int for index is standard in Java.
        for (int i = 0; i < s.length(); i++) {
            d[s.charAt(i)] = 1;
        }
        
        // C++: for (long i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
        for (int i = 'a'; i <= 'z'; i++) {
            if (d[i] == 0) {
                System.out.println("NO");
                return;
            }
        }
        
        System.out.println("YES");
    }
}
```
Wait, I should check if `s` is null or empty before accessing `s.length()`?
The C++ code assumes `s` is valid. `cin >> s` skips whitespace. If input is empty, it blocks.
If `s` is empty, `s.length()` is 0. `LowerCase` does nothing. `d` remains all 0. Loop `a` to `z` finds 0. Prints NO.
This is consistent.

One small detail: `s` is declared `string s;` then `cin >> s;`.
In Java `String s = scanner.next();`.
This is fine.

The solution seems complete.

```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // C++: cin >> n;
        // Reading n as long
        long n = scanner.nextLong();
        
        // C++: cin >> s;
        // Reading s as String
        String s = scanner.next();
        
        // C++: LowerCase(s);
        // In Java, String is immutable. We use StringBuilder to modify characters.
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            // C++: if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            // In Java, char promotes to int. We modify the character in the builder.
            if (c >= 'A' && c <= 'Z') {
                sb.setCharAt(i, (char)(c + 32));
            }
        }
        // Update s reference to the modified StringBuilder content
        s = sb.toString();
        
        // C++: long d[10000] = {};
        // Java initializes arrays to 0 by default.
        long[] d = new long[10000];
        
        // C++: for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }
        // Java: for (int i = 0; i < s.length(); i++){ d[s.charAt(i)] = 1; }
        // Note: Using int for index is standard in Java.
        for (int i = 0; i < s.length(); i++) {
            d[s.charAt(i)] = 1;
        }
        
        // C++: for (long i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
        for (int i = 'a'; i <= 'z'; i++) {
            if (d[i] == 0) {
                System.out.println("NO");
                return;
            }
        }
        
        System.out.println("YES");
    }
}
```
Double check one thing: `d` is `long`. `d[s[i]] = 1`.
`s[i]` is char. `char` to `int` conversion is automatic.
`d` is `long[]`. Index is `int`.
This is valid Java.

The plan is:
1. Class `a_520`.
2. `Scanner` for IO.
3. `LowerCase` logic using `StringBuilder`.
4. `d` array.
5. Loop checks.
6. Output.

This covers all aspects.

One subtle thing: The C++ code `string s; string x = "hello";`.
`x` is defined but never used.
`cin >> s;` overwrites `s`.
So `x` is dead code. I will remove `String x = "hello";` as it is not used in the logic.
Wait, `cin >> s` reads into `s`. `x` is not involved.
I should remove the unused variable `x` to make the Java code clean, unless I want to be strictly 1:1 including dead code.
Usually, "translate" implies making it functional Java code. Dead code in C++ is dead code in Java.
However, `x` is never used. I will leave it out to keep the code clean, or include it if strict translation is needed.
Given the instruction "translate this C++ code", usually implies preserving functionality. Unused variables are often removed for clarity.
But `string x = "hello";` is there.
Actually, if I include it, it's fine.
I will include `String x = "hello";` just to be faithful to the provided snippet, even though it's unused.
Wait, `cin >> s` reads into `s`. `x` is not touched.
Okay, I will include `String x = "hello";` to match the C++ structure exactly.

Wait, `string x = "hello";` is before `cin >> s`.
So `x` is initialized to "hello". Then `s` is read from input.
I will keep `String x = "hello";` to be faithful.

Revised plan:
1. Class `a_520`.
2. `Scanner`.
3. `long n`.
4. `String x = "hello";`.
5. `String s`.
6. `LowerCase` logic.
7. `d` array.
8. Logic.

Okay, ready to generate.

```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // C++: long n; cin >> n;
        long n = scanner.nextLong();
        
        // C++: string x = "hello";
        String x = "hello";
        
        // C++: string s; cin >> s;
        String s = scanner.next();
        
        // C++: LowerCase(s);
        // Java: String is immutable, use StringBuilder
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                sb.setCharAt(i, (char)(c + 32));
            }
        }
        s = sb.toString();
        
        // C++: long d[10000] = {};
        long[] d = new long[10000];
        
        // C++: for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }
        for (int i = 0; i < s.length(); i++) {
            d[s.charAt(i)] = 1;
        }
        
        // C++: for (long i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
        for (int i = 'a'; i <= 'z'; i++) {
            if (d[i] == 0) {
                System.out.println("NO");
                return;
            }
        }
        
        System.out.println("YES");
    }
}
```
This looks perfect.
</think>

### Translation Plan

1.  **Class Structure**:
    *   The C++ `main` function is translated into the `public static void main(String[] args)` method within the class `a_520`.
    *   The C++ `using namespace std;` is replaced by importing specific Java packages (`java.util.Scanner`).

2.  **Input/Output**:
    *   C++ `cin >> n` and `cout << "..."` are translated to Java's `Scanner` class (`scanner.nextLong()`) and `System.out.println()`.
    *   C++ `string` is translated to Java's `String` class.

3.  **Mutable Strings**:
    *   The C++ function `LowerCase(string &s)` modifies the string in place.
    *   Java `String` is immutable. To achieve the same effect, we use `StringBuilder`. We iterate through the `StringBuilder`, check for uppercase characters (`'A'` to `'Z'`), and replace them with lowercase characters (`char + 32`). Finally, we convert the `StringBuilder` back to a `String`.

4.  **Arrays**:
    *   C++ `long d[10000] = {};` is translated to `long[] d = new long[10000];`.
    *   Java initializes arrays with `0` by default, which matches the C++ initialization `{}`.

5.  **Logic and Control Flow**:
    *   The loop `for (long i = 0; i < s.length(); i++)` is translated to `for (int i = 0; i < s.length(); i++)` using Java's `int` for indices.
    *   Character access `s[i]` becomes `s.charAt(i)`.
    *   The logic checking for missing characters (`if (d[i] == 0)`) remains the same, printing "NO" and returning, or printing "YES" if the loop completes.
    *   Unused variables (like `string x = "hello";` in the C++ snippet) are preserved in the Java code to maintain a faithful translation, though they are not used in the logic.

```java
import java.util.Scanner;

public class a_520 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // C++: long n; cin >> n;
        long n = scanner.nextLong();
        
        // C++: string x = "hello";
        String x = "hello";
        
        // C++: string s; cin >> s;
        String s = scanner.next();
        
        // C++: void LowerCase(string &s) { ... }
        // Java: String is immutable, so we use StringBuilder to modify it.
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            // C++: if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            // Java: char promotes to int. We set the character at index i to (char)(c + 32).
            if (c >= 'A' && c <= 'Z') {
                sb.setCharAt(i, (char)(c + 32));
            }
        }
        s = sb.toString();
        
        // C++: long d[10000] = {};
        // Java: Arrays are initialized to 0 by default.
        long[] d = new long[10000];
        
        // C++: for (long i = 0; i < s.length(); i++){ d[s[i]] = 1; }
        // Java: Using int for loop index is standard.
        for (int i = 0; i < s.length(); i++) {
            d[s.charAt(i)] = 1;
        }
        
        // C++: for (long i = 'a'; i <= 'z'; i++){ if (d[i] == 0) ... }
        for (int i = 'a'; i <= 'z'; i++) {
            if (d[i] == 0) {
                System.out.println("NO");
                return;
            }
        }
        
        System.out.println("YES");
    }
}
```