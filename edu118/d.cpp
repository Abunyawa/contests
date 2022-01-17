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

ll dp[n+1];

void solve() {
    int n;
    cin>>n;

    vi a(n);
    vi depth(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i] = 0;
    }
    dp[n]=0;

    dp[0] = 1;

    for(int i=0;i<n;i++){
        ll updRaz = 0;
        if(a[i]-1>=0){
            updRaz = dp[a[i]-1];
        }

        ll updDva = dp[a[i]];
        ll updTri = dp[a[i]+1];

        dp[a[i]-1] = (dp[a[i]-1]+updRaz)%MOD;
        dp[a[i]+1] = (dp[a[i]+1]+updDva)%MOD;
        dp[a[i]+1] = (dp[a[i]+1]+updTri)%MOD;
    }

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

