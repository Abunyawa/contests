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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

vi g[200100];
ll sum[200100];
ll mx[200100];
ll ans = 0;

void dfs(int v){
    
    sum[v] = 0;
    mx[v] = 0;
    for(int to:g[v]){
        dfs(to);
        sum[v]+=max(sum[to], mx[to]);
        mx[v] = max(mx[v], mx[to]+1);
    }

    if(g[v].size()==0){
        sum[v] = 1;
        mx[v]  =1;
        return;
    }

    if(v==1){
        if(g[v].size()==1){
            ans = max(sum[v], mx[v]);
        }else{
            for(int to:g[v]){
                ans += max(sum[to], mx[to]);
            }
        }
    }
}

void solve() {
    int n;
    cin>>n;

    for(int i=2;i<=n;i++){
        int x;
        cin>>x;

        g[x].pb(i);
    }

    dfs(1);

    cout<<ans<<'\n';
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

