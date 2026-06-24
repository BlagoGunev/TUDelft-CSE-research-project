Translate this C++ code to Java code. The main class name should be b_1112. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    k = min(k, n);
    vector<pair<int, int> > order(k);
    int p = 0;
    for (p = 0; p < k; p++) {
        order[p] = make_pair(1, p);
    }

    int m = 0;
    int ans = 0;
    vector<bool> used(n);
    while (m < n) {
        double q = floor(100.0 * ((double)m / (double)(n)) + 0.5);
        for (int i = 0; i < k; i++) {
			if (order[i].first == -1) continue;
            if (order[i].first == q && !used[order[i].second]) {
                used[order[i].second] = true;
                ans++;
            }
        }
        for (int i = 0; i < k; i++) {
			if (order[i].first == -1) continue;
			if (a[order[i].second] == order[i].first) {
                m++;
                if (p < n) {
                    order[i] = make_pair(1, p++);
                }
				else {
					order[i] = make_pair(-1, -1);
				}
            }
            else {
                order[i].first++;
            }
        }
    }
    cout << ans;
}

Here is the plan for translating the C++ code to Java:

1.  **Header Inclusions**: C++ uses `#include` directives (iostream, random, algorithm, cmath). Java does not use these directly. Instead, we need to import the corresponding classes from the `java.util` package (`Scanner`, `System` for I/O, `Arrays` for utility methods). The `<cmath>` functions like `floor` and `min` need to be replaced by their Java equivalents (`Math.floor`, `Math.min`).
2.  **Namespace**: C++ uses `using namespace std;`. In Java, we do not have namespaces; we use fully qualified names or import statements. We will use `java.util.Scanner` and `java.util.Arrays` explicitly.
3.  **Main Method**: The `main` function in C++ is `int main()`. In Java, it must be `public static void main(String[] args)`.
4.  **I/O Optimization**: The C++ code uses `ios_base::sync_with_stdio(false);` and `cin.tie(0);` for performance. While Java's `Scanner` is generally slower, for standard competitive programming tasks, it is often sufficient unless strict timing constraints require `BufferedReader`. However, to stay true to the spirit of the optimization, we will stick to `Scanner` as it maps directly to `cin`, but we should be aware that for very large inputs, `BufferedReader` + `StringTokenizer` is preferred. Given the logic complexity, `Scanner` is the direct translation.
5.  **Data Structures**:
    *   `vector<int> a(n)` becomes `int[] a = new int[n]`.
    *   `vector<bool> used(n)` becomes `boolean[] used = new boolean[n]`.
    *   `vector<pair<int, int> > order(k)` becomes `int[][] order = new int[k][2]`.
6.  **Logic Translation**:
    *   `make_pair(x, y)` in C++ creates a pair object. In Java, we just assign values to `order[i][0]` and `order[i][1]`.
    *   `min(k, n)` becomes `Math.min(k, n)`.
    *   `floor(100.0 * ...)` becomes `(int)Math.floor(...)`. Note: Since the expression is multiplied by 100.0, casting the result to `int` effectively acts as `floor` for positive numbers.
    *   `cin >> var` becomes `sc.nextInt()` or `sc.nextLong()`.
    *   `cout << var` becomes `System.out.print(var)`.
7.  **Class Structure**: The code must be inside a class named `b_1112`.

**Incremental Tasks**:
1.  Define class `b_1112` with `main` method.
2.  Import `Scanner` and `Math`.
3.  Read input `n`, `k`.
4.  Read array `a`.
5.  Initialize `order` array.
6.  Implement the `while(m < n)` loop.
7.  Implement the inner `for` loops and logic inside the `while`.
8.  Print result.

<CODE>
import java.util.Scanner;

public class b_1112 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        k = Math.min(k, n);
        int[][] order = new int[k][2];
        int p = 0;
        for (int i = 0; i < k; i++) {
            order[i][0] = 1;
            order[i][1] = i;
        }

        int m = 0;
        int ans = 0;
        boolean[] used = new boolean[n];
        
        while (m < n) {
            // q = floor(100.0 * m / n + 0.5)
            // In integer arithmetic, (100 * m / n + 50) / 100 is equivalent to floor(100.0 * m / n + 0.5)
            // However, to be precise with the floating point logic provided:
            double qDouble = 100.0 * ((double)m / (double)(n)) + 0.5;
            int q = (int) Math.floor(qDouble);

            // First loop: Check usage and increment ans
            for (int i = 0; i < k; i++) {
                if (order[i][0] == -1) continue;
                if (order[i][0] == q && !used[order[i][1]]) {
                    used[order[i][1]] = true;
                    ans++;
                }
            }

            // Second loop: Update state
            for (int i = 0; i < k; i++) {
                if (order[i][0] == -1) continue;
                if (a[order[i][1]] == order[i][0]) {
                    m++;
                    if (p < n) {
                        order[i][0] = 1;
                        order[i][1] = p++;
                    } else {
                        order[i][0] = -1;
                        order[i][1] = -1;
                    }
                } else {
                    order[i][0]++;
                }
            }
        }

        System.out.print(ans);
    }
}
</CODE>