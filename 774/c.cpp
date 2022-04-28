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
1011

0100
0110
0001

*/

ll fact[20];

void solve() {
    ll n;
    cin>>n;

    int ans = __builtin_popcountll(n);

    for(int i = 0;i<(1<<16);i++){
        
        ll sm = 0;
        for(int k=0;k<15;k++){
            if(i&(1<<k)){
                sm+=fact[k];
            }
        }

        if(sm>n){
            continue;
        }
        ans = min(ans,__builtin_popcountll(i)+__builtin_popcountll(n-sm));
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = fact[1] = 1;
    for(ll i = 2;i<=15;i++){
        fact[i] = fact[i-1]*i;
    }
    int tt = 1;
    cin>>tt;

    while (tt--) {
        solve();
    }

    return 0;
}

