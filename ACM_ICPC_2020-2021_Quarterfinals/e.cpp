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
 
const int MAXN = (int)3e5 + 5;
 
int outdeg[MAXN], indeg[MAXN];
vector<pii> adj[MAXN];
vector<array<int, 3>> e;
bool used[MAXN];
vi ans, bad, ord;
int n, m, st;
 
void compress() {
    vi vec;
    vec.pb(st);
     
    for (int i = 0; i < sz(e); ++i) {
        vec.pb(e[i][0]);
        vec.pb(e[i][1]);
    }
     
    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
     
    for (int i = 0; i < sz(e); ++i) {
        e[i][0] = upper_bound(all(vec), e[i][0]) - vec.begin();
        e[i][1] = upper_bound(all(vec), e[i][1]) - vec.begin();
    }
     
    st = upper_bound(all(vec), st) - vec.begin();
    m = sz(vec);
}
 
void dfs(int v) {
    while (!adj[v].empty()) {
        pii cur = adj[v].back();
        adj[v].pop_back();
        dfs(cur.fi);
        ord.pb(cur.se);
    }
}
 
void solve() {
    cin >> n >> st;
     
    for (int i = 1; i <= n; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
         
        if (w == 0) {
            if (a != st) {
                used[i] = 1;
                ans.pb(i);
            }
            else {
                bad.eb(i);
            }
        }
        else {
            e.pb({a, b, i});
        }
    }
     
    compress();
     
    rep (i, 0, sz(e)) {
        auto &[u, v, id] = e[i];
        adj[u].eb(v, i);
        ++outdeg[u];
        ++indeg[v];
    }
     
    int A = -1, B = -1;
     
    for (int i = 1; i <= m; ++i) {
        if (indeg[i] == outdeg[i] - 1) {
            if (A != -1) {
                cout << "No" << endl;
                return;
            }
             
            A = i;
        }
        else if (indeg[i] == outdeg[i] + 1) {
            if (B != -1) {
                cout << "No" << endl;
                return;
            }
             
            B = i;
        }
        else if (indeg[i] != outdeg[i]) {
            cout << "No\n";
            return;
        }
    }
     
    if ((A == -1) != (B == -1)) {
        cout << "No\n";
        return;
    }
     
    dfs(st);
    reverse(all(ord));
    int cur = st;
     
    for (int v : ord) {
        assert(cur == e[v][0]);
        used[e[v][2]] = 1;
        ans.pb(e[v][2]);
        cur = e[v][1];
         
        if (cur != st) {
            for (int id : bad) {
                ans.pb(id);
                used[id] = 1;
            }
             
            bad.clear();
        }
    }
     
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            cout << "No\n";
            return;
        }
    }
     
    cout << "Yes\n";
     
    for (int x : ans) {
        cout << x << ' ';
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