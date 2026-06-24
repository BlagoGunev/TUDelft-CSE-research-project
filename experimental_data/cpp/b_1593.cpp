//

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define deb(x) cout<<#x<<" "<<x<<endl;

#define pb push_back
#define mp make_pair
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define test() cout<<"test-"<<c++<<endl;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void printV(vector<int> v);
void printS(set<int> s);


int charToInt(char c);
char intToChar(int x);


string numSpliteToString(int n){
    
    int r;
    string s;

    while(n!=0)
    {
        r=n%10;
        n=n/10;
        s.push_back(r);
    }

    reverse(s.begin(),s.end());

    return s;
}

bool isDivisibleBy25(string str)
{
    // If length of string is single digit then
    // it's not divisible by 25
    int n = str.length();
    if (n == 1)
        return false;
 
    return ( (str[n-1]-'0' == 0  &&
              str[n-2]-'0' == 0) ||
   ((str[n-2]-'0')*10 + (str[n-1]-'0'))%25 == 0 );
}

void solve()
{

    string s;
    cin>>s;
    int n=s.size();
    int zero=-1,five=-1;
    int szero=-1,sfive=-1;
    int ct=0;
    int ans;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            zero=i;
            break;
        }
        ct++;
    }
    if(zero!=-1){
        for(int i=zero-1;i>=0;i--){
            if(s[i]=='0' || s[i]=='5'){
                szero=i;
                break;
            }
            ct++;
        }
    }
    ans=ct;
    ct=0;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='5'){
            five=i;
            break;
        }
        ct++;
    }

    
    if(five!=-1){
        for(int i=five-1;i>=0;i--){
            if(s[i]=='2' || s[i]=='7'){
                szero=i;
                break;
            }
            ct++;
        }       
    }

if(ans>ct){
    ans=ct;
}

cout<<ans<<endl;

}

int main()
{
optimize();


// #ifndef ONLINE_JUDGE

//    // For getting input from input.txt file
//    freopen("C:\\Users\\admin\\Desktop\\input Output\\input.txt", "r", stdin);

//    // Printing the Output to output.txt file
//    freopen("C:\\Users\\admin\\Desktop\\input Output\\output.txt", "w", stdout);

// #endif



    // //ll t;
     int t;
     cin>>t;

     while(t--)
     {
     //    //cout<<solve()<<endl;

        solve();
     }

    return 0;
}


void printV(vector<int> v){
    for(auto i=v.begin(); i!=v.end(); i++)
    {
        cout<<*i<<endl;
    }
}

void printS(set<int> s){
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        cout<<*i<<endl;
    }
}


int charToInt(char c){

 //char a = c;
 int num = c-'0';

 return num;

}

char intToChar(int x){

    //int i = x;
    char c = '0'+x;

    return c;
}