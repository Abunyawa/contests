#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define watch(x) (#x)<<" : "<<(x)<<" ";
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 998244353;


ll count(ll n, ll st, ll k){
    ll cur = st;
    ll ans = 0;
    while(cur<n){
        ans++;
        if(n-cur<=k){
            break;
        }
        cur += min(cur,(n-cur)/2);
    }
    return ans;
}

void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans = 10000;

    if(k>=n){
        cout<<1<<'\n';
        return;
    }
    for(ll i = 1;i<k;i++){
        ans = min(ans,count(n,i,k-i));
    }
    cout<<ans<<'\n';
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
