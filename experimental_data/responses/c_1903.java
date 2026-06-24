Translate this C++ code to Java code. The main class name should be c_1903. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=100005;
int n;
LL a[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void solve()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	repd(i,n-1,1) a[i]+=a[i+1];
	LL ans=a[1];
	rep(i,2,n) if(a[i]>0) ans+=a[i];
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**:
    *   Replace `#include<bits/stdc++.h>` with specific standard library headers (`iostream`, `vector`, `numeric`, `algorithm`) to adhere to Java standards.
    *   Remove `using namespace std;` as Java requires fully qualified class names or explicit imports.

2.  **Macros and Loops**:
    *   Remove C++ preprocessor macros (`#define rep`, `#define repd`).
    *   Replace `rep(i, x, y)` with a standard `for` loop: `for (int i = x; i <= y; i++)`.
    *   Replace `repd(i, x, y)` with a standard `for` loop: `for (int i = x; i >= y; i--)`.

3.  **Data Types**:
    *   Replace `int` with `int` (Java `int` is 32-bit, same as C++ `int`).
    *   Replace `LL` (`long long`) with `long` (Java `long` is 64-bit, equivalent to C++ `long long`).
    *   Update array size constant `N` to fit Java array indexing (1-based indexing logic will be preserved but adjusted for 0-based arrays internally or mapped explicitly).

4.  **Input/Output**:
    *   Replace `getint()` and `printf()` with `Scanner` class from `java.util`.
    *   Remove the manual character-by-character parsing logic in `getint()` and use `scanner.nextInt()`.
    *   Replace `printf("%lld\n", ans)` with `System.out.println(ans)`.

5.  **Main Class Structure**:
    *   Create a public class named `c_1903` with a `main` method.
    *   Move the `solve()` logic into a method (e.g., `solve()`) called within the main loop.
    *   Handle the test case count `T` by reading it and looping.

6.  **Incremental Tasks**:
    *   Step 1: Setup class structure and imports.
    *   Step 2: Implement input reading (`getint` -> `Scanner`).
    *   Step 3: Implement the array storage and prefix sum logic.
    *   Step 4: Implement the calculation logic and output.
    *   Step 5: Integrate into `main` and finalize.

### Java Code

<CODE>
import java.util.Scanner;

public class c_1903 {
    
    static final int N = 100005;
    static int n;
    static long[] a = new long[N];
    static Scanner scanner = new Scanner(System.in);

    static int getint() {
        // In Java, we rely on Scanner.nextInt() for simplicity instead of manual char parsing
        return scanner.nextInt();
    }

    static void solve() {
        n = getint();
        for (int i = 1; i <= n; i++) {
            a[i] = getint();
        }

        // Repd: for(int i=n-1; i>=1; --i)
        for (int i = n - 1; i >= 1; i--) {
            a[i] += a[i + 1];
        }

        long ans = a[1];
        for (int i = 2; i <= n; i++) {
            if (a[i] > 0) {
                ans += a[i];
            }
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        int T = getint();
        while (T-- > 0) {
            solve();
        }
    }
}
</CODE>