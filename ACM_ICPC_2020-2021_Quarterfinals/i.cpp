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
    int s;
    cin >> s;
    int aa = -1, bb = -1;
     
    for (int a = 0; a <= s; ++a) {
        for (int b = 0; b <= s; ++b) {
            if (a * a + b * b == s) {
                aa = a;
                bb = b;
            }
        }
    }
     
    if (aa == -1) {
        cout << "Impossible" << endl;
        return;
    }
     
    cout << aa << ' ' << 0 << endl;
    cout << aa + bb << ' ' << aa << endl;
    cout << 0 << ' ' << bb << endl;
    cout << bb << ' ' << aa + bb << endl;
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