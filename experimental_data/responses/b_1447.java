Translate this C++ code to Java code. The main class name should be b_1447. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

#define int long long

using namespace std;



void solve()

{

    int a,b;

    cin>>a>>b;

    int arr[a][b];

    for (int i=0;i<a;i++) for (int j=0;j<b;j++) cin>>arr[i][j];

    int sum=0, neg=0;int m=INT_MAX;

    for (int i=0;i<a;i++)

    {

        for (int j=0;j<b;j++)

        {

            if (arr[i][j]<0)

            {

                neg++;

                arr[i][j]*=-1;

            }

            sum+=arr[i][j];

            m=min(m,arr[i][j]);

        }

    }

    if (neg%2==0) cout<<sum<<endl;

    else cout<<sum-2*m<<endl;

}



int32_t main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int T;

    cin>>T;

    while(T--)

    {

        solve();

    }

    return 0;

}

Here is the translation plan and the resulting Java code.

### Translation Plan

1.  **Header and Imports**:
    *   C++: `#include<bits/stdc++.h>` and `using namespace std;`
    *   Java: Replace with `import java.util.*;` and `import java.io.*;`. Since the C++ code uses fast I/O (`ios_base::sync_with_stdio(false); cin.tie(NULL);`), we will use `BufferedReader` and `StringTokenizer` in Java to ensure efficiency, rather than `Scanner`.

2.  **Data Types**:
    *   C++: `#define int long long` changes all `int` variables to `long long`.
    *   Java: The default `int` is 32-bit, which might overflow if the inputs are large. We will use `long` (64-bit) for variables `a`, `b`, `arr`, `sum`, and `m` to match the C++ logic.

3.  **Class Structure**:
    *   C++: Single function `solve()` called inside `main()`.
    *   Java: Java requires a `main` method inside a `public class`. We will create a `main` method that reads the test case count `T` and calls a `solve()` method for each iteration.

4.  **2D Array Handling**:
    *   C++: `int arr[a][b]` creates a dynamic array on the stack (VLA) based on runtime values `a` and `b`.
    *   Java: Java does not support Variable Length Arrays (VLAs). We must use `long[][] arr = new long[a][b]`.

5.  **Input/Output**:
    *   C++: `cin >>` and `cout <<`.
    *   Java: `br.read()` and `br.readLine()` with `StringTokenizer` for input parsing, and `System.out.println()` for output.

6.  **Logic Implementation**:
    *   The logic inside `solve()` (calculating sum, counting negatives, and adjusting the minimum negative value) remains identical in structure, just adapting the syntax and types.

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class b_1447 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(next());
        while (T-- > 0) {
            solve();
        }
    }

    static long next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return Long.parseLong(st.nextToken());
    }

    static String nextString() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static void solve() throws IOException {
        long a = next();
        long b = next();
        
        long[][] arr = new long[(int)a][(int)b];
        
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                arr[i][j] = next();
            }
        }

        long sum = 0;
        int neg = 0;
        long m = Long.MAX_VALUE;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (arr[i][j] < 0) {
                    neg++;
                    arr[i][j] = -arr[i][j]; // Make positive
                }
                sum += arr[i][j];
                m = Math.min(m, arr[i][j]);
            }
        }

        if (neg % 2 == 0) {
            System.out.println(sum);
        } else {
            System.out.println(sum - 2 * m);
        }
    }
}
</CODE>