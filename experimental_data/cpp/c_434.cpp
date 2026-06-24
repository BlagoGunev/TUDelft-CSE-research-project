#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007
#define UPD(a,b) { a = (a + (b)) % MD; }

struct ACnode {
       int fail, val; int ch[22];
       ACnode(){}
       void Init(){
            Fill(ch,0); val = 0;
       }
}A[MaxN];

int ACnow = 0;
struct AC_Automaton{
       int root;
       void clr(){A[root = ++ACnow].Init();}
       void ins(int t,int *a,int Val){
            if(a[1]==11126){
                A[t].val += Val;
                return ;
            }
            int s = a[1];
            if(A[t].ch[s] == 0)
                A[t].ch[s]= ++ACnow;
            int tt = A[t].ch[s];
            ins(tt,a+1,Val);
       }
       int q[MaxN];
       void GetFail(){
            int hd(0),tl(1);A[root].fail = root;q[1] = root;
            while(hd < tl){
                int vex = q[++hd];
                A[vex].val += A[A[vex].fail].val;
                For(x,0,20) if (A[vex].ch[x]) {
                    int tSon = A[vex].ch[x],t;
                    int tAlp = x;
                    q[++tl] = tSon;
                    for(t = A[vex].fail;(t != root)&&(A[t].ch[x]==0);t = A[t].fail);
                    if(A[t].ch[x] && vex != root)t = A[t].ch[x];
                    A[tSon].fail = t;
                } else {
                    int t;
                    for (t = A[vex].fail; t != root; t = A[t].fail) if (A[t].ch[x]) break ;
                    if (A[t].ch[x]) t = A[t].ch[x];
                    A[vex].ch[x] = t;
                }
            }
       }
}AC;

void getInt(int *A) {
    int len = 0;
    For(i,1,200) A[i] = 0;
    scanf("%d",&len);
    For(i,200 - len + 1,200) scanf("%d",&A[i]);
}

int Range[222];
int f[222][555][222];
bool calc[222][555][222];
int n,BASE,k;
int dp(int n, int curval, int curnode, bool w, bool Started) {
    if (n == 0) {
        return curval >= 0 && Started;
    }
    if (curval < 0) return 0;
    int c = Range[200 - n + 1];
    if (!Started) {
        int ans = 0;
        UPD(ans,dp(n - 1,curval, curnode, w && (c == 0), false));
        For(j,1,((w) ? (c) : (BASE - 1))) {
            int nextNode = A[curnode].ch[j];
            UPD(ans,dp(n - 1,curval - A[nextNode].val, nextNode, w && (j == c), true));
        }
        return ans;
    }
    if (w) {
        int ans = 0;
        For(j,0,c) {
            int nextNode = A[curnode].ch[j];
            UPD(ans,dp(n - 1,curval - A[nextNode].val, nextNode, w && (j == c), true));
        }
        return ans;
    }
    if (calc[n][curval][curnode]) return f[n][curval][curnode];
    calc[n][curval][curnode] = true;
    int ans = 0;
    For(j,0,BASE - 1) {
        int nextNode = A[curnode].ch[j];
        UPD(ans,dp(n - 1,curval - A[nextNode].val, nextNode, false, true));
    }
    return f[n][curval][curnode] = ans;
}

int solve(int *R) {
    For(i,1,200) Range[i] = R[i];
    return dp(200,k,AC.root,1,0);
}

int ask(int *L, int *R) {
    int ansr = solve(R);
    --L[200];
    int c = 200;
    while (L[c] < 0) {
        --L[c - 1];
        L[c] += BASE;
        --c;
    }
    int ansl = solve(L);
    return (ansr + MD - ansl) % MD;
}

int L[222],R[222],tmp[222];
int main() {
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    cin >> n >> BASE >> k;
    getInt(L);
    getInt(R);
    AC.clr();
    For(i,1,n) {
        int tl = 0;
        scanf("%d",&tl);
        For(j,1,tl) scanf("%d",&tmp[j]);
        tmp[tl + 1] = 11126;
        int tval = 0;
        scanf("%d",&tval);
        AC.ins(1,tmp,tval);
    }
    AC.GetFail();
    Fill(calc,0);
    int ans = ask(L,R);
    cout << ans << endl;
    return 0;
}