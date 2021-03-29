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


bool check(ll x, ll y, ll p, ll q, ll t){

    return x <= p*t && q*t - p*t >= y-x;
}


ll ans(ll l, ll r){
    ll pow = log2(r);
    if(l==r){
        return l;
    }else  if((1LL<<pow)<=l){
        return (1LL<<pow)+ans(l-(1LL<<pow),r-(1LL<<pow));
    }else if((1LL<<(pow+1))-1<=r){
        return (1LL<<(pow+1))-1;
    }else{
        return (1LL<<(pow))-1;
    }
}
void solve() {
    ll l,r;
    cin>>l>>r;
    cout<<ans(l,r)<<'\n';
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

