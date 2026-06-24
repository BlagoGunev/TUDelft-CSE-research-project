#include <bits/stdc++.h>

using namespace std;

#define DIM 200009
#define INF ((long long)1e18+9ll)
#define pairll pair<long long,long long>
#define fi first
#define se second
#define ld long double
#define amen exit(0)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

long long i,j,k,l,n,m,r,mid,cnt;

string s;

vector<long long>nums;

int main()
{
    fast;

    int nt;
    cin>>nt;
    while(nt--){
        cin>>n;
        s="1";
        nums.clear();
        while(n){
            l=1;
            r=1e5;
            while(l<r){
                mid=(l+r+1)/2;
                if(mid*(mid-1)/2<=n)l=mid;
                else r=mid-1;
            }
            nums.push_back(l);
            n-=l*(l-1)/2;
        }

        cnt=2;
        long long kilk=0;
        l=0;
        reverse(nums.begin(),nums.end());
        for(auto to:nums){
            //cout<<to<<' ';
            for(i=1;i<=to-kilk;i++)s+='3';
            s+='7';
            kilk=to;
        }
        //cout<<endl;
        cout<<s<<endl;
    }

    amen;
}
/**

1 3 6 10 15 21 28 36 45

*/