Translate this C++ code to Java code. The main class name should be c_628. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<stdio.h>
#include<string.h>
char a[100005];
int n,k,i,dis,dir;
int main()
{
	while(~scanf("%d%d%s",&n,&k,a))
	{
		a[n]='\0';
		for(i=0;i<n;i++)
		{
			dir= 'z'-a[i]>=13?1:-1;
			dis= 'z'-a[i]>=13?'z'-a[i]:a[i]-'a';
			if(k>dis)
			{
				k-=dis;
				a[i]=a[i]+dis*dir;
			}
			else
			{
				a[i]=a[i]+k*dir;
				k=0;
				break;
			}
		}
		if(k>0)
			printf("-1\n");
		else
			puts(a);
	}
}

Here is the plan for translating the provided C++ code to Java.

### Translation Plan

1.  **Input/Output Handling**:
    *   **C++**: Uses `scanf` and `printf`/`puts` from `<stdio.h>`.
    *   **Java**: The standard way to handle this is using `Scanner` from `java.util`. Since the input involves a mix of integers and a string, and the string can be long (up to 100,000 characters), `Scanner` is sufficient for this specific logic, though `BufferedReader` is faster for massive inputs. Given the logic (calculating `dis` based on character distance), `Scanner` is acceptable and easier to read for this context.
    *   **Logic**: The C++ `while(~scanf(...))` loop checks for EOF. In Java, we can use `hasNext()` to check if there is more input.
    *   **String Termination**: The C++ code manually terminates the string `a` with `a[n]='\0'`. In Java, `String` is immutable and does not have a null terminator. We will use a `char[]` array to simulate the mutable behavior of C++ strings or simply pass the string length to the logic. The logic `a[n]='\0'` is effectively setting the string length to `n` for the purpose of the loop.

2.  **Data Structures and Variables**:
    *   **C++**: `char a[100005]`, `int n, k, i, dis, dir`.
    *   **Java**: `char[] a` (size 100005 to match), `int n, k, i, dis, dir`.
    *   **Note**: C++ arrays are mutable (`a[i]`), Java `char[]` arrays are also mutable, so the logic `a[i] = ...` works directly.

3.  **Logic Translation**:
    *   **Loop**: `while(~scanf(...))` becomes `while (scanner.hasNext())`.
    *   **Reading**: `scanf("%d%d%s", ...)` becomes `int n = sc.nextInt(); int k = sc.nextInt(); String s = sc.next();`. The string `s` needs to be converted to a `char[]` array.
    *   **Calculation**:
        *   `dir`: `1` if `z` - `a[i]` >= 13, else `-1`.
        *   `dis`: `z` - `a[i]` if `z` - `a[i]` >= 13, else `a[i]` - `a`.
        *   **Shift Logic**: If `k > dis`, subtract `dis` from `k`, update `a[i]`. Else, update `a[i]` with `k` and set `k=0`.
    *   **Output**:
        *   `printf("-1\n")` becomes `System.out.println("-1")`.
        *   `puts(a)` becomes `System.out.println(new String(a))`.

4.  **Class Structure**:
    *   The main class name must be `c_628`.
    *   The `main` method must be `public static void main(String[] args)`.

5.  **Incremental Tasks**:
    *   Step 1: Define the class `c_628` and imports.
    *   Step 2: Implement the `main` method with `Scanner`.
    *   Step 3: Implement the input reading logic (integers and string array).
    *   Step 4: Implement the loop and character shifting logic.
    *   Step 5: Implement the output logic.

### Java Code

```java
import java.util.Scanner;

public class c_628 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Buffer size to match C++ char a[100005]
        char[] a = new char[100005];
        
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();
            
            // Convert String to char array for manipulation
            // In C++, a is a char array. We fill it up to n.
            // We assume the input string fits within the buffer.
            // The C++ logic a[n]='\0' effectively sets the valid length to n.
            // In Java, we just use the string s which has length n.
            // However, to strictly follow the C++ logic where 'a' is a fixed array 
            // and we access 'a[i]', we can just copy the string into the array.
            // Note: C++ code reads string into 'a' (which is a char array).
            // We need to handle the mapping from String to char[] a.
            
            // Since C++ reads into a char array 'a', we assume the input is 
            // placed into 'a' starting at index 0.
            // The string s read by sc.next() corresponds to the content of 'a' from 0 to n-1.
            // Let's copy it to our char array 'a'.
            for (int i = 0; i < n; i++) {
                a[i] = s.charAt(i);
            }
            // In C++, a[n] is set to '\0'. In Java, we don't strictly need to 
            // set a[n] to null terminator because we iterate up to n-1 (i < n).
            
            for (int i = 0; i < n; i++) {
                char c = a[i];
                // C++ logic: dir = 'z'-a[i]>=13?1:-1;
                // In Java, we use the character value directly.
                // 'z' is 122. 'a' is 97.
                // Condition: 122 - c >= 13
                int dir = (122 - c >= 13) ? 1 : -1;
                
                // C++ logic: dis = 'z'-a[i]>=13?'z'-a[i]:a[i]-'a';
                // Equivalent to: if (122 - c >= 13) dis = 122 - c; else dis = c - 97;
                int dis = (122 - c >= 13) ? (122 - c) : (c - 97);
                
                if (k > dis) {
                    k -= dis;
                    // Update character
                    // C++: a[i]=a[i]+dis*dir;
                    // Java: a[i] = (char)(a[i] + dis * dir);
                    a[i] = (char)(a[i] + dis * dir);
                } else {
                    // C++: a[i]=a[i]+k*dir; k=0; break;
                    a[i] = (char)(a[i] + k * dir);
                    k = 0;
                    break;
                }
            }
            
            if (k > 0) {
                System.out.println("-1");
            } else {
                // C++: puts(a);
                // We need to print the string formed by the array up to index n-1
                System.out.println(new String(a, 0, n));
            }
        }
        
        sc.close();
    }
}
```

<CODE>
import java.util.Scanner;

public class c_628 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Buffer size to match C++ char a[100005]
        char[] a = new char[100005];
        
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            String s = sc.next();
            
            // Convert String to char array for manipulation
            // In C++, a is a char array. We fill it up to n.
            // We assume the input string fits within the buffer.
            // The string s read by sc.next() corresponds to the content of 'a' from 0 to n-1.
            // Let's copy it to our char array 'a'.
            for (int i = 0; i < n; i++) {
                a[i] = s.charAt(i);
            }
            // In C++, a[n] is set to '\0'. In Java, we don't strictly need to 
            // set a[n] to null terminator because we iterate up to n-1 (i < n).
            
            for (int i = 0; i < n; i++) {
                char c = a[i];
                // C++ logic: dir = 'z'-a[i]>=13?1:-1;
                // In Java, we use the character value directly.
                // 'z' is 122. 'a' is 97.
                // Condition: 122 - c >= 13
                int dir = (122 - c >= 13) ? 1 : -1;
                
                // C++ logic: dis = 'z'-a[i]>=13?'z'-a[i]:a[i]-'a';
                // Equivalent to: if (122 - c >= 13) dis = 122 - c; else dis = c - 97;
                int dis = (122 - c >= 13) ? (122 - c) : (c - 97);
                
                if (k > dis) {
                    k -= dis;
                    // Update character
                    // C++: a[i]=a[i]+dis*dir;
                    // Java: a[i] = (char)(a[i] + dis * dir);
                    a[i] = (char)(a[i] + dis * dir);
                } else {
                    // C++: a[i]=a[i]+k*dir; k=0; break;
                    a[i] = (char)(a[i] + k * dir);
                    k = 0;
                    break;
                }
            }
            
            if (k > 0) {
                System.out.println("-1");
            } else {
                // C++: puts(a);
                // We need to print the string formed by the array up to index n-1
                System.out.println(new String(a, 0, n));
            }
        }
        
        sc.close();
    }
}
</CODE>