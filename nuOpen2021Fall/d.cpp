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
    int n,k;
    cin>>n>>k;
    vl d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }

    sort(all(d));
    ll ans = 1e18;
    for(int i=0;i<n-k+1;i++){
        ll locA = abs(0-d[i]) + abs(d[i]-d[i+k-1]);
        ll locB = abs(0-d[i+k-1]) + abs(d[i]-d[i+k-1]);
        ans = min(ans,min(locA, locB));
    }


    cout<<ans<<'\n';
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

