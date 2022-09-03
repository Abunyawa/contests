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

vi g[300100];
int d[300100];

int ans;
void dfs(int v, int par){


    for(int to: g[v]){
        if(to!=par){
            d[to] += d[v]+1;
            dfs(to,v);
        }
    }

    if((g[v].size()==2 && v!=1) || (v==1 && g[v].size()==1)){
        ans = min(ans,d[v]+d[v]);
    }

    if(g[v].size()==1 && v!=1){
        ans = min(ans, d[v]+d[v]-1);
    }
    //cout<<v<<' '<<ans<<'\n';
}


void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        g[i].clear();
        d[i] = 0;
    }
    ans = n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    d[1] = 1;
    dfs(1,-1);

    cout<<n-ans<<'\n';
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

