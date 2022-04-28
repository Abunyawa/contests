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

const ll MOD = 998244353;
ll fact[100010];


void solve() {
    int n;
    cin>>n;
    if(n%2==1){
        cout<<0<<'\n';
        return;
    }

    cout<<(fact[n/2]*fact[n/2])%MOD<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = fact[1] = 1;
    for(int i=2;i<100010;i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    int tt = 1;
    cin>>tt;

    while (tt--) {
        solve();
    }

    return 0;
}

