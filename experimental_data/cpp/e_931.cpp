#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n, ma, x, w;
string alfa;
vector <int> V[30];
int WYJ[30];
long double w1, w2;

int main()
{
    
    cin>>alfa;
    w=0;
    for (int l=0;l<26; l++)
    {
        ma=0;
        for (int la=0; la<alfa.size(); la++)
        {
            if (alfa[la]==(char)(l+97)) V[l].push_back(la);
        }
        for (int la=0; la<alfa.size(); la++)
        {
            for (int lo=0; lo<V[l].size(); lo++)
            {
                V[l][lo]++; if (V[l][lo]>=alfa.size()) V[l][lo]=0;
                WYJ[(int)alfa[V[l][lo]]-97]++;
            }
            x=0;
            for (int lo=0; lo<26; lo++)
            {
                if (WYJ[lo]==1) x++;
                WYJ[lo]=0;
            }
            ma=max(x, ma);
        }
        w+=ma;
    }
    w1=alfa.size(); 
    w2=w;
    w1=w2/w1;
    cout.fixed;
    cout<<setprecision(15);
    cout<<w1<<endl;
}