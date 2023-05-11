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
1 2 3 5 3
*/

void solve() {
    ll m;
    cin>>m;

    if(m==1){
        cout<<2<<'\n';
        cout<<1<<' '<<1<<'\n';
        return;
    }
    

    ll mod = 1;
    ll prev1 = 1;
    ll prev2 = 1;
    vi ans;
    ans.pb(1);
    ans.pb(2);

    for(ll i=3;i<=m;i+=mod){
        ans.pb(i);
        mod = prev1+prev2;
        prev2 = prev1;
        prev1 = mod;
    }

    ans.pb(ans[ans.size()-2]);

    cout<<ans.size()<<'\n';

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }

    cout<<'\n';
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

