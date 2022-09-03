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
    ll x;
    cin>>n>>x;

    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll l = a[0]-x;
    ll r = a[0]+x;
    int ans = 0;

    for(int i=1;i<n;i++){
        ll curl = a[i]-x;
        ll curr = a[i]+x;

        if((curl>=l && curl<=r) || (curr>=l && curl<=r)){
            l = max(l, curl);
            r = min(r, curr);
        }else{
            ans++;
            l = curl;
            r = curr;
        }
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

