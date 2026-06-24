Translate this C++ code to Java code. The main class name should be c_1099. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define read freopen("in.in","r",stdin)
#define write freopen("out.out","w",stdout)
using namespace std;

typedef long long ll;



int main(){
	ios::sync_with_stdio(false);
	//read; write;
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	int candy = 0, snow = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '?') candy++;
		else if (s[i] == '*') snow++;
	}

	int len = s.size() - candy - snow;
	if (k < len - candy - snow || (k > len && snow == 0)) {
		cout << "Impossible";
		return 0;
	}
	if (k < len){
		string r;
		int c = len - k;
		for (int i = 0; i < n; i++){
			if (s[i] != '?' && s[i] != '*') r += s[i];
			else if (c > 0){
				r.pop_back();
				c--;
			}
		}
		cout << r;
	}
	else {
		string r;
		int c = k - len;
		for (int i = 0; i < n; i++){
			if (s[i] != '?' && s[i] != '*') r += s[i];
			else if (s[i] == '*' && c > 0){
				while (c--){
					r += s[i - 1];
				}
			}
		}
		cout << r;

	}
	return 0;
}

Here is the plan for the translation from C++ to Java.

### Translation Plan

1.  **Class Structure**:
    *   C++ uses `int main()` as the entry point.
    *   Java requires a `public static void main(String[] args)` method inside a class.
    *   The class name must be `c_1099`.

2.  **Headers and Imports**:
    *   C++ uses `#include<bits/stdc++.h>` and `using namespace std;`.
    *   Java requires explicit imports. `String` is in `java.lang` (default), but `Scanner` is in `java.util`.
    *   C++ macros (`read`, `write`, `_CRT_SECURE_NO_WARNINGS`) are preprocessor directives. These will be ignored or adapted. The file redirection logic (`freopen`) is not standard in Java and will be omitted, assuming standard input/output.

3.  **Data Types**:
    *   C++ `long long` is mapped to Java `long`.
    *   C++ `int` remains `int` in Java.
    *   C++ `string` is mapped to Java `String`.

4.  **Logic Translation**:
    *   **Input**: C++ `cin >> s >> k` becomes Java `scanner.next()` and `scanner.nextInt()`.
    *   **Counting**: The loop `for (int i = 0; i < n; i++)` remains similar but uses Java syntax (e.g., `s.charAt(i)`).
    *   **Output**: C++ `cout << ...` becomes Java `System.out.println(...)`.
    *   **String Manipulation**:
        *   C++ `r += s[i]` (char to string) becomes Java `r += s.charAt(i)` (char to string).
        *   C++ `r.pop_back()` (removing last char) becomes Java `r = r.substring(0, r.length() - 1)`.
    *   **Logic Flow**: The `if/else` structure is preserved.

5.  **Incremental Tasks**:
    *   Step 1: Define class and imports.
    *   Step 2: Implement input reading.
    *   Step 3: Implement counting logic (`candy` and `snow`).
    *   Step 4: Implement the "Impossible" check.
    *   Step 5: Implement the "remove '?' logic" (when `k < len`).
    *   Step 6: Implement the "change '?' to '*' logic" (when `k > len`).
    *   Step 7: Finalize main method and remove unused variables.

### Java Code

<CODE>
import java.util.Scanner;

public class c_1099 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int k = scanner.nextInt();
        int n = s.length();
        int candy = 0;
        int snow = 0;
        
        for (int i = 0; i < n; i++) {
            char currentChar = s.charAt(i);
            if (currentChar == '?') {
                candy++;
            } else if (currentChar == '*') {
                snow++;
            }
        }

        int len = n - candy - snow;
        if (k < len - candy - snow || (k > len && snow == 0)) {
            System.out.println("Impossible");
            return;
        }

        if (k < len) {
            StringBuilder r = new StringBuilder();
            int c = len - k;
            for (int i = 0; i < n; i++) {
                char currentChar = s.charAt(i);
                if (currentChar != '?' && currentChar != '*') {
                    r.append(currentChar);
                } else if (c > 0) {
                    // We skip the current '?' and decrement c
                    // In C++, this was r.pop_back() which implies we just don't append it
                    // and decrement c.
                    c--;
                }
            }
            System.out.println(r.toString());
        } else {
            StringBuilder r = new StringBuilder();
            int c = k - len;
            for (int i = 0; i < n; i++) {
                char currentChar = s.charAt(i);
                if (currentChar != '?' && currentChar != '*') {
                    r.append(currentChar);
                } else if (currentChar == '?' && c > 0) {
                    while (c-- > 0) {
                        // We need to append the previous character 's[i-1]'
                        // Check boundary just in case, though logic implies i > 0 here usually
                        if (i > 0) {
                            r.append(s.charAt(i - 1));
                        }
                    }
                    // Skip the current '?'
                }
            }
            System.out.println(r.toString());
        }
    }
}
</CODE>