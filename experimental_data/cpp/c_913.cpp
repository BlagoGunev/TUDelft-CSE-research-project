#include<stdio.h>
#include<algorithm>

long long int min( long long int a, long long int b ){
    return a==0?b:((a<b)?a:b);
}

struct bottle {
    long long int cost,volume;
    double rate;
};

bool cmp( bottle a, bottle b ){
    return a.rate > b.rate;
}

int main(){
    long long int n, L;
    bottle arr[31];
    scanf("%lld %lld",&n,&L);
    long long int tmp = 1;
    for( long long int i = 0; i < n; ++i ){
        scanf("%lld",&arr[i].cost);
        arr[i].volume = tmp;
        tmp *= 2;
        arr[i].rate = (double)arr[i].volume/(double)arr[i].cost;
        if( i >= 1 && cmp(arr[i-1],arr[i]) ){
            arr[i].cost = arr[i-1].cost * 2;
            arr[i].rate = (double)arr[i].volume/(double)arr[i].cost;
        }
    }

    int best = 0;
    for( int i = 1; i < n; ++i ){
        if( cmp(arr[i],arr[best]) ){
            best = i;
        }
    }
    long long int result = 0;
    long long int min_cost = (L/arr[best].volume) * arr[best].cost;
    L = L%arr[best].volume;
    if( L == 0 ){
        result = min_cost;
    }

    while( 0 < L && L < tmp ){
        long long int cost = min_cost;
        long long int a = L;
        for( long long int i = 0; i < n; ++i ){
            if( ( a & arr[i].volume ) != 0 ){
                cost += arr[i].cost;
                a -= arr[i].volume;
            }
        }
        result = min( result, cost );
        L += ( L & -L );
    }
    printf("%lld\n",result);
    return 0;
}