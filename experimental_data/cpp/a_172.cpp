#include <cstdio>
#include <cstring>

const int MAXLEN=20;
char com_pref[MAXLEN+1], buf[MAXLEN+1];
int main()
{
    int n, i, j;
    scanf("%d%s", &n, com_pref);
    for(i=1; i<n; ++i)
    {
        scanf("%s", buf);
        for(j=0; com_pref[j] && buf[j] && com_pref[j]==buf[j]; ++j);
        com_pref[j]='\0';
    }
    printf("%d\n", strlen(com_pref));
    return 0;
}