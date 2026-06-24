#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 10;
typedef int64_t LL;

LL a[N], num[N];
int n;

LL gao(LL x){
    LL cnt = 0;
    for(LL i = 2; i*i <= x; i++){
        if( x%i == 0 ){
            while(x%i==0) x/=i,cnt++;
        }
    }
    if(x != 1) cnt++;
    return cnt;
}
vector<int> S[N];
vector<LL> proc[N];

int st[N];
LL ans, sum;
void dfs( int cur ){
    if( cur == n ){
        LL tot = 0, tmp = sum; //printf("tmp = %lld\n", tmp );
        for(int i = 0; i < n; i++){
            if( st[i] == i ) tot++;
            else tmp -= num[i];
        }
//        printf("tot = %d\n", tot );
        if( tot > 1 ) tmp += 1;
        if( ans == -1 ) ans = tmp;
        else  ans = min( ans, tmp );
        return;
    }
    for(int i = 0; i < S[cur].size(); i++){
        int j = S[cur][i];

        LL tmp = a[j];
        for(int k = 0; k < j; k++){
            if( st[k] == j ){
                tmp /= a[k];
            }
        }
        if( tmp%a[cur] == 0 ){
            st[cur] = j;
            dfs( cur+1 );
            st[cur] = cur;
        }
    }
    dfs( cur+1 );
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort( a, a+n );

    LL key = 0;
    for(int i = 0; i < n; i++){
        num[i] = gao( a[i] );
        sum += num[i];
        if( num[i] == 1 ) key++;
//        printf("num[%d] = %lld\n", i, num[i]);
    }
    if( sum  )
    sum += n-key;
//    printf("sum = %lld\n", sum );
    for(int i = 0; i < n; i++)
        S[i].clear(), proc[i].clear();

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if( a[j]%a[i] == 0 )
                S[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++)
        st[i] = i;
    ans = -1;
    dfs(0);
    printf("%lld\n", ans );
    return 0;
}