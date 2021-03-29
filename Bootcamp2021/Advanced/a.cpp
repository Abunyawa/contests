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
    ll n,m;
    cin>>n>>m;
    vi u(10,0);
    ll s = m%10;
    vi was;
    ll sm = 0;
    while(u[s]==0){
        was.pb(s);
        sm+=s;
        u[s] = 1;
        s+=m;
        s%=10;
    }
    ll b = n/m;
    ll ans = b/was.size() * sm;
    for(int i=0;i<b%was.size();i++){
        ans+=was[i];
    }

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

