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

ll fact[2000100];
ll MOD = 998244353;

ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

ll C(int n, int k){
    return (fact[n] * powM((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
}

void solve() {
    fact[1] = 1;
    fact[0] = 1;
    for(int i = 2;i<2000100;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    ll n;
    cin>>n;
    ll ans = (n * fact[n])%MOD;
    for(int i = 1;i<n;i++){
        ans-= (C(n,i) * fact[n-i])%MOD;
        if(ans<0){
            ans+=MOD;
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

