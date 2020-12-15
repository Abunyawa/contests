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
 
ll dp[105][105][2];
int n, k;
 
ll calc(int l, int pp, int flag) {
    if (pp < 0) {
        return 0ll;
    }
 
    int r = n - l - 1;
     
    if (l > r) {
        return pp == 0;
    }
     
    if (l == r) {
        return pp == 0 || pp == 1;
    }
     
    ll &ret = dp[l][pp][flag];
     
    if (ret != -1) {
        return ret;
    }
     
    ret = 0;
     
    // 0, 0
    ret += calc(l + 1, pp, flag);
    // 1, 0
    ret += calc(l + 1, pp - 1, 1);
    // 0, 1
    if (flag) {
        ret += calc(l + 1, pp - 1, 1);
    }
     
    // 1, 1
    ret += calc(l + 1, pp - 2, flag);
     
    return ret;
} 
 
void solve() {
    cin >> n >> k;
    // (i, n - i - 1)
     
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
     
    ll ans = 0;
     
    for (int i = 0; i <= n; ++i) {
        if (i >= k - n && i <= k) {
            ans += calc(0, i, 0);
        }
    }
     
    if (k % 2 == 0) {
        ans += calc(0, k / 2, 0);
    }
     
    cout << ans << endl;
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