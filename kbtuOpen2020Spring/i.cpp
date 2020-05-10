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
int pos[200100];


void solve(){
    ll h,k;
    cin>>h>>k;
    vector<pair<double,ll>> a(k);
    for(int i=0;i<k;i++){
        cin>>a[i].S;
        a[i].F = (double)a[i].S/(double)pow(2,i);
    }
    sort(all(a));
    ll ans = 0;
    ans+=h/(ll)(a[0].S/a[0].F)*a[0].S;
    h = h%(ll)(a[0].S/a[0].F);
    ll mn = 999999999999;
    for(int i=0;i<k;i++){
        ll cur = (ll)(a[i].S/a[i].F);
       
        if((h+cur-1)/cur*a[i].S<mn){
            mn = (h+cur-1)/cur*a[i].S;
        }
        
    }
    cout<<ans+mn<<'\n';
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
