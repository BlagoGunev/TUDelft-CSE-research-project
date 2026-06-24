#include <bits/stdc++.h>
using namespace std;
char ch[4][100];
int main ()
{
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<4;i++){
            for(int j=0;j<n;j++){
                ch[i][j]='.';
            }
        }
        if(k%2==0){
            for(int i=1;i<=k/2;i++){
                ch[1][i]=ch[2][i]='#';
            }
        }else{
            if(k<=n-2){
                for(int i=(n-k)/2;i<=(n-k)/2+k-1;i++){
                    ch[1][i]='#';
                }
            }else{
                for(int i=1;i<=n-2;i++){
                    ch[1][i]='#';
                }
                k-=n-2;
                k++;
                for(int i=(n-k)/2;i<=(n-k)/2+k-1;i++){
                    ch[2][i]='#';
                }
                ch[2][n/2]='.';
            }

        }
        printf("YES\n");
        for(int i=0;i<4;i++){
            for(int j=0;j<n;j++){
                printf("%c",ch[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}