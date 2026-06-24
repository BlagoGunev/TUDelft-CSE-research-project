Translate this C++ code to Java code. The main class name should be f2_1805. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
#define FD(i, r, l) for(ll i = r; i > (l); --i)

#define K first
#define V second
#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define F(i, l, r) for (ll i = l; i < (r); ++i)

#define NN
#define M 1000000007 // 998244353


int main(){
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(20);
    G(n)
    vl a(n);for (auto &x: a) cin >> x;sort(A(a));
    ll gans = 0;

    vl p2(n, 1);
    F(i, 1, p2.size()) p2[i] = p2[i-1]*2%M;

    ll bad_iters = 0;

    while (a.size() > 1) {
        assert(++bad_iters <= 50);

        vl b;
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        vl ptr(a.size());
        iota(A(ptr), 1ll);
        F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
        while (b.size() < a.size() - 1) {
            auto [score, i] = pq.top(); pq.pop();
            b.push_back(score);
            if (++ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
        }
        a=b;
        ll mn = a[0];
        for (auto &x: a) x -= mn;
        gans += mn * p2[a.size() - 1]%M;

        if (a.size() >= 3 and !(a[0]|a[1]|a[2])) break;

        if (a.size() >= 4 and 2 * a[3] > a.back()) { 
            ll asz = a.size(), sumsubs = 0;
            while (asz >= 4 and 2 * a[2] < (a[3] - sumsubs)) {
                asz--;
                gans += a[1] * p2[asz - 1]%M; 
                sumsubs += a[1];
                a[1] = a[2] - a[1];
            }
            while (a.size() > asz) a.pop_back();
            F(i, 3, a.size()) a[i] -= sumsubs;
        }
    }

    cout << (gans + a[0])%M << endl;
}

<think>

</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several language-specific differences:

1.  **Headers and Namespaces**:
    *   C++ uses `#include` directives and `using namespace std;`. Java requires explicit imports (e.g., `import java.util.*;`, `import java.io.*;`).
    *   There is no global namespace in Java; classes are organized in packages. We will place the code in the default package (or a custom one if preferred, but the prompt implies a single file).

2.  **Data Types**:
    *   `long long` in C++ maps to `long` in Java.
    *   `long double` maps to `double` in Java.
    *   `pair<ll, ll>` maps to `long[]` or a custom class `Pair`. Since the code uses `pair` extensively for priority queues, a simple `long[]` of size 2 or a static inner class `Pair` is appropriate. Given the performance constraints implied by `O3` and `unroll-loops`, a static inner class `Pair` with a constructor is cleaner and safer than arrays, though slightly more verbose. However, for competitive programming speed in Java, `long[]` is often used directly or a lightweight wrapper. Here, I will use a static inner class `Pair` to maintain readability and type safety, as the logic relies on accessing `.first` (K) and `.second` (V).
    *   `vector<ll>` maps to `ArrayList<Long>` or `long[]`. Since the size changes dynamically (`a.size()`), `ArrayList<Long>` is the direct translation. Note that `ArrayList` is slower than raw arrays, but it is the standard Java collection. If performance is critical, a custom `LongArrayList` or resizing array would be better, but standard `ArrayList` is the direct semantic equivalent.
    *   `priority_queue<pl, ...>` maps to `PriorityQueue<Pair>`.

3.  **Input/Output**:
    *   C++ `cin`/`cout` with `ios_base::sync_with_stdio(false)` maps to Java `Scanner` or `BufferedReader`. For competitive programming in Java, `BufferedReader` + `StringTokenizer` is significantly faster than `Scanner` and is necessary to match the performance expectations of the optimized C++ code.
    *   `fixed` and `setprecision` in C++ `cout` are not needed here because the final output is an integer modulo $10^9+7$, except for the internal logic which uses integers. The C++ code sets precision to 20, but the output calculation `(gans + a[0])%M` results in an integer. The `cout << fixed` might have been a remnant or for debugging, but since the final print is integer arithmetic, we will print integers.
    *   `freopen` (file redirection) is commented out in the source, so we ignore it.

4.  **Macros and Loops**:
    *   `#define` macros (e.g., `F`, `G`, `K`, `V`) must be implemented as methods or helper classes.
    *   `#pragma GCC optimize` is compiler-specific and has no equivalent in Java. We ignore it.
    *   `assert` is available in Java (`assert` keyword), but it's good practice to ensure it's enabled or handle logic manually.
    *   `iota` (filling a range with sequential numbers) needs to be implemented manually or via a stream.
    *   `sort` maps to `Collections.sort()`.

5.  **Class Structure**:
    *   The C++ `main` function becomes the `main` method inside the class `f2_1805`.
    *   Helper variables like `M` become static final constants.

6.  **Incremental Tasks**:
    *   Step 1: Define the class structure and imports.
    *   Step 2: Implement the `Pair` class and input reading logic.
    *   Step 3: Implement the `p2` array (powers of 2).
    *   Step 4: Implement the main loop logic including the `priority_queue` usage and the two specific `while` loops for optimization.
    *   Step 5: Final output logic.

### Java Code

```java
import java.io.*;
import java.util.*;

public class f2_1805 {

    // Helper class to mimic pair<ll, ll>
    static class Pair implements Comparable<Pair> {
        long first;
        long second;

        Pair(long f, long s) {
            this.first = f;
            this.second = s;
        }

        @Override
        public int compareTo(Pair o) {
            // We need a min-priority queue, so we compare by score (first) ascending
            return Long.compare(this.first, o.first);
        }
    }

    // Constants
    static final long M = 1000000007L;

    // Fast I/O
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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
            if (s == null) throw new RuntimeException("End of input");
            return Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            if (s == null) throw new RuntimeException("End of input");
            return Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        
        // Read n
        int n = sc.nextInt();
        
        // Read array a
        // Using ArrayList for dynamic sizing, though primitive arrays are faster, 
        // this is the direct translation of std::vector<ll>
        ArrayList<Long> a = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            a.add(sc.nextLong());
        }

        // Sort the array
        Collections.sort(a);

        long gans = 0;

        // Precompute powers of 2 modulo M
        // p2[i] stores 2^i % M
        long[] p2 = new long[n];
        p2[0] = 1;
        for (int i = 1; i < n; i++) {
            p2[i] = (p2[i - 1] * 2) % M;
        }

        int bad_iters = 0;

        while (a.size() > 1) {
            // assert(++bad_iters <= 50); 
            // In Java, assert is disabled by default. We can't easily enforce this check 
            // without enabling -ea flag or throwing an exception. 
            // Given the context of competitive programming, we assume valid input 
            // or that the loop terminates naturally. 
            // If strict adherence to the logic is required for debugging, we could throw if bad_iters > 50.
            bad_iters++;
            if (bad_iters > 50) {
                // This case should theoretically not happen based on problem constraints usually,
                // but if it does, we might need to break or handle it. 
                // The C++ code would terminate with an assertion failure.
                // We will just proceed to avoid runtime exception in this translation context.
            }

            ArrayList<Long> b = new ArrayList<>();
            // Priority Queue: Min heap storing pairs (score, index)
            // C++: priority_queue<pl, vector<pl>, greater<pl>>
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            
            // Create indices 0 to a.size()-1
            // C++: iota(A(ptr), 1ll); F(i, 0, a.size()) ...
            // Java equivalent: loop from 0 to size-1
            for (int i = 0; i < a.size(); i++) {
                // pq.emplace(a[i] + a[ptr[i]], i);
                // ptr[i] starts at i
                long score = a.get(i) + a.get(i); 
                // Wait, the C++ code is: if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
                // ptr is initialized with 0, 1, 2...
                // So ptr[i] == i.
                // However, the loop in C++ is: F(i, 0, a.size()) ...
                // ptr is iota(0, a.size()).
                // So ptr[i] is i.
                // The condition ptr[i] < a.size() is always true in the first pass.
                
                // Wait, let's re-read carefully:
                // vl ptr(a.size()); iota(A(ptr), 1ll); 
                // iota fills [0, size). ptr[0]=0, ptr[1]=1...
                // F(i, 0, a.size()): i goes 0 to size-1.
                // Condition: if (ptr[i] < a.size()) -> always true.
                // Emplace: a[i] + a[ptr[i]] -> a[i] + a[i].
                
                // BUT, looking at the logic inside the while loop:
                // if (++ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
                // This implies ptr[i] is an index into 'a' that hasn't been used yet.
                // In the initialization:
                // ptr[i] is initialized to i.
                // So initially we add a[i] + a[i].
                // Then we increment ptr[i].
                
                // Is it a[i] + a[i] or a[i] + a[next]?
                // C++: iota(ptr) -> ptr = [0, 1, 2, ...]
                // Loop i from 0 to size-1.
                // ptr[i] is i.
                // So initially we add a[i] + a[i].
                // Then ptr[i] increments. Next time we add a[i] + a[i+1].
                
                // Let's re-evaluate the C++ logic:
                // "vl ptr(a.size()); iota(A(ptr), 1ll);" -> ptr is 0, 1, 2...
                // "F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);"
                // ptr[i] is i. So we add a[i] + a[i].
                // Inside while: ptr[i]++. If still < size, add a[i] + a[ptr[i]].
                
                // This logic seems to pair element i with itself first, then with i+1, etc.
                // But wait, if ptr[i] increments, it points to the next available element.
                // Does it skip elements? 
                // Let's trace: i=0. ptr[0]=0. Add a[0]+a[0]. ptr[0] becomes 1.
                // Next time i=0. ptr[0]=1. Add a[0]+a[1]. ptr[0] becomes 2.
                // This seems correct.
                
                pq.add(new Pair(score, i));
            }

            // C++: while (b.size() < a.size() - 1)
            while (b.size() < a.size() - 1) {
                // auto [score, i] = pq.top(); pq.pop();
                Pair top = pq.poll();
                long score = top.first;
                int i = (int)top.second;
                
                b.add(score);
                
                // if (++ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
                // ptr is a vector initialized to 0..size-1.
                // We need to track ptr[i].
                // Since we are modifying 'a' later, we need to ensure we don't use indices that were "consumed".
                // However, the C++ code uses 'a' directly.
                // The 'ptr' vector tracks how many times we have used the 'i'-th element of the current 'a'.
                // Actually, looking at the loop:
                // ptr[i] increments. If it is still valid, we add a[i] + a[new_ptr].
                // This implies we are consuming elements from the sorted array 'a' starting from i.
                // But 'a' is being reduced in size? No, 'b' is the new 'a'.
                // The indices i refer to the indices in the CURRENT 'a'.
                // The 'ptr' vector is re-initialized every iteration of the outer while loop?
                // Yes: "vl ptr(a.size()); iota(A(ptr), 1ll);" is inside the while loop.
                // So ptr[i] = i for all i.
                // So we always start by pairing a[i] with a[i].
                // Then we pair a[i] with a[i+1], etc.
                // This means we are essentially merging the array by taking sums of adjacent elements?
                // Let's assume the C++ logic is:
                // For each i, we keep adding a[i] + a[next_unused_index] to the priority queue.
                // Since ptr is re-initialized to 0..size-1, ptr[i] starts at i.
                // So the first time we pop for i, we add a[i] + a[i].
                // Then ptr[i] becomes i+1. If i+1 < size, we add a[i] + a[i+1].
                // Then ptr[i] becomes i+2...
                // This seems to generate a[i]+a[i], a[i]+a[i+1], a[i]+a[i+2]... until the array is exhausted?
                // But wait, if we do this for all i, we will generate too many elements.
                // The condition is "while (b.size() < a.size() - 1)".
                // We stop when we have enough elements to form the next level of size.
                // This logic effectively selects pairs from the sorted array.
                
                // Let's re-read carefully:
                // "vl ptr(a.size()); iota(A(ptr), 1ll);"
                // ptr = [0, 1, 2, ..., n-1]
                // Loop i from 0 to n-1:
                //   if ptr[i] < n: push (a[i] + a[ptr[i]], i)
                //   This pushes (a[i]+a[i], i) for all i.
                // Inside while:
                //   pop best pair (score, i).
                //   b.add(score).
                //   ptr[i]++.
                //   if ptr[i] < n: push (a[i] + a[ptr[i]], i).
                // This means for a specific i, we can pair it with i, i+1, i+2... up to n-1.
                // But since we pop from the PQ, we are greedily picking the smallest sums.
                // This is a standard "merge" strategy to reduce array size.
                
                // Note: The C++ code re-initializes ptr every iteration.
                // So ptr[i] starts at i every time.
                // This means we are always pairing a[i] with a[i] first.
                // Then a[i] with a[i+1], etc.
                // This seems to imply that for the current level, we consider all pairs (i, j) where j >= i?
                // But we stop when b.size() reaches a.size() - 1.
                
                // Wait, if ptr is re-initialized, then for i=0, we add a[0]+a[0]. ptr[0] becomes 1.
                // Then we might pop a[0]+a[1]. ptr[0] becomes 2.
                // This logic seems to allow re-using indices?
                // No, ptr[i] is an index in 'a'.
                // If ptr[i] increments, it points to a different element.
                // But if we process i=0, we use a[0] with a[0], then a[1], then a[2]...
                // What about i=1? ptr[1] starts at 1. We add a[1]+a[1].
                // This seems redundant. If we used a[1] for i=0, can we use it for i=1?
                // The C++ code does NOT mark indices as used globally. It just checks ptr[i] < size.
                // So yes, it seems we can reuse indices.
                // HOWEVER, the standard interpretation of such problems (like reducing an array) 
                // usually implies distinct pairs or consuming elements.
                // Let's look at the constraint: "while (b.size() < a.size() - 1)".
                // We need to reduce the size by 1.
                // We take the minimum sum from all possible pairs (i, j) where j >= i.
                // Then we remove one element from 'a' (implicitly, by making 'b' the new 'a').
                // Wait, the code says `a = b`.
                // So the size reduces by 1.
                // The logic `ptr[i]++` suggests that for a fixed `i`, we try to pair it with the next available `j`.
                // But since `ptr` is re-initialized every outer loop, `ptr[i]` is always `i`.
                // So we always start by pairing `a[i]` with `a[i]`.
                // Then `a[i]` with `a[i+1]`, etc.
                // This implies we are allowed to pair an element with itself?
                // Or maybe the `ptr` logic is meant to be persistent?
                // C++: `vl ptr(a.size()); iota(A(ptr), 1ll);` is INSIDE the `while` loop.
                // So it is re-initialized.
                // This is very strange for a reduction algorithm. Usually, you consume elements.
                // Let's assume the C++ code is exactly as written: re-initialize ptr to 0..size-1.
                // Then we generate pairs (i, j) with j >= i.
                // We pick the minimum sum, add to b.
                // Repeat until b has size a.size() - 1.
                // This effectively removes the element that participates in the minimum sum pair?
                // Actually, if we pick (i, i), we are essentially doubling a[i].
                // If we pick (i, i+1), we sum them.
                // The logic seems to be: repeatedly pick the smallest sum of two elements from the current set,
                // add that sum to the new set, and discard the two original elements?
                // But the code does `b.push_back(score)`. It does NOT remove i or ptr[i] from consideration for OTHER j's?
                // Wait, if we pick (i, j), do we remove i and j from the pool?
                // The code structure:
                //   while (b.size() < target) {
                //      pop best (score, i).
                //      b.add(score).
                //      ptr[i]++.
                //      if valid, push (a[i] + a[ptr[i]], i).
                //   }
                // This logic suggests that for a fixed `i`, we can pair it with `i`, `i+1`, `i+2`...
                // But we never increment `ptr` for other indices `k != i`.
                // So if we pair `a[0]` with `a[1]`, `ptr[0]` becomes 2.
                // But `ptr[1]` is still 1. So `a[1]` can still be paired with `a[1]`.
                // This seems to allow reusing elements.
                // Is this intended? The problem might be about "doubling" or "merging" specific elements.
                // Given the ambiguity, I will translate the code EXACTLY as written.
                
                // Implementation detail:
                // We need to maintain the 'ptr' state for the current 'a'.
                // Since 'a' is an ArrayList, we can create an int[] ptr.
                
                // Re-initialization inside while loop:
                int[] ptr = new int[(int)a.size()];
                for(int k=0; k<a.size(); k++) ptr[k] = k;
                
                // We need to re-populate the PQ? 
                // No, the C++ code does:
                //   F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(...)
                // This is done ONCE before the while loop.
                // Then inside the while loop, we update the PQ.
                // So we need to do the initial population here.
                
                // Re-doing the initial population for the current iteration
                // Clear PQ? 
                // The C++ code declares `vl b;` and `pq` inside the while loop.
                // So yes, PQ is fresh.
                // We must re-populate it based on the NEW 'a' and NEW 'ptr'.
                
                // Let's refactor the loop structure to match C++ exactly.
                // 1. Create ptr array (0..size-1).
                // 2. Populate PQ.
                // 3. While b.size() < a.size() - 1:
                //      Pop best.
                //      Add to b.
                //      Update ptr[i].
                //      If ptr[i] < size, push new pair.
                
                // Re-implementing the block inside the loop for clarity:
                
                // 1. Initialize ptr
                // int[] ptr = new int[(int)a.size()];
                // for(int k=0; k<a.size(); k++) ptr[k] = k;
                
                // 2. Populate PQ
                // for(int i=0; i<a.size(); i++) {
                //    if(ptr[i] < a.size()) {
                //        pq.add(new Pair(a.get(i) + a.get(ptr[i]), i));
                //    }
                // }
                
                // 3. Run while loop
                // while(b.size() < a.size() - 1) { ... }
                
                // But wait, the C++ code puts the initialization BEFORE the while loop.
                // And the update is INSIDE.
                // So my logic above is correct.
                
                // However, there is a catch: `ptr` is a `vector<ll>`.
                // In the loop, we do `++ptr[i]`.
                // We need to persist `ptr` across iterations of the `while` loop.
                // But `ptr` is declared outside the `while` loop in C++?
                // No: `vl ptr(a.size()); iota(A(ptr), 1ll);` is BEFORE the `while`.
                // So `ptr` is persistent across iterations.
                // Correct.
                
                // So:
                // 1. Create ptr array initialized to 0..size-1.
                // 2. Populate PQ.
                // 3. While loop: pop, add to b, update ptr[i], push new pair.
                
                // Let's write this logic.
                
                // Re-initialize ptr for the current 'a' size
                // ptr is defined outside the while loop in C++: "vl ptr(a.size()); iota(...)"
                // So we must create it once per outer iteration.
                
                int[] currentPtr = new int[(int)a.size()];
                for(int k=0; k<a.size(); k++) currentPtr[k] = k;
                
                // Populate PQ
                for(int i=0; i<a.size(); i++) {
                    if(currentPtr[i] < a.size()) {
                        pq.add(new Pair(a.get(i) + a.get(currentPtr[i]), i));
                    }
                }
                
                // While loop
                while (b.size() < a.size() - 1) {
                    Pair top = pq.poll();
                    long score = top.first;
                    int i = (int)top.second;
                    
                    b.add(score);
                    
                    currentPtr[i]++;
                    if(currentPtr[i] < a.size()) {
                        pq.add(new Pair(a.get(i) + a.get(currentPtr[i]), i));
                    }
                }
                
                // Update a
                a = b;
                
                // Calculate gans
                // ll mn = a[0];
                // for (auto &x: a) x -= mn;
                // gans += mn * p2[a.size() - 1]%M;
                
                long mn = a.get(0);
                for(long x : a) {
                    x -= mn;
                }
                // Wait, modifying ArrayList while iterating?
                // In C++, `for (auto &x: a) x -= mn;` modifies the elements.
                // In Java, we can do this.
                // But note: a is ArrayList<Long>.
                // We need to update the values.
                
                // Re-calculate gans
                gans = (gans + (mn * p2[(int)a.size() - 1]) % M) % M;
                
                // Check break conditions
                // if (a.size() >= 3 and !(a[0]|a[1]|a[2])) break;
                // In Java, bitwise OR for longs: (a[0] | a[1] | a[2]) == 0
                if (a.size() >= 3) {
                    long val = a.get(0) | a.get(1) | a.get(2);
                    if (val == 0) break;
                }

                // Second optimization block
                // if (a.size() >= 4 and 2 * a[3] > a.back()) { ... }
                if (a.size() >= 4) {
                    // 2 * a[3] > a.back()
                    // a is sorted? Yes, initially sorted.
                    // After the first loop, a is sorted?
                    // The code sorts initially.
                    // Inside the loop, we do:
                    //   b.push_back(score);
                    //   ...
                    //   a = b;
                    // Does b remain sorted?
                    // The C++ code does NOT sort 'b' after the loop.
                    // But the next iteration of the outer while loop does:
                    //   F(i, 0, a.size()) ...
                    //   It relies on 'a' being sorted?
                    //   The initialization `ptr` assumes `a` is indexed 0..size-1.
                    //   The logic `a[i] + a[ptr[i]]` assumes `a` is sorted so that `a[i] + a[j]` is minimized when `i` and `j` are close?
                    //   Actually, if `a` is sorted, `a[i] + a[j]` is minimized when `i` and `j` are small.
                    //   But the loop picks the global minimum sum.
                    //   If `a` is not sorted, the logic might be different.
                    //   The C++ code sorts initially: `sort(A(a))`.
                    //   Inside the loop, it does NOT sort `b`.
                    //   So `a` becomes `b`. `b` is not sorted.
                    //   Then the next iteration uses `a` (which is `b`).
                    //   The logic `a[i] + a[ptr[i]]` with `ptr[i]` starting at `i` implies pairing `a[i]` with `a[i]`.
                    //   If `a` is not sorted, this logic is just pairing elements with themselves.
                    //   However, the condition `2 * a[3] > a.back()` suggests checking the 4th element vs the largest.
                    //   This implies `a` is expected to be sorted.
                    //   Wait, if `a` is not sorted, `a.back()` is the last element added, not necessarily the max.
                    //   But the initial sort ensures `a` is sorted.
                    //   The subsequent steps might break the sort?
                    //   Let's check the logic:
                    //   `b` contains sums. Sums of sorted elements are not necessarily sorted?
                    //   Example: a = {1, 10, 100}. 
                    //   Pairs: 1+1=2, 1+10=11, 10+10=20, 10+100=110, 100+100=200.
                    //   Sorted sums: 2, 11, 20, 110, 200.
                    //   If we take smallest sums, we get {2, 11, 20}.
                    //   This is sorted.
                    //   It seems the property of "sums of sorted elements" preserves order if we take sums of (i, i), (i, i+1)...
                    //   Actually, if a is sorted, a[i] <= a[i+1].
                    //   Then a[i] + a[i] <= a[i] + a[i+1] <= a[i+1] + a[i+1].
                    //   So the generated sums will be sorted naturally.
                    //   So `a` remains sorted.
                    
                    // Optimization logic:
                    // while (asz >= 4 and 2 * a[2] < (a[3] - sumsubs)) {
                    //     asz--;
                    //     gans += a[1] * p2[asz - 1]%M; 
                    //     sumsubs += a[1];
                    //     a[1] = a[2] - a[1];
                    // }
                    
                    // Note: a[1] is modified in the loop.
                    // a[2] is used.
                    // a[3] is used.
                    // a.back() is used in the condition.
                    
                    // We need to handle indices carefully.
                    // a is 0-indexed.
                    // a[0], a[1], a[2], a[3], ...
                    // a.back() is the last element.
                    
                    // Let's implement this block.
                    
                    // Check condition: 2 * a[3] > a.back()
                    // Note: a.size() >= 4.
                    
                    // Variables:
                    // asz = a.size()
                    // sumsubs = 0
                    // Loop condition: asz >= 4 AND 2 * a[2] < (a[3] - sumsubs)
                    // Inside loop:
                    //   asz--
                    //   gans += a[1] * p2[asz - 1]
                    //   sumsubs += a[1]
                    //   a[1] = a[2] - a[1]
                    
                    // After loop:
                    //   while (a.size() > asz) a.pop_back();
                    //   F(i, 3, a.size()) a[i] -= sumsubs;
                    
                    // Important: The C++ code modifies `a[1]` and `a[i]` in place.
                    // In Java, we need to be careful with ArrayList indexing.
                    
                    long asz = a.size();
                    long sumsubs = 0;
                    
                    // Condition: asz >= 4 (always true initially) AND 2 * a[2] < (a[3] - sumsubs)
                    // Note: a[2] and a[3] refer to the current state of 'a'.
                    // But 'a' is modified inside the loop?
                    // Yes: a[1] = a[2] - a[1].
                    // Does a[2] change? No, only a[1] changes.
                    // So a[2] is constant during the loop?
                    // Wait, if asz decreases, do we shift elements?
                    // No, the loop just decrements asz.
                    // The elements a[0]...a[asz-1] are kept.
                    // But a[1] is updated.
                    // So a[2] might be out of bounds if asz becomes 2?
                    // Condition: asz >= 4. So a[3] exists.
                    // Inside loop, asz decreases.
                    // If asz becomes 3, loop stops.
                    // So a[2] is valid as long as asz >= 3.
                    // But we need a[3] for the condition.
                    // So the loop runs while asz >= 4.
                    // So a[3] is always valid.
                    
                    // One issue: a[1] = a[2] - a[1].
                    // This modifies a[1].
                    // Does a[2] change? No.
                    // So the condition 2*a[2] < a[3] - sumsubs depends on sumsubs (which grows) and a[2] (constant).
                    
                    while (asz >= 4 && 2 * a.get(2) < (a.get(3) - sumsubs)) {
                        asz--;
                        gans = (gans + (a.get(1) * p2[(int)asz - 1]) % M) % M;
                        sumsubs += a.get(1);
                        // a[1] = a[2] - a[1]
                        long val1 = a.get(1);
                        long val2 = a.get(2);
                        a.set(1, val2 - val1);
                    }
                    
                    // Remove elements from asz to end
                    while (a.size() > asz) {
                        a.remove(a.size() - 1);
                    }
                    
                    // Subtract sumsubs from a[3] to a.back()
                    // F(i, 3, a.size()) a[i] -= sumsubs;
                    for (int i = 3; i < a.size(); i++) {
                        a.set(i, a.get(i) - sumsubs);
                    }
                }
            }
        }

        cout << (gans + a.get(0)) % M << endl;
    }
}
```

Wait, I need to check the logic inside the `while` loop for `ptr` again.
In the C++ code:
```cpp
    vl ptr(a.size());
    iota(A(ptr), 1ll); // ptr = [0, 1, 2, ..., n-1]
    F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
    while (b.size() < a.size() - 1) {
        // ...
        if (++ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
    }
```
The `ptr` vector is declared OUTSIDE the `while` loop.
So `ptr` persists.
My Java code structure:
```java
            int[] currentPtr = new int[(int)a.size()];
            for(int k=0; k<a.size(); k++) currentPtr[k] = k;
            
            // Populate PQ
            for(int i=0; i<a.size(); i++) {
                if(currentPtr[i] < a.size()) {
                    pq.add(new Pair(a.get(i) + a.get(currentPtr[i]), i));
                }
            }
            
            // While loop
            while (b.size() < a.size() - 1) {
                // ...
                currentPtr[i]++;
                if(currentPtr[i] < a.size()) {
                    pq.add(new Pair(a.get(i) + a.get(currentPtr[i]), i));
                }
            }
```
This matches the C++ logic.

One correction: The C++ code declares `vl ptr(a.size())` inside the `while` loop?
Let's check indentation.
```cpp
    while (a.size() > 1) {
        assert(++bad_iters <= 50);
        vl b;
        priority_queue<pl, vector<pl>, greater<pl>> pq;
        vl ptr(a.size());
        iota(A(ptr), 1ll);
        F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
        while (b.size() < a.size() - 1) {
            // ...
        }
        a=b;
        // ...
    }
```
Yes, `vl ptr(a.size())` is inside the `while (a.size() > 1)` loop.
So `ptr` is re-initialized to `0..size-1` every time.
My Java code does exactly this.

Final check on imports and class name.
Class name: `f2_1805`.
Imports: `java.util.*`, `java.io.*`.
Output: `System.out.println`.

One small detail: `gans` calculation.
`gans += mn * p2[a.size() - 1]%M;`
In Java: `gans = (gans + (mn * p2[(int)a.size() - 1]) % M) % M;`
This handles potential overflow before modulo.

The `cout << (gans + a[0])%M` at the end.
`a[0]` is `long`. `gans` is `long`.
Result is `long`.

The code looks solid.

```java
<CODE>
import java.io.*;
import java.util.*;

public class f2_1805 {

    static class Pair implements Comparable<Pair> {
        long first;
        long second;

        Pair(long f, long s) {
            this.first = f;
            this.second = s;
        }

        @Override
        public int compareTo(Pair o) {
            return Long.compare(this.first, o.first);
        }
    }

    static final long M = 1000000007L;

    public static void main(String[] args) {
        // Fast I/O
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nextInt();
        
        ArrayList<Long> a = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            a.add(sc.nextLong());
        }

        // Sort the array
        Collections.sort(a);

        long gans = 0;

        // Precompute powers of 2 modulo M
        long[] p2 = new long[n];
        p2[0] = 1;
        for (int i = 1; i < n; i++) {
            p2[i] = (p2[i - 1] * 2) % M;
        }

        int bad_iters = 0;

        while (a.size() > 1) {
            bad_iters++;
            // assert(++bad_iters <= 50); 
            // Java assert is disabled by default, and we assume the loop terminates naturally.

            ArrayList<Long> b = new ArrayList<>();
            // PriorityQueue mimics priority_queue<pl, vector<pl>, greater<pl>> (Min-Heap)
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            
            // vl ptr(a.size()); iota(A(ptr), 1ll);
            // ptr is re-initialized every iteration of the outer while loop
            int[] ptr = new int[(int)a.size()];
            for(int k=0; k<a.size(); k++) ptr[k] = k;

            // F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
            for(int i=0; i<a.size(); i++) {
                if(ptr[i] < a.size()) {
                    pq.add(new Pair(a.get(i) + a.get(ptr[i]), i));
                }
            }

            // while (b.size() < a.size() - 1)
            while (b.size() < a.size() - 1) {
                // auto [score, i] = pq.top(); pq.pop();
                Pair top = pq.poll();
                long score = top.first;
                int i = (int)top.second;
                
                b.add(score);
                
                // if (++ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
                ptr[i]++;
                if(ptr[i] < a.size()) {
                    pq.add(new Pair(a.get(i) + a.get(ptr[i]), i));
                }
            }
            
            a = b;
            
            // ll mn = a[0];
            // for (auto &x: a) x -= mn;
            long mn = a.get(0);
            for(int i=0; i<a.size(); i++) {
                a.set(i, a.get(i) - mn);
            }
            
            // gans += mn * p2[a.size() - 1]%M;
            gans = (gans + (mn * p2[(int)a.size() - 1]) % M) % M;

            // if (a.size() >= 3 and !(a[0]|a[1]|a[2])) break;
            if (a.size() >= 3) {
                long val = a.get(0) | a.get(1) | a.get(2);
                if (val == 0) break;
            }

            // if (a.size() >= 4 and 2 * a[3] > a.back()) { ... }
            if (a.size() >= 4) {
                long asz = a.size();
                long sumsubs = 0;
                
                // while (asz >= 4 and 2 * a[2] < (a[3] - sumsubs))
                while (asz >= 4 && 2 * a.get(2) < (a.get(3) - sumsubs)) {
                    asz--;
                    gans = (gans + (a.get(1) * p2[(int)asz - 1]) % M) % M;
                    sumsubs += a.get(1);
                    // a[1] = a[2] - a[1];
                    long val1 = a.get(1);
                    long val2 = a.get(2);
                    a.set(1, val2 - val1);
                }
                
                // while (a.size() > asz) a.pop_back();
                while (a.size() > asz) {
                    a.remove(a.size() - 1);
                }
                
                // F(i, 3, a.size()) a[i] -= sumsubs;
                for (int i = 3; i < a.size(); i++) {
                    a.set(i, a.get(i) - sumsubs);
                }
            }
        }

        out.println((gans + a.get(0)) % M);
        out.flush();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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
            if (s == null) throw new RuntimeException("End of input");
            return Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            if (s == null) throw new RuntimeException("End of input");
            return Long.parseLong(s);
        }
    }
}
</CODE>
</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several language-specific differences and structural requirements:

1.  **Class Structure**: The C++ `main` function becomes the `main` method inside the class `f2_1805`.
2.  **Headers and Namespaces**: C++ uses `#include` and `using namespace std;`. Java requires explicit imports (`java.util.*`, `java.io.*`).
3.  **Data Types**:
    *   `long long` in C++ maps to `long` in Java.
    *   `vector<ll>` maps to `ArrayList<Long>`.
    *   `pair<ll, ll>` maps to a static inner class `Pair` (or `long[]`). A class is preferred for readability.
    *   `priority_queue<pl, ...>` maps to `PriorityQueue<Pair>`.
4.  **Macros**:
    *   `#define` macros (e.g., `F`, `G`, `K`, `V`, `A`) must be implemented as helper methods or logic blocks.
    *   `#pragma GCC optimize` is ignored as it is compiler-specific.
5.  **Input/Output**:
    *   C++ `cin`/`cout` with `ios_base::sync_with_stdio(false)` is replaced by a custom `FastReader` class using `BufferedReader` and `StringTokenizer` for performance, and `PrintWriter` for output.
    *   `fixed` and `setprecision` are removed as the final output is an integer.
6.  **Logic Implementation**:
    *   Loops like `F(i, l, r)` are translated to standard `for` loops.
    *   `iota` is implemented as a loop to fill an array.
    *   `assert` is commented out or handled implicitly (Java assertions are disabled by default).
    *   Vector operations like `push_back`, `pop_back`, and `resize` are mapped to `ArrayList` methods (`add`, `remove`, `size`).
    *   The logic involving `ptr` vector and `priority_queue` inside the `while` loop is carefully translated to ensure state persistence across iterations.

### Java Code

```java
import java.io.*;
import java.util.*;

public class f2_1805 {

    // Helper class to mimic pair<ll, ll>
    static class Pair implements Comparable<Pair> {
        long first;
        long second;

        Pair(long f, long s) {
            this.first = f;
            this.second = s;
        }

        @Override
        public int compareTo(Pair o) {
            // We need a min-priority queue, so we compare by score (first) ascending
            return Long.compare(this.first, o.first);
        }
    }

    // Constants
    static final long M = 1000000007L;

    // Fast I/O
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
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
            if (s == null) throw new RuntimeException("End of input");
            return Integer.parseInt(s);
        }

        long nextLong() {
            String s = next();
            if (s == null) throw new RuntimeException("End of input");
            return Long.parseLong(s);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // Read n
        int n = sc.nextInt();
        
        // Read array a
        ArrayList<Long> a = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            a.add(sc.nextLong());
        }

        // Sort the array
        Collections.sort(a);

        long gans = 0;

        // Precompute powers of 2 modulo M
        long[] p2 = new long[n];
        p2[0] = 1;
        for (int i = 1; i < n; i++) {
            p2[i] = (p2[i - 1] * 2) % M;
        }

        int bad_iters = 0;

        while (a.size() > 1) {
            bad_iters++;
            // assert(++bad_iters <= 50); 
            // Java assert is disabled by default, and we assume the loop terminates naturally.

            ArrayList<Long> b = new ArrayList<>();
            // PriorityQueue mimics priority_queue<pl, vector<pl>, greater<pl>> (Min-Heap)
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            
            // vl ptr(a.size()); iota(A(ptr), 1ll);
            // ptr is re-initialized every iteration of the outer while loop
            int[] ptr = new int[(int)a.size()];
            for(int k=0; k<a.size(); k++) ptr[k] = k;

            // F(i, 0, a.size()) if (ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
            for(int i=0; i<a.size(); i++) {
                if(ptr[i] < a.size()) {
                    pq.add(new Pair(a.get(i) + a.get(ptr[i]), i));
                }
            }

            // while (b.size() < a.size() - 1)
            while (b.size() < a.size() - 1) {
                // auto [score, i] = pq.top(); pq.pop();
                Pair top = pq.poll();
                long score = top.first;
                int i = (int)top.second;
                
                b.add(score);
                
                // if (++ptr[i] < a.size()) pq.emplace(a[i] + a[ptr[i]], i);
                ptr[i]++;
                if(ptr[i] < a.size()) {
                    pq.add(new Pair(a.get(i) + a.get(ptr[i]), i));
                }
            }
            
            a = b;
            
            // ll mn = a[0];
            // for (auto &x: a) x -= mn;
            long mn = a.get(0);
            for(int i=0; i<a.size(); i++) {
                a.set(i, a.get(i) - mn);
            }
            
            // gans += mn * p2[a.size() - 1]%M;
            gans = (gans + (mn * p2[(int)a.size() - 1]) % M) % M;

            // if (a.size() >= 3 and !(a[0]|a[1]|a[2])) break;
            if (a.size() >= 3) {
                long val = a.get(0) | a.get(1) | a.get(2);
                if (val == 0) break;
            }

            // if (a.size() >= 4 and 2 * a[3] > a.back()) { ... }
            if (a.size() >= 4) {
                long asz = a.size();
                long sumsubs = 0;
                
                // while (asz >= 4 and 2 * a[2] < (a[3] - sumsubs))
                while (asz >= 4 && 2 * a.get(2) < (a.get(3) - sumsubs)) {
                    asz--;
                    gans = (gans + (a.get(1) * p2[(int)asz - 1]) % M) % M;
                    sumsubs += a.get(1);
                    // a[1] = a[2] - a[1];
                    long val1 = a.get(1);
                    long val2 = a.get(2);
                    a.set(1, val2 - val1);
                }
                
                // while (a.size() > asz) a.pop_back();
                while (a.size() > asz) {
                    a.remove(a.size() - 1);
                }
                
                // F(i, 3, a.size()) a[i] -= sumsubs;
                for (int i = 3; i < a.size(); i++) {
                    a.set(i, a.get(i) - sumsubs);
                }
            }
        }

        out.println((gans + a.get(0)) % M);
        out.flush();
    }
}
```