Translate this C++ code to Java code. The main class name should be b_1726. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>

using namespace std;

 

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

 

#define fix(n,f) std::fixed<<std::setprecision(f)<<n

#define ll long long 

#define all(v) v.begin(),v.end()

#define nl "\n"

#define M 1000000007 

#define sum(a,b) ((a%M)+(b%M))%M

#define pro(a,b) ((a%M)*(b%M))%M

#define diff(a,b) ((a%M)-(b%M))%M



/*=================================== Bow to Lord Shiva  =================================*/

void Print(vector<ll> v){

    for(auto &p:v){cout<<p<<" ";}cout<<nl;

}

void solve(){

    ll n,m;cin>>n>>m;

    if(m<n){

        cout<<"No"<<nl;

        return;

    }

    if(n&1){

        cout<<"Yes"<<nl;

        for(ll i=0;i<n-1;i++){

            cout<<1<<" ";

        }

        cout<<m-n+1<<nl;

    }

    else{

        if(m%2==0){

            cout<<"Yes"<<nl;

            for(ll i=0;i<n-2;i++){

                cout<<1<<" ";

            }

            cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<nl;

        }

        else{

            cout<<"No"<<nl;

        }

    }

}



int main(){

    fastio();

   // freopen("input.txt", "r" ,stdin);

   // freopen("output.txt", "w" ,stdout);

    int t=1;

    cin>>t;

    while(t--){

        solve();    

    }

}

Here is the plan for translating the provided C++ code to Java.

### Translation Plan

1.  **Environment Setup**:
    *   **Class Name**: Rename the main class to `b_1726`.
    *   **Entry Point**: Change `int main()` to `public static void main(String[] args)`.
    *   **Fast I/O**: Implement the logic of `fastio()` using `BufferedReader` and `PrintWriter` (or `System.out` with `StringBuilder`) to handle large inputs efficiently, which is standard in Java for competitive programming.

2.  **Data Types**:
    *   **`long long`**: In C++, `long long` is used to store large integers. In Java, this maps directly to `long`.
    *   **`int`**: Maps directly to `int`.

3.  **Specific Features & Macros**:
    *   **`#include<bits/stdc++.h>`**: Removed. Java requires explicit imports.
    *   **`using namespace std;`**: Removed. Java requires explicit class/method usage.
    *   **`#define fastio()`**: Replaced with Java I/O setup.
    *   **`#define ll long long`**: Replaced with type `long`.
    *   **`#define M 1000000007`**: Defined as a static `final long` constant.
    *   **`#define sum(a,b) ...`**: In this specific problem, the `sum` and `pro` macros are not used in the logic (only `diff` logic is implicitly handled by checking parity or specific arithmetic). However, the logic uses simple arithmetic. The logic `m-n+1` and `(m-n+2)/2` does not require modulo operations on the result itself, only the inputs are checked against `n`. The `diff` macro is also not used in the logic. So, we can simply perform the arithmetic operations directly.
    *   **`#define all(v)`**: Not used in the logic.
    *   **`#define nl "\n"`**: In Java, we can use `System.out.println()` or append `"\n"` to a `StringBuilder`.

4.  **Logic Translation**:
    *   **`Print` Function**: This function prints a vector. In Java, we can either pass a `List<Long>` or a `long[]` and print it inside `solve`. Since the logic generates the array dynamically, it's cleaner to implement the printing logic directly inside `solve` to avoid overhead of creating a `List` object and passing it.
    *   **`solve` Function**:
        *   Read `n` and `m`.
        *   Check `if (m < n)`: Print "No".
        *   Check `if (n & 1)` (Odd `n`):
            *   Print "Yes".
            *   Loop `n-1` times printing `1`.
            *   Print `m - n + 1`.
        *   Else (Even `n`):
            *   Check `if (m % 2 == 0)`:
                *   Print "Yes".
                *   Loop `n-2` times printing `1`.
                *   Print `(m - n + 2) / 2` twice.
            *   Else:
                *   Print "No".
    *   **`main` Function**:
        *   Initialize `t = 1`.
        *   Read `t`.
        *   Loop `t` times calling `solve()`.

5.  **Incremental Tasks**:
    *   Task 1: Setup `b_1726` class with `main` method and `BufferedReader`/`PrintWriter`.
    *   Task 2: Implement the `solve` logic with input parsing.
    *   Task 3: Implement the conditional logic for the specific problem constraints (Odd/Even `n`, Parity of `m`).
    *   Task 4: Handle the output formatting (spaces between numbers, newlines).

### Code Implementation

<CODE>
import java.io.*;
import java.util.*;

public class b_1726 {
    static BufferedReader br;
    static PrintWriter out;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        
        // Read number of test cases
        // The C++ code initializes t=1 and reads t. 
        // Usually in CP, t is read from input. We follow the C++ logic exactly.
        // However, standard CP inputs usually provide t. The code provided does:
        // int t=1; cin>>t; 
        // This implies the input file MUST contain the number of test cases.
        // If the input is empty or doesn't contain t, it will block waiting for input.
        // We assume standard CP input format where the first line is the number of test cases.
        
        String line = br.readLine();
        if (line == null) return;
        int t = Integer.parseInt(line.trim());

        while (t-- > 0) {
            solve();
        }
        
        out.flush();
    }

    private static void solve() throws IOException {
        // Read n and m
        // Handle potential whitespace skipping
        while (st == null || !st.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) return;
            st = new StringTokenizer(s);
        }
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());

        if (m < n) {
            out.println("No");
            return;
        }

        if ((n & 1) == 1) { // n is odd
            out.println("Yes");
            // Print n-1 ones
            for (long i = 0; i < n - 1; i++) {
                out.print("1 ");
            }
            // Print the remainder
            long remainder = m - n + 1;
            out.println(remainder);
        } else { // n is even
            if (m % 2 == 0) {
                out.println("Yes");
                // Print n-2 ones
                for (long i = 0; i < n - 2; i++) {
                    out.print("1 ");
                }
                // Print the two equal numbers
                long val = (m - n + 2) / 2;
                out.println(val + " " + val);
            } else {
                out.println("No");
            }
        }
    }
}
</CODE>