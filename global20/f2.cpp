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
int used[200100];
bool cycle = false;
void dfs(int v){
    used[v] = 1;

    for(int to: g[v]){
        if(used[to]==1) cycle = true;
        if(!used[to]) dfs(to);
    }

    used[v] = 2;
}

void solve() {
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    cycle = false;
    for(int i=0;i<=n;i++){
        g[i].clear();
        used[i] = 0;
    }

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    for(int i=0;i<n;i++){
        g[a[i]].pb(b[i]);
    }

    int mx = 1;
    for(int i = 1;i<=n;i++){
        if(g[i].size() > g[mx].size()){
            mx = i;
        }
    }

    used[mx] = 2;

    for(int i =1;i<=n;i++){
        if(!used[i]) dfs(i);
    }

    if(cycle){
        cout<<"WA\n";
    }else{
        cout<<"AC\n";
    }

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

