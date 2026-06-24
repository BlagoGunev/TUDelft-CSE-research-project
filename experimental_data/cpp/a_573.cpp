#include<cstdio>
#include<queue>
#include<climits>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<ctype.h>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)


int main()
{
    int i,j,T,n,m,k=0,x=-1;
    scanf("%d",&n);
    for (int cas=0;cas<n;cas++){
        scanf("%d",&m);
        while (m%2==0) m/=2;
        while (m%3==0) m/=3;
        k=m;
        if (k!=x&&x!=-1){
            printf("No\n");
            return 0;
        }
        else{
            x=k;
        }
    }
    printf("Yes\n");
    return 0;
}