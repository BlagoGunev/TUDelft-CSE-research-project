#include<bits/stdc++.h>

using namespace std;

#define mp make_pair

#define fi first

#define se second

#define pii pair<int,int>

map<pii,int> Map;

const int N=200005;

struct Ask{

    int x,y,from;

}A[N];

int n,m,Ans[N],nxt,last,Empty;

set<int> S;

inline void add(int x){

    int cnt=0;

    while (1){

    int k=*S.begin();

    if (last+x+cnt>=k)S.erase(k),cnt++;

    else break;

        }

    last+=cnt+x;

}

inline int cmp(Ask x,Ask y){

 return x.x<y.x||(x.x==y.x&&x.from<y.from);

}

int main(){

    scanf("%d%d",&n,&m);

    for (int i=1;i<=n;i++)

        scanf("%d%d",&A[i].x,&A[i].y),

        A[i].from=0,

        Map[mp(A[i].x,A[i].y)]=1;

    for (int i=1;i<=m;i++)

        scanf("%d%d",&A[i+n].x,&A[i+n].y),

        A[i+n].from=i;

    n+=m;

    sort(A+1,A+n+1,cmp);

    A[0].x=-1;

    S.insert(2e9);

    last=-1;

    for (int i=1;i<=n;i++){

        if (A[i].from==0){

            Empty=0;

            add(A[i].x-A[i-1].x);

            int Min=2e9,j=i;

            while (j<=n&&A[j].x==A[i].x&&A[j].from==0){

                if (A[j].y>=last)S.insert(A[j].y);

                Min=min(Min,A[j].y);

                j++;

                }

        if (Min<=last)last--,Empty=1;

        i=j-1;

        }

    else {

        if (A[i].x!=A[i-1].x)add(A[i].x-A[i-1].x),Empty=0;

        if (Map[mp(A[i].x,A[i].y)] || (!Empty&&A[i].y==last))Ans[A[i].from]=0;

        else Ans[A[i].from]=1;

        }

    }

    for (int i=1;i<=m;i++)

        if (Ans[i]) puts("WIN");

        else puts("LOSE");

}