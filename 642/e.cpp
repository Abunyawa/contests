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


void solve(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vl pre(n+1);
    vl dp(k+1,0);
    pre[0] = 0;
    
    for(int i=1;i<=n;i++){
        if(s[i-1]=='1'){
            pre[i] = pre[i-1]+1;
        }else{
            pre[i] = pre[i-1];
        }
    }
    for(int i=1;i<=k;i++){
        int prev = 0;
        for(int j=i;j<=n;j+=k){
            dp[i] += pre[j-1]-pre[prev];
            if(s[j-1]=='0'){
                dp[i]++;
            }            
            prev = j;
        }
        dp[i]+=pre[n]-pre[prev];
    }
    ll ans = n+1;
    for(int i=1;i<=k;i++){
        cout<<dp[i]<<' ';
        if(dp[i]<ans){
            ans = dp[i];
        }
    }
    cout<<'\n';
    cout<<min(ans,max(0ll,pre[n]-1))<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
