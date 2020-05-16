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
int state[200100];
vector<int> g1[200100];
vector<int> g2[200100];

int was[200100];
int used1[200100];
int used2[200100];
bool isOk[200100];

void dfs1(int v){
    used1[v] = true;
    was[v]++;
    for(int i=0;i<g1[v].size();i++){
        if(!used1[g1[v][i]] && state[g1[v][i]]!=1){
            dfs1(g1[v][i]);
        }
    }
  

}
void dfs2(int v){
    used2[v] = true;
    was[v]++;
    if(state[v]==1){
        return;
    }
    for(int i=0;i<g2[v].size();i++){
        if(!used2[g2[v][i]]){
            dfs2(g2[v][i]);
        }
    }
  

}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> heads;
    vector<int> tails;
    for(int i=1;i<=n;i++){
        cin>>state[i];
        if(state[i]==1){
            heads.pb(i);
        }
        if(state[i]==2){
            tails.pb(i);
        }
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g1[u].pb(v);
        g2[v].pb(u);
    }
    for(int i = 0;i<heads.size();i++){
        if(!used1[heads[i]])
            dfs1(heads[i]);
    }
    for(int i = 0;i<tails.size();i++){
        if(!used2[tails[i]])
            dfs2(tails[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<max(0,was[i]-1)<<'\n';
    }
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
