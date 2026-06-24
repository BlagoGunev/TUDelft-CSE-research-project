#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
       
        int n; cin >> n;

        vector<double> a(n*(n+1)/2-1);

        for(auto &i: a) cin >> i;

        sort(a.begin(), a.end());
        vector<double> el;

        int k=1;

        for(int i=1; i<a.size(); i++){
            if(a[i] != a[i-1]){
                if(k%2) el.push_back(a[i-1]);
                k=1;;
            }
            else k++;
        }
        auto geteven =[&](vector<double> x){
            vector<double> a;
            sort(x.begin(), x.end());
            for(int i=x.size()-1; i>0; i--){
                a.push_back((x[i]-x[i-1])/2);
            }
            a.push_back(x[0]/2);

            for(int i=a.size()-1; i>=0; i--){
                a.push_back(a[i]);
            }
            return a;
        };

        auto check=[&](vector<double> b){
            vector<double> c;
            for(int i=0; i<b.size(); i++){
                double v=0;
                for(int l=i; l<b.size(); l++){
                    v+=b[l];
                    c.push_back(v);
                }
            }


            sort(c.begin(), c.end());
          
            int x=a.size()-1, y=c.size()-1;

            while(x>=0&&y>=0){
                if(a[x]!=c[y]) return max<double>(c[y], a[x]);
                x--; y--;
            }
            return 0.0;
        };
        int sum;

        auto split=[&](vector<double> x, int ma){
            double pf=sum-ma; 
            vector<double> gh;
            double h=0;

            for(int i=0; i<x.size(); i++){
                if(h+x[i]>pf && h<pf){
                    gh.push_back(pf-h);
                    h+=x[i];
                    gh.push_back(h-pf);
                }
                else if(h+x[i]>ma && h<ma){
                    gh.push_back(ma-h);
                    h+=x[i];
                    gh.push_back(h-ma);       
                }
                else{
                    h+=x[i];
                    gh.push_back(x[i]);
                }
            }

            return gh;
        };
        auto mergg=[&](vector<double> x, double ma){
            double pf=(double)sum-ma; 
            vector<double> gh;
            double h=0;
            for(int i=0; i<x.size(); i++){
                if(h+x[i]==pf){
                    gh.push_back(x[i]+x[i+1]);
                    h+=x[i];
                    h+=x[i+1];
                    i++;
                }
                else if(h+x[i]==ma){
                    gh.push_back(x[i]+x[i+1]);
                    h+=x[i]; h+=x[i+1];
                    i++;       
                }
                else{
                    h+=x[i];
                    gh.push_back(x[i]);
                }
            }
            return gh;
        };

        auto f=[&](vector<double> x){
            if(n%2==0) return x;
            else{
                vector<double> a;
                for(int i=0; i<x.size(); i++){
                    if(i==(n/2)+1) a.back()+=x[i];
                    else a.push_back(x[i]);
                }

                return a;
            }
        };

        auto ans=[&](vector<double> g){
            for(auto i: g) cout<<(int)i<<" ";
                cout<<"\n";
        };

        if(k%2==0){
            // max is missing
            el.push_back(a.back()+a.back()-el.back());
            el = geteven(el);
            ans(f(el));
        }
        else{
            el.push_back(a.back());
            sum = el.back();
            if(el.size() <(n+1)/2){
                //split an element  

                auto x=geteven(el);

                double ma=check(x);
                x = split(x, ma);
                ans(f(x));
            }
            else{;
                //mergg one
                auto x = geteven(el);
                double ma = check(x);
                x=mergg(x, ma);

                ans(f(x));
            }
        }
    }
}