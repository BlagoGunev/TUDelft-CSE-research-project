#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 10
int cnt[N];
char str[N<<1], tmp[N<<1];

int main( ){
    int i, j, n, s;
    scanf( "%s", str );
    scanf( "%s", tmp );
    n = atoi( tmp );
    s = strlen( tmp );
    for ( i = 0; tmp[i] != '\0' && tmp[i] == '0'; i++ );
    i--;
    //printf( "%d\n", i );
    if ( s > 1 ){
        if ( i >= 0 ){
            printf( "WRONG_ANSWER\n" );
            return 0;
        } 
    }
    memset( cnt, 0, sizeof(cnt) );
    for ( i = 0; str[i] != '\0'; i++ ) cnt[str[i]-'0']++;
    for ( i = 1; i < N && cnt[i] == 0; i++ );
    if ( i == N ){
        if ( n == 0 ) printf( "OK\n" );
        else printf( "WRONG_ANSWER\n" );
    }
    else {
        int ans = 0;
        for ( i = 1; i < N && cnt[i] == 0; i++ );
        ans = i, cnt[i]--;
        for ( j = 0; j < cnt[0]; j++ ){
            ans = ans*10;
        }
        for ( ; i < N; i++ ){
            for ( j = 0; j < cnt[i]; j++ ) ans = ans*10+i;
        }
        if ( ans != n ) printf( "WRONG_ANSWER\n" );
        else printf( "OK\n" );
    }
}