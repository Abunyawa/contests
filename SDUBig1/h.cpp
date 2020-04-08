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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
vector<int> g[200100];
int ctr = 0;
bool used[200100];
void dfs(int v){
    used[v] = true;
    bool fl = false;
    for(int i = 0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            fl = true;
            dfs(g[v][i]);
        }
    }
    if(!fl){
        ctr++;
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int v,u;
        cin>>v>>u;
        g[v].pb(u);
        g[u].pb(v);
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()>1){
            dfs(i);
            break;
        }
    }
    if(n==2){
        ctr = 2;
    }
    cout<<(ctr+1)/2<<'\n';
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
