#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t{};
    cin>>t;
    while(t--)
    {
        int n{},k{};
        long long x{};
        cin>>n>>k>>x;
        x--;
        string s;
        cin>>s;
        vector <int> v;
        for(int i=0;i<n;)
        {
            if(s[i]=='a')
                i++;
            else
            {
                int count{};
                for(;i<n && s[i]=='*';i++)
                    count++;
                v.push_back(count);
            }
        }
        int groups=v.size();
        int arr_b[groups]{};
        int i{groups-1};
        for(;x>0;i--)
        {
            arr_b[i]=x%(v[i]*k+1);
            x=x/(v[i]*k+1);
        }
        int j{};
        for(int i=0;i<n;)
        {
            if(s[i]=='a')
            {
                cout<<'a';
                i++;
            }
            else
            {
                for(;i<n && s[i]=='*';i++);
                string bs(arr_b[j],'b');
                cout<<bs;
                j++;
            }
        }
        cout<<endl;
    }
}