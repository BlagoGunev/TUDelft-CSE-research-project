#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

struct aCell {
    int r;
    int c;
    int v;
    aCell(){}
    aCell (int _r, int _c, int _v) : r(_r), c(_c), v(_v){}
    bool operator < (const aCell &a) const {
        return v < a.v;
    }
};

#define MAX_C 1000005

int R, C, a[MAX_C];
int nC;
int mxR[MAX_C], mxC[MAX_C];
aCell allC[MAX_C];
int lastSeen[MAX_C];
int unseenPii;

int allE[MAX_C][4];


bool seen[MAX_C];
bool maxSeen[MAX_C];

int getR (int c) { return c/C;}
int getC (int c) { return c%C;}
int getInd (int r, int c) { return r*C+c; }

void rec (int r, int c, int v) {
    int myInd = getInd(r,c);
    if (seen[myInd]) return;
    seen[myInd] = true;
    FO (i,0,4) {
        if (allE[myInd][i] != unseenPii) {
            rec (getR(allE[myInd][i]), getC(allE[myInd][i]),v);
        }
    }
    //Colour it: mainly for testing for now:
    a[myInd] = v;
    mxR[r] = v;
    mxC[c] = v;
    return;
}

int recMax (int r, int c) {
    int myInd = getInd(r,c);
    if (maxSeen[myInd]) return -1;
    maxSeen[myInd] = true;
    int rV = max (mxR[r],mxC[c]);
    FO (i,0,4) {
        if (allE[myInd][i] != unseenPii) {
            rV = max(rV,recMax (getR(allE[myInd][i]), getC(allE[myInd][i])));
        }
    }
    return rV;
}

int main() {
    scanf ("%d %d", &R, &C);
    FO (i,0,R) {
        FO (p,0,C) {
            scanf ("%d", &a[getInd(i,p)]);
        }
    }
    FO (i,0,R) {
        FO (p,0,C) {
            allC[nC++] = aCell(i,p,a[getInd(i,p)]);
        }
    }
    sort (allC, allC+nC);
    int compV = 0;
    int prevV = -1;
    FO (i,0,nC) {
        if (i != 0 && allC[i].v != prevV) {
            compV++;
        }
        prevV = allC[i].v;
        allC[i].v = compV;
        a[getInd(allC[i].r,allC[i].c)] = compV;
    }
    /*
    FO (i,0,R) {
        FO (p,0,C) {
            printf ("%d ", a[getInd(i,p)]);
        }
        printf ("\n");
    }
    */
    //Generate graph: first set everything to unseens;
    unseenPii = -1;
    FO (i,0,nC+2) FO(t,0,4) allE[i][t] = unseenPii;
    FO (i,0,nC+2) lastSeen[i] = unseenPii; 
    FO (i,0,R) {
        FO (p,0,C) {
            int myA = a[getInd(i,p)];
            if (lastSeen[myA] != unseenPii) {
                int lR = getR(lastSeen[myA]);
                int lC = getC(lastSeen[myA]);
                if (lR == i) {
                    allE[getInd(lR,lC)][1] = getInd(i,p);
                    allE[getInd(i,p)][3] = getInd(lR,lC);
                }
            }
            lastSeen[myA] = getInd(i,p);
        }
    }
    FO (i,0,nC+2) lastSeen[i] = unseenPii; 
    FO (p,0,C) {
        FO (i,0,R) {
            int myA = a[getInd(i,p)];
            if (lastSeen[myA] != unseenPii) {
                int lR = getR(lastSeen[myA]);
                int lC = getC(lastSeen[myA]);
                if (lC == p) {
                    allE[getInd(lR,lC)][2] = getInd(i,p);
                    allE[getInd(i,p)][0] = getInd(lR,lC);
                }
            }
            lastSeen[myA] = getInd(i,p);
        }
    }
    
    FO (i,0,nC) {
        int mV = recMax(allC[i].r,allC[i].c) + 1;
        rec (allC[i].r,allC[i].c,mV);
    }
    int ans = 0;
    FO (i,0,R) ans = max (ans, mxR[i]);
    FO (i,0,C) ans = max (ans, mxC[i]);
    FO (i,0,R) {
        FO (p,0,C) {
            printf ("%d ", a[getInd(i,p)]);
        }
        printf ("\n");
    }
    return 0;
}