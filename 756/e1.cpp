// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

vi g[200100];
bool used[200100];
bool used2[200100];
int d[200100];
bool win = false;

void bfs(vi x){
    queue<int> q;

    for(int i=0;i<x.size();i++){
        q.push(x[i]);
        used[x[i]] =true;
        d[x[i]] = 0;
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto to: g[cur]){
            if(!used[to]){
                used[to] = true;
                d[to] = d[cur]+1;
                q.push(to);
            }
        }
    }
}

void dfs(int v, int dis){
    used2[v] = true;

    if(g[v].size()==1 && v!=1){
        win = true;
    }

    for(auto to: g[v]){
        if(!used2[to]){
            if(dis+1<d[to]){
                dfs(to, dis+1);
            }
        }
    }
}
void solve() {
    int n,k;
    cin>>n>>k;
    vi x(k);
    win = false;
    for(int i=1;i<=n;i++){
        used[i] = false;
        used2[i] = false;
        g[i].clear();
    }
    for(int i=0;i<k;i++){
        cin>>x[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs(x);

    dfs(1,0);


    if(win){
        yes();
    }else{
        no();
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

