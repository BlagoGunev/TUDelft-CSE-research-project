#include <iostream>
    #include <algorithm>
    #include <cmath>
    #include <vector>
    #include <map>
    using namespace std;
    int main()
    {
int n,m;
cin>>n>>m;
vector <pair <int, int> > v;
vector <int> day;
vector <pair <int, int> > yolo;
int a,b,c,i,j;
vector <pair <int, int > > arr;
arr.resize(m);
yolo.resize(m);
for (i=0; i<m; i++) {
    cin>>a>>b>>c;
    v.push_back(pair <int, int> (b,c));
    arr[i].first=b; //
    arr[i].second=a;
    yolo[i].first=b;
    yolo[i].second=i+1;

}
sort (v.begin(), v.end());
day.resize(m);
int index;
vector <int> geass;
geass.resize(m);
for (i=0; i<m; i++) {

        for (j=0; j<m; j++)
        if (arr[j].first==v[i].first) index=j;

    day[i]=arr[index].second;
    for (j=0; j<m; j++)
        if (yolo[j].first==v[i].first) index=j;

    geass[i]=yolo[index].second;
}

vector <int> ans;
int last=0;
ans.resize(n);

for (i=1; i<=n; i++) {

        if (i==v[last].first) {
            if (v[last].second==0) {ans[i-1]=m+1; last++; continue;}
            else {cout<<-1; return 0;}
        }
        bool b=false;
    for (j=last; j<v.size(); j++)
        {
        if (v[j].second!=0 && day[j]<=i) {
        v[j].second--; ans[i-1]=geass[j]; b=true; break;}
        }


    if (!b) ans[i-1]=0;

}
for (i=0; i<ans.size(); i++)
    cout<<ans[i]<<" ";
        return 0;
    }