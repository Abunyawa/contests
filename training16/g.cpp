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
int n,m;
ll T;
vector<pair<int,ll>> g[5050];
vector<pair<int,ll>> gb[5050];

vector<vector<int>> dp(5050,vector<int>(5050,-1)); 

void dfs(int v,vector<int> path, ll pr){
    for(int i=0;i<g[v].size();i++){
        dfs(g[v][i].F,path,pr+g[v][i].S);
    }

}


void solve(){
    cin>>n>>m>>T;
    for(int i=0;i<m;i++){
        int u,v;
        ll t;
        cin>>u>>v>>t;
        g[u].pb({v,t});
        g[v].pb({u,t});

    }
    vector<int> p(0);
    dp[1][1] = 0;
    dfs(1,p,0);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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
