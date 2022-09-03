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
/*

1 2 3 4 5 6 7
2 3 1 7 6 5 4
2 0 1 0 0 0 0

1       2     2
(1 2 3) (4 7) (5 6)


2*2*2


[2] [2] [2]
*/
vi g[200100];
int va[200100];
bool used[200100];
const ll MOD = 1e9+7;

bool dfs(int v){
    used[v] = true;
    bool ret = false;

    if(va[v]){
        ret = true;
    }
    for(int to: g[v]){
        if(!used[to]){
            ret |= dfs(to);
        }
    }

    return ret;
}

void solve() {
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        g[i].clear();
        used[i] = false;
        va[i] = 0;
    }
    vi a(n+1);
    vi b(n+1);
    vi c(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    
    ll ans =1;

    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            g[a[i]].pb(b[i]);
            if(c[i]!=0) va[a[i]] = 1;
        }else{
            used[a[i]] = true;
        }
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            bool res = dfs(i);

            if(!res){
                ans = (ans*2)%MOD;
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

