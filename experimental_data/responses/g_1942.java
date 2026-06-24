Translate this C++ code to Java code. The main class name should be g_1942. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int r[4000010],w[4000010];

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline void add2(int &x,int y)
{
	x+=y;
	if(x<0) x+=MOD;
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline void init()
{
	for(int i=1;i<22;i++){
		int wn=my_pow(3,(MOD-1)/(1<<i)),now=1;
		for(int j=0;j<(1<<(i-1));j++){
			w[(1<<(i-1))+j]=now;
			now=1ll*now*wn%MOD;
		}
	}
}

inline void NTT(vector<int> &a)
{
	int n=a.size();
	int p=1,k=0;
	while(p<n) p*=2,k++;
	for(int i=1;i<n;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(k-1));
	for(int i=0;i<n;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(int i=1;i<=k;i++){
		for(int j=0;j<(1<<k);j+=(1<<i)){
			int off=(1<<(i-1));
			for(int l=j;l<j+off;l++){
				int x=a[l],y=1ll*a[l+off]*w[off+l-j]%MOD;
				a[l]=(x+y)>=MOD?(x+y-MOD):(x+y);
				a[l+off]=(x-y)<0?(x-y+MOD):(x-y);
			}
		}
	}
}

inline vector<int> convolution(vector<int> a,vector<int> b)
{
	int n=a.size(),m=b.size();
	int k=1;
	while(k<n+m) k*=2;
	a.resize(k);b.resize(k);
	NTT(a);NTT(b);
	for(int i=0;i<k;i++) a[i]=1ll*a[i]*b[i]%MOD;
	NTT(a);
	reverse(a.begin()+1,a.end());
	a.resize(n+m-1);
	int rev=my_pow(k,MOD-2);
	for(int i=0;i<n+m-1;i++) a[i]=1ll*a[i]*rev%MOD;
	return a;
}

int f[400010],g[400010],pw[400010],rev[400010];

inline int calc(int x,int y)
{
	if(x<y) return 0;
	return 1ll*pw[x]*rev[y]%MOD*rev[x-y]%MOD;
}

inline void solve(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	solve(l,mid);
	vector<int> v1,v2,v3;
	for(int i=l;i<=mid;i++) v1.push_back(f[i]);
	for(int i=1;i<=r-l;i++) v2.push_back(g[i]);
	v3=convolution(v1,v2);
	for(int i=mid+1;i<=r;i++){
		add2(f[i],-v3[i-l-1]);
	}
	solve(mid+1,r);
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	init();
	int t;cin>>t;
	while(t--){
		int a,b,c;cin>>a>>b>>c;
		int n=a+c+5;
		pw[0]=1;
		for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*i%MOD;
		rev[n]=my_pow(pw[n],MOD-2);
		for(int i=n-1;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
		int tot=1ll*calc(n,a+5)*calc(a+5,5)%MOD;
		int ans=tot,sum=c-a-5;
		for(int i=0;i<=a+c+5;i++){
			f[i]=0;
			int j=-5;
			if(i-j>=0&&(i-j)%2==0){
				int u=(i-j)/2;
				if(u>a+5) continue;
				if(u>i) continue;
				add2(f[i],-calc(i,u));
			}
		}
		for(int i=1;i<=a+c+5;i++){
			g[i]=0;
			if(i%2==0) g[i]=calc(i,i/2);
		}
		solve(0,a+c+5);
		for(int i=1;i<=a+c+5;i++){
			int j=sum+5;
			if(i-j>=0&&(i-j)%2==0){
				int u=(i-j)/2;
				if(u>a+5) continue;
				if(u>i) continue;
				for(int k=1;k<=5;k++){
					add1(ans,1ll*calc(i,u)*calc(u,k)%MOD*calc(a+5-u,5-k)%MOD*f[a+c+5-i]%MOD);
				}
			}
		}
		ans=1ll*ans*my_pow(tot,MOD-2)%MOD;
		cout<<ans<<'\n';
	}
	return 0;
}

<think>

</think>

### Translation Plan

**1. Headers and Namespaces:**
*   **`#include <bits/stdc++.h>`**: Replaced with specific standard library headers (`iostream`, `vector`, `algorithm`, `chrono`) to adhere to Java's modular package structure.
*   **`#include <ext/pb_ds/...>` & `using namespace __gnu_pbds;`**: The original code uses a custom hash struct intended for C++ `gp_hash_table`. In Java, the standard `HashMap` is generally sufficient and performs well enough for competitive programming unless a specific custom hash is strictly required to avoid collisions in a specific test case. Since the code defines a `custom_hash` struct but uses it implicitly via `__gnu_pbds` (which isn't directly used in the logic shown, only defined), I will remove the C++ PB_DS specific includes and rely on `java.util.*`. The `custom_hash` class itself is not used in the provided logic (the logic uses arrays and `vector`), so it can be safely omitted to keep the code clean.
*   **`using namespace std;`**: Replaced with explicit class prefixes (e.g., `System.out`, `Arrays`, `ArrayList`).

**2. Data Structures and Arrays:**
*   **Global Arrays (`r`, `w`, `f`, `g`, `pw`, `rev`)**: In C++, these are allocated on the global/static memory (zero-initialized). In Java, static arrays are also zero-initialized. I will convert them to `static int[]`.
    *   Sizes: `4000010` for `r` and `w`, `400010` for others.
*   **`struct custom_hash`**: As noted, this is unused in the logic. Removed.

**3. Inline Functions:**
*   C++ `inline` functions become `static` methods in Java classes.
*   **`add1` / `add2`**: Converted to `static void add1(int[] arr, int idx, int val)` and `add2` equivalents. Since Java arrays are objects, we pass the array index.
*   **`my_pow`**: Converted to `static long my_pow(long x, long y)`. Note: C++ `int` might overflow during `1ll*res*res`, so Java `long` is appropriate here.
*   **`init`**: Converted to `static void init()`.
*   **`NTT`**: Converted to `static void NTT(ArrayList<Integer> a)`.
    *   *Note*: Java `ArrayList` is dynamic. The C++ code resizes vectors. `ArrayList` handles this naturally.
    *   `swap` is replaced with a temporary variable swap.
*   **`convolution`**: Converted to `static ArrayList<Integer> convolution(ArrayList<Integer> a, ArrayList<Integer> b)`.
*   **`calc`**: Converted to `static long calc(int x, int y)`.
*   **`solve`**: Converted to `static void solve(int l, int r)`.
    *   *Note*: The C++ code uses `vector<int> v1, v2, v3`. In Java, we will use `ArrayList<Integer>`.

**4. `main` Function:**
*   Converted to `public static void main(String[] args)`.
*   **Input/Output**:
    *   `cin`/`cout` are replaced with `BufferedReader` and `PrintWriter` (or `System.out`) for performance, as competitive programming inputs can be large. `Scanner` is slow.
    *   `ios::sync_with_stdio(false); cin.tie(0);` is handled by the `BufferedReader`/`PrintWriter` setup.
*   **Logic Flow**: The logic inside the `while(t--)` loop remains the same, adapted for Java syntax (e.g., `a += b` vs `a = a + b`, `vector` vs `ArrayList`).

**5. Incremental Tasks Strategy:**
1.  **Setup**: Create class `g_1942`, add imports, define static arrays, and create the `main` method with `BufferedReader` setup.
2.  **Helper Functions**: Translate `my_pow`, `add1`, `add2`, and `init`.
3.  **NTT Logic**: Translate `NTT` and `convolution`. This is the most complex part due to dynamic resizing and index manipulation.
4.  **Solver Logic**: Translate `calc` and `solve`.
5.  **Main Loop**: Adapt the `main` function logic to use the translated helper methods and output results.
6.  **Refinement**: Ensure array bounds are respected (Java throws `ArrayIndexOutOfBoundsException` if out of bounds, whereas C++ might segfault silently or access garbage).

---

### Java Code

<CODE>
import java.io.*;
import java.util.*;

public class g_1942 {
    // Global arrays, initialized to 0 by default in Java static context
    // Size 4000010 for r and w (used up to index 4000009)
    static int[] r = new int[4000010];
    static int[] w = new int[4000010];
    
    // Size 400010 for f, g, pw, rev
    static int[] f = new int[400010];
    static int[] g = new int[400010];
    static long[] pw = new long[400010];
    static long[] rev = new long[400010];

    private static final int MOD = 998244353;

    public static void main(String[] args) throws IOException {
        // Fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer("");

        // Helper to read tokens
        // Since we need to read 't' first, then loop, we can just use a simple loop
        // However, to handle potential whitespace issues, a helper method is good.
        // But given the structure, we can just read line by line or token by token.
        
        // Read number of test cases
        String line;
        while ((line = br.readLine()) != null && line.trim().isEmpty()) {
            // Skip empty lines
        }
        if (line == null) return;
        
        st = new StringTokenizer(line);
        int t = Integer.parseInt(st.nextToken());

        // Initialize global arrays
        init();

        while (t-- > 0) {
            // Read a, b, c
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            if (!st.hasMoreTokens()) break;
            
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            int n = a + c + 5;
            
            // Precompute factorials pw[i]
            pw[0] = 1;
            for (int i = 1; i <= n; i++) {
                pw[i] = (pw[i - 1] * i) % MOD;
            }

            // Precompute inverse factorials rev[i]
            rev[n] = my_pow(pw[n], MOD - 2);
            for (int i = n - 1; i >= 0; i--) {
                rev[i] = (rev[i + 1] * (i + 1)) % MOD;
            }

            // Calculate total ways
            long tot = calc(n, a + 5);
            tot = (tot * calc(a + 5, 5)) % MOD;
            
            long ans = tot;
            int sum = c - a - 5;

            // Initialize f array
            for (int i = 0; i <= n; i++) {
                f[i] = 0;
                int j = -5;
                if (i - j >= 0 && (i - j) % 2 == 0) {
                    int u = (i - j) / 2;
                    if (u > a + 5) continue;
                    if (u > i) continue;
                    add2(f, i, -calc(i, u));
                }
            }

            // Initialize g array
            for (int i = 1; i <= n; i++) {
                g[i] = 0;
                if (i % 2 == 0) {
                    g[i] = calc(i, i / 2);
                }
            }

            // Solve using divide and conquer with NTT
            solve(0, n);

            // Calculate final answer
            for (int i = 1; i <= n; i++) {
                int j = sum + 5;
                if (i - j >= 0 && (i - j) % 2 == 0) {
                    int u = (i - j) / 2;
                    if (u > a + 5) continue;
                    if (u > i) continue;
                    
                    long term1 = calc(i, u);
                    long term2 = calc(u, 5);
                    long term3 = calc(a + 5 - u, 5 - 5); // 5-k, k goes 1..5, so 5-k goes 4..0. Wait, logic check below.
                    
                    // Original C++: calc(a+5-u, 5-k) where k is loop var 1..5
                    // In Java loop:
                    for (int k = 1; k <= 5; k++) {
                        long term3 = calc(a + 5 - u, 5 - k);
                        long term4 = f[n - i]; // f[a+c+5-i] -> f[n-i]
                        
                        long term = (term1 * term2) % MOD;
                        term = (term * term3) % MOD;
                        term = (term * term4) % MOD;
                        
                        add1(ans, term);
                    }
                }
            }

            // Multiply by modular inverse of tot
            ans = (ans * my_pow(tot, MOD - 2)) % MOD;
            
            out.println(ans);
        }

        out.flush();
    }

    static void init() {
        for (int i = 1; i < 22; i++) {
            // wn = 3^((MOD-1)/2^i)
            long wn = my_pow(3, (MOD - 1) / (1 << i));
            int now = 1;
            int limit = 1 << (i - 1);
            for (int j = 0; j < limit; j++) {
                w[limit + j] = now;
                now = (1L * now * wn) % MOD;
            }
        }
    }

    static void add1(int[] arr, int idx, int val) {
        arr[idx] += val;
        if (arr[idx] >= MOD) arr[idx] -= MOD;
    }

    static void add2(int[] arr, int idx, int val) {
        arr[idx] += val;
        if (arr[idx] < 0) arr[idx] += MOD;
    }

    static long my_pow(long x, long y) {
        if (y == 0) return 1;
        if (y == 1) return x % MOD;
        long res = my_pow(x, y / 2);
        if (y % 2 == 0) {
            return (res * res) % MOD;
        } else {
            return ((res * res) % MOD * (x % MOD)) % MOD;
        }
    }

    static void NTT(ArrayList<Integer> a) {
        int n = a.size();
        int p = 1;
        int k = 0;
        while (p < n) {
            p *= 2;
            k++;
        }
        
        // Reordering
        for (int i = 1; i < n; i++) {
            r[i] = (r[i >> 1] >> 1) | ((i & 1) << (k - 1));
        }
        
        // Swap
        for (int i = 0; i < n; i++) {
            if (i < r[i]) {
                int temp = a.get(i);
                a.set(i, a.get(r[i]));
                a.set(r[i], temp);
            }
        }
        
        // Butterfly operations
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < (1 << k); j += (1 << i)) {
                int off = 1 << (i - 1);
                for (int l = j; l < j + off; l++) {
                    // x = a[l], y = a[l+off] * w[...]
                    // Indices for w: off + l - j
                    // w array is int[], need to handle potential overflow if values were long, but here they are int
                    // However, product might exceed int range, so cast to long for calculation
                    int idxW = off + l - j;
                    long y = (1L * a.get(l + off) * w[idxW]) % MOD;
                    int x = a.get(l);
                    
                    int sum = x + (int)y;
                    if (sum >= MOD) sum -= MOD;
                    a.set(l, sum);
                    
                    int diff = x - (int)y;
                    if (diff < 0) diff += MOD;
                    a.set(l + off, diff);
                }
            }
        }
    }

    static ArrayList<Integer> convolution(ArrayList<Integer> a, ArrayList<Integer> b) {
        int n = a.size();
        int m = b.size();
        int k = 1;
        while (k < n + m) k *= 2;
        
        // Resize using ArrayList (implicitly adds 0s if capacity increased, but we need to ensure size is k)
        // In C++ resize adds default constructed elements (0 for int).
        // In Java, adding nulls or creating new ArrayList? 
        // The code assumes integer 0s for new elements.
        // We will create a new list or ensure size is k.
        // Since we modify in place, let's create new lists of size k filled with 0.
        ArrayList<Integer> A = new ArrayList<>(Collections.nCopies(k, 0));
        for(int i=0; i<n; i++) A.set(i, a.get(i));
        
        ArrayList<Integer> B = new ArrayList<>(Collections.nCopies(k, 0));
        for(int i=0; i<m; i++) B.set(i, b.get(i));
        
        NTT(A);
        NTT(B);
        
        for (int i = 0; i < k; i++) {
            long prod = (1L * A.get(i) * B.get(i)) % MOD;
            A.set(i, (int)prod);
        }
        
        // Inverse NTT
        // Note: The C++ code calls NTT(a) again.
        NTT(A);
        
        // Reverse
        // C++: reverse(a.begin()+1, a.end())
        // Java: subList(1, size) reversed
        ArrayList<Integer> res = new ArrayList<>();
        res.add(A.get(0));
        ArrayList<Integer> sub = new ArrayList<>(A.subList(1, A.size()));
        Collections.reverse(sub);
        res.addAll(sub);
        
        // Resize to n+m-1
        // C++: a.resize(n+m-1)
        // We take the first n+m-1 elements.
        int finalSize = n + m - 1;
        if (res.size() > finalSize) {
            res = new ArrayList<>(res.subList(0, finalSize));
        } else {
            // Pad with zeros if needed (unlikely given logic)
            while (res.size() < finalSize) res.add(0);
        }
        
        // Multiply by modular inverse of k
        long revK = my_pow(k, MOD - 2);
        for (int i = 0; i < res.size(); i++) {
            long val = (1L * res.get(i) * revK) % MOD;
            res.set(i, (int)val);
        }
        
        return res;
    }

    static long calc(int x, int y) {
        if (x < y) return 0;
        return (1L * pw[x] * rev[y]) % MOD;
    }

    static void solve(int l, int r) {
        if (l == r) return;
        int mid = (l + r) / 2;
        solve(l, mid);
        solve(mid + 1, r);
        
        ArrayList<Integer> v1 = new ArrayList<>();
        ArrayList<Integer> v2 = new ArrayList<>();
        
        for (int i = l; i <= mid; i++) v1.add(f[i]);
        for (int i = 1; i <= r - l; i++) v2.add(g[i]);
        
        ArrayList<Integer> v3 = convolution(v1, v2);
        
        // Update f array
        for (int i = mid + 1; i <= r; i++) {
            add2(f, i, -v3.get(i - l - 1));
        }
    }
}
</CODE>