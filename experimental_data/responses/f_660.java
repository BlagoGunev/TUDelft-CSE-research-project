Translate this C++ code to Java code. The main class name should be f_660. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
/*************************************************************************

	> File Name: 660F.cpp

	> Author: jiangyuzhu

	> Mail: 834138558@qq.com

	> Created Time: Mon 20 Jun 2016 10:25:40 AM CST

 ************************************************************************/



#include<iostream>

#include<cstdio>

#include<cstring>

#include<cmath>

#include<queue>

#include<stack>

using namespace std;

typedef pair<int, int>p;

typedef long long ll;

#define sa(n) scanf("%d", &(n))

#define sal(n) scanf("%lld", &(n))

const int maxn = 2e5 + 5, mod = 1e9 + 7, oo = 0x3f3f3f3f;

ll a[maxn], val[maxn], sum[maxn];

int q[maxn];

inline ll up(int a, int b)

{

	ll x1 = val[a] - a * sum[a];

	ll x2 = val[b] - b * sum[b];

	return x2 - x1;

}

inline ll down(int a, int b){return (ll)b - a;}

bool judge(int a, int i)

{

	ll x1 = val[q[a]] - q[a] * sum[q[a]];

	ll x2 = val[q[a + 1]] - q[a + 1] * sum[q[a + 1 ]];

	return x2 - x1 > -sum[i] * down(q[a], q[a + 1]);

}

int main (void)

{

	int n;sa(n);

	ll ans = 0;

	for(int i = 1; i <= n; i++){

		sal(a[i]);

		sum[i] = sum[i - 1] + a[i];

		val[i] = val[i - 1] + i * a[i];

		ans = max(ans, a[i]);

	}

	int rear = 0;

	int l, r;

	q[rear++] = 0;

	for(int i = 1; i <= n; i++){

		l = 0, r = rear - 1;

		int res = 0;

		while(l <= r){//[]

			int mid = l + r >> 1;

			if(judge(mid, i)) r = mid - 1, res = mid;

			else l = mid + 1;

		}

        ans = max(ans, val[i] - val[q[res]] - q[res] * (sum[i] - sum[q[res]]));

		while(rear > 1 && up(q[rear - 1], i) * down(q[rear - 2], q[rear - 1]) < up(q[rear - 2], q[rear - 1]) * down(q[rear - 1], i)) rear--;

		q[rear++] = i;

	}

	printf("%lld\n", ans);

	return 0;

}

Here is the plan for translating the C++ code to Java.

### Translation Plan

1.  **Namespace and Imports**:
    *   The C++ code uses `using namespace std;` and includes `<bits/stdc++.h>`. In Java, we do not have namespaces, so we will explicitly import the necessary classes (`java.util.Scanner` or `java.io.*` for input, and `java.lang.Math`).
    *   The code uses `long long` for `ll` type. In Java, this maps to `long`.

2.  **Input/Output**:
    *   C++ uses `scanf` and `printf`. Java will use `Scanner` from `java.util`.
    *   `sa(n)` corresponds to `n = sc.nextInt()`.
    *   `sal(n)` corresponds to `n = sc.nextLong()`.
    *   `printf("%lld\n", ans)` corresponds to `System.out.println(ans)`.

3.  **Data Structures**:
    *   The C++ code defines global arrays `a`, `val`, `sum`, and `q` with a size of `maxn` (200005).
    *   In Java, these will be instance variables of the class `f_660`.
    *   Since `a`, `val`, and `sum` are used as arrays, we will declare them as `long[]`.
    *   `q` is used as an array for the deque/stack logic.

4.  **Functions**:
    *   `up` and `down` are simple arithmetic functions. They will be translated into private static methods or instance methods.
    *   `judge` is a helper method. Since it depends on global arrays `val`, `sum`, and `q`, it will be an instance method accessing instance variables.

5.  **Main Logic**:
    *   The `main` function logic remains largely the same, with C++ specific syntax changes (e.g., `>> 1` becomes `/ 2`, `max` becomes `Math.max`).
    *   The loop structure and the two-pointer/maintaining convex hull logic (using `while` loops) are preserved.

6.  **Class Structure**:
    *   The class name will be `f_660`.
    *   Constants `maxn` and `mod` will be static final constants.

### Incremental Task Splitting

1.  **Setup**: Create class `f_660`, define constants, and declare array fields.
2.  **Input Methods**: Implement `up` and `down` helper methods.
3.  **Logic**: Translate the `main` method logic, specifically the binary search (`judge` function) and the deque maintenance logic.
4.  **IO**: Implement the `main` method to handle input reading and output printing.

### Java Code

```java
import java.util.Scanner;

public class f_660 {
    // Constants
    // maxn corresponds to 2e5 + 5
    private static final int maxn = 200005;
    // mod = 1e9 + 7 (though not explicitly used in calculations shown, kept for completeness)
    private static final long mod = 1000000007;
    // oo = 0x3f3f3f3f (not used in this snippet)

    // Arrays corresponding to C++ globals
    // a: long long
    private static long[] a = new long[maxn];
    // val: long long
    private static long[] val = new long[maxn];
    // sum: long long
    private static long[] sum = new long[maxn];
    // q: int
    private static int[] q = new int[maxn];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (!sc.hasNext()) return;
        
        int n = sc.nextInt();
        
        long ans = 0;
        
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextLong();
            sum[i] = sum[i - 1] + a[i];
            val[i] = val[i - 1] + i * a[i];
            ans = Math.max(ans, a[i]);
        }
        
        int rear = 0;
        int l, r;
        
        q[rear++] = 0;
        
        for (int i = 1; i <= n; i++) {
            l = 0;
            r = rear - 1;
            int res = 0;
            
            while (l <= r) { // Binary search
                int mid = (l + r) / 2;
                if (judge(mid, i)) {
                    r = mid - 1;
                    res = mid;
                } else {
                    l = mid + 1;
                }
            }
            
            ans = Math.max(ans, val[i] - val[q[res]] - q[res] * (sum[i] - sum[q[res]]));
            
            // Maintain the monotonic property of the deque (convex hull trick)
            // Logic: while (rear > 1 && up(q[rear-1], i) * down(q[rear-2], q[rear-1]) < up(q[rear-2], q[rear-1]) * down(q[rear-1], i)) rear--;
            // Note: In C++, up returns long long, down returns long long.
            // We must cast to long to avoid integer overflow before comparison if values are large, 
            // though in Java long is 64-bit, so direct multiplication is safer than C++ int.
            
            while (rear > 1) {
                long u1 = up(q[rear - 1], i);
                long u2 = up(q[rear - 2], q[rear - 1]);
                long d1 = down(q[rear - 2], q[rear - 1]);
                long d2 = down(q[rear - 1], i);
                
                if (u1 * d1 < u2 * d2) {
                    rear--;
                } else {
                    break;
                }
            }
            
            q[rear++] = i;
        }
        
        System.out.println(ans);
    }
    
    // Helper function up(a, b)
    private static long up(int a, int b) {
        long x1 = val[a] - a * sum[a];
        long x2 = val[b] - b * sum[b];
        return x2 - x1;
    }
    
    // Helper function down(a, b)
    private static long down(int a, int b) {
        return (long)b - a;
    }
    
    // Helper function judge(a, i)
    private static boolean judge(int a, int i) {
        // Note: In C++, q is accessed as q[a] and q[a+1].
        // In Java, we access q[a] and q[a+1].
        // Since q is 0-indexed in C++ (q[0]=0), and we pass index 'a' to judge, 
        // we assume q is valid up to index 'a+1'.
        // However, in C++, q is an array of ints.
        // The logic relies on q being populated such that q[a] and q[a+1] exist.
        // In the loop, we access q[res] where res comes from binary search on 0..rear-1.
        // We must ensure bounds.
        
        // In C++: int x1 = val[q[a]] - q[a] * sum[q[a]];
        // In Java:
        int idxA = q[a];
        int idxB = q[a + 1];
        
        long x1 = val[idxA] - idxA * sum[idxA];
        long x2 = val[idxB] - idxB * sum[idxB];
        
        return (x2 - x1) > -sum[i] * down(idxA, idxB);
    }
}
```