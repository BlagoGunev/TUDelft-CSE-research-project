Translate this C++ code to Java code. The main class name should be a_813. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <stdio.h>
int main(){
	int n,m;
	scanf("%d",&n);
	int t,t1,t2,ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		ans+=t;
	}
	scanf("%d",&m);
	if(!m){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		if(ans<=t1){
			printf("%d\n",t1);
			return 0;
		}
		else if(ans<=t2){
			printf("%d\n",ans);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

Here is the translation plan:

1.  **Header Inclusion**: The C++ code uses `#include <stdio.h>`, which is necessary for `scanf` and `printf`. In Java, these functions are part of the `java.io` package, specifically the `Scanner` and `System.out` classes.
2.  **Main Class Definition**: The C++ `main` function becomes the `main` method inside a public class named `a_813` as requested.
3.  **Input/Output**:
    *   `scanf("%d",&n)` and `scanf("%d %d",&t1,&t2)` are replaced by `scanner.nextInt()`.
    *   `printf` statements are replaced by `System.out.println()`.
    *   The logic for reading integers remains the same, but we need to handle the logic flow carefully as Java is strictly typed.
4.  **Variable Declaration**: C++ allows implicit type conversion in some contexts, but Java requires explicit declaration of variables before use. `int n`, `int m`, `int t`, `int t1`, `int t2`, and `int ans` will be declared explicitly.
5.  **Control Flow**: The `for` loops and `if` statements translate directly to Java syntax.
6.  **Logic Splitting**:
    *   Read `n`.
    *   Loop `n` times to read `t` and update `ans`.
    *   Read `m`.
    *   Check if `m` is 0. If so, print "-1".
    *   Loop `m` times to read `t1` and `t2` and check conditions against `ans`.
    *   If no answer is found after `m` queries, print "-1".

Here is the Java code:

<CODE>
import java.util.Scanner;

public class a_813 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        int t = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            t = scanner.nextInt();
            ans += t;
        }
        
        int m = scanner.nextInt();
        if (m == 0) {
            System.out.println("-1");
            return;
        }
        
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < m; i++) {
            t1 = scanner.nextInt();
            t2 = scanner.nextInt();
            
            if (ans <= t1) {
                System.out.println(t1);
                return;
            } else if (ans <= t2) {
                System.out.println(ans);
                return;
            }
        }
        
        System.out.println("-1");
    }
}
</CODE>