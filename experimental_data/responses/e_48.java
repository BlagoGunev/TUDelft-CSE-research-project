Translate this C++ code to Java code. The main class name should be e_48. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAXN = 201;

typedef pair <int, int> PII;

#define X first 
#define Y second

int H, T, R, n, m, headH[MAXN], tailH[MAXN], headT[MAXN], tailT[MAXN], mark[MAXN][MAXN], dis[MAXN][MAXN];

void bfs()
{
	memset(dis, 0, sizeof(dis));
	vector <PII> Q;
	Q.push_back(PII(H, T));
	mark[H][T] = 1;
	for (int i = 0 ; i < (int)Q.size() ; i++)
	{
		int u = Q[i].X, v = Q[i].Y;
		for (int j = 1 ; j <= min(u, n) ; j++)
		{
			int uu = u - j + headH[j], vv = v + tailH[j];
			if (uu + vv <= R && !mark[uu][vv])
			{
				Q.push_back(PII(uu, vv));
				dis[uu][vv] = dis[u][v] + 1;
				mark[uu][vv] = 1;
			}
		}
		for (int j = 1 ; j <= min(v, m) ; j++)
		{
			int uu = u + headT[j], vv = v - j + tailT[j];
			if (uu + vv <= R && !mark[uu][vv])
			{
				Q.push_back(PII(uu, vv));
				dis[uu][vv] = dis[u][v] + 1;
				mark[uu][vv] = 1;
			}
		}
	}
}

void dfs(int h, int t)
{
	mark[h][t] = 2;
	for (int i = 1 ; i <= min(h, n) ; i++)
	{
		int u = h - i + headH[i], v = t + tailH[i];
		if (u + v <= R)
		{
			if (!mark[u][v])
				dfs(u, v);
			else if (mark[u][v] == 2)
			{
				cout << "Draw" << endl;
				exit(0);
			}
		}
		dis[h][t] = max(dis[h][t], dis[u][v]+1);
	}
	for (int i = 1 ; i <= min(t, m) ; i++)
	{
		int u = h + headT[i], v = t - i + tailT[i];
		if (u + v <= R)
		{
			if (!mark[u][v])
				dfs(u, v);
			else if (mark[u][v] == 2)
			{
				cout << "Draw" << endl;
				exit(0);
			}
		}
		dis[h][t] = max(dis[h][t], dis[u][v]+1);
	}
	mark[h][t] = 1;
}

int main()
{
	cin >> H >> T >> R;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> headH[i] >> tailH[i];
	cin >> m;
	for (int i = 1 ; i <= m ; i++)
		cin >> headT[i] >> tailT[i];
	bfs();
	if (dis[0][0])
	{
		cout << "Ivan" << endl << dis[0][0] << endl;
		return 0;
	}
	memset(mark, 0, sizeof(mark));
	memset(dis, 0, sizeof(dis));
	dfs(H, T);
	cout << "Zmey" << endl << dis[H][T] << endl;
	return 0;
}

Here is the plan for the translation from C++ to Java, followed by the translated code.

### Translation Plan

1.  **Standard Library and IO**:
    *   Replace `#include <iostream>`, `<cstring>`, `<vector>`, `<cstdlib>` with Java standard library classes.
    *   `std::cin` and `std::cout` will be replaced by `java.util.Scanner`.
    *   `memset` (from `<cstring>`) will be replaced by `java.util.Arrays.fill` or `Arrays.copyOf` logic, or manual loops since Java does not have a direct equivalent for `memset` on arrays of objects or specific byte patterns without explicit loops (though here we deal with `int` arrays, so `Arrays.fill` is perfect).
    *   `exit(0)` will be replaced by `System.exit(0)`.

2.  **Data Structures**:
    *   `std::vector<std::pair<int, int>>` is replaced by `java.util.ArrayList` or `java.util.List`.
    *   Since the C++ code uses `pair<int, int>` with `first` and `second` macros, I will create a simple `Point` class or use `int[]` to represent coordinates to keep the logic clean. Given the frequency of usage, a custom class `Point` is cleaner than `int[]` but `int[]` is more performant. However, to strictly follow the C++ logic of `pair`, a `class Point` with `x` and `y` fields is the most readable translation.
    *   2D arrays `mark[MAXN][MAXN]` and `dis[MAXN][MAXN]` will be translated to `int[][]` in Java.

3.  **Macros and Constants**:
    *   `const int MAXN = 201;` becomes a `static final int MAXN = 201;`.
    *   `#define X first` and `#define Y second` become `x` and `y` fields in the `Point` class.

4.  **Logic Translation**:
    *   **`bfs()`**:
        *   Queue implementation: In C++, `std::vector` is used as a queue with `push_back` and iteration. In Java, `java.util.Queue` (specifically `LinkedList` or `ArrayDeque`) is the standard. The C++ code iterates through the vector using an index `i` to access elements. In Java, we can iterate using an `Iterator` or a simple index loop on the `ArrayList`.
        *   `min(u, n)` and `min(v, m)` use `Math.min()`.
        *   `memset` calls become `Arrays.fill()`.
    *   **`dfs()`**:
        *   Recursive function remains recursive.
        *   `cout << "Draw"` becomes `System.out.println("Draw")`.
        *   `exit(0)` becomes `System.exit(0)`.
        *   `max` becomes `Math.max()`.
    *   **`main()`**:
        *   Input parsing using `Scanner`.
        *   Output using `System.out.println`.

5.  **Incremental Tasks**:
    *   Step 1: Define constants and create the `Point` class.
    *   Step 2: Translate `bfs` function (Queue logic, neighbor generation).
    *   Step 3: Translate `dfs` function (Recursive logic).
    *   Step 4: Translate `main` function (Input/Output).
    *   Step 5: Combine and verify.

### Java Code

<CODE>
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

class Point {
    int x;
    int y;
    
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class e_48 {
    static final int MAXN = 201;
    static int H, T, R, n, m;
    static int[] headH = new int[MAXN];
    static int[] tailH = new int[MAXN];
    static int[] headT = new int[MAXN];
    static int[] tailT = new int[MAXN];
    static int[][] mark = new int[MAXN][MAXN];
    static int[][] dis = new int[MAXN][MAXN];

    static void bfs() {
        // C++ memset(dis, 0, sizeof(dis))
        for (int i = 0; i < MAXN; i++) {
            Arrays.fill(dis[i], 0);
        }
        
        // C++ vector<PII> Q; Q.push_back(...)
        ArrayList<Point> Q = new ArrayList<>();
        Q.add(new Point(H, T));
        mark[H][T] = 1;
        
        // C++ for loop over vector
        for (int i = 0; i < Q.size(); i++) {
            Point p = Q.get(i);
            int u = p.x;
            int v = p.y;
            
            // First loop
            for (int j = 1; j <= Math.min(u, n); j++) {
                int uu = u - j + headH[j];
                int vv = v + tailH[j];
                if (uu + vv <= R && mark[uu][vv] != 1) {
                    Q.add(new Point(uu, vv));
                    dis[uu][vv] = dis[u][v] + 1;
                    mark[uu][vv] = 1;
                }
            }
            
            // Second loop
            for (int j = 1; j <= Math.min(v, m); j++) {
                int uu = u + headT[j];
                int vv = v - j + tailT[j];
                if (uu + vv <= R && mark[uu][vv] != 1) {
                    Q.add(new Point(uu, vv));
                    dis[uu][vv] = dis[u][v] + 1;
                    mark[uu][vv] = 1;
                }
            }
        }
    }

    static void dfs(int h, int t) {
        mark[h][t] = 2;
        
        for (int i = 1; i <= Math.min(h, n); i++) {
            int u = h - i + headH[i];
            int v = t + tailH[i];
            if (u + v <= R) {
                if (mark[u][v] != 2) {
                    dfs(u, v);
                } else {
                    System.out.println("Draw");
                    System.exit(0);
                }
            }
            dis[h][t] = Math.max(dis[h][t], dis[u][v] + 1);
        }
        
        for (int i = 1; i <= Math.min(t, m); i++) {
            int u = h + headT[i];
            int v = t - i + tailT[j];
            if (u + v <= R) {
                if (mark[u][v] != 2) {
                    dfs(u, v);
                } else {
                    System.out.println("Draw");
                    System.exit(0);
                }
            }
            dis[h][t] = Math.max(dis[h][t], dis[u][v] + 1);
        }
        mark[h][t] = 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) return;
        H = scanner.nextInt();
        T = scanner.nextInt();
        R = scanner.nextInt();
        n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            headH[i] = scanner.nextInt();
            tailH[i] = scanner.nextInt();
        }
        m = scanner.nextInt();
        for (int i = 1; i <= m; i++) {
            headT[i] = scanner.nextInt();
            tailT[i] = scanner.nextInt();
        }
        
        bfs();
        
        if (dis[0][0] != 0) { // C++ checks if dis[0][0] is true (non-zero)
            System.out.println("Ivan");
            System.out.println(dis[0][0]);
            return;
        }
        
        // Reset arrays
        for (int i = 0; i < MAXN; i++) {
            Arrays.fill(mark[i], 0);
            Arrays.fill(dis[i], 0);
        }
        
        dfs(H, T);
        System.out.println("Zmey");
        System.out.println(dis[H][T]);
    }
}
</CODE>