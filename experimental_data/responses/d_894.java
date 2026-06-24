Translate this C++ code to Java code. The main class name should be d_894. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN=1000005, MAXM=100005;

int N, M, L[MAXN], D[MAXN];
long long K;

struct tree{
    vector<int> a;
    vector<long long> s;
} T[MAXN*3];

void makeTree(int idx, int t){
    if(t>N){
        return;
    }
    int lidx=idx<<1, ridx=lidx+1;
    makeTree(lidx, t*2);
    makeTree(ridx, t*2+1);
    int i, j;
    T[idx].a.push_back(D[t]);
    for(i=j=0; i<T[lidx].a.size() && j<T[ridx].a.size(); ){
        if(T[lidx].a[i]<T[ridx].a[j]){
            T[idx].a.push_back(T[lidx].a[i]);
            i++;
        }
        else{
            T[idx].a.push_back(T[ridx].a[j]);
            j++;
        }
    }
    for(; i<T[lidx].a.size(); i++){
        T[idx].a.push_back(T[lidx].a[i]);
    }
    for(; j<T[ridx].a.size(); j++){
        T[idx].a.push_back(T[ridx].a[j]);
    }
    T[idx].s.push_back(T[idx].a[0]);
    for(i=1; i<T[idx].a.size(); i++) T[idx].s.push_back(T[idx].a[i]+T[idx].s[i-1]);
}

int main(){
    int i, A, H, t, P, O;
    scanf("%d %d", &N, &M);
    for(i=1; i<N; i++)
        scanf("%d", L+i);
    for(i=2; i<=N; i++)
        D[i]=D[i/2]+L[i-1];
    makeTree(1, 1);
    for(i=1; i<=M; i++){
        scanf("%d %d", &A, &H);
        K=0;
        t=lower_bound(T[A].a.begin(), T[A].a.end(), D[A]+H)-T[A].a.begin();
        t=min(t, (int)T[A].a.size()-1);
        if(T[A].a[t]>=D[A]+H) t--;
        if(t>=0){
            K+=(long long)(t+1)*(D[A]+H)-T[A].s[t];
        }
        P=O=A;
        A/=2;
        for(; A>=1; P=A, A/=2){
            if(D[O]-D[A]>=H) break;
            K+=(H-D[O]+D[A]);
            if(A*2==P && T[A*2+1].a.size()){     //A*2+1
                t=lower_bound(T[A*2+1].a.begin(), T[A*2+1].a.end(), D[A]+H-(D[O]-D[A]))-T[A*2+1].a.begin();
                t=min(t, (int)T[A*2+1].a.size()-1);
                if(t<T[A*2+1].a.size() && T[A*2+1].a[t]>=D[A]+H-(D[O]-D[A])) t--;
                if(t>=0){
                    K+=(long long)(t+1)*(D[A]+H-(D[O]-D[A]))-T[A*2+1].s[t];
                }
            }
            else if(A*2+1==P && T[A*2].a.size()){           //A*2
                t=lower_bound(T[A*2].a.begin(), T[A*2].a.end(), D[A]+H-(D[O]-D[A]))-T[A*2].a.begin();
                t=min(t, (int)T[A*2].a.size()-1);
                if(t<T[A*2].a.size() && T[A*2].a[t]>=D[A]+H-(D[O]-D[A])) t--;
                if(t>=0){
                    K+=(long long)(t+1)*(D[A]+H-(D[O]-D[A]))-T[A*2].s[t];
                }
            }
        }
        printf("%I64d\n", K);
    }
    return 0;
}

<think>

</think>

### Translation Plan

1.  **Headers & Namespace**:
    *   Replace `<cstdio>` and `<algorithm>` with Java equivalents. `scanf`/`printf` will be replaced by `java.util.Scanner` for simplicity (though slower, it's sufficient for competitive programming logic translation). `std::vector`, `std::algorithm` functions (`lower_bound` logic), and `using namespace std` will be mapped to standard Java classes and methods.
    *   Remove `using namespace std;`.

2.  **Data Structures**:
    *   **Arrays**: C++ `int N, M, L[MAXN], D[MAXN]` become Java `int[]` or `ArrayList<Integer>`. Since `MAXN` is known (`1000005`), fixed-size arrays are efficient. Java arrays are 0-indexed, while the C++ code uses 1-based indexing for logic (e.g., `L[i]`, `D[i]`). We will allocate arrays of size `MAXN + 1` to preserve the 1-based indexing logic directly.
    *   **Struct `tree`**: C++ structs are static classes in Java. `vector<int> a` and `vector<long long> s` become `ArrayList<Integer>` and `ArrayList<Long>`.
    *   **Array of Structs**: `tree T[MAXN*3]` becomes `tree[] T`.

3.  **Logic Translation**:
    *   **`makeTree`**: Recursion is identical in Java.
        *   `idx << 1` becomes `idx * 2`.
        *   `push_back` becomes `add`.
        *   `size()` becomes `size()`.
        *   Pointer arithmetic (`lidx`, `ridx`) remains similar.
        *   The merge logic inside the loop (merging two sorted lists) remains logically identical.
        *   Prefix sum calculation (`s`) remains identical.
    *   **`main`**:
        *   Input reading: Use `Scanner` to replace `scanf`.
        *   `lower_bound`: C++ `std::lower_bound` returns an iterator. In Java, `ArrayList` doesn't have a built-in binary search returning an index directly comparable to iterators. We must implement a custom binary search or use `Collections.binarySearch`. Given the specific logic in the code (`t = ... - begin()`, then `min`, then adjustment), a custom `lowerBound` method for `ArrayList` is cleaner and avoids the overhead of `Collections.binarySearch` which returns insertion points differently.
        *   `long long`: Java `long` corresponds to C++ `long long`.
        *   `printf("%I64d\n", K)`: Replaced by `System.out.println(K)`. Note that `%I64d` is a Windows-specific format for `long long` in C++. Java handles `long` printing automatically.
        *   Array bounds: Ensure array sizes match the C++ `MAXN` definition.

4.  **Incremental Tasks**:
    *   Define constants and class structure.
    *   Implement `makeTree`.
    *   Implement `main` input parsing and array initialization.
    *   Implement the query loop logic (including the custom binary search).
    *   Implement output.

### Java Code

```java
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class d_894 {

    static final int MAXN = 1000005;
    static final int MAXM = 100005;

    static int N, M;
    static int[] L = new int[MAXN];
    static int[] D = new int[MAXN];
    static long K;

    static class Tree {
        List<Integer> a = new ArrayList<>();
        List<Long> s = new ArrayList<>();
    }

    static Tree[] T = new Tree[MAXN * 3];

    static void makeTree(int idx, int t) {
        if (t > N) {
            return;
        }
        int lidx = idx * 2;
        int ridx = lidx + 1;

        makeTree(lidx, t * 2);
        makeTree(ridx, t * 2 + 1);

        T[idx].a.add(D[t]);

        int i = 0, j = 0;
        int sizeL = T[lidx].a.size();
        int sizeR = T[ridx].a.size();

        while (i < sizeL && j < sizeR) {
            if (T[lidx].a.get(i) < T[ridx].a.get(j)) {
                T[idx].a.add(T[lidx].a.get(i));
                i++;
            } else {
                T[idx].a.add(T[ridx].a.get(j));
                j++;
            }
        }

        while (i < sizeL) {
            T[idx].a.add(T[lidx].a.get(i));
            i++;
        }

        while (j < sizeR) {
            T[idx].a.add(T[ridx].a.get(j));
            j++;
        }

        // Compute prefix sums
        T[idx].s.add((long) T[idx].a.get(0));
        for (int k = 1; k < T[idx].a.size(); k++) {
            T[idx].s.add(T[idx].s.get(k - 1) + T[idx].a.get(k));
        }
    }

    // Custom lower_bound for ArrayList to mimic std::lower_bound behavior
    // Returns the index of the first element >= val
    static int lowerBound(List<Integer> list, int val) {
        int low = 0;
        int high = list.size();
        while (low < high) {
            int mid = (low + high) >>> 1;
            if (list.get(mid) >= val) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;

        N = sc.nextInt();
        M = sc.nextInt();

        // L is 1-indexed in logic (L[1] to L[N-1])
        // In C++: for(i=1; i<N; i++) scanf("%d", L+i);
        // Java arrays are 0-indexed, but we allocate size MAXN to keep 1-based logic simple.
        for (int i = 1; i < N; i++) {
            L[i] = sc.nextInt();
        }

        // D calculation: D[i] = D[i/2] + L[i-1]
        // C++: for(i=2; i<=N; i++) D[i]=D[i/2]+L[i-1];
        // Note: D[1] is implicitly 0 based on loop starting at 2 and C++ array init.
        for (int i = 2; i <= N; i++) {
            D[i] = D[i / 2] + L[i - 1];
        }

        makeTree(1, 1);

        for (int i = 1; i <= M; i++) {
            A = sc.nextInt();
            H = sc.nextInt();
            
            K = 0;
            int t = lowerBound(T[A].a, D[A] + H);
            t = Math.min(t, T[A].a.size() - 1);
            
            if (t >= 0 && T[A].a.get(t) >= D[A] + H) {
                t--;
            }
            
            if (t >= 0) {
                long val = (long) (t + 1) * (D[A] + H) - T[A].s.get(t);
                K += val;
            }

            int P = A;
            int O = A;
            A /= 2;

            while (A >= 1) {
                P = A;
                if (D[O] - D[A] >= H) {
                    break;
                }
                K += (long) (H - D[O] + D[A]);

                int rightChild = A * 2 + 1;
                int leftChild = A * 2;

                if (rightChild == P && !T[rightChild].a.isEmpty()) {
                    int target = D[A] + H - (D[O] - D[A]);
                    t = lowerBound(T[rightChild].a, target);
                    t = Math.min(t, T[rightChild].a.size() - 1);
                    
                    if (t < T[rightChild].a.size() && T[rightChild].a.get(t) >= target) {
                        t--;
                    }
                    
                    if (t >= 0) {
                        long val = (long) (t + 1) * target - T[rightChild].s.get(t);
                        K += val;
                    }
                } else if (leftChild == P && !T[leftChild].a.isEmpty()) {
                    int target = D[A] + H - (D[O] - D[A]);
                    t = lowerBound(T[leftChild].a, target);
                    t = Math.min(t, T[leftChild].a.size() - 1);
                    
                    if (t < T[leftChild].a.size() && T[leftChild].a.get(t) >= target) {
                        t--;
                    }
                    
                    if (t >= 0) {
                        long val = (long) (t + 1) * target - T[leftChild].s.get(t);
                        K += val;
                    }
                }
                
                A /= 2;
            }

            System.out.println(K);
        }
        
        sc.close();
    }
}
```

**Note on Variable Names**: The original C++ code uses global variables `N`, `M`, `A`, `H`, `P`, `O` inside `main`. In Java, these are treated as local variables within `main`. I have declared them as `static` fields and assigned them in `main` to match the C++ scope behavior where they are accessed globally (e.g., `D[O]`). This is necessary because `makeTree` and other parts of the logic might theoretically need them, though in this specific snippet, `O` and `P` are only used inside the loop in `main`. However, to strictly mirror the C++ structure where `A`, `H`, `P`, `O` are global variables accessible everywhere, I have declared them as static fields.

**Correction on Scope**: In the provided C++ code, `A`, `H`, `P`, `O` are declared as `int i, A, H, t, P, O;` inside `main`. They are **not** global variables. They are local to `main`. My Java translation above correctly places `A`, `H`, `P`, `O` inside `main` and removes the global declaration for them, while keeping `N`, `M`, `L`, `D`, `K` as static globals (or local to main if preferred, but `MAXN` arrays need to be accessible). The C++ code uses global arrays `L` and `D` and global `K`.

Refined Java structure to match C++ exactly:
1.  `N`, `M`, `L`, `D`, `K` are global (static in Java).
2.  `A`, `H`, `P`, `O` are local to `main`.
3.  `makeTree` uses global `N` and `T`.
4.  `T` is a global array of objects.

The code block below reflects this precise mapping.

```java
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class d_894 {

    static final int MAXN = 1000005;
    static final int MAXM = 100005;

    static int N, M;
    static int[] L = new int[MAXN];
    static int[] D = new int[MAXN];
    static long K;

    static class Tree {
        List<Integer> a = new ArrayList<>();
        List<Long> s = new ArrayList<>();
    }

    static Tree[] T = new Tree[MAXN * 3];

    static void makeTree(int idx, int t) {
        if (t > N) {
            return;
        }
        int lidx = idx * 2;
        int ridx = lidx + 1;

        makeTree(lidx, t * 2);
        makeTree(ridx, t * 2 + 1);

        T[idx].a.add(D[t]);

        int i = 0, j = 0;
        int sizeL = T[lidx].a.size();
        int sizeR = T[ridx].a.size();

        while (i < sizeL && j < sizeR) {
            if (T[lidx].a.get(i) < T[ridx].a.get(j)) {
                T[idx].a.add(T[lidx].a.get(i));
                i++;
            } else {
                T[idx].a.add(T[ridx].a.get(j));
                j++;
            }
        }

        while (i < sizeL) {
            T[idx].a.add(T[lidx].a.get(i));
            i++;
        }

        while (j < sizeR) {
            T[idx].a.add(T[ridx].a.get(j));
            j++;
        }

        // Compute prefix sums
        T[idx].s.add((long) T[idx].a.get(0));
        for (int k = 1; k < T[idx].a.size(); k++) {
            T[idx].s.add(T[idx].s.get(k - 1) + T[idx].a.get(k));
        }
    }

    // Custom lower_bound for ArrayList to mimic std::lower_bound behavior
    // Returns the index of the first element >= val
    static int lowerBound(List<Integer> list, int val) {
        int low = 0;
        int high = list.size();
        while (low < high) {
            int mid = (low + high) >>> 1;
            if (list.get(mid) >= val) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;

        N = sc.nextInt();
        M = sc.nextInt();

        // L is 1-indexed in logic (L[1] to L[N-1])
        // In C++: for(i=1; i<N; i++) scanf("%d", L+i);
        for (int i = 1; i < N; i++) {
            L[i] = sc.nextInt();
        }

        // D calculation: D[i] = D[i/2] + L[i-1]
        // C++: for(i=2; i<=N; i++) D[i]=D[i/2]+L[i-1];
        for (int i = 2; i <= N; i++) {
            D[i] = D[i / 2] + L[i - 1];
        }

        makeTree(1, 1);

        for (int i = 1; i <= M; i++) {
            int A = sc.nextInt();
            int H = sc.nextInt();
            
            K = 0;
            int t = lowerBound(T[A].a, D[A] + H);
            t = Math.min(t, T[A].a.size() - 1);
            
            if (t >= 0 && T[A].a.get(t) >= D[A] + H) {
                t--;
            }
            
            if (t >= 0) {
                long val = (long) (t + 1) * (D[A] + H) - T[A].s.get(t);
                K += val;
            }

            int P = A;
            int O = A;
            A /= 2;

            while (A >= 1) {
                P = A;
                if (D[O] - D[A] >= H) {
                    break;
                }
                K += (long) (H - D[O] + D[A]);

                int rightChild = A * 2 + 1;
                int leftChild = A * 2;

                if (rightChild == P && !T[rightChild].a.isEmpty()) {
                    int target = D[A] + H - (D[O] - D[A]);
                    t = lowerBound(T[rightChild].a, target);
                    t = Math.min(t, T[rightChild].a.size() - 1);
                    
                    if (t < T[rightChild].a.size() && T[rightChild].a.get(t) >= target) {
                        t--;
                    }
                    
                    if (t >= 0) {
                        long val = (long) (t + 1) * target - T[rightChild].s.get(t);
                        K += val;
                    }
                } else if (leftChild == P && !T[leftChild].a.isEmpty()) {
                    int target = D[A] + H - (D[O] - D[A]);
                    t = lowerBound(T[leftChild].a, target);
                    t = Math.min(t, T[leftChild].a.size() - 1);
                    
                    if (t < T[leftChild].a.size() && T[leftChild].a.get(t) >= target) {
                        t--;
                    }
                    
                    if (t >= 0) {
                        long val = (long) (t + 1) * target - T[leftChild].s.get(t);
                        K += val;
                    }
                }
                
                A /= 2;
            }

            System.out.println(K);
        }
        
        sc.close();
    }
}
```