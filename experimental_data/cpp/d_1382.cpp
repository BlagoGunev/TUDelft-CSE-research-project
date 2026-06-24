#include<cstdio>
#include<vector>
using namespace std;
int main()
{
int t,n;
vector<int> len;
int p[4005];
int dp[4005];
scanf("%d",&t);
while(t--){
len.clear();
scanf("%d",&n);
for(int i=1;i<=2*n;i++){
scanf("%d",&p[i]);
}
p[2*n+1]=10000000;
int num=1;
for(int i=1;i<=2*n;){
int j=i+1;
while(p[i]>p[j]){
num++;
j++;
}
len.push_back(num);
i=j;
num=1;
}
for(int i=1;i<=n;i++) dp[i]=0;
dp[0]=1;
for(int i=0;i<len.size();i++){
for(int j=n;j>=len[i];j--){
if(dp[j-len[i]]){
dp[j]=1;
}
}
}
if(dp[n]){
printf("YES\n");
}else{
printf("NO\n");
}
}
}