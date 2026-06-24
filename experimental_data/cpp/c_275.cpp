#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std ;
#define N 101000
int a[N] = {0};
bool vis[N] = {0} ;
int main(){
    int n ;
    int k ;
    scanf("%d %d", &n, &k) ;
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]) ;
    sort(a, a+n) ;
    int l = 1 ;
    for(int i=1; i<n; i++)
        if(a[i] != a[i-1])
            a[l++] = a[i] ;
    n = l ;
    if(k == 1)  {
        cout << n << endl ;
        return 0 ;
    }
    int h = 0 ;
    for(int i=0; i<n; i++){
        if(vis[i])  continue ;
        while((long long)a[i] * k > a[h] && h < n)   h++ ;
        if((long long)a[i] * k == a[h]) vis[h] = 1 ;
    }
    int ans = 0 ;
    for(int i=0; i<n; i++)
        if(!vis[i])
            ans++ ;
    cout << ans << endl ;
    return 0 ;
}