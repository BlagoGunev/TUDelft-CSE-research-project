#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n;
    int ans;
    scanf("%d",&n);
    int a,b;
    for(a = 1;;a++){
        b = n / a;
        if(b < a){
            break;
        }
        if(a*b == n){
            ans = b;
        }
    }
    printf("%d %d\n",n/ans,ans);

}