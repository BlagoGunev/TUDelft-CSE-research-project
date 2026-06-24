Translate this C++ code to Java code. The main class name should be c_219. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <string.h>
#include<cstring>
#include<stdio.h>
using namespace std;
char a[500001];
int main ()
{
    int n,p;
while(cin>>n>>p)
    {
        scanf("%s",a);
        int cou=0;
        if(p==2)
        {
            for(int i=1;i<n;i++){
                if(a[i]==a[i-1]){
                    cou++;
                    if(a[i]=='A')  a[i]='B';
                    else a[i]='A';
                }
            }
            if(cou<=n/2)
               printf("%d\n%s\n",cou,a);
            else {
                   for(int i=0;i<n;i++) a[i]='A'+'B'-a[i];
                   printf("%d\n%s\n",n-cou,a);
            }
        }
        else {
             for(int i=1;i<n;i++){
                 if(a[i]==a[i-1]){
                    cou++;
                    if(a[i]=='A') {
                        if(a[i+1]!='B')
                           a[i]='B';
                        else a[i]='C';
                    }
                    else {
                        if(a[i+1]!='A')
                             a[i]='A';
                        else {
                            if(a[i-1]!='B')
                               a[i]='B';
                            else a[i]='C';
                        }
                    }
                }
             }
            printf("%d\n%s\n",cou,a);
        }
}
}

Here is the plan for translating the C++ code to Java:

### Translation Plan

1.  **Class Structure**:
    *   Create a class named `c_219` as requested.
    *   The `main` method will be placed inside this class.

2.  **Input/Output Handling**:
    *   **C++**: Uses `cin` for integers and `scanf` for strings.
    *   **Java**: Use `Scanner` class (`java.util.Scanner`) for input.
        *   `cin >> n >> p` translates to `sc.nextInt()` followed by `sc.nextInt()`.
        *   `scanf("%s", a)` translates to `sc.next()`.
    *   **Output**: `printf` translates to `System.out.println`.

3.  **Data Structures and Arrays**:
    *   **C++**: `char a[500001]` is a C-style character array.
    *   **Java**: Use a `char[]` array. The size should be 500001 (or slightly larger to be safe, e.g., 500005) to accommodate the input string. Note that Java arrays are 0-indexed, whereas the C++ logic iterates from index 1. We must map the logic carefully.

4.  **Logic Translation**:
    *   **Looping**: `while(cin >> n >> p)` translates to a `while` loop checking `sc.hasNext()`. Inside the loop, read `n`, `p`, and the string.
    *   **Character Comparison**: `a[i] == a[i-1]` works directly in Java.
    *   **Character Modification**:
        *   `a[i] = 'A'` translates to `a[i] = 'A'`.
        *   `a[i] = 'B'` translates to `a[i] = 'B'`.
        *   Arithmetic like `a[i] = 'A' + 'B' - a[i]` is valid in Java for characters.
    *   **String Conversion**: The C++ code prints the modified array directly. In Java, we need to convert the `char[]` to a `String` using `new String(a)` before printing.
    *   **Edge Cases**:
        *   The C++ code iterates `i` from `1` to `n-1`.
        *   If the input string is read into a Java array, we need to ensure we only process the characters corresponding to the length `n`.
        *   **Important Logic Check**: The C++ code reads the string into `a` (0-indexed). It iterates `i` from 1 to `n-1`. It compares `a[i]` with `a[i-1]`. This implies it ignores the first character (`a[0]`) for comparison purposes, or rather, it treats the loop as starting from the second character.
        *   However, the logic inside the loop modifies `a[i]` based on `a[i-1]` and `a[i+1]`.
        *   **Java Array Bounds**: If `n` is large, `a` must be large enough. `a` is allocated as 500001. If the input string is exactly 500,000 characters, accessing `a[i+1]` where `i = n-1` (i.e., index 499,999) is safe (index 500,000). If `n` is 500,001, index 500,001 is out of bounds. Given the C++ array size is 500001 (indices 0 to 500000), `n` can be at most 500001. If `n` is 500001, the last index is 500000. The loop goes up to `n-1` (499,999). Inside the loop, it accesses `a[i+1]` which is `a[500,000]`. This is safe.
        *   **String Reading**: `scanf("%s", a)` reads a null-terminated string. In C++, if the string is "ABC", `a` might look like `{'A', 'B', 'C', '\0', ...}`. The length `n` is read separately. In Java, `sc.next()` reads the string token. We convert it to a char array. We must ensure the char array has enough space or we just work with the string returned by `next()`. Since we are modifying the array in place, creating a char array from the string is the best approach.
        *   **Logic nuance**: The C++ code modifies `a` in place. If we read a string into a Java `String`, we cannot modify it. We must read it into a `char[]`.

5.  **Incremental Tasks**:
    *   Task 1: Setup class, imports, and input loop structure.
    *   Task 2: Handle the `p == 2` case (simple toggle).
    *   Task 3: Handle the `p != 2` case (complex logic).
    *   Task 4: Handle output and main loop termination.

### Implementation Details

*   **Input**: `Scanner` reads `n` and `p`. Then it reads the string.
*   **Array**: `char[] a = new char[500005];` (slightly larger than C++ to be safe, though 500001 is strictly sufficient for `n` up to 500000, and `n=500001` is technically possible in C++ with `char a[500001]` if `n` is the length. Wait, if `n` is the length, and `n=500001`, indices are `0..500000`. `i` goes to `499999`. `i+1` is `500000`. This fits exactly. I will use 500005 to be safe).
*   **Loop**: `while(sc.hasNext())` or `while(true)` with a break. Since the problem implies a stream of inputs, `while(sc.hasNext())` is safer, but we need to parse `n` and `p` first. The C++ code assumes valid input. We will assume valid input matching the format.
*   **Logic Preservation**:
    *   `cou` counter.
    *   If `p==2`: Iterate `1` to `n-1`. If `a[i] == a[i-1]`, increment `cou` and toggle `a[i]`. Check `cou` vs `n/2`.
    *   If `p!=2`: Iterate `1` to `n-1`. If `a[i] == a[i-1]`, increment `cou`.
        *   Logic involves checking `a[i+1]` and `a[i-1]` to decide whether to change `a[i]` to 'B' or 'C'.
        *   Specifically:
            *   If `a[i]` is 'A': Change to 'B' if `a[i+1]` is not 'B', else 'C'.
            *   If `a[i]` is 'B' (else branch): Change to 'A' if `a[i+1]` is not 'A', else check `a[i-1]`. If `a[i-1]` is not 'B', change to 'B', else 'C'.
    *   Print `cou` and the resulting string.

### Code Construction

```java
import java.util.Scanner;

public class c_219 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Buffer size: C++ uses 500001. We need to accommodate n.
        // If n is the length of the string, indices are 0 to n-1.
        // The loop in C++ goes up to i < n. Inside the loop it accesses a[i+1].
        // So max index accessed is n-1+1 = n.
        // If n=500001, max index is 500001. 
        // C++ array size 500001 covers indices 0 to 500000.
        // If n=500001, accessing a[n] (index 500001) would be out of bounds in C++ code if n was actually the size limit?
        // Wait, the C++ code: char a[500001]; int n; scanf("%s", a);
        // If the string length is 500000, n=500000. Indices 0..499999. Loop 1..499999. Accesses a[500000]. Safe.
        // If the string length is 500001, n=500001. Indices 0..500000. Loop 1..500000. Accesses a[500001]. 
        // C++ array size 500001 means valid indices are 0..500000. Accessing a[500001] is Out Of Bounds in C++ too?
        // Actually, usually in competitive programming, n <= 500000 for this array size.
        // To be safe in Java, we will allocate a bit more.
        char[] a = new char[500005]; 

        while (sc.hasNext()) {
            if (!sc.hasNextInt()) break; // Safety check
            int n = sc.nextInt();
            int p = sc.nextInt();
            String s = sc.next();
            
            // Copy string to char array
            // Ensure string length matches n? Usually yes. 
            // Just copy the string content.
            for (int i = 0; i < s.length(); i++) {
                a[i] = s.charAt(i);
            }
            // Pad the rest of the array with null or just ignore. 
            // The logic depends on 'n'. We must use 'n' for loop bounds.
            // The C++ code uses 'n' as the length.
            
            int cou = 0;
            if (p == 2) {
                // Logic for p==2
                // C++: for(int i=1;i<n;i++)
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') a[i] = 'B';
                        else a[i] = 'A';
                    }
                }
                if (cou <= n / 2) {
                    System.out.println(cou + "\n" + new String(a, 0, n));
                } else {
                    // Invert logic
                    for (int i = 0; i < n; i++) {
                        a[i] = (char) ('A' + 'B' - a[i]);
                    }
                    System.out.println((n - cou) + "\n" + new String(a, 0, n));
                }
            } else {
                // Logic for p!=2
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            // Check a[i+1]
                            // In C++, a[i+1] is accessed. We assume n > 1 here?
                            // If n=1, loop doesn't run. Safe.
                            if (i + 1 < n && a[i+1] != 'B') {
                                a[i] = 'B';
                            } else {
                                a[i] = 'C';
                            }
                        } else { // a[i] == 'B'
                            if (i + 1 < n && a[i+1] != 'A') {
                                a[i] = 'A';
                            } else {
                                if (i - 1 >= 0 && a[i-1] != 'B') {
                                    a[i] = 'B';
                                } else {
                                    a[i] = 'C';
                                }
                            }
                        }
                    }
                }
                System.out.println(cou + "\n" + new String(a, 0, n));
            }
        }
        sc.close();
    }
}
```

Wait, looking closely at the C++ code:
`if(a[i+1]!='B')`
In C++, `a` is a char array. `a[i+1]` accesses the next element.
If `n` is the length of the string, and the array is filled with the string, `a[n-1]` is the last char.
The loop runs `i` from `1` to `n-1`.
Max `i` is `n-1`.
Inside the loop, it accesses `a[i+1]`.
Max index accessed is `n`.
The array `a` is declared `char a[500001]`. Indices `0` to `500000`.
If `n` is `500001`, the loop goes `1` to `500000`.
Inside loop, `i` can be `500000`. `a[i+1]` accesses `a[500001]`.
This is **Out of Bounds** for `char a[500001]` in C++ (valid indices 0..500000).
However, usually in these problems, `n` is bounded such that `n <= 500000` or the array is large enough.
If `n` is strictly the length of the string read by `scanf`, and the string is read into `a`, then `a` is filled up to `n-1`.
If `n` is large (e.g., 500001), the C++ code might segfault or behave unexpectedly on `a[i+1]` if `i=n-1`.
BUT, looking at the logic, it seems `a` might be pre-filled or `n` is guaranteed to be small enough?
Actually, `scanf("%s", a)` reads characters until whitespace. It does not null-terminate strictly if it hits the buffer limit without null terminator, but `scanf` with `%s` stops at whitespace.
If the input string is "A" repeated 500001 times. `n` becomes 500001.
`a` has size 500001. Indices 0..500000.
Loop `i` goes 1..500000.
When `i=500000`, `a[i+1]` accesses `a[500001]`. This is invalid memory access in C++.
However, I must translate the code faithfully. I will assume the test cases respect the bounds or that `n` is small enough (<= 500000).
Wait, if `n` is 500000, loop is 1..499999. `i+1` is 500000. Valid.
So `n` must be <= 500000 for the C++ code to be safe.
In Java, I will allocate `new char[500005]` to be safe.

One detail: `scanf("%s", a)` reads a string.
In Java `sc.next()` reads a string.
The C++ code iterates `i` from `1` to `n-1`.
It compares `a[i]` and `a[i-1]`.
This means it processes pairs `(a[1], a[0])`, `(a[2], a[1])`, ..., `(a[n-1], a[n-2])`.
It ignores `a[0]` as a target for modification based on `a[0] == a[-1]` (which doesn't exist).
So `a[0]` is never modified in the loop.
The logic modifies `a[i]` based on `a[i-1]`.
For `p != 2`, it also checks `a[i+1]` and `a[i-1]`.
Wait, if `i = n-1`, `a[i+1]` is out of bounds.
If `n` is the length, `a[n-1]` is the last character. `a[n]` is uninitialized or null.
If the C++ code accesses `a[n]`, it is technically undefined behavior if `a` is size `n`.
But I will translate it as is, assuming the environment handles it or `n` is small enough.
Actually, in Java, accessing `a[n]` where `n` is length of string and array size is `n` (or slightly more) will throw IndexOutOfBounds if `n` is the length.
Wait, if `a` is size `500001`, and `n` is `500000`. `a` indices `0..500000`.
If `n` is `500000`, loop `1..499999`. `i+1` is `500000`. `a[500000]` is valid.
So `n` must be `<= 500000`.
If `n` is `500001`, `i` goes to `500000`. `i+1` is `500001`. `a[500001]` is invalid for `char[500001]`.
I will assume the input `n` respects the array bounds of the original C++ code (i.e., `n <= 500000`).
However, to be robust in Java, I will make the array `500005` and ensure `n` is used for logic.
Actually, looking at the code `scanf("%s", a)`, `a` is a fixed buffer.
If the input string is longer than the buffer, `scanf` behavior is undefined/overflow.
Assuming valid input within buffer limits.

One subtle point: `printf("%d\n%s\n",cou,a);`
In Java, `new String(a, 0, n)` creates a string from the char array up to `n`.
The `else` block in `p==2`:
`for(int i=0;i<n;i++) a[i]='A'+'B'-a[i];`
This inverts the characters (A<->B).
`'A' + 'B' - 'A'` = `'B'`.
`'A' + 'B' - 'B'` = `'A'`.
This logic is preserved.

Final check on `p!=2` logic:
```cpp
if(a[i]=='A') {
    if(a[i+1]!='B') a[i]='B';
    else a[i]='C';
}
else { // a[i] == 'B'
    if(a[i+1]!='A') a[i]='A';
    else {
        if(a[i-1]!='B') a[i]='B';
        else a[i]='C';
    }
}
```
This logic is preserved.

One thing: `Scanner` might be slow for very large inputs, but for `500000` chars it's usually acceptable for simple translation tasks unless Time Limit is extremely strict. Given the task is translation, I will use `Scanner`.

```java
import java.util.Scanner;

public class c_219 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // C++ code uses char a[500001]. 
        // We allocate slightly more to prevent OOB in Java if n is close to 500001.
        char[] a = new char[500005];
        
        while (sc.hasNext()) {
            if (!sc.hasNextInt()) break;
            int n = sc.nextInt();
            int p = sc.nextInt();
            String s = sc.next();
            
            // Copy string to char array
            // Ensure we don't copy beyond n if n < s.length(), though usually n == s.length()
            for (int i = 0; i < s.length() && i < n; i++) {
                a[i] = s.charAt(i);
            }
            // Fill the rest with null chars or just leave as is (default is \u0000)
            // The logic relies on n.
            
            int cou = 0;
            if (p == 2) {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            a[i] = 'B';
                        } else {
                            a[i] = 'A';
                        }
                    }
                }
                if (cou <= n / 2) {
                    System.out.println(cou + "\n" + new String(a, 0, n));
                } else {
                    for (int i = 0; i < n; i++) {
                        a[i] = (char) ('A' + 'B' - a[i]);
                    }
                    System.out.println((n - cou) + "\n" + new String(a, 0, n));
                }
            } else {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            // Check a[i+1]
                            // Ensure i+1 is within bounds of n (and array)
                            if (i + 1 < n && a[i+1] != 'B') {
                                a[i] = 'B';
                            } else {
                                a[i] = 'C';
                            }
                        } else { // a[i] == 'B'
                            if (i + 1 < n && a[i+1] != 'A') {
                                a[i] = 'A';
                            } else {
                                if (i - 1 >= 0 && a[i-1] != 'B') {
                                    a[i] = 'B';
                                } else {
                                    a[i] = 'C';
                                }
                            }
                        }
                    }
                }
                System.out.println(cou + "\n" + new String(a, 0, n));
            }
        }
        sc.close();
    }
}
```
Wait, `sc.hasNext()` loops until EOF.
Inside the loop, `sc.nextInt()` reads `n` and `p`.
`sc.next()` reads the string.
The C++ code `while(cin>>n>>p)` implies it reads pairs until EOF.
My Java translation does the same.

One detail: `a` is `char[]`.
In C++, `char` is signed/unsigned 8-bit. In Java, `char` is 16-bit Unicode.
'A' and 'B' are standard ASCII.
The logic `'A' + 'B' - a[i]` works for ASCII characters.
`'A'` is 65, `'B'` is 66.
If `a[i]` is 'A' (65), `65+66-65 = 66` ('B').
If `a[i]` is 'B' (66), `65+66-66 = 65` ('A').
This works.

Wait, `if (!sc.hasNextInt()) break;` is a safety measure.
If the input ends with whitespace, `hasNext()` might be true but `hasNextInt()` false.
Standard competitive programming template: `while (sc.hasNext()) { int n = sc.nextInt(); ... }` usually works if input is well-formed.
I will stick to `while(sc.hasNext())` and read `n`, `p`, `s`.
If `sc.next()` throws exception, it means input is malformed, which is fine.
The C++ code doesn't check for EOF explicitly, it relies on `cin >> n >> p` returning false.
In Java `sc.nextInt()` throws exception if no token.
So `while(sc.hasNext())` is correct.

Double check the array size.
C++: `char a[500001]`.
If `n` is 500001, indices `0` to `500000`.
Loop `i` from `1` to `500000`.
Access `a[i+1]` -> `a[500001]`.
This is **Out of Bounds** for `char a[500001]` (max index 500000).
So the C++ code provided actually has a potential bug if `n` is 500001.
However, I must translate the logic.
If I allocate `new char[500001]` in Java, and `n=500001`, `a[i+1]` throws Exception.
To be safe and faithful to the intent (assuming `n` fits), I will allocate `new char[500005]`.
This allows `n` up to 500004 safely.

One more check: `printf("%d\n%s\n",cou,a);`
In Java `System.out.println(cou + "\n" + new String(a, 0, n));`.
Note that `new String(a, 0, n)` creates a string from `a[0]` to `a[n-1]`.
This matches the C++ behavior of printing the string `a` of length `n`.

Final check on logic for `p!=2`:
The C++ code:
```cpp
if(a[i]=='A') {
    if(a[i+1]!='B') a[i]='B';
    else a[i]='C';
}
else {
    if(a[i+1]!='A') a[i]='A';
    else {
        if(a[i-1]!='B') a[i]='B';
        else a[i]='C';
    }
}
```
This logic is preserved.

```java
import java.util.Scanner;

public class c_219 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // C++ code uses char a[500001].
        // We allocate a slightly larger array to safely handle n up to 500001
        // where accessing a[i+1] might be required.
        char[] a = new char[500005];
        
        while (sc.hasNext()) {
            // Check if we can read n
            if (!sc.hasNextInt()) break;
            int n = sc.nextInt();
            int p = sc.nextInt();
            String s = sc.next();
            
            // Copy the input string into the char array
            for (int i = 0; i < s.length(); i++) {
                a[i] = s.charAt(i);
            }
            // Note: The C++ code iterates up to n-1. 
            // We assume the input string length corresponds to n.
            
            int cou = 0;
            if (p == 2) {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            a[i] = 'B';
                        } else {
                            a[i] = 'A';
                        }
                    }
                }
                if (cou <= n / 2) {
                    System.out.println(cou + "\n" + new String(a, 0, n));
                } else {
                    for (int i = 0; i < n; i++) {
                        a[i] = (char) ('A' + 'B' - a[i]);
                    }
                    System.out.println((n - cou) + "\n" + new String(a, 0, n));
                }
            } else {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            if (i + 1 < n && a[i+1] != 'B') {
                                a[i] = 'B';
                            } else {
                                a[i] = 'C';
                            }
                        } else { // a[i] == 'B'
                            if (i + 1 < n && a[i+1] != 'A') {
                                a[i] = 'A';
                            } else {
                                if (i - 1 >= 0 && a[i-1] != 'B') {
                                    a[i] = 'B';
                                } else {
                                    a[i] = 'C';
                                }
                            }
                        }
                    }
                }
                System.out.println(cou + "\n" + new String(a, 0, n));
            }
        }
        sc.close();
    }
}
```
Wait, I should remove the comments to make it cleaner, but keeping them explains the translation choices. I will keep the array size explanation.
Actually, I will simplify the loop condition `while(sc.hasNext())` to just `while(true)` with a break, or rely on `hasNext()`.
The C++ code `while(cin>>n>>p)` returns false when input ends.
In Java, `sc.hasNext()` returns false when input ends.
So `while(sc.hasNext())` is correct.

One minor detail: `scanf("%s",a)` reads a string.
If the string contains spaces, `scanf("%s")` stops at space.
`sc.next()` also stops at space.
So `n` should match the length of the token read by `sc.next()`.
The C++ code reads `n` then `scanf("%s", a)`.
If `n` is 5, and the string is "ABCDE", `n` is 5.
If `n` is 5, and the string is "ABC", `scanf` reads "ABC". `n` is 5.
Then loop `i` from 1 to 4. `a[4]` is `\0`.
`a[i-1]` is `a[3]` ('C').
`a[4]` is `\0`.
`\0` != 'C'.
It modifies `a[4]`.
But `a` is `char[500001]`.
The C++ code logic assumes `a` is filled with the string.
If `n` > string length, the rest of `a` is `\0`.
The Java code copies `s` into `a`.
If `n` > `s.length()`, `a` has `\0` at the end.
The loop runs up to `n-1`.
If `s.length() < n`, `a` has `\0`s.
This matches the C++ behavior (assuming `scanf` fills `a` with `\0` padding implicitly if not enough chars, but `scanf` stops at whitespace).
Actually, `scanf("%s", a)` fills `a` with the string and null-terminates it.
If `n` is larger than the string length, `a` has `'\0'` at `s.length()`.
So `a[i]` for `i >= s.length()` is `\0`.
This matches the behavior.
So `a` should be filled with `s` and then padded with `\0` up to `n`.
In Java, `char[]` is initialized to `\u0000`.
So `new char[500005]` is all `\0`.
Copying `s` into `a` fills `0` to `s.length()-1`.
If `n > s.length()`, the rest of `a` (up to `n`) remains `\0`.
This matches the C++ `scanf` behavior where `a` is filled with the string and the rest is `\0`.
So `new String(a, 0, n)` will include the `\0`s if `n > s.length()`.
Wait, `new String(char[])` ignores `\0` if passed the whole array?
`new String(a, 0, n)` takes `n` characters. If `a[n-1]` is `\0`, it prints it?
No, `new String(char[], int, int)` creates a string from the specified range.
If `a[n-1]` is `\0`, the string will end with `\0`?
No, `String` constructor does not include null terminators as characters usually?
Wait, `new String(char[] val, int offset, int len)` creates a string containing the characters from `val` starting at `offset` with length `len`.
If `val[len-1]` is `\0`, the string contains `\0` at the end.
When printed with `System.out.println`, `\0` is not visible.
So `new String(a, 0, n)` is correct.

Wait, `new String(char[])` creates a string from the whole array.
If I pass `a` (size 500005), it creates a huge string.
I must pass `new String(a, 0, n)`.
This is correct.

I will remove comments to make the code cleaner as per "output the code".
Actually, comments are good for explanation but the prompt asks for "code of the resulting program". I will keep it clean.
I'll remove the verbose comments about C++ specific features in the final code block to keep it clean, as the translation logic is internal.

One final check: `if (p==2)` block.
`if(cou<=n/2) printf("%d\n%s\n",cou,a);`
`else { for... a[i]='A'+'B'-a[i]; printf("%d\n%s\n",n-cou,a); }`
In Java:
`if (cou <= n / 2) { System.out.println(cou + "\n" + new String(a, 0, n)); } else { ... }`
This is correct.

I'll write the code now.

```java
import java.util.Scanner;

public class c_219 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] a = new char[500005];
        
        while (sc.hasNext()) {
            if (!sc.hasNextInt()) break;
            int n = sc.nextInt();
            int p = sc.nextInt();
            String s = sc.next();
            
            for (int i = 0; i < s.length(); i++) {
                a[i] = s.charAt(i);
            }
            
            int cou = 0;
            if (p == 2) {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            a[i] = 'B';
                        } else {
                            a[i] = 'A';
                        }
                    }
                }
                if (cou <= n / 2) {
                    System.out.println(cou + "\n" + new String(a, 0, n));
                } else {
                    for (int i = 0; i < n; i++) {
                        a[i] = (char) ('A' + 'B' - a[i]);
                    }
                    System.out.println((n - cou) + "\n" + new String(a, 0, n));
                }
            } else {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            if (i + 1 < n && a[i+1] != 'B') {
                                a[i] = 'B';
                            } else {
                                a[i] = 'C';
                            }
                        } else {
                            if (i + 1 < n && a[i+1] != 'A') {
                                a[i] = 'A';
                            } else {
                                if (i - 1 >= 0 && a[i-1] != 'B') {
                                    a[i] = 'B';
                                } else {
                                    a[i] = 'C';
                                }
                            }
                        }
                    }
                }
                System.out.println(cou + "\n" + new String(a, 0, n));
            }
        }
        sc.close();
    }
}
```
The logic seems solid. The translation is direct.
The `if (!sc.hasNextInt()) break;` is a safety check for the loop termination, as `sc.hasNext()` might return true for whitespace.
Actually, `while(sc.hasNext())` is sufficient if the input is well-formed.
I'll stick to the logic.
The prompt asks for "code of the resulting program".
I will output the code block.
</think>

<CODE>
import java.util.Scanner;

public class c_219 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // C++ code uses char a[500001].
        // We allocate a slightly larger array to safely handle n up to 500001
        // where accessing a[i+1] might be required.
        char[] a = new char[500005];
        
        while (sc.hasNext()) {
            // Ensure we have integers to read
            if (!sc.hasNextInt()) break;
            int n = sc.nextInt();
            int p = sc.nextInt();
            String s = sc.next();
            
            // Copy the input string into the char array
            for (int i = 0; i < s.length(); i++) {
                a[i] = s.charAt(i);
            }
            // The rest of the array remains null-terminated ('\0'), matching C++ behavior
            
            int cou = 0;
            if (p == 2) {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            a[i] = 'B';
                        } else {
                            a[i] = 'A';
                        }
                    }
                }
                if (cou <= n / 2) {
                    System.out.println(cou + "\n" + new String(a, 0, n));
                } else {
                    for (int i = 0; i < n; i++) {
                        a[i] = (char) ('A' + 'B' - a[i]);
                    }
                    System.out.println((n - cou) + "\n" + new String(a, 0, n));
                }
            } else {
                for (int i = 1; i < n; i++) {
                    if (a[i] == a[i-1]) {
                        cou++;
                        if (a[i] == 'A') {
                            // Check a[i+1]
                            // Ensure i+1 is within bounds of n (and array)
                            if (i + 1 < n && a[i+1] != 'B') {
                                a[i] = 'B';
                            } else {
                                a[i] = 'C';
                            }
                        } else { // a[i] == 'B'
                            if (i + 1 < n && a[i+1] != 'A') {
                                a[i] = 'A';
                            } else {
                                if (i - 1 >= 0 && a[i-1] != 'B') {
                                    a[i] = 'B';
                                } else {
                                    a[i] = 'C';
                                }
                            }
                        }
                    }
                }
                System.out.println(cou + "\n" + new String(a, 0, n));
            }
        }
        sc.close();
    }
}
</CODE>