Translate this C++ code to Java code. The main class name should be e_1812. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define int long long
#define pii pair<int,int>
using namespace std;
const int MOD=998244353;
const int maxn=1e6;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cout<<"114514";
    return 0;
}
/*inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}*/

Here is the plan for translating the provided C++ code to Java:

1.  **Header and Includes**: The C++ code uses `#include<bits/stdc++.h>`. This is a non-standard header that includes all standard libraries. In Java, we don't need explicit imports for basic I/O classes (`Scanner`, `System`), but we need to ensure we use standard classes available in `java.io` and `java.util` if we were doing more complex I/O. For this specific code, no imports are strictly necessary for the output logic, but we will structure it as a standard class.
2.  **Macros and Constants**:
    *   `#define int long long`: In C++, this changes the type `int` to `long long`. In Java, there is no equivalent macro. We must explicitly use `long` for variables that would have been `int` in the C++ version.
    *   `#define inf 0x3f3f3f3f`: This is a constant value. In Java, this can be a `static final` field. Note that `0x3f3f3f3f` is a 32-bit integer. Since we are using `long` (64-bit) in the Java translation for the "int" type, we should cast this to `long` or use the literal value `1061109567L` to maintain the semantic meaning of "infinity" for a `long`.
    *   `#define pii pair<int,int>`: This defines a structure. In Java, we don't need this for the current code, but if we were writing a full translation, we would define a class or use `int[]`.
3.  **Input/Output**:
    *   C++ uses `cin`, `cout`, and `ios::sync_with_stdio(false)`.
    *   Java uses `System.out` and `System.in`. The C++ optimization `ios::sync_with_stdio(false)` is not needed in Java (it's a JVM-level optimization already), but we can keep the `Scanner` logic simple.
    *   The C++ code prints `114514`. In Java, this is `System.out.println(114514);`.
4.  **Class Structure**:
    *   C++ `main` function becomes Java `main` method inside a class.
    *   The class name must be `e_1812`.
5.  **Ignored Code**:
    *   The commented-out section (`/* ... */`) regarding `__int128` is C++ specific and will be omitted as Java does not support `__int128` natively.

Here is the resulting Java code:

<CODE>
public class e_1812 {
    // Constants translated from C++ macros
    // inf was 0x3f3f3f3f in C++ (int/long long). In Java, we use long.
    // 0x3f3f3f3f is 1061109567.
    public static final long INF = 0x3f3f3f3fL;
    
    // MOD constant
    public static final int MOD = 998244353;
    
    // maxn constant
    public static final int MAXN = 1000000;

    public static void main(String[] args) {
        // C++: ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        // Java: System.out is thread-safe enough for simple tasks, 
        // and BufferedReader is faster than Scanner for large inputs, 
        // though this specific code doesn't read anything.
        
        // C++: cout << "114514";
        // Java: System.out.println(114514);
        System.out.println(114514);
        
        return;
    }
}
</CODE>