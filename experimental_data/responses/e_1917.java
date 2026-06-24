Translate this C++ code to Java code. The main class name should be e_1917. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
/*input
5
4 0
18 162
6 5
2 2
6 36

*/
 
 
#include <bits/stdc++.h>
#define ll long long int
#define vi vector< ll >
#define pi pair< ll, ll > 
#define mset(A,v,n) memset((A),(v),(n)*sizeof((A)[0]) ) 
#define FORi(n) for(ll i=0;i<(n);i++)
#define FORj(n) for(ll j=0;j<(n);j++)
#define FORk(n) for(ll k=0;k<(n);k++)
#define pb push_back
#define inp(A) FORi( (A).size() )cin>>((A)[i]);
#define inp2(n,m) scanf("%⁄lld%lld",&(n),&(m));
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define mp(a,b) make_pair((a),(b))
#define INT_SIZE 60
 
 
#define MAXN  100010
#define mod 1000000007    
#define level  22
using namespace std;
 
#define n_l '\n'
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); }  template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); } 
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
 
void print(vi v){FORi(v.size())cout<<v[i]<<" ";cout<<endl;}
void print(deque<int> v){FORi(v.size())cout<<v[i]<<" ";cout<<endl;}
void print(vi v,int n){FORi(n)cout<<v[i]<<" ";cout<<endl;}
ll pm(ll x,ll y){ll res = 1;while(y>0){if(y&1) res = (res*x)%mod;x= (x*x)%mod;y/=2;}return res;}
ll gcd(ll a, ll b){if(b==0)return a;if(a==0) return b; return gcd(b,a%b);}
 



 
void solve(){
    
    ll n,d,k;
    cin>>n>>k;

    ll M[n][n];

    if(n == 2 && k == 2){
        cout<<"Yes\n1 0\n0 1\n";
        return;
    }
    
    FORi(n)FORj(n)M[i][j] = 0;

    ll inv = 0;
    if(k > n*n/2){
        inv = 1;
        k = n*n - k;
    }

    if(k&1){
        cout<<"No\n";
        return;
    }

    if(k%4 == 2){

        if(k == 2 || n < 3){
            cout<<"No\n";
            return;
        }

        M[n-1][n-3] = 1;
        M[n-1][n-2] = 1;
        M[n-2][n-3] = 1;
        M[n-2][n-1] = 1;
        M[n-3][n-1] = 1;
        M[n-3][n-2] = 1;

        k -= 6;
    }


    for(int j = 0;j<n-2;j+=2){
        if(k == 0)break;
        for(int i = 0;i<n;i+=2){
            if(k == 0 )break;

            M[i][j] = 1;
            M[i+1][j] = 1;
            M[i][j+1] = 1;
            M[i+1][j+1] = 1;

            k -= 4;
        }
    }

    cout<<"Yes\n";
    FORi(n){
        FORj(n){
            cout<< (M[i][j]^inv )<<" ";
        }
        cout<<"\n";
    }

 
    
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // pre();
 
    int t;cin>>t;FORi(t)
        solve();
    return 0;
 
}

Here is the plan for translating the C++ code to Java:

1.  **Headers and Imports**: Replace C++ specific headers (`#include <bits/stdc++.h>`) with necessary Java imports (`java.util.*`, `java.io.*`).
2.  **Data Types**:
    *   `long long` in C++ maps to `long` in Java.
    *   `int` maps to `int`.
3.  **Input/Output**:
    *   C++ uses `cin` and `cout`. Java uses `Scanner` or `BufferedReader` and `PrintWriter`/`System.out`. Given the constraints implied by competitive programming (fast I/O), `BufferedReader` and `StringTokenizer` are preferred over `Scanner` to avoid Time Limit Exceeded (TLE).
    *   The code uses `scanf` in a macro (`inp2`), but since the actual usage is via `cin`, we will stick to the `BufferedReader` approach.
4.  **Templates and Macros**:
    *   The C++ code uses extensive macros (`#define`) for loops, vectors (`vi`), pairs (`pi`), and debugging (`dbgm`). In Java, we cannot use macros. We must implement these as helper methods or classes.
    *   `vector<ll>` becomes `ArrayList<Long>`.
    *   `memset` becomes `Arrays.fill`.
    *   `pair` logic is manual (using a class or two variables).
5.  **Specific Logic Translation**:
    *   `solve()` function remains a method.
    *   `main()` function becomes the `main` method.
    *   `M[n][n]` becomes a `long[][]` array.
    *   `print` functions become helper methods.
    *   `pm` (modular exponentiation) and `gcd` remain similar logic but with Java syntax.
    *   The `to_string` template is extremely complex and used for debugging. Since it's not used in the core logic provided in `solve()`, we can omit it to keep the code clean and efficient, or implement a simple version if needed. Given the core logic doesn't use `dbgm`, we can skip the complex `to_string` implementation.
6.  **Structure**:
    *   Create class `e_1917`.
    *   Create a fast I/O helper class or methods within the main class.
    *   Translate the logic inside `solve` step-by-step.

### Code Translation

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Arrays;

public class e_1917 {
    static long mod = 1000000007L;

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int t = sc.nextInt();
        while (t-- > 0) {
            solve(sc, out);
        }
        
        out.flush();
    }

    static void solve(FastReader sc, PrintWriter out) {
        int n = sc.nextInt();
        int k = sc.nextInt();

        long[][] M = new long[n][n];

        if (n == 2 && k == 2) {
            out.println("Yes");
            out.println("1 0");
            out.println("0 1");
            return;
        }

        // Initialize array with 0
        for (int i = 0; i < n; i++) {
            Arrays.fill(M[i], 0);
        }

        long inv = 0;
        if (k > n * n / 2) {
            inv = 1;
            k = n * n - k;
        }

        if ((k & 1) == 1) { // k&1
            out.println("No");
            return;
        }

        if (k % 4 == 2) {
            if (k == 2 || n < 3) {
                out.println("No");
                return;
            }

            M[n - 1][n - 3] = 1;
            M[n - 1][n - 2] = 1;
            M[n - 2][n - 3] = 1;
            M[n - 2][n - 1] = 1;
            M[n - 3][n - 1] = 1;
            M[n - 3][n - 2] = 1;

            k -= 6;
        }

        for (int j = 0; j < n - 2; j += 2) {
            if (k == 0) break;
            for (int i = 0; i < n; i += 2) {
                if (k == 0) break;

                M[i][j] = 1;
                M[i + 1][j] = 1;
                M[i][j + 1] = 1;
                M[i + 1][j + 1] = 1;

                k -= 4;
            }
        }

        out.println("Yes");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out.print((M[i][j] ^ inv) + " ");
            }
            out.println();
        }
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
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            if(s == null) return 0; // Should not happen based on problem constraints
            return Integer.parseInt(s);
        }
        
        long nextLong() {
            String s = next();
            if(s == null) return 0L;
            return Long.parseLong(s);
        }
    }
}
```

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Arrays;

public class e_1917 {
    static long mod = 1000000007L;

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        String tStr = sc.next();
        if(tStr != null) {
            int t = Integer.parseInt(tStr);
            while (t-- > 0) {
                solve(sc, out);
            }
        }
        
        out.flush();
    }

    static void solve(FastReader sc, PrintWriter out) {
        int n = sc.nextInt();
        int k = sc.nextInt();

        long[][] M = new long[n][n];

        if (n == 2 && k == 2) {
            out.println("Yes");
            out.println("1 0");
            out.println("0 1");
            return;
        }

        // Initialize array with 0
        for (int i = 0; i < n; i++) {
            Arrays.fill(M[i], 0);
        }

        long inv = 0;
        if (k > n * n / 2) {
            inv = 1;
            k = n * n - k;
        }

        if ((k & 1) == 1) { // k&1
            out.println("No");
            return;
        }

        if (k % 4 == 2) {
            if (k == 2 || n < 3) {
                out.println("No");
                return;
            }

            M[n - 1][n - 3] = 1;
            M[n - 1][n - 2] = 1;
            M[n - 2][n - 3] = 1;
            M[n - 2][n - 1] = 1;
            M[n - 3][n - 1] = 1;
            M[n - 3][n - 2] = 1;

            k -= 6;
        }

        for (int j = 0; j < n - 2; j += 2) {
            if (k == 0) break;
            for (int i = 0; i < n; i += 2) {
                if (k == 0) break;

                M[i][j] = 1;
                M[i + 1][j] = 1;
                M[i][j + 1] = 1;
                M[i + 1][j + 1] = 1;

                k -= 4;
            }
        }

        out.println("Yes");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out.print((M[i][j] ^ inv) + " ");
            }
            out.println();
        }
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
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            if(s == null) return 0;
            return Integer.parseInt(s);
        }
        
        long nextLong() {
            String s = next();
            if(s == null) return 0L;
            return Long.parseLong(s);
        }
    }
}
</CODE>