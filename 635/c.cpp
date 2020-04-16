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
int dist[200100];
int deg[200100];
bool used[200100];
vector<int> lf;
int par[200100];
int chil[200100];
int prof[200100];
void dfs(int v,int d){

    used[v] = true;
    bool flag = false;
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            par[g[v][i]]=v;
            dfs(g[v][i],d+1);
            flag = true;
            chil[v] += chil[g[v][i]]+1;
        }
    }

    deg[v] = g[v].size()-1;
    dist[v] = d;
}   
bool cmp(int a,int b){
    return dist[a]>dist[b];
}
ll dp[200100];

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);

    dp[n] = 0;
    dp[n-1] = n-1;
    vector<bool> usedL(n+1,false);
    priority_queue<pair<int,int>> q;
    int cur = n-1;
    usedL[1] = true;
    for(int i=0;i<g[1].size();i++){
        usedL[g[1][i]] = true;
        q.push({((dist[g[1][i]]+1)*(chil[g[1][i]])-dist[g[1][i]]*(chil[g[1][i]]+1)),g[1][i]});
    }
    while(!q.empty()){
        pair<int,int> now = q.top();
        q.pop();
        cur--;
        dp[cur] = dp[cur+1] + now.F;
        for(int i=0;i<g[now.S].size();i++){
            if(!usedL[g[now.S][i]]){
                usedL[g[now.S][i]] = true;
                q.push({((dist[g[now.S][i]]+1)*(chil[g[now.S][i]])-dist[g[now.S][i]]*(chil[g[now.S][i]]+1)),g[now.S][i]});
            }
        } 
    }
    cout<<dp[k]<<'\n';
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
