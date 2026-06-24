Translate this C++ code to Java code. The main class name should be d_496. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int N=100100;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
int arr[N];
int s0[N+1],s1[N+1],p0[N],p1[N];
int cnt0,cnt1;
int main(){
	std::ios::sync_with_stdio(0);

	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==1)
			p0[cnt0++]=i;
		else
			p1[cnt1++]=i;
		s0[i+1]=s0[i]+(arr[i]==1);
		s1[i+1]=s1[i]+(arr[i]==2);
	}
    
	vector<pair<int,int> > ans;
	for(int k=1;k<=n;k++){
		int t0=0,t1=0;
		int flag=0;
		int ok=1;
		i=0;
		while(i<n){
			int j0=s0[i]+k>cnt0?n+1:(p0[s0[i]+k-1]+1);
			int j1=s1[i]+k>cnt1?n+1:(p1[s1[i]+k-1]+1);
			if(min(j0,j1)>n){
				ok=0;
				break;
			}
			if(j0<j1){
				i=j0;
				t0++;
				flag=0;
			}
			else{
				i=j1;
				t1++;
				flag=1;
			}
		}
		if(t0==t1 || (t0<t1)^flag){
			ok=0;
		}
		if(ok){
			ans.push_back(make_pair(max(t0,t1),k));
		}
	}
    sort(ans.begin(),ans.end());

cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;

	return 0;
}

Here is the plan for the C++ to Java translation:

1.  **Headers and Imports**:
    *   `#include<iostream>` and `#include<cstdio>` are replaced by `java.io.*` and `java.util.*`.
    *   `#include<vector>` and `#include<algorithm>` are replaced by `java.util.*`.

2.  **Constants and Macros**:
    *   `const int N=100100;` becomes `static final int N = 100100;`.
    *   Macros `max(a,b)` and `min(a,b)` are replaced by `Math.max(a,b)` and `Math.min(a,b)`.
    *   `using namespace std;` is removed (Java requires fully qualified names or imports).

3.  **Data Structures**:
    *   C++ arrays `int arr[N]`, `s0[N+1]`, etc., are translated to Java `int[]` arrays.
    *   `vector<pair<int,int> > ans;` is translated to `ArrayList<int[]> ans`. Since C++ `pair` is not directly available in standard Java, a custom class or a 2-element array is used. A 2-element `int[]` is simpler and sufficient here.
    *   `std::ios::sync_with_stdio(0);` is removed. In Java, `Scanner` is somewhat slow, but usually acceptable for competitive programming unless strict time limits apply. Given the logic involves a loop over `N`, `Scanner` might be slow, but `BufferedReader` + `StringTokenizer` is a safer bet for large inputs. However, to keep the logic structure close to the original simple `cin` style, I will use `Scanner` but keep in mind that for $N=100100$, `BufferedReader` is often preferred. I will use `Scanner` for simplicity unless the code complexity suggests otherwise, but actually, looking at the nested loop `while(i<n)`, the complexity is roughly $O(N^2)$ in the worst case (though the logic suggests it's optimized via the `s0`/`s1` pointers to be $O(N)$ or $O(N \log N)$). Wait, the inner loop `while(i<n)` jumps `i` by at least 1. In the worst case (all 1s or all 2s), it runs $N$ times. Total complexity $O(N^2)$. For $N=100,000$, $N^2$ is $10^{10}$, which will TLE in Java.
    *   *Correction*: The logic `j0 = ...`, `j1 = ...`, `i = j0` or `j1` implies that `i` jumps forward. This is a two-pointer / binary search style logic. If the array is sorted, it's fast. If not, it's still efficient because `i` always increases. The number of steps is bounded by $N$. The outer loop runs $N$ times. So it's $O(N^2)$ in worst case. Wait, no. The pointers `p0` and `s0` allow jumping.
    *   Actually, let's look at the complexity. The outer loop is `k` from 1 to `n`. Inside, `i` starts at 0 and increments. In each step, `i` jumps to `j0` or `j1`. Since `j0 > i` and `j1 > i`, `i` strictly increases. The maximum value `i` reaches is `n`. So the inner `while` loop runs at most `n` times total across all `k`? No, for a specific `k`, `i` runs. But `s0` and `s1` depend on `k`? No, `s0` is prefix sum of 1s. `s0[i] + k` is the index in `p0` for the $(s0[i]+k)$-th '1'.
    *   The loop structure is: For each `k`, we simulate a process starting from `i=0`. We pick the next position. The position `i` is updated. The loop terminates when `i` exceeds `n`.
    *   This looks like the code is checking if a valid sequence of length `k` exists. The complexity is roughly $O(N^2)$ because for each `k`, we might scan the whole array.
    *   Regardless of complexity, the translation task is to map the logic. I will use `BufferedReader` and `StringTokenizer` for I/O to ensure it runs fast enough for Java, as `Scanner` is notoriously slow for large inputs.

4.  **Main Class Structure**:
    *   Class name `d_496`.
    *   Method `main`.
    *   Logic translation:
        *   `cin >> n` -> `st.nextToken()`.
        *   Arrays -> `int[]`.
        *   `vector` -> `ArrayList`.
        *   `sort` -> `Collections.sort` (with a custom comparator for `int[]` or implementing `Comparable`).
        *   `push_back` -> `add`.
        *   `make_pair` -> `new int[]{...}`.
        *   `cout` -> `System.out.println` or `StringBuilder`.

5.  **Incremental Tasks**:
    *   Define class and I/O setup.
    *   Define arrays and read input.
    *   Implement the logic for `s0`, `s1`, `p0`, `p1`.
    *   Implement the nested loop logic.
    *   Implement sorting and output.

6.  **Specific Translations**:
    *   `pair<int,int>` -> `int[]` of size 2.
    *   `make_pair` -> `new int[]{a, b}`.
    *   `sort` -> `Collections.sort`. Since `int[]` is not `Comparable`, we need a custom `Comparator`.
    *   `std::ios::sync_with_stdio(0)` -> Removed (or replaced with fast I/O).

Let's write the code.

```java
import java.io.*;
import java.util.*;

public class d_496 {
    static final int N = 100100;
    static int[] arr = new int[N];
    static int[] s0 = new int[N + 1];
    static int[] s1 = new int[N + 1];
    static int[] p0 = new int[N];
    static int[] p1 = new int[N];
    static int cnt0, cnt1;
    static int n;
    static int i; // Reusing i as in C++ code, though in Java it's safer to declare inside loops. 
                  // The C++ code declares `int i;` before the loop and reuses it.
                  // In Java, we must declare it inside the loop or re-declare.
                  // The C++ code: `int i; for(i=0;i<n;i++){...}`.
                  // Inside the loop: `i=0; while(i<n){...}`.
                  // So `i` is declared once outside. In Java, we can do the same.

    public static void main(String[] args) throws IOException {
        // I/O Setup
        // Using BufferedReader for speed, as Scanner might be too slow for N=100000 with O(N^2) logic
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        // Read n
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        n = Integer.parseInt(st.nextToken());

        // Read array
        for (i = 0; i < n; i++) {
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            arr[i] = Integer.parseInt(st.nextToken());
            
            if (arr[i] == 1) {
                p0[cnt0++] = i;
            } else {
                p1[cnt1++] = i;
            }
            s0[i + 1] = s0[i] + (arr[i] == 1 ? 1 : 0);
            s1[i + 1] = s1[i] + (arr[i] == 2 ? 1 : 0);
        }

        // Logic
        // Using ArrayList<int[]> to simulate vector<pair<int,int>>
        ArrayList<int[]> ans = new ArrayList<>();

        for (int k = 1; k <= n; k++) {
            int t0 = 0;
            int t1 = 0;
            int flag = 0;
            int cur_i = 0; // Using a local variable to avoid confusion, though C++ reuses 'i'
            
            // Note: The C++ code reuses 'i' declared outside. 
            // In Java, we must declare it inside the loop.
            // However, the C++ code sets `i=0` at the start of the loop.
            // So `cur_i` is equivalent to `i`.
            
            while (cur_i < n) {
                // j0 calculation
                int idx0 = s0[cur_i] + k;
                int j0 = idx0 > cnt0 ? n + 1 : p0[idx0 - 1] + 1;

                // j1 calculation
                int idx1 = s1[cur_i] + k;
                int j1 = idx1 > cnt1 ? n + 1 : p1[idx1 - 1] + 1;

                if (Math.min(j0, j1) > n) {
                    cur_i = n + 1; // Break condition equivalent
                    break;
                }

                if (j0 < j1) {
                    cur_i = j0;
                    t0++;
                    flag = 0;
                } else {
                    cur_i = j1;
                    t1++;
                    flag = 1;
                }
            }

            // Check condition
            // C++: if(t0==t1 || (t0<t1)^flag)
            // Java: (t0 == t1) || (t0 < t1) ^ flag
            // Note: ^ is XOR in C++ for booleans/integers.
            // In Java, ^ is bitwise XOR.
            // boolean logic: (t0 < t1) != flag
            boolean cond1 = (t0 == t1);
            boolean cond2 = (t0 < t1);
            boolean cond3 = (cond2 != flag);
            
            if (cond1 || cond3) {
                ans.add(new int[]{Math.max(t0, t1), k});
            }
        }

        // Sort
        Collections.sort(ans, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                // Sort by first element (primary), then second (secondary)
                if (a[0] != b[0]) return a[0] - b[0];
                return a[1] - b[1];
            }
        });

        // Output
        StringBuilder sb = new StringBuilder();
        sb.append(ans.size()).append("\n");
        for (int[] pair : ans) {
            sb.append(pair[0]).append(" ").append(pair[1]).append("\n");
        }
        System.out.print(sb);
    }
}
```

Wait, I should double check the `i` variable.
In C++:
```cpp
int i;
for(i=0;i<n;i++){ ... }
    for(int k=1;k<=n;k++){
        // ...
        i=0;
        while(i<n){
             // ...
        }
```
The `i` inside the `k` loop is re-initialized to 0. The `i` declared before the `k` loop is effectively shadowed or reused.
In Java:
```java
int i;
for(i=0; i<n; i++) { ... }

for(int k=1; k<=n; k++) {
    int t0 = 0;
    // ...
    int i = 0; // Must declare inside loop or shadow it. 
                // If I declare `int i = 0;` inside, it's fine.
    // But wait, the C++ code has `i` declared outside the `k` loop.
    // `for(int k...` does NOT declare `i`.
    // So `i` is the variable from the first loop.
    // Inside the `k` loop, `i=0` resets it.
    // In Java, I can do `int i = 0;` inside the `k` loop.
}
```
However, to be safe and clean, I will use a distinct variable name `cur_i` or just reuse `i` if I declare it inside the loop. The logic is the same. I used `cur_i` in the draft above. I will stick with `cur_i` to be explicit, or just use `i` if I declare it inside the loop. The prompt asks to translate the code. If I change variable names, it's still valid Java. But to be faithful to the logic flow, I will declare `int i = 0;` inside the `k` loop.

Wait, `s0[i]` accesses `s0` at index `i`. `s0` is size `N+1`.
The indices `p0` are populated at `0` to `cnt0-1`.
`s0[i]` is the count of 1s in `arr[0...i-1]`.
`s0[i+1]` is the count of 1s in `arr[0...i]`.
The logic: `j0 = s0[i] + k > cnt0 ? n+1 : p0[s0[i] + k - 1] + 1`.
If `s0[i] + k` is the target count of 1s, we want the index in `p0`.
`p0` is 0-indexed. `p0[0]` is the index of the 1st '1'.
So `p0[count - 1]` is the index of the `count`-th '1'.
So `p0[s0[i] + k - 1]` is correct.
The `+1` at the end of `j0` is to make it 1-based index?
In C++, `p0` stores 0-based indices (since `i` goes from 0 to `n-1`).
So `p0[...] + 1` makes it 1-based index.
The condition `min(j0, j1) > n` checks if the index exceeds `n`.
This logic is preserved.

One detail: `t0` and `t1` are counts. `max(t0, t1)` is the answer.
The `sort` logic: `ans` is `vector<pair<int,int>>`.
In Java `ArrayList<int[]>`.
Comparator: `a[0]` vs `b[0]`, then `a[1]` vs `b[1]`.

I will refine the I/O to use `BufferedReader` and `StringTokenizer` because `Scanner` is slow and the problem likely has tight time limits (implied by `N=100100` and the algorithmic complexity).

Final check on `min` and `max` macros.
C++: `#define min(a,b) ((a)>(b)?(b):(a))`
Java: `Math.min(a, b)`
C++: `#define max(a,b) ((a)>(b)?(a):(b))`
Java: `Math.max(a, b)`

The XOR logic: `(t0<t1)^flag`.
In C++, `^` is bitwise XOR. `flag` is 0 or 1. `t0<t1` is boolean.
In C++, `bool` is treated as integer 0 or 1.
In Java, `^` is bitwise XOR. If we use boolean operands, `^` acts as logical XOR (`!=`).
So `(t0 < t1) ^ flag` works in Java if `flag` is int?
Wait. `flag` is `int`. `t0 < t1` is `boolean`.
In C++, `boolean ^ int` works? Yes, `true` is 1, `false` is 0.
In Java, `boolean ^ int` is a compile error.
We must cast or use logical XOR.
`(t0 < t1) != flag` is the correct translation for `(t0 < t1) ^ flag` where `flag` is 0 or 1.

I will construct the final code now.

```java
import java.io.*;
import java.util.*;

public class d_496 {
    static final int N = 100100;
    static int[] arr = new int[N];
    static int[] s0 = new int[N + 1];
    static int[] s1 = new int[N + 1];
    static int[] p0 = new int[N];
    static int[] p1 = new int[N];
    static int cnt0, cnt1;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        // Read n
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        n = Integer.parseInt(st.nextToken());

        // Read array and build structures
        for (int i = 0; i < n; i++) {
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            arr[i] = Integer.parseInt(st.nextToken());

            if (arr[i] == 1) {
                p0[cnt0++] = i;
            } else {
                p1[cnt1++] = i;
            }
            s0[i + 1] = s0[i] + (arr[i] == 1 ? 1 : 0);
            s1[i + 1] = s1[i] + (arr[i] == 2 ? 1 : 0);
        }

        // Logic
        ArrayList<int[]> ans = new ArrayList<>();

        for (int k = 1; k <= n; k++) {
            int t0 = 0;
            int t1 = 0;
            int flag = 0;
            int i = 0; // Re-declared inside loop to match C++ scope behavior (reset to 0)
            
            while (i < n) {
                int idx0 = s0[i] + k;
                int j0 = idx0 > cnt0 ? n + 1 : p0[idx0 - 1] + 1;

                int idx1 = s1[i] + k;
                int j1 = idx1 > cnt1 ? n + 1 : p1[idx1 - 1] + 1;

                if (Math.min(j0, j1) > n) {
                    break;
                }

                if (j0 < j1) {
                    i = j0;
                    t0++;
                    flag = 0;
                } else {
                    i = j1;
                    t1++;
                    flag = 1;
                }
            }

            // C++: if(t0==t1 || (t0<t1)^flag)
            // Java: (t0 == t1) || ((t0 < t1) ^ flag)
            // Since flag is int (0 or 1), we use != for logical XOR with boolean
            boolean cond1 = (t0 == t1);
            boolean cond2 = (t0 < t1);
            boolean cond3 = (cond2 != flag);

            if (cond1 || cond3) {
                ans.add(new int[]{Math.max(t0, t1), k});
            }
        }

        // Sort
        Collections.sort(ans, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) return a[0] - b[0];
                return a[1] - b[1];
            }
        });

        // Output
        StringBuilder sb = new StringBuilder();
        sb.append(ans.size()).append("\n");
        for (int[] pair : ans) {
            sb.append(pair[0]).append(" ").append(pair[1]).append("\n");
        }
        System.out.print(sb);
    }
}
```
One small detail: `cnt0` and `cnt1` are static fields. They are incremented in the first loop. They are not reset. This matches the C++ code where `cnt0` and `cnt1` are global/static and incremented.
The `p0` array is populated up to `cnt0`.
The logic `idx0 > cnt0` handles the case where we need more 1s than available.
This is correct.

I'll output the code now.
</think>

The translation from C++ to Java involves adapting the syntax, data structures, and libraries to Java's standard.

**Translation Plan:**
1.  **Imports**: Replace `#include<iostream>`, `#include<cstdio>`, `#include<vector>`, `#include<algorithm>` with `java.io.*` and `java.util.*`.
2.  **Constants and Macros**:
    *   `const int N` becomes `static final int N`.
    *   Macros `max(a,b)` and `min(a,b)` are replaced with `Math.max(a,b)` and `Math.min(a,b)`.
    *   `using namespace std;` is removed as Java requires explicit class names.
3.  **Data Structures**:
    *   C++ global arrays (`int arr[N]`, etc.) become `static int[]` arrays in Java.
    *   `std::vector<pair<int,int> > ans` is replaced by `ArrayList<int[]>`. `pair` is simulated using `int[]` of size 2.
    *   `std::sort` is replaced by `Collections.sort` with a custom `Comparator`.
4.  **I/O**:
    *   `std::cin` and `std::cout` are replaced by `BufferedReader` and `StringTokenizer` for efficiency (essential for large $N$ in Java).
    *   `std::ios::sync_with_stdio(0);` is removed (Java's I/O is already buffered, but `BufferedReader` is used here for speed).
5.  **Logic**:
    *   The nested loop logic is preserved.
    *   The condition `(t0<t1)^flag` (C++ bitwise XOR on boolean/int) is translated to `(t0 < t1) != flag` (Java logical inequality).
    *   Variable `i` is declared inside the `k` loop in the original C++ code (after initialization outside). In Java, we must declare it inside the loop.

```CODE
import java.io.*;
import java.util.*;

public class d_496 {
    static final int N = 100100;
    static int[] arr = new int[N];
    static int[] s0 = new int[N + 1];
    static int[] s1 = new int[N + 1];
    static int[] p0 = new int[N];
    static int[] p1 = new int[N];
    static int cnt0, cnt1;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        // Read n
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return;
            st = new StringTokenizer(line);
        }
        n = Integer.parseInt(st.nextToken());

        // Read array and build structures
        for (int i = 0; i < n; i++) {
            while (!st.hasMoreTokens()) {
                String line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            arr[i] = Integer.parseInt(st.nextToken());

            if (arr[i] == 1) {
                p0[cnt0++] = i;
            } else {
                p1[cnt1++] = i;
            }
            s0[i + 1] = s0[i] + (arr[i] == 1 ? 1 : 0);
            s1[i + 1] = s1[i] + (arr[i] == 2 ? 1 : 0);
        }

        // Logic
        ArrayList<int[]> ans = new ArrayList<>();

        for (int k = 1; k <= n; k++) {
            int t0 = 0;
            int t1 = 0;
            int flag = 0;
            int i = 0; // Re-declared inside loop to match C++ scope behavior (reset to 0)
            
            while (i < n) {
                int idx0 = s0[i] + k;
                int j0 = idx0 > cnt0 ? n + 1 : p0[idx0 - 1] + 1;

                int idx1 = s1[i] + k;
                int j1 = idx1 > cnt1 ? n + 1 : p1[idx1 - 1] + 1;

                if (Math.min(j0, j1) > n) {
                    break;
                }

                if (j0 < j1) {
                    i = j0;
                    t0++;
                    flag = 0;
                } else {
                    i = j1;
                    t1++;
                    flag = 1;
                }
            }

            // C++: if(t0==t1 || (t0<t1)^flag)
            // Java: (t0 == t1) || ((t0 < t1) ^ flag)
            // Since flag is int (0 or 1), we use != for logical XOR with boolean
            boolean cond1 = (t0 == t1);
            boolean cond2 = (t0 < t1);
            boolean cond3 = (cond2 != flag);

            if (cond1 || cond3) {
                ans.add(new int[]{Math.max(t0, t1), k});
            }
        }

        // Sort
        Collections.sort(ans, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) return a[0] - b[0];
                return a[1] - b[1];
            }
        });

        // Output
        StringBuilder sb = new StringBuilder();
        sb.append(ans.size()).append("\n");
        for (int[] pair : ans) {
            sb.append(pair[0]).append(" ").append(pair[1]).append("\n");
        }
        System.out.print(sb);
    }
}
```