#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
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
*/
/*
int a[200000],b[200000];
int m,n,k,tj1,tj2;
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    cin>>n>>m>>k;
    if(n>m)
    {
        cout<<"YES";
        return 0;
    }
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<m;i++)scanf("%d",&b[i]);

    sort(a,a+n,cmp);
    sort(b,b+m,cmp);
    int i=0;
    while(i<n)
    {
        if(a[i]>b[i])
        {
            cout<<"YES";
            return 0;
        }
        if(a[i]<b[i])
        {
            tj1=tj2=0;
            for(int j=i+1;a[j]==a[i];j++)
            {
                a[j]=b[i];
                tj1=j;
            }
            for(int j=i+1;b[j]>=a[i];j++)
            {
                b[j]=b[i];
                tj2=j;
            }
            if(tj1>tj2)
            {
                cout<<"YES";
                return 0;
            }
            if(tj1<=tj2 && tj1!=0) i=tj1;
        }
        if(a[i]==b[i])i++;
        else break;
    }
    if(a[n-1]>b[n-1])cout<<"YES";
    else cout<<"NO";
}

#include <cmath>
#include <map>
int gcd(int a, int b)
{
    if(b == 0 )return a;
    return gcd(b, a % b);
}
map<int,int> p;
int main()
{
    int n,t,ai;
    cin>>n;
    cin>>t;
    p[t]=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&ai);

        if(p[ai]!=1) t=gcd(ai,t);p[ai]=1;
    }
    if(p[t]==1)
    {
        cout<<t;
        return 0;
    }
    else
    {
            for(int i=1;i<=sqrt(t);i++)
            if(t % i == 0 && p[i] == 1)
            {
                cout<<t;
                return 0;
            }

    }
    cout<<"-1";
    return 0;
}
*/
char ch;
int main()
{
    int n,k,t=0;
    cin>>n>>k;
    getchar();
    while(n--)
    {
        ch=getchar();
        if(ch == '#')t++;
        else t=0;
        if(t==k)
        {
            cout << "NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}