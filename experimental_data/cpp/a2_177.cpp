#include <bits/stdc++.h>
using namespace std ;
const int N = 110 ;
int A[110][110] ;
int main() {
    int n ;
    scanf("%d", &n) ;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &A[i][j]) ;
    int sum = 0 ;
    for(int i = 1; i <= n; i++) {
        if(A[i][i] != -1 ) sum += A[i][i] ; A[i][i] = -1 ;
    }
    for(int i = n , j = 1; i >= 1 && j <= n; i-- , j++) {
            if(A[j][i] != -1) {
                sum += A[j][i] ; A[j][i] = -1 ;
            }
    }
    for(int i = (n+1)/2 , j = 1; j <= n; j++) {
        if(A[i][j] != -1) {
            sum += A[i][j] ; A[i][j] = -1;
        } 
    }
    for(int j = (n+1)/2 , i = 1; i <= n; i++) {
        if(A[i][j] != -1) {
            sum += A[i][j] ; A[i][j] = -1;
        }
    }
    printf("%d\n", sum) ;
    return 0;
}