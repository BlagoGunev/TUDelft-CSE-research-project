Translate this C++ code to Java code. The main class name should be f2_1077. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
using namespace std ;

int n, k, x ;

int a[5010] ;

long long dp[5010][5010] ;

deque < int > q ;

int main(){
	#define NAME "example"
	//freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

	ios_base :: sync_with_stdio(false) ;

	cin >> n >> k >> x ;

	for (int i = 1; i <= n; ++ i) cin >> a[i] ;

	memset(dp, -0x3f, sizeof(dp)) ;
	
	dp[0][0] = 0 ;

	for (int i = 1; i <= x; ++ i){
		for (int j = 1; j <= n; ++ j){
			while(!q.empty() && q.front() + k < j) q.pop_front() ;
			while(!q.empty() && dp[i - 1][q.back()] <= dp[i - 1][j - 1]) q.pop_back() ;
			q.push_back(j - 1) ;
			dp[i][j] = dp[i - 1][q.front()] + 1ll * a[j] ;
		}
		while(!q.empty()) q.pop_back() ;
	}

	long long res = -(long long)1e18 ;

	for (int i = n - k + 1; i <= n; ++ i) res = max(res, dp[x][i]) ;

	if(res < 0) cout << -1 ;
	else cout << res ;

	return 0 ;
}

Here is the plan for the translation from C++ to Java:

1.  **Includes and Namespace**: The C++ code uses `#include<bits/stdc++.h>` and `using namespace std;`. In Java, these are replaced by importing specific classes from the `java.util` and `java.io` packages.
2.  **Global Variables**: C++ allows global variables (e.g., `n`, `k`, `x`, `a`, `dp`, `q`). In Java, these must be instance variables or local variables inside the `main` method. Since the logic depends on them, moving them to be instance variables of the class `f2_1077` is the cleanest approach.
3.  **Data Types**:
    *   `int` maps to `int`.
    *   `long long` maps to `long`.
4.  **I/O Handling**:
    *   C++ uses `cin`, `cout`, `memset`, and `freopen`.
    *   Java uses `Scanner` or `BufferedReader` for input and `PrintWriter` or `System.out` for output. `BufferedReader` is generally preferred for performance in competitive programming contexts (suggested by the C++ `ios_base::sync_with_stdio(false)` optimization).
    *   `memset` is replaced by `Arrays.fill`.
5.  **Deques**: The C++ `std::deque` is replaced by Java's `ArrayDeque`.
6.  **Main Method**: The `main` function in C++ becomes the `public static void main(String[] args)` method in Java.
7.  **Code Structure**: The code will be split into logical blocks: Input Reading, Initialization, DP Loop, Result Calculation, and Output.

Here is the resulting Java code:

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class f2_1077 {

    int n, k, x;
    int[] a = new int[5010];
    long[][] dp = new long[5010][5010];
    ArrayDeque<Integer> q = new ArrayDeque<>();

    public static void main(String[] args) {
        new f2_1077().solve();
    }

    private void solve() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             PrintWriter out = new PrintWriter(System.out)) {

            StringTokenizer st = new StringTokenizer(br.readLine());
            if (!st.hasMoreTokens()) return;
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());

            for (int i = 1; i <= n; i++) {
                String line = br.readLine();
                while (line != null && line.trim().isEmpty()) {
                    line = br.readLine();
                }
                if (line != null) {
                    st = new StringTokenizer(line);
                    a[i] = Integer.parseInt(st.nextToken());
                }
            }

            Arrays.fill(dp, -0x3f3f3f3f3f3f3f3fL);
            dp[0][0] = 0;

            for (int i = 1; i <= x; i++) {
                q.clear();
                for (int j = 1; j <= n; j++) {
                    while (!q.isEmpty() && q.peekFirst() + k < j) {
                        q.pollFirst();
                    }
                    while (!q.isEmpty() && dp[i - 1][q.peekLast()] <= dp[i - 1][j - 1]) {
                        q.pollLast();
                    }
                    q.add(j - 1);
                    dp[i][j] = dp[i - 1][q.peekFirst()] + (long) a[j];
                }
            }

            long res = Long.MIN_VALUE;
            // Adjusting the loop range to match C++ logic: max(n-k+1, 1) to n
            int start = Math.max(1, n - k + 1);
            for (int i = start; i <= n; i++) {
                res = Math.max(res, dp[x][i]);
            }

            if (res < 0) {
                out.println("-1");
            } else {
                out.println(res);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
</CODE>