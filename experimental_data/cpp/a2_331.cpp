#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
main(){
ios_base::sync_with_stdio(0);
int n;
cin>>n;
int tab[n];
int skal[n];
int pierw[2*n+10];
int ost[2*n+10];
vector<int>pom;      
for(int i=0;i<2*n+10;i++)pierw[i]=-1; 
for(int i=0;i<n;i++){cin>>tab[i];pom.push_back(tab[i]);}
sort(pom.begin(),pom.end());
for(int i=0;i<n;i++)skal[i]=(upper_bound(pom.begin(),pom.end(),tab[i])-pom.begin());
for(int i=0;i<n;i++){if(pierw[skal[i]]==-1)pierw[skal[i]]=i;ost[skal[i]]=i;}
long long maks=1000000000;
maks=maks*maks;
maks=maks*-1;
int poz;
vector<int>wyc;
for(int i=0;i<n;i++){if(pierw[skal[i]]!=ost[skal[i]]){if(tab[i]>maks){maks=tab[i];poz=i;}}}
long long pref[n+1];//uwaga indeksy long longi
pref[0]=0;
for(int i=1;i<=n;i++){
if(tab[i-1]<0)pref[i]=pref[i-1];
else pref[i]=pref[i-1]+tab[i-1];        
}
int pocz,kon;
//for(int i=0;i<=n;i++)cout<<pref[i]<<" ";
//cout<<"\n";
//for(int i=0;i<n;i++)cout<<skal[i]<<" ";
//cout<<"\n";
//for(int i=0;i<n;i++)cout<<pierw[skal[i]]<<" "<<ost[skal[i]]<<"\n";
maks=1000000000;
maks=maks*maks;
maks=maks*-1;
for(int i=0;i<n;i++){
if(pierw[skal[i]]==ost[skal[i]])continue;
if(pref[ost[skal[i]]]-pref[pierw[skal[i]]+1]+tab[pierw[skal[i]]]+tab[ost[skal[i]]]>maks)
{maks=pref[ost[skal[i]]]-pref[pierw[skal[i]]+1]+tab[pierw[skal[i]]]+tab[ost[skal[i]]];pocz=pierw[skal[i]];kon=ost[skal[i]];} 
}
for(int i=0;i<n;i++){
if(i<pocz||i>kon||tab[i]<0){if(pocz==i||kon==i)continue;wyc.push_back(i+1);}        
}
cout<<maks<<" "<<wyc.size()<<"\n";
for(int i=0;i<wyc.size();i++)cout<<wyc[i]<<" ";
cout<<"\n";
//system("pause");
}