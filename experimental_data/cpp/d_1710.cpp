#include "bits/stdc++.h"

using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int N=2005;

int l[N],r[N]; 

char s[N][N];

void solve(){

         int n;

         scanf("%d",&n);

		for(int i=1;i<=n;++i) 

        l[i]=r[i]=i,scanf("%s",s[i]+i);

		

        

        for(int len=2;len<=n;++len) {

              for(int i=1,j;i<=n-len+1;++i) {

                if(s[i][j=i+len-1]>48&&l[i]-l[j]){

                         	printf("%d %d\n",i,j);

                            int t[2]={i,j};



                            for (int k = i + 1, cur = 1; k < l[j]; ++k)

                                if (l[k] == k)

                                    printf("%d %d\n",t[cur],k), t[cur] = k, cur ^= 1;



                            for (int L = l[i], R = r[j], k = L; k <= R; ++k)

                                l[k] = L, r[k] = R;

                }

              }

        }

}



int main(){

    fast;

    int t ;

    scanf("%d",&t);

      while(t--)solve();



}