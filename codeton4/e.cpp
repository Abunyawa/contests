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

int to[200100];
int a[200100];
int size[200100];
bool used[200100];
priority_queue<pii> q[200100];

void bfs(int st){
    for(int to: g[st]){
        q[st].push({-a[to],to});
    }

    while(q.empty()){
        int cur = q.top()[1];
        int par = q.top()[2];
        q.pop();


    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        to[i]=i;
        size[i] = 1;
        used[i] = false;
    }

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
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

