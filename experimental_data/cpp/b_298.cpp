#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
/*
char s[1012];
int main()
{
    int n,sor,t,p=0;
    cin >> n;
    scanf("%s", s);
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i]=='L')
        {
            p=1;
            break;
        }
        if(s[i]=='R' && s[i]!='.')
        {
            sor = i;
            for(int j = i + 1; j < strlen(s); j++)
            if(s[j] != s[i])
            {
                t = j;
                break;
            }
            break;
        }
    }
    if(p)
    for(int i = strlen(s)-1; i >= 0 ; i--)
    {
        if(s[i]=='R')break;
        if(s[i]=='L')
        {
            sor = i;
            for(int j = i-1; j > -1; j--)
            if(s[j] != s[i])
            {
                t = j;
                break;
            }
            break;
        }
    }
    cout << sor+1 << ' ' << t+1 ;
}
*/
int main()
{
    int t,x,y,ex,ey,tt=-1;
    char ch;
    cin>>t>>x>>y>>ex>>ey;
    getchar();
    for(int i=1;i<=t;i++)
    {
        ch=getchar();
        switch(ch)
        {
            case 'E' : if(x<ex)x++; break;
            case 'S' : if(y>ey)y--; break;
            case 'W' : if(x>ex)x--; break;
            case 'N' : if(y<ey)y++; break;
        }
        if(x==ex && y==ey)
        {
            tt=i;
            break;
        }
    }
    cout<<tt;
}