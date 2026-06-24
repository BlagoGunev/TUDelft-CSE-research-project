#include<bits/stdc++.h>
#define up(l, r, i) for(int i = l, END##i = r;i <= END##i;++ i)
#define dn(r, l, i) for(int i = r, END##i = l;i >= END##i;-- i)
using namespace std;
typedef long long i64;
const int INF = 2147483647;

int qread(){
    int w = 1, c, ret;
    while((c = getchar()) >  '9' || c <  '0') w = (c == '-' ? -1 : 1); ret = c - '0';
    while((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + c - '0';
    return ret * w;
}

const int MAXN = 15 + 3;
const int MAXM = (1 << 16) + 3;

int A[MAXN][MAXN];
int F[MAXM][MAXN][MAXN], G[MAXM][MAXN][MAXN];
int X[MAXN][MAXN], Y[MAXN][MAXN];
int P[MAXN], Q[MAXN];

int main(){

    up(1, qread(), _){
        int n = qread(), m = qread();
        up(1, n, i){
            up(1, m, j)
                A[i][j] = qread();
        }
        up(1, n, i){
            A[i][m + 1] = 0;
            up(1, m, j)
                A[i][m + 1] ^= A[i][j];
        }
        ++ m;
        up(1, m, i){
            A[n + 1][i] = 0;
            up(1, n, j)
                A[n + 1][i] ^= A[j][i];
        }
        ++ n;

        up(1, n, i){
            P[i] = 0;
            up(1, m - 1, j) P[i] += abs(A[i][j] - A[i][j + 1]);
        }
        up(1, m, i){
            Q[i] = 0;
            up(1, n - 1, j) Q[i] += abs(A[j][i] - A[j + 1][i]);
        }
        up(1, n, i){
            up(1, n, j) if(i != j){
                X[i][j] = 0;
                up(1, m, k){
                    X[i][j] += abs(A[i][k] - A[j][k]);
                }
            }
        }
        up(1, m, i){
            up(1, m, j) if(i != j){
                Y[i][j] = 0;
                up(1, n, k){
                    Y[i][j] += abs(A[k][i] - A[k][j]);
                }
            }
        }
        
        int t;
        
        t = (1 << n) - 1;
        up(1, m, u){
            up(0, t, i){
                up(0, n - 1, j) if(i & (1 << j)){
                    if(i == (1 << j))
                        F[i][j][u] = 0;
                    else {
                        F[i][j][u] = 1e9;
                        up(0, n - 1, k) if((i & (1 << k)) && j != k){
                            F[i][j][u] = min(F[i][j][u], F[i ^ (1 << j)][k][u] + X[j + 1][k + 1] - abs(A[j + 1][u] - A[k + 1][u]));
                        }
                    }
                }
            }
        }
        t = (1 << m) - 1;
        up(1, n, u){
            up(0, t, i){
                up(0, m - 1, j) if(i & (1 << j)){
                    if(i == (1 << j))
                        G[i][j][u] = 0;
                    else {
                        G[i][j][u] = 1e9;
                        up(0, m - 1, k) if((i & (1 << k)) && j != k){
                            G[i][j][u] = min(G[i][j][u], G[i ^ (1 << j)][k][u] + Y[j + 1][k + 1] - abs(A[u][j + 1] - A[u][k + 1]));
                        }
                    }
                }
            }
        }

        int ans = 1e9;
        up(1, n, a){
            up(1, n, x) if(a != x){
                up(1, m, b){
                    up(1, m, y) if(b != y){
                        int w1 = F[((1 << n) - 1) ^ (1 << a - 1)][x - 1][b];
                        int w2 = G[((1 << m) - 1) ^ (1 << b - 1)][y - 1][a];
                        ans = min(ans, w1 + w2);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
/*
1
1 2
1 3

2, 1, 3, 2: 0, 4: 0, 4 
*/