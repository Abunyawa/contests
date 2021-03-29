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

const int MAXN = (int)1e5 + 5;

map<string, vi> pos[3];
string ans[MAXN];
int m, n, k;

void solve() {
    cin >> m >> n >> k;
    
    rep (i, 0, 3) {
        pos[i].clear();
    }
    
    fill(ans, ans + n, "");
    set<int> S;
    
    rep (i, 0, n) {
        S.insert(i);
    }
    
    rep (i, 0, m) {
        string s;
        cin >> s;
           
        if (pos[2].count(s)) {
            continue;
        }
        
        int lvl = 0;
        
        while (lvl < 2) {
            vi &vec = pos[lvl][s];
            
            if (sz(vec) == k - 1) {
                for (int id : vec) {
                    ans[id].clear();
                    S.insert(id);
                }
                
                vec.clear();
                lvl++;        
            }
            else {
                break;
            }
        }
        
        if (!S.empty()) {
            pos[lvl][s].pb(*S.begin());
            ans[*S.begin()] = s + (lvl > 0 ? to_string(lvl + 1) : "");
            S.erase(S.begin());
        }
    }   
    
    rep (i, 0, n) {
        cout << (ans[i].empty() ? "-1" : ans[i]) << ' ';
    }
    
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    rep (i, 1, tt + 1) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}