Translate this C++ code to Java code. The main class name should be b_1051. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define LL long long 
using namespace std;
LL l,r,a;

LL gcd(LL a,LL b){
	if (b==0) return a;
	return gcd(b,a%b);
}

int main(){
	scanf("%lld%lld",&l,&r);
	if ((r-l+1)%2==1) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (LL i=l;i<=r;i+=2)	printf("%lld %lld\n",i,i+1);
	 
}

Here is the plan for the C++ to Java translation:

1.  **Headers and Includes**:
    *   C++ `#include <bits/stdc++.h>` is a non-standard header including everything. In Java, we don't need explicit includes for basic I/O like `printf` and `scanf`, as `System.out` and `Scanner`/`BufferedReader` are part of the standard library.
    *   C++ `#include <cstdio>` is needed for `scanf` and `printf`. In Java, we will use `Scanner` (for simplicity) or `BufferedReader` (for performance). Given the simplicity of the task, `Scanner` is sufficient.
    *   C++ `#include <cstdlib>` is needed for `exit` (though not explicitly used, it's often included). Java handles program termination naturally.
    *   C++ `#include <iostream>` is needed for `cin`/`cout`. We will use `Scanner` instead.
    *   C++ `#include <cstring>` is for string functions. Not used here, but good to note.

2.  **Data Types**:
    *   C++ `long long` is mapped to Java `long`. The code uses `LL` typedef, so we will use `long` directly in Java.
    *   `LL l, r, a;` becomes `long l, r, a;`. Note that `a` is declared but never used in the provided code.

3.  **Functions**:
    *   C++ `gcd` function: The logic is identical (`if (b==0) return a; return gcd(b, a%b);`). In Java, this becomes a static method `gcd` inside the main class.
    *   `main` function: Becomes the `public static void main(String[] args)` method.
    *   I/O operations: `scanf` and `printf` will be replaced by `Scanner` (`nextLong()`) and `System.out.println()`.

4.  **Logic Flow**:
    *   Read `l` and `r`.
    *   Check if the count of numbers in the range `[l, r]` is odd: `(r - l + 1) % 2 == 1`.
    *   If odd, print "NO".
    *   Otherwise, print "YES" and iterate from `l` to `r` with a step of 2, printing pairs `i` and `i+1`.

5.  **Class Structure**:
    *   The main class name must be `b_1051`.
    *   The `gcd` function should be a `static` method within this class.

6.  **Incremental Tasks**:
    *   Define the class structure.
    *   Implement the `gcd` function (though not strictly used in the logic, it is present in the source code, so I will include it to be faithful to the source structure).
    *   Implement the `main` method with variable declarations.
    *   Implement the input reading logic.
    *   Implement the conditional logic and output.
    *   Implement the loop for printing pairs.

Here is the resulting Java code:

<CODE>
import java.util.Scanner;

public class b_1051 {
    long l, r, a;

    public static void gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            l = scanner.nextLong();
            r = scanner.nextLong();
            a = scanner.nextLong(); // Read 'a' even if unused to match structure, though input format implies only 2 numbers.
            // Note: The C++ code reads 2 numbers into l and r. The variable 'a' is declared but not read.
            // I will strictly follow the C++ logic which reads l and r.
            // Re-evaluating the C++ code: scanf("%lld%lld",&l,&r);
            // It does NOT read 'a'. So I will only read l and r.
            // Correcting the reading logic:
            l = scanner.nextLong();
            r = scanner.nextLong();
        }

        if ((r - l + 1) % 2 == 1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (long i = l; i <= r; i += 2) {
                System.out.println(i + " " + (i + 1));
            }
        }
    }
}
</CODE>

**Correction on `gcd` method**:
In C++, `gcd` returns a `long long`. In Java, the method must return a value.
C++: `LL gcd(LL a,LL b){ ... return ... }`
Java: `public static long gcd(long a, long b)`
However, looking at the provided C++ code, the `gcd` function is defined but **never called** inside `main`. It is dead code in the context of the provided snippet.
To be faithful to the source code structure, I will keep the `gcd` method definition, but since it returns a `long` and the C++ version returns `LL` (long long), I will map it to `long`.
Wait, the C++ code has a syntax error in the `gcd` return statement if it's meant to be a void function or if the return type doesn't match the return value?
No, `LL gcd` returns `LL`. `return a` returns `LL`. `return gcd(...)` returns `LL`.
In Java, `long gcd` returns `long`. `return a` returns `long`.
However, the C++ code defines `gcd` but does not use it. I will include it as a static method.
Actually, looking closely at the C++ code:
`LL gcd(LL a,LL b){ if (b==0) return a; return gcd(b,a%b); }`
This is a recursive function returning `long long`.
In the Java translation, I should define it as a `static` method.
The `main` method in Java is `public static void main`.
The variables `l`, `r`, `a` are instance variables. Accessing them from the static `gcd` method would require passing them or making `gcd` non-static (which requires an instance).
In the C++ code, `gcd` accesses global variables `l` and `r`? No, it takes arguments `a` and `b`.
Wait, the C++ code defines `LL l, r, a;` globally.
Then `LL gcd(LL a,LL b)` takes local arguments.
It does not use the global `l`, `r`, `a` inside `gcd`.
So the static nature is fine.
However, in the `main` function, `l` and `r` are global.
In Java, if I define `l` and `r` as instance variables, I must access them via `this.l` and `this.r` or pass them to `gcd`.
The C++ code uses global variables.
So in Java, I can make `l` and `r` static fields to mimic the global scope, or instance fields.
If I make them instance fields, I need to pass them to `gcd`.
But `gcd` is not called in `main`.
So I will define `l` and `r` as static fields to mimic the global C++ behavior, or just instance fields and not use them (since they aren't used in `main` anyway).
The most direct translation of "Global Variables" in C++ to Java is "Static Fields".
So I will make `l`, `r`, `a` static fields.
The `gcd` method will remain `static`.
The `main` method will use these static fields.

Let's refine the plan:
1. Class `b_1051`.
2. Static fields `l`, `r`, `a` (long).
3. Static method `gcd(long a, long b)` returning `long`.
4. Static method `main`.
5. Read input using `Scanner`.
6. Logic: check parity of `(r - l + 1)`.
7. Output.

One detail: The C++ code reads `l` and `r`. It does not read `a`.
`scanf("%lld%lld",&l,&r);`
So `a` is declared but unused. I will declare it but not read it to match the C++ structure exactly, or I can remove it as it's unused. To be faithful to the source, I'll declare it.
Wait, the C++ code has `#include <bits/stdc++.h>`. I will remove this and use standard Java imports.

Revised Code Structure:
```java
import java.util.Scanner;

public class b_1051 {
    static long l, r, a;
    
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            l = sc.nextLong();
            r = sc.nextLong();
            // a is declared but not read in C++, so we don't read it here.
        }
        // ... rest of logic
    }
}
```
Wait, `gcd` is defined but not used. I will keep it as is to match the source code provided.

One specific check: `gcd` return type.
C++: `LL gcd` (returns `long long`).
Java: `long gcd` (returns `long`).
This is valid.

One more check on `gcd` usage:
The provided C++ code defines `gcd` but never calls it.
`main` just does math on `l` and `r` directly.
So `gcd` is dead code. I will include it.

Final check on variable access:
C++: Global `l`, `r`.
Java: Static `l`, `r`.
This is the correct mapping.

One detail: `if ((r-l+1)%2==1)`
In Java, this is `if ((r - l + 1) % 2 == 1)`.
Since `l` and `r` are `long`, the arithmetic works correctly.

One detail: `printf("%lld %lld\n",i,i+1);`
In Java: `System.out.println(i + " " + (i + 1));`
This creates a string, which is slightly less efficient than `printf` but standard for simple Java solutions. `PrintWriter` could be used for speed, but `System.out.println` is safer for correctness and simpler for this context.

Let's write the code.

<CODE>
import java.util.Scanner;

public class b_1051 {
    static long l, r, a;

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            l = scanner.nextLong();
            r = scanner.nextLong();
        }

        if ((r - l + 1) % 2 == 1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (long i = l; i <= r; i += 2) {
                System.out.println(i + " " + (i + 1));
            }
        }
    }
}
</CODE>

Wait, I should check if `a` needs to be read.
C++: `LL l,r,a;` then `scanf("%lld%lld",&l,&r);`.
`a` is never touched. So I should not read it.
The plan says "consider whether the work could be split up".
I have split the plan into headers, types, functions, logic, and class structure.
The code looks solid.

One small optimization/correction:
In C++, `long long` is 64-bit. In Java, `long` is 64-bit.
The logic `(r - l + 1) % 2` works for negative numbers too?
If `l > r`, `r - l + 1` might be negative.
Example: `l=5, r=3`. `3-5+1 = -1`. `-1 % 2` is `-1` in Java (and C++).
`-1 != 1`. So it goes to `else` (YES).
But range `[5, 3]` is empty.
The C++ code logic:
`if ((r-l+1)%2==1)` -> NO.
If `r < l`, `r-l+1` is negative.
If `r-l+1` is `-1`, `-1 % 2` is `-1`. `-1 != 1`. So it prints YES.
But the loop `for (LL i=l; i<=r; i+=2)` will not execute if `l > r`.
So if `l > r`, it prints YES and no output.
This matches the C++ logic exactly.
So no change needed for logic.

Final check on the `gcd` function.
The C++ code:
`LL gcd(LL a,LL b){ if (b==0) return a; return gcd(b,a%b); }`
My Java code:
`static long gcd(long a, long b) { if (b == 0) return a; return gcd(b, a % b); }`
This is correct.

I will put the code inside the `<CODE>` tags as requested.

<CODE>
import java.util.Scanner;

public class b_1051 {
    static long l, r, a;

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            l = scanner.nextLong();
            r = scanner.nextLong();
            // 'a' is declared in C++ but not read in the input logic
        }

        if ((r - l + 1) % 2 == 1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (long i = l; i <= r; i += 2) {
                System.out.println(i + " " + (i + 1));
            }
        }
    }
}
</CODE>

Wait, I should check the input reading again.
`scanf("%lld%lld",&l,&r);`
It reads two longs.
In Java `scanner.nextLong()` reads one long.
So `l = scanner.nextLong(); r = scanner.nextLong();` is correct.
The variable `a` is declared `LL l,r,a;` in C++.
In Java `static long l, r, a;`.
I will leave `a` declared but not used, as per the C++ code structure.

One detail: `#include <bits/stdc++.h>` implies competitive programming context.
Sometimes `Scanner` is too slow. But for this simple logic, it's fine.
Also, the problem statement asks to translate the code. It doesn't explicitly ask to optimize for performance beyond the translation.
So `Scanner` is acceptable.

I will finalize the code block.

One minor thing: `if (scanner.hasNextLong())` is good practice, but in competitive programming, it's assumed input is valid.
The C++ code `scanf` doesn't check. It assumes input exists.
I will keep the check or remove it?
If I remove it, `scanner.nextLong()` throws exception if empty.
If I keep it, it's safer.
But `scanf` returns number of items read.
To be strictly faithful to C++, I should probably just call `nextLong()`.
However, `Scanner` is safer.
I'll stick to the safer version or just direct calls.
Given the C++ code doesn't check return value of scanf, I will just call `nextLong()`.
Actually, if I just call `nextLong()`, it's a direct translation of the behavior (assuming valid input).
If I add `hasNextLong`, it adds logic not present in C++.
I will remove `if (scanner.hasNextLong())` to keep it closer to the original C++ logic, assuming valid input as per typical CP problems.
Wait, `scanf` returns. If it fails, it returns 0.
I will assume valid input.
So:
`l = scanner.nextLong();`
`r = scanner.nextLong();`

Final check on the `gcd` method.
In C++, `gcd` is defined globally.
In Java, it must be `static` to be called as `b_1051.gcd(...)`.
But it is not called. So it doesn't matter much.
I will make it `static` to match the global scope of the C++ function.

One detail: `#include <cstdio>` is for `scanf`/`printf`.
`#include <iostream>` is for `cin`/`cout`.
`#include <bits/stdc++.h>` is for everything.
I am using `Scanner` which is in `java.util`.
So `import java.util.Scanner;` is needed.
`printf` is not used in Java, so no `java.io` needed unless I use `PrintWriter`.
I used `System.out.println`, so no extra imports needed.

Final check on variable `a`.
It is declared `LL l, r, a;`.
I will declare `static long l, r, a;`.
It is never used.
I will keep the declaration to match the C++ source.

The code looks ready.

```java
import java.util.Scanner;

public class b_1051 {
    static long l, r, a;

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        l = scanner.nextLong();
        r = scanner.nextLong();
        // 'a' is declared but not read in the C++ source code logic

        if ((r - l + 1) % 2 == 1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            for (long i = l; i <= r; i += 2) {
                System.out.println(i + " " + (i + 1));
            }
        }
    }
}
```
Wait, I need to make sure I don't miss anything.
The C++ code:
`scanf("%lld%lld",&l,&r);`
It reads 2 values.
If I use `Scanner`, `nextLong()` reads 1 value.
So `l = scanner.nextLong(); r = scanner.nextLong();` is correct.
The variable `a` is declared but not read.
I will add a comment about `a`.

One detail: `gcd` function.
`LL gcd(LL a,LL b)`
`a` and `b` are parameters.
In C++, `a` and `b` shadow the global variables `a`?
No, `l, r, a` are global.
`gcd` takes `a` and `b`.
Inside `gcd`, `a` refers to the parameter.
In Java, parameters shadow fields.
So `static long gcd(long a, long b)` is fine.

Okay, ready to generate.

One last check:
The C++ code uses `#include <bits/stdc++.h>`.
This is a GCC specific header.
In Java, we just import what we need.
So `import java.util.Scanner;` is sufficient.

The class name must be `b_1051`.
The code must start with `<CODE>` and end with `</CODE>`.
Wait, the prompt says "token "<CODE>" at the beginning and at the end".
So:
<CODE>
...
</CODE>
Yes.

Double check the C++ code logic for the loop.
`for (LL i=l;i<=r;i+=2)`
It starts at `l`.
If `l` is odd, `i` is odd.
`i+1` is even.
It prints `i` and `i+1`.
Then `i` becomes `i+2`.
Next pair `i+2` (odd) and `i+3` (even).
It prints pairs of (odd, even).
If `l` is even, `i` is even.
`i+1` is odd.
It prints pairs of (even, odd).
The condition `if ((r-l+1)%2==1)` checks if the count of numbers is odd.
If count is odd, it prints NO.
If count is even, it prints YES and prints pairs.
This logic is preserved.

One detail: `if (b==0) return a;`
In Java, this is fine.

I will write the code now.
</think>

Here is the plan for the translation:

1.  **Headers**: The C++ code uses `#include <bits/stdc++.h>`, which includes standard libraries. In Java, we need to explicitly import the required classes. The code uses `scanf` and `printf` from `<cstdio>`, so we will use `java.util.Scanner` and `java.lang.System` (implicitly available) for I/O.
2.  **Data Types**: The C++ code uses `long long` (defined as `LL`). In Java, the equivalent 64-bit integer type is `long`.
3.  **Variables**: The C++ code declares global variables `l`, `r`, and `a` of type `LL`. In Java, global variables become static class fields. So, `static long l, r, a;` will be used. Note that `a` is declared but not used in the logic, so we will keep it declared to match the source structure.
4.  **Functions**:
    *   The `gcd` function in C++ is a global function. In Java, it should be a `static` method within the class. The return type `LL` maps to `long`.
    *   The `main` function in C++ maps to `public static void main(String[] args)` in Java.
5.  **I/O Operations**: `scanf` and `printf` will be replaced by `Scanner` (`nextLong()`) and `System.out.println()`.
6.  **Logic**: The logic for checking parity `(r-l+1)%2==1` and the loop `for (LL i=l;i<=r;i+=2)` will be translated directly, adjusting for Java syntax (e.g., `++i` vs `i++` doesn't matter here, but `i+=2` is the same).

<CODE>
import java.util.Scanner;

public class b_1051 {
    // C++ global variables mapped to Java static fields
    static long l, r, a;

    // C++ global function mapped to Java static method
    // LL maps to long
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading input using Scanner instead of scanf
        // The C++ code reads two values into l and r
        if (scanner.hasNextLong()) {
            l = scanner.nextLong();
            r = scanner.nextLong();
            // Variable 'a' is declared in C++ but not read in the input logic
        }

        // Logic check: if the number of elements in range [l, r] is odd
        if ((r - l + 1) % 2 == 1) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
            // Loop with step 2 to print pairs
            for (long i = l; i <= r; i += 2) {
                System.out.println(i + " " + (i + 1));
            }
        }
    }
}
</CODE>