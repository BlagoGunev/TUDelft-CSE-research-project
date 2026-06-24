#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long int n,c=0;
    char a[3],s;
    scanf("%ld",&n);
    n--;
    scanf("%s",a);
    s=a[0];
    c++;
    while(n--)
    {
              scanf("%s",a);
              if(s!=a[0])
              {
                         s=a[0];
                         c++;
              }
    }
    printf("%ld\n",c);
    return 0;
}