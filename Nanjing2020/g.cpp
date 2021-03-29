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

bool dp[1000000];
vi dp2[1000000];
vi ans[1000000];
ll fact[510];

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    
    for(int i=0;i<250001;i++){
        dp[i]=false;
    }
    dp[0] = true;
    dp2[0].pb(0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j = 250000;j>=0;j--){
            if(dp[j]){

                dp[j+x] = true;
                for(int k = 0;k<dp2[j].size();k++){
                    dp2[j+x].pb(dp2[j][k]+1);
                    if(j<=a && j+x>b){
                        ans[j+x].pb(dp2[j][k]);
                    }
                }
                
            }
        }
    }

    double res = 0;
    for(int cur = b+1;cur<=250000;cur++){
        if(ans[cur].size()>0){
            for(auto x: ans[cur]){
                res+=fact[x]*fact[n-x-1];
            }
        }   
    }


    printf("%.10f\n", 1.0 - res/(double)fact[n]);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<500;i++){
        fact[i] = fact[i-1]*i;
    }
    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

