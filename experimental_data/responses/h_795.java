Translate this C++ code to Java code. The main class name should be h_795. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
/* Eat a live frog first thing in the morning,
   and nothing worse will happen to you the rest of the day */

/* You can't connect the dots looking forward
   you can only connect them looking backwards. */

/* Nothing is impossible; impossible itself says "I'm possible" */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed;
#define dbset(x) for(int i=0 ; i<x.size(); i++) cerr << x[i] << " "; cerr << endl;
#define dbg(x,y) cerr << x << " " << y << endl;
#define db(x) cerr << x << endl;
#define inf 1000000007
#define INF 1000000000000000000LL
#define PI 3.14159265358979323846
#define mod 1000000007
#define mod1 1000696969
#define flusz fflush(stdout);
#define VI vector<int>
#define VPI vector < pair<int,int> >
#define PII pair<int, int>
#define BIT bitset<N>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;

#define N 500007

int test;

int t[N];

int n;

int cur;

string res;

void solve()
{
    cin >> n;

    FOR(i,1,n)
    {
        cin >> t[i];
    }

    FORR(i,n,1)
    {
        while(t[i])
        {
            cur++;
            cur%=5;

            int lel=i;

            while(lel--)
                res+=(char)('a'+cur);

            FOR(j,1,i)
            {
                t[j]-=i-j+1;
            }
        }
    }

    cout << res;

    return;
}

int32_t main()
{
    boost

    test=1;

    while(test--)
        solve();

    return 0;
}

Here is the translation plan:

1.  **Includes and Namespaces**: Replace `#include<bits/stdc++.h>` with specific headers (`iostream`, `string`, `vector`, `iomanip`, `vector`, `algorithm`) and use `using namespace std;`.
2.  **Macros**: Convert C++ specific macros to Java logic or standard constants.
    *   `long long` / `unsigned long long`: Use `long` (64-bit) in Java.
    *   `fixed`, `precision`: Use `System.out.printf` or `DecimalFormat`.
    *   `vector<int>`, `pair<int,int>`: Use `ArrayList<Integer>` or custom classes.
    *   `for` loops (`FOR`, `FORR`): Convert to standard Java `for` loops.
    *   `cin >>`: Use `Scanner` or `BufferedReader`.
    *   `cout <<`: Use `System.out.print` or `PrintWriter`.
    *   `#define N 500007`: This is a constant.
3.  **Main Class**: Create class `h_795` with a `main` method.
4.  **Logic Conversion**:
    *   The C++ code uses `t` as a global array (`int t[N]`). In Java, we should declare this as a static array or pass it to the `solve` method. Given the fixed size `N`, a static array is efficient and matches the C++ structure.
    *   The `solve` function logic is almost identical to C++, just replacing `++x` with `x++` (post-increment logic is same, but Java doesn't have pre/post in the same macro context easily, so standard loops are better) and ensuring array bounds are respected (Java arrays are 0-indexed, C++ is 1-indexed here).
    *   The C++ loop `FORR(x, y, z)` iterates backwards. In Java, this is `for(int x = y; x >= z; x--)`.
    *   The `while` loop condition `while(t[i])` checks if `t[i] > 0`.
    *   The string concatenation `res+=...` works in Java but can be slow for large strings. Since `N` is up to 500,000, `StringBuilder` is preferred over string concatenation in a loop.
    *   The `boost` macro disables sync with stdio. In Java, we don't strictly need this, but we should use `BufferedReader` and `PrintWriter` for speed.

Here is the translated code:

<CODE>
import java.io.*;
import java.util.*;

public class h_795 {
    static int[] t = new int[500007];
    static int test = 1;
    static int n;
    static int cur;
    static StringBuilder res = new StringBuilder();

    public static void main(String[] args) {
        // boost equivalent: fast I/O
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(System.out);
            
            // Read number of test cases
            String line = br.readLine();
            if (line == null || line.trim().isEmpty()) return;
            test = Integer.parseInt(line.trim());
            
            while (test-- > 0) {
                solve(br, out);
            }
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void solve(BufferedReader br, PrintWriter out) throws IOException {
        // Read n
        String line = br.readLine();
        while (line != null && line.trim().isEmpty()) {
            line = br.readLine();
        }
        if (line == null) return;
        
        n = Integer.parseInt(line.trim());

        // Read array t
        // The C++ code uses 1-based indexing. 
        // We will read n integers.
        StringTokenizer st = new StringTokenizer("");
        
        for (int i = 1; i <= n; i++) {
            while (!st.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) break;
                st = new StringTokenizer(s);
            }
            if (st.hasMoreTokens()) {
                t[i] = Integer.parseInt(st.nextToken());
            }
        }

        // Logic translation
        // C++: FORR(i,n,1) -> Java: for(int i = n; i >= 1; i--)
        for (int i = n; i >= 1; i--) {
            while (t[i] > 0) {
                cur++;
                cur %= 5;

                // C++: res+=(char)('a'+cur); inside a loop
                // Java: StringBuilder append
                // C++: while(lel--) res+=...
                // Java: for(int j=0; j<i; j++) res.append...
                
                for (int j = 0; j < i; j++) {
                    res.append((char)('a' + cur));
                }

                // C++: FOR(j,1,i) t[j]-=i-j+1;
                // Java: for(int j = 1; j <= i; j++) t[j]-=(i-j+1);
                for (int j = 1; j <= i; j++) {
                    t[j] -= (i - j + 1);
                }
            }
        }

        // Output result
        out.print(res.toString());
        out.println();
    }
}
</CODE>