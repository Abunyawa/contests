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
    ll n;
    cin>>n;
    vi a;
    vi b;
    map<int,ll> t;
    map<int,ll> c;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.pb(x);
        b.pb(y);
        t[x]++;
        c[y]++;
    }
    ll ans = n*(n-1LL)*(n-2LL)/6LL;
    ll bad = 0;
    for(int i=0;i<n;i++){
        bad += (t[a[i]]-1LL)*(c[b[i]]-1LL);
    }

    cout<<ans-bad<<'\n';
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

