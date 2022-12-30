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
vi let[26];

void solve() {
    string s;
    cin>>s;
    ll ans = 0;
    int n = s.length();

    for(int i=0;i<26;i++){
        let[i].pb(-1);
    }
    for(int i=0;i<n;i++){
        let[s[i]-'A'].pb(i);
    }

    for(int i=0;i<26;i++){
        let[i].pb(n);
    }

    for(int i=0;i<26;i++){
        for(int cur=1;cur<let[i].size()-1;cur++){
            ll left = (let[i][cur] - let[i][cur-1]);
            ll right = (let[i][cur+1] - let[i][cur]);

            ans += (left*right)%MOD;
            if(ans>=MOD){
                ans-=MOD;
            }
        }
    }

    cout<<ans<<'\n';

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

