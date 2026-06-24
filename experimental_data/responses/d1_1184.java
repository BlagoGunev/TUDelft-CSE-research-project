Translate this C++ code to Java code. The main class name should be d1_1184. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
 #define mod 1000000007
 const int N=100005;
 const int inf=1e18;
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n,k,m,t;
	cin>>n>>k>>m>>t;
	int cc=n;
	int cp=k;
	while(t--){
		int b;
		cin>>b;
		int i;
		cin>>i;
		if(b==1){
			if(cp<i){
				cc++;
			}else{
				cp++;
				cc++;
				if(cc>m){
					cc=m;
				}
			}
		}else{
			if(cp<=i){
				cc=i;
			}else{
				cp=cp-i;
				cc=cc-i;
			}
		}
		cout<<cc<<" "<<cp<<"\n";
	}
	







	
	
return 0;	
}

Here is the plan for translating the C++ code to Java:

1.  **Headers and Imports**:
    *   `#include <bits/stdc++.h>` is a catch-all header in C++. In Java, we need specific imports for I/O operations (`java.util.Scanner`) and potentially others, though the logic here uses standard `Scanner`.
    *   `using namespace std;` is specific to C++. In Java, we use classes and fully qualified names or imports. We will use `Scanner` from `java.util`.

2.  **Data Types and Constants**:
    *   `#define int long long`: This forces all integer variables to be `long long` (64-bit) in C++. In Java, `int` is 32-bit and `long` is 64-bit. We must replace every instance of `int` with `long` to match the C++ logic.
    *   `const int N=100005;`: This is a constant used for array sizing in C++. Since the provided code does not actually use an array, we can ignore this constant in the Java translation.
    *   `const int inf=1e18;`: This is a constant used for infinity. Since we are replacing `int` with `long`, this should be `1000000000000000000L`.
    *   `#define mod 1000000007`: This constant is defined but not used in the provided snippet. We can ignore it.

3.  **Main Class Structure**:
    *   C++: `signed main()` -> Java: `public static void main(String[] args)`.
    *   Class name: `d1_1184`.

4.  **I/O Optimization**:
    *   C++: `ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);`.
    *   Java: `Scanner` is generally slower than C++'s `cin`/`cout` optimization, but since the logic is simple, we don't strictly need a custom `FastReader` class for this specific snippet, but we should ensure standard `Scanner` usage is efficient enough. Given the constraints implied by `long long` (up to $10^{18}$), standard `Scanner` is usually acceptable for moderate inputs, but for competitive programming, `BufferedReader` + `StringTokenizer` is preferred. However, to keep the translation direct and simple without adding boilerplate unless necessary, `Scanner` is the direct equivalent of `cin`/`cout`. I will use `Scanner` for simplicity and readability, matching the high-level logic.

5.  **Logic Translation**:
    *   `cin >> var` -> `sc.nextLong()` (since `var` is `long`).
    *   `cout << var` -> `System.out.println(var)`.
    *   `while(t--)` -> `while(t > 0) { t--; }`.
    *   `if/else` blocks remain similar, but variable types change from `int` to `long`.

6.  **Incremental Tasks**:
    *   Step 1: Define class and imports.
    *   Step 2: Translate variable declarations (`n`, `k`, `m`, `t`, `cc`, `cp`, `b`, `i`).
    *   Step 3: Translate the input reading logic.
    *   Step 4: Translate the `while` loop and conditional logic inside.
    *   Step 5: Translate output and return.

7.  **Specific Considerations**:
    *   The C++ code uses `signed main()`. Java `main` must be `public static void`.
    *   The constant `mod` is unused, so it won't be included.
    *   The constant `N` is unused, so it won't be included.

8.  **Final Code Construction**:
    *   Class `d1_1184`.
    *   Variables `n`, `k`, `m`, `t` as `long`.
    *   Variables `cc`, `cp`, `b`, `i` as `long`.
    *   Logic preserved exactly.

```java
import java.util.Scanner;

public class d1_1184 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // In C++, 'int' is redefined as 'long long'. In Java, we use 'long'.
        long n = sc.nextLong();
        long k = sc.nextLong();
        long m = sc.nextLong();
        long t = sc.nextLong();
        
        long cc = n;
        long cp = k;
        
        while (t > 0) {
            long b = sc.nextLong();
            long i = sc.nextLong();
            
            if (b == 1) {
                if (cp < i) {
                    cc++;
                } else {
                    cp++;
                    cc++;
                    if (cc > m) {
                        cc = m;
                    }
                }
            } else {
                if (cp <= i) {
                    cc = i;
                } else {
                    cp = cp - i;
                    cc = cc - i;
                }
            }
            System.out.println(cc + " " + cp);
            t--;
        }
    }
}
```
<CODE>
import java.util.Scanner;

public class d1_1184 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // In C++, 'int' is redefined as 'long long'. In Java, we use 'long'.
        long n = sc.nextLong();
        long k = sc.nextLong();
        long m = sc.nextLong();
        long t = sc.nextLong();
        
        long cc = n;
        long cp = k;
        
        while (t > 0) {
            long b = sc.nextLong();
            long i = sc.nextLong();
            
            if (b == 1) {
                if (cp < i) {
                    cc++;
                } else {
                    cp++;
                    cc++;
                    if (cc > m) {
                        cc = m;
                    }
                }
            } else {
                if (cp <= i) {
                    cc = i;
                } else {
                    cp = cp - i;
                    cc = cc - i;
                }
            }
            System.out.println(cc + " " + cp);
            t--;
        }
    }
}
</CODE>