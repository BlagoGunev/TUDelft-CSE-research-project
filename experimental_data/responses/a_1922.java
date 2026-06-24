Translate this C++ code to Java code. The main class name should be a_1922. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
#define F first ;
#define S  second;
#define endl '\n' ;

void Fast(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
}

void solve(){
    /* تعزُّ عليَّ فِلسطين، تعزُّ عليَّ أحزانُها  بسم الله على فِلسطين حتى يطمَئن فؤادُها */
    int n;
    cin>>n;
    string a, b, c;
    cin>>a>>b>>c;
    for (int i=0;i<n;i++){
        if (a[i] != c[i] && b[i] != c[i]){
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}
int main (){
    Fast();
    int t=1;
    cin>>t;
    while(t--){
       solve();
       if(t!=0) cout<<endl;
    }
}

Here is the plan for translating the C++ code to Java:

1.  **Header and Imports**:
    *   C++: `#include <bits/stdc++.h>` and `using namespace std;`
    *   Java: Replace with `import java.util.*;` and `import java.io.*;` (for fast I/O).
    *   `typedef long long ll;`: Java does not have a direct typedef, but we can use `long` for 64-bit integers.
    *   Macros (`#define`): Convert macros like `F`, `S`, `endl` into Java constants or inline logic. `endl` in Java usually becomes `System.out.println()` or `"\n"`.

2.  **Fast I/O**:
    *   C++: Uses `cin.tie(0)`, `sync_with_stdio(0)`, `cout.tie(0)`.
    *   Java: Implement a custom `FastReader` class using `BufferedReader` and `StringTokenizer` to handle large inputs efficiently, as Java's `Scanner` is slow.

3.  **Logic (`solve` function)**:
    *   C++: `cin >> n`, `string a, b, c`, loop, `cout`.
    *   Java: Use `nextLong()` or `nextInt()` for `n`. Use `next()` for strings. Loop using `for` and `charAt`. Use `System.out.print` or `PrintWriter` for output.
    *   The Arabic comment block in C++ will be preserved as a comment in Java.

4.  **Main Method**:
    *   C++: `main` calls `Fast()` then `solve()` inside a loop.
    *   Java: `main` creates a `FastReader` instance, reads `t`, loops `t` times calling `solve`.

5.  **Incremental Task Splitting**:
    *   Step 1: Define the `FastReader` class.
    *   Step 2: Create the class structure and imports.
    *   Step 3: Implement the `solve` method logic.
    *   Step 4: Implement the `main` method.
    *   Step 5: Integrate and test logic.

Here is the resulting Java code:

<CODE>
import java.util.*;
import java.io.*;

public class a_1922 {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void solve() {
        /* تعزُّ عليَّ فِلسطين، تعزُّ عليَّ أحزانُها  بسم الله على فِلسطين حتى يطمَئن فؤادُها */
        int n = reader.nextInt();
        String a = reader.next();
        String b = reader.next();
        String c = reader.next();

        boolean found = false;
        for (int i = 0; i < n; i++) {
            if (a.charAt(i) != c.charAt(i) && b.charAt(i) != c.charAt(i)) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        int t = reader.nextInt();
        while (t-- > 0) {
            solve();
            if (t > 0) {
                System.out.println();
            }
        }
    }
}
</CODE>