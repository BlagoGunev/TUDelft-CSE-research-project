#include <stdio.h>

#include <string.h>
int main ()
{


long long int n,y,z;
int i,j,k,d=0;
//char x[1000];
//scanf("%s",&x);
//k=strlen(x);
//d=0;
//for (i=0;i<k;i++)
//{
    //d=d*10;
    //d=((d+x[i])-48)%4;
    //printf("%d\n",d);
    scanf("%lld",&n);
    d=n%4;

if (n==0)
{
    printf("1");
}
else if (d==1)
{
    printf("8");
}
else if (d==2)
{
    printf("4");
}
else if (d==3)
{
    printf("2");
}
else if (d==4)
{
    printf("6");
}
else if (d==0)
{
    printf("6");
}

return 0;
}