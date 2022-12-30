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

ll fact[2000100];

ll powM(ll a, ll b){
    if(b<0){
        return 0;
    }

    if(b==0){
        return 1;
    }

    if(b%2==0){
        ll tmp = powM(a,b/2);

        return tmp*tmp%MOD;
    }else{
        return a*powM(a,b-1)%MOD;
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
    ll n,k;
    cin>>n>>k;


    ll ans = 0;
    ll free = n-k;

    if(k==0){
        cout<<powM(3,n)<<'\n';
        return;
    }
    for(ll num = k;num>=1;num--){
        
        
        ll ff = (((C(free-1, free-num-1))%MOD * powM(3,free-num))%MOD*powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
        if(free<num+1){
            ff = 0;
        }
        if(free==num+1){
            ff = 3LL*(powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
        }

        ll ee = (((C(num-1+free-num+1-1, free-num+1))%MOD * powM(3,free-num+1))%MOD*powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
        if(free<num-1){
            ee = 0;
        }
        if(free==num-1){
            ee = (powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
        }


        ll fe = (((C(num+free-num-1, free-num))%MOD * powM(3,free-num))%MOD*powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
        ll ef = (((C(num+free-num-1, free-num))%MOD * powM(3,free-num+1))%MOD*powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
        if(free<num){
            fe = 0;
            ef = 0;
        }

        if(free==num){
            fe = (powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
            ef = 3LL*(powM(2,k-num)%MOD)*C(k-1,k-num)%MOD;
        }

        debug(ff);
        debug(ee);
        debug(fe);
        debug(ef);
        
        ans = ((((ans+ff)%MOD+ee)%MOD+ef)%MOD+fe)%MOD;
    }



    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = fact[1] = 1;
    for(ll i=2;i<2000100;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

