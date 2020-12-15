
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

void yes() {
    cout << "YES" << '\n';
}

void no() {
    cout << "NO" << '\n';
}
bool win = false;
int ctr = 0;
string str;
int n;
int pref = 0;


void check(){
    if(ctr>=10000){
        assert(0);
    }
}

void save() {
    int end = pref;
    bool flag = false;

    for (int i = 1; i < end; i++) {
        cout << i << ' ' << i + 1 << endl;
        cin >> str;
        ctr++;
        
        if (str == "WIN") {
            win = true;
            return;
        }
        check();

        if (str == "SWAPPED") {
            for (int k = n; k >= i + 2; --k) {
                cout << i + 1 << ' ' << k << endl;
                cin >> str;
                ctr++;
                if (str == "WIN") {
                    win = true;
                    return;
                }
                check();
            }

            cout << i << ' ' << i + 1 << endl;
            cin >> str;
            ctr++;
           
            if (str == "WIN") {
                win = true;
                return;
            }
            check();
            flag = true;
            break;
        }
    }
    if(!flag){
        for (int k = end + 1; k <= n; k++) {
            cout << end << ' ' << k << endl;
            cin >> str;
            if (str == "WIN") {
                win = true;
                return;
            }
            ctr++;
            check();
        }
    }
}



void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << i << ' ' << j << endl;
            cin >> str;
            ctr++;
            
            if (str == "WIN") {
                return;
            }
            check();
            if(j==n){
                pref = i;
            }

            if (ctr % (2 * n) == 0) {
                save();
            }

            if(win){
                return;
            }
        }

        pref = i;
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

