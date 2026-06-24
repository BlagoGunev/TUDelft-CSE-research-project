#include <bits/stdc++.h>



using namespace std;



const int N = 1<<17;

const int CUT_OFF = 316;



int n,m,q;

long long a[N];

long long sum[N],updates[N],additional[N],ans;

int common[N][CUT_OFF + 7];

int big_count,big[N],big_number[N];

int sz[N];

int *s[N];

vector < int > who[N],who_big[N];



int main() {

    int i,j,x,y,z;

    char type[4];



    scanf("%d %d %d", &n, &m, &q);

    for(i=1;i<=n;i++) scanf("%lld", &a[i]);

    for(i=1;i<=m;i++) {

        scanf("%d", &sz[i]);

        s[i]=(int*)malloc((sizeof(int)*(sz[i]+3)));

        if(sz[i]>CUT_OFF) ++big_count,big_number[i]=big_count,big[big_count]=i;

        for(j=0;j<sz[i];j++) {

            scanf("%d", &x);

            s[i][j]=x;

            who[x].push_back(i);

            if(sz[i]>CUT_OFF) who_big[x].push_back(i);

            sum[i]+=a[x];

        }

    }

    //for(i=1;i<=m;i++) printf("sz [ %d ] = %d, sum [ %d ] = %lld\n", i, sz[i], i, sum[i]);

    for(i=1;i<=n;i++) for(j=0;j<(int)(who[i].size());j++) for(z=0;z<(int)(who_big[i].size());z++) ++common[who[i][j]][big_number[who_big[i][z]]];

    while(q--) {

        scanf("%s", type+1);

        if(type[1]=='?') {

            scanf("%d", &x);

            ans=0;

            if(sz[x]<=CUT_OFF) {

                for(i=0;i<sz[x];i++) ans+=a[s[x][i]];

                for(i=1;i<=big_count;i++) ans+=updates[big[i]]*common[x][i];

            }

            else {

                ans=sum[x]+updates[x]*sz[x]+additional[x];

            }

            printf("%lld\n", ans);

        }

        else {

            scanf("%d %d", &x, &y);

            if(sz[x]<=CUT_OFF) {

                for(i=0;i<sz[x];i++) a[s[x][i]]+=y;

                for(i=1;i<=big_count;i++) additional[big[i]]+=y*1ll*common[x][i];

            }

            else {

                updates[x]+=y;

                for(i=1;i<=big_count;i++) if(big[i]!=x) additional[big[i]]+=y*1ll*common[x][i];

            }

        }

    }



    return 0;

}