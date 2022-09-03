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

ll const MOD= 1e9+7;

ll fact[200100];

ll powM(ll a, ll b){
    if(b==1){
        return a%MOD;
    }

    if(b==0){
        return 1;
    }

    if(b%2==0){
        ll rt = powM(a,b/2LL);

        return (rt*rt)%MOD;
    }else{
        return (powM(a,b-1LL)*a)%MOD;
    }
}

ll C(int n, int k){
    return (fact[n] * powM((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
}


void solve() {
    ll n,k;
    cin>>n>>k;


    if(k>=n){
        cout<<powM(2,n)<<'\n';
        return;
    }

    ll ans = 1;

    for(int i=1;i<=k;i++){
        ans = (ans+C(n,i))%MOD;
    }


    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = fact[1] = 1;

    for(int i=2;i<200100;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}

