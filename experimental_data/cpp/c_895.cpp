#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;


const int P = 110;
const int N = 26;
const int V = 100010;
const int MOD = 1000000007;

int primes[P];
bool mprimes[P];
int np;


bool a[N][V];


int main(){
    np = 0;
   
    for(int i = 2; i < P; i++){
        if(mprimes[i])continue;
        primes[np++] = i;
        for(int j = 2*i; j < P; j += i){
            mprimes[j] = true;
        }
    }
    for(int i = 0; i < N; i++){
       // printf("%d\n", primes[i]);
    }
    
    int t = N, m;
    scanf("%d",&m);
    int aux = 0;
    for(int j = 0; j < m; j++){
        int at;
        scanf("%d", &at);
        for(int i = 0; i < t; i++){
            int k = 0;
            while(at % primes[i] == 0){
                at /= primes[i];
                k++;
            }
            a[i][j] = (k%2!=0);
        }
    }
    int r = 0, c = 0;
    bool swap;
    while(r < t && c < m){
        int rr = -1;
        for(int i = r; i < t; i++){
            if(a[i][c]){
                rr = i;
                break;
            }
        }
        if(rr == -1){
            ++c;
        }else{
            for(int j = c; j < m; j++){
                swap = a[r][j];
                a[r][j] = a[rr][j];
                a[rr][j] = swap;
            }
            for(int i = r + 1; i < t; i++){
                if(a[i][c]){
                    a[i][c] = false;
                    for(int j = c + 1; j < m; ++j){
                        if(a[r][j]){
                            a[i][j] = !a[i][j];
                        }
                    }
                }
            }
            ++r;
        }
        
    }
    int val = m-r;
    int ans = 1;
    for(int i = 0; i < val; i++){
        ans = ans * 1ll * 2 % MOD;
    }
    ans  = (ans+MOD-1)%MOD;
    printf("%d\n",ans);
}