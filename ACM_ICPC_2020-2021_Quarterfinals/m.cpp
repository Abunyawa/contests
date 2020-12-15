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
 
void solve() {
    int n;
    cin >> n;
    vi a(n);
     
    rep (i, 0, n) {
        cin >> a[i];
    }
     
    a.pb(0);
    sort(all(a));
    n = sz(a);
    int d = 0;
     
    rep (i, 1, n) {
        d = max(d, a[i] - a[i - 1]);
    }
     
    rep (i, 0, n) {
        if (i + 2 < n && a[i + 2] - a[i] <= d) {
            cout << 0 << endl;
            return;
        }
    }
     
    cout << d << endl;
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