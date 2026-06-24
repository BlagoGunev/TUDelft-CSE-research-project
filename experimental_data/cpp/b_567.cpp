#include<iostream>

#include<cstring>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<set>

#include<map>

#define N 4000010

#define INF 100000007

using namespace std;

set<int>q;

int main()

{

	int n;  

    scanf("%d",&n);

    char s[101][2];  

    int x;  

    int ans=0;  

    for(int i=0; i<n; i++)  

    {  

        cin>>s[i]>>x;  

        if(s[i][0]=='-')  

        {  

            if(q.count(x))  

                q.erase(x);  

            else  

                ans++;  

        }  

        else  

        {  

            q.insert(x);  

            int ans1=q.size();  

            ans=max(ans,ans1);  

        }  

    }  

    cout<<ans<<endl;

	return 0;

}