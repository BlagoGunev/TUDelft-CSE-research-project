#include<bits/stdc++.h>
using namespace std;
int Testcase, n, i, j, k, a, b, m, c, B[3010][3010], N=3000, X[3010];
double A[3010][3010], C[3010][3010];
main()
{
    for(j=1;j<=N;j++)
    {
        A[1][j]=1;
        B[1][j]=j;
        C[1][j]=1;
    }
    for(i=2;i<=N;i++)
    {
        for(j=i;j<=N;j++)
        {
            C[i][j]=1e9;
            for(k=1;k<=j-i+1;k++)
            {
                double x=A[i-1][j-k];
                int y=B[i-1][j-k];
                double r=(double)y*(1+x)/k+1;
                if(C[i][j]>r+C[i-1][j-k])
                {
                    C[i][j]=r+C[i-1][j-k];
                    B[i][j]=k;
                    A[i][j]=r;
                }
                else if(i>=100) break;
            }
        }
    }
    cin>>n>>m;
    printf("%.10f", C[n][m]);
}