Translate this C++ code to Java code. The main class name should be b_663. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int mod=1000000000+7;

int addm(int& a,int b) {return (a+=b)<mod?a:a-=mod;}

template<class T,class U> bool smin(T& a,U b) {return a>b?(a=b,1):0;}
template<class T,class U> bool smax(T& a,U b) {return a<b?(a=b,1):0;}

ll query(string name) {
	string y=name.substr(4);
	ll fy=1989;
	int len=1;
	ll p10=10;
	while (len<y.size()) {
		len++;
		fy+=p10;
		p10*=10;
	}

	ll toadd=(stoi(y)-fy)%p10;
	if (toadd<0) toadd+=p10;
	return fy+toadd;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string abb;
		cin >> abb;
		cout << query(abb) << '\n';
	}
	
}

Here is the translation plan:

1.  **Includes**: The C++ header `<bits/stdc++.h>` is a catch-all for standard library headers. In Java, we must explicitly include the necessary classes: `java.util.Scanner` (or `BufferedReader` for better performance, but `Scanner` is closer to `cin`), `java.io.PrintWriter` (for `cout`), `java.lang.String`, `java.lang.Integer`, and `java.lang.Long`.
2.  **Macros and typedefs**:
    *   `#define` macros are not supported in Java. The usage of `x` and `y` for `first` and `second` in pairs is specific to C++'s `pair` type. Since the provided code does not actually use `ii` or `pll` types or the `x`, `y` macros, this part of the code can be safely ignored.
    *   `typedef` for `long long` (`ll`) becomes `long` in Java (since `long` is 64-bit, matching `long long` in C++).
    *   `typedef` for `long double` (`ld`) becomes `double` in Java.
    *   `typedef` for vectors (`vi`, `vvi`) are not used in the provided snippet, so they are ignored.
3.  **Constants**: The constant `mod` (1000000007) remains the same.
4.  **Helper Function `addm`**:
    *   C++: `int addm(int& a, int b)` returns the result of addition modulo `mod`.
    *   Java: `int addm(int a, int b)` (no reference parameter needed). It returns `(a + b) % mod`. Note that Java's `%` operator works on integers directly, unlike C++ where manual modulo adjustment is sometimes needed for negative results if not careful, but here inputs are positive.
5.  **Helper Function `query`**:
    *   C++: `ll query(string name)` takes a string and returns a `long long`.
    *   Java: `long query(String name)` takes a `String` and returns a `long`.
    *   Logic:
        *   `name.substr(4)` -> `name.substring(4)`.
        *   `stoi(y)` -> `Integer.parseInt(y)`.
        *   `len` calculation loop -> Java `for` or `while` loop.
        *   `p10` calculation -> Java `long`.
        *   `toadd` calculation -> `(Integer.parseInt(y) - fy) % p10`. In Java, if the result is negative, `%` returns a negative number. We must add `p10` if the result is negative to match C++ behavior.
        *   Return `fy + toadd`.
6.  **Main Function**:
    *   C++: `main` reads `n`, loops `n` times, reads `abb`, calls `query`, prints result.
    *   Java: `public static void main(String[] args)`.
    *   Input: Use `Scanner` to read `n` and `abb`.
    *   Output: Use `System.out.println` or `PrintWriter`.
    *   `ios::sync_with_stdio(0); cin.tie(0);`: This optimization is not strictly necessary for Java's `Scanner` in most competitive programming contexts unless time limits are extremely tight, but for correctness and standard practice, we will implement the logic. `Scanner` is easier to read and sufficient for this specific problem logic.

7.  **Structure**: The code will be a single class `b_663` containing the `main` method and the `query` method.

Here is the resulting code:

<CODE>
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;
import java.io.OutputStream;

public class b_663 {

    private static final int mod = 1000000007;

    private static int addm(int a, int b) {
        return (a + b) % mod;
    }

    private static long query(String name) {
        String y = name.substring(4);
        long fy = 1989;
        long p10 = 10;
        int len = 1;
        while (len < y.length()) {
            len++;
            fy += p10;
            p10 *= 10;
        }

        long toadd = (Integer.parseInt(y) - (int) fy) % p10;
        if (toadd < 0) {
            toadd += p10;
        }
        return fy + toadd;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            while (n-- > 0) {
                String abb = scanner.next();
                out.println(query(abb));
            }
        }
        
        out.flush();
    }
}
</CODE>