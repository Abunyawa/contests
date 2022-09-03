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
const ll MOD = 1e9+7;
vi pals;
ll dp[40010];

void solve() {
    int n;
    cin>>n;

    cout<<dp[n]<<'\n';
}

bool isPal(int n){
    string s = to_string(n);

    for(int i=0;i<s.length();i++){
        if(s[i]!=s[s.length()-i-1]){
            return false;
        }
    }

    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ctr = 0;
    for(int i=1;i<=40000;i++){
        if(isPal(i)){ 
            pals.pb(i);
        }
    }

    dp[0] = 1;
    for(int pal: pals){
        for(int i=0;i<=40000;i++){
            if(i+pal>40000){
                continue;
            }
            dp[i+pal] = (dp[i+pal] + dp[i])%MOD;

        }
    }

    int tt = 1;
    
    cin>>tt;


    while (tt--) {
        solve();
    }

    return 0;
}

