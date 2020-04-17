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
vector<int> g[200100];
bool used[200100];
int dp[200100];
int a1,a2;
int ans = -1;
void dfs(int v){
    used[v] = true;
    if(v == a1 || v == a2){
        dp[v]++;
    }
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            dfs(g[v][i]);
            dp[v] += dp[g[v][i]];
        }
    }
    if(dp[v]==2 && ans == -1){
        ans = v;
    }   
}
void solve(){
    int n;
    cin>>n;
    cin>>a1>>a2;
    for(int i= 2;i<=n;i++){
        int x;
        cin>>x;
        g[x].pb(i);
    }
    dfs(1);
    cout<<ans<<'\n';
}

int main(){
    
    freopen("INPUT.TXT","r",stdin);
    freopen("OUTPUT.TXT","w",stdout);
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
