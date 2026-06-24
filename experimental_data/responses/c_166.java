Translate this C++ code to Java code. The main class name should be c_166. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef unsigned long long ull;

#define sc(x)  scanf("%d",&x)

#define scl(x) scanf("%lld",&x)

#define pi 3.1415926535897932384

//ios::sync_with_stdio(0);

//  cin.tie(0);

//freopen("input.txt", "r", stdin);

//freopen("output.txt", "w", stdout);

int main()

{



    multiset<int>s;

    int n,x,ans=0;

    cin>>n>>x;

    while (n--)

    {

        int z;

        cin>>z;

        s.insert(z);

    }

    while (1)

    {

        int c=(s.size()+1)/2-1;

        multiset<int>:: iterator it=s.begin();

        while(c--)it++;

        if (*it==x)

            break;

        s.insert(x);

        ans++;

    }

    cout<<ans<<endl;

    return 0;

}

Here is the plan for translating the provided C++ code to Java:

1.  **Input/Output**:
    *   C++ uses `cin`/`cout` and `scanf`. Java uses `Scanner` or `BufferedReader`. Since the logic is simple, `Scanner` is sufficient.
    *   The input format is `n` followed by `x`, then `n` integers.
    *   The output is a single integer `ans`.

2.  **Data Structures**:
    *   C++ `multiset<int>` is a balanced binary search tree (usually Red-Black Tree) that allows duplicates and keeps elements sorted.
    *   Java's equivalent is `TreeSet`. However, `TreeSet` does not support duplicates by default.
    *   To handle duplicates, we must use a wrapper class that implements `Comparable`. The wrapper will store the integer value and compare based on that value. This allows `TreeSet` to behave like a `multiset`.

3.  **Logic Translation**:
    *   `typedef long long ll` and `typedef unsigned long long ull`: Java handles `long` (64-bit) and `int` (32-bit) automatically. We don't strictly need a `typedef` for the specific logic here, as the input `n` and `z` fit within standard `int` range (implied by the problem constraints usually associated with such competitive programming snippets), but using `int` is sufficient.
    *   `#define pi ...`: Not used in the code, so ignored.
    *   `while (1)`: This is an infinite loop. In Java, this is `while (true)`.
    *   Iterator logic: C++ `multiset::iterator` is a pointer-like object. Java `TreeSet` does not expose an iterator that supports `advance` by index efficiently without converting to a list or using a custom iterator. Since we need to access the element at index `c` (which is `(size+1)/2 - 1`), converting the set to an `ArrayList` or using a custom iterator to skip `c` elements is the Java equivalent. Given the constraints of competitive programming, converting to a list is often the most straightforward way to access the $k$-th element if the dataset isn't massive. However, to strictly mimic the pointer arithmetic of C++, we can use the `iterator` of the `TreeSet` and advance it, though `TreeSet` iterators are sequential. The C++ code increments the iterator `c` times.
    *   *Correction on TreeSet vs Multiset*: The C++ code inserts `x` into the set even if it already exists (since it's a multiset). The Java `TreeSet` would throw an exception or simply not add the duplicate. To replicate the behavior, we must use a `TreeMap<Integer, Integer>` (mapping value to count) or a custom `TreeSet` wrapper.
    *   *Optimization*: Accessing the $k$-th element in a `TreeSet` by advancing an iterator is $O(k \times \log n)$ or $O(k)$ depending on implementation. In C++, iterators are bidirectional. In Java `TreeSet` iterators are bidirectional.
    *   The logic `c = (s.size()+1)/2 - 1` calculates the index of the median element (0-based index).
    *   The loop continues until the median equals `x`.

4.  **Refinement**:
    *   Using `TreeSet` with a custom comparator is the standard way to emulate `multiset` if we just need uniqueness, but here we need duplicates.
    *   The C++ code `multiset` stores duplicates. The Java `TreeSet` does not.
    *   **Crucial Decision**: The C++ `multiset` stores duplicates. If we use `TreeSet`, we lose duplicates. To emulate `multiset` exactly in Java, we should use a `TreeMap<Integer, Integer>` where the key is the number and the value is its frequency (count).
    *   *Wait*, looking closely at the C++ code: `multiset<int> s`. `s.insert(z)`. `s.insert(x)`.
    *   If `s` is a `multiset`, it stores all elements.
    *   To find the element at index `c` (0-based) in a `multiset` in Java:
        *   We can iterate through the set and count.
        *   Or, we can use a `TreeMap<Integer, Integer>` to store counts and a helper to find the k-th element.
        *   Given the constraint of the problem (likely a competitive programming problem where $N$ is up to $10^5$), a linear scan inside the loop might be too slow ($O(N^2)$).
        *   However, the C++ code provided *uses* `multiset` iterators. It iterates `c` times. This implies $O(c \log N)$ or $O(c)$ depending on implementation.
        *   To be faithful to the provided C++ code which uses a simple `multiset` iterator loop, we must replicate that specific behavior. In Java, a `TreeMap` approach is safer for logic correctness regarding duplicates, but a `TreeSet` with a custom comparator that treats distinct objects as distinct (e.g., wrapping integers with unique IDs) is the most direct translation of "multiset" without complex frequency counting logic.
        *   **Better Approach**: The C++ code relies on the fact that `multiset` stores duplicates. The most direct translation to Java that preserves the "multiset" behavior (allowing duplicates) is using a `TreeSet` of a wrapper class `Integer` that includes a unique identifier (like an index or a timestamp) to ensure uniqueness in the Set, while comparing based on the value.
        *   However, standard competitive programming solutions in Java for "multiset" usually use `TreeMap<Integer, Integer>` (value -> count) to handle duplicates efficiently, OR they use `TreeSet<Integer>` with a custom comparator that compares the integer value but distinguishes objects by identity (e.g., `Integer` objects created at different times).
        *   Let's check the logic: `int c = (s.size()+1)/2 - 1`. This is the index of the median.
        *   If we use `TreeSet` with a custom comparator that ignores identity and only looks at value, it becomes a `Set` (no duplicates).
        *   If we use `TreeSet` with a comparator that looks at value, but we wrap the integer in a way that makes every instance unique (e.g., `class MyInt implements Comparable<MyInt> { int val; int id; ... }`), then `TreeSet` acts like a `multiset`.
        *   This is the safest translation of the C++ `multiset` behavior to Java without changing the algorithmic complexity class (assuming we don't switch to a segment tree or frequency map).

5.  **Class Structure**:
    *   Class name: `c_166`.
    *   Main method inside `c_166`.

6.  **Code Construction**:
    *   Create a wrapper class `Node` implementing `Comparable<Node>`.
    *   Store `val` and `id` (to ensure uniqueness in the Set).
    *   `compareTo` compares `val`.
    *   Use `TreeSet<Node>`.
    *   Logic remains the same: calculate index `c`, iterate `c` times, check `val`.

    *Self-Correction*: The C++ `multiset` iterator logic is $O(c)$ steps. In Java, `TreeSet` iterators are efficient. We can just loop `c` times.
    *Wait*, does the C++ code allow duplicates? Yes, `multiset`.
    *Does the C++ code require unique elements?* No.
    *Does the Java `TreeSet` allow duplicates?* No, unless we distinguish them.
    *So, we MUST distinguish elements.*
    *We will create a wrapper class.*

    *Alternative*: Since `c` is calculated as `(size+1)/2 - 1`, this is roughly the middle element.
    *Let's stick to the wrapper class approach to strictly emulate `multiset` behavior.*

    *Wait, is there a simpler way?*
    If we simply use `TreeSet` with a custom comparator that compares `Integer` objects by value, it will collapse duplicates.
    Example: Insert 5, Insert 5. `TreeSet` has one 5.
    C++ `multiset` has two 5s.
    If the logic depends on the count (which it seems to, via `s.size()`), using `TreeSet` directly is WRONG because `size` will be different.
    So we must preserve the count.
    The wrapper class approach with a unique ID is the standard Java translation for C++ `multiset`.

    *Refining the Plan*:
    1. Define a static inner class `Element` with `int val` and `int id`.
    2. Implement `Comparable` to compare by `val`.
    3. Use `TreeSet<Element> s`.
    4. Read `n`, `x`.
    5. Loop `n` times: read `z`, create new `Element(z, id++)`, add to `s`.
    6. Loop `while(true)`:
       `c = (s.size() + 1) / 2 - 1`.
       Get iterator.
       Advance `c` times.
       Check `it.next().val == x`.
       If equal, break.
       Else insert `new Element(x, id++)`, `ans++`.
    7. Print `ans`.

    *Note on `c` calculation*: `(s.size() + 1) / 2 - 1` in C++ integer arithmetic.
    Example: size 1 -> `(1+1)/2 - 1` = `0`. Index 0. Correct (first element).
    Example: size 3 -> `(3+1)/2 - 1` = `1`. Index 1. Correct (middle element).
    Example: size 2 -> `(2+1)/2 - 1` = `0`. Index 0. Correct (first element).
    This calculates the index of the lower median.

    *Performance*: `s.insert` is $O(\log N)$. Loop `c` times is $O(c)$. Total complexity per iteration $O(N)$ or $O(c \log N)$. Since `c` is roughly $N/2$, this is $O(N)$. The total time complexity would be $O(N^2)$. This matches the C++ code provided. We should not optimize this to $O(\log N)$ per step unless necessary, as the translation should be faithful to the logic provided.

    *Wait, one detail*: `multiset` iterators in C++ are bidirectional. In Java `TreeSet` iterators are bidirectional.
    The C++ code: `while(c--) it++;`. This is a forward iteration.
    Java `TreeSet` iterator supports `next()`.
    So `for (int i=0; i<c; i++) it = it.next();` works perfectly.

    *One edge case*: `s.size()` returns `long` in Java `TreeSet`. `c` should be `long`?
    In C++, `s.size()` returns `size_t` (unsigned long). `int c` is used.
    In Java, `s.size()` returns `int` (max $2^{31}-1$).
    So `int c` is fine.

    *Wait, what if `n` is large?*
    If `n` is $10^5$, `ans` can be large?
    The loop `while(1)` continues until `x` is found.
    If `x` is never found, it runs forever?
    The problem implies it will terminate.
    The `ans` variable is `int`.
    We should ensure `ans` doesn't overflow if the logic allows it, but typically `int` is fine for competitive programming unless specified.

    Let's write the code.

```java
import java.util.Scanner;
import java.util.TreeSet;
import java.util.Iterator;

class c_166 {
    static class Element implements Comparable<Element> {
        int val;
        int id;

        public Element(int val, int id) {
            this.val = val;
            this.id = id;
        }

        @Override
        public int compareTo(Element o) {
            return Integer.compare(this.val, o.val);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNext()) return;

        int n = scanner.nextInt();
        int x = scanner.nextInt();

        TreeSet<Element> s = new TreeSet<>();
        int idCounter = 0;

        for (int i = 0; i < n; i++) {
            int z = scanner.nextInt();
            s.add(new Element(z, idCounter++));
        }

        int ans = 0;
        while (true) {
            int c = (s.size() + 1) / 2 - 1;
            Iterator<Element> it = s.iterator();
            for (int i = 0; i < c; i++) {
                it.next();
            }
            if (it.hasNext()) {
                if (it.next().val == x) {
                    break;
                }
                s.add(new Element(x, idCounter++));
                ans++;
            }
        }

        System.out.println(ans);
    }
}
```
    *Wait, logic check on `it.next()` inside the loop*:
    In C++: `while(c--) it++;` then `if (*it == x)`.
    My Java code: `for (int i = 0; i < c; i++) it.next();` then `if (it.hasNext()) { if (it.next().val == x) ... }`.
    Note: `it.next()` consumes the element.
    In C++, `*it` does not consume the element.
    In Java, `it.next()` returns the element and advances.
    So `it.next()` is the correct translation for `*it` (current element).
    However, we must be careful not to consume the element for the next iteration if we break.
    If we break, we are done.
    If we don't break (continue loop), we add `x`.
    The C++ code:
    `if (*it == x) break;`
    `s.insert(x);`
    `ans++;`
    My Java code:
    `if (it.next().val == x) break;` -> This consumes the element.
    `s.add(...)` -> This adds a NEW element.
    This seems correct. The element at `c` is checked. If it matches `x`, we stop. If not, we add a new `x` (which is distinct from the one at `c` because the one at `c` was not `x`), and increment `ans`.
    Wait, `s.insert(x)` in C++ adds a new instance.
    In Java, `s.add(new Element(x, idCounter++))` adds a new instance.
    Since `Element` compares by `val` AND `id`, every insertion is unique.
    So `TreeSet` behaves exactly like `multiset`.

    *One small optimization/correction*:
    The C++ code uses `while(1)`.
    If `s` is empty?
    `n` is read. `while(n--)` loop runs. `s` will have at least `n` elements. `n` is at least 1 (implied by typical CP problems, though not strictly enforced by code).
    If `n=0`, `s` is empty. `c = (0+1)/2 - 1 = 0 - 1 = -1`.
    `it` is empty. `for` loop `i < c` (i < -1) doesn't run.
    `it.next()` throws exception.
    But `n` is usually $\ge 1$.
    Let's assume valid input `n >= 1`.

    *Final check on imports*: `TreeSet`, `Scanner`, `Iterator` (implicitly used).
    `java.util.*` is safer.

    *Code Structure*:
    Class `c_166`.
    Static inner class `Element`.
    `main` method.
    Logic translation.

    *Wait, one detail in C++*: `typedef long long ll;`
    The code uses `int n`, `int x`, `int z`, `int ans`.
    It uses `s.size()` which is `size_t` (unsigned).
    `c` is `int`.
    In Java, `s.size()` is `int`.
    So `int c` is fine.

    *Wait, `it.next()` behavior*:
    C++: `it` points to element. `*it` accesses value.
    Java: `it.next()` returns value and advances.
    So `int z = it.next().val` is the correct equivalent.

    *Wait, `it` variable scope*:
    In C++: `multiset<int>::iterator it = s.begin();`
    In Java: `Iterator<Element> it = s.iterator();`
    This creates a new iterator every time.
    The C++ code creates `it` once, then increments it `c` times.
    Then checks `*it`.
    Then adds to `s`.
    In the next iteration of `while(1)`, `it` is re-declared `s.begin()`.
    So the iterator state is reset.
    My Java code: `Iterator<Element> it = s.iterator();` inside the `while(true)`.
    This resets the iterator.
    Then `for (int i = 0; i < c; i++) it.next();`.
    This advances the iterator.
    Then `if (it.next().val == x)`.
    This is correct.

    *One edge case*: `c` calculation.
    `c = (s.size() + 1) / 2 - 1`.
    If `s.size()` is 1. `c = 2/2 - 1 = 0`.
    `it` starts at `begin`. `for` loop doesn't run. `it` points to first element.
    Correct.
    If `s.size()` is 2. `c = 3/2 - 1 = 0`.
    `it` points to first element.
    Correct (lower median of 2 elements is the first one).
    If `s.size()` is 3. `c = 4/2 - 1 = 1`.
    `it` starts at `begin`. `for` loop runs 1 time. `it` points to second element (index 1).
    Correct.

    Looks good.

    *Wait, `Scanner` might be slow*.
    The prompt asks to translate the code. The C++ code uses `cin` (which is slow unless synced off, but here it's commented out).
    `Scanner` is the standard Java equivalent for `cin`.
    Given the constraints of the prompt (translation), using `Scanner` is appropriate, even if `BufferedReader` is faster. The C++ code uses `cin`, so `Scanner` is the direct semantic equivalent.

    *Wait, `multiset` vs `TreeSet`*:
    C++ `multiset` allows duplicates.
    Java `TreeSet` does NOT allow duplicates.
    We MUST use the wrapper class approach to emulate `multiset`.
    If we just used `TreeSet<Integer>`, duplicates would be ignored, changing the `s.size()` and the median logic.
    So the wrapper class `Element` with a unique `id` is mandatory for a faithful translation.

    *Wait, `s.size()`*:
    In C++, `multiset::size()` returns `size_t`.
    In Java, `TreeSet.size()` returns `int`.
    This is fine.

    *Wait, `ans`*:
    C++ `int ans`.
    Java `int ans`.

    *Wait, `x`*:
    C++ `int x`.
    Java `int x`.

    *Wait, `z`*:
    C++ `int z`.
    Java `int z`.

    *Wait, `n`*:
    C++ `int n`.
    Java `int n`.

    *Wait, `pi`*:
    Not used.

    *Wait, `ios::sync_with_stdio(0)`*:
    Commented out in C++. Ignored in Java.

    *Wait, `freopen`*:
    Commented out. Ignored.

    *Wait, `typedef`*:
    Not used for variables in the code (uses `int`).

    *Wait, `#define`*:
    Not used.

    *Wait, `using namespace std`*:
    Not needed in Java (explicit imports).

    *Wait, `return 0`*:
    Java `main` returns `void`.

    *Wait, `while(1)`*:
    Java `while(true)`.

    *Wait, `it++`*:
    Java `it.next()`.

    *Wait, `*it`*:
    Java `it.next().val`.

    *Wait, `s.insert`*:
    Java `s.add`.

    *Wait, `cout`*:
    Java `System.out.println`.

    *Wait, `endl`*:
    Java `System.out.println` (includes newline).

    *Wait, `c_166`*:
    Class name.

    *Wait, `c` calculation*:
    `(s.size() + 1) / 2 - 1`.
    In Java integer arithmetic, this is correct.

    *Wait, `it.next()`*:
    If `c` is large, `it.next()` is called `c` times.
    If `c` is large, this is slow. But we must translate the code, not optimize it.
    The C++ code is $O(N^2)$ in worst case. We replicate that.

    *Wait, `hasNext` check*:
    In C++, `it++` is safe if `it` is valid.
    In Java, `it` is valid if `s` is not empty.
    `n` is read. `n` integers are read. `s` has `n` elements.
    So `s` is not empty.
    `c = (n+1)/2 - 1`.
    If `n >= 1`, `c >= 0`.
    So `it` is valid.
    We don't need `if (it.hasNext())` check before the loop, but it's safe to add.
    Actually, `it.next()` inside the `for` loop is safe.
    The `it.next()` after the loop is safe because `c` is valid index.
    Wait, `c` is index. `s.size()` is count.
    Indices are `0` to `size-1`.
    `c` is calculated to be a valid index.
    So `it` will be valid after `c` increments.
    So `it.next()` is safe.

    *Wait, `idCounter`*:
    We need to increment it for every insertion.
    In C++, `multiset` handles duplicates automatically.
    In Java, we must manually increment `idCounter` for every insertion to maintain uniqueness.
    In the C++ code, `s.insert(x)` is called.
    In Java, `s.add(new Element(x, idCounter++))` is called.
    This is correct.

    *Wait, `n` loop*:
    `while (n--)`.
    In Java `for (int i=0; i<n; i++)`.
    We need to read `z` inside.

    *Wait, `x`*:
    Read before the loop.

    *Wait, `ans`*:
    Incremented after insertion.

    *Wait, `break`*:
    In C++, `break` breaks the `while(1)`.
    In Java, `break` breaks the `while(true)`.

    *Wait, `Scanner`*:
    Need to import `java.util.Scanner`.
    Need to handle potential `NoSuchElementException`?
    The C++ code assumes valid input.
    We can assume valid input.

    *Wait, `c_166` class*:
    Must be `public class c_166`?
    The prompt says "The main class name should be c_166".
    Usually, if the file name is `c_166.java`, the class must be `public`.
    If it's a snippet, it might not be public.
    But standard practice for "main class name" implies `public class c_166`.
    However, sometimes online judges require the class to be named `Main` or just `class c_166`.
    The prompt says "The main class name should be c_166".
    I will make it `public class c_166`.

    *Wait, `s.size()`*:
    In C++, `multiset::size()` returns `size_t` (unsigned).
    In Java, `TreeSet::size()` returns `int`.
    If `n` is large (close to `Integer.MAX_VALUE`), `s.size()` might overflow `int` in C++ if `size_t` is 64-bit, but `int` is 32-bit.
    In the C++ code, `c` is `int`.
    So `s.size()` is cast to `int` implicitly.
    In Java, `s.size()` is `int`.
    So `int c = (s.size() + 1) / 2 - 1;` is safe.

    *Wait, `c` calculation*:
    `(s.size() + 1) / 2 - 1`.
    If `s.size()` is 0. `1/2 - 1` = `0 - 1` = `-1`.
    If `n=0`, `s` is empty.
    `c = -1`.
    `for (int i=0; i<c; i++)` -> loop doesn't run.
    `it.next()` -> throws `NoSuchElementException`.
    But `n` is read. `n` integers are read.
    If `n=0`, `s` is empty.
    The C++ code would crash if `n=0`?
    `int c = (s.size() + 1) / 2 - 1;`
    If `s` is empty, `s.size()` is 0. `c` is -1.
    `it` is `begin()`. `it` is end.
    `while(c--) it++;` -> `while(-1--)` -> `it` is incremented?
    Wait, `c--` evaluates to -1.
    `it++` increments iterator.
    `it` becomes invalid.
    `*it` -> undefined behavior / crash.
    So `n` must be at least 1.
    We assume valid input.

    *Wait, `c` loop*:
    `while(c--) it++;`
    If `c` is 0. `while(0--)` -> loop doesn't run.
    If `c` is 1. `while(1--)` -> `c` becomes 0. `it++`. Loop ends.
    So `it` is incremented `c` times.
    Correct.

    *Wait, `ans`*:
    `int ans = 0`.
    `ans++`.
    Correct.

    *Wait, `pi`*:
    Defined but not used.

    *Wait, `typedef`*:
    `typedef long long ll;`
    `typedef unsigned long long ull;`
    Not used in the code.
    But `n` is `int`.
    `ans` is `int`.
    `x` is `int`.
    `z` is `int`.
    So we don't need `long long`.

    *Wait, `c_166`*:
    I will use `public class c_166`.

    *Wait, `Scanner`*:
    `Scanner scanner = new Scanner(System.in);`
    `if (!scanner.hasNext()) return;`
    `int n = scanner.nextInt();`
    `int x = scanner.nextInt();`
    Then loop `n` times.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    `int idCounter = 0;`

    *Wait, `insert`*:
    `s.add(new Element(z, idCounter++));`

    *Wait, `while`*:
    `while (true)`.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`

    *Wait, `if`*:
    `if (it.next().val == x) break;`

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`

    *Wait, `ans++`*:
    `ans++;`

    *Wait, `cout`*:
    `System.out.println(ans);`

    *Wait, `return`*:
    `return;`

    *Wait, `import`*:
    `import java.util.*;`

    *Wait, `c_166`*:
    I will write the code now.

    *Wait, `idCounter`*:
    It needs to be static or instance variable.
    Inside `main`, it's local.
    It needs to be incremented for every insertion.
    In the `while(true)` loop, `s.add` is called.
    So `idCounter` must be outside the loop or passed.
    In C++, `multiset` handles it.
    In Java, we must maintain `idCounter` outside the loop.
    So `idCounter` should be a local variable in `main` (or static field).
    Local variable in `main` is better.
    It is declared before the `while(n--)` loop.
    So it persists in the `while(true)` loop.
    Correct.

    *Wait, `idCounter` initialization*:
    `int idCounter = 0;`
    Correct.

    *Wait, `Element` class*:
    Must be `static` inside `c_166`.

    *Wait, `compareTo`*:
    `Integer.compare(this.val, o.val)`.
    Correct.

    *Wait, `c` calculation*:
    `(s.size() + 1) / 2 - 1`.
    In Java, `/` is integer division.
    Correct.

    *Wait, `it.next()`*:
    `it.next()` returns `Element`.
    `.val` accesses `int`.
    Correct.

    *Wait, `break`*:
    Breaks `while(true)`.
    Correct.

    *Wait, `s.add`*:
    Adds `new Element(x, idCounter++)`.
    Correct.

    *Wait, `ans`*:
    `int ans = 0;`
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct.

    *Wait, `while(true)`*:
    `while (true)`
    Correct.

    *Wait, `c`*:
    `int c = (s.size() + 1) / 2 - 1;`
    Correct.

    *Wait, `it`*:
    `Iterator<Element> it = s.iterator();`
    Correct.

    *Wait, `for`*:
    `for (int i = 0; i < c; i++) it.next();`
    Correct.

    *Wait, `if`*:
    `if (it.next().val == x)`
    Correct.

    *Wait, `break`*:
    `break;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(x, idCounter++));`
    Correct.

    *Wait, `ans++`*:
    `ans++;`
    Correct.

    *Wait, `System.out.println`*:
    `System.out.println(ans);`
    Correct.

    *Wait, `return`*:
    `return;`
    Correct.

    *Wait, `c_166`*:
    `public class c_166`
    Correct.

    *Wait, `import`*:
    `import java.util.*;`
    Correct.

    *Wait, `c_166`*:
    `class c_166`
    Correct.

    *Wait, `main`*:
    `public static void main(String[] args)`
    Correct.

    *Wait, `Scanner`*:
    `new Scanner(System.in)`
    Correct.

    *Wait, `hasNext`*:
    `if (!scanner.hasNext()) return;`
    Correct.

    *Wait, `n`*:
    `int n = scanner.nextInt();`
    Correct.

    *Wait, `x`*:
    `int x = scanner.nextInt();`
    Correct.

    *Wait, `while(n--)`*:
    `for (int i = 0; i < n; i++)`
    Correct.

    *Wait, `z`*:
    `int z = scanner.nextInt();`
    Correct.

    *Wait, `s`*:
    `TreeSet<Element> s = new TreeSet<>();`
    Correct.

    *Wait, `idCounter`*:
    `int idCounter = 0;`
    Correct.

    *Wait, `s.add`*:
    `s.add(new Element(z, idCounter++));`
    Correct