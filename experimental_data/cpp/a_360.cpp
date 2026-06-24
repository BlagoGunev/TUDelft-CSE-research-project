#include <cstdio>

#define e109 1000000000

int mv[5555] ;
int val[5555] ;

int minv(int i1, int i2){
    return i1 < i2 ? i1 : i2 ;
}

int cfl[5555], cfr[5555], cfv[5555][5555] ;

int main()
{
    int n, m ;
    scanf("%d%d", &n, &m) ;
    for(int i = 1 ; i <= n ; i++)
        mv[i] = e109 ;
    int p = 0 ;
    while(m--){
        int t ;
        scanf("%d", &t) ;
        if(t == 1){
            int l, r, d ;
            scanf("%d%d%d", &l, &r, &d) ;
            for(int i = l ; i <= r ; i++)
                val[i] += d ;
        }
        else{
            int l, r, v ;
            scanf("%d%d%d", &l, &r, &v) ;
            cfl[p] = l ;
            cfr[p] = r ;
            for(int i = l ; i <= r ; i++){
                mv[i] = minv(mv[i], v-val[i]) ;
                cfv[p][i] = v-val[i] ;
            }
            p++ ;
        }
    }
    bool ans = true ;
    for(int i = 0 ; i != p ; i++){
        bool ok = false ;
        for(int j = cfl[i] ; j <= cfr[i] ; j++){
            if(mv[j] == cfv[i][j]){
                ok = true ;
                break ;
            }
        }
        if(!ok){
            ans = false ;
            break ;
        }
    }
    puts(ans ? "YES" : "NO") ;
    if(ans)
        for(int i = 1 ; i <= n ; i++)
            printf("%d ", mv[i]) ;
    puts("") ;
    return 0 ;
}