Translate this C++ code to Java code. The main class name should be b_1829. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int max_blank_space = 0;
        int current_blank_space = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] == 0) {
                current_blank_space++;
            } else {
                max_blank_space = max(max_blank_space, current_blank_space);
                current_blank_space = 0;
            }
        }

        max_blank_space = max(max_blank_space, current_blank_space);

        cout << max_blank_space << endl;
    }

    return 0;
}

Here is the plan for translating the C++ code to Java:

1.  **Main Class Structure**:
    *   C++: `int main()` is the entry point.
    *   Java: `public static void main(String[] args)` is the entry point.
    *   Class Name: The class must be named `b_1829` and must be declared as `public`.

2.  **Input/Output**:
    *   C++: Uses `cin` and `cout` from `<iostream>`.
    *   Java: Uses `java.util.Scanner` for input (`System.in`) and `System.out.println` for output.
    *   Note: `cin` reads integers directly, while `Scanner` also reads integers directly. `endl` is replaced by `println`.

3.  **Data Structures**:
    *   C++: `vector<int> arr(n)` is a dynamic array.
    *   Java: `int[] arr = new int[n]` is the equivalent.

4.  **Logic & Control Flow**:
    *   `using namespace std;`: In Java, we use fully qualified names or import `java.util.*`.
    *   `while (t--)`: This loop structure is identical in both languages.
    *   `max()`: C++ uses the global `std::max`. Java does not have a global `max` function in the same way; usually, we implement it manually or use `Math.max()`. We will use `Math.max()`.

5.  **Incremental Task Split**:
    *   **Step 1**: Define the class and `main` method, setup `Scanner`.
    *   **Step 2**: Read `t` (number of test cases).
    *   **Step 3**: Loop `t` times. Inside the loop:
        *   Read `n`.
        *   Create the array `arr` and read `n` integers.
        *   Iterate through `arr` to calculate `max_blank_space` and `current_blank_space`.
        *   Print the result.

6.  **Code Translation**:
    *   Replace `vector<int>` with `int[]`.
    *   Replace `std::max` with `Math.max`.
    *   Replace `cin >> var` with `scanner.nextInt()`.
    *   Replace `cout << var << endl` with `System.out.println(var)`.

```CODE
import java.util.Scanner;

public class b_1829 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        if (scanner.hasNextInt()) {
            int t = scanner.nextInt();

            while (t-- > 0) {
                int n = scanner.nextInt();

                int[] arr = new int[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = scanner.nextInt();
                }

                int maxBlankSpace = 0;
                int currentBlankSpace = 0;

                for (int i = 0; i < n; i++) {
                    if (arr[i] == 0) {
                        currentBlankSpace++;
                    } else {
                        maxBlankSpace = Math.max(maxBlankSpace, currentBlankSpace);
                        currentBlankSpace = 0;
                    }
                }

                maxBlankSpace = Math.max(maxBlankSpace, currentBlankSpace);

                System.out.println(maxBlankSpace);
            }
        }
        
        scanner.close();
    }
}
```