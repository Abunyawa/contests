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

int n,m;
vi g[100100];
int col[100100];
bool used[100100];

void dfs(int v){
    used[v] = true;
    for(int i=1;i<=3;i++){
        bool flag=true;
        for(int j=0;j<g[v].size();j++){
            if(i==col[g[v][j]]){
                flag = false;
            }
            
        }
        if(flag){
            col[v] = i;
            break;
        }
    }
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            dfs(g[v][i]);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb(b);
        g[a].pb(c);
        g[b].pb(a);
        g[b].pb(c);
        g[c].pb(a);
        g[c].pb(b);
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<col[i]<<' ';
    }
    cout<<endl;
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
