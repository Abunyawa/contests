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

ll t[4*200100];
ll fact[200100];
const ll INF = (1LL<<32)-1LL;
const ll MOD = 1e9+7;
ll preC[32][32];

void build (ll v, ll tl, ll tr) {
	if (tl == tr)
		t[v] = INF;
	else {
        t[v] = INF;
		ll tm = (tl + tr) / 2;
		build (v*2, tl, tm);
		build (v*2+1, tm+1, tr);
	}
}
 
void update (ll v, ll tl, ll tr, ll l, ll r, ll add) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] &= add;
	else {
		ll tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), add);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
	}
}
 
ll get (ll v, ll tl, ll tr, ll pos) {
	if (tl == tr)
		return t[v];
	ll tm = (tl + tr) / 2;
	if (pos <= tm)
		return t[v] & get (v*2, tl, tm, pos);
	else
		return t[v] & get (v*2+1, tm+1, tr, pos);
}

ll binPow(ll a, ll b){
    if(b==0){
        return 1LL;
    }

    if(b%2==0){
        ll ret = binPow(a,b/2);
        return (ret*ret)%MOD;
    }else{
        return (a*binPow(a,b-1))%MOD;
    }
}


ll C(int n, int k){
    return (fact[n] * binPow((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
}


void solve() {
    int n,m;
    cin>>n>>m;
    build(1, 1,n);

    

    for(int i=0;i<m;i++){
        ll l,r;
        ll x;
        cin>>l>>r>>x;

        update(1, 1, n, l, r, x);
    }

    vl a;
    for(int i=1;i<=n;i++){
        a.pb(get(1,1,n,i));
    }

    vi ctr(32,0);
    for(int i=0;i<n;i++){
        for(int j=0;(1LL<<j)<=a[i];j++){
            if(a[i]&(1LL<<j)){
                ctr[j]++;
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<32;i++){
        ll fix = binPow(2,n-ctr[i]);
        //cout<<ctr[i]<<'\n';
        ll md = (1LL<<i);
        if(ctr[i]==0){
            continue;
        }
        ll c = binPow(2,ctr[i]-1);

        ans = (ans + (((fix*c)%MOD)*md)%MOD)%MOD;
    }

    

    cout<<ans%MOD<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<200100;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    
    int tt = 1;
    cin>>tt;

    while (tt--) {
        solve();
    }

    return 0;
}

