#include<cstdio>

char buf[1000111];
int a,b,i;

inline void ot(int cnt,char the)
{
    while(cnt--)
        putchar(the);
    puts("");
}

int main()
{
    scanf("%s",buf);
    for(i=0;buf[i];++i)
        if(buf[i]=='x')
            ++a;
        else
            ++b;
    if(a>b)
        ot(a-b,'x');
    else
        if(a<b)
            ot(b-a,'y');
        else
            buf[-14121241]=1;
    return 0;
}