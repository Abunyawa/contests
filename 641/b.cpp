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
    vector<ll> a(n+1);
    mx = 0;
  
    cin>>a[1];
    vector<int> dp(n+1,1);
    for(int i=2;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=sqrt(i);j++){
            if(i%j==0){
                if(a[i]>a[j] && a[i]>a[i/j])
                    dp[i] = max(dp[i],max(dp[j],dp[i/j])+1);
                else if(a[i]>a[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }else if(a[i]>a[i/j]){
                    dp[i] = max(dp[i],dp[i/j]+1);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dp[i]>mx){
            mx = dp[i];
        }
    }


    cout<<mx<<'\n';
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
