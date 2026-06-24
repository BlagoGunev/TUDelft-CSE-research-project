Translate this C++ code to Java code. The main class name should be d_353. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define lld I64d

const int maxn = 1000010;
char s[maxn];

int main() {
#ifdef ONLINE_JUDGE
    //freopen("revolutions.in", "r", stdin);
    //freopen("revolutions.out", "w", stdout);
#endif
	int n;
	scanf("%s", s);
	n = strlen(s);
	int numb = 0;
	int pos = n - 1;
	while (pos >= 0 && s[pos] == 'M') {
		pos--;
	}
	while (pos >= 0 && s[pos] == 'F') {
		numb++;
		pos--;
	}
	if (pos == -1) {
		printf("0");
		return 0;
	}
	int ans = numb;
	int last_ans = 0;
	for (int i = pos - 1; i >= 0; i--) {
		if (s[i] == 'F') {
			numb++;
		} else {
			last_ans = max(0, last_ans + 2 - pos + i);
			ans = numb + last_ans;
			pos = i;
		}
	}
	printf("%d", ans);
	return 0;
}

Here is the plan for translating the provided C++ code to Java.

### Translation Plan

1.  **Header and Imports**:
    *   Replace C++ headers (`<cstdio>`, `<iostream>`, `<string>`, `<algorithm>`, etc.) with necessary Java imports (`java.util.Scanner`, `java.util.Arrays`, `java.util.StringTokenizer`).
    *   The C++ `#pragma comment` is a linker directive specific to MSVC and is not needed in Java. It is removed.
    *   The `#define lld I64d` is not used in the code, so it is ignored.

2.  **Class Structure**:
    *   The C++ `main` function becomes the `public static void main(String[] args)` method.
    *   The class name is defined as `d_353`.

3.  **Data Types and Variables**:
    *   C++ `int` maps to Java `int`.
    *   C++ `long long` (implied by `lld` or `I64d`) is not explicitly used for `n` or `ans` here, but standard `int` is sufficient for the logic provided.
    *   The global character array `char s[maxn]` is replaced by a `String` or `char[]` buffer. Since `scanf("%s", s)` reads into a fixed-size array, using a `StringBuilder` or `char[]` in Java is safer and more idiomatic than `String` for mutable operations, though `String` is immutable. Given the logic modifies indices but not the content, a `char[]` array or `String` is fine. To match the C++ fixed buffer approach (`maxn`), a `char[]` of size `1000010` is created.

4.  **Input/Output**:
    *   C++ `scanf("%s", s)` and `strlen(s)` are replaced by `Scanner.next()` and `s.length()`.
    *   C++ `printf` is replaced by `System.out.print`.
    *   `freopen` (file redirection) is commented out as it is not standard in Java.

5.  **Logic Translation**:
    *   `max` function: C++ `std::max` is replaced by `Math.max`.
    *   The loop logic remains identical, just changing syntax (e.g., `while` loops, array indexing).
    *   The `#ifdef ONLINE_JUDGE` block is kept but adapted to Java's standard `Scanner` usage, removing the file redirection logic which is specific to C++ file I/O.

6.  **Incremental Tasks**:
    *   Define class and imports.
    *   Implement input reading.
    *   Implement string length and index logic.
    *   Implement the counting loops (`while` loops for 'M' and 'F').
    *   Implement the final loop and `max` calculation.
    *   Implement output and return.

### Java Code

```CODE
import java.util.Scanner;

public class d_353 {
    // Maximum size as defined in C++
    private static final int MAXN = 1000010;
    // Buffer to store the string, similar to char s[maxn]
    private static char[] s = new char[MAXN];

    public static void main(String[] args) {
        // Reading input using Scanner
        // In C++: scanf("%s", s);
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String inputStr = scanner.next();
            // Copy string to char array to simulate char s[] behavior
            // In Java, we can just use the String directly or copy it.
            // To match the C++ logic of 's' being an array, we copy it.
            // However, the logic only reads s[i], so using String is also valid.
            // We will use the char array to strictly follow the C++ structure.
            for (int i = 0; i < inputStr.length(); i++) {
                s[i] = inputStr.charAt(i);
            }
            
            int n = inputStr.length();
            
            // Logic translation:
            // int numb = 0;
            // int pos = n - 1;
            // while (pos >= 0 && s[pos] == 'M') { pos--; }
            // while (pos >= 0 && s[pos] == 'F') { numb++; pos--; }
            // if (pos == -1) { printf("0"); return 0; }
            
            int numb = 0;
            int pos = n - 1;
            
            // Skip trailing 'M's
            while (pos >= 0 && s[pos] == 'M') {
                pos--;
            }
            
            // Count 'F's immediately preceding 'M's
            while (pos >= 0 && s[pos] == 'F') {
                numb++;
                pos--;
            }
            
            // Check if string ends with 'F's (pos == -1 means all were consumed)
            if (pos == -1) {
                System.out.print("0");
                return;
            }
            
            int ans = numb;
            int last_ans = 0;
            
            // Main loop
            // for (int i = pos - 1; i >= 0; i--) { ... }
            for (int i = pos - 1; i >= 0; i--) {
                if (s[i] == 'F') {
                    numb++;
                } else {
                    // last_ans = max(0, last_ans + 2 - pos + i);
                    last_ans = Math.max(0, last_ans + 2 - pos + i);
                    ans = numb + last_ans;
                    // pos = i;
                    pos = i;
                }
            }
            
            System.out.print(ans);
        }
    }
}
```
</think>

Here is the plan for translating the C++ code to Java.

### Translation Plan

1.  **Imports and Class Definition**:
    *   C++ includes (`<cstdio>`, `<iostream>`, etc.) are replaced by Java imports (`java.util.Scanner`, `java.lang.Math`).
    *   The C++ `main` function is converted into the standard Java `public static void main(String[] args)` method.
    *   The class name is set to `d_353`.

2.  **Memory and Input Handling**:
    *   The C++ global character array `char s[maxn]` is mapped to a Java `char[]` array of size `1000010`.
    *   C++ `scanf("%s", s)` is replaced by `Scanner.next()`. Since Java Strings are immutable, we copy the string from `Scanner.next()` into the `char[]` buffer to match the C++ structure.
    *   C++ `strlen(s)` is replaced by `s.length` (or `inputStr.length()` before copying).
    *   C++ `printf` is replaced by `System.out.print`.
    *   The `#ifdef ONLINE_JUDGE` block is simplified. Java does not support `freopen` in the same way, so standard `System.in` is used.

3.  **Logic Translation**:
    *   C++ `std::max` is replaced by Java `Math.max`.
    *   The loops (`while`, `for`) and conditional logic (`if`, `else`) remain syntactically similar but use Java syntax.
    *   Variable types (`int`) remain `int`.

4.  **Incremental Tasks**:
    *   **Step 1**: Define the class and imports.
    *   **Step 2**: Implement the input reading logic (Scanner and char array population).
    *   **Step 3**: Implement the initial `while` loops to count 'F's and skip 'M's.
    *   **Step 4**: Implement the final `for` loop and calculation logic.
    *   **Step 5**: Output the result.

### Java Code

```CODE
import java.util.Scanner;

public class d_353 {
    // Maximum size as defined in C++ (maxn = 1000010)
    private static final int MAXN = 1000010;
    // Buffer to store the string, similar to char s[maxn]
    private static char[] s = new char[MAXN];

    public static void main(String[] args) {
        // Reading input using Scanner
        // In C++: scanf("%s", s);
        Scanner scanner = new Scanner(System.in);
        
        if (scanner.hasNext()) {
            String inputStr = scanner.next();
            
            // Copy string to char array to simulate char s[] behavior
            // In Java, we can just use the String directly or copy it.
            // We use the char array to strictly follow the C++ structure.
            for (int i = 0; i < inputStr.length(); i++) {
                s[i] = inputStr.charAt(i);
            }
            
            int n = inputStr.length();
            
            // Logic translation:
            // int numb = 0;
            // int pos = n - 1;
            // while (pos >= 0 && s[pos] == 'M') { pos--; }
            // while (pos >= 0 && s[pos] == 'F') { numb++; pos--; }
            // if (pos == -1) { printf("0"); return 0; }
            
            int numb = 0;
            int pos = n - 1;
            
            // Skip trailing 'M's
            while (pos >= 0 && s[pos] == 'M') {
                pos--;
            }
            
            // Count 'F's immediately preceding 'M's
            while (pos >= 0 && s[pos] == 'F') {
                numb++;
                pos--;
            }
            
            // Check if string ends with 'F's (pos == -1 means all were consumed)
            if (pos == -1) {
                System.out.print("0");
                return;
            }
            
            int ans = numb;
            int last_ans = 0;
            
            // Main loop
            // for (int i = pos - 1; i >= 0; i--) { ... }
            for (int i = pos - 1; i >= 0; i--) {
                if (s[i] == 'F') {
                    numb++;
                } else {
                    // last_ans = max(0, last_ans + 2 - pos + i);
                    last_ans = Math.max(0, last_ans + 2 - pos + i);
                    ans = numb + last_ans;
                    // pos = i;
                    pos = i;
                }
            }
            
            System.out.print(ans);
        }
    }
}
```