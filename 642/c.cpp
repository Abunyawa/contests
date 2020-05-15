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
ll dp[500100];

void solve(){
    int n;
    cin>>n;
    cout<<dp[n]<<'\n';
}

int main(){
    abu;
    said;
    for(ll i=3;i<500100;i+=2){
        dp[i] = dp[i-2] + (2*i + 2*(i-2))*(i/2);
    }
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
