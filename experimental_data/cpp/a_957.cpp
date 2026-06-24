#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
char ch[110];
int main()
{
 int n;
 scanf("%d",&n);
 scanf("%s",ch+1);
 bool bk=true;bool bkk=false;
 for(int i=1;i<n;i++)if(ch[i]==ch[i+1] && ch[i]!='?'){bk=false;break;}
 if(bk==false){printf("No\n");return 0;}
 for(int i=1;i<=n;i++)if(ch[i]=='?')bkk=true;
 if(bkk==false){printf("No\n");return 0;}
 for(int i=1;i<n;i++)if(ch[i]==ch[i+1] && ch[i]=='?'){bk=false;break;}
 if(bk==false){printf("Yes\n");return 0;}
 for(int i=1;i<=n;i++)if(ch[i]=='?' && (ch[i-1]==ch[i+1] || i==1 || i==n)){bk=false;break;}
 if(bk==false)printf("Yes\n");
 else printf("No\n");
 return 0;
}