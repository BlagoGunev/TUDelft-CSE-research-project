#include<bits/stdc++.h>
using namespace std;

// Problem Statement
/*
    n (<= 100)

    permutation p, q of len n

    op,     
        swap(pi, pj)  - cost = min(|i - j|, |pi - pj|)

    minimum cost to make p to q

    n^3 <= 1e6


    output k <= n^2 operations
    

*/
 
// Small Observatins
/*
    We should be able to show a solution,
        that shows that this operations are optimal 
            for any permutation to any permutation

    cost (p, q) = cost (q, p)


    Just a view,
        a graph (n!) nodes 
        an edge between x, y, where  (i, j) x = y
            minimum (|xi - xj|, |i - j|)
        
        required = min path from p to q = min path from p-1 to q-1

    If we see cycles
        i->pi   j->pj 

    How would we prove this ?
        showing all operations means,
            all the nodes that we show is the optimal for them !!

    Looking at an optimal path 


    Are there any lower bounds ? 
        between p and q
            if p != q , and there is one swap of cost 1. then this is minimum

        if we look at them as points on plane.
            minimum of |pi - q fi| + |i - fi| over all permutations f

            this is a lower bound surely,  (is this strong is still a question)
                as in one operation can be seen as 2 points in space, moving horizonally or vertically (as they chose the best both can be viewed like this !!)
                    so finally if points are getting changed to their new positions
                        they might have moved atleast manhatten distance. 
        

            is this the answer ?
                if u have a f
                    that maps points from p to q 

                    so each points have an x displacement and a y displacement
                        And, net x displacements = 0, net y displacements = 0
                            So, now if there is an arrow
                                that goes from                x1 ------------> x2 
                                                      x4 <----------- x3

                                                      then we can swap (x1, x3) and move closer to our goal with cost <= the desired one

                                                      do such an arrows exist ?
                                                        this nothing but an inversion right ?
                            So, the above f can be split into 
                                fx, and fy 
                                    where  f(a, b) = (fx(a), fy(b))

                                        If there is a cycle, 
                                            take the min in that cycle
                                                x0 ------> f x0
                                                <--------f-1 x0,   if f-1 x0 <= fx0 then done

                                            else 
                                                x0 ------> f x0
                                                <----------------f-1 x0,
                                                now there is a path in the cycle frmo fx0 to f-1 x0,
                                                    and among this path where fx0 < f-1x0,
                                                    means at some point we make a move from < f-1x0 to >= f-1x0
                                                            and this gives us the required pair

            
                We can surely do this for any f

            So this must be the answer 
            
            Answer = |pi - q fi| + |i - fi| 

            And if we do this pairing, can we get f ?
                FUck this is minimum perfect matching, 
                    googled it and there is hungarian algorithm

                And once we have this, f . We will use the same above logic to find operaions and do it in 2 * n ? fuck (as we reduce one cycle in x and 1 in y with each op)


            


*/
 
 
 
/*
    What all can be said about the operation ?
        the operatoin is symmetric for p and p-1

        is there a super operation ? 
            u can do a cycle , with 
*/
 
 
// Claims on algo 
/*  
    
 
*/


#define N 110

int A[N][N];

int u [N], v [N], f [N], way [N];

void solve(){
    int n; cin >> n;
    int p[n + 1], q[n + 1];

    for (int i = 0; i <= n; i++) u[i] = v[i] = f[i] = way[i] = 0;

    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> q[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) A[i][j] = abs(i - j) + abs(p[i] - q[j]);

    for (int i=1; i<=n; ++i) {
        f[0] = i;
        int j0 = 0;
        vector<int> minv (n+1, 1000);
        vector<bool> used (n+1, false);
        do {
            used[j0] = true;
            int i0 = f[j0],  delta = 1000,  j1;
            for (int j=1; j<=n; ++j)
                if (!used[j]) {
                    int cur = A[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=n; ++j)
                if (used[j])
                    u[f[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (f[j0] != 0);
        do {
            int j1 = way[j0];
            f[j0] = f[j1];
            j0 = j1;
        } while (j0);
    }

    vector<int> tmp(n + 1);
    for (int j=1; j<=n; ++j)
        tmp[f[j]] = j;
    
    for (int i = 1; i <= n; i++) f[i] = tmp[i];

    // cout << "f = ";
    // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    // cout << '\n';

    int fx[n + 1], fy[n + 1], fyinv[n + 1], fxinv[n + 1];

    for (int i = 1; i <= n; i++){
        fx[i] = f[i];
        fy[p[i]] = q[f[i]];
    }

    for (int i = 1; i <= n; i++){
        fxinv[fx[i]] = i;
        fyinv[fy[i]] = i;
    }


    vector<pair<int, int>> ops;

    int done[n + 1];
    for (int i = 0; i <= n; i++) done[i] = 0;

    int gx[n + 1], gy[n + 1], gxinv[n + 1], gyinv[n + 1];
    for (int i = 1; i <= n; i++){
        gx[i] = i;
        gy[i] = p[i];
    }

    for (int i = 1; i <= n; i++){
        gxinv[gx[i]] = i;
        gyinv[gy[i]] = i;
    }


    for (int x = 1; x <= n; x++){
        if (fx[x] == x) continue;
        int target = fxinv[x];
        int cur = x;
        while (fx[cur] < target){
            cur = fx[cur];
        }
        ops.push_back({cur, target});
        swap(fx[cur], fx[target]);
        swap(fxinv[fx[cur]], fxinv[fx[target]]);
        swap(gxinv[cur], gxinv[target]);
        swap(gx[gxinv[cur]], gx[gxinv[target]]);
        x--;
    }


    for (int y = 1; y <= n; y++){
        if (fy[y] == y) continue;
        int target = fyinv[y];
        int cur = y;
        while (fy[cur] < target){
            cur = fy[cur];
        }
        ops.push_back({gx[gyinv[cur]], gx[gyinv[target]]});
        swap(fy[cur], fy[target]);
        swap(fyinv[fy[cur]], fyinv[fy[target]]);
        swap(gyinv[cur], gyinv[target]);
        swap(gy[gyinv[cur]], gy[gyinv[target]]);

        y--;
    }


    cout << ops.size() << '\n';
    for (auto f : ops){
        cout << f.first  << ' ' << f.second << '\n';
        swap(p[f.first], p[f.second]);
    }

    for (int i = 1; i <= n; i++) assert(p[i] == q[i]);

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}


// Golden Rules
/*
    Solutions are simple.

    Proofs are simple.

    Implementations are simple.
*/