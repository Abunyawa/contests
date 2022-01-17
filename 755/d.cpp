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

/*
x/u + y/v = (x+y)/(u+v)

x/u + y/v = (vx + uy) / uv

*/


int ctr = 0;
void answer(ll i, ll j, ll k){
    cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
    cout.flush();
}
ll ask(ll l, ll r){
    ctr++;
    cout<<"? "<<l<<' '<<r<<endl;
    ll tot;
    cin>>tot;
    cout.flush();

    return tot;
}

/*
6 2 5 6
1 4 3 2 6 5
*/

void solve() {
    ll tot;
    ll n;
    cin>>n;
    ctr = 0;
    tot = ask(1LL,n);
    ll l=1LL, r=n;

    while(l<r){
        ll m = (l+r)/2LL;
        
        if(ctr>=40){
            assert(0);
        }
        ll now = ask(1LL,m);
        if(now == tot){
            r = m;
        }else{
            l = m+1;
        }
        debug(l);
        debug(r);
    }

    int k = r;
    int j = k - (tot - ask(1, k-1));
    tot = ask(1, j-1);
    int i = j-1 - (tot - ask(1, j-2));

    answer(i,j,k);
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

