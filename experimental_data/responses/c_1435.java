Translate this C++ code to Java code. The main class name should be c_1435. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
/*
Problem : 
Algorithm : 
Status : 
*/
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define DEBUG cerr << "Passing Line " << __LINE__<< " in Function [" << __FUNCTION__ << "].\n";
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll llINF = 1e18;
const int MAXN = 1e5 + 5;
const int MAXM = 10;
const int m = 6;

int n;
int a[MAXN],b[MAXN],suf[MAXN];
pii c[MAXN];

int main(){
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    for(int i = 1;i <= m;i++)
        scanf("%d",&a[i]);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&b[i]);
    sort(a + 1,a + 1 + m);
    sort(b + 1,b + 1 + n);
    for(int i = 2;i <= m;i++)
        a[i] -= a[1];
    a[1] = 0;
    for(int i = 2;i <= n;i++)
        b[i] -= b[1];
    b[1] = 0;
    for(int i = 1;i <= n;i++){
        int x = upper_bound(a + 1,a + 1 + m,b[i]) - a - 1;
        c[i].first = b[i] - a[x];
        x = lower_bound(a + 1,a + 1 + m,b[i]) - a;
        if(x == m + 1)
            c[i].second = -INF;
        else
            c[i].second = b[i] - a[x];
    }
    sort(c + 1,c + 1 + n);
    int ans = INF;
    suf[n] = c[n].second;
    for(int i = n - 1;i >= 1;i--)
        suf[i] = min(suf[i + 1],c[i].second);
    for(int i = 1;i <= n;i++)
        ans = min(ans,c[i].first - suf[i + 1]);
    printf("%d\n",ans);
    return 0;
}

<think>

</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several differences between the two languages:

1.  **Headers and Namespaces**: C++ uses `#include` directives and the `using namespace std;` directive. In Java, we must explicitly import classes like `java.util.Scanner`, `java.util.Arrays`, and `java.util.StringTokenizer` from the `java.util` package.
2.  **Input/Output**: C++ uses `scanf` and `printf` (from `<cstdio>`). Java uses `Scanner` or `BufferedReader` for input and `System.out.println` for output. Given the constraints implied by `MAXN = 1e5`, `Scanner` might be slow, but for a direct translation of logic, `Scanner` is sufficient and easier to read. However, to ensure performance matches the C++ intent (which often implies competitive programming constraints), I will use a standard `Scanner` but keep the logic identical. If the problem requires strict IO performance, a `BufferedReader` + `StringTokenizer` approach is usually preferred, but I will stick to `Scanner` for clarity unless the logic suggests otherwise. *Correction*: Looking at the logic, it's $O(N \log N)$ or $O(N \log M)$, which is fine for `Scanner` in Java for $N=10^5$.
3.  **Data Types**:
    *   C++: `int` (usually 32-bit), `long long` (64-bit).
    *   Java: `int` (32-bit), `long` (64-bit). The constant `llINF` is `1e18`, so we must use `long` in Java. `INF` is `0x3f3f3f3f`, which fits in `int`.
4.  **Structs**: C++ uses `struct` or `pair` (`pii`). Java does not have built-in structs for pairs in the same way. We will create a simple static inner class `Pair` or just use two separate arrays (`first` and `second`) to store the values of `c[i]`. Using separate arrays is often more efficient and idiomatic in Java for competitive programming when accessing elements by index.
5.  **Constants**: `MAXN`, `INF`, `llINF`, etc., are defined globally in C++. In Java, we can define them as `static final` constants in the main class.
6.  **Main Method**: C++ `int main()` becomes Java `public static void main(String[] args)`.
7.  **Pointers and Arrays**: C++ arrays are pointers. Java arrays are objects. `a + 1` in C++ corresponds to `Arrays.copyOfRange(a, 1, ...)` or simply iterating with 1-based indexing if we allocate size `N+1`. To match the C++ logic exactly (which uses 1-based indexing `1` to `m`), we will allocate arrays of size `MAXN + 1` and ignore index 0.
8.  **Algorithms**: `sort` in C++ becomes `Arrays.sort()`. `upper_bound` and `lower_bound` are manual binary searches in C++ (using `std::upper_bound` on iterators). In Java, we must implement these manually since `Arrays.binarySearch` only finds exact matches or returns insertion points for missing ones, but standard library doesn't have direct `upper_bound` for custom ranges in the same way. We will implement helper methods `upperBound` and `lowerBound`.
9.  **File I/O**: The commented lines `freopen` are ignored as they are not active in the original code.

### Incremental Tasks
1.  Define constants (`MAXN`, `INF`, `llINF`, `m`).
2.  Define the `main` method and set up input reading using `Scanner`.
3.  Read arrays `a` and `b`.
4.  Sort arrays `a` and `b`.
5.  Normalize arrays `a` and `b` (subtract `a[1]` and `b[1]`).
6.  Compute the `c` array (pairs) using binary search logic.
7.  Sort the `c` array (by first element).
8.  Compute the suffix minimums (`suf`).
9.  Compute the final answer and print it.

### Java Code

<CODE>
import java.util.Scanner;
import java.util.Arrays;

public class c_1435 {
    // Constants
    static final int INF = 0x3f3f3f3f;
    static final long llINF = 1e18;
    static final int MAXN = 100005; // 1e5 + 5
    static final int m = 6;

    // Global arrays to match C++ structure (1-based indexing)
    static int[] a = new int[MAXN];
    static int[] b = new int[MAXN];
    static int[] cFirst = new int[MAXN]; // Stores first element of pair c
    static int[] cSecond = new int[MAXN]; // Stores second element of pair c
    static int[] suf = new int[MAXN];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Reading array a (size m)
        for (int i = 1; i <= m; i++) {
            a[i] = sc.nextInt();
        }

        // Reading n
        int n = sc.nextInt();

        // Reading array b (size n)
        for (int i = 1; i <= n; i++) {
            b[i] = sc.nextInt();
        }

        // Sort arrays a and b
        Arrays.sort(a, 1, m + 1);
        Arrays.sort(b, 1, n + 1);

        // Normalize array a: subtract a[1] from all elements
        for (int i = 2; i <= m; i++) {
            a[i] -= a[1];
        }
        a[1] = 0;

        // Normalize array b: subtract b[1] from all elements
        for (int i = 2; i <= n; i++) {
            b[i] -= b[1];
        }
        b[1] = 0;

        // Compute pair c[i] for each element in b
        // c[i].first = b[i] - element in a strictly greater than b[i] (closest)
        // c[i].second = b[i] - element in a >= b[i] (closest)
        for (int i = 1; i <= n; i++) {
            // Upper Bound: first element in a > b[i]
            int idxUpper = upperBound(a, b[i]);
            // In C++: upper_bound(...) - a - 1
            // If idxUpper is 0 (all elements <= b[i]), then in C++ logic it would be 0.
            // Wait, C++ logic: upper_bound returns iterator. index = iterator - begin - 1.
            // Let's re-verify C++ logic:
            // int x = upper_bound(a + 1, ..., b[i]) - a - 1;
            // In Java 0-based array logic for 1-based C++ array:
            // C++ array 'a' is 1-based. upper_bound finds first element > val.
            // If no element > val, upper_bound returns end (index m+1).
            // x = (m+1) - 1 = m.
            // If element at k is > val, upper_bound returns k.
            // x = k - 1.
            
            // Let's implement a custom upperBound that returns the index in 1-based array
            // or m+1 if not found.
            int posUpper = upperBound1Based(a, b[i]);
            if (posUpper == 0) {
                // No element > b[i] found? 
                // Actually, if b[i] is max, upper bound is m+1.
                // If b[i] is smaller than min(a), upper bound is 1.
                // Let's stick to the C++ logic directly.
                // C++: x = upper_bound(...) - a - 1.
                // If upper_bound returns iterator to a[1], index is 1. x = 1-1 = 0.
                // If upper_bound returns iterator to a[m+1] (end), index is m+1. x = m.
                
                // My helper upperBound1Based should return the index of the first element > val.
                // If not found, return m + 1.
                // Then x = posUpper - 1.
                int x = posUpper - 1;
                cFirst[i] = b[i] - a[x];
            } else {
                // Found element > val
                // If posUpper is 1, x = 0. But a[0] is 0? No, a is 1-based.
                // If posUpper is 1, it means a[1] > b[i]. Then x = 0.
                // But in C++, if x=0, accessing a[0] might be invalid if not initialized?
                // In C++ code: a[1] is 0. But loop starts i=2.
                // Wait, C++ code:
                // int x = upper_bound(...) - a - 1;
                // if x=0, c[i].first = b[i] - a[0].
                // Is a[0] used? In C++, a is declared size MAXN. a[0] is 0 by default.
                // So if b[i] < a[1], x becomes 0. c[i].first = b[i] - 0.
                
                // Let's implement strictly following C++ logic.
                // upper_bound returns index 'k' such that a[k] > val.
                // If all a[i] <= val, it returns m+1.
                // x = k - 1.
                
                // My helper: returns index k (1-based) of first element > val.
                // If none, returns m+1.
                int k = upperBound1Based(a, b[i]);
                int x = k - 1;
                cFirst[i] = b[i] - a[x];
            }

            // Lower Bound: first element in a >= b[i]
            // C++: x = lower_bound(...) - a;
            // If lower_bound returns iterator to a[m+1] (end), x = m+1.
            // Else x = index.
            int kLower = lowerBound1Based(a, b[i]);
            if (kLower == m + 1) {
                cSecond[i] = -INF;
            } else {
                cSecond[i] = b[i] - a[kLower];
            }
        }

        // Sort c array based on first element
        // We need to sort pairs. We can sort an array of indices or create a custom comparator.
        // Since we have parallel arrays, let's create an Integer array of indices and sort them.
        Integer[] indices = new Integer[n];
        for(int i = 1; i <= n; i++) indices[i-1] = i;
        Arrays.sort(indices, (i, j) -> Integer.compare(cFirst[i], cFirst[j]));

        // Reorder cFirst and cSecond based on sorted indices
        for (int i = 0; i < n; i++) {
            int idx = indices[i];
            cFirst[i + 1] = cFirst[idx];
            cSecond[i + 1] = cSecond[idx];
        }

        // Compute suffix minimums
        // suf[n] = c[n].second
        // suf[i] = min(suf[i+1], c[i].second)
        suf[n] = cSecond[n];
        for (int i = n - 1; i >= 1; i--) {
            suf[i] = Math.min(suf[i + 1], cSecond[i]);
        }

        // Compute answer
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            // ans = min(ans, c[i].first - suf[i+1])
            // Note: suf[n+1] is not defined in C++ code, but loop goes to n.
            // Wait, C++ code: suf[i+1]. When i=n, it accesses suf[n+1].
            // In C++, suf is size MAXN. suf[n+1] is 0.
            // But logic: min(INF, ... - 0).
            // However, usually suf array is sized N+2 or similar.
            // Let's assume suf[n+1] is 0 (default int value).
            // But wait, if suf[i+1] is accessed when i=n, we need to handle boundary.
            // In C++: int suf[MAXN]. suf[n+1] is 0.
            // So ans = min(ans, c[i].first - suf[i+1]).
            // If i=n, suf[n+1] is 0.
            
            // Let's ensure suf array is large enough.
            // We need to access up to n+1.
            // In my Java code above, suf is size MAXN.
            // I will resize or handle the index n+1 carefully.
            // Actually, in the loop `for(int i = n - 1; i >= 1; i--)`, suf[1] depends on suf[2].
            // Then loop `for(int i = 1; i <= n; i++)`, ans uses `suf[i+1]`.
            // When i=n, it uses `suf[n+1]`.
            // Since Java arrays are 0-indexed and initialized to 0, we need to make sure suf has size n+2.
            
            // Re-initializing suf size to be safe (n+2)
            // But since n is variable, we can't declare static final size easily if n varies.
            // But n <= MAXN. So MAXN+2 is safe.
            // Let's just use MAXN+5.
        }
        
        // Re-declare suf with sufficient size for safety (n+1 access)
        // Since n is read at runtime, we can't declare static final size based on n.
        // But we know n <= 100005. So MAXN + 5 is safe.
        // I will re-declare suf here or just ensure the array is big enough.
        // Actually, in the previous block I declared `static final int MAXN = 100005;`
        // And `int[] suf = new int[MAXN];`.
        // If n = 100005, accessing `suf[n+1]` (index 100006) throws IndexOutOfBounds.
        // I must increase the size of `suf`.
        
        // Let's fix the array size logic.
        // I will redefine suf after reading n or just make it larger.
        // Let's just make it MAXN + 10.
        // But `MAXN` is static final.
        // I'll change `MAXN` to `100010` to be safe for n+1.
        // Or better, allocate suf based on n.
        // Let's refactor slightly to allocate suf after reading n.
        
        // Re-computation with correct array sizing
        // (We will re-run the logic with corrected array allocation)
        
        // Re-reading logic for clarity in final code:
        // 1. Read n.
        // 2. Allocate suf = new int[n + 2];
        // 3. Fill suf[n] and loop down to 1.
        // 4. Loop 1 to n, access suf[i+1].
        
        // Note: The previous block in thought process had `static final int MAXN`.
        // To avoid IndexOutOfBoundsException, I will allocate `suf` dynamically after reading `n`.
    }
    
    // Helper to find first index (1-based) where a[idx] > val
    // Returns m + 1 if no such element exists
    static int upperBound1Based(int[] a, int val) {
        int low = 1;
        int high = a.length - 1; // a.length is MAXN, so max index is MAXN-1.
        // But we only care up to m.
        // The C++ code sorts a[1...m]. So we search in 1 to m.
        // My array 'a' is 1-based up to m.
        // Let's search in range [1, m].
        int limit = m;
        
        // Binary search for first element > val
        int ans = limit + 1; // Default if not found
        int l = 1, r = limit;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] > val) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    // Helper to find first index (1-based) where a[idx] >= val
    static int lowerBound1Based(int[] a, int val) {
        int ans = m + 1; // Default if not found
        int l = 1, r = m;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid] >= val) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}
</CODE>

Wait, I need to make sure the code is a single coherent block and fixes the array size issue.
Refining the plan:
1. Keep `MAXN` as `100005`.
2. In `main`, after reading `n`, allocate `suf` as `new int[n + 2]`.
3. Ensure `cFirst` and `cSecond` are large enough (size `n+1`).
4. Implement `upperBound` and `lowerBound` carefully to match C++ `upper_bound` and `lower_bound` behavior on the 1-based sorted array `a`.

Corrected Logic for Bounds:
C++: `sort(a + 1, a + 1 + m)`.
`upper_bound` on `a` (range `1` to `m`) returns iterator to first element `> val`.
If all `a[1..m] <= val`, it returns `a + 1 + m` (iterator after last element).
Index calculation: `it - a - 1`.
If iterator is `a + 1 + m`, index is `m`.
If iterator is `a + 1`, index is `0`.
So if `upperBound` returns index `k` (where `k` is 1-based index in `a`), then `x = k - 1`.
If `k` is `m + 1` (meaning no element found > val, i.e., all `a` are `<= val`), then `x = m`.
Wait, C++: `upper_bound` returns iterator.
If `a = {0, 10, 20}`, `val = 5`. `upper_bound` finds `10` (index 2). `x = 2 - 1 = 1`. `c.first = 5 - a[1] = 5 - 0 = 5`.
If `val = 25`. `upper_bound` finds end (index 3). `x = 3 - 1 = 2`. `c.first = 25 - a[2] = 25 - 20 = 5`.
If `val = -1`. `upper_bound` finds `0` (index 1). `x = 1 - 1 = 0`. `c.first = -1 - a[0]`. `a[0]` is 0. `c.first = -1`.

So my helper `upperBound1Based` returning the 1-based index of the first element `> val` works perfectly. If not found, it returns `m + 1`.
Then `x = returned_index - 1`.

Same for `lower_bound`:
C++: `lower_bound` finds first element `>= val`.
If `a = {0, 10, 20}`, `val = 5`. `lower_bound` finds `10` (index 2). `x = 2`. `c.second = 5 - 10 = -5`.
If `val = 0`. `lower_bound` finds `0` (index 1). `x = 1`. `c.second = 0 - 0 = 0`.
If `val = 25`. `lower_bound` finds end (index 3). `x = 3`. `c.second = -INF`.

So `lowerBound1Based` returning the 1-based index of the first element `>= val` works. If not found, return `m + 1`.

Final check on `suf` array size.
C++: `suf` is `int suf[MAXN]`.
`n` is read. `n` can be up to `MAXN-5`.
Loop `i` from `n-1` down to `1`. `suf[i]` uses `suf[i+1]`.
Loop `i` from `1` to `n`. `ans` uses `suf[i+1]`.
When `i=n`, it accesses `suf[n+1]`.
Since `MAXN` is `100005`, and `n` is input, we must ensure `suf` has size at least `n+2`.
I will allocate `suf` dynamically as `new int[n + 2]` inside `main`.

<CODE>
import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

public class c_1435 {
    // Constants matching C++
    static final int INF = 0x3f3f3f3f;
    static final long llINF = 1e18;
    static final int MAXN = 100005; // 1e5 + 5
    static final int m = 6;

    // Global arrays to match C++ structure (1-based indexing)
    static int[] a = new int[MAXN];
    static int[] b = new int[MAXN];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Reading array a (size m)
        for (int i = 1; i <= m; i++) {
            a[i] = sc.nextInt();
        }

        // Reading n
        int n = sc.nextInt();

        // Reading array b (size n)
        for (int i = 1; i <= n; i++) {
            b[i] = sc.nextInt();
        }

        // Sort arrays a and b
        // C++: sort(a + 1, a + 1 + m);
        Arrays.sort(a, 1, m + 1);
        Arrays.sort(b, 1, n + 1);

        // Normalize array a: subtract a[1] from all elements
        for (int i = 2; i <= m; i++) {
            a[i] -= a[1];
        }
        a[1] = 0;

        // Normalize array b: subtract b[1] from all elements
        for (int i = 2; i <= n; i++) {
            b[i] -= b[1];
        }
        b[1] = 0;

        // Arrays to store pairs c[i].first and c[i].second
        // Size n + 1 for 1-based indexing
        int[] cFirst = new int[n + 1];
        int[] cSecond = new int[n + 1];

        // Compute pair c[i] for each element in b
        for (int i = 1; i <= n; i++) {
            // Upper Bound: first element in a > b[i]
            // Logic: find index k such that a[k] > b[i]. If none, k = m + 1.
            // Then x = k - 1.
            int k = upperBound1Based(a, b[i]);
            int x = k - 1;
            cFirst[i] = b[i] - a[x];

            // Lower Bound: first element in a >= b[i]
            // Logic: find index k such that a[k] >= b[i]. If none, k = m + 1.
            // Then x = k.
            int kLower = lowerBound1Based(a, b[i]);
            if (kLower == m + 1) {
                cSecond[i] = -INF;
            } else {
                cSecond[i] = b[i] - a[kLower];
            }
        }

        // Sort c array based on first element
        // We create an array of indices and sort them
        Integer[] indices = new Integer[n];
        for(int i = 1; i <= n; i++) {
            indices[i-1] = i;
        }
        Arrays.sort(indices, (i, j) -> Integer.compare(cFirst[i], cFirst[j]));

        // Reorder cFirst and cSecond based on sorted indices
        // Note: After sorting, we overwrite the arrays at positions 1 to n
        for (int i = 0; i < n; i++) {
            int idx = indices[i];
            cFirst[i + 1] = cFirst[idx];
            cSecond[i + 1] = cSecond[idx];
        }

        // Compute suffix minimums
        // suf[i] stores min(c[j].second) for j >= i
        // We need suf array of size n + 2 to handle i+1 when i=n
        int[] suf = new int[n + 2];
        
        // suf[n] = c[n].second
        suf[n] = cSecond[n];
        
        // Fill backwards
        for (int i = n - 1; i >= 1; i--) {
            suf[i] = Math.min(suf[i + 1], cSecond[i]);
        }

        // Compute answer
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            // ans = min(ans, c[i].first - suf[i+1])
            // When i=n, suf[n+1] is 0 (default int value), which matches C++ behavior if not initialized
            int diff = cFirst[i] - suf[i + 1];
            if (diff < ans) {
                ans = diff;
            }
        }

        System.out.println(ans);
    }
    
    // Helper to find first index (1-based) where a[idx] > val
    // Returns m + 1 if no such element exists in a[1...m]
    static int upperBound1Based(int[] a, int val) {
        int low = 1;
        int high = m; 
        int ans = m + 1; // Default if not found
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] > val) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    // Helper to find first index (1-based) where a[idx] >= val
    // Returns m + 1 if no such element exists in a[1...m]
    static int lowerBound1Based(int[] a, int val) {
        int low = 1;
        int high = m;
        int ans = m + 1; // Default if not found
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] >= val) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}
</CODE>