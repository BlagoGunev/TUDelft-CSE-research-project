#include<bits/stdc++.h>
using namespace std;
int N,Ans[200010],Queue[200010];
bool Flag[200010],Visit[200010];
inline int Read()
{
    register int Return=0,Flag=0;
    register char C=getchar();
    for(;!isdigit(C);C=getchar())Flag^=!(C^45);
    for(;isdigit(C);C=getchar())Return=(Return<<1)+(Return<<3)+(C^'0');
    if(Flag)Return=-Return;
    return Return;
}
inline void Write(int X)
{
    if(X<0)X=-X,putchar('-');
    if(X>9)Write(X/10);
    putchar(X%10^48);
}
int main(void)
{
    register int Case;Case=Read();while(Case--)
    {
        register int i;N=Read();
        register queue< int >Q;
        for(i=1;i<=N;i++)Ans[i]=Queue[i]=0,Flag[i]=Visit[i]=false;
        for(i=1;i<=N;i++)Ans[i]=Read();
        for(i=1;i<=N;i++)Flag[Ans[i]]=true;
        register int Ret=0;
        for(i=1;i<=N;i++)
        {
            if(!Flag[i])Q.push(i);
            else Ret++;
        }
        for(i=1;i<=N;i++)
        {
            if(!Visit[Ans[i]])Visit[Ans[i]]=true,Queue[Ans[i]]=i;
            else
            {
                register int Top=Q.front();Q.pop();
                if(Top!=i)Ans[i]=Top,Queue[Top]=i;
                else
                {
                    if(!Q.empty())
                    {
                        Ans[i]=Q.front();
                        Queue[Q.front()]=i,Q.pop(),Q.push(Top);
                    }
                    else
                    {
                        register int Now=Ans[Queue[Ans[i]]];
                        Ans[Queue[Ans[i]]]=Top;
                        Ans[i]=Now;
                    }
                }
            }
        }
        Write(Ret);
        putchar('\n');
        for(i=1;i<=N;i++)Write(Ans[i]),putchar(' ');
        putchar('\n');
    }
    return 0;
}