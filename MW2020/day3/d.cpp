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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}


int n,m;
const int MAXN = 20100;
vector<int> g[MAXN];
bool used[MAXN],is[MAXN][MAXN];
int timer, tin[MAXN], fup[MAXN];
 
void dfs (int v, int p = 0) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]){
				is[v][to]=true;
				is[to][v]=true;
            }
		}
	}
}
 
void find_bridges() {
	timer = 0;
	for (int i=1; i<=n; ++i)
		used[i] = false;
	for (int i=1; i<=n; ++i)
		if (!used[i])
			dfs (i);
}


void solve() {
    cin>>n>>m;
    vector<pair<int,int>> edge;
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        edge.pb({u,v});
    }
    find_bridges();
    vector<int> ans;

    for(int i = 0;i<edge.size();i++){
        pii x  =edge[i];
        if(is[x.fi][x.se]){
            ans.pb(i+1);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x: ans){
        cout<<x<<' ';
    }
    cout<<'\n';
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

