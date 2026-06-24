#include <cstdio>
using namespace std;
long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}
long long get(long long a, long long b){
    // if(a % b == 0){
    //     return a / b - 1;
    // }
    // return a / b;
    return (a - 1) / b;
}
int main(){
    // printf("%lld %lld\n", get(1,3), get(3, 3));
    long long n, m, q;
    scanf("%lld%lld%lld", &n, &m, &q);
    long long t = gcd(n, m);
    long long a = n / t, b = m / t;
    while(q --){
        long long sx, sy, ex, ey;
        scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
        int flag = 0;
        if(sx == ex){
            if(sx == 1){
                if(get(sy, a) != get(ey, a)){
                    flag = 0;
                }
                else{
                    flag = 1;
                }
            }
            else if(sx == 2){
                if(get(sy, b) != get(ey, b)){
                    flag = 0;
                }
                else{
                    flag = 1;
                }
            }
        }
        else{
            if(sx == 1 && ex == 2){
                // printf("xss %lld %lld\n", get(sy, a), get(ey, b));
                if(get(sy, a) != get(ey, b)){
                    flag = 0;
                }
                else{
                    flag = 1;
                }
            }
            else if(sx == 2 && ex == 1){
                if(get(sy, b) != get(ey, a)){
                    flag = 0;
                }
                else{
                    flag = 1;
                }
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}