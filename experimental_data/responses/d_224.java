Translate this C++ code to Java code. The main class name should be d_224. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cstdio>
#include <cstring>

char s[200001],p[200001];
int maxp[200000],minp[200000];
int main()
{
    scanf("%s %s",s,p);
    int lens=strlen(s),lenp=strlen(p),at=0,tmp[26];
    for (int i=0;i<26;i++)
        tmp[i]=-1;
    for (int i=0;i<lens;i++){
        if (at<lenp&&p[at]==s[i]){
            tmp[p[at]-'a']=at;
            at++;
        }
        maxp[i]=tmp[s[i]-'a'];
    }
    for (int i=0;i<26;i++)
        tmp[i]=-1;
    at=lenp-1;
    for (int i=lens-1;i>=0;i--){
        if (at>=0&&p[at]==s[i]){
            tmp[p[at]-'a']=at;
            at--;
        }
        minp[i]=tmp[s[i]-'a'];
    }
    bool ok=true;
    for (int i=0;i<lens;i++)
        if (maxp[i]==-1||minp[i]==-1||maxp[i]<minp[i]){
            ok=false;
            break;
        }
    puts((ok)?"Yes":"No");
}

Here is the plan for translating the C++ code to Java:

1.  **Headers and I/O**:
    *   C++ uses `<cstdio>` and `scanf`/`puts`. Java does not have direct equivalents in the standard library for C-style formatted I/O.
    *   **Translation**: We will use `java.util.Scanner` or `java.io.BufferedReader` combined with `java.util.StringTokenizer`. Given the simplicity and the constraint of reading two strings separated by whitespace, `Scanner` is the most straightforward translation, though `BufferedReader` is more performant for large inputs. Since the string size is up to 200,000 characters, `BufferedReader` is preferred to avoid Time Limit Exceeded (TLE) issues often found in competitive programming contexts.
    *   `s` and `p` are global character arrays. In Java, we will use `char[]` or `String`. Since the code performs random access and modification (conceptually, though here it's read-only), `char[]` is closer to the C++ structure. However, `String` is immutable, which might be safer if we don't modify the original array. Looking at the code, `s` and `p` are used as `s[i]` and `p[at]`. `String` characters are accessed via `charAt()`. To match the exact semantics and potentially save memory (though Java strings are immutable), we will read the input into `char[]` arrays.
    *   `scanf("%s %s", s, p)` reads strings. In Java, we will use `br.readLine()` or a tokenizer. Since the strings might contain spaces (unlikely for competitive programming string problems unless specified, but `scanf("%s")` stops at whitespace), `next()` in `Scanner` or a custom tokenizer is safer. Let's use `BufferedReader` and `StringTokenizer` for efficiency.

2.  **Data Structures**:
    *   `s` and `p`: C++ `char[200001]`. Java `char[]` of size 200001 (or sufficient size to hold input).
    *   `maxp`, `minp`: C++ `int[200000]`. Java `int[]`.
    *   `tmp`: C++ `int[26]`. Java `int[]`.
    *   `lens`, `lenp`, `at`: C++ `int`. Java `int`.

3.  **Logic Translation**:
    *   **Initialization**: `for (int i=0;i<26;i++) tmp[i]=-1;` becomes a loop in Java.
    *   **First Pass (Forward)**: The logic `if (at<lenp&&p[at]==s[i])` translates directly. Java's `at` is an integer, `p` is an array.
    *   **Second Pass (Backward)**: `for (int i=lens-1;i>=0;i--)` translates directly. Note `at` starts at `lenp-1`.
    *   **Check**: `if (maxp[i]==-1||minp[i]==-1||maxp[i]<minp[i])`. Logic remains the same.
    *   **Output**: `puts((ok)?"Yes":"No")`. Java `System.out.println` or `System.out.print`.

4.  **Incremental Tasks**:
    *   Step 1: Setup class structure and imports.
    *   Step 2: Implement input reading logic (BufferedReader).
    *   Step 3: Implement the forward pass to calculate `maxp`.
    *   Step 4: Implement the backward pass to calculate `minp`.
    *   Step 5: Implement the final check and output.

5.  **Specific Java Considerations**:
    *   `scanf` behavior: `scanf("%s")` reads until whitespace. `BufferedReader`'s `readLine()` reads until newline. If the input format is just two strings separated by space, `StringTokenizer` is the robust choice.
    *   Array bounds: C++ arrays are 0-indexed. Java arrays are 0-indexed. The sizes in C++ are fixed (`200001`). In Java, we should dynamically allocate based on input length or allocate the fixed size to be safe. Allocating `200005` is a safe bet to avoid index out of bounds.
    *   `at` logic: In C++, `at` is an integer variable. In Java, it's a local `int`.
    *   `maxp[i] < minp[i]`: This is the core logic. It checks if the character `s[i]` appears in `p` both before and after the current position `i` (relative to the prefix/suffix match logic), or if the "match index" in `p` is strictly greater than the "match index" in `p` found from the right. Actually, `maxp[i]` stores the index of the *first* occurrence of `s[i]` in `p` that is $\ge$ the current position in `s` (greedy matching from left). `minp[i]` stores the index of the *first* occurrence of `s[i]` in `p` that is $\le$ the current position in `s` (greedy matching from right). The condition `maxp[i] < minp[i]` ensures that the occurrence found from the left is strictly to the left of the occurrence found from the right, meaning there is a valid "middle" segment or overlap logic.

6.  **Refining the Code**:
    *   Class name: `d_224`.
    *   Main method: `public static void main(String[] args)`.
    *   Input: Use `BufferedReader` for speed.
    *   Logic: Direct translation of loops and conditions.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class d_224 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        StringTokenizer st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        
        String sStr = st.nextToken();
        String pStr = st.nextToken();
        
        // C++ char array sizes are fixed at 200001.
        // We use String length to determine actual size needed, 
        // but allocate slightly more to be safe like C++ fixed arrays.
        int lens = sStr.length();
        int lenp = pStr.length();
        int maxLen = Math.max(lens, lenp);
        
        // In C++, arrays are char[200001]. In Java, we use char[] or String.
        // Since we need random access and don't modify the original string content 
        // (we only read chars), String is fine, but char[] is closer to C++ semantics.
        // However, converting String to char[] is easy.
        char[] s = sStr.toCharArray();
        char[] p = pStr.toCharArray();
        
        int[] maxp = new int[maxLen];
        int[] minp = new int[maxLen];
        int[] tmp = new int[26];
        
        // Initialize tmp array
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Forward pass
        int at = 0;
        for (int i = 0; i < lens; i++) {
            if (at < lenp && p[at] == s[i]) {
                tmp[p[at] - 'a'] = at;
                at++;
            }
            maxp[i] = tmp[s[i] - 'a'];
        }
        
        // Reset tmp array
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Backward pass
        at = lenp - 1;
        for (int i = lens - 1; i >= 0; i--) {
            if (at >= 0 && p[at] == s[i]) {
                tmp[p[at] - 'a'] = at;
                at--;
            }
            minp[i] = tmp[s[i] - 'a'];
        }
        
        // Check condition
        boolean ok = true;
        for (int i = 0; i < lens; i++) {
            if (maxp[i] == -1 || minp[i] == -1 || maxp[i] < minp[i]) {
                ok = false;
                break;
            }
        }
        
        System.out.println((ok) ? "Yes" : "No");
    }
}
```

Wait, I need to make sure the C++ code logic is perfectly mirrored.
C++: `char s[200001],p[200001];`
Java: `char[] s = new char[200001];`
In C++, `scanf` fills the array. In Java, `sStr.toCharArray()` fills the array up to `length`. The rest of the array remains `\0` (char 0).
In C++, `p[at]` accesses the array. If `at` is valid, it works.
In the check `maxp[i] < minp[i]`, if `s[i]` is not in `p`, `maxp` is `-1` (from init loop).
Wait, the initialization loop in C++ sets `tmp` to `-1`.
Then `maxp[i] = tmp[s[i]-'a']`. If `s[i]` is not found in `p` (within the greedy matching window), `tmp` remains `-1`.
So `maxp[i]` will be `-1`.
The check `if (maxp[i] == -1 ...)` handles this.
So dynamic allocation based on `lens` and `lenp` is fine, provided we don't access indices beyond `lens` in `maxp` and `minp` arrays.
In the loop `for (int i=0; i<lens; i++)`, we access `maxp[i]`.
In the loop `for (int i=lens-1; i>=0; i--)`, we access `minp[i]`.
So `new int[Math.max(lens, lenp)]` is sufficient, but to be strictly safe against potential off-by-one errors or if `lens` is large, `200005` is safer. I will use `200005` to mimic the C++ static allocation style which guarantees space.

Also, `p[at]` access: `at` goes up to `lenp-1`. So `p` needs to be at least `lenp`.
The C++ code defines `p` as `200001`.
If `lens` is 200000, `i` goes up to 199999.
If `lenp` is 200000, `at` goes up to 199999.
So size `200001` is enough. I will use `200005` to be safe.

One detail: `scanf("%s %s",s,p)` reads two strings. If the input contains spaces within the strings (unlikely for this type of problem), `scanf("%s")` stops. `StringTokenizer` splits by whitespace, which matches `scanf("%s")` behavior for standard competitive programming inputs.

Final check on `maxp` and `minp` sizing.
In C++, `maxp` and `minp` are size `200000`.
Wait, `s` is size `200001`.
Indices for `s` are `0` to `200000`.
The loop is `for (int i=0;i<lens;i++)`.
If `lens` is 200001, `i` goes to 200000.
So `maxp` needs to be at least size `200001`.
The C++ code declares `maxp[200000]`. This implies `lens` is strictly less than 200001 (i.e., max 200000 chars).
So `new int[200001]` is sufficient. I will use `200005` to be absolutely sure.

One small logic check:
In C++:
`if (at<lenp&&p[at]==s[i])`
`maxp[i] = tmp[s[i]-'a'];`
If `s[i]` matches `p[at]`, `tmp` is updated.
If `s[i]` does NOT match `p[at]`, `tmp` is NOT updated (remains `-1` or previous value).
Wait, `tmp` is initialized to `-1`.
If `s[i]` is not matched at current `at`, `tmp[s[i]-'a']` will be `-1` (unless it was matched earlier in the loop? No, `tmp` is reset every time? No, `tmp` is reset before the loop starts).
Inside the loop, `tmp` is updated ONLY if `p[at] == s[i]`.
So if `s[i]` is not found in `p` at the current greedy step, `tmp[s[i]-'a']` retains its value from the initialization?
Wait, the initialization is `for (int i=0;i<26;i++) tmp[i]=-1;`.
This happens BEFORE the loop.
Inside the loop:
`if (p[at] == s[i]) tmp[p[at]-'a'] = at;`
If `s[i]` != `p[at]`, `tmp` is NOT updated for `s[i]`.
So `maxp[i]` will be `-1` if `s[i]` is not found in the remaining prefix of `p`.
This logic holds.

However, there is a subtle point. `tmp` stores the index of the character.
If `s[i]` was seen before in `p` (at index `k < at`), `tmp[s[i]-'a']` would hold `k`.
But the loop iterates `i` from `0`. `at` starts at `0`.
We only update `tmp` when we find a match.
So `maxp[i]` stores the index in `p` of the character `s[i]` found in `p` starting from index `0` up to `at`.
Wait, if `s[i]` appeared in `p` at index `k` (where `k < at`), then `tmp[s[i]-'a']` would be `k`.
But the loop condition `if (at<lenp && p[at] == s[i])` checks the *current* `at`.
If `s[i]` != `p[at]`, we do NOT update `tmp`.
So `tmp` retains the value from the *previous* iteration?
Ah, `tmp` is NOT reset inside the loop. It is reset before the loop.
So if `s[i]` is not `p[at]`, `tmp[s[i]-'a']` keeps the value from `i-1`?
Yes.
Example: `s="ab"`, `p="ab"`.
`i=0`: `s[0]='a'`, `p[0]='a'`. Match. `tmp['a']=0`. `at=1`. `maxp[0]=0`.
`i=1`: `s[1]='b'`, `p[1]='b'`. Match. `tmp['b']=1`. `at=2`. `maxp[1]=1`.
Example: `s="ab"`, `p="ac"`.
`i=0`: `s[0]='a'`, `p[0]='a'`. Match. `tmp['a']=0`. `at=1`. `maxp[0]=0`.
`i=1`: `s[1]='b'`, `p[1]='c'`. No match. `tmp` not updated. `tmp['b']` remains `-1`. `maxp[1]=-1`.
This logic is correct for finding the "greedy match index".

The code looks solid.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class d_224 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        StringTokenizer st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        
        // Read s and p
        String sStr = st.nextToken();
        String pStr = st.nextToken();
        
        int lens = sStr.length();
        int lenp = pStr.length();
        
        // Allocate arrays. C++ uses fixed size 200001. 
        // We use a slightly larger size to be safe and mimic the static array behavior.
        int MAX_SIZE = 200005;
        char[] s = new char[MAX_SIZE];
        char[] p = new char[MAX_SIZE];
        int[] maxp = new int[MAX_SIZE];
        int[] minp = new int[MAX_SIZE];
        int[] tmp = new int[26];
        
        // Initialize tmp array
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Forward pass to compute maxp
        int at = 0;
        for (int i = 0; i < lens; i++) {
            s[i] = sStr.charAt(i);
            if (at < lenp && p[at] == s[i]) {
                tmp[s[i] - 'a'] = at;
                at++;
            }
            maxp[i] = tmp[s[i] - 'a'];
        }
        
        // Reset tmp array for backward pass
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Backward pass to compute minp
        at = lenp - 1;
        for (int i = lens - 1; i >= 0; i--) {
            s[i] = sStr.charAt(i);
            if (at >= 0 && p[at] == s[i]) {
                tmp[s[i] - 'a'] = at;
                at--;
            }
            minp[i] = tmp[s[i] - 'a'];
        }
        
        // Check condition
        boolean ok = true;
        for (int i = 0; i < lens; i++) {
            if (maxp[i] == -1 || minp[i] == -1 || maxp[i] < minp[i]) {
                ok = false;
                break;
            }
        }
        
        System.out.println((ok) ? "Yes" : "No");
    }
}
```
Wait, I should check the array initialization.
In C++, `char s[200001]` initializes to `\0`.
In Java, `new char[...]` initializes to `\0`.
However, I am assigning `s[i] = sStr.charAt(i)` inside the loop.
The loop runs `i` from `0` to `lens-1`.
So `s[0]` to `s[lens-1]` are set.
`s[lens]` to `s[MAX_SIZE-1]` remain `\0`.
In the loop `for (int i=0;i<lens;i++)`, we access `s[i]`.
In the loop `for (int i=lens-1;i>=0;i--)`, we access `s[i]`.
So the uninitialized part of `s` is never accessed. This is safe.
The `p` array is also filled implicitly? No, `p` is read from `pStr`.
I need to copy `pStr` to `p` array.
Wait, in the C++ code: `scanf("%s %s",s,p);`.
This fills `s` and `p` from index 0.
In Java, I am doing `s[i] = sStr.charAt(i)` inside the loop.
This means `p` array is NOT filled.
In the loop `if (at < lenp && p[at] == s[i])`, `p[at]` is accessed.
If `p` is not filled, `p[at]` will be `\0` (char 0).
If `s[i]` is not null char, `p[at] == s[i]` will be false (unless `s[i]` is `\0`, which is not possible for valid strings).
So `p` MUST be filled.
I need to copy `pStr` to `p` array before using it.
Correct logic:
`p[at]` depends on `lenp`.
I need to ensure `p` is populated up to `lenp`.
I will add a loop to copy `pStr` to `p` array.

Also, `s` is accessed in the loop.
I can just use `sStr.charAt(i)` directly instead of copying to `s` array, to save a step?
But the C++ code uses `s[i]`.
To be faithful to the translation, I should probably populate `s` array as well, or just use `sStr` if it's semantically equivalent.
Since `s` is used in `p[at] == s[i]`, and `s[i]` is the character at `i`.
`sStr.charAt(i)` is the same.
But `s` is used in `maxp` calculation: `maxp[i] = tmp[s[i]-'a']`.
So I can just use `sStr.charAt(i)`.
However, for the backward pass, `s[i]` is accessed.
`sStr.charAt(i)` is safe.
But what about `p`? `p` is used in `p[at]`.
`p` is filled by `scanf`.
I must copy `pStr` to `p` array.

Revised plan:
1. Read `sStr` and `pStr`.
2. Copy `sStr` to `s` array? Actually, `s` is only used to access characters. `sStr.charAt(i)` is equivalent and more "Java". But to match C++ structure, I'll populate `s` array too.
3. Copy `pStr` to `p` array.
4. Run the logic.

Wait, `maxp` and `minp` are `int[200000]`.
If `lens` is 200000, `i` goes to 199999.
So `maxp` size 200000 is enough.
I will use `200005` for safety.

One more thing: `scanf("%s %s",s,p)` reads two tokens.
If `p` is longer than `s`, `p` might be accessed in `p[at]`.
The logic `at < lenp` ensures we don't go out of bounds of `p`.
So `p` array must be at least `lenp` size.
Since `lenp` can be up to 200000, `p` array must be large enough.
I'll stick to `200005`.

One detail: `s` and `p` are `char` arrays.
In Java, `char` is 16-bit. `char` is fine.
`int` is 32-bit. `int` is fine.

Let's do the final code assembly.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class d_224 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        StringTokenizer st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        
        String sStr = st.nextToken();
        String pStr = st.nextToken();
        
        int lens = sStr.length();
        int lenp = pStr.length();
        
        // C++ arrays are fixed size 200001.
        // We allocate slightly more to be safe.
        int MAX_SIZE = 200005;
        
        char[] s = new char[MAX_SIZE];
        char[] p = new char[MAX_SIZE];
        int[] maxp = new int[MAX_SIZE];
        int[] minp = new int[MAX_SIZE];
        int[] tmp = new int[26];
        
        // Initialize tmp array
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Copy strings to char arrays (simulating scanf behavior)
        for (int i = 0; i < lens; i++) {
            s[i] = sStr.charAt(i);
        }
        for (int i = 0; i < lenp; i++) {
            p[i] = pStr.charAt(i);
        }
        
        // Forward pass to compute maxp
        int at = 0;
        for (int i = 0; i < lens; i++) {
            if (at < lenp && p[at] == s[i]) {
                tmp[p[at] - 'a'] = at;
                at++;
            }
            maxp[i] = tmp[s[i] - 'a'];
        }
        
        // Reset tmp array for backward pass
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Backward pass to compute minp
        at = lenp - 1;
        for (int i = lens - 1; i >= 0; i--) {
            if (at >= 0 && p[at] == s[i]) {
                tmp[p[at] - 'a'] = at;
                at--;
            }
            minp[i] = tmp[s[i] - 'a'];
        }
        
        // Check condition
        boolean ok = true;
        for (int i = 0; i < lens; i++) {
            if (maxp[i] == -1 || minp[i] == -1 || maxp[i] < minp[i]) {
                ok = false;
                break;
            }
        }
        
        System.out.println((ok) ? "Yes" : "No");
    }
}
```
Wait, `maxp` and `minp` are declared as `int[200000]` in C++.
If `lens` is 200000, `i` goes to 199999.
So `new int[200000]` is technically sufficient for `lens` up to 200000.
But `s` is `200001`.
If `lens` is 200001, `i` goes to 200000.
Then `maxp[200000]` would be out of bounds if `maxp` is size 200000.
So `MAX_SIZE` should be at least 200001.
I used `200005`, which is safe.

One edge case: `if (at < lenp && p[at] == s[i])`.
If `s[i]` is a character that is NOT in `p`, `tmp[s[i]-'a']` remains `-1`.
Then `maxp[i] = -1`.
This is handled by `if (maxp[i] == -1 ... ok=false)`.
This logic is correct.

I am confident in this translation.
I will output the code block now.
</think>

Here is the plan for the translation:

1.  **Class and Imports**: The C++ code uses `<cstdio>` and `<cstring>`. Java does not have a direct equivalent for C-style I/O. We will use `java.io.BufferedReader` and `java.util.StringTokenizer` for efficient input reading, which is standard for Java competitive programming solutions. The class name will be `d_224`.

2.  **Data Structures**:
    *   `char s[200001], p[200001]`: In C++, these are static arrays. In Java, we will use `char[]` arrays. Since the size is fixed in C++, we will allocate arrays of size `200005` to be safe and mimic the C++ behavior.
    *   `int maxp[200000], minp[200000]`: These will be `int[]` arrays of size `200005` to accommodate the maximum length of `s` (up to 200,000 characters).
    *   `int tmp[26]`: This will be an `int[]` of size 26.

3.  **Input Handling**:
    *   `scanf("%s %s", s, p)`: This reads two whitespace-separated strings. In Java, `StringTokenizer` is ideal for this. We will read the input line and tokenize it to extract `s` and `p` as `String` objects, then convert them to `char[]` arrays to match the C++ structure.

4.  **Logic Implementation**:
    *   **Initialization**: The loop `for (int i=0;i<26;i++) tmp[i]=-1;` is directly translatable.
    *   **Forward Pass**: The loop `for (int i=0;i<lens;i++)` calculates `maxp`. The condition `if (at<lenp&&p[at]==s[i])` is identical.
    *   **Reset**: `tmp` array is reset to `-1` before the second pass.
    *   **Backward Pass**: The loop `for (int i=lens-1;i>=0;i--)` calculates `minp`. The condition `if (at>=0&&p[at]==s[i])` is identical.
    *   **Check**: The final loop checks `maxp[i] == -1 || minp[i] == -1 || maxp[i] < minp[i]`. This logic is preserved.
    *   **Output**: `puts((ok)?"Yes":"No")` is translated to `System.out.println((ok) ? "Yes" : "No")`.

5.  **Incremental Tasks**:
    *   Step 1: Define class and imports, setup input reading.
    *   Step 2: Implement array allocation and string-to-array conversion.
    *   Step 3: Implement the forward pass for `maxp`.
    *   Step 4: Implement the backward pass for `minp`.
    *   Step 5: Implement the final check and output logic.

```CODE
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class d_224 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        if (line == null) return;
        
        StringTokenizer st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        
        // Read s and p as strings
        String sStr = st.nextToken();
        String pStr = st.nextToken();
        
        int lens = sStr.length();
        int lenp = pStr.length();
        
        // Allocate arrays. C++ uses fixed size 200001. 
        // We allocate slightly more to be safe.
        int MAX_SIZE = 200005;
        
        char[] s = new char[MAX_SIZE];
        char[] p = new char[MAX_SIZE];
        int[] maxp = new int[MAX_SIZE];
        int[] minp = new int[MAX_SIZE];
        int[] tmp = new int[26];
        
        // Initialize tmp array
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Copy strings to char arrays (simulating scanf behavior)
        for (int i = 0; i < lens; i++) {
            s[i] = sStr.charAt(i);
        }
        for (int i = 0; i < lenp; i++) {
            p[i] = pStr.charAt(i);
        }
        
        // Forward pass to compute maxp
        int at = 0;
        for (int i = 0; i < lens; i++) {
            if (at < lenp && p[at] == s[i]) {
                tmp[p[at] - 'a'] = at;
                at++;
            }
            maxp[i] = tmp[s[i] - 'a'];
        }
        
        // Reset tmp array for backward pass
        for (int i = 0; i < 26; i++) {
            tmp[i] = -1;
        }
        
        // Backward pass to compute minp
        at = lenp - 1;
        for (int i = lens - 1; i >= 0; i--) {
            if (at >= 0 && p[at] == s[i]) {
                tmp[p[at] - 'a'] = at;
                at--;
            }
            minp[i] = tmp[s[i] - 'a'];
        }
        
        // Check condition
        boolean ok = true;
        for (int i = 0; i < lens; i++) {
            if (maxp[i] == -1 || minp[i] == -1 || maxp[i] < minp[i]) {
                ok = false;
                break;
            }
        }
        
        System.out.println((ok) ? "Yes" : "No");
    }
}
```