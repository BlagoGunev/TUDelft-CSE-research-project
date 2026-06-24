# include<map>
# include<set>
# include<queue>
# include<stack>
# include<deque>
# include<math.h>
# include<vector>
# include<bitset>
# include<stdio.h>
# include<ctype.h>
# include<iostream>
# include<stdlib.h>
# include<string.h>
# include<algorithm>
# define si size
# define er erase
# define sc scanf
# define be begin
# define fr first
# define se second
# define pr printf
# define pb push_back
# define mp make_pair
# define INF 100000000
# define Int long long int
using namespace std;
int k,n,p,i,j,l,g,d[30][4100],u[30];
string s;
char c;
main()
{
//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
cin>>k>>s;
l=s.length();
vector<string>v(k,s);
vector<int>ln(k,l);
for(i=0;i<l;i++)
{
    u[s[i]-97]++;
}
for(i=0;i<26;i++)
{
    for(j=4096-k;j<4096;j++)
    {
        d[i][j]=u[i];
    }

    for(j=2047;j>0;j--)
    {
        d[i][j]=d[i][j*2]+d[i][j*2+1];
    }
}
for(sc("%d",&n);n--;)
{
    sc("%d %c",&p,&c);
    //pr("%d %c\n",p,c);
    c-=97;
    i=1;
    while(i<2048)
    {
        if(d[c][i*2]<p)
        {
            p-=d[c][i*2];
            i=(i*2)+1;
        }
        else
        {
            i=(i*2);
        }
    }
    c+=97;
    j=k-(4096-i);
    l=v[j].length();
    //pr("%d\n",p);
    for(g=0;g<l;g++)
    {
        if(v[j][g]==c)
        {
            p--;
            if(p==0)
            {
                v[j].er(v[j].be()+g);
                break;
            }
        }
    }
    c-=97;
    //pr("%d\n",i);
    while(i)
    {
        //pr("%d\n",i);
        d[c][i]--;
        i/=2;
    }
}
for(i=0;i<k;i++)
{
    cout<<v[i];
}
cout<<endl;
return 0;
}