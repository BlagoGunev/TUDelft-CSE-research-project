Translate this C++ code to Java code. The main class name should be c_1793. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <set>
#include <numeric>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int minx = INT_MAX, maxx = 0;
    for( int i = 0 ; i < n ; i++ )
    {
        cin>>a[i];
        minx = min(minx, a[i]);
        maxx = max(maxx, a[i]);
    }
    int l = 0, r = n-1;
    int ans = 0;
    while( l < r )
    {
        if( a[l] != maxx && a[l] != minx && a[r] != minx && a[r] != maxx )
        {
            ans = 1;
            break;
        }
        if( a[l] == maxx )
            maxx--, l++;
        else if( a[r] == maxx )
            maxx--, r--;
        if( a[l] == minx )
            minx++, l++;
        else if( a[r] == minx )
            minx++, r--;
    }
    if( ans )
        cout<<l+1<<" "<<r+1<<"\n";
    else
        cout<<"-1\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Includes and Namespace**: C++ uses `#include` and `using namespace std;`. Java does not have this. We need to import specific classes: `java.util.Scanner` (or `BufferedReader`/`StringTokenizer` for efficiency) and `java.lang.Math`.
2.  **Main Class**: The C++ code has no class definition, just a `main` function. In Java, we need a `public class c_1793` containing the `main` method.
3.  **Variable Types**: C++ uses `int`. Java uses `int` for standard integers.
4.  **Dynamic Arrays**: C++ allows `int a[n]` (VLA) inside functions. Java does not support this syntax. We must use `int[] a = new int[n];`.
5.  **Constants**: C++ uses `INT_MAX` from `<climits>`. Java uses `Integer.MAX_VALUE`.
6.  **I/O Optimization**: The C++ code uses `ios_base::sync_with_stdio(false); cin.tie(NULL);` which suggests performance optimization is desired. While `Scanner` is easier to write, `BufferedReader` and `StringTokenizer` are preferred in Java for competitive programming to match the speed of the C++ I/O. I will use `BufferedReader` and `StringTokenizer` to handle the input parsing efficiently.
7.  **Logic Translation**:
    *   `min`, `max`: Use `Math.min()` and `Math.max()`.
    *   `cin >>`: Use `StringTokenizer` or `Scanner`.
    *   `cout <<`: Use `PrintWriter` or `System.out.print`.
    *   `return`: The `return 0;` in `main` is implicit in Java, but the `return;` in `void solve()` is valid.
    *   **Constraints**: The problem implies $N$ can be up to $10^5$ (based on the optimization logic). The C++ code uses `int` for `ans`, `l`, `r`, `minx`, `maxx`. This is safe for typical competitive programming constraints where the answer fits in a standard integer.

**Incremental Steps**:
1.  Define the class structure.
2.  Implement the `main` method with `BufferedReader`.
3.  Implement the `solve` method logic (reading array, finding min/max, two-pointer approach).
4.  Handle the output logic.

Here is the Java code:

<CODE>
import java.io.*;
import java.util.*;

public class c_1793 {
    
    static int[] a;
    static int n;
    static int minx;
    static int maxx;
    
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        
        try {
            String s = sc.next();
            if (s == null) return;
            int t = Integer.parseInt(s);
            
            while (t-- > 0) {
                n = sc.nextInt();
                a = new int[n];
                minx = Integer.MAX_VALUE;
                maxx = 0;
                
                for (int i = 0; i < n; i++) {
                    a[i] = sc.nextInt();
                    minx = Math.min(minx, a[i]);
                    maxx = Math.max(maxx, a[i]);
                }
                
                int l = 0;
                int r = n - 1;
                int ans = 0;
                
                while (l < r) {
                    if (a[l] != maxx && a[l] != minx && a[r] != minx && a[r] != maxx) {
                        ans = 1;
                        break;
                    }
                    if (a[l] == maxx) {
                        maxx--;
                        l++;
                    } else if (a[r] == maxx) {
                        maxx--;
                        r--;
                    }
                    if (a[l] == minx) {
                        minx++;
                        l++;
                    } else if (a[r] == minx) {
                        minx++;
                        r--;
                    }
                }
                
                if (ans == 1) {
                    out.println(l + 1 + " " + (r + 1));
                } else {
                    out.println("-1");
                }
            }
        } catch (Exception e) {
            // Handle potential exceptions silently or log them
        }
        
        out.flush();
    }
    
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                    return null;
                }
            }
            return st.nextToken();
        }
        
        int nextInt() {
            String s = next();
            if (s == null) return 0;
            return Integer.parseInt(s);
        }
    }
}
</CODE>