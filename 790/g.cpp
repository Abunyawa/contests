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
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

vi g[200100];
int col[200100];
int b[200100];
int w[200100];
int ans;

void dfs(int v){

    if(col[v]==1){
        w[v]++;
    }else{
        b[v]++;
    }

    for(int to:g[v]){
        dfs(to);

        w[v]+=w[to];
        b[v]+=b[to];
    }
    //cout<<v<<' '<<w[v]<<' '<<b[v]<<'\n';
    if(w[v]==b[v]){
        ans++;
    }
}

void solve() {
    int n;
    cin>>n;
    ans = 0;

    for(int i=0;i<=n;i++){
        g[i].clear();
        w[i] = 0;
        b[i] = 0;
        col[i] = 0;
    }
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;

        if(x==i) continue;

        g[x].pb(i);
    }

    string s;
    cin>>s;
    for(int i=0;i<n;i++){
    
        if(s[i]=='W') col[i+1] = 1;
    }

    dfs(1);

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

