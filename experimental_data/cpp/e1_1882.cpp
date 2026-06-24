#include <bits/stdc++.h>  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
using namespace std;
typedef long long ll;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

bool is_sorted(vector<ll> &arr){
    for(ll i = 1;i<arr.size();i++)
        if(arr[i] != (i))
            return 0;
    return 1;
}

void perform_op(vector<ll> &arr, ll idx){
    // cout<<"PERFORMING idx = "<<idx<<endl;
    vector<ll> ret;
    ret.push_back(-1);
    for(ll i = idx + 1;i<arr.size();i++)
        ret.push_back(arr[i]);
    ret.push_back(arr[idx]);
    for(ll i = 1;i<idx;i++)
        ret.push_back(arr[i]);
    for(ll i = 1;i<arr.size();i++)
        arr[i] = ret[i];
    // cout<<"DONE"<<endl;
}
void print_arr(vector<ll> &arr){
    for(ll i = 1;i<arr.size();i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+1), b(m+1);
    for(ll i =1;i<=n;i++)
        cin>>a[i];
    for(ll i =1;i<=m;i++)
        cin>>b[i];
    vector<ll> ans1;
    vector<ll> acp = a;
    if(n != 1){
        ll nxt_num = n-1;
        ll mtchn = -1;
        for(ll i = 1 ;i<=n;i++)
            if(a[i] == n)
                {mtchn = i;break;}
        if(mtchn != 1){
            ans1.push_back(mtchn-1);
            perform_op(a, mtchn-1);
            // cout<<"HELLO1"<<endl;
            // print_arr(a);
        }
        while(!is_sorted(a)){
            ll mtch = -1;
            for(ll i = 1;i<=n;i++)
                if(a[i] == nxt_num)
                    {mtch = i;break;}
            ans1.push_back(mtch);
            perform_op(a, mtch);
            // cout<<"HELLO2"<<endl;
            // print_arr(a);
            for(ll i = 1;i<=n;i++)
                if(a[i] == n)
                    {mtch = i;break;}
            if(mtch != n){
                ans1.push_back(mtch + 1);
                perform_op(a, mtch + 1);
                // cout<<"HELLO3"<<endl;
                // print_arr(a);
            }
            for(ll i = 1;i<=n;i++)
                if(a[i] == nxt_num)
                    {mtch = i;break;}
            if(mtch != 1){
                ans1.push_back(mtch - 1);
                perform_op(a, mtch - 1);
            // cout<<"HELLO4"<<endl;
            // print_arr(a);
            }
            nxt_num--;
            // break;
            // sleep(1);
        }
    }
    vector<ll> ans2;
    if(m != 1){
        ll nxt_num = m-1;
        ll mtchn = -1;
        for(ll i = 1 ;i<=m;i++)
            if(b[i] == m)
                {mtchn = i;break;}
        if(mtchn != 1){
            ans2.push_back(mtchn-1);
            perform_op(b, mtchn-1);
            // cout<<"HELLO5"<<endl;
            // print_arr(b);
        }
        while(!is_sorted(b)){
            ll mtch = -1;
            for(ll i = 1;i<=m;i++)
                if(b[i] == nxt_num)
                    {mtch = i;break;}
            ans2.push_back(mtch);
            perform_op(b, mtch);
            // cout<<"HELLO6"<<endl;
            // print_arr(b);
            for(ll i = 1;i<=m;i++)
                if(b[i] == m)
                    {mtch = i;break;}
            if(mtch != m){
                ans2.push_back(mtch + 1);
                perform_op(b, mtch + 1);
                // cout<<"HELLO7"<<endl;
                // print_arr(b);
            }
            for(ll i = 1;i<=m;i++)
                if(b[i] == nxt_num)
                    {mtch = i;break;}
            if(mtch != 1){
                ans2.push_back(mtch - 1);
                perform_op(b, mtch - 1);
                // cout<<"HELLO8"<<endl;
                // print_arr(b);
            }
            // break;
            nxt_num--;
        }
    }
    ll ok = 1;
    ll mx = max(ans1.size() , ans2.size());
    ll mn = min(ans1.size() , ans2.size());
    if((mx - mn)%2 == 1 && n%2 ==  0 && m%2 == 0){
        cout<<-1<<endl;
        return 0;
    }
    if((mx - mn) %2 && n%2){
        for(ll i = 1;i<=n;i++){
            ans1.push_back(1);
            perform_op(a, 1);
        }
    }
    else if((mx - mn) %2 && m%2){
        for(ll i = 1;i<=m;i++){
            ans2.push_back(1);
            perform_op(b, 1);
        }
    }
    ll cs = 1;
    while(ans1.size() < ans2.size()){
        if(cs){
            ans1.push_back(1);
            perform_op(a, 1);
        }
        else{
            ans1.push_back(n);
            perform_op(a, n);
        }
        cs = !cs;
    }
    cs = 1;
    while(ans2.size() < ans1.size()){
        if(cs){
            ans2.push_back(1);
            perform_op(b, 1);
        }
        else{
            ans2.push_back(m);
            perform_op(b, m);
        }
        cs = !cs;
    }
    for(ll i = 1;i<=n;i++)
        if(a[i] != i)
            ok = 0;
    for(ll i = 1;i<=m;i++)
        if(b[i] != i)
            ok = 0;
    if(!ok){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans1.size()<<endl;
    for(ll i = 0;i<ans1.size();i++)
        cout<<ans1[i]<<" "<<ans2[i]<<endl;

    return 0;
}