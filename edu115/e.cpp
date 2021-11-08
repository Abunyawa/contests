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

int d[1010][1010];
ll n,m;

void solve() {
    int q;
    cin>>n>>m>>q;
    ll ans = n*m;
    ll diag = min(n,m);

    ll maxDiag = max(n,m)-min(n,m)+1;

    ll cntDiag = diag*(diag-1)/2LL;

    ans+= (cntDiag*6LL)*maxDiag;

    for(ll i = 1;i<min(n,m);i++){
        ll diagSz = diag - i;

        cntDiag = diagSz*(diagSz-1)/2LL;

        ans+= (cntDiag*6LL)*2LL;
    }

    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

