Translate this C++ code to Java code. The main class name should be e_1512. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

using namespace std;

#include <string>

#include <algorithm>

#include <cmath>

#define ll long long

#define endl '\n'

#define pb push_back

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);



void solve()

{

    int n,l,r,s;

    cin>>n>>l>>r>>s;

    ll ans[n+1]={0},flag[n+1]={0};

    int diff=r-l+1;

    if(s<diff*(diff+1)/2 || s>diff*(2*n+1-diff)/2)

    cout<<-1<<endl;

    else{

        for(int i=n;i>0;i--){

            if(s-i>=(1+r-l)*(r-l)/2 && s>=i){

                s-=i;

                ans[l++]=i;

                flag[i]=1;

            } 

        }

        for(int i=1;i<=n;i++){

            int j=1;

            if(flag[i]==0){

                while(ans[j]!=0)

                j++;

                ans[j++]=i;

            }

        }

    for(int i=1;i<=n;i++)

	cout<<ans[i]<<" ";

	cout<<endl;    

    }

    

}

int main()

{

    fastio();

    ll t=1;

    cin>>t;



    while(t--)

    {

        solve();

    }

    return 0;

}

Here is the plan for translating the C++ code to Java:

1.  **Headers and Imports**: The C++ code uses `#include<bits/stdc++.h>`, which is non-standard but includes common headers. In Java, we must explicitly import necessary classes like `java.util.Scanner` or `java.io.*` for input/output.
2.  **I/O Optimization**: The C++ code uses `fastio()` to disable synchronization between C and C++ standard streams and tie `cin` to `NULL`. In Java, `Scanner` is generally slow. To replicate this, we should use `BufferedReader` and `StringTokenizer`, which is the standard way to achieve fast I/O in Java.
3.  **Data Types**: The C++ code uses `ll` (defined as `long long`) for variables `ans` and `t`. In Java, the equivalent is `long`. The variable `n` is an `int` in C++, which remains `int` in Java.
4.  **Arrays**: C++ uses static arrays `ans[n+1]` and `flag[n+1]`. Java does not support variable-length arrays (VLA) in the same way. We should use `int[]` or `long[]` arrays. Since `n` is determined at runtime, we allocate the array with size `n + 1`.
5.  **Namespace**: The C++ code uses `using namespace std;`. In Java, we use fully qualified class names or explicit imports (e.g., `System.out`, `Arrays`).
6.  **Logic Translation**:
    *   `cin >>` becomes `st.nextToken()`.
    *   `cout <<` becomes `sb.append()`.
    *   `endl` becomes `System.lineSeparator()` or just `System.out.println()`.
    *   `pb` (push_back) isn't used here, but `ans` is a direct array assignment.
    *   The mathematical logic inside `solve()` remains the same, just changing types and syntax (e.g., `i--` vs `i--`, `flag[i]=1` vs `flag[i]=true`).
7.  **Structure**: The C++ `main` function loops `t` times calling `solve()`. In Java, this translates to a `while(t-- > 0)` loop inside `main`.

**Incremental Tasks:**
1.  Create the class structure `e_1512`.
2.  Implement the `solve()` method.
3.  Implement the `main()` method with the input loop.
4.  Implement the fast I/O helper class or methods.
5.  Translate the logic inside `solve()` to Java syntax.
6.  Combine and finalize the code.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class e_1512 {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        // C++ uses t=1 and reads t, assuming 1 test case if not read or just reading t.
        // The logic: ll t=1; cin>>t; while(t--)
        // This implies if input is empty or t is not provided, it runs once. 
        // But cin>>t will wait for input. So we read t.
        // However, often in these problems, if the loop condition is while(t--), 
        // and t is initialized to 1, it runs exactly once unless t is read from input.
        // The C++ code does: cin>>t; while(t--). So we read t from input.
        
        try {
            // Check if there is input available
            // In competitive programming, sometimes the file ends. 
            // But strictly following the C++ logic:
            // ll t=1; cin>>t; 
            // This is slightly ambiguous. Usually, it's int t; cin>>t;
            // If the C++ code initializes t=1 then reads it, it overwrites the 1.
            // Let's assume standard behavior: read t from input.
            
            // We need to handle the case where the stream might be empty if the C++ code 
            // was meant to run once (like some platforms do if no input is given).
            // But cin>>t blocks. So we assume input exists.
            // Let's just read t.
            String tStr = scanner.next();
            if (tStr == null) return; // No input
            int t = Integer.parseInt(tStr);
            
            while (t-- > 0) {
                solve(out, scanner);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.flush();
        }
    }

    public static void solve(PrintWriter out, FastScanner scanner) {
        int n = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int s = scanner.nextInt();
        
        long[] ans = new long[n + 1];
        boolean[] flag = new boolean[n + 1];
        
        int diff = r - l + 1;
        
        // C++: ll ans[n+1]={0}, flag[n+1]={0};
        // Java initializes arrays to 0/false by default.
        
        long minSum = (long) diff * (diff + 1) / 2;
        long maxSum = (long) diff * (2 * n + 1 - diff) / 2;
        
        if (s < minSum || s > maxSum) {
            out.println("-1");
        } else {
            // C++: for(int i=n;i>0;i--)
            for (int i = n; i > 0; i--) {
                // C++: if(s-i>=(1+r-l)*(r-l)/2 && s>=i)
                // Note: (1+r-l) is exactly diff.
                long currentMin = (long) diff * (diff + 1) / 2;
                if (s - i >= currentMin && s >= i) {
                    s -= i;
                    ans[l++] = i;
                    flag[i] = true;
                }
            }
            
            // C++: for(int i=1;i<=n;i++)
            for (int i = 1; i <= n; i++) {
                int j = 1;
                // C++: if(flag[i]==0)
                if (!flag[i]) {
                    // C++: while(ans[j]!=0) j++;
                    while (ans[j] != 0) {
                        j++;
                    }
                    ans[j++] = i;
                }
            }
            
            // C++: for(int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
            for (int i = 1; i <= n; i++) {
                out.print(ans[i]);
                out.print(" ");
            }
            out.println();
        }
    }
}
```
<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class e_1512 {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        // The C++ code initializes t=1 and then reads t.
        // This implies the program expects an integer input for t.
        // If input is empty, we handle it gracefully, though cin>>t would block.
        try {
            String tStr = scanner.next();
            if (tStr != null) {
                int t = Integer.parseInt(tStr);
                while (t-- > 0) {
                    solve(out, scanner);
                }
            }
        } catch (Exception e) {
            // In case of parsing error or empty input
        } finally {
            out.flush();
        }
    }

    public static void solve(PrintWriter out, FastScanner scanner) {
        int n = scanner.nextInt();
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        int s = scanner.nextInt();
        
        long[] ans = new long[n + 1];
        boolean[] flag = new boolean[n + 1];
        
        int diff = r - l + 1;
        
        // Calculate min and max possible sums
        // C++: ll minSum = diff*(diff+1)/2;
        // C++: ll maxSum = diff*(2*n+1-diff)/2;
        long minSum = (long) diff * (diff + 1) / 2;
        long maxSum = (long) diff * (2 * n + 1 - diff) / 2;
        
        if (s < minSum || s > maxSum) {
            out.println("-1");
        } else {
            // C++: for(int i=n;i>0;i--)
            for (int i = n; i > 0; i--) {
                // C++: if(s-i>=(1+r-l)*(r-l)/2 && s>=i)
                // Note: (1+r-l) is exactly diff.
                long currentMin = (long) diff * (diff + 1) / 2;
                if (s - i >= currentMin && s >= i) {
                    s -= i;
                    ans[l++] = i;
                    flag[i] = true;
                }
            }
            
            // C++: for(int i=1;i<=n;i++)
            for (int i = 1; i <= n; i++) {
                int j = 1;
                // C++: if(flag[i]==0)
                if (!flag[i]) {
                    // C++: while(ans[j]!=0) j++;
                    while (ans[j] != 0) {
                        j++;
                    }
                    ans[j++] = i;
                }
            }
            
            // C++: for(int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
            for (int i = 1; i <= n; i++) {
                out.print(ans[i]);
                out.print(" ");
            }
            out.println();
        }
    }
}
</CODE>