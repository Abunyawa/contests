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

    vi a(2*n);

    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }

    int sm1 = 0;
    int sm2 = 0;

    if(n==1){
        cout<<abs(a[0]-a[1])<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        sm1+=abs(a[i]);
    }

    for(int i=n;i<2*n;i++){
        sm2+=abs(a[i]);
    }
    int ans = abs(sm1) + abs(sm2);
    for(int i =0;i<n;i++){

        int lsm1 = sm1;

        int lsm2 = sm2;

        lsm1 -= a[i];
        lsm2 -= a[i+n];
        lsm2 += a[i+n] - a[i];
        lsm2 += a[i];

        ans = min(ans, abs(lsm1) + abs(lsm2));
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

