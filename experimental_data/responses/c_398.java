Translate this C++ code to Java code. The main class name should be c_398. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n==5){
		puts("1 2 3");
		puts("1 3 3");
		puts("2 4 2");
		puts("4 5 1");
		puts("3 4");
		puts("3 5");
		return 0;
	}
	else{
		int t=n/2;
		for(int i=1;i<=t;i++)printf("%d %d %d\n",i,i+t,1);
		for(int i=1;i+t<n;i++)printf("%d %d %d\n",i+t,i+t+1,2*i-1);
		for(int i=1;i<t;i++)printf("%d %d\n",i,i+1);
		puts("1 3");
	}
}

Here is the plan for the translation from C++ to Java.

### Translation Plan

1.  **Class Structure**:
    *   The C++ code uses `int main()` and global variables.
    *   The Java equivalent requires a class named `c_398` with a `public static void main(String[] args)` method.
    *   Global variables (like `n`) will be moved to local variables inside the `main` method.

2.  **Input/Output**:
    *   **Input**: C++ uses `scanf` from `<cstdio>`. Java uses `Scanner` from `java.util`.
    *   **Output**: C++ uses `printf` and `puts` from `<cstdio>`. Java uses `System.out.println` or `System.out.print`. Since the output format is space-separated integers, `System.out.println` is the most direct replacement for `printf` with newlines, and `System.out.print` for lines without newlines (though `println` works for the last line too).

3.  **Logic Implementation**:
    *   The logic is divided into three main sections based on the condition `n == 5`.
    *   **Case `n == 5`**: Directly print the hardcoded lines.
    *   **Case `n != 5`**:
        *   Calculate `t = n / 2`.
        *   **Loop 1**: Iterate from 1 to `t`, printing `i`, `i+t`, and `1`.
        *   **Loop 2**: Iterate from 1 to `t-1` (since the condition is `i+t < n`), printing `i+t`, `i+t+1`, and `2*i-1`.
        *   **Loop 3**: Iterate from 1 to `t-1`, printing `i` and `i+1`.
        *   **Final Line**: Print `1 3`.

4.  **Imports**:
    *   Include `java.util.Scanner`.

5.  **Incremental Tasks**:
    *   Task 1: Setup class and imports, replace `scanf` with `Scanner`.
    *   Task 2: Implement the `if (n==5)` block.
    *   Task 3: Implement the `else` block with the three loops and the final print statement.
    *   Task 4: Combine and verify.

### Java Code

```java
import java.util.Scanner;

public class c_398 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            
            if (n == 5) {
                System.out.println("1 2 3");
                System.out.println("1 3 3");
                System.out.println("2 4 2");
                System.out.println("4 5 1");
                System.out.println("3 4");
                System.out.println("3 5");
            } else {
                int t = n / 2;
                
                // Loop 1: for(int i=1;i<=t;i++)printf("%d %d %d\n",i,i+t,1);
                for (int i = 1; i <= t; i++) {
                    System.out.println(i + " " + (i + t) + " 1");
                }
                
                // Loop 2: for(int i=1;i+t<n;i++)printf("%d %d %d\n",i+t,i+t+1,2*i-1);
                for (int i = 1; i + t < n; i++) {
                    System.out.println((i + t) + " " + (i + t + 1) + " " + (2 * i - 1));
                }
                
                // Loop 3: for(int i=1;i<t;i++)printf("%d %d\n",i,i+1);
                for (int i = 1; i < t; i++) {
                    System.out.println(i + " " + (i + 1));
                }
                
                // Final line: puts("1 3");
                System.out.println("1 3");
            }
        }
        scanner.close();
    }
}
```

<CODE>
import java.util.Scanner;

public class c_398 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            
            if (n == 5) {
                System.out.println("1 2 3");
                System.out.println("1 3 3");
                System.out.println("2 4 2");
                System.out.println("4 5 1");
                System.out.println("3 4");
                System.out.println("3 5");
            } else {
                int t = n / 2;
                
                // Loop 1: for(int i=1;i<=t;i++)printf("%d %d %d\n",i,i+t,1);
                for (int i = 1; i <= t; i++) {
                    System.out.println(i + " " + (i + t) + " 1");
                }
                
                // Loop 2: for(int i=1;i+t<n;i++)printf("%d %d %d\n",i+t,i+t+1,2*i-1);
                for (int i = 1; i + t < n; i++) {
                    System.out.println((i + t) + " " + (i + t + 1) + " " + (2 * i - 1));
                }
                
                // Loop 3: for(int i=1;i<t;i++)printf("%d %d\n",i,i+1);
                for (int i = 1; i < t; i++) {
                    System.out.println(i + " " + (i + 1));
                }
                
                // Final line: puts("1 3");
                System.out.println("1 3");
            }
        }
        scanner.close();
    }
}
</CODE>