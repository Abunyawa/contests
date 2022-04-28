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
 
vi A, B;
string s;
int n;
 
vi conv(string s) {
    vi ret;
     
    for (char c : s) {
        ret.pb(c - 'A');
    }
     
    return ret;
}
 
void solve() {
    cin >> s;
    A = conv(s);
    cin >> s;
    B = conv(s);
    cin >> n;
    vi mark(26, 0);
     
    for (int x : A) {
        mark[x] = 1;
    }
     
    for (int x : B) {
        mark[x] = 1;
    }
     
    vi S;
     
    rep (i, 0, 26) {
        if (mark[i]) {
            S.pb(i);
        }
    }
     
    if (sz(S) > 10) {
        cout << 0 << endl;
        return;
    }
     
    while (sz(S) < 10) {
        S.pb(-1);
    }
     
    sort(all(S));
    map<pair<vi, vi>, int> cnt;
     
    do {
        vi dg(26, -1);
     
        rep (i, 0, 10) {
            if (S[i] != -1) {
                dg[S[i]] = i;
            }
        }
         
        if (dg[A[0]] == 0 || dg[B[0]] == 0) {
            continue;
        } 
         
        int x = 0, y = 0;
         
        for (int cur : A) {
            x = x * 10 + dg[cur];
        }
         
        for (int cur : B) {
            y = y * 10 + dg[cur];
        }
         
        int sum = x + y;
        vi z;
         
        while (sum > 0) {
            z.pb(sum % 10);
            sum /= 10;
        }
         
        reverse(all(z));
        vi zz;
        vi zz_groups(10, 0);
         
        rep (i, 0, sz(z)) {
            if (S[z[i]] != -1) {
                zz.pb(S[z[i]]);
            }
            else {
                zz.pb(-1);
                zz_groups[z[i]] += (1 << i);
            }
        }
         
        sort(all(zz_groups));
        reverse(all(zz_groups));
         
        while (!zz_groups.empty() && zz_groups.back() == 0) {
            zz_groups.pop_back();
        }
         
        cnt[mp(zz, zz_groups)]++;
    }
    while (next_permutation(all(S)));
     
    vector<string> ans;
     
    rep (i, 0, n) {
        cin >> s;
        vi arr = conv(s);
        vi ss;
        vi ss_groups(26, 0);
         
        rep (j, 0, sz(arr)) {
            int x = arr[j];
         
            if (mark[x]) {
                ss.pb(x);
            }
            else {
                ss.pb(-1);
                ss_groups[x] += (1 << j);
            }
        }
         
        sort(all(ss_groups));
        reverse(all(ss_groups));
         
        while (!ss_groups.empty() && ss_groups.back() == 0) {
            ss_groups.pop_back();
        }
         
        if (cnt[mp(ss, ss_groups)] == 1) {
            ans.pb(s);
        }
    }
     
    cout << sz(ans) << '\n';
     
    for (string x : ans) {
        cout << x << endl;
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