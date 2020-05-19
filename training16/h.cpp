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
ll const INF = 10e10;


void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}


vector<ll> dp(10000100,INF);

void solve(){
    int n;
    cin>>n;
    ll x,y;
    cin>>x>>y;
    dp[1] = x;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+x;
        if(i%2==1){
            dp[i] = min(dp[i],dp[i/2+1]+y+x);
        }else{
            dp[i] = min(dp[i],dp[i/2]+y);
        }
    }
    cout<<dp[n]<<'\n';
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
