Translate this C++ code to Java code. The main class name should be b_664. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>

using namespace std;

int p = 1, n, j, a[105];

char c;

int main()

{

	a[j++] = 1;

	while (cin >> c && c != '=')

	{

		if (c == '-')

		   p--, a[j++] = -1;

		if (c == '+')

		   p++, a[j++] = 1;

	}

	cin >> n;

	for(int i=0;i<j;i++)

	{

		if(a[i]>0)

		   while (p<n && a[i]<n)

		       a[i]++, p++;

		else

		   while (p>n && a[i]<0 && a[i]>-n)

		       a[i]--, p--;

	}

	if (p != n)

    {

	    cout << "Impossible"<<endl;

        return 0;

    }

	cout << "Possible"<<endl;

	cout<<a[0];



	for(int i=1;i<j;i++)

       if(a[i]<0)

          cout<<" - "<<-a[i];

       else

          cout<<" + "<<a[i];

       cout << " = " << n;

	return 0;

}

Here is the plan for the translation from C++ to Java.

### Translation Plan

1.  **Environment Setup**:
    *   Java does not have a global namespace like C++. Variables must be declared inside classes.
    *   The `main` method signature changes from `int main()` to `public static void main(String[] args)`.
    *   The C++ global variables (`p`, `n`, `j`, `a[]`, `c`) will be converted to static member variables or local variables within `main`. Since they are initialized before `main` logic starts in C++, making them static fields is a direct structural equivalent, though keeping them local to `main` is often cleaner in Java. Here, I will define them as local variables inside `main` to avoid static initialization order issues, which is a common pitfall when porting global C++ state.

2.  **Input/Output**:
    *   C++ `iostream` (`cin`, `cout`) will be replaced by `java.util.Scanner` for input and `System.out.println` / `System.out.print` for output.
    *   Character input (`char c`) in C++ reads a single character including whitespace skipping (if formatted that way) or raw bytes. `Scanner.next().charAt(0)` is a robust way to handle this in Java, skipping whitespace automatically.

3.  **Arrays**:
    *   C++ `int a[105]` is a static array. Java uses dynamic arrays (`int[]`). We need to initialize `a` with a size of 105.
    *   Indexing in Java is 0-based, same as C++, so `a[j++]` maps directly to `a[j++]`.

4.  **Logic Flow**:
    *   The logic involving `while(cin >> c && c != '=')` needs to be carefully translated. In Java, `Scanner` checks for tokens. We can loop while `scanner.hasNext()` and break if the token equals "=".
    *   Nested loops and `if-else` logic remain largely the same, with syntax adjustments (e.g., braces are optional but recommended for clarity).

5.  **Incremental Tasks**:
    *   **Step 1**: Setup class structure and imports (`java.util.Scanner`).
    *   **Step 2**: Declare variables (`p`, `n`, `j`, `a`, `c`) and initialize `a` to size 105.
    *   **Step 3**: Translate the first loop reading characters (`-`, `+`, `=`).
    *   **Step 4**: Translate the nested loops that adjust `a[i]` and `p`.
    *   **Step 5**: Translate the output logic (Impossible/Possible, array printing).
    *   **Step 6**: Compile and verify.

### Java Code

```java
import java.util.Scanner;

public class b_664 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // C++ globals converted to local variables
        int p = 1;
        int n;
        int j;
        int[] a = new int[105];
        String cStr;

        // Initialize the first element as in C++: a[j++] = 1;
        // Assuming j starts at 0 globally or implicitly before usage.
        // In C++, j is global so it is 0.
        j = 0;
        a[j++] = 1;

        // C++: while (cin >> c && c != '=')
        // Java: Read tokens until we find '=' or run out of input.
        // Note: Scanner skips whitespace by default.
        while (scanner.hasNext()) {
            cStr = scanner.next();
            char c = cStr.charAt(0);

            if (c == '=') {
                break;
            }

            if (c == '-') {
                p--;
                a[j++] = -1;
            }
            if (c == '+') {
                p++;
                a[j++] = 1;
            }
        }

        // C++: cin >> n;
        if (scanner.hasNextInt()) {
            n = scanner.nextInt();
        }

        // Logic block
        for (int i = 0; i < j; i++) {
            if (a[i] > 0) {
                while (p < n && a[i] < n) {
                    a[i]++;
                    p++;
                }
            } else {
                // Note: Original C++ logic 'else' covers a[i] <= 0.
                // The condition 'a[i] < 0 && a[i] > -n' handles negative values.
                while (p > n && a[i] < 0 && a[i] > -n) {
                    a[i]--;
                    p--;
                }
            }
        }

        if (p != n) {
            System.out.println("Impossible");
            return;
        }

        System.out.println("Possible");
        System.out.print(a[0]);

        for (int i = 1; i < j; i++) {
            if (a[i] < 0) {
                System.out.print(" - " + (-a[i]));
            } else {
                System.out.print(" + " + a[i]);
            }
        }
        System.out.print(" = " + n);
    }
}
```

<CODE>
import java.util.Scanner;

public class b_664 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // C++ globals converted to local variables
        int p = 1;
        int n;
        int j;
        int[] a = new int[105];
        String cStr;

        // Initialize the first element as in C++: a[j++] = 1;
        // Assuming j starts at 0 globally or implicitly before usage.
        // In C++, j is global so it is 0.
        j = 0;
        a[j++] = 1;

        // C++: while (cin >> c && c != '=')
        // Java: Read tokens until we find '=' or run out of input.
        // Note: Scanner skips whitespace by default.
        while (scanner.hasNext()) {
            cStr = scanner.next();
            char c = cStr.charAt(0);

            if (c == '=') {
                break;
            }

            if (c == '-') {
                p--;
                a[j++] = -1;
            }
            if (c == '+') {
                p++;
                a[j++] = 1;
            }
        }

        // C++: cin >> n;
        if (scanner.hasNextInt()) {
            n = scanner.nextInt();
        }

        // Logic block
        for (int i = 0; i < j; i++) {
            if (a[i] > 0) {
                while (p < n && a[i] < n) {
                    a[i]++;
                    p++;
                }
            } else {
                // Note: Original C++ logic 'else' covers a[i] <= 0.
                // The condition 'a[i] < 0 && a[i] > -n' handles negative values.
                while (p > n && a[i] < 0 && a[i] > -n) {
                    a[i]--;
                    p--;
                }
            }
        }

        if (p != n) {
            System.out.println("Impossible");
            return;
        }

        System.out.println("Possible");
        System.out.print(a[0]);

        for (int i = 1; i < j; i++) {
            if (a[i] < 0) {
                System.out.print(" - " + (-a[i]));
            } else {
                System.out.print(" + " + a[i]);
            }
        }
        System.out.print(" = " + n);
    }
}
</CODE>