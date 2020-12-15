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
int dp[200100];
int k = 1;

void dfs(int v, int par = -1){
    
    vi lows;
    for(auto x: g[v]){
        if(x!=par){
            dfs(x,v);
            lows.pb(dp[x]+1);
        }
    }
    if(lows.size()==0){
        dp[v] = 0;
    }else{
        if(lows.size()==1){
            dp[v] = lows[0];
            k = max(k,dp[v]);
        }else{
            sort(all(lows));
            if(v!=1){
                k = max(k,max(lows[0],lows[lows.size()-1]+1));
                dp[v] = lows[0];    
            }else{
                k = max(k,max(lows[0],lows[lows.size()-1]));
                for(int i=0;i<lows.size()-1;i++){
                    k = max(k,lows[i]+1);
                }
            }      
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        g[i].clear();
        dp[i] = 0;
    }
    k = 1;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);

    
    cout<<k<<'\n';
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

