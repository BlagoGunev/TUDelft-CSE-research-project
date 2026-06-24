#include <cstring>

#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <ctime>

#include <memory.h>

#include <cassert>



using namespace std;

const int N=101;

const int MAX=10004;

int s[N][N],e[N][N],a[N][N];

int n ,m;

int k[N];

int best[N][N];

int dp[2][MAX];

int main(){

//freopen("in.txt","r",stdin);

//freopen("out.txt","w",stdout);

scanf("%d %d",&n,&m);

for(int i=0;i<n;i++){

    scanf("%d",&k[i]);

    for(int j=1;j<=k[i];j++){

        scanf("%d",&a[i][j]);

    }

}

for(int i=0;i<n;i++){

    s[i][0]=0;

    for(int j=1;j<=k[i];j++){

        s[i][j]=s[i][j-1]+a[i][j];

    }

    e[i][0]=0;

for(int j=1;j<=k[i];j++){

e[i][j]=e[i][j-1]+a[i][(k[i]-j)+1];

}



}

for(int i=0;i<n;i++){

    for(int j=1;j<=k[i];j++){

        for(int w=0;w<=j;w++){

            best[i][j]=max(best[i][j],s[i][w]+e[i][j-w]);

        }

    }

}

int o=0;

for(int i=0;i<n;i++){

    for(int j=0;j<=m;j++){

        dp[o][j]=dp[o^1][j];

    }

for(int j=0;j<=k[i];j++){

    dp[o][j]= max(dp[o][j],best[i][j]);

}

for(int j=1;j<=m;j++){

    if(dp[o^1][j]==0){break;}

    for(int l=1;l<=k[i];l++){

        if(j+l>m){break;}

        dp[o][j+l]=max(dp[o][j+l],dp[o^1][j]+best[i][l]);

    }



}



o^=1;



}

printf("%d\n",dp[o^1][m]);

    return 0;

}