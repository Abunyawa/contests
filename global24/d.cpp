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
ll MOD;
ll fact[5010];
ll n;

ll powM(ll a, ll b){
    if(b==0) return 1LL;
    if(b%2==0){
        ll tmp = powM(a,b/2);

        return (tmp*tmp)%MOD;
    }else{
        return (a*powM(a,b-1))%MOD;
    }
}

ll C(ll n, ll k){
    if(n<0 || k<0){
        return 0;
    }

    if(k>n){
        return 0;
    }

    return (fact[n] * powM((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
}


void solve() {
    cin>>n>>MOD;

    fact[0] = fact[1] = 1;

    for(int i=2;i<5010;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }


    if(n%2==0){
        ll needRm = (n-2LL)/2LL;

        ll ans = 0;

        for(int i=0;i<=needRm;i++){
            ll tot = needRm + i;

            ll locA = ((2*fact[tot])%MOD*C(needRm, i))%MOD;
            ans = (ans+locA)%MOD;
        }

        cout<<((n/2)*ans)%MOD<<'\n';
    }else{
        ll needRm = (n-3LL)/2LL;

        ll ans = 0;

        for(int i=0;i<=needRm;i++){
            ll tot = needRm + i;

            ll locA = ((2LL*fact[tot])%MOD*C(needRm+1LL, i))%MOD;

            ans = (ans+locA)%MOD;
        }
        ans = (ans+((needRm+1LL)*fact[n-3])%MOD)%MOD;

        ans = (n*ans)%MOD;

        if(ans<0){
            ans+=MOD;
        }
        cout<<ans<<'\n';
    }
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

