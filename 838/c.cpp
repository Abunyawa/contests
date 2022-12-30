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

const ll MOD =   998244353;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    ll ans = 1;
    ll cur = 1;
    ll o = 0;
    ll z = 0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            cur = (cur*2LL)%MOD;
        }else{
            cur = 1;
        }

        ans = (ans+cur)%MOD;
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

