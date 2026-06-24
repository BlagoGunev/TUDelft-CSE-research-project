#include "cstdio"

int a[110];

int Map[110][110];

int main(){

    a[3]=1;

    for(int i=4;i<=100;i++){

        int ans=(i-1)*(i-2)/2;

        a[i]=a[i-1]+ans;

    }

    int n; scanf("%d",&n);

    int t=3;

    while (a[t]<n) {

        t++;

    }

    for(int i=1;i<t;i++)

        for(int j=1;j<t;j++)

            if(i!=j)

                Map[i][j]=1;

//    printf("%d",t);

    int ans=n-a[t-1];

    int k=t;

//    printf("%d\n",ans);

    for(int i=t;i<=100&&ans;i++){

        Map[i][1]=Map[1][i]=1;

        Map[i][2]=Map[2][i]=1;

        ans-=1;

        for(int j=3;j<=i&&ans;j++){

            int k=ans-j+1;

            if(k<0) break;

            ans=k;

            Map[i][j]=Map[j][i]=1;

        }

        if(ans==0){

            k=i;

            break;

        }

    }

    printf("%d\n",k);

    for(int i=1;i<=k;i++){

        for (int j=1; j<=k; j++)

            printf("%d",Map[i][j]);

        puts("");

    }

    

    return 0;

}