Translate this C++ code to Java code. The main class name should be c_1367. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

using namespace std;
char a[200005];
int in[200005];
int main()
{
    int t,n,tmp,k,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        scanf("%s",a);
        tmp=0;ans=0;
        in[tmp++]=-k-1;
        for(int i=0;i<n;++i){
            if(a[i]=='1')
                in[tmp++]=i;
        }
        in[tmp++]=n+k;
            int i=0,j=0;
            for(;i<n&&j<tmp;++i){
                while(i-in[j]>k&&in[j+1]-i>k){
                    ++ans,i+=k+1;
                }
                while(i>in[j+1])
                    ++j;
            }
            printf("%d\n",ans);
    }
}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**:
    *   C++ includes `<bits/stdc++.h>` and uses `using namespace std;`.
    *   Java requires specific imports (`java.util.Scanner`, `java.io.PrintWriter` or `System.out`, etc.). We will use `java.util.Scanner` for simplicity, though `BufferedReader` would be faster for large inputs. Given the array size (200,000), `Scanner` might be slow, but it's the direct equivalent of `cin`/`scanf` for logic demonstration. We will use `Scanner` for readability, but note that in a competitive programming context, `BufferedReader` + `StringTokenizer` is preferred. For this translation, we stick to standard `Scanner` to mirror the logic structure without adding excessive boilerplate unless necessary for performance.
    *   `main` function becomes `public static void main(String[] args)`.

2.  **Global Arrays**:
    *   C++: `char a[200005];` and `int in[200005];`.
    *   Java: These must be instance variables or static. Since the logic runs inside `main` and reuses them for multiple test cases (`t`), making them `static` is the most efficient way to avoid re-allocating large arrays every time.
    *   Max size: 200005. In Java, arrays are objects, so we define `char[] a = new char[200005];` and `int[] in = new int[200005];`.

3.  **Input/Output**:
    *   `scanf("%d", &t)` $\rightarrow$ `sc.nextInt()`.
    *   `scanf("%d %d", &n, &k)` $\rightarrow$ `sc.nextInt()` twice.
    *   `scanf("%s", a)` $\rightarrow$ `sc.next()` (reads a string token). We need to handle the string length carefully since C++ `scanf("%s")` fills the array starting at index 0. In Java, `sc.next()` returns a String. We will convert this String to a char array or just access characters via the String. Accessing via String (`str.charAt(i)`) is more idiomatic in Java than managing a fixed-size char array manually, but to strictly follow the C++ structure (where `a` is a global array), we can store the string in a `String` variable and use it, or fill the global char array. Given the constraints and Java's string immutability, using a `String` variable `s` and accessing `s.charAt(i)` is cleaner, but to mimic the C++ global array `a`, we can either use the String directly or fill the array. Let's use a `String` variable `s` to hold the input string for the current test case to avoid the overhead of filling the large global array every time, as Java Strings are immutable and efficient enough here. However, to be faithful to the C++ structure where `a` is a buffer, we could technically fill it, but that's inefficient in Java. A better approach is to treat the input string as the source of truth.
    *   `printf("%d\n", ans)` $\rightarrow` `System.out.println(ans)`.

4.  **Logic Translation**:
    *   Variable declarations: `int t, n, tmp, k, ans;` $\rightarrow$ Java local variables.
    *   Loop `while(t--)` $\rightarrow$ `while (t-- > 0)` or a `do-while` loop.
    *   Array indexing: C++ `in[tmp++] = val` $\rightarrow$ `in[tmp++] = val` works the same in Java.
    *   String access: C++ `a[i]` $\rightarrow$ `s.charAt(i)` (if using String) or `a[i]` (if using char array). Since `scanf("%s", a)` reads into a C-style string, in Java `sc.next()` gives us the string. We will read the string into a local variable `s`.
    *   Nested loops and conditionals: Direct translation.
        *   `if(a[i]=='1')` $\rightarrow$ `if (s.charAt(i) == '1')`.
        *   `while(i-in[j]>k && in[j+1]-i>k)` $\rightarrow$ Same logic.
        *   `while(i>in[j+1])` $\rightarrow$ Same logic.

5.  **Incremental Tasks**:
    *   Step 1: Set up class structure and imports.
    *   Step 2: Define global arrays (static) to match C++ scope.
    *   Step 3: Translate `main` method signature and variable declarations.
    *   Step 4: Translate input reading loop (`scanf` calls).
    *   Step 5: Translate the population of the `in` array (handling the '1's and boundary conditions).
    *   Step 6: Translate the sliding window logic (the nested while loops).
    *   Step 7: Translate the output statement.

6.  **Edge Cases**:
    *   The C++ code uses `scanf("%s", a)`. If the string is longer than the buffer (unlikely given the problem constraints usually implied by the array size), it's undefined behavior in C++. In Java, `Scanner` handles dynamic sizing.
    *   The `in` array in C++ is global, so it persists across test cases. `tmp` is reset to 0 at the start of each test case. This matches the Java logic.

### Code Implementation

```java
import java.util.Scanner;

public class c_1367 {
    // Global arrays to mimic C++ behavior, reused across test cases
    // Size 200005 to match the C++ declaration char a[200005]; int in[200005];
    // Although in Java we might just use a String for 'a', keeping the structure
    // similar allows us to follow the C++ logic closely. However, using String
    // is more Java-idiomatic. Let's stick to the logic: read string into a variable
    // and map it to the logic. The C++ code uses a global char array 'a'.
    // To be safe and efficient in Java, we will use a String 's' for the input
    // and access it via charAt, effectively replacing 'a'.
    // We keep 'in' as a static int array.
    
    static int[] in;
    // We don't strictly need the char array 'a' if we use String, 
    // but to be faithful to the C++ structure where 'a' is a global buffer:
    // static char[] a = new char[200005]; 
    // Actually, reading into a char array with Scanner is messy. 
    // We will use a String 's' to hold the input for the current test case.
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read number of test cases
        if (!sc.hasNextInt()) return;
        int t = sc.nextInt();
        
        // Initialize the 'in' array globally once.
        // Max index needed is roughly 200005 + buffer. 
        // In C++, it's 200005. We'll allocate slightly more just in case, 
        // or stick to 200005 as per C++ declaration.
        in = new int[200005];

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            
            // Read string 'a'
            // In C++, scanf("%s", a) reads into the global char array.
            // In Java, we read into a String.
            String s = sc.next();
            
            // Logic from C++: tmp=0; ans=0;
            int tmp = 0;
            int ans = 0;
            
            // C++: in[tmp++]=-k-1;
            in[tmp++] = -k - 1;
            
            // C++: for(int i=0;i<n;++i){ if(a[i]=='1') in[tmp++]=i; }
            // Java equivalent using String s
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '1') {
                    in[tmp++] = i;
                }
            }
            
            // C++: in[tmp++]=n+k;
            in[tmp++] = n + k;
            
            // C++ Logic:
            // int i=0,j=0;
            // for(;i<n&&j<tmp;++i){
            //     while(i-in[j]>k&&in[j+1]-i>k){
            //         ++ans,i+=k+1;
            //     }
            //     while(i>in[j+1])
            //         ++j;
            // }
            
            int i = 0;
            int j = 0;
            
            // Note: In the C++ code, 'i' iterates up to 'n'. 
            // In Java, we use a while loop or for loop. 
            // The condition is i < n && j < tmp.
            
            while (i < n && j < tmp) {
                // while(i-in[j]>k&&in[j+1]-i>k){
                while (i - in[j] > k && (j + 1) < tmp && in[j + 1] - i > k) {
                    ans++;
                    i += k + 1;
                }
                
                // while(i>in[j+1]) ++j;
                // We need to ensure j+1 is valid before accessing in[j+1]
                // However, the outer loop condition ensures j < tmp, so j+1 <= tmp.
                // But we must ensure we don't go out of bounds if j+1 == tmp? 
                // The C++ code assumes in[tmp] exists (it does, n+k).
                // So j can go up to tmp-1.
                while (i > in[j + 1]) {
                    j++;
                }
            }
            
            // C++: printf("%d\n", ans);
            System.out.println(ans);
        }
        
        sc.close();
    }
}
```

```java
<CODE>
import java.util.Scanner;

public class c_1367 {
    // Global array to mimic C++ behavior.
    // Size 200005 to match the C++ declaration int in[200005];
    static int[] in;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read number of test cases
        if (!sc.hasNextInt()) return;
        int t = sc.nextInt();
        
        // Initialize the 'in' array globally once.
        // Max index needed is roughly 200005 + buffer. 
        // We allocate 200005 as per C++ declaration.
        in = new int[200005];

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            
            // Read string 'a'. In C++, this fills the global char array.
            // In Java, we use a String for efficiency and idiomatic usage.
            String s = sc.next();
            
            // Logic from C++: tmp=0; ans=0;
            int tmp = 0;
            int ans = 0;
            
            // C++: in[tmp++]=-k-1;
            in[tmp++] = -k - 1;
            
            // C++: for(int i=0;i<n;++i){ if(a[i]=='1') in[tmp++]=i; }
            // Java equivalent using String s
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '1') {
                    in[tmp++] = i;
                }
            }
            
            // C++: in[tmp++]=n+k;
            in[tmp++] = n + k;
            
            // C++ Logic:
            // int i=0,j=0;
            // for(;i<n&&j<tmp;++i){
            //     while(i-in[j]>k&&in[j+1]-i>k){
            //         ++ans,i+=k+1;
            //     }
            //     while(i>in[j+1])
            //         ++j;
            // }
            
            int i = 0;
            int j = 0;
            
            // Translating the for loop to a while loop for clarity and safety
            while (i < n && j < tmp) {
                // while(i-in[j]>k&&in[j+1]-i>k){
                // Added check (j + 1) < tmp to be safe, though logic implies j < tmp-1 here usually
                while (i - in[j] > k && (j + 1) < tmp && in[j + 1] - i > k) {
                    ans++;
                    i += k + 1;
                }
                
                // while(i>in[j+1]) ++j;
                // Ensure j+1 is within bounds
                if (j + 1 < tmp) {
                    while (i > in[j + 1]) {
                        j++;
                    }
                }
            }
            
            // C++: printf("%d\n", ans);
            System.out.println(ans);
        }
        
        sc.close();
    }
}
</CODE>
```