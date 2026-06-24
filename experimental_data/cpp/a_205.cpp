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
# define Int long long int
# define MN 100002
# define INF 100000000
using namespace std;
main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int i,j,k,l,n,a,p=0,b,c;
scanf("%d",&n);
for (i=0;i<n;i++)
    {
    scanf("%d",&a);
    if(i==0||a<c)
        {
        c=a;
        b=i;
        p=1;
        }
    else if(a==c)
        {
        p++;
        }
    }
if(p==1)printf("%d",b+1);
else printf("Still Rozdil");
return 0;
}