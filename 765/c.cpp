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

/*
dp[n][k];

*/
ll const INF = 1e10;
ll dp[501][501];
ll sp[501][501];

void solve() {
    int n,l,k;
    cin>>n>>l>>k;
    for(int i=0;i<501;i++){
        for(int j = 0;j<501;j++){
            dp[i][j] = INF;
        }
    }
    vl d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    d.pb(l);
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    

    dp[1][0] = d[1]*a[0];
    for(int i=1;i<n;i++){
        for(int de = 0;de<=k;de++){
            //cout<<dp[i][de]<<' ';
            if(dp[i][de]!=INF){
                if(dp[i][de] + a[i] * (d[i+1]-d[i]) < dp[i+1][de]){
                    sp[i+1][de] = a[i];
                    dp[i+1][de] = dp[i][de] + a[i] * (d[i+1]-d[i]);
                }else if(dp[i][de] + a[i] * (d[i+1]-d[i]) == dp[i+1][de]){
                    sp[i+1][de] = min(a[i],sp[i+1][de]);
                }


                for(int steps = 0; steps+de <= k; steps++){
                    if(de+steps<=k){
                        if(dp[i][de] + sp[i][de] * (d[i+steps]-d[i]) < dp[i+steps][de+steps]){
                            sp[i+1][de+1] = sp[i][de];
                            dp[i+1][de+1] = dp[i][de] + sp[i][de] * (d[i+1]-d[i]);
                        }else if(dp[i][de] + sp[i][de] * (d[i+1]-d[i]) == dp[i+1][de+1]){
                            sp[i+1][de+1] = min(sp[i][de],sp[i+1][de+1]);
                        }
                    }
                }
            }
        }
        //cout<<'\n';
    }


    ll ans = INF;

    for(int i=0;i<=k;i++){
        ans = min(dp[n][i], ans);
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
 