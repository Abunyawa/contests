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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,p,k;
    cin>>n>>p>>k;
    string s;
    cin>>s;
    s = '0'+s;
    int x,y;
    cin>>x>>y;
    vector<int> dp(n+1,0);
    for(int i=n;i>0;i--){
        if(s[i]=='0'){
            dp[i]+=x;
        }

        if(i+k<=n){
            dp[i]+=dp[i+k];
        }
    }
    int ans = 9999999999999999;
    for(int i=1;i<=n;i++){
        if(i-p>=0){
            ans = min(dp[i]+(i-p)*y,ans);
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

