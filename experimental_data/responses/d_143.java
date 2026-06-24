Translate this C++ code to Java code. The main class name should be d_143. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<cstdio> 

#include<cstdlib>

#include<iostream>

#include<cmath> 

#include<vector> 

#include<algorithm> 

#include<map> 

#include<string> 

#include<cstring> 

using namespace std;



long long i,j,k,l,x,y,m,n,t,t1,s,e[11],a,b,c,d;

string r,p;

long long u (long long a, long long b, long long c){

   return 2*a*b+2*a*c+b*c+4*a+2*b+2*c+4;

}

int main() {

	cin >> n >>m;

	if (n ==1 || m ==1){

	   cout << n*m;

	   return 0;

	}

	if (n > m)

	   swap (n,m); 

	if ( n == 2){

	   s = m/4 *2;

	   m %= 4;

	   if (m > 2)

	      m = 2;

	   s += m;

	   cout << 2 * s;

	   return 0;

	}

	

   cout << (n*m+1)/2;

}

Here is the plan for translating the C++ code to Java:

1.  **Header Inclusions and Imports**:
    *   C++: `#include<cstdio>`, `#include<cstdlib>`, `#include<iostream>`, `#include<cmath>`, `#include<vector>`, `#include<algorithm>`, `#include<map>`, `#include<string>`, `#include<cstring>`
    *   Java: `import java.util.*;` (Covers `String`, `Scanner`, `Arrays`, `Map`, `Vector`, `List`, `ArrayList`, `Collections`). Since the C++ code uses `std::swap`, we will use `java.util.Collections.swap` or manual swapping, but for primitive `long` types, manual swapping is often more efficient or simply `long temp = n; n = m; m = temp;`.
    *   `using namespace std;` is not needed in Java as classes are explicitly imported.

2.  **Variable Declarations**:
    *   C++: Global variables are declared at the top of the file (e.g., `long long i, j...`, `string r, p`).
    *   Java: Global variables (class-level fields) must be declared inside the class `d_143`.
    *   Note: `string` in C++ is a string object, in Java it is `String`. The C++ code declares `string r, p`, but they are not used in the logic shown (only `n` and `m` are used). We will keep the declarations for structural fidelity but they are effectively unused.
    *   `long long` in C++ maps to `long` in Java (since Java doesn't have `long long`, `long` is 64-bit signed, equivalent to C++ `long long`).

3.  **Function Translation**:
    *   C++: `long long u (long long a, long long b, long long c)`
    *   Java: `long u(long a, long b, long c)`
    *   The function is defined but not called in the `main` method. We will keep the method definition for structural fidelity.

4.  **Main Method**:
    *   C++: `int main() { ... }`
    *   Java: `public static void main(String[] args) { ... }`
    *   Input/Output: `cin`/`cout` will be replaced by `Scanner` and `System.out.println`.

5.  **Incremental Tasks**:
    *   Step 1: Set up the class structure and imports.
    *   Step 2: Translate global variables and helper function `u`.
    *   Step 3: Translate the `main` logic (Input reading, condition checks, output).

Here is the resulting Java code:

<CODE>
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class d_143 {

    // Global variables corresponding to C++ declarations
    // long long maps to long in Java
    long i, j, k, l, x, y, m, n, t, t1, s;
    long[] e = new long[11];
    String r, p;

    // Helper function u
    // C++: long long u (long long a, long long b, long long c)
    // Java: long u(long a, long b, long c)
    // Note: In Java, return type must match. Since the logic returns a long value, 
    // we use long. C++ long long is 64-bit, Java long is 64-bit.
    public static long u(long a, long b, long c) {
        return 2*a*b + 2*a*c + b*c + 4*a + 2*b + 2*c + 4;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read n and m
        // C++: cin >> n >> m;
        if (sc.hasNextLong()) {
            n = sc.nextLong();
            m = sc.nextLong();
        } else {
            return;
        }

        // Logic translation
        
        // if (n ==1 || m ==1){
        if (n == 1 || m == 1) {
            // cout << n*m;
            System.out.println(n * m);
            // return 0;
            return;
        }

        // if (n > m) swap (n,m);
        if (n > m) {
            long temp = n;
            n = m;
            m = temp;
        }

        // if ( n == 2){
        if (n == 2) {
            // s = m/4 *2;
            s = (m / 4) * 2;
            // m %= 4;
            m = m % 4;
            // if (m > 2) m = 2;
            if (m > 2) {
                m = 2;
            }
            // s += m;
            s += m;
            // cout << 2 * s;
            System.out.println(2 * s);
            // return 0;
            return;
        }

        // cout << (n*m+1)/2;
        System.out.println((n * m + 1) / 2);
    }
}
</CODE>