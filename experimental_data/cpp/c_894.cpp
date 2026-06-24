#include <cstdio>
#include <algorithm>
using namespace std;

int M, S[1005], A[4005], N;

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

int main(){
    int i, g;
    scanf("%d", &M);
    for(i=1; i<=M; i++) scanf("%d", S+i);
    g=S[1];
    for(i=1; i<=M; i++){
        g=gcd(g, S[i]);
    }
    if(g!=S[1]){
        puts("-1");
        return 0;
    }
    for(i=M; i>=1; i--){
        A[++N]=S[i];
        A[++N]=S[1];
    }
    printf("%d\n", N);
    for(i=1; i<=N; i++){
        printf("%d ", A[i]);
    }
    return 0;
}