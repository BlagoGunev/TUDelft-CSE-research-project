#include<stdio.h>

int main(){
    int a[105];
    int i,n,k,add;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d%d",&n,&k)==2){
        add=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if((a[i]-3*k)>=0) add+=a[i]-3*k;
            else add+=a[i]%k;
        }
        printf("%d\n",add);
    }
    return 0;
}