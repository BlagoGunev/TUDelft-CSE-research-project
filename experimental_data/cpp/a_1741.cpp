#include<iostream>
#include<stack>
#include<vector>
#include<set>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){return b == 0 ? a : gcd(b, a % b);}
bool cmp(ll x,ll y){return x>y;}
struct intComp {
    bool operator() (const ll& lhs, const ll& rhs) const{
        return lhs > rhs;
    }
};

struct strComp
{
    bool operator() (const string& str1, const string& str2) const {
        return str1.length() < str2.length();
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string n,x;
        int A,B;
        cin>>n>>x;

        if(n.length()>x.length()&&x[x.length()-1]=='L'&&n[n.length()-1]=='L')
        {
            cout<<">"<<endl;
        }
        else if(n.length()<x.length()&&x[x.length()-1]=='L'&&n[n.length()-1]=='L')
        {
            cout<<"<"<<endl;
        }
        else if(n.length()>x.length()&&x[x.length()-1]=='S'&&n[n.length()-1]=='S')
        {
            cout<<"<"<<endl;
        }
        else if(n.length()<x.length()&&x[x.length()-1]=='S'&&n[n.length()-1]=='S')
        {
            cout<<">"<<endl;
        }
        else{
            if(x[x.length()-1]=='S'&&n[n.length()-1]=='L')
                cout<<">"<<endl;
            else if(x[x.length()-1]=='L'&&n[n.length()-1]=='S')
                cout<<"<"<<endl;
            else if(x[x.length()-1]=='S'&&n[n.length()-1]=='M')
                cout<<">"<<endl;
            else if(x[x.length()-1]=='M'&&n[n.length()-1]=='L')
                cout<<">"<<endl;
            else if(x[x.length()-1]=='M'&&n[n.length()-1]=='S')
                cout<<"<"<<endl;
            else if(x[x.length()-1]=='L'&&n[n.length()-1]=='M')
                cout<<"<"<<endl;
            else if(n==x)
                cout<<"="<<endl;
        }


    }
    return 0;
}