#include <bits/stdc++.h>

#define Dattebayo() ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)

#define all(v) ((v).begin()), ((v).end())

#define YES cout<<"YES\n"

#define NO cout<<"NO\n"

#define ll long long

#define F first

#define S second

#define endl "\n"

using namespace std;

///Where there's a will there's a way.

///Well, نـورت الكــود يـعـمـنـا



int main()

{

    Dattebayo();

    int t;

    string s,res;

    char c;

    cin>>t;

    while(t--){

        int ind=0;

        res="";

        cin>>s;

        set <char> st;

        map <char,int> mp;

        for(int i=0 ; i<s.size() ; i++)

        {

            st.insert(s[i]);

            mp[s[i]]= i;

        }

        while (ind <s.size()){

            c=*(st.begin());

            if(mp[c]<ind){

                st.erase(c);

                continue;

            }

            for( ; ind <= mp[c];ind++)

            {

                if(s[ind]!='9' && s[ind]!=c)

                    res.push_back((char)(s[ind]+1));

                else

                    res.push_back(s[ind]);

            }

            st.erase(c);

        }

        sort(all(res));

        cout<<res<<endl;

    }

}