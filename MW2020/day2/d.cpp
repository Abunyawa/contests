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
const ll MOD = 1e9+7;


void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll powM(ll a, ll p){
    if(p==0) return 1;
    if(p==1) return a%MOD;
    if(p%2==0) {
        ll res = powM(a,p/2);
        return (res*res)%MOD;
    }else{
        return (a*powM(a,p-1))%MOD;
    }
}


void solve() {
    int n;

    while(cin>>n){
        ll ans = 0;
        ll x;
        cin>>x;
        vl a(n);
        vl b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            ans+= (a[i]*b[i])%MOD;
            if(ans>=MOD) ans-=MOD;
        }

        ans+=x;
        if(ans>=MOD) ans-=MOD;

        ans = (ans*powM(x,n-1))%MOD;
        cout<<ans<<'\n';
    }
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

