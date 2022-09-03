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

ll binPow(ll n, ll x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = binPow(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*binPow(n,x-1))%MOD;
    }
}

void solve() {
    ll n;
    cin>>n;
    vl a(n);
    ll sm = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
        if(sm>=MOD){
            sm-=MOD;
        }
    }

    ll mtp = 0;
    for(int i=1;i<=n;i++){
        ll p1 = i/n;

        mtp+=p1;
        if(mtp>=MOD){
            mtp-=MOD;
        }
    }
    ll ans = ((mtp*sm)%MOD * binPow(n,MOD-2))%MOD;
    cout<<ans<<'\n';


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

