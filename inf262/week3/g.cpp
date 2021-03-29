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

ll dp[100005][220][2];

void solve() {
    int n;
    cin>>n;
    vi a(n+1);

    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<=200;i++){
        dp[0][i][1] = 1;
    }
    // dp[pref][a][flag]  num of ways on prefix, where the last == a, flag 1 = a[pref-1] > a[pref-2]
    // keep prefix sum
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=200;j++){
            if(a[i-1] == -1|| a[i-1]==j){
                dp[i][j][0] = (dp[i-1][j-1][0]+dp[i-1][j-1][1])%MOD;
                dp[i][j][1] = (dp[i-1][200][1]-dp[i-1][j-1][1]+dp[i-1][j][0]-dp[i-1][j-1][0]+2*MOD)%MOD;
            }

            dp[i][j][0]=(dp[i][j][0]+dp[i][j-1][0])%MOD;
			dp[i][j][1]=(dp[i][j][1]+dp[i][j-1][1])%MOD;
        }
    }
    cout<<dp[n][200][1]%MOD<<'\n';

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

