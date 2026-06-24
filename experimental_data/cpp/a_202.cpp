#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    char a[10];
    scanf("%s",a);
    int l,ma=0;
    l=strlen(a);
    int h[27];
    for(int i=0;i<27;i++)
        h[i]=0;
    for(int i=0;i<l;i++)
    {
        h[a[i]-'a']++;
        if(ma<a[i]-'a')
        {
            ma=a[i]-'a';
        }
    //    printf("%d %d\n",a[i]-'a',ma);
    }
 //   printf("%d %c\n",h[ma],ma+'a');
    for(int i=0;i<h[ma];i++)
        printf("%c",ma+'a');
}