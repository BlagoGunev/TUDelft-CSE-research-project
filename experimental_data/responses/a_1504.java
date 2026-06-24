Translate this C++ code to Java code. The main class name should be a_1504. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
int n,t_case;
char a[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",a+1);
		n=strlen(a+1)+1;
		int pos=0;
		for(ri i=1;i<n;++i)
			if(a[n-i]!='a'){
				pos=i;
				break;
			}
		if(pos){
			puts("YES");
			for(ri i=1;i<pos;++i)putchar(a[i]);
			putchar('a');
			for(ri i=pos;i<n;++i)putchar(a[i]);
			putchar(10);
		}
		else puts("NO");
	}
	return 0;
}

Here is the plan for translating the C++ code to Java:

### Translation Plan

1.  **Headers and Imports**:
    *   C++ uses `#include<bits/stdc++.h>`. In Java, we must explicitly import the necessary classes. We will need `java.util.Scanner` for input and `java.io.PrintWriter` (or `System.out`) for output.
    *   The `using namespace std;` directive is not needed in Java.

2.  **Data Types and Constants**:
    *   `typedef long long ll;` is ignored as the code does not explicitly use `long long` for calculations (only `int` is used).
    *   `const int maxn=3e5+10;` becomes `final int maxn = 300010;`.
    *   `char a[maxn];` becomes `char[] a = new char[maxn];`.

3.  **Input/Output Logic**:
    *   `scanf` is replaced by `Scanner.nextInt()` and `Scanner.next()`.
    *   `puts` and `putchar` are replaced by `System.out.println` and `System.out.print`.
    *   The logic for `scanf("%s", a+1)` is replaced by `s = sc.next()`. We store this in `a` but need to handle indices carefully. Since the C++ code iterates from index `1` to `n` and skips index `0`, in Java we will read the string into a `String` or `char[]` and iterate based on the string's length. To match the C++ logic exactly (where `a[0]` is unused), we can either allocate `maxn` and fill indices starting from 1, or simply use `String` methods and adjust indices. Given the constraint `a[n-i]`, using a `String` is cleaner and safer than a fixed-size `char` array for Java, but to strictly mimic the C++ structure, we will stick to the array approach or convert the string logic to match the C++ indices.
    *   *Decision*: To keep the logic identical and avoid `String.charAt` overhead (though negligible here), I will use a `String` for storage but adjust the logic to simulate the C++ array behavior. The C++ code reads into `a+1` (index 1). In Java, if we store in `a[1]`, we must skip `a[0]`.
    *   *Refined Decision*: Using `String` is much more idiomatic in Java. However, the C++ code relies on `a[n-i]` where `n` is the length. If I use `String`, `n` is `s.length()`. The C++ code iterates `i` from `1` to `n-1` (since loop condition is `i<n`). If I use `String`, `s.charAt(i)` corresponds to `a[i+1]` in C++?
        *   C++: `scanf("%s", a+1)`. This fills `a[1]`, `a[2]`, ..., `a[n]`. `a[0]` is untouched. `n` is `strlen(a+1) + 1`.
        *   Java `String s = sc.next()`: `s.length()` corresponds to `n` in C++.
        *   C++ `a[n-i]`: In Java `s`, this corresponds to `s.charAt(n-i)`.
        *   C++ `a[i]`: In Java `s`, this corresponds to `s.charAt(i-1)`.
        *   C++ `a[pos]`: In Java `s`, this corresponds to `s.charAt(pos-1)`.
        *   *Correction*: The C++ code reads into `a+1`. So `a[1]` is the first character.
        *   C++ loop: `for(ri i=1;i<n;++i)`. `i` goes from 1 to `n-1`.
        *   If I use `String s` (length `n`), `s.charAt(0)` is `a[1]`.
        *   So `a[i]` in C++ is `s.charAt(i-1)` in Java.
        *   `a[n-i]` in C++ is `s.charAt(n-i-1)` in Java.
        *   Let's verify: C++ `i=1` -> `a[n-1]`. Java `s.charAt(n-2)`.
        *   C++ `i=n-1` -> `a[1]`. Java `s.charAt(0)`.
        *   This index mapping is slightly complex.
        *   *Alternative*: Just allocate `char[] a = new char[n]` and fill it directly? No, the C++ code uses `scanf("%s", a+1)`.
        *   Let's stick to the `String` approach but map indices carefully to match the C++ logic.
        *   C++ Logic: Finds the first non-'a' character starting from the *end* of the string (index 1 to `n-1`).
        *   Java Logic: Iterate from `n-2` down to `0`. Find the first char that is not 'a'.

4.  **Main Class Structure**:
    *   C++ `main` becomes Java `public static void main(String[] args)`.
    *   Class name `a_1504`.

5.  **Incremental Steps**:
    *   Step 1: Setup class and imports.
    *   Step 2: Implement input reading loop.
    *   Step 3: Implement the search logic.
    *   Step 4: Implement output logic.
    *   Step 5: Combine and finalize.

### Java Code Implementation

```java
import java.util.Scanner;

public class a_1504 {
    // maxn corresponds to the C++ constant
    // C++: 3e5 + 10 = 300010
    private static final int maxn = 300010;
    
    // We don't strictly need a large char array if we use String, 
    // but to match the C++ structure conceptually, we could use one.
    // However, using String is safer for Java and avoids manual memory management.
    // We will use String to store the input.
    // Note: C++ stores input at a[1]...a[n]. 
    // Java String indices are 0...n-1.
    // Mapping: C++ a[i] -> Java s.charAt(i-1) for i >= 1.
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // C++: scanf("%d",&t_case);
        if (sc.hasNextInt()) {
            int t_case = sc.nextInt();
            while (t_case-- > 0) {
                // C++: scanf("%s", a+1);
                // We read into a String. 
                // In C++, a[1] is the first char. In Java s[0] is the first char.
                String s = sc.next();
                // C++: n = strlen(a+1) + 1;
                // In C++, n is the length of the string stored in a[1..n].
                // Since we mapped a[1..n] to s[0..n-1], the length n in C++ is s.length().
                int n = s.length();
                
                // Logic translation:
                // C++: for(ri i=1;i<n;++i) if(a[n-i]!='a') ...
                // In C++, a is 1-indexed. a[1] is first char. a[n] is last char.
                // Java s is 0-indexed. s[0] is first char. s[n-1] is last char.
                // C++ a[i] corresponds to Java s.charAt(i-1).
                // C++ a[n-i] corresponds to Java s.charAt(n-i-1).
                // Loop in C++: i goes from 1 to n-1.
                // Java loop: j goes from 0 to n-2.
                // Check: C++ a[n-i] != 'a'
                // Java s.charAt(n-i-1) != 'a'
                
                int pos = 0;
                // C++ loop: i from 1 to n-1
                // Java loop: j from 0 to n-2
                // Mapping: j = i - 1.
                // Condition: if(s.charAt(n - j - 1) != 'a')
                // In C++, pos is set to i. In Java, pos should be j + 1.
                
                boolean found = false;
                for (int j = 0; j < n - 1; j++) {
                    // C++: if(a[n-i]!='a')
                    // Java: if(s.charAt(n - j - 1) != 'a')
                    if (s.charAt(n - j - 1) != 'a') {
                        pos = j + 1;
                        found = true;
                        break;
                    }
                }
                
                if (pos != 0) {
                    System.out.println("YES");
                    // C++: for(ri i=1;i<pos;++i)putchar(a[i]);
                    // Java: for(int i=1;i<pos;i++) print s.charAt(i-1);
                    for (int i = 1; i < pos; i++) {
                        System.out.print(s.charAt(i - 1));
                    }
                    // C++: putchar('a');
                    System.out.print('a');
                    // C++: for(ri i=pos;i<n;++i)putchar(a[i]);
                    // Java: for(int i=pos;i<n;i++) print s.charAt(i-1);
                    for (int i = pos; i < n; i++) {
                        System.out.print(s.charAt(i - 1));
                    }
                    // C++: putchar(10);
                    System.out.println();
                } else {
                    System.out.println("NO");
                }
            }
        }
        sc.close();
    }
}
```

```java
import java.util.Scanner;

public class a_1504 {
    // C++: const int maxn=3e5+10;
    // Java: final int maxn = 300010;
    // Although not strictly used for storage in this specific snippet (as String is used), 
    // we define it to match the C++ declaration.
    private static final int maxn = 300010;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // C++: scanf("%d",&t_case);
        if (sc.hasNextInt()) {
            int t_case = sc.nextInt();
            while (t_case-- > 0) {
                // C++: scanf("%s", a+1);
                // We use a String to store the input.
                // C++ logic fills a[1] to a[n].
                // Java String s will store these characters at indices 0 to n-1.
                String s = sc.next();
                
                // C++: n = strlen(a+1) + 1;
                // In C++, a+1 is a pointer to the first element of the array (index 1).
                // strlen returns the number of characters excluding null terminator.
                // If we have "abc", a[1]='a', a[2]='b', a[3]='c'. strlen(a+1) is 3. n becomes 4.
                // Wait, let's re-read the C++ code carefully.
                // a is a char array. scanf("%s", a+1) reads into a[1].
                // strlen(a+1) counts characters in a[1]...a[k].
                // n = strlen(...) + 1.
                // If input is "abc", a[1]='a', a[2]='b', a[3]='c', a[4]='\0'.
                // strlen(a+1) returns 3. n = 4.
                // Loop i=1 to i<4 (i.e., 1, 2, 3).
                // a[n-i]: i=1 -> a[3] ('c'). i=2 -> a[2] ('b'). i=3 -> a[1] ('a').
                // So the loop iterates backwards through the string "abc".
                // In Java, if s="abc", s.length() is 3.
                // To match C++ n=4, Java n should be s.length().
                // Wait, if C++ n=4, loop goes 1..3.
                // If Java n=3, loop goes 0..2.
                // C++ a[1] -> Java s[0].
                // C++ a[i] -> Java s[i-1].
                // C++ a[n-i] -> Java s[n-i-1].
                // Let's check the loop bounds.
                // C++: i from 1 to n-1.
                // Java: j from 0 to n-2.
                // C++: pos = i. Java: pos = j + 1.
                
                int n = s.length(); 
                // Wait, strictly speaking, if C++ code does n = strlen(a+1)+1, and a+1 points to start of string.
                // If string is "abc", a[1]='a', a[2]='b', a[3]='c', a[4]='\0'.
                // strlen(a+1) is 3. n = 4.
                // Loop i=1 to 3.
                // Java s="abc", length 3.
                // If I use n = s.length(), n=3.
                // Loop j=0 to 2.
                // C++ a[n-i] -> Java s[n-j-1].
                // If n=4 (C++), j=0 -> index 3. If n=3 (Java), j=0 -> index 2.
                // So n should be s.length() for the logic to hold correctly in Java.
                // Because C++ loop stops before n (exclusive). Java loop stops before n (exclusive).
                // C++ a[i] maps to s[i-1]. C++ a[n-i] maps to s[n-i-1].
                // So we just use n = s.length().
                
                int pos = 0;
                boolean found = false;
                
                // C++: for(ri i=1;i<n;++i)
                // Java: for(int j=0; j<n-1; j++)
                for (int j = 0; j < n - 1; j++) {
                    // C++: if(a[n-i]!='a')
                    // Java: if(s.charAt(n - j - 1) != 'a')
                    if (s.charAt(n - j - 1) != 'a') {
                        pos = j + 1;
                        found = true;
                        break;
                    }
                }
                
                if (pos != 0) {
                    System.out.println("YES");
                    // C++: for(ri i=1;i<pos;++i)putchar(a[i]);
                    // Java: for(int i=1; i<pos; i++) System.out.print(s.charAt(i-1));
                    for (int i = 1; i < pos; i++) {
                        System.out.print(s.charAt(i - 1));
                    }
                    // C++: putchar('a');
                    System.out.print('a');
                    // C++: for(ri i=pos;i<n;++i)putchar(a[i]);
                    // Java: for(int i=pos; i<n; i++) System.out.print(s.charAt(i-1));
                    for (int i = pos; i < n; i++) {
                        System.out.print(s.charAt(i - 1));
                    }
                    // C++: putchar(10);
                    System.out.println();
                } else {
                    System.out.println("NO");
                }
            }
        }
        sc.close();
    }
}
```