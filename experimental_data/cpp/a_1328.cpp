#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a%b) printf("%d\n",b-(a%b));
        else printf("0\n");
    }
    return 0;
};