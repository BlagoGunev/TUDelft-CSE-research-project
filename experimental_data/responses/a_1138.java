Translate this C++ code to Java code. The main class name should be a_1138. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<cstdio>
#include<cctype>
#include<algorithm>
//#include<ctime>
#define rg register
typedef long long ll;
template <typename T> inline T max(const T a,const T b){return a>b?a:b;}
template <typename T> inline T min(const T a,const T b){return a<b?a:b;}
template <typename T> inline void mind(T&a,const T b){a=a<b?a:b;}
template <typename T> inline void maxd(T&a,const T b){a=a>b?a:b;}
template <typename T> inline T abs(const T a){return a>0?a:-a;}
template <typename T> inline void swap(T&a,T&b){T c=a;a=b;b=c;}
//template <typename T> inline void swap(T*a,T*b){T c=a;a=b;b=c;}
template <typename T> inline T gcd(const T a,const T b){if(!b)return a;return gcd(b,a%b);}
template <typename T> inline T lcm(const T a,const T b){return a/gcd(a,b)*b;}
template <typename T> inline T square(const T x){return x*x;};
template <typename T> inline void read(T&x)
{
	char cu=getchar();x=0;bool fla=0;
	while(!isdigit(cu)){if(cu=='-')fla=1;cu=getchar();}
	while(isdigit(cu))x=x*10+cu-'0',cu=getchar();
	if(fla)x=-x;
}
template <typename T> inline void printe(const T x)
{
	if(x>=10)printe(x/10);
	putchar(x%10+'0');
}
template <typename T> inline void print(const T x)
{
	if(x<0)putchar('-'),printe(-x);
	else printe(x);
}
int n,a,dqz=100001,sgz=100001,dqcx=-100000000,sgcx=-100000000,ans=0;
int main()
{
	read(n);
	for(rg int i=1;i<=n;i++)
	{
		read(a);
		if(a==dqz)
		{
			dqcx++;
		}
		else
		{
			sgz=dqz;
			sgcx=dqcx;
			dqz=a;
			dqcx=1;
		}
		maxd(ans,min(dqcx,sgcx)<<1);
	}
	print(ans);
	return 0;
}

Here is the translation plan and the final Java code.

### Translation Plan

1.  **Headers and Imports**:
    *   Replace `<cstdio>` and `<cctype>` with Java's `java.io.*` and `java.util.*` (specifically for `Scanner` or `BufferedReader`). Since the C++ code uses a custom `read` function for fast I/O, I will implement a similar `FastReader` class in Java using `BufferedReader` and `StringTokenizer` to match the performance and behavior of the C++ `read` function.
    *   `<algorithm>` is not strictly needed as custom `max` and `min` functions are defined manually, but the logic remains.

2.  **Data Types**:
    *   The C++ code uses `long long` (`ll`). In Java, the equivalent is `long`. The variable `n` is `int` (up to $10^5$ based on context, though defined as `int` in C++), so `int` in Java is appropriate.

3.  **Templates and Generic Functions**:
    *   C++ uses templates (e.g., `template <typename T> inline T max`). Java does not support templates.
    *   I will implement specific versions of `max`, `min`, and `abs` for `int` and `long` types, as these are the only types used in the logic.
    *   `gcd` and `lcm` are defined in C++. The C++ code defines `lcm` but never calls it, so it can be omitted. `gcd` is also not called in the provided snippet.
    *   `swap` is defined but not used in the snippet, so it can be omitted.
    *   `square` is defined but not used.

4.  **Custom I/O Functions**:
    *   **`read`**: The C++ function reads an integer by skipping whitespace, handling signs, and parsing digits. I will create a Java method `readInt()` that does exactly this using `BufferedReader` to handle input efficiently.
    *   **`printe` and `print`**: The C++ functions recursively print integers. I will implement a `print` method in Java. Since Java prints to `System.out` which is buffered, a simple recursive print is fine for small numbers, but for large numbers or performance, printing to a `StringBuilder` or `BufferedWriter` is better. Given the recursion depth is logarithmic, recursion is acceptable here.

5.  **Main Logic**:
    *   The logic involves reading `n`, iterating `n` times to read `a`, maintaining a running sequence (`dqz`, `dqcx`) and a previous sequence (`sgz`, `sgcx`), and calculating the maximum of the doubled lengths of consecutive identical elements.
    *   I will translate the C++ variables `n`, `a`, `dqz`, `sgz`, `dqcx`, `sgcx`, `ans` directly to Java `int` variables.
    *   The loop and conditional logic will be translated 1:1.

6.  **Class Structure**:
    *   The class name must be `a_1138`.
    *   The `main` method will be standard Java `public static void main(String[] args)`.

7.  **Incremental Tasks**:
    *   Step 1: Implement `FastReader` class.
    *   Step 2: Implement `max`, `min` helpers.
    *   Step 3: Implement `print` helper.
    *   Step 4: Implement `main` method logic.
    *   Step 5: Integrate and test.

### Java Code

```java
import java.io.*;
import java.util.StringTokenizer;

public class a_1138 {
    
    // Fast I/O Reader to replace C++ read function
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public int readInt() {
            int c = 0;
            int x = 0;
            boolean fla = false;
            try {
                // Skip whitespace
                while (br.ready() && (c = br.read()) != -1) {
                    if (c == ' ') continue;
                    if (c == '-') fla = true;
                    break;
                }
                // Handle sign
                if (c == '-') fla = true;
                
                // Skip remaining whitespace if sign was found or if we hit whitespace immediately
                // Note: The C++ logic skips non-digits until a digit is found.
                // We need to ensure we skip spaces before the number.
                while (br.ready() && (c = br.read()) != -1) {
                    if (Character.isDigit(c)) {
                        break;
                    }
                    if (c == '-' && !fla) {
                        fla = true;
                        break;
                    }
                    // If it's a non-digit, non-minus character, it's invalid or whitespace
                    // The C++ code relies on isdigit(cu). 
                    // In the C++ code: while(!isdigit(cu)){...}
                    // So we loop until we find a digit or end of stream.
                    // Re-implementing strictly based on C++ logic:
                    if (!Character.isDigit(c)) {
                        // It's a space or other non-digit
                        if (c == '-') fla = true;
                        continue;
                    }
                    break; 
                }
            } catch (IOException e) {
                return 0;
            }
            
            // Actually, let's rewrite readInt to strictly match the C++ logic flow
            // C++: char cu = getchar(); while(!isdigit(cu))...
            // We will read char by char.
            return 0; // Placeholder, logic below is better
        }
    }
    
    // Re-implementing read logic cleanly inside main or a helper to match C++ exactly
    // C++: 
    // char cu=getchar(); x=0; bool fla=0;
    // while(!isdigit(cu)){if(cu=='-')fla=1; cu=getchar();}
    // while(isdigit(cu))x=x*10+cu-'0', cu=getchar();
    // if(fla)x=-x;
    
    // Java translation of read function
    static int readInt() throws IOException {
        int x = 0;
        boolean fla = false;
        int c = System.in.read();
        
        // Skip non-digits (spaces, newlines) until a digit or '-' is found
        while (c != -1 && !Character.isDigit(c)) {
            if (c == '-') fla = true;
            c = System.in.read();
        }
        
        // If we hit EOF or non-digit, return 0 or handle appropriately. 
        // Assuming valid input as per competitive programming standards.
        if (c == -1) return 0; 
        
        // Parse digits
        while (c != -1 && Character.isDigit(c)) {
            x = x * 10 + (c - '0');
            c = System.in.read();
        }
        
        if (fla) x = -x;
        return x;
    }
    
    // Helper functions for max/min matching C++ templates (int versions)
    static int max(int a, int b) {
        return a > b ? a : b;
    }
    
    static int min(int a, int b) {
        return a < b ? a : b;
    }
    
    static void mind(int a, int b) {
        if (a < b) a = b;
    }
    
    static void maxd(int a, int b) {
        if (a > b) a = b;
    }
    
    // Custom print function matching C++ print
    // C++ print: if(x<0) putchar('-'), printe(-x); else printe(x);
    // C++ printe: recursive
    static void print(int x) {
        if (x < 0) {
            System.out.print("-");
            x = -x;
        }
        printe(x);
    }
    
    static void printe(int x) {
        if (x >= 10) {
            printe(x / 10);
        }
        System.out.print(x % 10 + '0');
    }

    public static void main(String[] args) {
        int n = readInt();
        
        // Variables matching C++ global variables
        // dqz = 100001, sgz = 100001
        // dqcx = -100000000, sgcx = -100000000
        // ans = 0
        int dqz = 100001;
        int sgz = 100001;
        int dqcx = -100000000;
        int sgcx = -100000000;
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int a = readInt();
            
            if (a == dqz) {
                dqcx++;
            } else {
                sgz = dqz;
                sgcx = dqcx;
                dqz = a;
                dqcx = 1;
            }
            
            // maxd(ans, min(dqcx, sgcx) << 1)
            // In Java: ans = max(ans, min(dqcx, sgcx) * 2);
            // Note: C++ uses << 1 for *2.
            int val = min(dqcx, sgcx);
            val = val << 1; // Multiply by 2
            maxd(ans, val);
        }
        
        print(ans);
    }
}
```

### Refinement on I/O
The `readInt` implementation using `System.in.read()` directly is slightly risky if the buffer is empty initially (though `System.in` usually returns -1 immediately if empty). However, `BufferedReader` is safer and standard. Let's optimize the `readInt` to use `BufferedReader` to match the performance expectation of C++ `getchar` loops, as `System.in.read()` might be slow if not buffered.

Revised `readInt`:
```java
    static int readInt() throws IOException {
        int c = (int) br.read();
        int x = 0;
        boolean fla = false;
        
        while (c != -1 && !Character.isDigit(c)) {
            if (c == '-') fla = true;
            c = (int) br.read();
        }
        
        if (c == -1) return 0;
        
        while (c != -1 && Character.isDigit(c)) {
            x = x * 10 + (c - '0');
            c = (int) br.read();
        }
        
        if (fla) x = -x;
        return x;
    }
```
I will include the `FastReader` class structure properly.

### Final Code Construction

```java
import java.io.*;
import java.util.StringTokenizer;

public class a_1138 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = null;

    static int readInt() throws IOException {
        int c = (int) br.read();
        int x = 0;
        boolean fla = false;
        
        while (c != -1 && !Character.isDigit(c)) {
            if (c == '-') fla = true;
            c = (int) br.read();
        }
        
        if (c == -1) return 0;
        
        while (c != -1 && Character.isDigit(c)) {
            x = x * 10 + (c - '0');
            c = (int) br.read();
        }
        
        if (fla) x = -x;
        return x;
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static void mind(int a, int b) {
        if (a < b) a = b;
    }

    static void maxd(int a, int b) {
        if (a > b) a = b;
    }

    static void printe(int x) {
        if (x >= 10) {
            printe(x / 10);
        }
        System.out.print(x % 10 + '0');
    }

    static void print(int x) {
        if (x < 0) {
            System.out.print("-");
            printe(-x);
        } else {
            printe(x);
        }
    }

    public static void main(String[] args) throws IOException {
        int n = readInt();
        
        int dqz = 100001;
        int sgz = 100001;
        int dqcx = -100000000;
        int sgcx = -100000000;
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int a = readInt();
            
            if (a == dqz) {
                dqcx++;
            } else {
                sgz = dqz;
                sgcx = dqcx;
                dqz = a;
                dqcx = 1;
            }
            
            // maxd(ans, min(dqcx, sgcx) << 1)
            int val = min(dqcx, sgcx);
            val = val << 1; // Equivalent to * 2
            maxd(ans, val);
        }
        
        print(ans);
    }
}
```

Wait, I should check the recursion limit for `printe`. If `ans` is large, recursion might stack overflow. In C++, `printe` is recursive. If the number is $10^9$, depth is 10. It's safe. However, for very large numbers, recursion is risky. But here `ans` is bounded by `2 * n` (roughly $200,000$), so recursion depth is $\approx 6$. It is perfectly safe.

One detail: `dqcx` is initialized to `-100000000`. `dqz` is `100001`.
The logic: `if (a == dqz) dqcx++; else { sgz = dqz; sgcx = dqcx; dqz = a; dqcx = 1; }`.
This logic calculates the longest consecutive run of identical numbers.
If `dqcx` is negative (first element), `sgcx` is also negative. `min` of two negatives is negative. `<< 1` makes it a larger negative number. `maxd(ans, val)` where `ans` starts at 0.
If `val` is negative, `maxd(ans, val)` does nothing because `ans` (0) > `val` (negative).
Once `dqcx` becomes positive (2nd element matches 1st), `sgcx` becomes positive (1st element). Then `min` is positive.
So the logic holds.

Double check the class name: `a_1138`.
Double check imports.
Double check `print` logic.

The code looks solid.

```java
<CODE>
import java.io.*;
import java.util.StringTokenizer;

public class a_1138 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = null;

    // Function to read integer, matching C++ read(T&x) logic
    static int readInt() throws IOException {
        int c = (int) br.read();
        int x = 0;
        boolean fla = false;
        
        // Skip non-digit characters
        while (c != -1 && !Character.isDigit(c)) {
            if (c == '-') fla = true;
            c = (int) br.read();
        }
        
        if (c == -1) return 0;
        
        // Read digits
        while (c != -1 && Character.isDigit(c)) {
            x = x * 10 + (c - '0');
            c = (int) br.read();
        }
        
        if (fla) x = -x;
        return x;
    }

    // Helper functions for max and min, specific to int
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // maxd and mind modify the reference variable (passed by value in Java, so we must modify local copy or return)
    // C++: void mind(T&a, const T b){a=a<b?a:b;}
    // Java cannot pass by reference. We implement this by taking the variable we want to update as the first arg 
    // and modifying it directly, but since Java passes primitives by value, we can't modify 'a' inside the method 
    // unless we wrap it in an object. 
    // However, looking at the usage in main:
    // maxd(ans, val);
    // In C++, this modifies 'ans'. In Java, 'ans' in main is not modified by 'maxd' if it takes primitives.
    // We must change the signature to return the new value or use a wrapper.
    // Let's change maxd to return the updated value to be safe and cleaner.
    // Original C++: void maxd(T&a, const T b){a=a>b?a:b;}
    // Usage: maxd(ans, val) -> ans becomes max(ans, val).
    // Java version: int maxd(int a, int b) { return a > b ? a : b; }
    // Usage: ans = maxd(ans, val);
    
    static int maxd(int a, int b) {
        return a > b ? a : b;
    }

    // printe and print
    static void printe(int x) {
        if (x >= 10) {
            printe(x / 10);
        }
        System.out.print(x % 10 + '0');
    }

    static void print(int x) {
        if (x < 0) {
            System.out.print("-");
            printe(-x);
        } else {
            printe(x);
        }
    }

    public static void main(String[] args) throws IOException {
        int n = readInt();
        
        int dqz = 100001;
        int sgz = 100001;
        int dqcx = -100000000;
        int sgcx = -100000000;
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int a = readInt();
            
            if (a == dqz) {
                dqcx++;
            } else {
                sgz = dqz;
                sgcx = dqcx;
                dqz = a;
                dqcx = 1;
            }
            
            // C++: maxd(ans, min(dqcx, sgcx) << 1);
            // Java: ans = maxd(ans, min(dqcx, sgcx) << 1);
            int val = min(dqcx, sgcx);
            val = val << 1; 
            ans = maxd(ans, val);
        }
        
        print(ans);
    }
}
```
Wait, I need to make sure I don't change the logic semantics too much.
In C++, `maxd` modifies `a` in place.
In Java, `ans = maxd(ans, val)` achieves the same effect.
The logic is preserved.

One minor point: `sgz` and `dqz` are `int`. In C++, `dqz` is `100001`.
In the loop: `if (a == dqz)`.
This logic assumes `dqz` is updated.
The code looks correct.

One final check on `readInt`. The C++ code uses `getchar()`. `System.in.read()` reads a byte.
If the input contains characters that are not ASCII digits or space, `System.in.read()` might return extended ASCII values. `Character.isDigit` handles standard digits.
The C++ code `char cu=getchar()` reads a char (byte). `isdigit(cu)` checks if it is a digit.
If the input is strictly ASCII (digits, spaces, minus), `System.in.read()` works fine.
If the input contains multi-byte characters (unlikely for this problem type), `System.in.read()` reads bytes, which might break logic if `char` is not `byte`. But competitive programming inputs are usually ASCII.
The C++ `char cu` is signed char. `getchar` returns `int` (0-255 or -1).
`System.in.read()` returns `int` (0-255 or -1).
So `System.in.read()` is a direct translation.

```java
<CODE>
import java.io.*;
import java.util.StringTokenizer;

public class a_1138 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // Fast I/O Reader to replace C++ read function
    static int readInt() throws IOException {
        int c = (int) br.read();
        int x = 0;
        boolean fla = false;
        
        // Skip non-digit characters
        while (c != -1 && !Character.isDigit(c)) {
            if (c == '-') fla = true;
            c = (int) br.read();
        }
        
        if (c == -1) return 0;
        
        // Read digits
        while (c != -1 && Character.isDigit(c)) {
            x = x * 10 + (c - '0');
            c = (int) br.read();
        }
        
        if (fla) x = -x;
        return x;
    }

    // Helper functions for max and min
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // maxd: modify 'a' to be max(a, b). Since Java passes primitives by value, 
    // we return the updated value and assign it back to the caller.
    static int maxd(int a, int b) {
        if (a > b) a = b;
        return a;
    }
    
    // mind: modify 'a' to be min(a, b)
    static int mind(int a, int b) {
        if (a < b) a = b;
        return a;
    }

    // printe: recursive print of non-negative integer
    static void printe(int x) {
        if (x >= 10) {
            printe(x / 10);
        }
        System.out.print(x % 10 + '0');
    }

    // print: print integer with sign
    static void print(int x) {
        if (x < 0) {
            System.out.print("-");
            printe(-x);
        } else {
            printe(x);
        }
    }

    public static void main(String[] args) throws IOException {
        int n = readInt();
        
        // Variables matching C++ global variables
        int dqz = 100001;
        int sgz = 100001;
        int dqcx = -100000000;
        int sgcx = -100000000;
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int a = readInt();
            
            if (a == dqz) {
                dqcx++;
            } else {
                sgz = dqz;
                sgcx = dqcx;
                dqz = a;
                dqcx = 1;
            }
            
            // maxd(ans, min(dqcx, sgcx) << 1)
            // In C++, maxd modifies ans in place. In Java, we assign the return value.
            int val = min(dqcx, sgcx);
            val = val << 1; // Equivalent to * 2
            ans = maxd(ans, val);
        }
        
        print(ans);
    }
}
</CODE>
```
Wait, I noticed I used `maxd` and `mind` in the plan but only `maxd` was used in the code.
I will clean up the unused `mind` method to keep the code clean, or leave it if it's part of the "translation".
The prompt asks to translate the code. If `mind` is defined but not used, I should probably include it or remove it.
The C++ code includes `#include<cctype>`.
I will keep `mind` commented or removed if unused.
Actually, looking at the C++ code:
```cpp
template <typename T> inline void mind(T&a,const T b){a=a<b?a:b;}
template <typename T> inline void maxd(T&a,const T b){a=a>b?a:b;}
```
They are defined. I will include them in Java but maybe not use them if not needed, or use them if needed.
In the `main` function: `maxd(ans, min(dqcx, sgcx) << 1);`
So `maxd` is used. `mind` is defined but not used in the snippet.
I will include `mind` in the class to be faithful to the provided C++ code, even if not used in `main`.

Final check on `printe`.
C++:
```cpp
template <typename T> inline void printe(const T x)
{
	if(x>=10)printe(x/10);
	putchar(x%10+'0');
}
```
Java:
```java
static void printe(int x) {
    if (x >= 10) {
        printe(x / 10);
    }
    System.out.print(x % 10 + '0');
}
```
Matches.

Final check on `print`.
C++:
```cpp
template <typename T> inline void print(const T x)
{
	if(x<0)putchar('-'),printe(-x);
	else printe(x);
}
```
Java:
```java
static void print(int x) {
    if (x < 0) {
        System.out.print("-");
        printe(-x);
    } else {
        printe(x);
    }
}
```
Matches.

Final check on `read`.
C++:
```cpp
template <typename T> inline void read(T&x)
{
	char cu=getchar();x=0;bool fla=0;
	while(!isdigit(cu)){if(cu=='-')fla=1;cu=getchar();}
	while(isdigit(cu))x=x*10+cu-'0',cu=getchar();
	if(fla)x=-x;
}
```
Java:
```java
static int readInt() throws IOException {
    int c = (int) br.read();
    int x = 0;
    boolean fla = false;
    while (c != -1 && !Character.isDigit(c)) {
        if (c == '-') fla = true;
        c = (int) br.read();
    }
    if (c == -1) return 0; // Should not happen with valid input
    while (c != -1 && Character.isDigit(c)) {
        x = x * 10 + (c - '0');
        c = (int) br.read();
    }
    if (fla) x = -x;
    return x;
}
```
Matches.

One detail: `dqcx` is initialized to `-100000000`.
In C++, `int` is usually 32-bit. `-100000000` fits in `int`.
In Java, `int` is 32-bit signed. `-100000000` fits.
`100001` fits.
`ans` initialized to `0`.
Everything seems consistent.

I will structure the final output with the plan and then the code block.
Wait, the prompt says: "Then, output the code of the resulting program with token <CODE> at the beginning and at the end."
It implies I should output the plan first, then the code block.

Plan:
1. **Class Structure**: Create `public class a_1138`.
2. **I/O**: Implement `readInt` using `BufferedReader` to replace `getchar` and `read` templates. Implement `print` and `printe` recursively to match C++ behavior.
3. **Logic**: Translate variables `n`, `a`, `dqz`, `sgz`, `dqcx`, `sgcx`, `ans`.
4. **Functions**: Translate `max`, `min`, `maxd`, `mind`, `gcd`, `lcm`, `square` (though `gcd`, `lcm`, `square`, `swap` are unused in the snippet, I will include `max`, `min`, `maxd`, `mind` as they are used).
5. **Main Loop**: Translate the `for` loop logic exactly.

One small detail: `dqcx` is `-100000000`.
In C++, `int` is typically 32-bit.
In Java, `int` is 32-bit.
`-100000000` is valid.
However, `dqcx` starts at negative.
`sgcx` starts at negative.
`min(dqcx, sgcx)` will be negative.
`<< 1` will be negative.
`maxd(ans, negative)` where `ans` is 0. `0 > negative`. So `ans` remains 0.
This is correct.

I'll proceed with generating the response.
</think>

### Translation Plan

1.  **Class Definition**: The C++ code is a standalone program. In Java, this becomes a `public class a_1138`.
2.  **I/O Translation**:
    *   **Input**: The C++ code uses `read(T&x)` which reads integers via `getchar()`. I will implement a `readInt()` method in Java using `BufferedReader` and `InputStreamReader` to handle character-by-character input and parsing logic (skipping whitespace, handling signs) equivalent to the C++ template.
    *   **Output**: The C++ code uses `print(T x)` and `printe(T x)` for output. I will implement these as `static void print(int x)` and `static void printe(int x)` in Java, using `System.out.print()`. Since `printe` is recursive in C++, I will keep it recursive in Java (which is safe for the expected output size).
3.  **Data Types**:
    *   `long long` in C++ maps to `long` in Java. However, the variables `n`, `a`, `dqz`, `sgz`, `dqcx`, `sgcx`, `ans` are declared as `int` in the C++ code, so I will use `int` in Java.
4.  **Helper Functions**:
    *   **`max`, `min`**: C++ templates `max(T a, T b)` and `min(T a, T b)` will be translated to `static int max(int a, int b)` and `static int min(int a, int b)`.
    *   **`maxd`, `mind`**: C++ modifies the first argument by reference (`T&a`). Java passes primitives by value. I will implement `maxd` and `mind` to return the updated value, and update the caller variable (e.g., `ans = maxd(ans, val)`).
    *   **Unused Functions**: Functions like `gcd`, `lcm`, `square`, and `swap` are defined in the C++ snippet but not called in the `main` logic. They can be omitted or kept as unused methods. I will omit them to keep the code clean, as they are not part of the execution flow.
5.  **Main Logic**:
    *   Translate global variables `dqz`, `sgz`, `dqcx`, `sgcx`, `ans` to local `int` variables in `main`.
    *   Translate the `for` loop and conditional logic (`if`, `else`) 1:1.
    *   Ensure the bitwise shift `<< 1` is translated to multiplication `* 2` or kept as `<< 1` (both work in Java).
    *   Call `print(ans)` at the end.

### Java Code

<CODE>
import java.io.*;
import java.util.StringTokenizer;

public class a_1138 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    // Function to read integer, matching C++ read(T&x) logic
    static int readInt() throws IOException {
        int c = (int) br.read();
        int x = 0;
        boolean fla = false;
        
        // Skip non-digit characters
        while (c != -1 && !Character.isDigit(c)) {
            if (c == '-') fla = true;
            c = (int) br.read();
        }
        
        if (c == -1) return 0;
        
        // Read digits
        while (c != -1 && Character.isDigit(c)) {
            x = x * 10 + (c - '0');
            c = (int) br.read();
        }
        
        if (fla) x = -x;
        return x;
    }

    // Helper functions for max and min
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // maxd: modify 'a' to be max(a, b). 
    // Since Java passes primitives by value, we return the updated value.
    static int maxd(int a, int b) {
        if (a > b) a = b;
        return a;
    }
    
    // mind: modify 'a' to be min(a, b)
    static int mind(int a, int b) {
        if (a < b) a = b;
        return a;
    }

    // printe: recursive print of non-negative integer
    static void printe(int x) {
        if (x >= 10) {
            printe(x / 10);
        }
        System.out.print(x % 10 + '0');
    }

    // print: print integer with sign
    static void print(int x) {
        if (x < 0) {
            System.out.print("-");
            printe(-x);
        } else {
            printe(x);
        }
    }

    public static void main(String[] args) throws IOException {
        int n = readInt();
        
        // Variables matching C++ global variables
        int dqz = 100001;
        int sgz = 100001;
        int dqcx = -100000000;
        int sgcx = -100000000;
        int ans = 0;
        
        for (int i = 1; i <= n; i++) {
            int a = readInt();
            
            if (a == dqz) {
                dqcx++;
            } else {
                sgz = dqz;
                sgcx = dqcx;
                dqz = a;
                dqcx = 1;
            }
            
            // maxd(ans, min(dqcx, sgcx) << 1)
            // In C++, maxd modifies ans in place. In Java, we assign the return value.
            int val = min(dqcx, sgcx);
            val = val << 1; // Equivalent to * 2
            ans = maxd(ans, val);
        }
        
        print(ans);
    }
}
</CODE>