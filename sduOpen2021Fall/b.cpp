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
    ll ans = n;


    for(int i=1;i<=n;i++){
        ll c = i;
        ll ctr2 = 0;
        ll ctr5=0;
        while(c%2==0){
            ctr2++;
            c/=2;
        }

        while(c%5==0){
            ctr5++;
            c/=5;
        }

        ans += ctr2>0;

        ans += ctr5>0;

        ans+= ctr2>0 && ctr5>0;

    }

    


    cout<<ans<<'\n';

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

