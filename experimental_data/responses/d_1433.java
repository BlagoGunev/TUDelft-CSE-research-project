Translate this C++ code to Java code. The main class name should be d_1433. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int Ull;
typedef pair<int ,int> PII;
template <typename T>
inline T  read()
{
    char c=getchar();
    T x=0,f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
template <typename T>
inline void write(T x) 
{
    if(x < 0) x = (~x) + 1, putchar('-');
    if(x / 10) write(x / 10);
    putchar(x % 10 | 48);
}
const int INF = 0x3f3f3f3f;
const ll N = 1e5+10;
int arr[5005];
//int vis[5005];
int main(){
    //ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int t = read<int>();
    while(t--){
        int n = read<int>();
        for(int i = 1; i <= n; i++) arr[i] = read<int>();
        bool flag = 0;
        int ii;
        for(int i = 1; i <= n; i++){
            if(arr[i] != arr[1]){
                flag = 1;
                ii = i;
                break;
            }
        }
        if(!flag) printf("NO\n");
        else{
            //memset(vis,0,sizeof(vis));
            //vis[1] = 1;
            printf("YES\n");
            for(int i = 2; i <= n; i++){
                if(arr[i] != arr[1]) printf("1 %d\n",i);
                else printf("%d %d\n",ii,i);
            }
        }
    }
}

Here is the translation plan and the resulting Java code.

### Translation Plan

1.  **Environment Setup**:
    *   The C++ code relies on `iostream` and `cstdio` (via `<bits/stdc++.h>`). In Java, we will use `java.io.BufferedReader` and `java.io.PrintWriter` for fast I/O, as `Scanner` and `System.out` are generally too slow for competitive programming constraints (implied by `1e5+10` and the custom `read` function).

2.  **Type Definitions**:
    *   C++: `typedef long long int ll;`
    *   Java: `long` is used for `ll`. `int` remains `int`.

3.  **Input/Output Logic**:
    *   C++: Custom `read()` function parsing characters.
    *   Java: A custom `readInt()` method using `BufferedReader` and `StringTokenizer` (or manual parsing) is preferred. Given the structure of the input (integers), a manual parser or `StringTokenizer` is sufficient.
    *   C++: `write()` function (recursive).
    *   Java: `PrintWriter` or `StringBuilder` for output. Since the logic is simple, `PrintWriter` is sufficient.
    *   C++: `printf`.
    *   Java: `PrintWriter.printf` or manual string concatenation.

4.  **Arrays**:
    *   C++: `int arr[5005]`.
    *   Java: `int[] arr`. The size needs to be `5005` to match C++ behavior (0-indexed vs 1-indexed logic).

5.  **Main Logic**:
    *   C++: `main()` function.
    *   Java: `main(String[] args)` method.
    *   C++: `ios_base::sync_with_stdio(0)...` (optimization).
    *   Java: Disable synchronization if using `Scanner` (not used here), or simply use the fast I/O directly.
    *   C++: `memset` (commented out).
    *   Java: Not needed as we don't use the commented-out array.
    *   C++: `flag` variable and `ii` index tracking.
    *   Java: `boolean flag` and `int ii`.

6.  **Class Structure**:
    *   The main class name must be `d_1433`.

7.  **Incremental Task Split**:
    *   Step 1: Setup class, imports, and constants.
    *   Step 2: Implement `readInt()` method.
    *   Step 3: Implement `main()` method logic (reading `t`, reading `n`, reading array).
    *   Step 4: Implement the logic to find the first element different from `arr[0]`.
    *   Step 5: Implement the output logic based on the flag.
    *   Step 6: Integrate and finalize.

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class d_1433 {
    
    // Fast I/O
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static StringTokenizer st;
    
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
    
    static int readInt() throws IOException {
        String s = next();
        if (s == null) return 0; // Should not happen based on problem constraints
        return Integer.parseInt(s);
    }
    
    public static void main(String[] args) throws IOException {
        String tStr = readInt(); // We assume input is valid integers
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        // C++: int arr[5005];
        int[] arr = new int[5005];
        
        while (t-- > 0) {
            int n = readInt();
            for (int i = 1; i <= n; i++) {
                arr[i] = readInt();
            }
            
            boolean flag = false;
            int ii = -1;
            
            // C++: for(int i = 1; i <= n; i++) { if(arr[i] != arr[1]) ... }
            for (int i = 1; i <= n; i++) {
                if (arr[i] != arr[1]) {
                    flag = true;
                    ii = i;
                    break;
                }
            }
            
            if (!flag) {
                out.println("NO");
            } else {
                out.println("YES");
                // C++: for(int i = 2; i <= n; i++) { ... }
                for (int i = 2; i <= n; i++) {
                    if (arr[i] != arr[1]) {
                        out.println("1 " + i);
                    } else {
                        out.println(ii + " " + i);
                    }
                }
            }
        }
        out.flush();
    }
}
</CODE>