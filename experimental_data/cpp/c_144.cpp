#include<bits/stdc++.h>

#define MP make_pair

#define PB push_back

#define PP pop_back()

#define ALL(x) x.begin(),x.end()

#define st first

#define nd second

#define sz(x) (int) x.size()

#define pii pair<int,int>

#define ii int,int

#define ll long long

#define MIN3(x,y,z) min(min(x,y),z)

#define MAX3(x,y,z) max(max(x,y),z)

#define FOR(i,j,k) for(int i=j;i<=k;i++)

#define FR(i,j,k) for(int i=j;i>=k;i--)

#define dbg(x) cout<<x<<endl;getchar();

#define dbgs(x) cout<<x<<" ";

#define MOD 1000000007

#define MXN 100005

using namespace std;

int len1,len2,dp[27],dp2[27],ans,joker;

char s[MXN],s2[MXN];

int main()

{

    scanf("%s",s);

    scanf("%s",s2);

    len1=strlen(s);len2=strlen(s2);

    FOR(i,0,len2-1)

        dp[(int)s2[i]-'a']++;

    FOR(i,0,len2-1)

    {

        if(s[i]!='?')

            dp2[(int)s[i]-'a']++;

        else

            joker++;

    }

    FOR(i,0,len1-len2)

    {

        int dif=0,flag=0;

        FOR(j,0,25)

        {

            if(dp[j]!=dp2[j])

            {

                if(dp2[j]<dp[j])

                    dif++;

                else

                {

                    flag=1;

                    break ;

                }

            }

        }

        if(!flag)

            ans+=(dif<=joker);

        if(s[i]!='?')

            dp2[(int)s[i]-'a']--;

        else

            joker--;

        if(s[i+len2]!='?')

            dp2[(int)s[i+len2]-'a']++;

        else

            joker++;

    }

    printf("%d",ans);

}