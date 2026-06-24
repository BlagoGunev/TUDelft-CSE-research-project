#include<bits/stdc++.h>
#define Mod 1000000007
using namespace std;
#define ll long long int
#define gc getchar//_unlocked
#define pc putchar//_unlocked
#define siz 400005
inline ll getn()
{
  ll n=0, c=gc();

  while(c < '0' || c > '9') c = gc();

  while(c >= '0' && c <= '9')
   n = (n<<3) + (n<<1) + c - '0', c = gc();

  return n;
}
inline void fastWrite(ll a)
{
   char snum[20];
   ll i=0;

   do
    {
     snum[i++]=a%10+48;
     a=a/10;
   }while(a!=0);

   i=i-1;

   while(i>=0)
    pc(snum[i--]);

   pc('\n');
}

     
ll RK[600][600];
     
        void no()
        {
            puts("No");
            exit(0);
        }
     
        bool foo_sol(char a, char b)
        {
            return abs(a - b) <= 1;
        }
        
int main()
{   //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ll t,n,m,i,j,k;
    t=1;
    while(t--)
    {   n=getn();m=getn();
     
           for(i=0;i<m;++i)
            {
                ll a = getn();
                a=a-1;
                ll b = getn();
                b=b-1;
                RK[a][b] = 1;
                RK[b][a] = 1;
            }
     
            vector<char> used(n);
     
            string str;
            str.resize(n, '*');
     
            for (i = 0; i < n; i++ )
            {
                for ( j = i + 1; j < n; j++ )
                {
                    if ( !RK[i][j] )
                    {
                        if ( str[i] == '*' ) str[i] = 'a';
     
                        if ( str[j] == '*' )
                            str[j] = (str[i] == 'a') ? 'c' : 'a';
                        else
                        {
                            if ( foo_sol(str[i], str[j]) )
                                no();
                        }
                    }
                }
            }
     
            for(i=0;i<n;i++) 
			if ( str[i] == '*' )
			  str[i] = 'b';
            for ( i = 0; i < n; i++ )
                for (j = i + 1; j < n; j++)
                    if ( foo_sol(str[i], str[j]) ^ RK[i][j]) no();
     
            cout << "Yes\n" << str;
    }

   //fclose(stdout);
    return 0;
}