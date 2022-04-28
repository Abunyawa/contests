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
int g[200100];
ll f[200100];
int in[200100];
int cur[200100];
vl vals[200100];
ll ans = 0;

void dfs(int v){
    if(vals[v].size()==0){
        vals[v].pb(f[v]);
    }

    int ind = 0;
    ll sm = 0;
    for(int i=0;i<vals[v].size();i++){
        if(vals[v][i]<vals[v][ind]){
            ind = i;
        }
        sm+=vals[v][i];
    }

    sm-=vals[v][ind];

    vals[v][ind] = max(vals[v][ind], f[v]);
    ans+=sm;

    //cout<<v<<' '<<vals[v][ind]<<'\n';


    if(g[v]!=0){
        cur[g[v]]++;
        vals[g[v]].pb(vals[v][ind]);
        if(cur[g[v]] == in[g[v]]){
            dfs(g[v]);
        }
    }else{
        ans+=vals[v][ind];
    }
}

void solve() {
    int n;
    cin>>n;
    ans = 0;
    for(int i=1;i<=n;i++){
        g[i] = 0;
        in[i] = 0;
        cur[i] = 0;
        vals[i].clear();
        cin>>f[i];
    }
    for(int i=1;i<=n;i++){
        cin>>g[i];
        in[g[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(in[i]==0){
            dfs(i);
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
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

