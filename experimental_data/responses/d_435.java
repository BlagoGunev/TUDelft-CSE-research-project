Translate this C++ code to Java code. The main class name should be d_435. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>

#include <algorithm>

#include <stdio.h>

#include <set>

#include <string.h>

#include <string>

#include <vector>

#include <unordered_map>

#include <queue>

#include <iomanip>

#include <fstream>

#include <map>



using namespace std;

typedef vector<int> vi;

typedef pair<int,int> ii;

typedef long long ll;

typedef long double ld;

typedef pair<double,double> dd;

typedef pair<ll, ll> l4;

typedef vector<ii> vii;

int n,m;

char g[410][410];

int row[410][410];

int col[410][410];

int dig1[810][410];

int dig2[810][410];

int main() {

    scanf("%d%d",&n,&m);

    for (int i = 1; i <= n; i++) {

        scanf("%s",&g[i][1]);

    }

    // int t = max(n,m);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            row[i][j] = row[i][j-1]+g[i][j]-'0';

            dig1[i-j+m][i] = dig1[i-j+m][i-1]+g[i][j]-'0';

            dig2[i+j][i] = dig2[i+j][i-1]+g[i][j]-'0';

            col[j][i] = col[j][i-1]+g[i][j]-'0';

        }

    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (g[i][j] == '1') continue;

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && j-k>=1 && row[i][j]-row[i][j-k-1]==0 && col[j][i]-col[j][i-k-1]==0) {

                    if (dig2[i+j-k][i]-dig2[i+j-k][i-k-1] == 0) ans++;         

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && j+k<=m && row[i][j+k]-row[i][j-1]==0 && col[j][i]-col[j][i-k-1]==0) {

                    if (dig1[i-j-k+m][i]-dig1[i-j-k+m][i-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && j-k>=1 && row[i][j]-row[i][j-k-1]==0 && col[j][i+k]-col[j][i-1]==0) {

                    if (dig1[i-j+k+m][i+k]-dig1[i-j+k+m][i-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && j+k<=m && row[i][j+k]-row[i][j-1]==0 && col[j][i+k]-col[j][i-1]==0) {

                    if (dig2[i+j+k][i+k]-dig2[i+j+k][i-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && j+k<=m && j-k>=1 && dig1[i-j+m][i]-dig1[i-j+m][i-k-1]==0 && dig2[i+j][i]-dig2[i+j][i-k-1]==0) {

                    if (row[i-k][j+k]-row[i-k][j-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && i-k>=1 && j+k<=m && dig1[i-j+m][i+k]-dig1[i-j+m][i-1]==0 && dig2[i+j][i]-dig2[i+j][i-k-1]==0) {

                    if (col[j+k][i+k]-col[j+k][i-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i+k<=n && j+k<=m && j-k>=1 && dig1[i-j+m][i+k]-dig1[i-j+m][i-1]==0 && dig2[i+j][i+k]-dig2[i+j][i-1]==0) {

                    if (row[i+k][j+k]-row[i+k][j-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

            for (int k = 1; k < min(n,m); k++) {

                if (i-k>=1 && i+k<=n && j-k>=1 && dig1[i-j+m][i]-dig1[i-j+m][i-k-1]==0 && dig2[i+j][i+k]-dig2[i+j][i-1]==0) {

                    if (col[j-k][i+k]-col[j-k][i-k-1] == 0) ans++;                    

                } else {

                    break;

                }

            }

        }

    }

    cout << ans;

    return 0;

}

Here is the plan for translating the provided C++ code to Java:

1.  **Class Structure**: The C++ `main` function becomes the `main` method in a `public class d_435`.
2.  **Standard I/O**: C++ uses `scanf` and `cout`. Java uses `Scanner` or `BufferedReader` and `System.out.println`. Given the simplicity, `Scanner` is easier to read, but `BufferedReader` is faster. Since this code involves nested loops and potentially heavy computation (checking squares), `BufferedReader` and `StringTokenizer` are preferred for performance.
3.  **Typedefs**:
    *   `vector<int> vi` $\rightarrow$ `ArrayList<Integer>` or `int[]` (if size known, but here size is dynamic).
    *   `pair<int,int> ii` $\rightarrow$ A custom class or `int[]` (since primitive arrays are preferred for performance in CP, `int[]` or simple logic is used).
    *   `long long ll` $\rightarrow$ `long`.
    *   `long double ld` $\rightarrow$ `double` (or `BigDecimal` if precision matters, but here it's just a type alias).
    *   `pair<double,double> dd` $\rightarrow$ `double[]`.
    *   `pair<ll, ll> l4` $\rightarrow$ `long[]`.
    *   `vector<ii> vii` $\rightarrow$ `ArrayList<int[]>`.
4.  **Global Variables**: C++ uses global variables (`n`, `m`, arrays `g`, `row`, `col`, etc.). In Java, these should be static fields or local variables within the class. Since the logic depends on them being accessible everywhere, making them `static` fields is the direct translation of the global scope.
5.  **Arrays**:
    *   C++: `char g[410][410]` (2D array).
    *   Java: `char[][] g = new char[410][410]`.
    *   Int arrays in C++ are global; in Java, they are static fields.
6.  **Logic**: The nested loops and conditional logic remain identical, just the syntax changes (e.g., `for (int i = 1; ...)` vs `for (int i = 1; i <= n; i++)`).
7.  **Input Parsing**: The input format is `n m` followed by `n` strings. Java's `Scanner` or `StringTokenizer` handles whitespace skipping automatically.
8.  **Output**: `cout << ans` becomes `System.out.println(ans)`.

The code is a single block, so it can be translated directly without splitting into multiple files, although the logic is repetitive.

<CODE>
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;

public class d_435 {
    static int n, m;
    static char[][] g = new char[410][410];
    static int[][] row = new int[410][410];
    static int[][] col = new int[410][410];
    static int[][] dig1 = new int[810][410];
    static int[][] dig2 = new int[810][410];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            for (int j = 1; j <= m; j++) {
                g[i][j] = line.charAt(j - 1);
            }
        }

        // Precompute prefix sums
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                row[i][j] = row[i][j - 1] + (g[i][j] - '0');
                dig1[i - j + m][i] = dig1[i - j + m][i - 1] + (g[i][j] - '0');
                dig2[i + j][i] = dig2[i + j][i - 1] + (g[i][j] - '0');
                col[j][i] = col[j][i - 1] + (g[i][j] - '0');
            }
        }

        long ans = 0;
        int limit = Math.min(n, m);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == '1') continue;

                // Check 4 corners logic (Top-Left, Top-Right, Bottom-Left, Bottom-Right)
                // Note: The C++ code checks 4 directions. 
                // 1. Top-Left (k goes down-right)
                // 2. Top-Right (k goes down-left)
                // 3. Bottom-Left (k goes up-right)
                // 4. Bottom-Right (k goes up-left)
                // 5. Cross shape (Top-Left + Bottom-Right)
                // 6. Cross shape (Top-Right + Bottom-Left)
                // 7. Cross shape (Top-Left + Bottom-Right) - Wait, C++ has 8 loops.
                // Let's map them carefully.
                
                // Loop 1: Top-Left to Bottom-Right (Main Diagonal)
                for (int k = 1; k < limit; k++) {
                    if (i - k >= 1 && j - k >= 1 && 
                        row[i][j] - row[i][j - k - 1] == 0 && 
                        col[j][i] - col[j][i - k - 1] == 0) {
                        if (dig2[i + j - k][i] - dig2[i + j - k][i - k - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                // Loop 2: Top-Right to Bottom-Left (Anti-Diagonal)
                for (int k = 1; k < limit; k++) {
                    if (i - k >= 1 && j + k <= m && 
                        row[i][j + k] - row[i][j - 1] == 0 && 
                        col[j][i] - col[j][i - k - 1] == 0) {
                        if (dig1[i - j - k + m][i] - dig1[i - j - k + m][i - k - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                // Loop 3: Bottom-Left to Top-Right (Anti-Diagonal)
                for (int k = 1; k < limit; k++) {
                    if (i + k <= n && j - k >= 1 && 
                        row[i][j] - row[i][j - k - 1] == 0 && 
                        col[j][i + k] - col[j][i - 1] == 0) {
                        if (dig1[i - j + k + m][i + k] - dig1[i - j + k + m][i - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                // Loop 4: Bottom-Right to Top-Left (Main Diagonal)
                for (int k = 1; k < limit; k++) {
                    if (i + k <= n && j + k <= m && 
                        row[i][j + k] - row[i][j - 1] == 0 && 
                        col[j][i + k] - col[j][i - 1] == 0) {
                        if (dig2[i + j + k][i + k] - dig2[i + j + k][i - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                // Loop 5: Cross shape (Main Diagonal + Anti Diagonal)
                // C++: i-k, j+k (Top-Left to Bottom-Right) AND i-k, j-k (Top-Right to Bottom-Left)
                // Wait, looking at indices: i-k, j+k is Top-Left to Bottom-Right? No.
                // i-k (up), j+k (right) -> Top-Left to Bottom-Right? No, i decreases, j increases.
                // i-k (up), j+k (right) -> Top-Right to Bottom-Left? No.
                // Let's trace: i-k (row up), j+k (col right). This is Top-Right to Bottom-Left? 
                // No. i decreases -> Row Up. j increases -> Col Right.
                // So (i-k, j+k) is Top-Right. (i+k, j-k) is Bottom-Left.
                // So this loop checks Top-Right to Bottom-Left.
                
                for (int k = 1; k < limit; k++) {
                    if (i - k >= 1 && j + k <= m && j - k >= 1 && 
                        dig1[i - j + m][i] - dig1[i - j + m][i - k - 1] == 0 && 
                        dig2[i + j][i] - dig2[i + j][i - k - 1] == 0) {
                        if (row[i - k][j + k] - row[i - k][j - k - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                // Loop 6: Cross shape (Main Diagonal + Anti Diagonal)
                // C++: i+k, i-k (rows), j+k, j-k (cols)
                // i+k (row down), i-k (row up). j+k (col right), j-k (col left).
                // This checks Top-Left to Bottom-Right and Top-Right to Bottom-Left.
                
                for (int k = 1; k < limit; k++) {
                    if (i + k <= n && i - k >= 1 && j + k <= m && 
                        dig1[i - j + m][i + k] - dig1[i - j + m][i - 1] == 0 && 
                        dig2[i + j][i] - dig2[i + j][i - k - 1] == 0) {
                        if (col[j + k][i + k] - col[j + k][i - k - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                // Loop 7: Cross shape (Main Diagonal + Anti Diagonal)
                // C++: i+k, i-k (rows), j+k, j-k (cols)
                // Same as Loop 6 but checking different row/col diffs.
                
                for (int k = 1; k < limit; k++) {
                    if (i + k <= n && j + k <= m && j - k >= 1 && 
                        dig1[i - j + m][i + k] - dig1[i - j + m][i - 1] == 0 && 
                        dig2[i + j][i + k] - dig2[i + j][i - 1] == 0) {
                        if (row[i + k][j + k] - row[i + k][j - k - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                // Loop 8: Cross shape (Main Diagonal + Anti Diagonal)
                // C++: i-k, i+k (rows), j-k, j+k (cols)
                // Same as Loop 6 but checking different row/col diffs.
                
                for (int k = 1; k < limit; k++) {
                    if (i - k >= 1 && i + k <= n && j - k >= 1 && 
                        dig1[i - j + m][i] - dig1[i - j + m][i - k - 1] == 0 && 
                        dig2[i + j][i + k] - dig2[i + j][i - k - 1] == 0) {
                        if (col[j - k][i + k] - col[j - k][i - k - 1] == 0) {
                            ans++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
</CODE>