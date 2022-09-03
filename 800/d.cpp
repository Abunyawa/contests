// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int ans;
int ctr;
vi g[200100];
ll l[200100];
ll r[200100];
ll st[200100];

void dfs(int v, int par){

    
    vl a;
    for(int to: g[v]){
        if(to!=par){
            dfs(to, v);
            a.pb(st[to]);
        }
    }

    if(a.size()==0){
        ctr++;
        st[v] = r[v];
        return;
    }

    sort(rall(a));

    ll cur = 0;
    ll sm = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]<=r[v]-sm){
            sm+=a[i];
            cur = max(cur, a[i]);
        }else{
            
            cur = max(cur, r[v] - sm);
            sm = r[v];
            break;
        }
    }

    if(sm<=r[v] && sm>=l[v]){
        st[v] = cur;
        ans--;
    }else{
        st[v] = r[v];
    }
}
void solve() {
    ctr = 0;
    int n;
    cin>>n;
    ans = n;
    for(int i=0;i<=n;i++){
        g[i].clear();
        st[i] = 0;
    }

    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].pb(i);
    }

    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }

    dfs(1,-1);

    if(ans>n || ans<ctr){
        assert(0);
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

