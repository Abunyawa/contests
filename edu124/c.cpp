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
    int n;
    cin>>n;
    vl a(n);
    vl b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    ll ans = abs(a[0]-b[0]) + abs(a[n-1]-b[n-1]);

    ans = min(ans, abs(a[n-1]-b[0]) + abs(a[0]-b[n-1]));

    vl la;
    vl ra;
    vl lb;
    vl rb;
    for(int i=0;i<n;i++){
        la.pb(abs(a[0]-b[i]));
        ra.pb(abs(a[n-1]-b[i]));

        lb.pb(abs(b[0]-a[i]));
        rb.pb(abs(b[n-1]-a[i]));
    }

    sort(all(la));
    sort(all(ra));
    sort(all(lb));
    sort(all(rb));

    ans = min(ans, abs(a[0]-b[0])+ra[0]+rb[0]);
    ans = min(ans, abs(a[n-1]-b[n-1])+la[0]+lb[0]);
    ans = min(ans, abs(a[0]-b[n-1])+ra[0]+lb[0]);
    ans = min(ans, abs(a[n-1]-b[0])+la[0]+rb[0]);

    ans = min(ans, la[0]+ra[0]+lb[0]+rb[0]);


    cout<<ans<<'\n';
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

