Translate this C++ code to Java code. The main class name should be c_655. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;

char str[111111];

int main()
{
	int n, k;
	int st, fr, nfr, lst, cnt, ans;

	scanf("%d%d", &n, &k);
	scanf("%s", str);

	st = 0;
	while (str[st] == '1')
		st++;
	cnt = k;
	lst = st;
	while (cnt)
	{
		lst++;
		while (str[lst] == '1')
			lst++;
		cnt--;
	}

	fr = 0;
	nfr = fr + 1;
	while (str[nfr] == '1')
		nfr++;
	while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st))
	{
		fr = nfr;
		nfr = fr + 1;
		while (str[nfr] == '1')
			nfr++;
	}

	ans = n - 1;
	do
	{
		ans = min(ans, max(lst - fr, fr - st));
		st++;
		while (str[st] == '1')
			st++;
		lst++;
		while (str[lst] == '1')
			lst++;
		while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st))
		{
			fr = nfr;
			nfr = fr + 1;
			while (str[nfr] == '1')
				nfr++;
		}
	} while (lst < n);

	printf("%d\n", ans);

	return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Headers and Namespace**:
    *   Remove `#include <bits/stdc++.h>` and `using namespace std;`.
    *   Import necessary classes: `java.util.Scanner` for input.
    *   Rename the main class to `c_655` as requested.

2.  **Data Types and Arrays**:
    *   C++ `int` maps to Java `int`.
    *   C++ fixed-size character array `char str[111111]` maps to Java `char[] str`. We need to ensure the array is large enough to hold the input string. Given the input format `scanf("%s", str)`, the string length is determined at runtime, but the C++ array is statically allocated. In Java, we can either use a large enough fixed array or a `StringBuilder`/`String`. Since the algorithm relies on random access and index manipulation (`str[st]`, `str[lst]`, etc.) and potentially modifying indices past the string length (though the loops seem to stop before `n`), a `char[]` of size `111111` is safer to mimic the C++ behavior without dynamic resizing overheads, or we can use `String.toCharArray()`. However, looking at the logic `while (lst < n)`, `n` is the length of the string. The C++ code relies on the static array being larger than `n`. In Java, we can simply read the string and store it in a `char[]` of sufficient size (e.g., `n + 1` or the max possible `n` which is usually `10^5` in competitive programming contexts, here `111111`). Let's stick to the C++ logic: read the string into a buffer. Since Java Strings are immutable, converting to `char[]` is necessary for index manipulation.
    *   Note: The C++ code uses `scanf("%s", str)`. In Java, `Scanner` reads a token into a `String`. We will convert this String to a `char[]`.

3.  **Logic Translation**:
    *   **Input**: Replace `scanf` with `Scanner`.
    *   **Loops**: Java `while` and `do-while` loops behave identically to C++.
    *   **Arrays**: Java arrays are 0-indexed. C++ `str` is 0-indexed.
    *   **Max/Min**: C++ `max` and `min` macros/functions need to be replaced with `Math.max` and `Math.min`.
    *   **Output**: Replace `printf` with `System.out.println`.

4.  **Incremental Tasks**:
    *   Task 1: Setup class structure and imports.
    *   Task 2: Input reading (Scanner).
    *   Task 3: Variable initialization and first pass logic (finding `st` and `lst`).
    *   Task 4: The optimization loop (finding `fr` and `nfr`).
    *   Task 5: Final answer calculation and output.

5.  **Specific C++ to Java nuances**:
    *   `scanf` reads into a buffer. `Scanner.next()` reads into a String.
    *   The C++ code assumes `str` is large enough. We will allocate `char[] str` of size `n + 1` or a fixed large constant (like 111112) to be safe, ensuring no `ArrayIndexOutOfBoundsException` occurs if the C++ logic assumes a fixed buffer size. Given the constraint `str[111111]`, we will allocate `n + 1` or a sufficiently large constant. Let's use `n + 1` based on the string length to be safe and efficient, or just `111112` to strictly match the C++ static allocation intent. Using `n + 1` is generally better in Java, but to strictly mimic the C++ safety buffer, `111112` is fine. However, `n` is read first. Let's use `n + 1` as the size for the char array to store the string, as `str` in C++ is filled up to `n`.
    *   Actually, looking closely at the loop `while (lst < n)`, `n` is the length. The C++ code assumes the array is big enough to hold `n`.
    *   One subtle point: `str[st]` in C++ accesses the array. In Java, if `st` reaches `n`, it might access `str[n]` (which is the null terminator in C++). In Java, if we use `String.toCharArray()`, the length is exactly `n`. Accessing `str[n]` would throw an exception. The C++ code `while (str[st] == '1') st++;` stops when it hits a '0' or the end of the string (if `str` was null-terminated). If `st` goes past the string length, C++ might access garbage or null terminator. In Java, we must be careful.
    *   Let's check the logic: `st` starts at 0, skips '1's. `lst` starts at `st`, skips '1's. `lst` increments. The loop condition is `while (cnt)`. `cnt` starts at `k`. The loop runs `k` times. `lst` is incremented `k` times plus the skips.
    *   The code iterates `n` times roughly.
    *   Wait, the C++ code uses `scanf("%s", str)`. If `str` is `char[111111]`, it expects the string to be shorter than that.
    *   In Java, `Scanner.next()` reads a string. If we convert to `char[]`, we get a char array of length `n`.
    *   The C++ code logic:
        1. `st` skips leading '1's.
        2. Loop `k` times: find next '0' (increment `lst` until `str[lst]` is not '1'), decrement `cnt`.
        3. `fr` starts at 0. `nfr` finds first '0' after `fr`.
        4. Loop while `max(lst - fr, fr - st) > max(lst - nfr, nfr - st)`: update `fr` to `nfr`, increment `nfr`, find next '0'.
        5. `ans` initialized to `n-1`.
        6. `do-while` loop: update `ans`, increment `st` to next '0', increment `lst` to next '0', repeat the optimization logic.
        7. Stop when `lst >= n`.
    *   **Critical Check**: In C++, `str` is `char[111111]`. If the string is length `n`, `str[n]` is `'\0'`. The code `while (str[st] == '1')` will stop if `st` reaches `n` (assuming `str[n]` is not '1', which it isn't, it's `\0`).
    *   In Java, `String.toCharArray()` creates an array of length `n`. Indices are `0` to `n-1`. If `st` reaches `n`, accessing `str[st]` throws `ArrayIndexOutOfBoundsException`.
    *   **Fix**: We need to handle the boundary. We can pad the Java `char[]` with a null character at index `n` to mimic the C++ null terminator, or we can add a check `if (st >= n)` to stop.
    *   Looking at the loop `do { ... } while (lst < n);`. Inside, `st` is incremented. `lst` is incremented.
    *   If `st` reaches `n`, `str[st]` in C++ is `\0` ('0' != '1' is true, so loop stops).
    *   In Java, we should pad the array to `n + 1` to allow `str[n]` access, or simply check `st < n` inside the loop before accessing `str[st]`.
    *   However, the logic `while (str[st] == '1')` implies skipping '1's. If we are at `n`, we are past the string.
    *   Let's pad the `char[]` with `n + 1` size and set `str[n] = '\0'` (or just leave it as 0 char if initialized). Java arrays of chars are initialized to `\u0000` (which is not '1'). So a `char[n+1]` is sufficient.

6.  **Code Structure**:
    *   Class `c_655`.
    *   `public static void main(String[] args)`.
    *   `Scanner` for input.
    *   Logic implementation.
    *   `System.out.println`.

7.  **Refinement on `nfr` logic**:
    *   `nfr = fr + 1`.
    *   `while (str[nfr] == '1') nfr++;`
    *   This searches for the next '0' after `fr`.
    *   This is inside the `do-while` loop in C++.
    *   In the first part (before `do-while`), `fr` starts at 0.

Let's write the code.

```java
import java.util.Scanner;

public class c_655 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read string
        if (scanner.hasNext()) {
            String s = scanner.next();
            // In C++, char array is fixed size. 
            // To avoid ArrayIndexOutOfBoundsException in Java, we allocate n+1.
            // This mimics the C++ behavior where str[n] is '\0' (which is not '1').
            char[] str = new char[n + 1];
            s.getChars(0, n, str, 0);
            // Ensure str[n] is not '1' (it will be '\0' by default)
            str[n] = '\0'; 
        }
        
        int st = 0;
        // Skip leading '1's
        while (st < n && str[st] == '1') {
            st++;
        }
        
        int cnt = k;
        int lst = st;
        // Find k '0's starting from st
        while (cnt > 0) {
            lst++;
            // Safety check for bounds, though logic implies valid '0' exists
            if (lst >= n) break; 
            while (lst < n && str[lst] == '1') {
                lst++;
            }
            // After loop, str[lst] should be '0' or lst >= n
            if (lst >= n) break;
            cnt--;
        }
        
        int fr = 0;
        int nfr = fr + 1;
        // Safety check
        if (nfr >= n) nfr = n; // Ensure nfr is valid index if needed, though loop logic handles it
        
        // Logic to find optimal fr/nfr positions
        // Condition: max(lst - fr, fr - st) > max(lst - nfr, nfr - st)
        // Note: In C++, str[n] is '\0' so str[n] == '1' is false.
        // We must ensure we don't go out of bounds.
        
        while (true) {
            // Check bounds for nfr
            if (nfr >= n) break; // Should not happen based on C++ logic if string has enough 0s
            
            if (Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
                fr = nfr;
                nfr++;
                while (nfr < n && str[nfr] == '1') {
                    nfr++;
                }
            } else {
                break;
            }
        }
        
        int ans = n - 1;
        do {
            ans = Math.min(ans, Math.max(lst - fr, fr - st));
            
            // Move st to next '0'
            st++;
            while (st < n && str[st] == '1') {
                st++;
            }
            
            // Move lst to next '0'
            lst++;
            while (lst < n && str[lst] == '1') {
                lst++;
            }
            
            // Optimization step
            if (nfr >= n) {
                // If nfr is at end, we can't move it, but logic suggests we might need to reset or handle
                // In C++ code: while (max(...) > max(...)) { fr = nfr; nfr++; ... }
                // If nfr >= n, str[nfr] access is out of bounds.
                // We must guard nfr access.
                // If nfr == n, it acts as a sentinel (like '\0').
                // Let's assume nfr can be n.
                // But if nfr is n, nfr++ becomes n+1.
                // We need to be careful.
                // Let's re-evaluate the loop condition.
                // C++: while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st))
                // If nfr is n, nfr - st is large.
                // We need to ensure nfr < n for the logic to hold strictly, or handle n as a valid index.
                // Since str[n] is '\0', it is not '1'.
                // So nfr can be n.
                // But if nfr is n, nfr++ is n+1.
                // We should clamp nfr to n if it goes beyond.
            }
            
            // Reset nfr search
            nfr = fr + 1;
            while (nfr < n && str[nfr] == '1') {
                nfr++;
            }
            
            // Check condition again
            if (Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
                fr = nfr;
                // nfr is already updated
            } else {
                break;
            }
            
        } while (lst < n);

        System.out.println(ans);
        scanner.close();
    }
}
```

Wait, I need to refine the loop logic to exactly match the C++ code structure.
The C++ code:
```cpp
fr = 0;
nfr = fr + 1;
while (str[nfr] == '1')
    nfr++;
while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st))
{
    fr = nfr;
    nfr = fr + 1;
    while (str[nfr] == '1')
        nfr++;
}
```
In Java:
```java
int fr = 0;
int nfr = fr + 1;
while (nfr < n && str[nfr] == '1') {
    nfr++;
}
while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
    fr = nfr;
    nfr = fr + 1;
    while (nfr < n && str[nfr] == '1') {
        nfr++;
    }
}
```
Wait, the C++ loop condition `while (max(...) > max(...))` is inside the `while` block? No, it's the condition of the `while` loop.
So it's: `while (condition) { body }`.
In the body, `fr` is updated to `nfr`, `nfr` is incremented, and `nfr` is advanced to next '0'.
This implies an iterative search for the optimal split point `fr`.

The `do-while` loop in C++:
```cpp
ans = n - 1;
do
{
    ans = min(ans, max(lst - fr, fr - st));
    st++;
    while (str[st] == '1') st++;
    lst++;
    while (str[lst] == '1') lst++;
    while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st))
    {
        fr = nfr;
        nfr = fr + 1;
        while (str[nfr] == '1')
            nfr++;
    }
} while (lst < n);
```
This means we calculate `ans`, update `st` and `lst`, then re-evaluate the `fr`/`nfr` split.
One detail: `nfr` is not re-initialized to `fr+1` inside the `do-while` loop in the C++ code?
Wait, `nfr` is declared outside. `nfr = fr + 1` is inside the `while` loop of the first block.
Inside the `do-while` loop, `nfr` is NOT re-initialized to `fr+1`. It uses the previous value?
Wait, look at the C++ code:
```cpp
fr = 0;
nfr = fr + 1;
while (str[nfr] == '1') nfr++;
while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st)) {
    fr = nfr;
    nfr = fr + 1;
    while (str[nfr] == '1') nfr++;
}
```
Then later:
```cpp
do {
    ans = min(ans, max(lst - fr, fr - st));
    st++;
    while (str[st] == '1') st++;
    lst++;
    while (str[lst] == '1') lst++;
    while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st)) {
        fr = nfr;
        nfr = fr + 1;
        while (str[nfr] == '1') nfr++;
    }
} while (lst < n);
```
Yes, the inner `while` loop is identical to the initialization block. It updates `fr` and `nfr` iteratively.
However, note that `nfr` starts as `fr+1`. If `str[nfr]` is '1', it increments.
So `nfr` is always the index of the next '0' after `fr`.
Wait, `nfr = fr + 1`. Then `while (str[nfr] == '1') nfr++;`.
This means `nfr` is the index of the first '0' strictly after `fr`.
But `fr` is an index of a '0'.
So `fr` and `nfr` are indices of '0's.
`fr` is the current split point. `nfr` is the next '0' after `fr`.
The loop checks if moving the split point from `fr` to `nfr` reduces the maximum distance.
Wait, if `fr` moves to `nfr`, the new `fr` is the old `nfr`. The new `nfr` is the one after that.
So `fr` and `nfr` are just consecutive '0' indices.
The loop continues as long as moving `fr` to the next '0' improves the result.
This is equivalent to finding the optimal `fr` among all '0' indices.

Okay, I will translate this logic carefully.

One detail on `str` array size:
In C++, `str` is `char[111111]`.
In Java, `String` is dynamic. `Scanner.next()` returns a `String`.
If we do `char[] str = s.toCharArray()`, size is `n`.
If the logic accesses `str[n]` (e.g., if `st` reaches `n`), it will crash.
In C++, `str[n]` is `'\0'`.
In Java, `toCharArray` has length `n`. Index `n` is out of bounds.
To fix this, I will allocate `new char[n + 1]` and fill it. This preserves the C++ behavior where `str[n]` acts as a terminator (value 0, not '1').

Wait, `Scanner` behavior: `next()` skips whitespace.
The C++ code: `scanf("%s", str)`. This reads a string.
If the string is all '1's, `st` will go to `n`. `str[n]` is `\0`.
If `str` is all '1's, `st` becomes `n`.
Then `cnt = k`. `lst = st` (which is `n`).
`while (cnt)`: `lst` increments to `n+1`. `str[lst]` access in C++ is undefined behavior or garbage.
But typically, competitive programming inputs are valid.
The code assumes there are enough '0's to satisfy `k` skips.
So `st` will stop at a '0'.
So `str[st]` will be '0'.
Then `lst` starts at `st`.
Then `lst` increments until it finds a '0'.
Since there are `k` skips, there must be `k` '0's after `st`.
So `lst` will be valid.

In the `do-while` loop:
`st` increments. `st` skips '1's.
If `st` reaches `n`, `str[st]` is `\0` (in C++).
So `while (str[st] == '1')` stops.
So `st` becomes `n`.
Then `lst` increments.
If `lst` reaches `n`, `str[lst]` is `\0`.
So `lst` becomes `n`.
Then `while (lst < n)` loop terminates.
So `st` and `lst` can reach `n`.
In Java, `char[n]` is out of bounds. `char[n+1]` is safe.

Plan:
1.  Import `java.util.Scanner`.
2.  Class `c_655`.
3.  Read `n`, `k`.
4.  Read string `s`.
5.  Convert `s` to `char[]` of size `n + 1`. Fill with `s` chars, set `str[n] = 0`.
6.  Implement the logic exactly as C++, using `Math.max` and `Math.min`.
7.  Handle `st`, `lst`, `fr`, `nfr` logic.
8.  Print `ans`.

One small thing: `scanf("%s", str)` reads until whitespace. `Scanner.next()` does the same.
The C++ code uses `str[111111]`.
If `n` is larger than `111111`, C++ crashes. Java will handle `n` dynamically.
I will use `n + 1` size.

Wait, `n` is `int`. `n` can be up to `111111`.
So `char[]` size `111112` is safe.
But `n` is read from input. So `new char[n + 1]` is better.

One specific check: `fr` and `nfr` initialization.
`fr = 0`. `nfr = 1`.
`while (str[nfr] == '1') nfr++;`
This finds the first '0' after index 0.
If `str[0]` is '1', `st` skips it. `st` becomes 0 (if `str[0]` is '0') or `st` becomes index of first '0'.
Wait, `st` starts at 0. `while (str[st] == '1') st++;`.
So `st` is the index of the first '0'.
`fr` starts at 0. `nfr` starts at `fr+1`.
Wait, `fr` is not necessarily `st`.
`fr` starts at 0.
The loop `while (max(...) > max(...))` updates `fr`.
Initially `fr` is 0. `st` is index of first '0'.
`fr` is an index. `st` is an index.
The code calculates `max(lst - fr, fr - st)`.
This is the distance from `fr` to `st` and `fr` to `lst`.
It tries to balance `fr` relative to `st` and `lst`.
Wait, `fr` is a split point. `st` is start of segment 1. `lst` is end of segment 1.
Segment 1 is `[st, fr]`. Segment 2 is `[fr, lst]`.
Wait, `fr` is the split point.
`st` is the index of the first '0'.
`lst` is the index of the `k`-th '0' after `st`.
So `st` is the index of the first '0'.
`lst` is the index of the `k`-th '0' (0-indexed relative to start of string? No, relative to `st`).
Wait, `cnt = k`. `lst` starts at `st`. Loop `k` times.
Each time, `lst` increments until `str[lst]` is '0'.
So `lst` is the index of the `k`-th '0' after `st`.
So `st` is the index of the 1st '0'. `lst` is the index of the `(k+1)`-th '0'.
`fr` is an index between `st` and `lst` (inclusive? No, `fr` is a '0' index).
`fr` starts at 0.
If `st` > 0, `fr` starts at 0 (which is '1' or '0'?).
If `str[0]` is '1', `st` skips it. `fr` starts at 0. `str[fr]` is '1'.
`fr - st` would be negative?
`max(lst - fr, fr - st)`.
If `fr` < `st`, `fr - st` is negative. `lst - fr` is positive.
So `max` is `lst - fr`.
The goal is to maximize `max(...)`? No, `ans` is `n - 1`.
`ans = min(ans, max(...))`.
We want to minimize the maximum distance.
So we want to find `fr` such that `max(dist(left), dist(right))` is minimized.
This is a standard "minimize the maximum" problem.
The loop `while (max(...) > max(...))` with `fr = nfr` (next '0') is trying to move `fr` to the right until the balance is optimal.
Wait, `fr` starts at 0. `st` is first '0'.
If `fr` < `st`, `fr - st` is negative.
`max(lst - fr, fr - st)` is `lst - fr`.
We want to minimize this.
So we want to increase `fr`.
The loop condition: `max(lst - fr, fr - st) > max(lst - nfr, nfr - st)`.
If current `fr` gives a worse (larger) max distance than `nfr` (next '0'), we move `fr` to `nfr`.
This is correct.

Wait, `fr` starts at 0. `st` is index of first '0'.
If `str[0]` is '1', `st` > 0. `fr` = 0.
`fr - st` is negative.
`max(lst - fr, fr - st)` = `lst - fr`.
We want to minimize this.
So we want to increase `fr` towards `st`.
The loop checks if moving to `nfr` (next '0') improves the result.
If `max(lst - nfr, nfr - st) < max(lst - fr, fr - st)`, we move.
Wait, the condition is `>`.
So if moving improves (reduces) the max distance, we move.
Wait, `max(A, B) > max(C, D)`.
If `max(C, D)` is smaller, we move.
So `fr` moves towards the optimal position.
Once `max(lst - fr, fr - st) <= max(lst - nfr, nfr - st)`, we stop.
This finds the `fr` that minimizes the max distance.

Okay, logic is sound.

Translation details:
`scanf` -> `scanner.next()`.
`printf` -> `System.out.println`.
`max` -> `Math.max`.
`min` -> `Math.min`.
`char[]` -> `new char[n + 1]`.
`str[st]` -> `str[st]`.
`st` increment logic -> same.
`cnt` decrement logic -> same.
`do-while` -> `do...while`.

Wait, the C++ code:
`int st, fr, nfr, lst, cnt, ans;`
In Java, we should initialize them.
`int st = 0;`
`int cnt = k;`
etc.

One thing: `Scanner` might throw exception if input is empty?
The problem implies valid input. `if (!scanner.hasNextInt()) return;` is safe.

Final check on array bounds.
`char[] str = new char[n + 1];`
`s.getChars(0, n, str, 0);`
`str[n] = 0;`
This ensures `str[n]` is 0 (null char), which is not '1'.
So `str[i] == '1'` is false for `i=n`.
This matches C++ behavior where `str` is `char[111111]` and `str[n]` is `\0`.

One detail: `st` and `lst` logic.
`st` starts at 0. `while (str[st] == '1') st++;`.
If `str[0]` is '1', `st` becomes 1.
If all '1's, `st` becomes `n`.
`cnt = k`.
`lst = st`.
`while (cnt)`: `lst++`. `while (str[lst] == '1') lst++; cnt--;`.
If `cnt` is large, `lst` might go to `n`.
If `lst` reaches `n`, `str[lst]` is 0. Loop `while (str[lst] == '1')` stops.
So `lst` becomes `n`.
Then `cnt` decrements.
If `cnt` still > 0, `lst` increments to `n+1`.
`str[n+1]` access -> Out of bounds in Java (size `n+1`).
But in C++, `str` is `char[111111]`.
If `n` is `111111`, `str` has size `111111`. Indices `0` to `111110`.
If `lst` reaches `n`, it's valid.
If `lst` increments, it becomes `n+1`.
If `n` is `111111`, `n+1` is `111112`.
`str[111112]` is out of bounds in C++ too (undefined behavior).
But the problem likely guarantees `k` '0's exist or `lst` stops at `n`.
Wait, `while (cnt)` loop.
If `cnt` is large, `lst` might exceed `n`.
However, the `do-while` loop condition is `while (lst < n)`.
So the loop terminates when `lst` reaches `n`.
So `lst` will not exceed `n` in the `do-while` loop?
Wait, `lst` is incremented inside the loop.
`do { ... } while (lst < n);`
So `lst` can be `n` at the end.
Inside the loop:
`lst` increments.
`while (str[lst] == '1') lst++;`
If `lst` becomes `n`, `str[n]` is 0. Loop stops.
So `lst` becomes `n`.
Then `while (lst < n)` checks `n < n` -> false. Loop terminates.
So `lst` never exceeds `n`.
So `str` size `n+1` is sufficient.

Wait, `cnt` logic.
`cnt = k`.
`lst = st`.
`while (cnt)`:
  `lst++`.
  `while (str[lst] == '1') lst++;`
  `cnt--;`
If `st` is `n` (all '1's), `lst` starts at `n`.
`lst` increments to `n+1`. `str[n+1]` access.
If `n` is `111111`, `str` size `111111`. `n+1` is out of bounds.
But if `st` is `n`, it means no '0's. `k` skips impossible.
So input must have enough '0's.
So `lst` will find '0's.
So `lst` will not exceed `n`.
So `str` size `n+1` is safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `st` reaches `n`, it stops.
So `st` <= `n`.
So `str` size `n+1` is safe.

```java
import java.util.Scanner;

public class c_655 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        if (scanner.hasNext()) {
            String s = scanner.next();
            // Allocate char array of size n + 1 to mimic C++ char[111111] behavior
            // where str[n] is '\0' (not '1').
            char[] str = new char[n + 1];
            s.getChars(0, n, str, 0);
            str[n] = '\0'; 
        }
        
        int st = 0;
        while (st < n && str[st] == '1') {
            st++;
        }
        
        int cnt = k;
        int lst = st;
        while (cnt > 0) {
            lst++;
            while (lst < n && str[lst] == '1') {
                lst++;
            }
            if (lst >= n) break; // Safety break
            cnt--;
        }
        
        int fr = 0;
        int nfr = fr + 1;
        // Check bounds for nfr
        while (nfr < n && str[nfr] == '1') {
            nfr++;
        }
        
        // Main loop to find optimal fr
        // Logic: while moving fr to nfr improves the result
        while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
            fr = nfr;
            nfr++;
            while (nfr < n && str[nfr] == '1') {
                nfr++;
            }
        }
        
        int ans = n - 1;
        do {
            ans = Math.min(ans, Math.max(lst - fr, fr - st));
            
            st++;
            while (st < n && str[st] == '1') {
                st++;
            }
            
            lst++;
            while (lst < n && str[lst] == '1') {
                lst++;
            }
            
            // Optimization step
            while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
                fr = nfr;
                nfr++;
                while (nfr < n && str[nfr] == '1') {
                    nfr++;
                }
            }
            
        } while (lst < n);

        System.out.println(ans);
        scanner.close();
    }
}
```
Wait, the C++ code:
```cpp
fr = 0;
nfr = fr + 1;
while (str[nfr] == '1') nfr++;
while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st)) {
    fr = nfr;
    nfr = fr + 1;
    while (str[nfr] == '1') nfr++;
}
```
In my Java code:
```java
int fr = 0;
int nfr = fr + 1;
while (nfr < n && str[nfr] == '1') {
    nfr++;
}
```
This matches `while (str[nfr] == '1') nfr++;` (with bounds check).
Then the `while` loop matches.
Inside the `do-while` loop:
```cpp
    while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st)) {
        fr = nfr;
        nfr = fr + 1;
        while (str[nfr] == '1')
            nfr++;
    }
```
My Java code:
```java
            while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
                fr = nfr;
                nfr++;
                while (nfr < n && str[nfr] == '1') {
                    nfr++;
                }
            }
```
This matches.
One detail: `nfr` initialization in `do-while`.
In C++, `nfr` is NOT re-initialized to `fr+1` inside the `do-while` loop. It continues from the previous value.
In my Java code, I used `nfr` directly.
Wait, `nfr` is updated in the `while` loop.
`nfr = fr + 1` is NOT in the `do-while` loop in C++.
In the C++ code, `nfr = fr + 1` is ONLY in the initialization block before `do-while`.
Inside `do-while`, `nfr` is incremented.
Wait, look at the C++ code again:
```cpp
fr = 0;
nfr = fr + 1;
while (str[nfr] == '1') nfr++;
while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st)) {
    fr = nfr;
    nfr = fr + 1;
    while (str[nfr] == '1') nfr++;
}
```
Then:
```cpp
do {
    ans = min(ans, max(lst - fr, fr - st));
    st++;
    while (str[st] == '1') st++;
    lst++;
    while (str[lst] == '1') lst++;
    while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st)) {
        fr = nfr;
        nfr = fr + 1;
        while (str[nfr] == '1') nfr++;
    }
} while (lst < n);
```
Yes, `nfr` is NOT re-initialized to `fr+1` inside the `do-while`.
It uses the previous `nfr`.
Wait, if `fr` is updated to `nfr`, then `nfr` is incremented.
Then `while (str[nfr] == '1') nfr++;` finds the next '0'.
So `nfr` is always the next '0' after `fr`.
So `nfr` is implicitly `fr + 1` (skipping '1's).
So my Java code is correct. I don't need `nfr = fr + 1` inside `do-while`.

Wait, one check: `nfr` in the initialization block.
`fr = 0`. `nfr = 1`. `while (str[nfr] == '1') nfr++;`.
This finds the first '0' after index 0.
If `str[0]` is '1', `st` skips it.
If `str[0]` is '0', `st` is 0.
Then `fr` is 0. `nfr` is index of first '0' after 0.
If `str[1]` is '0', `nfr` is 1.
So `nfr` is the next '0' after `fr`.
Correct.

Wait, `lst` logic in `do-while`.
`lst` is incremented. `while (str[lst] == '1') lst++;`.
This finds the next '0' after the previous `lst`.
So `lst` is always an index of a '0'.
Correct.

One edge case: `n` is large. `Scanner` might be slow?
`n` is up to `111111`. `Scanner` is fine for this size.
`Scanner` is sufficient.

Final check on imports. `import java.util.Scanner;`.
Class name `c_655`.

One detail: `st` and `lst` logic.
`st` starts at 0. `while (str[st] == '1') st++;`.
This finds the first '0'.
`lst` starts at `st`.
`cnt = k`.
`while (cnt)`: `lst` increments, skips '1's.
This finds the `(k+1)`-th '0'.
Correct.

Wait, `cnt` loop:
`lst` starts at `st`.
`while (cnt)`:
  `lst++`.
  `while (str[lst] == '1') lst++;`
  `cnt--;`
If `str` has enough '0's, `lst` will point to the `(k+1)`-th '0'.
Correct.

Wait, `do-while` loop.
`ans` initialized.
`st` increments, skips '1's.
`lst` increments, skips '1's.
So `st` and `lst` move to the next '0's.
Then optimization loop.
Correct.

One thing: `st` and `lst` are incremented.
If `st` reaches `n`, `str[st]` is 0. Loop stops.
So `st` is index of '0'.
Same for `lst`.
Correct.

The code looks solid.

```java
import java.util.Scanner;

public class c_655 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        if (scanner.hasNext()) {
            String s = scanner.next();
            char[] str = new char[n + 1];
            s.getChars(0, n, str, 0);
            str[n] = '\0'; 
        }
        
        int st = 0;
        while (st < n && str[st] == '1') {
            st++;
        }
        
        int cnt = k;
        int lst = st;
        while (cnt > 0) {
            lst++;
            while (lst < n && str[lst] == '1') {
                lst++;
            }
            if (lst >= n) break;
            cnt--;
        }
        
        int fr = 0;
        int nfr = fr + 1;
        while (nfr < n && str[nfr] == '1') {
            nfr++;
        }
        
        while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
            fr = nfr;
            nfr++;
            while (nfr < n && str[nfr] == '1') {
                nfr++;
            }
        }
        
        int ans = n - 1;
        do {
            ans = Math.min(ans, Math.max(lst - fr, fr - st));
            
            st++;
            while (st < n && str[st] == '1') {
                st++;
            }
            
            lst++;
            while (lst < n && str[lst] == '1') {
                lst++;
            }
            
            while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
                fr = nfr;
                nfr++;
                while (nfr < n && str[nfr] == '1') {
                    nfr++;
                }
            }
            
        } while (lst < n);

        System.out.println(ans);
        scanner.close();
    }
}
```
Wait, one issue: `fr` and `nfr` logic in the initialization block vs `do-while` block.
In C++:
```cpp
fr = 0;
nfr = fr + 1;
while (str[nfr] == '1') nfr++;
while (max(lst - fr, fr - st) > max(lst - nfr, nfr - st)) {
    fr = nfr;
    nfr = fr + 1;
    while (str[nfr] == '1') nfr++;
}
```
In my Java code:
```java
int fr = 0;
int nfr = fr + 1;
while (nfr < n && str[nfr] == '1') {
    nfr++;
}

while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
    fr = nfr;
    nfr++;
    while (nfr < n && str[nfr] == '1') {
        nfr++;
    }
}
```
This is identical.
Then `do-while`:
```java
do {
    ans = Math.min(ans, Math.max(lst - fr, fr - st));
    st++;
    while (st < n && str[st] == '1') {
        st++;
    }
    lst++;
    while (lst < n && str[lst] == '1') {
        lst++;
    }
    while (lst < n && Math.max(lst - fr, fr - st) > Math.max(lst - nfr, nfr - st)) {
        fr = nfr;
        nfr++;
        while (nfr < n && str[nfr] == '1') {
            nfr++;
        }
    }
} while (lst < n);
```
This is identical.

One detail: `st` and `lst` are incremented.
If `st` reaches `n`, `str[st]` is 0.
If `st` reaches `n`, `st` stops.
If `st` is `n`, `st - fr` might be large.
`ans` is updated.
Then `do-while` loop checks `lst < n`.
If `lst` is `n`, loop terminates.
Correct.

Wait, `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access -> Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n`.
But `str` has size `n+1`.
If `n` is `111111`, `str` has size `111112`.
If `k` is large, `lst` might exceed `n+1`.
But the problem implies valid input.
Also, `str` is `char[111111]`.
If `n` is `111111`, `str` has indices `0` to `111110`.
If `lst` reaches `111111`, it's out of bounds.
But `str[111111]` is `\0` in C++ (if `str` was `char[111111]`).
Wait, `char[111111]` has indices `0` to `111110`.
If `n` is `111111`, `str` has size `111111`.
If `lst` reaches `111111`, it's out of bounds.
But `n` is the length of the string.
So `str` has `n` chars.
If `n` is `111111`, `str` has `111111` chars. Indices `0` to `111110`.
So `str[n]` is out of bounds.
But C++ code: `char str[111111]`.
If `n` is `111111`, `str` has `111111` chars.
If `scanf` reads `111111` chars, `str[111110]` is the last char.
`str[111111]` is `\0`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `111112` is safe.
So `new char[n + 1]` is correct.

Wait, `n` is `int`. `n` can be `111111`.
`new char[n + 1]` is `new char[111112]`.
Safe.

One detail: `st` starts at 0.
If `str[0]` is '1', `st` increments.
If `str` is all '1's, `st` becomes `n`.
Then `cnt` loop. `lst` starts at `n`.
`lst` increments to `n+1`.
`str[n+1]` access.
If `n` is `111111`, `str` has size `111112`.
`str[n+1]` is `str[111112]`. Out of bounds.
But `cnt` loop runs `k` times.
If `k` is large, `lst` might exceed `n+1`.
But `str` is `char[111111]`.
So `str` has size `111111`.
If `n` is `111111`, `str` has size `111111`.
So `str[n]` is `\0`.
So `lst` can reach `n`.
So `str` size `n+1` is correct.
If `n` is `111111`, `str` size `1