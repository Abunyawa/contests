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

const int MAXN = (int)1e3 + 5;

int dp[MAXN][MAXN];

int calc(int x, int y) {
    if (y == 0) {
        return x % 3 == 2;
    }
    else {
        return x % 3 != 0;
    }

    // if (x == 0) {
    //     return 0;
    // }
    
    // if (x == 1 && y == 0) {
    //     return 0;
    // }
    
    // int &ret = dp[x][y];
    
    // if (ret != -1) {
    //     return ret;
    // }
    
    // ret = 0;
    // ret |= (1 - calc(x - 2, y + 1));
    // if (y > 0) ret |= (1 - calc(x - 1, y - 1));
    
    // return ret;
}

void solve() {
    // memset(dp, -1, sizeof dp);
    int c0, c1, c2, c3;
    cin >> c0 >> c1 >> c2 >> c3;
    int ans = (calc(c1, c2) ^ (c0 % 2));

    if (max({c1, c2, c3}) == 0) {
        ans ^= 1;
    }

    cout << (ans ? "Rabbit" : "Horse") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    rep (i, 1, tt + 1) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}