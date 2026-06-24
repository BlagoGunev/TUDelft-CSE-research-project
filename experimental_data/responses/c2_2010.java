Translate this C++ code to Java code. The main class name should be c2_2010. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll shash[1000005];
ll pot[1000005];
ll mod = 1e9+7;
ll p = 191;

int main()
{
    string s;
    cin >> s;
    pot[0] = 1;
    for(int i = 1; i <= 1000003; i++)
    {
        pot[i] = (pot[i-1] * p) % mod;
    }
    shash[0] = s[0] - '0' + 1;
    //cout << shash[0] << endl;
    for(int i = 1 ; i < s.size(); i++)
    {
        shash[i] = (shash[i-1] + (s[i] - '0' + 1) * pot[i] + mod) % mod;
        //cout << shash[i] << endl;
    }
    int startt = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        //cout << (shash[i] * pot[s.size()-i-1] + mod) % mod << " " <<  (shash[s.size()-1] - shash[s.size() - i - 2] + mod) % mod << endl;
        if((shash[i] * pot[s.size()-i-1] + mod) % mod == (shash[s.size()-1] - shash[s.size() - i - 2] + mod) % mod)
        {
            startt = i+1;
        }
    }
    if(startt > s.size()/2)
    {
        cout << "YES" << endl;
        for(int i = 0; i < startt; i++)
        {
            cout << s[i];
        }
    }
    else
    {
        cout << "NO" << endl;
    }





}

Here is the plan for the translation:

1.  **Headers**:
    *   Replace `#include<bits/stdc++.h>` with specific headers: `<iostream>`, `<string>`, `<vector>`.
    *   Remove `using namespace std;` to follow best practices, or keep it if preferred for brevity (I will keep it for simplicity as the original code implies it).
    *   Replace `#define ll long long` with `using long long ll;` or explicit types.

2.  **Arrays**:
    *   C++ arrays like `ll shash[1000005]` are static. In Java, these become arrays `long[] shash = new long[1000005];`.
    *   The size `1000005` must be defined as a constant (e.g., `MAX_SIZE`) to make the array creation safe and clear.

3.  **Main Method**:
    *   The C++ `main` function maps directly to Java's `public static void main(String[] args)`.
    *   **Input**: `cin >> s;` is replaced by `Scanner sc = new Scanner(System.in); String s = sc.next();`.
    *   **Output**: `cout << ... << endl;` is replaced by `System.out.println(...)` or `System.out.print(...)`.

4.  **Logic & Types**:
    *   Variable `ll` is `long` in Java.
    *   The modulo arithmetic logic remains the same, but ensure Java's `%` operator works correctly with negative numbers (though the logic provided `+ mod` handles this).
    *   Array indexing: C++ `shash[0]` corresponds to `shash[0]` in Java.

5.  **Incremental Tasks**:
    *   **Task 1**: Setup headers, define constants, and declare static arrays.
    *   **Task 2**: Implement the pre-computation of powers (`pot`).
    *   **Task 3**: Implement the computation of the rolling hash (`shash`).
    *   **Task 4**: Implement the palindrome check logic using the precomputed hashes.
    *   **Task 5**: Implement the output logic based on the check.

Here is the resulting Java code:

<CODE>
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.BufferedOutputStream;

public class c2_2010 {
    static final int MAX_SIZE = 1000005;
    static final long MOD = 1000000007L;
    static final long P = 191;

    static long[] shash = new long[MAX_SIZE];
    static long[] pot = new long[MAX_SIZE];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        // Precompute powers
        pot[0] = 1;
        for(int i = 1; i < MAX_SIZE; i++) {
            pot[i] = (pot[i-1] * P) % MOD;
        }

        // Compute prefix hashes
        // shash[i] represents the hash of the prefix s[0...i]
        // Note: The original code logic for shash[i] seems to assume 0-based indexing for the loop 
        // but calculates based on position. Let's map strictly to the C++ logic.
        // C++: shash[0] = s[0] - '0' + 1;
        // C++: shash[i] = (shash[i-1] + (s[i] - '0' + 1) * pot[i] + mod) % mod;
        
        // Note: The C++ code uses string index `i` for `shash[i]`. 
        // Java strings are 0-indexed, so s[i] maps to s.charAt(i).
        // However, the C++ code iterates up to `s.size() - 1`.
        // We must ensure the array is large enough for the string length.
        
        if (s.length() >= MAX_SIZE) {
            // In a real scenario, we would resize or handle this, but following the C++ structure:
            // We assume the input fits within the static array size defined.
        }

        shash[0] = (s.charAt(0) - '0' + 1);
        
        for(int i = 1; i < s.length(); i++) {
            long charVal = (s.charAt(i) - '0' + 1);
            shash[i] = (shash[i-1] + (charVal * pot[i]) % MOD + MOD) % MOD;
        }

        int startt = 0;
        // Check for palindromic suffix
        // The logic checks if the prefix s[0...i] (reversed) matches the suffix s[i+1...end]
        // Original C++ logic:
        // (shash[i] * pot[s.size()-i-1] + mod) % mod == (shash[s.size()-1] - shash[s.size() - i - 2] + mod) % mod
        
        // In Java:
        // Left side: Hash of s[0...i] reversed.
        // Right side: Hash of s[i+1...end].
        
        for(int i = 0; i < s.length() - 1; i++) {
            long leftHash = (shash[i] * pot[s.length() - i - 1]) % MOD;
            long rightHash = (shash[s.length() - 1] - shash[s.length() - i - 2] + MOD) % MOD;
            
            if(leftHash == rightHash) {
                startt = i + 1;
            }
        }

        if(startt > s.length() / 2) {
            System.out.println("YES");
            for(int i = 0; i < startt; i++) {
                System.out.print(s.charAt(i));
            }
        } else {
            System.out.println("NO");
        }
        
        // Close scanner if needed, though usually not strictly necessary for competitive programming
        sc.close();
    }
}
</CODE>