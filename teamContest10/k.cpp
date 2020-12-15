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

/*
5 16
again
pirpumsemoystoal
           
marywasnosyagain

*/

int n, m;
string a, b;

void solve() {
    cin >> n >> m;
    cin >> a >> b;
    string c = string(m - n, '?') + a;
    cout<<c<<'\n';
    for (int i = m - 1; i >= n; --i) {
        c[i - n] = 'a' + (26 + b[i] - c[i]) % 26;
        cout<<c<<'\n';
    }
    
    cout << c << endl;

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

