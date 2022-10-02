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

ll ask(ll a, ll b){
    cout<<"? "<<a<<' '<<b<<endl;

    ll x;
    cin>>x;

    return x;
}

void solve() {
    ll a = 1;
    ll b = 1e18;

    ll l = 3;
    ll r = 1e18;

    while(l<r-2){
        ll m = l + (r-l)/3;

        if(ask(1,m)==-1){
            r = m-1;
        }else{
            l = m;
        }
    }

    for(ll i = r;i>=l;i++){
        if(ask(1,i)!=-1){
            cout<<"! "<<i<<endl;
            return;
        }
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

