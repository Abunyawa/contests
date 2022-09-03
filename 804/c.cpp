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

ll fact[200100];

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
    int n;
    cin>>n;

    vi a(n);
    vi pos(n,0);
    int ind = -1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]] = i;
    }

    ll ans = 1;
    ll l = pos[0];
    ll r = pos[0];


    for(int i=1;i<n;i++){
        if(pos[i]>r) r = pos[i];
        else if(pos[i]<l) l =pos[i];
        else ans = (ans*(r-l-i+1))%MOD;
    }
    
    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = fact[1] = 1;

    for(ll i=2;i<200100;i++){
        fact[i]  = (fact[i-1]*i)%MOD;
    }
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

