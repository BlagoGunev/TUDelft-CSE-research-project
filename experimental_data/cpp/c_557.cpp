#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>



using namespace std;



#define si(a) scanf("%d",&a)

#define f first

#define s second

#define mp(a,b) make_pair(a,b)



int cnt[205];

pair<int,int> all[100005];

int suf_sum[100005];



int main()

{

    //freopen("input.txt","r",stdin);

    int n,i,j;

    si(n);

    for(i=0;i<n;i++)

        si(all[i].f);

    for(i=0;i<n;i++)

        si(all[i].s);

    sort(all,all+n);

    for(i=n-1;i>=0;i--)

        suf_sum[i]=suf_sum[i+1]+all[i].s;

    int ans=1000000000,tot=0;

    for(i=0;i<n;i=j){

        int bad=0;

        j=i;

        while(j<n && all[j].f==all[i].f)j++;

        int x=j-i,p=200;

        x--;

        while(x>0 && p>0){

            bad+=(p*min(cnt[p],x));

            x-=cnt[p];

            p--;

        }

        ans=min(ans,suf_sum[j]+tot-bad);

        for(p=i;p<j;p++){

            cnt[all[p].s]++;

            tot+=all[p].s;

        }

    }

    cout<<ans<<endl;

    return 0;

}