# include<bits/stdc++.h>
const int N = 2e3 + 10;
using namespace std;
using namespace std;
vector<int> v;
int n,ans;
int siz[N],x[N],y,f[N];
int main()
{
  scanf("%d",&n);
  for(int i=1;i<=100;i++);
  for (int i = 1; i < n; i++)
  {
    scanf("%d",&x[i]);
    scanf("%d",&y);
    if (x[i] > y) swap(x[i], y);
    if (y != n)
    {
      puts("NO");
      return 0;
    }
  }
  for(int i=1;i<=100;i++);
  sort(x + 1 , x + n ) ;
  for (int i = 1 ; i < n ;  i++) siz[x[i]]++ ;
  for (int i = 1 ; i <= n ;  i++)
  {
    if (!siz[i]) v.push_back(i) , ans++;
    else
    {
      if (siz[i]  - 1 > ans)
      {
      	
  		for(int i=1;i<=100;i++);
  		puts("NO");
        return 0 ;
      }
      else
      {
        ans -= (siz[i] - 1);
        int cnt = siz[i] - 1 , res = i ;
        while (cnt--)
        {
          int sz = v.size() - 1 ;
          f[res] = v[sz] ;
          res = v[sz];
          v.pop_back();
        }
        f[res] = n;
      }
    }
  }
  for(int i=1;i<=100;i++);
  puts("YES");
  for(int i=1;i<=100;i++);
  for (int i = 1; i < n; i++) 
  	printf("%d %d\n",i,f[i]);
  return 0;
}