Translate this C++ code to Java code. The main class name should be e_175. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define iss istringstream
#define sst stringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sh(i) (1LL<<i)
#define sz size()
#define vi vector<int>
#define vc vector
#define vl vector<ll>
#define vs vector<string>

int n,nf,ne,ns,fr[20];
double rf,re,rs,df,de,ans;

double insec(double a,double b,double c,double d){
	return max( 0., min(b,d)-max(a,c) );
}

double f(){
	double res=0;
	vector<double> v;
	rep(i,n)if(!fr[i]){
		double X=i/2, F=2*rf*df, E=2*re*de;
		rep(j,n)if(fr[j]){
			double x=j/2;
			F+=insec(X-rf, X+rf, x-rs, x+rs) *df;
			E+=insec(X-re, X+re, x-rs, x+rs) *de;
		}
		res+=F;
		v.pb(E-F);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	rep(i,ne)res+=v[i];
	return res;
}

int main(){
	cin>>nf>>ne>>ns>>rf>>re>>rs>>df>>de;
	rf=sqrt(rf*rf-1);
	re=sqrt(re*re-1);
	rs=sqrt(rs*rs-1);
	n=nf+ne+ns;
	int temp=n-1;
	rep(i,ns)fr[temp--]=1;
	do{
		int ok=1;
		rep(i,n/2){
			if(fr[i*2]==0 && fr[i*2+1]==1){ok=0;break;}
		}
		if(ok)ans=max(ans,f());
	}while(next_permutation(fr,fr+n));
	cout<<setprecision(9)<<ans;
}

Here is the plan for translating the C++ code to Java:

1.  **Header and Imports**: Replace C++ standard library includes (`<iostream>`, `<algorithm>`, etc.) with equivalent Java classes (`java.util.*`, `java.io.*`, `java.math.*`).
2.  **Class Structure**: Create a public class named `e_175` with a `main` method.
3.  **Macros and Constants**:
    *   Define `EPS`, `INF`, `MOD`, `n`, `nf`, `ne`, `ns`, `fr`, `rf`, `re`, `rs`, `df`, `de`, `ans` as static final or instance variables.
    *   C++ macros like `rep`, `rep2`, `pi`, `pb`, `sz`, `vi`, `vc`, `vl`, `vs`, `sh`, `mp`, `fir`, `sec`, `sst`, `iss`, `ll` need to be converted to Java loops, methods, or data structures (e.g., `ArrayList`, `Collections`).
4.  **Data Structures**:
    *   C++ `vector<double>` becomes `ArrayList<Double>`.
    *   C++ `pair` is not strictly used here, but `pi` is defined. We don't need it for the logic, but we might need it if logic changes.
    *   C++ `long long` becomes `long`.
5.  **Logic Translation**:
    *   `cin`/`cout` becomes `Scanner`/`System.out`.
    *   `sqrt` remains `Math.sqrt`.
    *   `max`/`min` become `Math.max`/`Math.min`.
    *   `sort` becomes `Collections.sort`.
    *   `reverse` becomes `Collections.reverse`.
    *   `next_permutation` requires a custom implementation in Java since there is no standard library equivalent.
6.  **Specific Logic**:
    *   The `insec` function calculates intersection length of intervals $[a, b]$ and $[c, d]$.
    *   The `f` function iterates through unselected indices, calculates a score based on intersections, sorts the scores, and sums the top ones.
    *   The `main` function reads input, calculates initial `rf`, `re`, `rs`, iterates through permutations of `fr` (boolean array), checks a condition, and updates the answer.

The code is split into logical parts: Helper functions (`insec`, `f`), the `main` method, and the `next_permutation` helper.

```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class e_175 {
    // Constants and global variables
    // Using static final for constants like MOD and EPS
    // Using instance variables for mutable state like n, fr, ans
    static final double EPS = 1e-9;
    static final long MOD = 1000000007L;
    
    // Variables
    int n, nf, ne, ns;
    int[] fr;
    double rf, re, rs, df, de, ans;

    // Helper method to calculate intersection length of intervals [a, b] and [c, d]
    // Equivalent to C++ insec
    private double insec(double a, double b, double c, double d) {
        double maxLeft = Math.max(a, c);
        double minRight = Math.min(b, d);
        return Math.max(0.0, minRight - maxLeft);
    }

    // Helper method to calculate the score based on current permutation
    // Equivalent to C++ f
    private double f() {
        double res = 0.0;
        List<Double> v = new ArrayList<>();
        
        // Equivalent to C++ rep(i, n)if(!fr[i])
        for (int i = 0; i < n; i++) {
            if (fr[i] == 0) {
                double X = i / 2.0;
                double F = 2.0 * rf * df;
                double E = 2.0 * re * de;
                
                // Equivalent to C++ rep(j, n)if(fr[j])
                for (int j = 0; j < n; j++) {
                    if (fr[j] == 1) {
                        double x = j / 2.0;
                        // insec call
                        double overlap = insec(X - rf, X + rf, x - rs, x + rs);
                        F += overlap * df;
                        E += overlap * de;
                    }
                }
                res += F;
                v.add(E - F);
            }
        }
        
        // Equivalent to C++ sort(v.begin(),v.end());
        // Equivalent to C++ reverse(v.begin(),v.end());
        Collections.sort(v);
        Collections.reverse(v);
        
        // Equivalent to C++ rep(i, ne)res+=v[i];
        // Note: C++ rep2(i, 0, ne) loops i from 0 to ne-1
        for (int i = 0; i < ne; i++) {
            res += v.get(i);
        }
        return res;
    }

    // Custom implementation of next_permutation
    // Since Java does not have a standard library equivalent
    private boolean nextPermutation(int[] arr) {
        // Find the largest index k such that arr[k] < arr[k + 1]
        int k = -1;
        for (int i = arr.length - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                k = i;
            }
        }
        
        if (k == -1) return false; // Last permutation reached
        
        // Find the largest index l greater than k such that arr[k] < arr[l]
        int l = -1;
        for (int i = arr.length - 1; i > k; i--) {
            if (arr[i] > arr[k]) {
                l = i;
            }
        }
        
        // Swap arr[k] and arr[l]
        int temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;
        
        // Reverse the sequence from arr[k + 1] to arr[n]
        int start = k + 1;
        int end = arr.length - 1;
        while (start < end) {
            int t = arr[start];
            arr[start] = arr[end];
            arr[end] = t;
            start++;
            end--;
        }
        
        return true;
    }

    public static void main(String[] args) {
        e_175 solver = new e_175();
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNext()) {
            solver.nf = sc.nextInt();
            solver.ne = sc.nextInt();
            solver.ns = sc.nextInt();
            double rfIn = sc.nextDouble();
            double reIn = sc.nextDouble();
            double rsIn = sc.nextDouble();
            double dfIn = sc.nextDouble();
            double deIn = sc.nextDouble();
            
            solver.n = solver.nf + solver.ne + solver.ns;
            solver.fr = new int[solver.n];
            
            // Fill fr array with 1s for the first ns elements
            // C++: rep(i, ns)fr[temp--]=1;
            // Logic: fill fr[0] to fr[ns-1] with 1, rest 0
            for (int i = 0; i < solver.ns; i++) {
                solver.fr[i] = 1;
            }
            // The rest are implicitly 0 (default int value)
            
            // Initial setup of rf, re, rs
            solver.rf = Math.sqrt(rfIn * rfIn - 1);
            solver.re = Math.sqrt(reIn * reIn - 1);
            solver.rs = Math.sqrt(rsIn * rsIn - 1);
            
            solver.ans = 0.0;
            
            // Iterate through permutations
            do {
                // Check condition
                // C++: rep(i, n/2){ if(fr[i*2]==0 && fr[i*2+1]==1){ok=0;break;} }
                boolean ok = true;
                for (int i = 0; i < solver.n / 2; i++) {
                    if (solver.fr[i * 2] == 0 && solver.fr[i * 2 + 1] == 1) {
                        ok = false;
                        break;
                    }
                }
                
                if (ok) {
                    solver.ans = Math.max(solver.ans, solver.f());
                }
                
            } while (solver.nextPermutation(solver.fr));
            
            // Output result with setprecision(9)
            System.out.println(String.format("%.9f", solver.ans));
        }
        sc.close();
    }
}
```

<CODE>
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class e_175 {
    // Constants and global variables
    // Using static final for constants like MOD and EPS
    // Using instance variables for mutable state like n, fr, ans
    static final double EPS = 1e-9;
    static final long MOD = 1000000007L;
    
    // Variables
    int n, nf, ne, ns;
    int[] fr;
    double rf, re, rs, df, de, ans;

    // Helper method to calculate intersection length of intervals [a, b] and [c, d]
    // Equivalent to C++ insec
    private double insec(double a, double b, double c, double d) {
        double maxLeft = Math.max(a, c);
        double minRight = Math.min(b, d);
        return Math.max(0.0, minRight - maxLeft);
    }

    // Helper method to calculate the score based on current permutation
    // Equivalent to C++ f
    private double f() {
        double res = 0.0;
        List<Double> v = new ArrayList<>();
        
        // Equivalent to C++ rep(i, n)if(!fr[i])
        for (int i = 0; i < n; i++) {
            if (fr[i] == 0) {
                double X = i / 2.0;
                double F = 2.0 * rf * df;
                double E = 2.0 * re * de;
                
                // Equivalent to C++ rep(j, n)if(fr[j])
                for (int j = 0; j < n; j++) {
                    if (fr[j] == 1) {
                        double x = j / 2.0;
                        // insec call
                        double overlap = insec(X - rf, X + rf, x - rs, x + rs);
                        F += overlap * df;
                        E += overlap * de;
                    }
                }
                res += F;
                v.add(E - F);
            }
        }
        
        // Equivalent to C++ sort(v.begin(),v.end());
        // Equivalent to C++ reverse(v.begin(),v.end());
        Collections.sort(v);
        Collections.reverse(v);
        
        // Equivalent to C++ rep(i, ne)res+=v[i];
        // Note: C++ rep2(i, 0, ne) loops i from 0 to ne-1
        for (int i = 0; i < ne; i++) {
            res += v.get(i);
        }
        return res;
    }

    // Custom implementation of next_permutation
    // Since Java does not have a standard library equivalent
    private boolean nextPermutation(int[] arr) {
        // Find the largest index k such that arr[k] < arr[k + 1]
        int k = -1;
        for (int i = arr.length - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                k = i;
            }
        }
        
        if (k == -1) return false; // Last permutation reached
        
        // Find the largest index l greater than k such that arr[k] < arr[l]
        int l = -1;
        for (int i = arr.length - 1; i > k; i--) {
            if (arr[i] > arr[k]) {
                l = i;
            }
        }
        
        // Swap arr[k] and arr[l]
        int temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;
        
        // Reverse the sequence from arr[k + 1] to arr[n]
        int start = k + 1;
        int end = arr.length - 1;
        while (start < end) {
            int t = arr[start];
            arr[start] = arr[end];
            arr[end] = t;
            start++;
            end--;
        }
        
        return true;
    }

    public static void main(String[] args) {
        e_175 solver = new e_175();
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNext()) {
            solver.nf = sc.nextInt();
            solver.ne = sc.nextInt();
            solver.ns = sc.nextInt();
            double rfIn = sc.nextDouble();
            double reIn = sc.nextDouble();
            double rsIn = sc.nextDouble();
            double dfIn = sc.nextDouble();
            double deIn = sc.nextDouble();
            
            solver.n = solver.nf + solver.ne + solver.ns;
            solver.fr = new int[solver.n];
            
            // Fill fr array with 1s for the first ns elements
            // C++: rep(i, ns)fr[temp--]=1;
            // Logic: fill fr[0] to fr[ns-1] with 1, rest 0
            for (int i = 0; i < solver.ns; i++) {
                solver.fr[i] = 1;
            }
            // The rest are implicitly 0 (default int value)
            
            // Initial setup of rf, re, rs
            solver.rf = Math.sqrt(rfIn * rfIn - 1);
            solver.re = Math.sqrt(reIn * reIn - 1);
            solver.rs = Math.sqrt(rsIn * rsIn - 1);
            
            solver.ans = 0.0;
            
            // Iterate through permutations
            do {
                // Check condition
                // C++: rep(i, n/2){ if(fr[i*2]==0 && fr[i*2+1]==1){ok=0;break;} }
                boolean ok = true;
                for (int i = 0; i < solver.n / 2; i++) {
                    if (solver.fr[i * 2] == 0 && solver.fr[i * 2 + 1] == 1) {
                        ok = false;
                        break;
                    }
                }
                
                if (ok) {
                    solver.ans = Math.max(solver.ans, solver.f());
                }
                
            } while (solver.nextPermutation(solver.fr));
            
            // Output result with setprecision(9)
            System.out.println(String.format("%.9f", solver.ans));
        }
        sc.close();
    }
}
</CODE>