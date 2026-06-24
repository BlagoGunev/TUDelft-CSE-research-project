Translate this C++ code to Java code. The main class name should be c_1527. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll rd(){
	ll x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	return x*f;
}
const int maxn=1e5+5;
const ll mod=998244353;
ll _,n,a[maxn],b[maxn];
ll tmp[maxn];
int main() {
    for(_=rd();_;_--){
        n=rd();
        for (int i=1;i<=n;i++)a[i]=rd(),b[i]=a[i],tmp[i]=0;
        sort(b+1,b+n+1);
    	int tot=unique(b+1,b+n+1)-b-1;
    	for (int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    	ll ans=0;
    	for (int i=1;i<=n;i++){
    		ans+=tmp[a[i]]*(n-i+1);
    		tmp[a[i]]+=i;
    	}
    	printf("%lld\n",ans);
    }
    return 0;
}

<think>

</think>

### Translation Plan

1.  **Headers and Namespaces**:
    *   Replace `#include <bits/stdc++.h>` with specific headers: `<iostream>`, `<vector>`, `<algorithm>`, `<cstdio>`.
    *   Remove `using namespace std;` and use explicit `std::` prefixes where appropriate, or include `using namespace std;` for brevity (common in competitive programming).
    *   Replace C++ `typedef long long ll` with `using ll = long long;`.

2.  **Input Function (`rd`)**:
    *   The C++ function uses `getchar()` and manual parsing to read integers. In Java, we will use `BufferedReader` and `StringTokenizer` for efficient I/O, which is the standard approach for competitive programming.
    *   The logic inside `rd` (handling negative signs and digit accumulation) will be replicated in a Java method `readLong()`.

3.  **Data Structures**:
    *   C++ arrays `a[maxn]`, `b[maxn]`, `tmp[maxn]` will be translated to Java arrays or `long[]`. Since the size is fixed (`100005`), static arrays are efficient and easy to translate.
    *   `maxn` becomes a `static final int`.
    *   `mod` remains a `long`.

4.  **Logic Translation**:
    *   **Looping**: C++ `for(_=rd();_;_--)` translates to a `while(true)` loop checking a counter variable initialized to the read value.
    *   **Sorting**: `std::sort(b+1, b+n+1)` translates to `Arrays.sort(b, 1, n + 1)`.
    *   **Unique**: C++ `std::unique` removes consecutive duplicates and returns an iterator. In Java, we can simulate this by iterating through the sorted array and counting unique elements, or creating a new array. To keep the logic identical to the C++ code (which modifies the array in-place conceptually), we will create a new array `distinctB` containing unique elements of `b`. The variable `tot` will represent the count of unique elements.
    *   **Lower Bound**: C++ `std::lower_bound` finds the first element not less than the value. In Java, we implement a binary search manually (`lowerBound`) to find the index of the first element $\ge$ `a[i]` within the unique elements of `b`.
    *   **Output**: Replace `printf("%lld\n", ans)` with `System.out.println(ans)`.

5.  **Incremental Tasks**:
    *   Step 1: Setup class structure, imports, and constants.
    *   Step 2: Implement the fast I/O (`readLong`).
    *   Step 3: Implement the `main` logic, translating the loop, array population, sorting, and unique logic.
    *   Step 4: Implement the `lowerBound` helper and the final calculation loop.
    *   Step 5: Refine and test the structure.

### Java Code

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class c_1527 {
    // Using long long equivalent
    using ll = long; // Note: Java doesn't support typedef like C++, using 'long' directly for 64-bit integers
    
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
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        long nextLong() {
            String s = next();
            long x = 0;
            boolean f = 1;
            int o;
            // Manual parsing similar to C++ rd() to handle potential negative signs and whitespace
            // Note: StringTokenizer usually handles whitespace, but here we mimic the char-by-char logic for robustness
            // However, since we use StringTokenizer for simplicity in Java, we can just parse the token.
            // If strict char-by-char is needed (e.g., handling specific whitespace issues):
            /*
            try {
                // Reset reader if needed, but next() already consumed tokens.
                // For this specific problem, standard token parsing is sufficient.
                // Let's implement a custom parseLong to strictly match C++ rd behavior if necessary,
                // but StringTokenizer is generally safer and faster for Java.
                // We will assume standard whitespace separation as per typical CP inputs.
                return Long.parseLong(s);
            } catch (NumberFormatException e) {
                e.printStackTrace();
            }
            */
            // To strictly match the C++ logic provided (which reads char by char):
            // We'll implement a custom long reader that mimics the C++ rd function exactly.
            return parseLong(s);
        }

        private long parseLong(String s) {
            long x = 0;
            boolean f = 1;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '-') {
                    f = -1;
                    continue;
                }
                x = (x << 3) + (x << 1) + (c - '0');
            }
            return x * f;
        }
    }

    static final int maxn = 100005;
    static final long mod = 998244353L;
    
    static long[] a = new long[maxn];
    static long[] b = new long[maxn];
    static long[] tmp = new long[maxn];

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        // Read number of test cases
        // The C++ code reads '_' first. We need to handle EOF gracefully if the input format varies,
        // but typically CP problems give T at the start.
        // However, the C++ code uses rd() which might return garbage if EOF is hit unexpectedly.
        // We will assume the input starts with a valid integer T.
        
        try {
            String tStr = sc.next();
            if (tStr == null) return;
            int t = Integer.parseInt(tStr);
            
            while (t-- > 0) {
                long nVal = sc.nextLong();
                int n = (int)nVal;
                
                for (int i = 1; i <= n; i++) {
                    a[i] = sc.nextLong();
                    b[i] = a[i];
                    tmp[i] = 0;
                }
                
                // Sort b array from index 1 to n
                Arrays.sort(b, 1, n + 1);
                
                // Unique logic: Count unique elements
                int tot = 0;
                if (n > 0) {
                    tot = 1;
                    for (int i = 2; i <= n; i++) {
                        if (b[i] != b[i - 1]) {
                            tot++;
                        }
                    }
                }
                
                // Replace a[i] with its rank (index in unique sorted b)
                // C++: lower_bound returns iterator, subtract b to get index.
                // Java: Binary search to find insertion point.
                for (int i = 1; i <= n; i++) {
                    int idx = lowerBound(b, 1, tot + 1, a[i]);
                    a[i] = idx;
                }
                
                long ans = 0;
                for (int i = 1; i <= n; i++) {
                    ans += tmp[a[i]] * (long)(n - i + 1);
                    tmp[a[i]] += i;
                }
                
                System.out.println(ans);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Manual binary search to find the first element >= value
    // range is [fromIndex, toIndex)
    private static int lowerBound(long[] arr, int fromIndex, int toIndex, long value) {
        int low = fromIndex;
        int high = toIndex;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= value) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
</CODE>