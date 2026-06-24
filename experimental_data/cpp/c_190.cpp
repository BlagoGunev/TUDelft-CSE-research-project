#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

#define MAXN 100010
#define INF 100000000
#define _clr(x,y) memset(x,y,sizeof(x))

int n,m,tot,countV;
char tp[MAXN][5];
char res[MAXN*15];

stack <int> sck;

int main()
{
    int i,j;
    cin>>n;
    while(~scanf("%s",tp[m++]));
    m--;
    if(m==1 && tp[0][0]=='i')
    {
        res[tot++]='i';
        res[tot++]='n';
        res[tot++]='t';
        m=0;
    }
    for(i=0;i<m;i++)
    {
        if(tp[i][0]=='i')
        {
            if(sck.empty()) break;
            else sck.top()++;
            res[tot++]='i';
            res[tot++]='n';
            res[tot++]='t';
            if(sck.top()==1) res[tot++]=',';
            else
            {
                res[tot++]='>';
                sck.pop();
                while(!sck.empty())
                {
                    sck.top()++;
                    if(sck.top()==1)
                    {
                        res[tot++]=',';
                        break;
                    }
                    else
                    {
                        res[tot++]='>';
                        sck.pop();  
                    }
                }
            }
        }
        else
        {
            res[tot++]='p';
            res[tot++]='a';
            res[tot++]='i';
            res[tot++]='r';
            res[tot++]='<';
            sck.push(0);
        }
    }
    res[tot]='\0';
    if(i<m || !sck.empty()) puts("Error occurred");
    else printf("%s\n",res);
    return 0;
}
/*
5
pair pair int pair pair int int int int
*/