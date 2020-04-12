#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
void cmp
void solve(){
    ll s;
    cin>>s;
    int n;
    cin>>n;
    vector<pair<pair<ll,ll>,int>> a(n);
    for(int i =0;i<n;i++){
        cin>>a[i].F.S>>a[i].F.F;
        a[i].S = i;
        a[i].F.S = -a[i].F.S;
    }
    sort(all(a));
    ll cur=0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        ans.pb(a[i].S+1);
        if(a[i].F.F>cur){
            cout<<-1<<'\n';
            return;
        }else{
            cur-=a[i].F.S;
        }
        if(cur>=s){
            break;
        }
    }
    if(cur>=s){
        cout<<ans.size()<<'\n';
        for(auto e: ans){
            cout<<e<<' ';
        }
        cout<<'\n';
    }else{
        cout<<-1<<'\n';
    }

}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
