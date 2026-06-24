Translate this C++ code to Java code. The main class name should be b_1693. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#include <ext/pb_ds/detail/standard_policies.hpp>



using namespace std;

using namespace __gnu_pbds;



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

typedef tree<int , int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;



// ord_set.find_by_order(1) --> returns an iterator to the k-th largest element (counting from zero)

// ord_set.order_of_key(3) --> returns the number of items in a set that are strictly smaller than our item



typedef long long ll; 

typedef long double ld;

typedef pair<int, int> pi; 

typedef pair<ll, ll> pl; 

typedef pair<string, string> pss; 

typedef vector<int> vi; 

typedef vector<vi> vvi; 

typedef vector<pi> vpi;

typedef vector<pl> vpl;

typedef vector<ll> vl; 

typedef vector<vl> vvl; 

typedef map<int,int > mpi;

typedef queue<int> qi;

typedef priority_queue<int> pqi;

typedef priority_queue <int, vector<int>, greater<int>> minpq;



#define ff first

#define ss second

#define pb push_back

#define mkp make_pair

#define endline "\n"

#define print(a,b) cout<<a<<" "<<b<<" "

#define println(a,b) cout<<a<<" "<<b<<endl



#define mod 1000000007

#define mxN 10000000

#define all(v) v.begin(),v.end() 

#define rall(v) v.rbegin(),v.rend() 

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)





// int uint64_log10(uint64_t n)

// {

//   #define S(k, m) if (n >= UINT64_C(m)) { i += k; n /= UINT64_C(m); }



//   int i = -(n == 0);

//   S(16,10000000000000000); S(8,100000000); S(4,10000); S(2,100); S(1,10);

//   return i;



//   #undef S

// }



// int uint64_log2(uint64_t n)

// {

//   #define S(k) if (n >= (UINT64_C(1) << k)) { i += k; n >>= k; }



//   int i = -(n == 0); S(32); S(16); S(8); S(4); S(2); S(1); return i;



//   #undef S

// }





// ll fact[mxN];

// void factorial() {

//   fact[0] = 1 ;

//   for(ll i = 1;i< mxN;++i) 

//     fact[i] = ( i * fact[i-1] ) % mod ;

// }



ll power(int a,int b) {

  a %= mod ; 

  if(b == 0 ) return 1;

  ll p = power(a,b/2) % mod ;

  p = p * p % mod ;

  return b & 1 ? p * a % mod : p ; 

}



ll invMod(ll a) {

  return power(a,mod-2) % mod ;

}

int gcd(int a, int b) {

  if (a < b)swap(a, b);

  while (b) {

    int r = a % b; a = b; b = r;

  }

  return a;

}



// ll ncr(int n, int k) { 

//     ll res = 1; 

  

//     if (k > n - k) 

//         k = n - k; 

  

//     for (int i = 0; i < k; ++i) { 

//         res = (res* (n - i))%mod; 



//         res = (res *invMod(i+1))%mod;

//     } 

  

//     return res; 

// } 





void prt(vi v){

  for (int i=0;i<v.size();i++){

    cout<<v[i]<<" ";

  }

  cout<<endl;

}



void prt2d(vvi v){

  for (int i=0;i<v.size();i++){



    for(int j=0;j<v[0].size();j++)

       cout<<v[i][j]<<" ";

    cout<<endl;

  }

}



vi graph[200005];

ll l[200005],r[200005];

ll operations;



ll dfs(int curr){

  ll opr=0;

  for(auto ch: graph[curr]){

     ll x=dfs(ch);

     //cout<<"ch: "<<ch<<" "<<x<<endl;

     opr+=x;

  }

  if(opr<l[curr]){

    operations++;

    return r[curr];

  }

  else return min(r[curr],opr);

}

void solve(){

  ll i,j,n,m,p;

  cin>>n;

  

  operations=0;

  for(i=2;i<=n;i++){

    cin>>p;

    graph[p].pb(i);

  }



  for(i=1;i<=n;i++){

    cin>>l[i]>>r[i];

  }

  

  dfs(1);

  cout<<operations<<endl;

  for(i=1;i<=n;i++)graph[i].clear();



}







//bool compare( int a[2], int b[2]) { return (a[1]<=a[1]) ; }

int main(){

  fio;

  #ifndef ONLINE_JUDGE

     freopen("input.txt","r", stdin);

     freopen("output.txt","w", stdout);

    #endif

   

   int i,j,t=1;

   cin>>t;



   while(t--){

     solve();

   }

   

   return 0;

}

Here is the plan for translating the provided C++ code to Java:

1.  **Header & Imports**: C++ uses `bits/stdc++.h` and specific headers for Policy-Based Data Structures (PBDS). Java does not have PBDS. The `ordered_set`, `ordered_multi_set`, and `ordered_map` typedefs must be removed or replaced with standard Java collections (like `TreeSet` or `TreeMap`) if they were used. In this specific code, they are defined but not used.
2.  **Data Types**:
    *   `ll` (long long) $\rightarrow$ `long`.
    *   `int` $\rightarrow$ `int`.
    *   `pi` (pair<int,int>) $\rightarrow$ `int[]` or `Pair` class. Since the code uses `graph` as an array of vectors and `l`, `r` as arrays, `int[]` is the most natural fit.
3.  **Macros**:
    *   `mod` $\rightarrow$ `final long MOD = 1000000007L`.
    *   `mxN` $\rightarrow$ `final int MAXN = 10000005`.
    *   `fio` $\rightarrow$ `BufferedReader` and `PrintWriter` (or `System.out` with `PrintWriter` for efficiency).
    *   `fopen` (file I/O) $\rightarrow$ `BufferedReader` reading from a specific file path if running locally, or standard `System.in` for online judges.
4.  **Arrays**: C++ uses static arrays (`graph[200005]`, `l[200005]`, `r[200005]`). In Java, these must be allocated dynamically or as large static arrays inside the class. Given the recursion depth and stack size limits in Java, a recursive solution might need an increased stack size or iterative conversion, but for this specific logic, we will keep it recursive.
5.  **Recursion**: Java handles recursion similarly to C++, but the default stack size might be smaller. We will implement the `dfs` method as is.
6.  **Input/Output**: Replace `cin`/`cout` with a custom `FastScanner` class using `BufferedReader` and `StringTokenizer` to handle the large input efficiently, similar to `fio` optimization.

**Incremental Tasks Plan**:
1.  Define the `FastScanner` utility class.
2.  Define constants (`MOD`, `MAXN`) and the main class `b_1693`.
3.  Translate the `power` and `invMod` methods.
4.  Translate the `dfs` method, ensuring array access is handled via indices.
5.  Translate the `solve` method, handling input reading and graph construction.
6.  Translate the `main` method to handle test cases and I/O redirection.

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;

public class b_1693 {
    
    // Constants
    static final long MOD = 1000000007L;
    static final int MAXN = 10000005; // Slightly larger than 10^7 to be safe

    // Global variables to match C++ static arrays
    static ArrayList<Integer>[] graph;
    static long[] l;
    static long[] r;
    static long operations;

    // FastScanner to replace cin/cout and optimize I/O
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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
            if (s == null) return -1; // Should not happen based on logic
            return Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            if (s == null) return -1;
            return Long.parseLong(s);
        }
    }

    // Modular Exponentiation (replacing C++ power function)
    static long power(int a, int b) {
        a %= MOD;
        if (b == 0) return 1;
        long p = power(a, b / 2);
        p = (p * p) % MOD;
        return (b & 1) ? (p * a) % MOD : p;
    }

    // Modular Inverse (replacing C++ invMod function)
    static long invMod(long a) {
        return power((int)a, (int)(MOD - 2)) % MOD;
    }

    // Greatest Common Divisor (replacing C++ gcd function)
    static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // DFS function
    static long dfs(int curr) {
        long opr = 0;
        ArrayList<Integer> children = graph[curr];
        if (children == null) return r[curr]; // Base case if no children

        for (int ch : children) {
            long x = dfs(ch);
            opr += x;
        }

        if (opr < l[curr]) {
            operations++;
            return r[curr];
        } else {
            return Math.min(r[curr], opr);
        }
    }

    // Solve function
    static void solve(FastScanner sc) {
        int n = sc.nextInt();
        
        // Re-initializing globals for each test case
        // In C++ this is global static. In Java, we recreate or clear.
        // Given the constraints and logic, we recreate the graph array.
        // Note: Creating a new ArrayList array every time might be slow if N is large and T is large.
        // However, the C++ code does `graph[p].pb(i)` which implies reusing or clearing.
        // We will initialize the graph array of size n+1 here.
        
        graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        l = new long[n + 1];
        r = new long[n + 1];
        operations = 0;

        // Reading edges
        // The C++ loop: for(i=2;i<=n;i++){ cin>>p; graph[p].pb(i); }
        // Note: The C++ code reads `p` then adds `i` to `graph[p]`.
        // This means `p` is the parent and `i` is the child.
        for (int i = 2; i <= n; i++) {
            int p = sc.nextInt();
            graph[p].add(i);
        }

        // Reading l and r values
        for (int i = 1; i <= n; i++) {
            l[i] = sc.nextLong();
            r[i] = sc.nextLong();
        }

        // Run DFS
        dfs(1);
        
        // Output result
        PrintWriter out = new PrintWriter(System.out);
        out.println(operations);
        out.flush();
    }

    // Main function
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        String tStr = sc.next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);

        while (t-- > 0) {
            solve(sc);
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
import java.util.ArrayList;

public class b_1693 {
    
    // Constants
    static final long MOD = 1000000007L;
    static final int MAXN = 10000005; // Slightly larger than 10^7 to be safe

    // Global variables to match C++ static arrays
    // In C++: graph[200005], l[200005], r[200005]
    // In Java: We allocate dynamically based on N inside solve() to handle multiple test cases efficiently
    static ArrayList<Integer>[] graph;
    static long[] l;
    static long[] r;
    static long operations;

    // FastScanner to replace cin/cout and optimize I/O
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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
            if (s == null) return -1;
            return Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            if (s == null) return -1;
            return Long.parseLong(s);
        }
    }

    // Modular Exponentiation (replacing C++ power function)
    static long power(int a, int b) {
        a %= MOD;
        if (b == 0) return 1;
        long p = power(a, b / 2);
        p = (p * p) % MOD;
        return (b & 1) ? (p * a) % MOD : p;
    }

    // Modular Inverse (replacing C++ invMod function)
    static long invMod(long a) {
        return power((int)a, (int)(MOD - 2)) % MOD;
    }

    // Greatest Common Divisor (replacing C++ gcd function)
    static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // DFS function
    // Note: The C++ code uses `graph` as an array of vectors. 
    // In Java, this is an array of ArrayLists.
    static long dfs(int curr) {
        long opr = 0;
        ArrayList<Integer> children = graph[curr];
        if (children == null || children.isEmpty()) return r[curr];

        for (int ch : children) {
            long x = dfs(ch);
            opr += x;
        }

        if (opr < l[curr]) {
            operations++;
            return r[curr];
        } else {
            return Math.min(r[curr], opr);
        }
    }

    // Solve function
    static void solve(FastScanner sc) {
        int n = sc.nextInt();
        
        // Re-initializing globals for each test case
        // In C++ this is global static. In Java, we recreate or clear.
        // Given the constraints and logic, we recreate the graph array.
        // Note: Creating a new ArrayList array every time might be slow if N is large and T is large.
        // However, the C++ code does `graph[p].pb(i)` which implies reusing or clearing.
        // We will initialize the graph array of size n+1 here.
        
        graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        
        l = new long[n + 1];
        r = new long[n + 1];
        operations = 0;

        // Reading edges
        // The C++ loop: for(i=2;i<=n;i++){ cin>>p; graph[p].pb(i); }
        // Note: The C++ code reads `p` then adds `i` to `graph[p]`.
        // This means `p` is the parent and `i` is the child.
        for (int i = 2; i <= n; i++) {
            int p = sc.nextInt();
            graph[p].add(i);
        }

        // Reading l and r values
        for (int i = 1; i <= n; i++) {
            l[i] = sc.nextLong();
            r[i] = sc.nextLong();
        }

        // Run DFS
        dfs(1);
        
        // Output result
        PrintWriter out = new PrintWriter(System.out);
        out.println(operations);
        out.flush();
    }

    // Main function
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        String tStr = sc.next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);

        while (t-- > 0) {
            solve(sc);
        }
    }
}
</CODE>