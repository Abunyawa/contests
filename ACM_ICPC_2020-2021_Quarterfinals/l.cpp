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
 
const int MAXN = (int)1e4 + 5;
const int DBG = 0;
 
int p[MAXN], invp[MAXN], q[MAXN], a[MAXN];
int n;
 
vi query() {
    cout << "?";
     
    for (int i = 1; i <= n; ++i) {
        cout << ' ' << q[i];
    }
     
    cout << endl;
    vi ret(n + 5);
     
    if (DBG) {
        for (int i = 1; i <= n; ++i) {
            ret[i] = p[q[invp[i]]];
        }
    }
    else {     
        for (int i = 1; i <= n; ++i) {
            cin >> ret[i];
        }
    }
     
    return ret;
}
 
void report(int x[]) {
    cout << "!";
     
    for (int i = 1; i <= n; ++i) {
        cout << ' ' << x[i];
    }
     
    cout << endl;
     
    if (DBG) {
        for (int i = 1; i <= n; ++i) {
            assert(x[i] == p[i]);
        }
    }
}
 
void solve() {
    cin >> n;
     
    if (DBG) {
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            invp[p[i]] = i;
        }
    }
     
    for (int i = 1; i <= n; ++i) {
        q[i] = i % n + 1;
    }
     
    vi nxt = query();
     
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            q[i] = 1;
        }
        else if (i < n) {
            q[i] = i + 1;
        }
        else {
            q[i] = 2;
        }
    }
     
    vi tmp = query();    
    int p = -1;
     
    for (int i = 1; i <= n; ++i) {
        if (tmp[i] == i) {
            assert(p == -1);
            p = i;
        }
    }
     
    a[1] = p;
     
    for (int i = 2, v = nxt[p]; v != p; ++i) {
        a[i] = v;
        v = nxt[v];
    }
     
    report(a);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int tt;
    cin >> tt;
     
    while (tt--) {
        solve();
    }
 
    return 0;
}