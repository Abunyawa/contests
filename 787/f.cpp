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
int par[200100];
bool used[200100];
int ans;

void dfs(int v){
    for(int to: g[v]){
        if(to!=par[v]){
            par[to] = v;
            dfs(to);
        }
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    ans = 0;
    for(int i=0;i<=n;i++){
        g[i].clear();
        used[i] = false;
        par[i] = 0;
    }
    int x,y;
    cin>>x>>y;
    vi p(k);
    for(int i=0;i<k;i++){
        cin>>p[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }


    dfs(x);


    int cur = y;

    while(cur!=x){
        used[cur] = true;
        cur = par[cur];
        ans++;
    }

    used[x] = true;


    for(int i=0;i<k;i++){
        if(!used[p[i]]){
            int cur = p[i];

            while(!used[cur]){
                used[cur] = true;
                cur = par[cur];
                ans+=2;
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

