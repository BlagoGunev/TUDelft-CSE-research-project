Translate this C++ code to Java code. The main class name should be d_851. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<iostream>
#include<cstdio>
using namespace std;
int n,x,y;
bool f[1000010];
int a[500010];
int cnt[1000010];
long long ans=1e18;
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	for(int i=2;i<=1000000;i++)
	{
		if(f[i])continue;
		int s=cnt[i];
		for(int j=i+i;j<=1000000;j+=i)
		{
			f[j]=true;
			s+=cnt[j];
		}
		long long res=0;
		if(1LL*(n-s)*min(x,y)>=ans)continue;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%i==0)continue;
			int md=a[j]%i;
			res+=min(1LL*x,1LL*(i-md)*y);
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}

<think>

</think>

### Translation Plan

To translate the provided C++ code to Java, we need to address several language differences:

1.  **Input/Output**:
    *   C++ uses `scanf` and `printf` from `<cstdio>`.
    *   Java uses `Scanner` and `System.out.println` (or `PrintWriter` for better performance, though `Scanner` is sufficient here given the logic).
    *   Note: `scanf` reads integers directly, while `Scanner` requires method calls (`nextInt()`).

2.  **Data Types**:
    *   C++ `long long` maps to Java `long`.
    *   C++ `int` maps to Java `int`.
    *   C++ `bool` maps to Java `boolean`.

3.  **Arrays**:
    *   C++ arrays (`int a[500010]`) are statically allocated with a fixed size.
    *   Java arrays must be instantiated dynamically (`new int[size]`). We will define the size based on the maximum index used in the loop (`1000001` to accommodate indices up to `1000000`).

4.  **Main Method**:
    *   C++ `main()` returns `int`.
    *   Java `main` method signature must be `public static void main(String[] args)`.

5.  **Logic Preservation**:
    *   The Sieve-like logic for finding non-primes and calculating costs remains identical, except for syntax adjustments (e.g., `1LL` becomes `1L` or explicit casting).
    *   Variable declarations are moved to the top of the method or class in Java.

6.  **Incremental Tasks**:
    *   Step 1: Define class structure and static variables.
    *   Step 2: Implement input reading.
    *   Step 3: Implement frequency counting array population.
    *   Step 4: Implement the sieve logic and cost calculation.
    *   Step 5: Implement output.

### Java Code

<CODE>
import java.util.Scanner;

public class d_851 {
    static int n, x, y;
    static boolean[] f = new boolean[1000011];
    static int[] a = new int[500011];
    static int[] cnt = new int[1000011];
    static long ans = Long.MAX_VALUE; // Using Long.MAX_VALUE instead of 1e18 for safety, though 1e18 is effectively the same for long

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        if (scanner.hasNextInt()) {
            n = scanner.nextInt();
            x = scanner.nextInt();
            y = scanner.nextInt();
            
            for (int i = 1; i <= n; i++) {
                a[i] = scanner.nextInt();
                cnt[a[i]]++;
            }
            
            for (int i = 2; i <= 1000000; i++) {
                if (f[i]) continue;
                
                int s = cnt[i];
                for (int j = i + i; j <= 1000000; j += i) {
                    f[j] = true;
                    s += cnt[j];
                }
                
                long res = 0;
                if (1L * (n - s) * Math.min(x, y) >= ans) {
                    continue;
                }
                
                for (int j = 1; j <= n; j++) {
                    if (a[j] % i == 0) continue;
                    int md = a[j] % i;
                    res += Math.min(1L * x, 1L * (i - md) * y);
                }
                
                if (res < ans) {
                    ans = res;
                }
            }
            
            System.out.println(ans);
        }
        
        scanner.close();
    }
}
</CODE>