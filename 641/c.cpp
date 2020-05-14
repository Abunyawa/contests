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

vector<ll> g[100100];
bool used[100100];
int mx = 0;

void dfs(int v,int dist){
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        dfs(g[v][i] , dist+1);        
    }
    if(dist>mx){
        mx = dist;
    }
}

void solve(){
    int n;
    cin>>n;
    vl a(n+1);
    ll pref[n+1],suf[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    pref[1]=a[1];
    suf[n] = a[n];
    for(int i=2;i<=n;i++){
        pref[i] = __gcd(pref[i-1],a[i]);
    }
    for(int i=n-1;i>=1;i--){
        suf[i] = __gcd(suf[i+1],a[i]);
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(i==0){
            ans = suf[2];
        }else if(i==n-1){
            ans=ans*pref[n-1]/__gcd(pref[n-1],ans);
        }else{
            ans = ans*__gcd(pref[i],suf[i+2])/__gcd(__gcd(pref[i],suf[i]),a[i]);
        }
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
