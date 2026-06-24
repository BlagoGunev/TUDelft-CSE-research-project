#include<cstdio>
using namespace std;
int main()
{
    char str[500],ans[500];
    int i,j;

    scanf("%s",str);
    for (i=0,j=0;str[i];i++)
    {
        if (str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y'||
            str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='Y')

            continue;

        ans[j++]='.';
        if (str[i]>='A'&&str[i]<='Z')
            ans[j++]=str[i]+32;
        else
            ans[j++]=str[i];

    }

    ans[j]=0;

    printf("%s\n",ans);

    return 0;
}