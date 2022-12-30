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
ll f[200100];
ll have[200100];
ll s[200100];
ll bst[200100];
ll ans;

void dfs(int v, int par){
    have[v] = f[v];
    ans+= have[v]*s[v];

    if(par!=-1 && g[v].size()==1){
        bst[v] = s[v];
        return;
    }
    ll each;
    if(par==-1){
        each = have[v]/g[v].size();
        f[v] = have[v]%g[v].size();
    }else{
        each = have[v]/(g[v].size()-1);
        f[v] = have[v]%(g[v].size()-1);
    }

    vl hv;
    for(int to: g[v]){
        if(to!=par){
            f[to] = each;
            dfs(to, v);
            hv.pb(bst[to]);
        }
    }

    bst[v] = s[v];
    

    sort(all(hv));

    int cur = hv.size()-1;

    for(int i=0;i<f[v];i++){
        ans += hv[cur--];
        if(i==f[v]-1){
            bst[v] += hv[cur];
        }
    }

    if(f[v]==0){
        bst[v] += hv[hv.size()-1];
    }

}

void solve() {
    int n;
    ll k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        bst[i] = 0;
        f[i] = 0;
        have[i] = 0;
        s[i] = 0;
        g[i].clear();
    }
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].pb(i);
        g[i].pb(x);
    }


    for(int i=1;i<=n;i++){
        cin>>s[i];
    }

    ans = 0;
    f[1] = k;
    dfs(1,-1);

    //cout<<bst[2]<<' '<<bst[4]<<'\n';
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

