#include<cstdio>
using namespace std;
const int maxn=2e5+10;
char s[maxn];
int main(){
    int n;
    while(~scanf("%d",&n)){
        scanf("%s",s);
        int i,flag=0;
        for(i=0;i<n-1;i++)
            if(s[i]>s[i+1]){
                flag=1;
                break;
            }
        if(flag){
            for(int j=0;j<n;j++)
                if(j!=i) printf("%c",s[j]);
        }
        else for(int j=0;j<n-1;j++) printf("%c",s[j]);
        printf("\n");
        

    }


}