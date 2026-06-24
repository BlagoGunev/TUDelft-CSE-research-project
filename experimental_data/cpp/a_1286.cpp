#include<bits/stdc++.h>

#include<unordered_set>

using namespace std;



typedef long long ll;



vector<ll> bulbs;



unordered_map<string,int> mp;



ll min(ll a,ll b)

{

    if(a<b) return a;

    return b;

}



// odd--->0



int util(ll odd,ll even,ll i,ll prev)

{

    string temp=to_string(odd)+"_"+to_string(even)+"_"+to_string(i)+"_"+to_string(prev);

    if(mp.find(temp)!=mp.end()) return mp[temp];

    if(i==bulbs.size()) return 0;

    ll res=INT_MAX;

    if(bulbs[i]!=0)

    {

        ll tp;

        if(bulbs[i]%2==1) tp=0;

        else tp=1;

        if(i==0)

        {   

            return mp[temp]=util(odd,even,i+1,tp);

        }

        if(prev==0&&bulbs[i]%2==0)

        {

            return mp[temp]= 1+util(odd,even,i+1,1);

        }

        else if(prev==1&&bulbs[i]%2==1)

        {

            return mp[temp]= 1+util(odd,even,i+1,0);

        }

        else

        {

            return mp[temp]= util(odd,even,i+1,tp);

        }

    }

    else

    {

        if(i==0)

        {

            if(odd>0)

            {

                res=min(res,util(odd-1,even,i+1,0));

            }

            if(even>0)

            {

                res=min(res,util(odd,even-1,i+1,1));

            }

            return mp[temp]= res;

        }

        else

        {

            if(prev==0)

            {

                if(odd>0)

                {

                    res=min(res,util(odd-1,even,i+1,0));

                }

                if(even>0)

                {

                    res=min(res,1+util(odd,even-1,i+1,1));

                }

                return mp[temp]= res;

            }

            else

            {

                if(odd>0)

                {

                    res=min(res,1+util(odd-1,even,i+1,0));

                }

                if(even>0)

                {

                    res=min(res,util(odd,even-1,i+1,1));

                }

                return mp[temp]= res;

            }

        }

    }

}



void solve(vector<ll> &bulbs)

{

    ll odd=0;

    ll even=0;

    ll n=bulbs.size();

    unordered_set<ll> us;

    for(auto x:bulbs)

    {

        us.insert(x);

    }

    for(ll i=1;i<=n;i++)

    {

        if(us.find(i)==us.end())

        {

            if(i%2==0) even++;

            else odd++;

        }

    }

    

    ll res=util(odd,even,0,-1);

    cout<<res<<"\n";

    return ;



}



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);



    ll n;

    cin>>n;

    bulbs.resize(n);

    for(ll i=0;i<n;i++)

    {

        cin>>bulbs[i];

    }

    solve(bulbs);

    return 0;

}