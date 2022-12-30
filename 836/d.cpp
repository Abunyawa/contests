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

void solve() {
    ll n;
    cin>>n;


    ll sm = (n+1LL)*n/2LL;

    for(ll k = n-1;;k++){
        ll need = k*k;

        ll x = need-sm;
        if(x<0){
            continue;
        }
        x -= k+1-n;

        if(x%n<=((n-2)*(k-n+1))){
            ll add = x/n;
            ll left = x%n;

            cout<<1+add<<' '<<k+1+add<<' ';
            for(int i=n-1;i>=2;i--){
                ll dop = min(left,k-n+1);
                left-=dop;

                cout<<i+add+dop<<' ';
            }

            cout<<'\n';
            return;
        }
    }
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

