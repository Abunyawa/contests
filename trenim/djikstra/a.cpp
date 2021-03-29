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

ll INF = 2009000999;
int n,m;



void solve() {
    cin>>n>>m;
    vector<pair<int,int>> g[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    int s;
    cin>>s;
    vi d(n,INF);
    d[s] = 0;
    priority_queue<pii> q;
    q.push({0,s});
    while(!q.empty()){
        int v = q.top().se;
        int cur = -q.top().fi;
        q.pop();
        if(cur>d[v]) continue;

        for(int i=0;i<g[v].size();i++){
            int to = g[v][i].fi;
            int len = g[v][i].se;
            if(d[v]+len<d[to]){
                d[to] = d[v] + len;
                q.push({-d[to],to});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<d[i]<<' ';
    }

    cout<<'\n';

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

