Translate this C++ code to Java code. The main class name should be e_722. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Mod
{
    static const auto P = int(1e9+7);
    int k;

    Mod() = default;
    Mod(const int k) : k(k) {}
};

Mod operator+(const Mod a, const Mod b) { return (a.k + b.k) % Mod::P; }
Mod operator-(const Mod a, const Mod b) { return (a.k - b.k + Mod::P) % Mod::P; }
Mod operator*(const Mod a, const Mod b) { return int((ll(a.k) * b.k) % Mod::P); }
Mod power(const Mod a, const int k)
{
    if (k == 0) return 1;
    else if (k%2 == 0) return power(a*a, k/2);
    else return a * power(a*a, k/2);
}
Mod inverse(const Mod a) { return power(a, Mod::P-2); }
Mod operator/(const Mod a, const Mod b) { return a * inverse(b); }
Mod& operator+=(Mod& a, const Mod b) { return a = a+b; }
Mod& operator-=(Mod& a, const Mod b) { return a = a-b; }

struct Point { int r, c; };
bool operator<(const Point p, const Point q)
{
    if (p.r != q.r) return p.r < q.r;
    else return p.c < q.c;
}

namespace lut
{
    vector<Mod> factorials, inverse_factorials;

    void precompute(const int max)
    {
        factorials.resize(max+1);
        factorials[0] = 1;
        for (auto i = 1; i <= max; i++)
            factorials[i] = factorials[i-1] * i;

        inverse_factorials.resize(max+1);
        inverse_factorials[max] = inverse(factorials[max]);
        for (auto i = max; i >= 1; i--)
            inverse_factorials[i-1] = i * inverse_factorials[i];
    }

    Mod binomial(const int n, const int k)
    {
        if (k < 0 || k > n) return 0;
        else return factorials[n] * inverse_factorials[k] * inverse_factorials[n-k];
    }

    Mod npaths(const Point a, const Point b)
    {
        const auto dr = b.r - a.r, dc = b.c - a.c;
        return binomial(dr+dc, dr);
    };
}

int main()
{
    int N, M, K, S;
    cin >> N >> M >> K >> S;

    lut::precompute(2*max(N, M));

    auto points = vector<Point>({{1, 1}});
    for (auto k = 0; k < K; k++)
    {
        int r, c; cin >> r >> c;
        points.push_back({r, c});
    }
    K++;
    sort(begin(points), end(points));

    auto remaining = vector<Mod>(K);
    for (auto k = 0; k < K; k++)
        remaining[k] = lut::npaths(points[k], {N, M});

    auto pre = new Mod[2001][2001];
    for (auto k1 = 0; k1 < K; k1++) for (auto k2 = 0; k2 < K; k2++)
        pre[k1][k2] = lut::npaths(points[k1], points[k2]);

    auto numerator = Mod(0);
    for (; S > 1; S -= S/2)
    {
        auto ways = vector<Mod>(K);
        for (auto k1 = K-1; k1 >= 0; k1--)
        {
            ways[k1] = remaining[k1];
            for (auto k2 = k1+1; k2 < K; k2++)
                ways[k1] -= pre[k1][k2] * ways[k2];
        }

        numerator += S * ways[0];

        for (auto k = 0; k < K; k++)
            remaining[k] -= ways[k];
    }
    numerator += remaining[0];

    const auto denominator = lut::npaths({1, 1}, {N, M});

    cout << (numerator/denominator).k << endl;
}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**:
    *   Replace `<bits/stdc++.h>` with specific standard headers (`iostream`, `vector`, `algorithm`, `cmath`).
    *   Replace `using namespace std;` with explicit qualification or selective usage to avoid ambiguity in Java.
    *   Remove C++ specific macros like `const auto`.

2.  **Data Types**:
    *   `long long` in C++ maps to `long` in Java (since Java `long` is 64-bit).
    *   The custom `Mod` struct will become a `class Mod` with a `static final int P`.
    *   C++ `int` maps to Java `int`.

3.  **Structures and Classes**:
    *   The `Mod` struct becomes a class with a constructor and static constants.
    *   The `Point` struct becomes a class implementing `Comparable<Point>` to handle the custom sorting logic (`operator<`).
    *   The `lut` namespace becomes a static inner class `LUT` (or a separate class with static methods) to encapsulate the factorial precomputation and binomial logic.

4.  **Operators**:
    *   C++ operator overloading (`+`, `-`, `*`, `/`, `+=`, `-=`, `power`, `inverse`) will be translated into static methods within the `Mod` class.
    *   The `power` function in C++ uses recursion; this will be preserved in Java.
    *   The `inverse` function uses Fermat's Little Theorem, which is valid in Java.

5.  **Main Logic**:
    *   `main` function remains the entry point.
    *   `vector` becomes `ArrayList` or `List`.
    *   `sort(begin, end)` becomes `Collections.sort()`.
    *   C++ raw arrays (`new Mod[...]`) are replaced with `Mod[][]` in Java.
    *   Range-based `for` loops (`for (auto x : list)`) are replaced with standard enhanced `for` loops (`for (Mod x : list)`).
    *   `cin` and `cout` are replaced with `Scanner` and `System.out.println`.

6.  **Incremental Tasks**:
    *   Define the `Mod` class.
    *   Define the `Point` class.
    *   Implement the `LUT` class (precompute, binomial, npaths).
    *   Implement the `main` method logic (input reading, point processing, DP calculation, output).

### Java Code

```java
import java.util.*;
import java.io.*;

public class e_722 {

    static class Mod {
        static final int P = 1000000007;
        int k;

        public Mod() {
            this.k = 0;
        }

        public Mod(int k) {
            this.k = k % P;
            if (this.k < 0) {
                this.k += P;
            }
        }

        public static Mod add(Mod a, Mod b) {
            Mod res = new Mod();
            res.k = (a.k + b.k) % Mod.P;
            return res;
        }

        public static Mod subtract(Mod a, Mod b) {
            Mod res = new Mod();
            res.k = (a.k - b.k + Mod.P) % Mod.P;
            return res;
        }

        public static Mod multiply(Mod a, Mod b) {
            Mod res = new Mod();
            res.k = (int) ((long) a.k * b.k % Mod.P);
            return res;
        }

        public static Mod power(Mod a, int exp) {
            if (exp == 0) return new Mod(1);
            if (exp % 2 == 0) {
                Mod baseSq = multiply(a, a);
                return power(baseSq, exp / 2);
            } else {
                Mod baseSq = multiply(a, a);
                return multiply(a, power(baseSq, exp / 2));
            }
        }

        public static Mod inverse(Mod a) {
            return power(a, Mod.P - 2);
        }

        public static Mod divide(Mod a, Mod b) {
            return multiply(a, inverse(b));
        }

        public Mod add(Mod b) {
            return add(this, b);
        }

        public Mod subtract(Mod b) {
            return subtract(this, b);
        }

        public Mod multiply(Mod b) {
            return multiply(this, b);
        }
        
        public Mod divide(Mod b) {
            return divide(this, b);
        }
    }

    static class Point implements Comparable<Point> {
        int r, c;

        public Point(int r, int c) {
            this.r = r;
            this.c = c;
        }

        @Override
        public int compareTo(Point other) {
            if (this.r != other.r) {
                return Integer.compare(this.r, other.r);
            }
            return Integer.compare(this.c, other.c);
        }
    }

    static class LUT {
        static List<Mod> factorials = new ArrayList<>();
        static List<Mod> inverseFactorials = new ArrayList<>();

        public static void precompute(int max) {
            factorials = new ArrayList<>(max + 1);
            inverseFactorials = new ArrayList<>(max + 1);
            
            for (int i = 0; i <= max; i++) {
                factorials.add(new Mod(1));
            }

            if (max >= 0) {
                factorials.get(0).k = 1;
            }

            for (int i = 1; i <= max; i++) {
                factorials.get(i) = Mod.multiply(factorials.get(i), new Mod(i));
            }

            if (max >= 0) {
                inverseFactorials.set(max, Mod.inverse(factorials.get(max)));
            }

            for (int i = max; i >= 1; i--) {
                Mod invNext = inverseFactorials.get(i);
                Mod invCurr = new Mod();
                invCurr.k = (int) ((long) (i * invNext.k) % Mod.P);
                inverseFactorials.set(i - 1, invCurr);
            }
        }

        public static Mod binomial(int n, int k) {
            if (k < 0 || k > n) {
                return new Mod(0);
            }
            // Ensure lists are large enough
            if (n >= factorials.size()) {
                throw new IllegalArgumentException("Precompute limit exceeded");
            }
            Mod res = Mod.multiply(factorials.get(n), inverseFactorials.get(k));
            res = Mod.multiply(res, inverseFactorials.get(n - k));
            return res;
        }

        public static Mod npaths(Point a, Point b) {
            int dr = b.r - a.r;
            int dc = b.c - a.c;
            return binomial(dr + dc, dr);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        int S = sc.nextInt();
        sc.close();

        LUT.precompute(2 * Math.max(N, M));

        List<Point> points = new ArrayList<>();
        points.add(new Point(1, 1));
        
        for (int k = 0; k < K; k++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            points.add(new Point(r, c));
        }
        K++; // Include the target point (N, M) as the K-th point
        Collections.sort(points);

        // remaining[k] stores the number of paths from points[k] to (N, M)
        List<Mod> remaining = new ArrayList<>(Collections.nCopies(K, new Mod(0)));
        for (int k = 0; k < K; k++) {
            remaining.set(k, LUT.npaths(points.get(k), new Point(N, M)));
        }

        // pre[k1][k2] stores the number of paths from points[k1] to points[k2]
        Mod[][] pre = new Mod[K][K];
        for (int k1 = 0; k1 < K; k1++) {
            for (int k2 = 0; k2 < K; k2++) {
                pre[k1][k2] = LUT.npaths(points.get(k1), points.get(k2));
            }
        }

        Mod numerator = new Mod(0);
        
        // Calculate the numerator using the inclusion-exclusion principle logic
        // Iterating while S > 1. S is reduced by S/2 (equivalent to S >>= 1)
        // However, the loop condition and body suggest a specific summation pattern.
        // The original C++ loop: for (; S > 1; S -= S/2)
        // This loop runs as long as S > 1.
        
        while (S > 1) {
            List<Mod> ways = new ArrayList<>(Collections.nCopies(K, new Mod(0)));
            
            for (int k1 = K - 1; k1 >= 0; k1--) {
                ways.set(k1, remaining.get(k1));
                for (int k2 = k1 + 1; k2 < K; k2++) {
                    Mod term = Mod.multiply(pre[k1][k2], ways.get(k2));
                    ways.set(k1, ways.get(k1).subtract(term));
                }
            }

            // Add S * ways[0] to numerator
            // Note: In C++, 'S' is int. Here we multiply Mod by int.
            Mod term = new Mod(S); 
            term = Mod.multiply(term, ways.get(0));
            numerator = numerator.add(term);

            // Update remaining
            for (int k = 0; k < K; k++) {
                remaining.set(k, remaining.get(k).subtract(ways.get(k)));
            }
            
            S -= S / 2;
        }

        numerator = numerator.add(remaining.get(0));

        Mod denominator = LUT.npaths(new Point(1, 1), new Point(N, M));
        
        Mod result = Mod.divide(numerator, denominator);
        System.out.println(result.k);
    }
}
```

<CODE>
import java.util.*;
import java.io.*;

public class e_722 {

    static class Mod {
        static final int P = 1000000007;
        int k;

        public Mod() {
            this.k = 0;
        }

        public Mod(int k) {
            this.k = k % P;
            if (this.k < 0) {
                this.k += P;
            }
        }

        public static Mod add(Mod a, Mod b) {
            Mod res = new Mod();
            res.k = (a.k + b.k) % Mod.P;
            return res;
        }

        public static Mod subtract(Mod a, Mod b) {
            Mod res = new Mod();
            res.k = (a.k - b.k + Mod.P) % Mod.P;
            return res;
        }

        public static Mod multiply(Mod a, Mod b) {
            Mod res = new Mod();
            res.k = (int) ((long) a.k * b.k % Mod.P);
            return res;
        }

        public static Mod power(Mod a, int exp) {
            if (exp == 0) return new Mod(1);
            if (exp % 2 == 0) {
                Mod baseSq = multiply(a, a);
                return power(baseSq, exp / 2);
            } else {
                Mod baseSq = multiply(a, a);
                return multiply(a, power(baseSq, exp / 2));
            }
        }

        public static Mod inverse(Mod a) {
            return power(a, Mod.P - 2);
        }

        public static Mod divide(Mod a, Mod b) {
            return multiply(a, inverse(b));
        }

        public Mod add(Mod b) {
            return add(this, b);
        }

        public Mod subtract(Mod b) {
            return subtract(this, b);
        }

        public Mod multiply(Mod b) {
            return multiply(this, b);
        }
        
        public Mod divide(Mod b) {
            return divide(this, b);
        }
    }

    static class Point implements Comparable<Point> {
        int r, c;

        public Point(int r, int c) {
            this.r = r;
            this.c = c;
        }

        @Override
        public int compareTo(Point other) {
            if (this.r != other.r) {
                return Integer.compare(this.r, other.r);
            }
            return Integer.compare(this.c, other.c);
        }
    }

    static class LUT {
        static List<Mod> factorials = new ArrayList<>();
        static List<Mod> inverseFactorials = new ArrayList<>();

        public static void precompute(int max) {
            factorials = new ArrayList<>(max + 1);
            inverseFactorials = new ArrayList<>(max + 1);
            
            for (int i = 0; i <= max; i++) {
                factorials.add(new Mod(1));
            }

            if (max >= 0) {
                factorials.get(0).k = 1;
            }

            for (int i = 1; i <= max; i++) {
                factorials.get(i) = Mod.multiply(factorials.get(i), new Mod(i));
            }

            if (max >= 0) {
                inverseFactorials.set(max, Mod.inverse(factorials.get(max)));
            }

            for (int i = max; i >= 1; i--) {
                Mod invNext = inverseFactorials.get(i);
                Mod invCurr = new Mod();
                invCurr.k = (int) ((long) (i * invNext.k) % Mod.P);
                inverseFactorials.set(i - 1, invCurr);
            }
        }

        public static Mod binomial(int n, int k) {
            if (k < 0 || k > n) {
                return new Mod(0);
            }
            // Ensure lists are large enough
            if (n >= factorials.size()) {
                throw new IllegalArgumentException("Precompute limit exceeded");
            }
            Mod res = Mod.multiply(factorials.get(n), inverseFactorials.get(k));
            res = Mod.multiply(res, inverseFactorials.get(n - k));
            return res;
        }

        public static Mod npaths(Point a, Point b) {
            int dr = b.r - a.r;
            int dc = b.c - a.c;
            return binomial(dr + dc, dr);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        int S = sc.nextInt();
        sc.close();

        LUT.precompute(2 * Math.max(N, M));

        List<Point> points = new ArrayList<>();
        points.add(new Point(1, 1));
        
        for (int k = 0; k < K; k++) {
            int r = sc.nextInt();
            int c = sc.nextInt();
            points.add(new Point(r, c));
        }
        K++; // Include the target point (N, M) as the K-th point
        Collections.sort(points);

        // remaining[k] stores the number of paths from points[k] to (N, M)
        List<Mod> remaining = new ArrayList<>(Collections.nCopies(K, new Mod(0)));
        for (int k = 0; k < K; k++) {
            remaining.set(k, LUT.npaths(points.get(k), new Point(N, M)));
        }

        // pre[k1][k2] stores the number of paths from points[k1] to points[k2]
        Mod[][] pre = new Mod[K][K];
        for (int k1 = 0; k1 < K; k1++) {
            for (int k2 = 0; k2 < K; k2++) {
                pre[k1][k2] = LUT.npaths(points.get(k1), points.get(k2));
            }
        }

        Mod numerator = new Mod(0);
        
        // Calculate the numerator using the inclusion-exclusion principle logic
        // Iterating while S > 1. S is reduced by S/2 (equivalent to S >>= 1)
        // However, the loop condition and body suggest a specific summation pattern.
        // The original C++ loop: for (; S > 1; S -= S/2)
        // This loop runs as long as S > 1.
        
        while (S > 1) {
            List<Mod> ways = new ArrayList<>(Collections.nCopies(K, new Mod(0)));
            
            for (int k1 = K - 1; k1 >= 0; k1--) {
                ways.set(k1, remaining.get(k1));
                for (int k2 = k1 + 1; k2 < K; k2++) {
                    Mod term = Mod.multiply(pre[k1][k2], ways.get(k2));
                    ways.set(k1, ways.get(k1).subtract(term));
                }
            }

            // Add S * ways[0] to numerator
            // Note: In C++, 'S' is int. Here we multiply Mod by int.
            Mod term = new Mod(S); 
            term = term.multiply(ways.get(0));
            numerator = numerator.add(term);

            // Update remaining
            for (int k = 0; k < K; k++) {
                remaining.set(k, remaining.get(k).subtract(ways.get(k)));
            }
            
            S -= S / 2;
        }

        numerator = numerator.add(remaining.get(0));

        Mod denominator = LUT.npaths(new Point(1, 1), new Point(N, M));
        
        Mod result = Mod.divide(numerator, denominator);
        System.out.println(result.k);
    }
}
</CODE>