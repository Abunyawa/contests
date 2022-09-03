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
int a[200100];
bool used[200100];
int mn = 1e9;
int ver = 0;

void dfs(int v){
    used[v] = true;
    if(g[v].size()%2==1){
        mn = min(mn, a[v]);
    }
    ver+=g[v].size();
    for(int to: g[v]){
        if(g[to].size()%2==0 && g[v].size()%2==0){
            mn = min(mn, a[to]+a[v]);
        }

        if(!used[to]){
            dfs(to);
        }
    }

}

void solve() {
    ver = 0;
    mn = 1e9;
    int n,m;
    cin>>n>>m;

    for(int i=0;i<=n;i++){
        g[i].clear();
        used[i] = 0;

    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs(i);
        }
    }

    //cout<<ver<<'\n';

    if(ver/2%2==1){
        ans+=mn;
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

