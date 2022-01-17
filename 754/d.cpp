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

vl g[200100];
queue<ll> q[32];
int p[200100];
vi leaves;
int d[200100];
void dfs1(int v, int par){
    
    if(g[v].size()==1){
        leaves.pb(v);
    }
    
    for(int to: g[v]){
        if(to!=par){
            p[to] = v;
            d[to] = d[v]+1;
            dfs(to,v);
        }
    }


}

void solve() {
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        g[i].clear();
        p[i] = 0;
        d[i] = 0;
    }
    ll ctr = 1;
    ll nxt = 0;
    for(int i=1;i<=n;i++){
        q[nxt].insert(i);
        ctr--;
        if(ctr==0){
            nxt++;
            ctr = (1LL<<nxt);
        }
    }

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
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

