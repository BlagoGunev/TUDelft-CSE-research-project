#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<int> prime_table(int n){
    vector<int> table;
    table.push_back(2);
    for(int i=3;i<=n;i+=2){
        bool prime=true;
        for(int j=3;j*j<=i;j+=2){
            if(i%j==0){
                prime=false;
                break;
            }
        }
        if(prime)table.push_back(i);
    }
    return table;
}

int max_prime_factor(int x, vector<int> &primes){
    for(int p:primes){
        if(p*p>x)break;
        while(x%p==0)x/=p;
        if(x==1)return p;
    }
    return x;
}

int main() {
    int x2;
    scanf("%d",&x2);
    vector<int> pt=prime_table(int(sqrt(x2+0.5)));
    int mpf_x2=max_prime_factor(x2,pt), min_x1=mpf_x2*(x2/mpf_x2-1)+1;
    
    int ans=x2,min_y=x2;
    for(int x1=min_x1;x1<=x2;x1++){
        int mpf=max_prime_factor(x1,pt);
        if(mpf==x1)continue;
        int y=x1/mpf, x0=mpf*(y-1)+1;
        if(x0<ans)ans=x0;
        if(y==2)break;
    }
    printf("%d\n",ans);
}