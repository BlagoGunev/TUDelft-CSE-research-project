#include<bits/stdc++.h>
using namespace std;
int n,a[10010],bk[10010],ans[10010];
int main(){
    int T;
    cin>>T;
    while(T--){
    	cin>>n;
	    for(int i=1;i<=n;i++)cin>>a[i];
	    basic_string<int>res;
	    for(int i=n;i;i--) res+=a[i];
	    for(int col=1;!res.empty();col++){
	        set<int>s;
	        for(int i:res)s.insert(i),bk[i]=0;
	        for(int i:res){
	            if(bk[i]==1) {s.erase(i);continue;}
	            auto pos=s.find(i);ans[*pos]=col;
	            if(pos!=s.begin()) pos--,bk[*pos]=1,pos++;
	            pos++;if(pos!=s.end()) bk[*pos]=1;pos--;
	            s.erase(pos);
	        }
	        basic_string<int>tmp;
	        for(int i:res) if(bk[i]) tmp+=i;
	        res=tmp;
	    }
	    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	} 
}