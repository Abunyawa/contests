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
vi g[200];
vi dp[200];

void dfs(int v){
    if(g[v].size()==0){
        dp[v].pb(v);
        return;
    }
    vector<vi> tmp;
    for(auto x: g[v]){
        dfs(x);
        tmp.pb(dp[x]);
    }
    vi prev;
    for(auto x: tmp[0]){
        prev.pb(x);
    }

    for(int i=1;i<tmp.size();i++){
        vi loc;
        for(auto x: prev){
            loc.pb(x);
        }
        reverse(all(prev));

        for(int j = 0;j<tmp[i].size();j++){
            loc.pb(tmp[i][j]);
            for(auto x: prev){  
                loc.pb(x);
            }
            reverse(all(prev));
        }

        prev = loc;
    }
    dp[v].pb(v);
    for(auto x: prev){
        dp[v].pb(x);
    }
    
}


void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int par;
        cin>>par;
        g[par].pb(i);
    }

    dfs(1);

    cout<<dp[1].size()-1<<'\n';
    for(int i = 1;i<dp[1].size();i++){
        cout<<dp[1][i]<<' ';
    }

    cout<<'\n';

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

