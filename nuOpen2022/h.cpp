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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}
int n,e,k;

vi g[1010];
int mn[1010];
vi s;

void dfs(int v){
    
    mn[v] = 1010;

    vi mns;
    for(int to: g[v]){
        dfs(to);

        mn[v] = min(mn[v], mn[to]+1);
        mns.pb(mn[to]);
    }

    if(g[v].size()==0){
        mn[v] = 0;
        return;
    }

    sort(all(mns));

    for(int i=1;i<mns.size();i++){
        s.pb(mns[i]);
    }
}

void solve() {
    cin>>n>>e>>k;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        g[u].pb(v);
    }

    dfs(1);

    s.pb(mn[1]);


    if(e<=k){
        yes();
        return;
    }

    int ms = e-k;

    int d = e/ms;

    for(int se: s){
        if(se>d){
            no();
            return;
        }
    }

    yes();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

