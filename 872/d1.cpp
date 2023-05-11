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
ll const MOD = 1e9+7;

ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

ll d[20010];
vi g[20010];
int p[20010];

void dfs(int v, int par){
    //d[v] = 1;
    p[v] = par; 
    for(int to: g[v]){
        if(to!=par){
            dfs(to, v);
            d[v] = d[to]+1;
        }
    }    
}


void solve() {
    ll n,k;
    cin>>n>>k;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,0);
    ll good = 0;
    if(k==1){
        cout<<1<<'\n';
    }else if(k==2){
        for(int i=1;i<=n;i++){
            ll loc = 0;
            loc = (loc+(d[i]*(n-d[i]))%MOD)%MOD;
            
            //cout<<loc<<'\n';
            good = (good+loc)%MOD;
        }
        
        //(fact(n) * powM((fact(k)*fact(n-k))%MOD,MOD-2))%MOD;
        ll tot = n*(n-1LL)/2LL;
        //cout<<good<<' '<<tot<<'\n';
        ll ans = (good * powM(tot%MOD, MOD-2))%MOD;
        cout<<ans<<'\n';
    }else{
        cout<<1<<'\n';
    }
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

