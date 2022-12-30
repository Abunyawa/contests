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

ll g[510][510];
vi adj[510];
ll d1[510];
bool used1[510];
int p1[510];
int p2[510];
ll d2[510];
bool used2[510];

void bfs1(int v){
    queue<int> q;
    q.push(v);
    used1[v] = true;
    d1[v] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int to: adj[cur]){
            if(!used1[to]){
                d1[to] = d1[cur]+1;
                p1[to] = cur;
                used1[to]=true;
                q.push(to);
            }
        }
    }
}


void bfs2(int v){
    queue<int> q;
    q.push(v);
    used2[v] = true;
    d2[v] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int to: adj[cur]){
            if(!used2[to]){
                d2[to] = d2[cur]+1;
                used2[to]=true;
                p2[to] = cur;
                q.push(to);
            }
        }
    }
}
void solve() {
    int n,m;
    cin>>n>>m;

    for(int i =0;i<=n;i++){
        adj[i].clear();
        used1[i] = false;
        used2[i] = false;
        d1[i] = 0;
        d2[i] = 0;
        for(int j=0;j<=n;j++){
            g[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;

        if(g[u][v]==0){
            g[u][v] = w;
            adj[u].pb(v);
            adj[v].pb(u);
        }else{
            g[u][v] = min(g[u][v], w);
        }
    }

    bfs1(1);
    bfs2(n);

    ll ans = 1e18;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            if(g[i][j]!=0){
                ll locA = min((d1[i]+d2[j]+1)*g[i][j], (d1[j]+d2[i]+1)*g[i][j]);

                locA = min(locA, min((d1[i]+d2[i]+1)*g[i][j], (d1[j]+d2[j]+1)*g[i][j]));


                
                // if(locA<ans){
                //     cout<<i<<' '<<j<<'\n';
                //     cout<<d1[i]<<' '<<d2[j]<<' '<<d1[j]<<' '<<d2[i]<<'\n';
                // }
                ans = min(ans, locA);
            }

        }
    }

    cout<<ans<<'\n';
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

