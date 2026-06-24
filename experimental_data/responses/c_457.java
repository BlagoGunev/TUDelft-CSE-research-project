Translate this C++ code to Java code. The main class name should be c_457. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define mod 1000000007
#define eps 1e-8
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; ++i)

vector<int> a[100005], p, q;
priority_queue<int> k;

int main()
{
    int n, x, b, ans = 0;
    cin >> n;
    REP(i,1,n) {
        scanf( "%d%d", &x, &b );
        if (x) a[x].push_back(b);
        ans += b;
    }
    REP(i,1,100000) if (a[i].size()) {
        sort(a[i].begin(), a[i].end());
        p.push_back(i);
    }
    int cnt = n, sum = ans;
    REP(i,1,n) {
        q.clear();
        if (p.size() == 0) break;
        for (int j = 0; j < p.size(); ++j) {
            sum -= a[p[j]].back(); --cnt;
            k.push(-a[p[j]].back());
            a[p[j]].pop_back();
            if (a[p[j]].size()) q.push_back(p[j]);
        }
        while (cnt <= i && k.size()) {
            sum += -k.top();
            ++cnt;
            k.pop();
        }
        if (cnt > i) ans = min(ans, sum);
        p.clear();
        for (int j = 0; j < q.size(); ++j) p.push_back(q[j]);
    }
    cout << ans << endl;
    return 0;
}

<think>

</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several language-specific differences:

1.  **Headers & Namespace**: Remove C++ headers (`#include ...`) and `using namespace std;`. Import necessary classes from `java.util` (Scanner, PriorityQueue, ArrayList, Collections, Arrays, List) and `java.math` if needed (though standard types suffice here).
2.  **Types**:
    *   `int` maps to `int`.
    *   `long long` (`LL`) maps to `long`.
    *   `unsigned long long` (`ULL`) maps to `long` (since Java `long` is signed but covers the range of positive `unsigned long long` up to $2^{63}-1$, which is sufficient for competitive programming unless bit manipulation is strictly required).
    *   `double` (`eps`) maps to `double`.
3.  **Input/Output**:
    *   `cin` / `cout` are replaced by `java.util.Scanner` and `System.out.println`.
    *   `scanf` is replaced by `Scanner.nextInt()`.
4.  **Data Structures**:
    *   `vector<int> a[100005]`: This is an array of vectors. In Java, this becomes an `ArrayList<Integer>[]` or `List<Integer>[]`. We must handle the type erasure by using raw types or suppressing warnings, or simply `ArrayList<ArrayList<Integer>>`. Given the fixed size and direct indexing in C++, `ArrayList<Integer>[]` is the most direct translation. Note that Java arrays of generics are unchecked, so we'll use `ArrayList<Integer>[]` and suppress the warning or cast.
    *   `priority_queue<int> k`: Becomes `PriorityQueue<Integer>`.
    *   `sort()`: Becomes `Collections.sort()`.
5.  **Macros**:
    *   `#define LL long long`: Replaced by direct usage of `long`.
    *   `#define REP(i,a,b)`: Replaced by a standard `for` loop.
    *   `#define MP`, `#define mod`, `#define eps`: Defined as `static final` constants or removed if unused (in this specific code, `mod` and `eps` are defined but not used in the logic provided, so they can be kept as constants or ignored). `MP` is unused.
6.  **Logic Flow**:
    *   The logic involving `vector`, `priority_queue`, and loops remains structurally identical, but syntax changes (e.g., `a[x].push_back(b)` becomes `a[x].add(b)`).
    *   `p` and `q` are `vector<int>`, so they become `ArrayList<Integer>`.
    *   `p.clear()` becomes `p.clear()`.
    *   `min` function: Java doesn't have a global `min` for primitives in `std`. We use `Math.min()`.
    *   `k.push(-val)`: Since `PriorityQueue` is a min-heap by default and we want a max-heap behavior (simulating C++ `priority_queue` which is a max-heap), we store negative values.
7.  **Class Structure**: Create a class `c_457` with a `main` method.

### Incremental Tasks
1.  Define constants (`mod`, `eps`, `MAX_N`).
2.  Declare global-like fields inside the class (static or instance variables).
3.  Implement `main` method.
4.  Implement input reading loop.
5.  Implement the first `REP` loop (sorting and collecting indices).
6.  Implement the main simulation loop.
7.  Implement output.

### Java Code

<CODE>
import java.util.*;
import java.io.*;

public class c_457 {
    // Constants defined in C++ macros
    static final int MAX_N = 100005;
    static final int mod = 1000000007;
    static final double eps = 1e-8;

    // Global variables equivalent to C++ globals
    // Using ArrayList array to simulate vector<int> a[100005]
    static ArrayList<Integer>[] a;
    static ArrayList<Integer> p;
    static ArrayList<Integer> q;
    static PriorityQueue<Integer> k;

    public static void main(String[] args) {
        // Initialize global structures
        a = new ArrayList[MAX_N];
        p = new ArrayList<>();
        q = new ArrayList<>();
        k = new PriorityQueue<>();

        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        
        int n = sc.nextInt();
        
        // Reset arrays if this was part of a larger system, but here we assume single run.
        // In C++, global arrays are zero-initialized. In Java, we must initialize lists.
        for (int i = 0; i < MAX_N; i++) {
            a[i] = new ArrayList<>();
        }

        int ans = 0;
        int x, b;

        // Read input and populate structure
        for (int i = 1; i <= n; i++) {
            if (sc.hasNextInt()) {
                x = sc.nextInt();
                b = sc.nextInt();
                if (x != 0) {
                    a[x].add(b);
                }
                ans += b;
            }
        }

        // Sort vectors and collect non-empty indices
        for (int i = 1; i <= 100000; i++) {
            if (!a[i].isEmpty()) {
                Collections.sort(a[i]);
                p.add(i);
            }
        }

        int cnt = n;
        int sum = ans;

        // Main simulation loop
        for (int i = 1; i <= n; i++) {
            q.clear();
            if (p.isEmpty()) break;

            // Process all available items
            for (int j = 0; j < p.size(); j++) {
                int idx = p.get(j);
                // In C++, back() gives the last element. In sorted list, it's the last added.
                // However, since we sort, the last element is the largest.
                // The C++ code does: sum -= a[p[j]].back();
                // This implies we are removing the largest element from the current set?
                // Wait, let's re-read C++ logic carefully.
                // sort(a[i].begin(), a[i].end()); -> Ascending order.
                // a[p[j]].back() -> The last element (largest).
                // sum -= a[p[j]].back(); -> Subtract largest.
                // k.push(-a[p[j]].back()); -> Push negative largest.
                // a[p[j]].pop_back(); -> Remove largest.
                
                int val = a[idx].get(a[idx].size() - 1);
                sum -= val;
                --cnt;
                k.add(-val); // Push negative to simulate max-heap behavior for min-heap structure
                a[idx].remove(a[idx].size() - 1); // Remove last element
                if (!a[idx].isEmpty()) {
                    q.add(idx);
                }
            }

            // Restore smallest elements until cnt <= i
            while (cnt <= i && !k.isEmpty()) {
                int restoredVal = -k.poll(); // Poll smallest (which is -largest original)
                sum += restoredVal;
                ++cnt;
            }

            if (cnt > i) {
                if (sum < ans) {
                    ans = sum;
                }
            }

            // Move remaining indices back to p
            p.clear();
            for (int j = 0; j < q.size(); j++) {
                p.add(q.get(j));
            }
        }

        System.out.println(ans);
    }
}
</CODE>