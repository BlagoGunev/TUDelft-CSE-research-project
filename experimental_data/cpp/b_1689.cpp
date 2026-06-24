#include <bits/stdc++.h>



using namespace std;



int t,n,A[1010],B[1010];



int main()

{

    scanf("%d",&t);

    while(t--)

    {

        scanf("%d",&n);

        for(int i=1; i<=n; i++)

        {

            scanf("%d",&A[i]);

            B[i] = i;

        }

        if(n==1)

        {

            printf("-1\n");

            continue;

        }

        for(int i=1; i<n; i++)

        {

            if(A[i]==B[i]) swap(B[i],B[i+1]);

        }

        if(A[n]==B[n]) swap(B[n-1],B[n]);

        for(int i=1; i<=n; i++) printf("%d ",B[i]);

        printf("\n");

    }

    return 0;

}