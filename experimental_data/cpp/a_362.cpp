#include <bits/stdc++.h>

using namespace std;

int t,add[4][2]={{2,2},{2,-2},{-2,2},{-2,-2}};

char a[9][9];

bool check(int h, int c) {

    if (h>=1 && h<=8 && c>=1 && c<=8) return true;

    return false;

}

void solve() {

    int q[65][3],d=0,c=0,i1,j1;

    bool ok=0,ok1=0;

    for (int i=1;i<=8;i++)

    for (int j=1;j<=8;j++)

    if (a[i][j]=='K') {

        q[++c][0]=i;

        q[c][1]=j;

        q[c][2]=0;

    }

    i1=q[c][0];

    j1=q[c--][1];

    a[i1][j1]='.';

    while (++d<=c) {

        int ic=q[d][0], jc=q[d][1];

        if (ic==i1 && jc==j1 && q[d][2]%2==0) ok=1;

        for (int i=0;i<4;i++) {

            int in=ic+add[i][0],jn=jc+add[i][1];

            if (check(in,jn) && a[in][jn]!='K') {

                    if (a[in][jn]=='.') ok1=1;

                    q[++c][0]=in;

                    q[c][1]=jn;

                    q[c][2]=q[d][2]+1;

                    a[in][jn]='K';

                }

        }

    }

    if (ok && ok1) printf("YES\n");

    else printf("NO\n");

}

int main() {

     //FILE *f=freopen("input.txt","rt",stdin);

     scanf("%d%*c",&t);

     for (int c=0;c<t;c++) {

        for (int i=1;i<=8;i++) {

            for (int j=1;j<=8;j++) scanf("%c",&a[i][j]);

            scanf("%*c");

        }

        scanf("%*c");

        solve();

     }

     return 0;

 }