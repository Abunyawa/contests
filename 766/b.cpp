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
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,m;
    cin>>n>>m;
    vi ans;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            ans.pb(max(max(abs(1-i)+abs(1-j), abs(1-i) + abs(m-j)),max(abs(n-i)+abs(1-j), abs(n-i) + abs(m-j))));
        }
    }


    sort(all(ans));

    for(int i=0;i<n*m;i++){
        cout<<ans[i]<<' ';
    }

    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

