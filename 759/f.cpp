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

ll const MOD = 998244353;

ll dp[200100][2];

void solve() {
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n==1){
        cout<<a[0]%MOD<<'\n';
        return;
    }
    if(a[0]>a[1]){
        dp[0][0] = a[1]%MOD;
        dp[0][1] = (a[0]-a[1])%MOD;
    }else{
        dp[0][0] = a[0]%MOD;
        dp[0][1] = 0;
    }
    for(int i=1;i<n-1;i++){
        dp[i][1] = ((max(0LL,a[i] - a[i+1]))%MOD*dp[i-1][1])%MOD;
        dp[i][0] = ((min(a[i],a[i+1]))%MOD*dp[i-1][1])%MOD;

        dp[i][1] = (dp[i][1] + ((dp[i-1][0]-1)%MOD*(max(0LL,a[i] - a[i+1]))%MOD)%MOD)%MOD;
        dp[i][0] = (dp[i][0] + ((dp[i-1][0]-1)%MOD*(min(a[i],a[i+1]))%MOD)%MOD)%MOD;
    }



    cout<<((dp[n-2][0]*(a[n-1]-1LL)%MOD)%MOD + (dp[n-2][1]*a[n-1])%MOD)<<'\n';
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

