//

// Created by zhangjiejun on 2022/8/1.

//



#include <cstdio>

#include <cstdint>

#include <cstring>

#include <cinttypes>



/*

 * Count A > B > C. Note they must not be equal because 0 is not a valid triangle edge.

 *

 * Write A, B, C in Binary form:

 *

 * Case 1

 * A    aaaa1aaaaa1aaa

 * B    aaaa1aaaaa0bbb

 * C    aaaa0ccccccccc      if x==0 (which implies y==1), a^b+a^c > b^c ==> abc=100 || abc=011

 *      ||||||||||||||      if x==1 (which implies y==0), a^b+b^c > a^c ==> abc=101 || abc=010

 * A^B            1***      ==> at least one bit, abc need to be uniquely constructed according to a's value,

 * A^C      1=====x***

 * B^C      1=====y***

 *

 * Case 2

 * A    aaaa1aaaaaaaaa

 * B    aaaa0bb1bbbbbb

 * C    aaaa0bb0cccccc      if x==0 (which implies y==1), B^C+A^B > A^C ==> abc=101 || abc=010

 *      ||||||||||||||      if x==1 (which implies y==0), B^C+A^C > A^B ==> abc=110 || abc=011

 * A^B      1==x******      ==> at least one bit, abc is uniquely constructed according to a's value

 * A^C      1==y******

 * B^C         1******

 *

 * Construction process:

 *   // State kInitial

 *   Either Construct A[i] == B[i] == C[i] (2 possibilities)

 *   Or Construct a bit where A[i] == 1 && B[i] == 0 && C[i] == 0 (unique)

 *     // State kLargestAConfirmed

 *     // A > B && A > C guaranteed, any bit could be assigned to B

 *     Either Construct A[i], any B[i] == C[i]

 *     or Construct a bit where A[i], B[i] == 1 && C[i] == 0

 *       // State kAbcOrderConfirmed

 *       // A > B && B > C are guaranteed, any bit could be assigned to C

 *       Either construct any A[i], B[i], C[i] (3 choices for each a[i] value)

 *       Or uniquely construct BC according to A, making triangle inequality hold (see discuss above)

 *         // State kTriangleBitConfirmed

 *         Construct any A[i], B[i], C[i]

 *   Or Construct a bit where A[i] == 1 && B[i] == 1 && C[i] == 0

 *     // State kSmallestCConfirmed

 *     // B > C guaranteed, any bit could be assigned to C

 *     Either construct any A[i] == B[i], any C[i]

 *     or Constuct A[i] == 1, B[i] == 0, C[i]

 *       // State kAbcOrderConfirmed

 *       // A > B && B > C are guaranteed, any bit could be assigned to B

 *        ... the same as State 3

 *

 * State: (i, cond1, state)

 * i -- first i digits

 * cond1 -- either constructed a bit and A < N is guaranteed to hold

 * state -- see discussion above

 */



constexpr int kMaxN = 200005;

constexpr int64_t kMod = 998244353;



enum States {

    kInitial = 0,

    kLargestAConfirmed = 1,

    kSmallestCConfirmed = 2,

    kAbcOrderConfirmed = 3,

    kTriangleConfirmed = 4

};



bool valid[kMaxN][2][5];

int64_t f[kMaxN][2][5];

char n[kMaxN];

size_t n_len;



void BruteForce() {

    int m = 0;

    for (int i = 0; i < n_len; ++i) {

        m <<= 1;

        m |= n[i];

    }



    int ans = 0;

    for (int a = 0; a <= m; ++a) {

        for (int b = a + 1; b <= m; ++b) {

            for (int c = b + 1; c <= m; ++c) {

                int x = a ^ b;

                int y = a ^ c;

                int z = b ^ c;



                if (x + y > z && x + z > y && y + z > x) {

                    ++ans;

                    // printf("Found (%d, %d, %d)\n", a, b, c);

                }

            }

        }

    }



    printf("BruteForce: %d\n", ans * 6);

}



int main() {

#ifdef LOCAL_DEBUG

    freopen("input.txt", "r", stdin);

#endif

    scanf("%s", n);

    n_len = strlen(n);

    for (int i = 0; i < n_len; ++i) {

        n[i] -= '0';

    }



#if LOCAL_DEBUG

    // BruteForce();

#endif



    f[0][0][kInitial] = 1;

    valid[0][0][kInitial] = 1;

    for (int i = 0; i < n_len; ++i) {

        for (int cond = 0; cond < 2; ++cond) {

            for (int state = 0; state < 5; ++state) {

                // if (!valid[i][cond][state]) continue;

                // Enumerate bit a

                for (int a = 0; a < 2; ++a) {

                    if (!cond && a > n[i]) {

                        continue;

                    }

                    int new_cond = cond || a < n[i];

                    if (state == kTriangleConfirmed) {

                        f[i + 1][new_cond][kTriangleConfirmed] += f[i][cond][state] * 4;

                        f[i + 1][new_cond][kTriangleConfirmed] %= kMod;

                        valid[i + 1][new_cond][kTriangleConfirmed] = true;

                    } else if (state == kAbcOrderConfirmed) {

                        // One unique choices goes to TriangleConfirmed state

                        f[i + 1][new_cond][kTriangleConfirmed] += f[i][cond][state];

                        f[i + 1][new_cond][kTriangleConfirmed] %= kMod;

                        valid[i + 1][new_cond][kTriangleConfirmed] = true;

                        // Other 3 choices goes to AbcOrderConfirmed state

                        f[i + 1][new_cond][kAbcOrderConfirmed] += f[i][cond][state] * 3;

                        f[i + 1][new_cond][kAbcOrderConfirmed] %= kMod;

                        valid[i + 1][new_cond][kAbcOrderConfirmed] = true;

                    } else if (state == kLargestAConfirmed) {

                        // Construct (b, c) = (0, 0) or (1, 1)

                        f[i + 1][new_cond][kLargestAConfirmed] += f[i][cond][state] * 2;

                        f[i + 1][new_cond][kLargestAConfirmed] %= kMod;

                        valid[i + 1][new_cond][kLargestAConfirmed] = true;

                        // Construct (b, c) = (1, 0)

                        f[i + 1][new_cond][kAbcOrderConfirmed] += f[i][cond][state];

                        f[i + 1][new_cond][kAbcOrderConfirmed] %= kMod;

                        valid[i + 1][new_cond][kAbcOrderConfirmed] = true;

                    } else if (state == kSmallestCConfirmed) {

                        // Construct b[i] == a[i] && any c[i], 2 combs

                        f[i + 1][new_cond][kSmallestCConfirmed] += f[i][cond][state] * 2;

                        f[i + 1][new_cond][kSmallestCConfirmed] %= kMod;

                        valid[i + 1][new_cond][kAbcOrderConfirmed] = true;

                        // Construct a[i] == 1, b[i] == 0 && any c[i], 2 combs

                        if (a == 1) {

                            f[i + 1][new_cond][kAbcOrderConfirmed] += f[i][cond][state] * 2;

                            f[i + 1][new_cond][kAbcOrderConfirmed] %= kMod;

                            valid[i + 1][new_cond][kAbcOrderConfirmed] = true;

                        }

                    } else if (state == kInitial) {

                        // costruct a=b=c, 1 comb

                        f[i + 1][new_cond][kInitial] += f[i][cond][state];

                        f[i + 1][new_cond][kInitial] %= kMod;

                        valid[i + 1][new_cond][kInitial] = true;

                        // construct (a,b,c) == (1,0,0), 1 comb

                        if (a == 1) {

                            f[i + 1][new_cond][kLargestAConfirmed] += f[i][cond][state];

                            f[i + 1][new_cond][kLargestAConfirmed] %= kMod;

                            valid[i + 1][new_cond][kLargestAConfirmed] = true;

                        }

                        // construct (a,b,c) == (1,1,0), 1 comb

                        if (a == 1) {

                            f[i + 1][new_cond][kSmallestCConfirmed] += f[i][cond][state];

                            f[i + 1][new_cond][kSmallestCConfirmed] %= kMod;

                            valid[i + 1][new_cond][kSmallestCConfirmed] = true;

                        }

                    }

                }

            }

        }

    }



    printf("%" PRId64 "\n", ((f[n_len][1][kTriangleConfirmed] + f[n_len][0][kTriangleConfirmed]) * 6) % kMod);

    return 0;

}