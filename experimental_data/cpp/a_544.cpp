#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[111];

int num[26];

bool mark[111];

int main(){

    int a,b,c,d,e,f,g,h;

    scanf("%d",&a);

    scanf("%s",s);

    e=strlen(s);

    if(e<a){

        printf("NO\n");

        return 0;

    }

    g=0;

    for(d=0;s[d];d++){

        f=s[d]-'a';

        if(!num[f]&&a){

            g++;

            num[f]++;

            mark[d]=1;

            a--;

        }



    }

    if(a){

        printf("NO\n");

        return 0;

    }

    printf("YES\n");

    printf("%c",s[0]);

    for(d=1;s[d];d++){

        if(mark[d]){

            printf("\n");

        }

        printf("%c",s[d]);

        if(d==e-1&&!mark[d])printf("\n");

    }

    return 0;

}