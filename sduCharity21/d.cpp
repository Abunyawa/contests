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

ll binPow(ll a, ll b){
    if(b==0){
        return 1;
    }

    if(b%2==0){
        ll ret  = binPow(a,b/2);
        return (ret)*ret%MOD;
    }else{
        return (a*binPow(a,b-1))%MOD;
    }
}
/*
    123
    132
    213
    231
    312
    321
    222
*/
void solve() {
    ll n;
    cin>>n;
    n *=3LL;

    ll all = binPow(3LL,n);

    ll fact = 1;
    for(int i=1;i<=n/3;i++){
        fact = (fact*i)%MOD;
    }
    all -= binPow(7,n/3);
    if(all<0){
        all+=MOD;
    }

    cout<<all%MOD<<'\n';
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

