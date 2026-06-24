Translate this C++ code to Java code. The main class name should be c_896. First, make a plan for the translation by considering what are C++ specific features and how they could be translated. Also consider whether the work could be split up in small incremental tasks. Then, output the code of the resulting program with token "<CODE>" at the beginning and at the end.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int seed;

int rnd() {
  int ret = seed;
  seed = (1ll * seed * 7 + 13) % 1000000007;
  return ret;
}

#define MAXN 100010

long long A[MAXN];
int S[MAXN];
int T[MAXN];

int mexp(int x, int e, int m) {
  if (e == 0) return 1;
  int r = 1;
  for (int i = 31 - __builtin_clz(e); i >= 0; i--) {
    r = (1ll * r * r) % m;
    if (e & 1 << i) {
      r = (1ll * r * x) % m;
    }
  }
  return r;
}

int main() {
  int N, M, vmax;
  cin >> N >> M >> seed >> vmax;

  int asz = N;
  for (int i = 0; i < N; i++) {
    S[i] = i;
    T[i] = i + 1;
    A[i] = (rnd() % vmax) + 1;
  }

  for (int i = 0; i < M; i++) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % N) + 1;
    int r = (rnd() % N) + 1;
    if (l > r) {
      swap(l, r);
    }
    l--;

    int x;
    if (op == 3) {
      x = (rnd() % (r - l));
    } else {
      x = (rnd() % vmax) + 1;
    }

    int y = 0;
    if (op == 4) {
      y = (rnd() % vmax) + 1;
    }
    

    if (op == 1) {
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        if (ql != S[i]) {
          S[asz] = ql;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = ql;
          asz++;
          i--;
          continue;
        }
        if (qr != T[i]) {
          S[asz] = qr;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = qr;
          asz++;
          i--;
          continue;
        }
        A[i] += x;
      }
    } else if (op == 2) {
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        if (ql != S[i]) {
          S[asz] = ql;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = ql;
          asz++;
          i--;
          continue;
        }
        if (qr != T[i]) {
          S[asz] = qr;
          T[asz] = T[i];
          A[asz] = A[i];
          T[i] = qr;
          asz++;
          i--;
          continue;
        }
        if (l != S[i]) {
          S[i] = S[asz - 1];
          T[i] = T[asz - 1];
          A[i] = A[asz - 1];
          asz--;
          i--;
          continue;
        }
        A[i] = x;
        T[i] = r;
      }
    } else if (op == 3) {
      vector<pair<long long, int> > res;
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        res.push_back(make_pair(A[i], qr - ql));
      }
      sort(res.begin(), res.end());

      for (auto p : res) {
        if (x < p.second) {
          cout << p.first << '\n';
          break;
        } 
        x -= p.second;
      }
    } else if (op == 4) {
      int res = 0;
      for (int i = 0; i < asz; i++) {
        int ql = max(S[i], l);
        int qr = min(T[i], r);
        if (qr <= ql) {
          continue;
        }
        res = (res + 1ll * (qr - ql) * mexp(A[i] % y, x, y)) % y;
      }
      cout << res << '\n';
    }

//cout << ":: " << asz << endl;
    //cout << op << " " << l << " " << r << endl;
  }

  return 0;
}

Here is the plan for the translation:

1.  **Header and Namespace**: Replace C++ headers (`<iostream>`, `<vector>`, `<algorithm>`) with Java imports (`java.util.Scanner`, `java.util.ArrayList`, `java.util.Collections`). Since `using namespace std;` is common in C++ competitive programming, I will map `cin`, `cout`, `endl`, `swap`, `max`, `min`, `vector`, and `sort` to their Java equivalents.
2.  **Global Variables**: The C++ code uses global variables (`seed`, `A`, `S`, `T`, `MAXN`). In Java, these should be instance variables of the main class `c_896`. `MAXN` can be a `static final` constant.
3.  **Random Number Generation**: The C++ `rnd()` function uses `long long` arithmetic and `__builtin_clz` (compiler intrinsic for bit counting).
    *   `__builtin_clz(e)` is not available in Java. We need a replacement. Since `e` is up to 31 (implied by the loop `31 - ...`), we can implement a simple bit count or use `Integer.numberOfLeadingZeros`.
    *   The modulo arithmetic needs to handle `long` in Java (equivalent to C++ `long long` for 64-bit integers).
4.  **Main Logic**:
    *   Replace `cin >>` with `Scanner` logic.
    *   Replace `vector` with `ArrayList`.
    *   Replace `pair` with a custom class or `int[]` (since Java doesn't have a built-in `std::pair` for primitive types, `long[]` is convenient).
    *   Replace `cout` with `System.out.println`.
    *   Replace `swap` with manual swapping.
5.  **Incremental Tasks**:
    *   Step 1: Setup class structure and global arrays.
    *   Step 2: Implement the `rnd()` function with Java-compatible bit manipulation.
    *   Step 3: Implement `mexp` (modular exponentiation) converting the C++ loop to Java.
    *   Step 4: Implement `main` method logic, handling the specific operations (1, 2, 3, 4) and array manipulations.
    *   Step 5: Final assembly and formatting.

```java
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class c_896 {
    static final int MAXN = 100010;
    
    static long seed;
    
    // Using ArrayList for dynamic sizing, though C++ code uses fixed array with 'asz' index.
    // To keep it efficient and close to the original logic, we use arrays but manage size manually.
    static long[] A = new long[MAXN];
    static int[] S = new int[MAXN];
    static int[] T = new int[MAXN];
    
    static int asz;

    static int rnd() {
        long ret = seed;
        seed = (1L * seed * 7 + 13) % 1000000007;
        return (int) ret;
    }

    static int mexp(int x, int e, int m) {
        if (e == 0) return 1;
        int r = 1;
        // __builtin_clz returns the number of zero bits preceding the highest-order one-bit.
        // For 32-bit int, 31 - __builtin_clz(e) gives the index of the most significant bit.
        // We need to replicate this logic. Integer.numberOfLeadingZeros works for 32-bit ints.
        // If e is 0, this would be 32, but the loop condition i >= 0 handles it (though e=0 is caught above).
        int msbIndex = 31 - Integer.numberOfLeadingZeros(e);
        
        for (int i = msbIndex; i >= 0; i--) {
            r = (1L * r * r) % m;
            if ((e & (1 << i)) != 0) {
                r = (1L * r * x) % m;
            }
        }
        return r;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int N = sc.nextInt();
        int M = sc.nextInt();
        seed = sc.nextLong();
        int vmax = sc.nextInt();

        asz = N;
        for (int i = 0; i < N; i++) {
            S[i] = i;
            T[i] = i + 1;
            A[i] = (rnd() % vmax) + 1;
        }

        for (int i = 0; i < M; i++) {
            int op = (rnd() % 4) + 1;
            int l = (rnd() % N) + 1;
            int r = (rnd() % N) + 1;
            if (l > r) {
                int temp = l;
                l = r;
                r = temp;
            }
            l--;

            int x;
            if (op == 3) {
                x = (rnd() % (r - l));
            } else {
                x = (rnd() % vmax) + 1;
            }

            int y = 0;
            if (op == 4) {
                y = (rnd() % vmax) + 1;
            }

            if (op == 1) {
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    if (ql != S[i]) {
                        S[asz] = ql;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = ql;
                        asz++;
                        i--;
                        continue;
                    }
                    if (qr != T[i]) {
                        S[asz] = qr;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = qr;
                        asz++;
                        i--;
                        continue;
                    }
                    A[i] += x;
                }
            } else if (op == 2) {
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    if (ql != S[i]) {
                        S[asz] = ql;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = ql;
                        asz++;
                        i--;
                        continue;
                    }
                    if (qr != T[i]) {
                        S[asz] = qr;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = qr;
                        asz++;
                        i--;
                        continue;
                    }
                    if (l != S[i]) {
                        S[i] = S[asz - 1];
                        T[i] = T[asz - 1];
                        A[i] = A[asz - 1];
                        asz--;
                        i--;
                        continue;
                    }
                    A[i] = x;
                    T[i] = r;
                }
            } else if (op == 3) {
                // Using ArrayList to store pairs. 
                // Storing as long[] {value, length}
                ArrayList<long[]> res = new ArrayList<>();
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    res.add(new long[]{A[i], (long)(qr - ql)});
                }
                // Sort by value (first element of pair)
                Collections.sort(res, new Comparator<long[]>() {
                    @Override
                    public int compare(long[] o1, long[] o2) {
                        return Long.compare(o1[0], o2[0]);
                    }
                });

                for (long[] p : res) {
                    if (x < p[1]) {
                        System.out.println(p[0]);
                        break;
                    } 
                    x -= p[1];
                }
            } else if (op == 4) {
                long res = 0;
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    res = (res + (long)(qr - ql) * mexp((int)(A[i] % y), x, y)) % y;
                }
                System.out.println(res);
            }
        }
    }
}
```
<CODE>
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class c_896 {
    static final int MAXN = 100010;
    
    static long seed;
    
    // Using ArrayList for dynamic sizing, though C++ code uses fixed array with 'asz' index.
    // To keep it efficient and close to the original logic, we use arrays but manage size manually.
    static long[] A = new long[MAXN];
    static int[] S = new int[MAXN];
    static int[] T = new int[MAXN];
    
    static int asz;

    static int rnd() {
        long ret = seed;
        seed = (1L * seed * 7 + 13) % 1000000007;
        return (int) ret;
    }

    static int mexp(int x, int e, int m) {
        if (e == 0) return 1;
        int r = 1;
        // __builtin_clz returns the number of zero bits preceding the highest-order one-bit.
        // For 32-bit int, 31 - __builtin_clz(e) gives the index of the most significant bit.
        // We need to replicate this logic. Integer.numberOfLeadingZeros works for 32-bit ints.
        // If e is 0, this would be 32, but the loop condition i >= 0 handles it (though e=0 is caught above).
        int msbIndex = 31 - Integer.numberOfLeadingZeros(e);
        
        for (int i = msbIndex; i >= 0; i--) {
            r = (1L * r * r) % m;
            if ((e & (1 << i)) != 0) {
                r = (1L * r * x) % m;
            }
        }
        return r;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int N = sc.nextInt();
        int M = sc.nextInt();
        seed = sc.nextLong();
        int vmax = sc.nextInt();

        asz = N;
        for (int i = 0; i < N; i++) {
            S[i] = i;
            T[i] = i + 1;
            A[i] = (rnd() % vmax) + 1;
        }

        for (int i = 0; i < M; i++) {
            int op = (rnd() % 4) + 1;
            int l = (rnd() % N) + 1;
            int r = (rnd() % N) + 1;
            if (l > r) {
                int temp = l;
                l = r;
                r = temp;
            }
            l--;

            int x;
            if (op == 3) {
                x = (rnd() % (r - l));
            } else {
                x = (rnd() % vmax) + 1;
            }

            int y = 0;
            if (op == 4) {
                y = (rnd() % vmax) + 1;
            }

            if (op == 1) {
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    if (ql != S[i]) {
                        S[asz] = ql;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = ql;
                        asz++;
                        i--;
                        continue;
                    }
                    if (qr != T[i]) {
                        S[asz] = qr;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = qr;
                        asz++;
                        i--;
                        continue;
                    }
                    A[i] += x;
                }
            } else if (op == 2) {
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    if (ql != S[i]) {
                        S[asz] = ql;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = ql;
                        asz++;
                        i--;
                        continue;
                    }
                    if (qr != T[i]) {
                        S[asz] = qr;
                        T[asz] = T[i];
                        A[asz] = A[i];
                        T[i] = qr;
                        asz++;
                        i--;
                        continue;
                    }
                    if (l != S[i]) {
                        S[i] = S[asz - 1];
                        T[i] = T[asz - 1];
                        A[i] = A[asz - 1];
                        asz--;
                        i--;
                        continue;
                    }
                    A[i] = x;
                    T[i] = r;
                }
            } else if (op == 3) {
                // Using ArrayList to store pairs. 
                // Storing as long[] {value, length}
                ArrayList<long[]> res = new ArrayList<>();
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    res.add(new long[]{A[i], (long)(qr - ql)});
                }
                // Sort by value (first element of pair)
                Collections.sort(res, new Comparator<long[]>() {
                    @Override
                    public int compare(long[] o1, long[] o2) {
                        return Long.compare(o1[0], o2[0]);
                    }
                });

                for (long[] p : res) {
                    if (x < p[1]) {
                        System.out.println(p[0]);
                        break;
                    } 
                    x -= p[1];
                }
            } else if (op == 4) {
                long res = 0;
                for (int i = 0; i < asz; i++) {
                    int ql = Math.max(S[i], l);
                    int qr = Math.min(T[i], r);
                    if (qr <= ql) {
                        continue;
                    }
                    res = (res + (long)(qr - ql) * mexp((int)(A[i] % y), x, y)) % y;
                }
                System.out.println(res);
            }
        }
    }
}
</CODE>