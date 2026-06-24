#include <cstdio>
#include <cstring>

char s[200001],p[200001];
int maxp[200000],minp[200000];
int main()
{
    scanf("%s %s",s,p);
    int lens=strlen(s),lenp=strlen(p),at=0,tmp[26];
    for (int i=0;i<26;i++)
        tmp[i]=-1;
    for (int i=0;i<lens;i++){
        if (at<lenp&&p[at]==s[i]){
            tmp[p[at]-'a']=at;
            at++;
        }
        maxp[i]=tmp[s[i]-'a'];
    }
    for (int i=0;i<26;i++)
        tmp[i]=-1;
    at=lenp-1;
    for (int i=lens-1;i>=0;i--){
        if (at>=0&&p[at]==s[i]){
            tmp[p[at]-'a']=at;
            at--;
        }
        minp[i]=tmp[s[i]-'a'];
    }
    bool ok=true;
    for (int i=0;i<lens;i++)
        if (maxp[i]==-1||minp[i]==-1||maxp[i]<minp[i]){
            ok=false;
            break;
        }
    puts((ok)?"Yes":"No");
}