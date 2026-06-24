#include <bits/stdc++.h>
using namespace std;
map<int,int  > mp;
map<int ,string > mp2;
map<int,string > mp3;
int main()
{
int n;
cin>>n;
mp3[1]="purple"; mp2[1]="Power";
mp3[2]="green";  mp2[2]="Time";
mp3[3]="blue";   mp2[3]="Space";
mp3[4]="orange"; mp2[4]="Soul";
mp3[5]="red";    mp2[5]="Reality";
mp3[6]="yellow"; mp2[6]="Mind";




for(int e=1;e<=n;e++)
{
	int u;
string s;
cin>>s;
if(s=="purple") u=1;
else if(s=="green") u=2;
else if(s=="blue") u=3;
else if (s=="orange") u=4;
else if( s=="red") u=5;
else
u=6;
mp[u]+=1;
}

cout<<6-n<<endl;
for(int e=1;e<=6;e++)
	if(mp[e]==0)
		cout<<mp2[e]<<endl;
}