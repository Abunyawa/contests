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
    int n,m;
    cin>>n>>m;
    vector<int> a(m,0);
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    int ans = 0;
    int dp[m+1];
    dp[0] = a[0]*2;
    for(int i=1;i<m;i++){
        dp[i] = (dp[i-1]+a[i]-a[i-1])*2;
    }
    cout<<dp[m-1]+(n-a[m-1])<<'\n';
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
