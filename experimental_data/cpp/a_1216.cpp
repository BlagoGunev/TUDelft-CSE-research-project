#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1<<(i))))
#define setbit1(n,i) ((n)(1<<(i)))
#define togglebit(n,i) ((n)^(1<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define fi first
#define se second
#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("d",&a,&b)
#define PI (acos(-1))
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 500005
int main()
{
   int count_a=0,count_b=0,n,count=0;
   scanf("%d",&n);
   char str[n];
   scanf("%s",str);
   for(int i=0;i<n;i++)
   {
       if(str[i]=='a') count_a++;
       else if(str[i]=='b') count_b++;
       if(i&1)
       {
           if(count_b>count_a)
           {
               str[i]='a';
               count_b--;
               count_a++;
               count++;
           }
          else if(count_a>count_b)
           {
               str[i]='b';
               count_b++;
               count_a--;
               count++;
           }
       }
    }
    printf("%d\n",count);
    printf("%s\n",str);
  return 0;
}