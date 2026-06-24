Translate this C++ code to Java code. The main class name should be d_379. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

using namespace std;

#define pf pop_front

#define pb push_back

#define FOR(i,begin,end) for (LL i=begin;i<=end;i++)

#define rep(i,t) for (LL i=0;i<t;i++)

#define pii pair<LL,LL>

#define X first

#define Y second

typedef long long LL;

typedef unsigned long long int ulli;

const LL maxN=5e1+7,N=5e1+7,inf=1e9+7,MOD=1e9+7,Mod=1e9+6;

LL k,x,n,m,e[maxN],s[maxN],dp[maxN][6],cnt,ln,lm,cs[maxN],ce[maxN],help,pos,len;

string str;

char ss,se,es,ee;

void print(char a,char b,LL x,LL y)

{

	LL count=0;

	if(x==1)

		cout<<a<<"\n";

	else

	{

		if(a=='A')

		{

			if(y)

				cout<<"AC",count=2;

			else

				cout<<a,count=1;

			FOR(i,1,y-1)

				cout<<"AC",count+=2;

			FOR(i,count+1,x-1)

				cout<<"B";

			cout<<b<<"\n";

		}

		else

		{

			if(b=='C')

			{

				str.clear();

				if(y)

					str+="CA",count=2;

				else

					str+="C",count=1;

				FOR(i,1,y-1)

					str+="CA",count+=2;

				FOR(i,count+1,x-1)

					str+="B";

				str+=a;

				reverse(str.begin(),str.end());

				cout<<str<<"\n";

			}

			else

			{

				cout<<a;

				count=1;

				FOR(i,1,y)

					count+=2,cout<<"AC";

				FOR(i,count+1,x-1)

					cout<<"B";

				cout<<b<<"\n";

			}

		}

	}

}

int main()

{

	cin>>k>>x>>n>>m;

	if(!x)

	{

		FOR(i,1,n)

			cout<<"B";

		cout<<"\n";

		FOR(i,1,m)

			cout<<"B";

		return cout<<"\n",0;

	}

	e[1]=s[1]=1;

	s[2]=e[2]=2;

	cs[1]=1;

	ce[2]=1;

	FOR(i,2,k)

		e[i]=2;

	FOR(i,3,k)

	{

		FOR(j,1,4)

			dp[i][j]=dp[i-1][j]+dp[i-2][j];

		cs[i]=cs[i-1]+cs[i-2];

		ce[i]=ce[i-1]+ce[i-2];

		s[i]=(i%2)?s[1]:s[2];

		if(e[i-2]==1)

		{

			if(s[i-1]==1)

				dp[i][1]++;

			else

				dp[i][2]++;

		}

		else

		{

			if(s[i-1]==1)

				dp[i][3]++;

			else

				dp[i][4]++;

		}

	}

	rep(i,3)

	{

		rep(j,3)

		{

			rep(l,3)

			{

				rep(t,3)

				{

					ss=se=es=ee='A';ss+=i;se+=j;es+=l;ee+=t;ln=n-2;lm=m-2;

					if(n==1)

						ss=se;

					if(m==1)

						es=ee;

					cnt=0;

					if(se=='A' && es=='C')

						cnt+=dp[k][2];//1 2

					if(se=='A' && ss=='C')

						cnt+=dp[k][1];//1 1

					if(ee=='A' && ss=='C')

						cnt+=dp[k][3];//2 1

					if(ee=='A' && es=='C')

						cnt+=dp[k][4];//2 2

					if(se=='C' || ss=='A')

						ln++;

					if(es=='A' || ee=='C')

						lm++;

					if(n==2 && ss=='A' && se=='C')

						cnt+=cs[k];

					if(m==2 && es=='A' && ee=='C')

						cnt+=ce[k];

					ln/=2;

					lm/=2;

					rep(xx,ln+1)

					{

						help=(xx*cs[k])+cnt;

						if(x>=help)

						{

							if(!((x-help)%ce[k]) || x==help)

							{

								pos=(x-help)/ce[k];

								if(pos<=lm)

								{

									print(ss,se,n,xx);

									print(es,ee,m,pos);

									return cout<<"\n",0;

								}

							}

						}

					}

				}

			}

		}

	}

	return cout<<"Happy new year!\n",0;

}

<think>

</think>

### Translation Plan

1.  **Header and Namespaces**:
    *   Replace `#include <bits/stdc++.h>` with specific includes: `<iostream>`, `<vector>`, `<string>`, `<algorithm>`.
    *   Replace `using namespace std;` with explicit namespace usage where appropriate or keep it for brevity (standard in competitive programming style Java).

2.  **Macros and Constants**:
    *   **Macros**: C++ macros like `#define pf`, `#define pb`, `#define FOR`, `#define rep`, `#define pii`, `#define X`, `#define Y` are removed.
        *   `FOR` and `rep` loops are replaced by standard `for` loops.
        *   `pf` and `pb` were empty definitions in the original code, so they are ignored.
    *   **Types**: `typedef long long LL;` becomes `long` (since Java's `long` is 64-bit, equivalent to C++ `long long` for this context) or `long`. Given the constraints ($5 \times 10^1$), `long` is sufficient.
    *   **Constants**: `maxN`, `N`, `inf`, `MOD`, `Mod` become `static final long` constants in the class.

3.  **Variables**:
    *   Global variables in C++ become class-level fields in Java.
    *   Arrays `e`, `s`, `dp`, `cs`, `ce` become `long[]` arrays.
    *   String `str` becomes `String str`.
    *   Char variables `ss`, `se`, `es`, `ee` become `char` fields.
    *   Integer/Long variables `k`, `x`, `n`, `m`, `cnt`, `ln`, `lm`, `pos`, `len` become fields.

4.  **Logic Translation**:
    *   **`print` function**: Converted to a `private void print(char a, char b, long n, long m)` method.
        *   C++ `cout` becomes `System.out.print` or `System.out.println`.
        *   `reverse` logic is implemented manually using `StringBuilder` or `StringBuffer`.
        *   C++ string concatenation (`+=`) is replaced with `StringBuilder` for efficiency.
    *   **`main` function**: Converted to `public static void main(String[] args)`.
        *   Input reading (`cin >>`) is replaced by `Scanner` or `BufferedReader`. Given the complexity and potential I/O volume, `Scanner` is used for simplicity, but `BufferedReader` is preferred for performance in competitive programming. I will use `Scanner` for readability unless the logic implies heavy I/O, but here the logic is $O(K^4)$ which is small, so `Scanner` is fine.
        *   Conditional logic (`if`, `else`) remains the same.
        *   Array indexing remains 1-based as per the original code logic (though Java arrays are 0-based, the logic explicitly uses indices 1 to `k`).
        *   The nested loops (`rep`/`FOR`) are rewritten as standard Java `for` loops.

5.  **Specific Syntax Adjustments**:
    *   `LL` type is replaced with `long`.
    *   `cout << ... << "\n"` becomes `System.out.println(...)`.
    *   `return cout << "\n", 0;` becomes `System.out.println(); return 0;`.
    *   `cin >>` becomes `sc.nextLong()`.

6.  **Incremental Tasks**:
    *   Step 1: Define class structure and constants.
    *   Step 2: Implement `print` method logic (handling the string generation and reversal).
    *   Step 3: Implement `main` method input reading and initial array setup.
    *   Step 4: Implement the DP calculation loop.
    *   Step 5: Implement the nested search loop and conditional printing.
    *   Step 6: Handle the final fallback output.

### Java Code

<CODE>
import java.util.Scanner;
import java.util.StringTokenizer;

public class d_379 {

    static final long MAXN = 50007;
    static final long INF = 1000000007L;
    static final long MOD = 1000000007L;
    static final long Mod = 1000000006L;

    static long k, x, n, m;
    static long[] e = new long[(int)MAXN];
    static long[] s = new long[(int)MAXN];
    static long[][] dp = new long[(int)MAXN][6];
    static long cnt;
    static long ln;
    static long lm;
    static long[] cs = new long[(int)MAXN];
    static long[] ce = new long[(int)MAXN];
    static long[] help = new long[(int)MAXN];
    static long pos;
    static String str;

    static char ss, se, es, ee;

    public static void print(char a, char b, long nVal, long mVal) {
        long count = 0;
        if (nVal == 1) {
            System.out.println(a);
        } else {
            if (a == 'A') {
                if (mVal > 0) {
                    System.out.print("AC");
                    count = 2;
                } else {
                    System.out.print(a);
                    count = 1;
                }
                for (long i = 1; i < mVal; i++) {
                    System.out.print("AC");
                    count += 2;
                }
                for (long i = count + 1; i < nVal; i++) {
                    System.out.print("B");
                }
                System.out.println(b);
            } else {
                if (b == 'C') {
                    str = "";
                    if (mVal > 0) {
                        str += "CA";
                        count = 2;
                    } else {
                        str += "C";
                        count = 1;
                    }
                    for (long i = 1; i < mVal; i++) {
                        str += "CA";
                        count += 2;
                    }
                    for (long i = count + 1; i < nVal; i++) {
                        str += "B";
                    }
                    str += a;
                    str = new StringBuilder(str).reverse().toString();
                    System.out.println(str);
                } else {
                    System.out.print(a);
                    count = 1;
                    for (long i = 1; i <= mVal; i++) {
                        count += 2;
                        System.out.print("AC");
                    }
                    for (long i = count + 1; i < nVal; i++) {
                        System.out.print("B");
                    }
                    System.out.println(b);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextLong()) return;
        k = sc.nextLong();
        x = sc.nextLong();
        n = sc.nextLong();
        m = sc.nextLong();

        if (x == 0) {
            for (long i = 1; i <= n; i++) {
                System.out.print("B");
            }
            System.out.println();
            for (long i = 1; i <= m; i++) {
                System.out.print("B");
            }
            System.out.println();
            return;
        }

        e[1] = 1;
        s[1] = 1;
        e[2] = 2;
        s[2] = 2;
        cs[1] = 1;
        ce[2] = 1;

        for (long i = 2; i <= k; i++) {
            e[i] = 2;
        }

        for (long i = 3; i <= k; i++) {
            for (int j = 1; j <= 4; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 2][j];
            }
            cs[i] = cs[i - 1] + cs[i - 2];
            ce[i] = ce[i - 1] + ce[i - 2];
            s[i] = ((i % 2) != 0) ? s[1] : s[2];

            if (e[i - 2] == 1) {
                if (s[i - 1] == 1) {
                    dp[i][1]++;
                } else {
                    dp[i][2]++;
                }
            } else {
                if (s[i - 1] == 1) {
                    dp[i][3]++;
                } else {
                    dp[i][4]++;
                }
            }
        }

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int l = 1; l <= 3; l++) {
                    for (int t = 1; t <= 3; t++) {
                        ss = (char)('A' + (i - 1));
                        se = (char)('A' + (j - 1));
                        es = (char)('A' + (l - 1));
                        ee = (char)('A' + (t - 1));
                        
                        ln = n - 2;
                        lm = m - 2;

                        if (n == 1) {
                            ss = se;
                            ln = 0; // Reset ln variable if needed, though logic below uses n directly
                        }
                        if (m == 1) {
                            es = ee;
                        }

                        cnt = 0;
                        if (se == 'A' && es == 'C') {
                            cnt += dp[(int)k][2];
                        }
                        if (se == 'A' && ss == 'C') {
                            cnt += dp[(int)k][1];
                        }
                        if (ee == 'A' && ss == 'C') {
                            cnt += dp[(int)k][3];
                        }
                        if (ee == 'A' && es == 'C') {
                            cnt += dp[(int)k][4];
                        }
                        
                        if (se == 'C' || ss == 'A') {
                            ln++;
                        }
                        if (es == 'A' || ee == 'C') {
                            lm++;
                        }

                        int halfN = (int)(n / 2);
                        int halfM = (int)(m / 2);

                        // Re-evaluating logic based on variable names in C++
                        // C++: ln = n-2; lm = m-2; ... if(n==1) ss=se; if(m==1) es=ee;
                        // Then loops use 'ln' and 'lm'.
                        // In Java, I'll use 'ln' and 'lm' as defined.
                        
                        // Wait, the C++ code uses 'ln' and 'lm' which are modified by n==1/m==1 checks.
                        // Let's trace carefully:
                        // ln = n-2; lm = m-2;
                        // if(n==1) ss=se; (ln is not updated here in C++ code provided? 
                        // Actually C++ code: "ln=n-2; lm=m-2; if(n==1) ss=se; if(m==1) es=ee;"
                        // It does NOT update ln based on n==1. It just updates characters.
                        // BUT later: "if(n==2 && ss=='A' && se=='C') cnt+=cs[k];"
                        // So ln is used for loop limit.
                        
                        // Correction on variable mapping:
                        // C++: ln = n-2; lm = m-2;
                        // Java: ln = n-2; lm = m-2;
                        
                        // Re-calculating ln and lm based on n and m
                        ln = n - 2;
                        lm = m - 2;

                        // If n==1, the loop for ss/se logic might differ, but the loop limit 'ln' remains n-2 (-1).
                        // However, the C++ code sets ss=se if n==1.
                        // Let's stick strictly to the C++ logic provided.
                        
                        // Re-declaring variables inside loop for clarity or use static fields updated before?
                        // In C++, ss, se, es, ee are chars. ln and lm are longs.
                        // I will re-calculate them inside the loop to be safe.
                        
                        long currentN = n;
                        long currentM = m;
                        
                        if (currentN == 1) {
                            ss = se;
                        }
                        if (currentM == 1) {
                            es = ee;
                        }

                        cnt = 0;
                        if (se == 'A' && es == 'C') {
                            cnt += dp[(int)k][2];
                        }
                        if (se == 'A' && ss == 'C') {
                            cnt += dp[(int)k][1];
                        }
                        if (ee == 'A' && ss == 'C') {
                            cnt += dp[(int)k][3];
                        }
                        if (ee == 'A' && es == 'C') {
                            cnt += dp[(int)k][4];
                        }
                        
                        if (se == 'C' || ss == 'A') {
                            ln++;
                        }
                        if (es == 'A' || ee == 'C') {
                            lm++;
                        }
                        
                        // C++: ln/=2; lm/=2;
                        ln /= 2;
                        lm /= 2;

                        for (long xx = 1; xx <= ln; xx++) {
                            help[xx] = (xx * cs[(int)k]) + cnt;
                            if (x >= help[xx]) {
                                if ((x - help[xx]) % ce[(int)k] == 0 || x == help[xx]) {
                                    pos = (x - help[xx]) / ce[(int)k];
                                    if (pos <= lm) {
                                        print(ss, se, currentN, xx);
                                        print(es, ee, currentM, pos);
                                        System.out.println();
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        System.out.println("Happy new year!");
    }
}
</CODE>