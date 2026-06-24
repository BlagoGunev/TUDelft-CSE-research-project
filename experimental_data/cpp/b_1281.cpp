#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define lp(i,s,n) for(ll i=s;i<ll(n);i++)
#define pb push_back
#define endl '\n'
#define debug(x) cout<<"[" << #x << " is: " << x << "] "<<endl;

#define file freopen("a.in","r",stdin);
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0);

int freq[26];
int main() {   fastIO
    
    int t; cin>>t;
    while(t--){
        memset(freq, 0, sizeof(freq));
        string a, b;
        cin>>a>>b;
        lp(i, 0, a.size())
            freq[a[i]-'A']++;

        bool less=false;
        bool swaped = false;
        lp(i, 0, max(a.size(),b.size()))
            if(i>=a.size()){
                less = true;
                break;
            }
            else if(i>=b.size()){
                break;
            }
            else if(a[i] < b[i]){
                less = true;
                break;
            }

            else{
                if(swaped){
                    if(a[i]==b[i]){
                        freq[a[i]-'A']--;
                        continue;
                    }
                    else
                        break;
                }

                
                for(int j=b[i]-'A'-1;j>=0;j--)
                    if(freq[j]){
                        for(int k=i+1;k<a.size();k++)
                            if(a[k]-'A' == j){
                                swap(a[i], a[k]);
                                break;
                            }
                        less=true;
                        break;
                    }
                if(less)
                    break;
                else if(a[i] == b[i])
                    freq[a[i]-'A']--;
                else{
                    if(freq[b[i]-'A']){
                        for(int k=a.size();k>i;k--)
                            if(a[k] == b[i]){
                                swap(a[i], a[k]);
                                swaped=true;
                                break;
                            }
                        freq[b[i]-'A']--;
                    }
                    else
                        break;

                }
                    
            }
        if(less)
            cout<<a<<endl;
        else 
            cout<<"---"<<endl;
    }
    
    return 0;
}