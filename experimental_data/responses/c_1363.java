Translate this C++ code to Java code. The main class name should be c_1363. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <bits/stdc++.h>

using namespace std;

int32_t main() {

	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int TC; cin >> TC; while (TC--) {

		int N, X; cin >> N >> X;

		map<int, int> cnt;

		for (int i = 0; i < N-1; ++i) {

			int u, v; cin >> u >> v;

			cnt[u]++, cnt[v]++;

		}

		if (cnt[X] == 0 || cnt[X] == 1) cout << "Ayush" << endl;

		else {

			if (N % 2 == 0) cout << "Ayush" << endl; else cout << "Ashish" << endl;

		}

	}

	return 0;

}

<think>

</think>

### Translation Plan

1.  **Header Inclusion**:
    *   C++: `#include <bits/stdc++.h>` includes everything.
    *   Java: Replace with specific imports. The code uses `Scanner` and `System`, so we need `import java.util.Scanner;`.

2.  **Main Method**:
    *   C++: `int32_t main()`
    *   Java: `public static void main(String[] args)`

3.  **I/O Optimization**:
    *   C++: `ios_base::sync_with_stdio(false); cin.tie(nullptr);`
    *   Java: Standard `Scanner` is slow. To mimic the optimization, we can use `BufferedReader` and `StringTokenizer` for faster I/O, or simply rely on the fact that for typical CP limits, `Scanner` might suffice, but given the explicit optimization in C++, `BufferedReader` is the correct Java equivalent for competitive programming contexts. I will use `BufferedReader` and `StringTokenizer` for robustness and speed.

4.  **Data Structures**:
    *   C++: `map<int, int> cnt;`
    *   Java: `Map<Integer, Integer> cnt = new HashMap<>();`

5.  **Logic Flow**:
    *   C++: `cin >> TC; while (TC--)`
    *   Java: Read `TC`, loop `while (TC-- > 0)`.
    *   C++: `cin >> N >> X;`
    *   Java: Read `N` and `X`.
    *   C++: Loop `for (int i = 0; i < N-1; ++i)` reading `u, v` and updating `cnt`.
    *   Java: Loop `for (int i = 0; i < N - 1; i++)` reading `u, v` and updating the map.
    *   C++: Conditional checks `if (cnt[X] == 0 || cnt[X] == 1)` and `N % 2`.
    *   Java: Equivalent `if` statements. Note that accessing `cnt[X]` in Java returns `null` if the key is missing, which would throw a `NullPointerException`. We must handle the "missing key" case (equivalent to count 0) explicitly or use `cnt.getOrDefault(X, 0)`.

6.  **Output**:
    *   C++: `cout << "Ayush" << endl;`
    *   Java: `System.out.println("Ayush");`

7.  **Incremental Steps**:
    *   Step 1: Setup class structure and imports.
    *   Step 2: Implement `main` and `FastReader` (or direct `BufferedReader` usage).
    *   Step 3: Implement the test case loop and input reading for `N`, `X`.
    *   Step 4: Implement the map logic to count degrees.
    *   Step 5: Implement the conditional logic for outputting "Ayush" or "Ashish".

### Java Code

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class c_1363 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        // Function to read next token
        // Using a local class or simple method inside main logic flow
        // Since we are inside main, we'll just manage the tokenizer here.
        
        // Read number of test cases
        String line = br.readLine();
        if (line == null) return;
        st = new StringTokenizer(line);
        if (!st.hasMoreTokens()) return;
        
        int TC = Integer.parseInt(st.nextToken());

        while (TC-- > 0) {
            // Read N and X
            while (!st.hasMoreTokens()) {
                line = br.readLine();
                if (line == null) break;
                st = new StringTokenizer(line);
            }
            int N = Integer.parseInt(st.nextToken());
            int X = Integer.parseInt(st.nextToken());

            // Map to store counts
            Map<Integer, Integer> cnt = new HashMap<>();

            // Read N-1 edges
            for (int i = 0; i < N - 1; i++) {
                while (!st.hasMoreTokens()) {
                    line = br.readLine();
                    if (line == null) break;
                    st = new StringTokenizer(line);
                }
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());

                cnt.put(u, cnt.getOrDefault(u, 0) + 1);
                cnt.put(v, cnt.getOrDefault(v, 0) + 1);
            }

            // Logic to determine winner
            int countX = cnt.getOrDefault(X, 0);
            
            if (countX == 0 || countX == 1) {
                System.out.println("Ayush");
            } else {
                if (N % 2 == 0) {
                    System.out.println("Ayush");
                } else {
                    System.out.println("Ashish");
                }
            }
        }
    }
}
</CODE>