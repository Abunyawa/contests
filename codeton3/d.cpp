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

const ll MOD = 998244353;

void solve() {
    int n;
    ll m;
    cin>>n>>m;

    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll cur = a[0];
    ll ans = 1;
    for(int i=1;i<n;i++){
        if(__gcd(cur,a[i])!=a[i]){
            cout<<0<<'\n';
            return;
        }

        ll have = m/a[i];
        
        ll left = cur/a[i];
        ll fix = cur/a[i];

        for(int i=2;i<=sqrt(fix);i++){
            if(left%i==0){
                have -= (fix/i);
            }
            while(left%i==0){
                left/=i;
            }
        }    
    
        cur = a[i];
        ans = (ans*have)%MOD;
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

