Translate this C++ code to Java code. The main class name should be c_1391. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
// RADHASOAMI , WITH THE GRACE OF HUZUR I PROMISE TO FIGHT TILL THE LAST SECOND OF EVERY CONTEST AND CODE TO MY FULL POTENTIAL ......

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

#define ll long long int
#define mod 1000000007

using namespace std;

// ====================  FUNCTIONS FOR INPUT AND OUTPUT OF VECTORS =======================================================

void input(vector < ll > &arr)
{
   for(int i = 0;i < arr.size();i++)
      cin >> arr[i];
}

void output(vector < ll > &arr)
{
   for(int i = 0;i < arr.size();i++)
      cout << arr[i] << " ";

   cout << "\n";
}

// ==============================  FOR MATHEMATICAL FUNCTIONS =============================================================

ll gcd(ll a,ll b)
{
   if(b==0)
     return a;

   return gcd(b,a%b);
}

ll power(ll a,ll b)
{
    if(b==0)
      return 1;

    if(b==1)
      return a;

    ll smallans=power(a,b/2);
    ll myans=(smallans*smallans)%mod;

    if((b&1))
      myans=(myans*a)%mod;

    return myans;
}

ll multiply(ll a,ll b)
{
   ll ans=((a%mod)*(b%mod))%mod;

   return ans;
}

ll divide(ll a,ll b)
{
   return multiply(a,power(b,mod-2));
}

// ============================ SEGMENT TREE FOR DEFAULT MINIMUM QUERY ==================================================

void manageLazy(vector <ll> &tree,vector <ll> &lazy,ll idx)
{
   tree[2*idx + 1] += lazy[idx];
   lazy[2*idx + 1] += lazy[idx];

   tree[2*idx + 2] += lazy[idx]; 
   lazy[2*idx + 2] += lazy[idx];

   lazy[idx] = 0;
}

void build(vector <ll> &tree,vector <ll> &arr,ll left,ll right,ll idx)
{
    if(left == right)
    {
       tree[idx] = arr[left];
       return;
    }

    ll mid = (left + right) / 2;
    build(tree , arr , left , mid , 2*idx + 1);
    build(tree , arr , mid + 1 , right , 2*idx + 2);

    tree[idx] = min(tree[2*idx + 1],tree[2*idx + 2]);
}

void update(vector <ll> &tree,vector <ll> &lazy,ll tl,ll tr,ll l,ll r,ll idx,ll val)
{
   if(l > r)
     return;

   if(l == tl && tr == r)
   {
      tree[idx] += val;
      lazy[idx] += val;
      return;
   }

   manageLazy(tree,lazy,idx);
   ll mid = (tl + tr) / 2;

   update(tree,lazy,tl,mid,l,min(r,mid),2*idx + 1,val);
   update(tree,lazy,mid + 1,tr,max(l,mid + 1),r,2*idx + 2,val);

   tree[idx] = min(tree[2*idx + 1],tree[2*idx + 2]);

}

ll query(vector <ll> &tree,vector<ll> & lazy,ll tl,ll tr,ll l,ll r,ll idx)
{
   if(l > r)
     return 1e18;

   if(l <= tl && tr <= r)
     return tree[idx];

   manageLazy(tree,lazy,idx);
   ll mid = (tl + tr) / 2;

   ll a = query(tree,lazy,tl,mid,l,min(r,mid),2*idx + 1);
   ll b = query(tree,lazy,mid + 1,tr,max(l,mid + 1),r,2*idx + 2);

   return min(a,b);
}

// ==================================  SPARSE TABLE FOR DEFAULT MINIMUM QUERY ==================================================

void precompute_min(vector < vector < ll > > &sparsetable , vector < ll > &a)
{
   int n = sparsetable.size();
   int p = sparsetable[0].size();

   for(int i = 0;i < n;i++)  
     sparsetable[i][0] = a[i];

   for(int j = 1;j < p;j++)
   {
      for(int i = 0;i + (1 << j) <= n;i++)
        sparsetable[i][j] = min(sparsetable[i][j - 1] , sparsetable[i + (1 << (j - 1))][j - 1]);
   }
   
}

ll minquery(vector < vector < ll > > &sparsetable , vector < ll > &log , ll l , ll r)
{
   ll range = r - l + 1;
   if(range == 0)  return sparsetable[l][0];
   ll j = log[range];
   return min(sparsetable[l][j] , sparsetable[r - (1 << j) + 1][j]);
}

//========================== BINARY INDEX TREE =========================================================================

void update(vector<ll> &tree,ll index,ll val)
{
   index++;
   while(index < tree.size())
   {
      tree[index]=(tree[index] + val) %mod;
 
      index+=index&(-index);
   }
}
 
ll calculate(vector<ll> &tree,ll index)
{
   ll sum=0;
   index++;
   while(index > 0)
   {
      sum=(sum + tree[index])%mod;
 
      index-=index&(-index);
   }
 
   return sum;
}

//=========================== FOR DISJOINT SET UNION ====================================================================

ll findpar(ll p,vector<ll> &parent)
{
    if(parent[p]==p)
     return p;

    parent[p]=findpar(parent[p],parent);

    return parent[p];
}

void merge(ll a, ll b,vector<ll> &parent,vector<ll> &size_) 
{
    a = findpar(a,parent);
    b = findpar(b,parent);
    
    if (a != b) 
    {
        if (size_[a] < size_[b])
             swap(a, b);
             
        parent[b] = a;
        size_[a] += size_[b];
    }
}

//   ====================================== FOR STORING AND COUNTING THE PRIMES USING SIEVE ============================

void sieve(vector<bool> &primes,vector<ll> &count)
{
   for(int i=2;i<primes.size();i++)
   {
      if(primes[i])
      {
         count.push_back(i);
         for(int j=i*i;j<primes.size();j+=i)
           primes[j]=false;
      }
   }
}

// =====================================================================================================================

void solve()
{
   ll n;
   cin >> n;

   ll ans = 1;
   for(ll i = 1;i <= n;i++) 
     ans = (ans * i) % mod;
   
   ll p = power(2, n - 1);
   ans = ((ans - p) % mod + mod) % mod;
   cout << ans << "\n";
}

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);
   cout.tie(NULL);
   #ifndef ONLINE_JUDGE
      freopen("input2.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   #endif

   int t = 1;
   // cin >> t;

   while(t--)
   {

      solve();
      
   }

   return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Structure and Class**: The C++ code uses a global `main` function. In Java, this must be encapsulated in a class named `c_1391` with a `main` method.
2.  **Data Types**: C++ uses `long long` (aliased as `ll`), which corresponds to Java's `long`. `int` corresponds to Java's `int`.
3.  **Input/Output**: C++ uses `cin` and `cout`. Java uses `Scanner` or `BufferedReader` for input and `System.out.println` for output. Given the complexity of the code and potential speed issues, `BufferedReader` and `StringTokenizer` are preferred for efficiency, but `Scanner` is easier to read and sufficient for this specific logic (which is $O(N)$ or $O(N \log N)$). I will use `Scanner` for simplicity as the logic is straightforward.
4.  **Vectors**: C++ `std::vector` is translated to Java `ArrayList<Long>`.
5.  **Pointers and References**: C++ passes references (e.g., `vector<ll> &arr`). Java passes references by value, so we just pass the `ArrayList` object to the methods.
6.  **Global Variables**: The C++ code defines `mod` and uses global `tree` and `lazy` arrays. In Java, these must be class-level static variables or passed as arguments. Passing arguments is cleaner for recursion and avoids static state issues.
7.  **Mathematical Functions**:
    *   `gcd`: Direct translation of Euclidean algorithm.
    *   `power`: Modular exponentiation. Java's `Math.pow` returns `double`, so we must implement integer modular exponentiation manually.
    *   `multiply`: Modular multiplication.
    *   `divide`: Modular inverse division (using Fermat's Little Theorem).
8.  **Segment Tree**:
    *   C++ uses arrays (`tree`, `lazy`). Java uses `ArrayList` or `long[]`. Arrays are slightly more performant but require dynamic resizing logic if not fixed size. Since the input size `n` is known, we can allocate arrays of size `4*n`.
    *   `min` function is `Math.min`.
9.  **Binary Indexed Tree (BIT)**: Direct translation of the Fenwick Tree logic using `long[]`.
10. **Disjoint Set Union (DSU)**: Direct translation of the parent and size arrays logic.
11. **Sieve**: Direct translation using a boolean array.
12. **Main Logic**: The `solve` function calculates $(N!) - 2^{N-1} \pmod{10^9+7}$.

**Incremental Tasks**:
1.  Define the class and `main` method.
2.  Implement input/output utilities.
3.  Implement mathematical utilities (`power`, `multiply`, `divide`, `gcd`).
4.  Implement Segment Tree functions.
5.  Implement Sparse Table functions.
6.  Implement BIT functions.
7.  Implement DSU functions.
8.  Implement Sieve function.
9.  Implement `solve` method.

```java
import java.util.*;
import java.io.*;

public class c_1391 {

    static final long MOD = 1000000007L;

    // ====================  FUNCTIONS FOR INPUT AND OUTPUT OF VECTORS =======================================================

    static void input(ArrayList<Long> arr) {
        // In Java, reading into an ArrayList usually involves adding elements one by one.
        // However, since the logic relies on the size, we can read into a temp list or directly 
        // if we knew the size. The C++ code assumes the vector is already sized or resized.
        // For this specific problem, let's assume the caller passes an empty list or a list 
        // that needs to be filled.
        // To make it robust, let's assume the method fills the list.
        // But wait, the C++ code does: cin >> arr[i]. This implies arr is already sized.
        // In Java, ArrayList doesn't have a fixed size. We will assume the list is pre-sized or we resize it.
        // For the sake of this translation, I will assume the list is pre-filled or resized.
        // Actually, looking at the main logic, the `solve` function doesn't use the `input` function 
        // for the array `arr`, it just reads `n`. The Segment Tree and Sparse Table functions 
        // take the array as input.
        // Let's assume the caller prepares the ArrayList with size `n`.
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < arr.size(); i++) {
            arr.set(i, sc.nextLong());
        }
    }

    static void output(ArrayList<Long> arr) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.size(); i++) {
            sb.append(arr.get(i)).append(" ");
        }
        System.out.println(sb.toString().trim());
    }

    // ==============================  FOR MATHEMATICAL FUNCTIONS =============================================================

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long power(long a, long b) {
        long res = 1;
        a %= MOD;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    static long multiply(long a, long b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    static long divide(long a, long b) {
        return multiply(a, power(b, MOD - 2));
    }

    // ============================ SEGMENT TREE FOR DEFAULT MINIMUM QUERY ==================================================

    // We pass arrays as references in Java by passing the array object.
    // We will use long[] for tree and lazy.
    // Size needs to be 4 * n.
    
    static void manageLazy(long[] tree, long[] lazy, int idx, long val) {
        // In C++, lazy[idx] += lazy[idx]. Here we pass the value to add.
        // The C++ code: tree[2*idx + 1] += lazy[idx]; lazy[2*idx + 1] += lazy[idx];
        // We need to know the index of the child nodes.
        // Since we don't have the parent index passed to children inside this function in C++,
        // we assume the caller knows the children indices or we pass the current index 
        // and the function updates children of idx.
        // Wait, the C++ code: manageLazy(tree, lazy, idx).
        // Inside manageLazy: tree[2*idx + 1] += lazy[idx]; ...
        // So we pass the current node index.
        
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        
        tree[leftChild] += val;
        lazy[leftChild] += val;
        tree[rightChild] += val;
        lazy[rightChild] += val;
        
        // In C++, lazy[idx] is set to 0 after pushing. 
        // In Java, we just update the children. The parent lazy[idx] is handled by the caller 
        // or passed as 0 if not needed. 
        // Actually, looking at the C++ code, lazy[idx] is set to 0 inside manageLazy.
        // But in Java, we can't easily modify the array element by reference if we don't have the index.
        // We have the index `idx`. So we set lazy[idx] = 0.
        // Wait, the C++ code updates the children and then sets lazy[idx] = 0.
        // So:
        // tree[leftChild] += lazy[idx];
        // lazy[leftChild] += lazy[idx];
        // ...
        // lazy[idx] = 0;
        
        // Let's refactor slightly to match C++ logic exactly.
        // We need to know the value of lazy[idx] before it is cleared.
        // But the function signature is void manageLazy(..., int idx).
        // So we can read lazy[idx].
        long currentLazy = lazy[idx];
        tree[leftChild] += currentLazy;
        lazy[leftChild] += currentLazy;
        tree[rightChild] += currentLazy;
        lazy[rightChild] += currentLazy;
        lazy[idx] = 0; // Clear lazy at current node
    }

    static void build(long[] tree, long[] arr, int left, int right, int idx) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }

        int mid = (left + right) / 2;
        build(tree, arr, left, mid, 2 * idx + 1);
        build(tree, arr, mid + 1, right, 2 * idx + 2);

        tree[idx] = Math.min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    static void update(long[] tree, long[] lazy, int tl, int tr, int l, int r, int idx, long val) {
        if (l > r)
            return;

        if (l == tl && tr == r) {
            tree[idx] += val;
            lazy[idx] += val;
            return;
        }

        manageLazy(tree, lazy, idx, 0); // We need to pass the value to add? 
        // Wait, the C++ code: manageLazy(tree, lazy, idx);
        // Inside: tree[child] += lazy[idx].
        // So we don't pass val here. We just use lazy[idx].
        // But wait, in the C++ update function, it calls manageLazy(tree, lazy, idx).
        // It does NOT pass val.
        // So we must implement manageLazy to take just the index and read from lazy[idx].
        
        // Let's fix the signature of manageLazy to match C++ exactly.
        // C++: void manageLazy(vector <ll> &tree,vector <ll> &lazy,ll idx)
        // It reads lazy[idx] and adds to children.
        
        // Correct logic for manageLazy:
        // long currentLazy = lazy[idx];
        // tree[2*idx+1] += currentLazy;
        // lazy[2*idx+1] += currentLazy;
        // ...
        // lazy[idx] = 0;
        
        // Let's re-implement manageLazy to be correct based on C++ logic.
        // I will remove the `val` parameter from manageLazy and just use the global/lazy array content.
        // But wait, in Java, if I pass the array, I can read lazy[idx].
        // So:
        // long val = lazy[idx];
        // tree[leftChild] += val;
        // lazy[leftChild] += val;
        // ...
        // lazy[idx] = 0;
        
        // Re-defining manageLazy inside this block for clarity or just using the one I wrote above?
        // The one above takes `val`. The C++ code doesn't.
        // I will update the signature to `void manageLazy(long[] tree, long[] lazy, int idx)`.
        
        // Let's restart the method definitions to be consistent.
        
        // Re-declaring manageLazy to match C++:
        // void manageLazy(long[] tree, long[] lazy, int idx)
        // {
        //    int left = 2*idx + 1;
        //    int right = 2*idx + 2;
        //    long val = lazy[idx];
        //    tree[left] += val;
        //    lazy[left] += val;
        //    tree[right] += val;
        //    lazy[right] += val;
        //    lazy[idx] = 0;
        // }
        
        // However, to avoid code duplication, I will use a helper method.
        // But wait, I need to fix the `update` function call.
        // In C++: manageLazy(tree, lazy, idx);
        // So I will implement `manageLazy` without `val`.
        
        // Re-writing manageLazy logic inline or as a static method without val.
        // Let's assume the static method signature below.
        
        // Re-defining manageLazy:
        // static void manageLazy(long[] tree, long[] lazy, int idx) {
        //     int left = 2 * idx + 1;
        //     int right = 2 * idx + 2;
        //     long val = lazy[idx];
        //     tree[left] += val;
        //     lazy[left] += val;
        //     tree[right] += val;
        //     lazy[right] += val;
        //     lazy[idx] = 0;
        // }
        
        // And update calls manageLazy(tree, lazy, idx).
        // This requires me to change the code structure.
        
        // Let's just use the logic directly in update to avoid signature confusion.
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        long val = lazy[idx];
        
        tree[leftChild] += val;
        lazy[leftChild] += val;
        tree[rightChild] += val;
        lazy[rightChild] += val;
        lazy[idx] = 0;
    }

    static long query(long[] tree, long[] lazy, int tl, int tr, int l, int r, int idx) {
        if (l > r)
            return 1000000000000000000L; // 1e18 equivalent for long

        if (l <= tl && tr <= r)
            return tree[idx];

        // Push lazy
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        long val = lazy[idx];
        
        tree[leftChild] += val;
        lazy[leftChild] += val;
        tree[rightChild] += val;
        lazy[rightChild] += val;
        lazy[idx] = 0;

        int mid = (tl + tr) / 2;

        long a = query(tree, lazy, tl, mid, l, Math.min(r, mid), leftChild);
        long b = query(tree, lazy, mid + 1, tr, Math.max(l, mid + 1), r, rightChild);

        return Math.min(a, b);
    }

    // ==================================  SPARSE TABLE FOR DEFAULT MINIMUM QUERY ==================================================

    static void precompute_min(ArrayList<ArrayList<Long>> sparsetable, ArrayList<Long> a) {
        int n = a.size();
        int p = (int) Math.ceil(Math.log(n) / Math.log(2)) + 1; 
        // Actually, the C++ code uses sparsetable.size() which is n.
        // And sparsetable[0].size() which is p.
        // In Java ArrayList, we need to initialize the structure.
        // The C++ code assumes sparsetable is initialized with size n and columns p.
        // We will create it here.
        
        // Re-calculating p based on n
        int logN = 0;
        if (n > 0) {
            logN = 32 - Integer.numberOfLeadingZeros(n);
        }
        // p is the number of columns needed. 
        // 1<<j <= n. Max j is logN. So columns 0 to logN. Size is logN + 1.
        // The C++ code: for(int j = 1; j < p; j++). So p is the number of columns.
        // We'll set p = logN + 1.
        
        // Let's just use the logic from C++:
        // int n = sparsetable.size();
        // int p = sparsetable[0].size();
        // This implies the structure is already built.
        // Since I am writing the whole program, I will build it in `solve`.
        // But for the function signature, I will keep it as is but ensure `solve` builds it.
        // Wait, `solve` calls `precompute_min`.
        // So I must initialize `sparsetable` before calling `precompute_min` or pass the size.
        // The C++ code assumes `sparsetable` is already allocated.
        // I will allocate it in `solve`.
        
        // Let's rewrite precompute_min to accept n.
        // No, I'll stick to the C++ style: pass the lists.
        // I will ensure the lists are sized correctly in `solve`.
        
        // Logic inside precompute_min:
        int n = a.size();
        // We need to determine p.
        // In C++, p = sparsetable[0].size().
        // So we need to ensure the first list has enough size.
        // Let's assume the list is sized correctly in `solve`.
        // We will just implement the logic.
        
        for (int i = 0; i < n; i++) {
            sparsetable.get(i).set(0, a.get(i));
        }

        for (int j = 1; j < sparsetable.get(0).size(); j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                sparsetable.get(i).set(j, Math.min(sparsetable.get(i).get(j - 1), sparsetable.get(i + (1 << (j - 1))).get(j - 1)));
            }
        }
    }

    static long minquery(ArrayList<ArrayList<Long>> sparsetable, ArrayList<Long> log, int l, int r) {
        long range = r - l + 1;
        if (range == 0) return sparsetable.get(l).get(0);
        
        // Find log[range]
        // In C++, log is precomputed.
        // In Java, we can compute log2 on the fly or use precomputed log array.
        // The C++ code passes a precomputed `log` vector.
        // We will assume `log` is passed as a precomputed array in `solve`.
        // Or we can compute it.
        // Let's use a helper to get log2.
        int j = 0;
        while ((1L << (j + 1)) <= range) {
            j++;
        }
        
        return Math.min(sparsetable.get(l).get(j), sparsetable.get(r - (1 << j) + 1).get(j));
    }

    //=========================== FOR DISJOINT SET UNION ====================================================================

    static int findpar(int p, int[] parent) {
        if (parent[p] == p)
            return p;
        parent[p] = findpar(parent[p], parent);
        return parent[p];
    }

    static void merge(int a, int b, int[] parent, long[] size_) {
        a = findpar(a, parent);
        b = findpar(b, parent);
        
        if (a != b) {
            if (size_[a] < size_[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            size_[a] += size_[b];
        }
    }

    //   ====================================== FOR STORING AND COUNTING THE PRIMES USING SIEVE ============================

    static void sieve(boolean[] primes, long[] count) {
        // count is a list to store primes.
        // In C++, count is a vector.
        // We will use an ArrayList for count.
        // Wait, the C++ code: count.push_back(i).
        // So count is a dynamic list.
        // But the signature says `vector<ll> &count`.
        // I will use ArrayList for count.
        // But the method signature in C++ is `void sieve(vector<bool> &primes, vector<ll> &count)`.
        // In Java:
        // static void sieve(boolean[] primes, ArrayList<Long> count)
        
        // However, the C++ code iterates `i` from 2 to `primes.size()`.
        // So `primes` must be sized up to the limit.
        // Let's assume `primes` is a boolean array of size `limit`.
        // And `count` is an ArrayList.
        
        // Logic:
        // for(int i=2;i<primes.size();i++)
        // This implies `primes` is an array/list.
        // In Java, `primes` is boolean[].
        // `primes.size()` is not valid for arrays.
        // So I will use `primes.length`.
        
        // Also `count` is a list.
        // In C++, `count` is a vector.
        // So `count.push_back(i)` is `count.add(i)`.
        
        // Let's assume `primes` is passed as a boolean array and `count` as ArrayList.
        // But wait, the C++ code passes `vector<bool> &primes`.
        // I will use boolean[] for primes.
        // And ArrayList<Long> for count.
        
        // But wait, the C++ code: `for(int i=2;i<primes.size();i++)`.
        // This implies `primes` is a vector.
        // If I pass a boolean array, I need to know the size.
        // I will pass the limit `n` to the sieve function or use a boolean array of known size.
        // To keep it simple, I will assume `primes` is a boolean array of size `n+1`.
        // And `count` is an ArrayList.
        
        // Let's adjust the signature to:
        // static void sieve(boolean[] primes, ArrayList<Long> count)
        // But how do we know the size of `primes`?
        // The C++ code uses `primes.size()`.
        // I will assume `primes` is passed as a boolean array with sufficient size.
        // And I will use `primes.length`.
        
        // Re-checking C++ code: `void sieve(vector<bool> &primes,vector<ll> &count)`
        // I will translate this to `void sieve(boolean[] primes, ArrayList<Long> count)`.
        // But I need to know the limit.
        // I will assume the caller passes `primes` with size `limit`.
        // And `count` is empty.
        
        // Wait, the C++ code iterates `i` from 2 to `primes.size()`.
        // So `primes` must be sized.
        // I will assume `primes` is a boolean array.
        
        // Let's implement the logic.
        
        // Note: The C++ code uses `count` to store primes.
        // `count` is a vector.
        // `count.push_back(i)`.
        // `primes[j] = false`.
        
        // I will implement:
        // for (int i = 2; i < primes.length; i++) {
        //    if (primes[i]) {
        //        count.add(i);
        //        for (int j = i * i; j < primes.length; j += i)
        //            primes[j] = false;
        //    }
        // }
        
        // Wait, the C++ code uses `primes.size()`.
        // If I pass a boolean array, I use `primes.length`.
        // If I pass an ArrayList, I use `primes.size()`.
        // I will use boolean[] for `primes` and ArrayList for `count`.
        // But I need to pass the size of the boolean array.
        // I will assume the array is sized correctly.
        
        // Actually, to match the C++ code exactly, I should probably use ArrayList for `primes` too?
        // `vector<bool>` is dynamic.
        // So:
        // static void sieve(ArrayList<Boolean> primes, ArrayList<Long> count)
        // for (int i = 2; i < primes.size(); i++)
        // This works.
        
        // Let's use ArrayList for `primes` to match the C++ signature.
        // And `count` as ArrayList.
        
        // Logic:
        // for (int i = 2; i < primes.size(); i++) {
        //    if (primes.get(i)) {
        //        count.add(i);
        //        for (int j = i * i; j < primes.size(); j += i)
        //            primes.set(j, false);
        //    }
        // }
        
        // Wait, the C++ code uses `vector<bool> &primes`.
        // I will use `ArrayList<Boolean> primes`.
        // And `count` is `ArrayList<Long>`.
        
        // But wait, the C++ code: `count.push_back(i)`.
        // So `count` is populated.
        
        // I will implement the sieve using ArrayLists.
        
        // Re-writing the method:
        // static void sieve(ArrayList<Boolean> primes, ArrayList<Long> count)
        // {
        //    for(int i=2;i<primes.size();i++)
        //    {
        //       if(primes.get(i))
        //       {
        //          count.add(i);
        //          for(int j=i*i;j<primes.size();j+=i)
        //             primes.set(j, false);
        //       }
        //    }
        // }
        
        // This matches the C++ logic perfectly.
    }
    
    // I will re-implement the sieve method with ArrayLists.
    static void sieve(ArrayList<Boolean> primes, ArrayList<Long> count) {
        for (int i = 2; i < primes.size(); i++) {
            if (primes.get(i)) {
                count.add(i);
                for (int j = i * i; j < primes.size(); j += i)
                    primes.set(j, false);
            }
        }
    }
    
    // =====================================================================================================================

    static void solve(Scanner sc) {
        int n = sc.nextInt();
        
        // Calculate ans = (n!) - 2^(n-1) % mod
        long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % MOD;
        }
        
        long p = power(2, n - 1);
        ans = ((ans - p) % MOD + MOD) % MOD;
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Handle potential IO redirection logic if needed, but standard IO is fine.
        // The C++ code has #ifdef ONLINE_JUDGE. 
        // We will ignore file redirection for standard Java IO unless specified.
        
        int t = 1;
        // sc.nextInt(); // Skip if needed, but C++ code has cin >> t.
        // Wait, the C++ code:
        // int t = 1;
        // cin >> t;
        // This is weird. It sets t=1, then tries to read t.
        // If input is empty, it might fail.
        // But usually, it reads t from input.
        // So I will read t.
        
        // Actually, looking at the C++ code:
        // int t = 1;
        // cin >> t;
        // This implies the first integer in input is t.
        // So I will read t.
        
        if (sc.hasNextInt()) {
            t = sc.nextInt();
        }

        while (t-- > 0) {
            solve(sc);
        }
    }
}
```

Wait, I need to make sure the code is complete and compiles.
The `solve` function in the C++ code does not take any arguments. It reads `n` from `cin`.
The Segment Tree and Sparse Table functions are defined but not called in `solve` in the provided C++ code.
Wait, let me check the `solve` function in the C++ code again.
```cpp
void solve()
{
   ll n;
   cin >> n;

   ll ans = 1;
   for(ll i = 1;i <= n;i++) 
     ans = (ans * i) % mod;
   
   ll p = power(2, n - 1);
   ans = ((ans - p) % mod + mod) % mod;
   cout << ans << "\n";
}
```
The `solve` function only calculates $N! - 2^{N-1} \pmod{10^9+7}$.
The Segment Tree, Sparse Table, BIT, and DSU functions are defined but **not used** in the `solve` function provided in the prompt.
This is likely a template or a partial solution where the `solve` function is minimal, and the helper functions are available for other problems or a more complex version.
However, I must translate the code as provided. I will not call the unused functions in `solve`.

One detail: `1e18` in C++ is `long long`. In Java, `1000000000000000000L` is `1e18`.
The `log` array in Sparse Table is not initialized in `solve` in the C++ code.
It seems the provided C++ code is a collection of utility functions and a simple `solve` function.
I will translate it exactly as is, including the unused functions.

Let's refine the Java code structure.
I will put all static methods in the class.
I will use `ArrayList` for vectors.
I will use `long[]` for arrays.
I will handle the `log` array in Sparse Table by either precomputing it or computing on the fly.
The C++ code has `vector<ll> &log`.
I will create a static method to precompute logs or just pass a precomputed list.
Since `solve` doesn't use it, I won't worry about initializing it.
But for completeness, I will implement `precompute_min` and `minquery` assuming the structures are passed correctly.

One issue: `1e18` in C++ is a double literal. `long long` max is approx `9e18`.
In Java, `1e18` is a double. I should use `1000000000000000000L`.

Let's do the translation.

```java
import java.util.*;
import java.io.*;

public class c_1391 {

    static final long MOD = 1000000007L;

    // ====================  FUNCTIONS FOR INPUT AND OUTPUT OF VECTORS =======================================================

    static void input(ArrayList<Long> arr) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < arr.size(); i++) {
            arr.set(i, sc.nextLong());
        }
    }

    static void output(ArrayList<Long> arr) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.size(); i++) {
            sb.append(arr.get(i)).append(" ");
        }
        System.out.println(sb.toString().trim());
    }

    // ==============================  FOR MATHEMATICAL FUNCTIONS =============================================================

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long power(long a, long b) {
        long res = 1;
        a %= MOD;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    static long multiply(long a, long b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    static long divide(long a, long b) {
        return multiply(a, power(b, MOD - 2));
    }

    // ============================ SEGMENT TREE FOR DEFAULT MINIMUM QUERY ==================================================

    static void manageLazy(long[] tree, long[] lazy, int idx) {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        long val = lazy[idx];
        
        tree[leftChild] += val;
        lazy[leftChild] += val;
        tree[rightChild] += val;
        lazy[rightChild] += val;
        
        lazy[idx] = 0;
    }

    static void build(long[] tree, long[] arr, int left, int right, int idx) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }

        int mid = (left + right) / 2;
        build(tree, arr, left, mid, 2 * idx + 1);
        build(tree, arr, mid + 1, right, 2 * idx + 2);

        tree[idx] = Math.min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    static void update(long[] tree, long[] lazy, int tl, int tr, int l, int r, int idx, long val) {
        if (l > r)
            return;

        if (l == tl && tr == r) {
            tree[idx] += val;
            lazy[idx] += val;
            return;
        }

        manageLazy(tree, lazy, idx);
        int mid = (tl + tr) / 2;

        update(tree, lazy, tl, mid, l, Math.min(r, mid), 2 * idx + 1, val);
        update(tree, lazy, mid + 1, tr, Math.max(l, mid + 1), r, 2 * idx + 2, val);

        tree[idx] = Math.min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    static long query(long[] tree, long[] lazy, int tl, int tr, int l, int r, int idx) {
        if (l > r)
            return 1000000000000000000L; // 1e18

        if (l <= tl && tr <= r)
            return tree[idx];

        manageLazy(tree, lazy, idx);
        int mid = (tl + tr) / 2;

        long a = query(tree, lazy, tl, mid, l, Math.min(r, mid), 2 * idx + 1);
        long b = query(tree, lazy, mid + 1, tr, Math.max(l, mid + 1), r, 2 * idx + 2);

        return Math.min(a, b);
    }

    // ==================================  SPARSE TABLE FOR DEFAULT MINIMUM QUERY ==================================================

    static void precompute_min(ArrayList<ArrayList<Long>> sparsetable, ArrayList<Long> a) {
        int n = a.size();
        int p = sparsetable.get(0).size();

        for (int i = 0; i < n; i++)  
            sparsetable.get(i).set(0, a.get(i));

        for (int j = 1; j < p; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                sparsetable.get(i).set(j, Math.min(sparsetable.get(i).get(j - 1), sparsetable.get(i + (1 << (j - 1))).get(j - 1)));
            }
        }
    }

    static long minquery(ArrayList<ArrayList<Long>> sparsetable, ArrayList<Long> log, int l, int r) {
        long range = r - l + 1;
        if (range == 0) return sparsetable.get(l).get(0);
        int j = 0;
        // Find log[range]
        // In C++, log is precomputed.
        // We will assume log array is passed.
        // But log is not passed in C++ solve.
        // So we compute it.
        while ((1L << (j + 1)) <= range) {
            j++;
        }
        return Math.min(sparsetable.get(l).get(j), sparsetable.get(r - (1 << j) + 1).get(j));
    }

    //=========================== FOR DISJOINT SET UNION ====================================================================

    static int findpar(int p, int[] parent) {
        if (parent[p] == p)
            return p;
        parent[p] = findpar(parent[p], parent);
        return parent[p];
    }

    static void merge(int a, int b, int[] parent, long[] size_) {
        a = findpar(a, parent);
        b = findpar(b, parent);
        
        if (a != b) {
            if (size_[a] < size_[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            size_[a] += size_[b];
        }
    }

    //   ====================================== FOR STORING AND COUNTING THE PRIMES USING SIEVE ============================

    static void sieve(ArrayList<Boolean> primes, ArrayList<Long> count) {
        for (int i = 2; i < primes.size(); i++) {
            if (primes.get(i)) {
                count.add(i);
                for (int j = i * i; j < primes.size(); j += i)
                    primes.set(j, false);
            }
        }
    }

    // =====================================================================================================================

    static void solve() {
        Scanner sc = new Scanner(System.in);
        // We need to read t from input?
        // The C++ code: int t = 1; cin >> t;
        // So we read t.
        // But solve() is called in a loop in main.
        // So solve() should not read t.
        // The C++ code has:
        // int t = 1;
        // cin >> t;
        // while(t--) { solve(); }
        // This means solve() reads n.
        
        int n = sc.nextInt();

        long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % MOD;
        }
        
        long p = power(2, n - 1);
        ans = ((ans - p) % MOD + MOD) % MOD;
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = 1;
        if (sc.hasNextInt()) {
            t = sc.nextInt();
        }

        while (t-- > 0) {
            solve();
        }
    }
}
```
Wait, the `solve` function in C++ reads `n` from `cin`.
The `main` function in C++ reads `t` from `cin`.
In my Java `main`, I read `t` and then call `solve()`.
Inside `solve()`, I read `n`.
This matches the C++ logic.

One small detail: `1e18` in C++ is a double.
In Java, `1000000000000000000L` is the integer equivalent.
The `power` function returns `long`.
The `query` function returns `long`.
So `1e18` should be `1000000000000000000L`.

One more thing: The C++ code has `#ifndef ONLINE_JUDGE`.
I will ignore the file redirection logic for simplicity unless it's critical.
I will keep the `Scanner` based IO.

The `log` array in `minquery` is not used in the C++ code's `solve` function.
I will compute `j` inside `minquery` to be safe, or assume it's passed.
Since `solve` doesn't use `minquery`, it doesn't matter.
But for completeness, I will compute it.

Final check on `manageLazy`.
C++: `tree[2*idx + 1] += lazy[idx];`
Java: `tree[2 * idx + 1] += lazy[idx];`
This is correct.

One detail: `1 << j` in Java is `int`.
If `j` is large, `1 << j` might overflow `int`.
But `n` is `int` in C++ (in `solve`, `n` is `int`).
Wait, in C++ `solve`, `n` is `ll` (long long).
In `precompute_min`, `n` is `sparsetable.size()`.
In `minquery`, `l` and `r` are `ll`.
In Java, `n` in `solve` is `int`.
Wait, in C++ `solve`: `ll n; cin >> n;`.
So `n` is `long long`.
In Java `solve`: `int n`.
This is a potential issue. `n` can be up to `10^9` or more?
If `n` is up to `10^9`, `int` is fine (up to `2*10^9`).
If `n` is larger, I should use `long` for `n` in `solve`.
But the C++ code uses `int` for `i` in loops.
`for(int i = 0; i < n; i++)`.
If `n` is `long long`, `i` must be `long long` to avoid overflow in `i++` or `i < n` if `n > INT_MAX`.
In the C++ code: `for(int i = 1;i <= n;i++)`.
If `n` is `long long`, `i` should be `long long`.
But the C++ code uses `int i`.
This implies `n` fits in `int`.
So `int n` in Java is fine.

Wait, the `power` function uses `ll` for `b`.
`power(2, n - 1)`.
If `n` is `int`, `n-1` is `int`.
In Java, `power(long a, long b)`.
So I should cast `n-1` to `long`.
`power(2, (long)n - 1)`.

Okay, I will make sure to cast `n` to `long` where necessary.

One more thing: `1 << j` in `precompute_min`.
`1 << j` is `int`.
If `n` is large, `1 << j` might overflow.
But `n` fits in `int` (since `i` is `int` in C++).
So `1 << j` is safe.

I will write the final code now.
</think>

<CODE>
import java.util.*;
import java.io.*;

public class c_1391 {

    static final long MOD = 1000000007L;

    // ====================  FUNCTIONS FOR INPUT AND OUTPUT OF VECTORS =======================================================

    static void input(ArrayList<Long> arr) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < arr.size(); i++) {
            arr.set(i, sc.nextLong());
        }
    }

    static void output(ArrayList<Long> arr) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.size(); i++) {
            sb.append(arr.get(i)).append(" ");
        }
        System.out.println(sb.toString().trim());
    }

    // ==============================  FOR MATHEMATICAL FUNCTIONS =============================================================

    static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static long power(long a, long b) {
        long res = 1;
        a %= MOD;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    static long multiply(long a, long b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    static long divide(long a, long b) {
        return multiply(a, power(b, MOD - 2));
    }

    // ============================ SEGMENT TREE FOR DEFAULT MINIMUM QUERY ==================================================

    static void manageLazy(long[] tree, long[] lazy, int idx) {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        long val = lazy[idx];
        
        tree[leftChild] += val;
        lazy[leftChild] += val;
        tree[rightChild] += val;
        lazy[rightChild] += val;
        
        lazy[idx] = 0;
    }

    static void build(long[] tree, long[] arr, int left, int right, int idx) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }

        int mid = (left + right) / 2;
        build(tree, arr, left, mid, 2 * idx + 1);
        build(tree, arr, mid + 1, right, 2 * idx + 2);

        tree[idx] = Math.min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    static void update(long[] tree, long[] lazy, int tl, int tr, int l, int r, int idx, long val) {
        if (l > r)
            return;

        if (l == tl && tr == r) {
            tree[idx] += val;
            lazy[idx] += val;
            return;
        }

        manageLazy(tree, lazy, idx);
        int mid = (tl + tr) / 2;

        update(tree, lazy, tl, mid, l, Math.min(r, mid), 2 * idx + 1, val);
        update(tree, lazy, mid + 1, tr, Math.max(l, mid + 1), r, 2 * idx + 2, val);

        tree[idx] = Math.min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    static long query(long[] tree, long[] lazy, int tl, int tr, int l, int r, int idx) {
        if (l > r)
            return 1000000000000000000L; // 1e18

        if (l <= tl && tr <= r)
            return tree[idx];

        manageLazy(tree, lazy, idx);
        int mid = (tl + tr) / 2;

        long a = query(tree, lazy, tl, mid, l, Math.min(r, mid), 2 * idx + 1);
        long b = query(tree, lazy, mid + 1, tr, Math.max(l, mid + 1), r, 2 * idx + 2);

        return Math.min(a, b);
    }

    // ==================================  SPARSE TABLE FOR DEFAULT MINIMUM QUERY ==================================================

    static void precompute_min(ArrayList<ArrayList<Long>> sparsetable, ArrayList<Long> a) {
        int n = a.size();
        int p = sparsetable.get(0).size();

        for (int i = 0; i < n; i++)  
            sparsetable.get(i).set(0, a.get(i));

        for (int j = 1; j < p; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                sparsetable.get(i).set(j, Math.min(sparsetable.get(i).get(j - 1), sparsetable.get(i + (1 << (j - 1))).get(j - 1)));
            }
        }
    }

    static long minquery(ArrayList<ArrayList<Long>> sparsetable, ArrayList<Long> log, int l, int r) {
        long range = r - l + 1;
        if (range == 0) return sparsetable.get(l).get(0);
        
        // Compute log2 of range
        int j = 0;
        while ((1L << (j + 1)) <= range) {
            j++;
        }
        
        return Math.min(sparsetable.get(l).get(j), sparsetable.get(r - (1 << j) + 1).get(j));
    }

    //=========================== FOR DISJOINT SET UNION ====================================================================

    static int findpar(int p, int[] parent) {
        if (parent[p] == p)
            return p;
        parent[p] = findpar(parent[p], parent);
        return parent[p];
    }

    static void merge(int a, int b, int[] parent, long[] size_) {
        a = findpar(a, parent);
        b = findpar(b, parent);
        
        if (a != b) {
            if (size_[a] < size_[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            size_[a] += size_[b];
        }
    }

    //   ====================================== FOR STORING AND COUNTING THE PRIMES USING SIEVE ============================

    static void sieve(ArrayList<Boolean> primes, ArrayList<Long> count) {
        for (int i = 2; i < primes.size(); i++) {
            if (primes.get(i)) {
                count.add(i);
                for (int j = i * i; j < primes.size(); j += i)
                    primes.set(j, false);
            }
        }
    }

    // =====================================================================================================================

    static void solve() {
        Scanner sc = new Scanner(System.in);
        
        // Read n. In C++, n is ll (long long).
        // In Java, we use long to match C++ type, but since loop uses int, 
        // we assume n fits in int range.
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            
            long ans = 1;
            for (int i = 1; i <= n; i++) {
                ans = (ans * i) % MOD;
            }
            
            long p = power(2, (long)n - 1);
            ans = ((ans - p) % MOD + MOD) % MOD;
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = 1;
        // In C++, t is read from cin.
        if (sc.hasNextInt()) {
            t = sc.nextInt();
        }

        while (t-- > 0) {
            solve();
        }
    }
}
</CODE>