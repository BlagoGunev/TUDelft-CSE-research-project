#include <stdio.h>
#include <string.h>
const int MAXN=100000+2;
char a[MAXN],b[MAXN],c[MAXN];
int judge (int len) {
    int ans=0;
    for (int i=0;i<len;i++) {
        if (a[i]!=b[i])
            ans++;
    }
    return ans;
}
int main ( ) {
    while (scanf("%s",a)!=EOF) {
            scanf("%s",b);
            int len=strlen (a);
            int ans=judge (len);
            if (ans%2) {
                printf("impossible\n");
                continue;
            }
            int k=ans/2;
            for (int i=0;i<len;i++) {
                if (a[i]==b[i])
                    c[i]=a[i];
                else {
                    if (k) {
                    --k;
                    c[i]=b[i];
                    }
                    else
                    c[i]=a[i];
                }
            }
            c[len]='\0';
            printf("%s\n",c);
    }
    return 0;
}