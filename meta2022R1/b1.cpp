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

ll MOD = 1e9+7;

void solve() {
    int n;
    cin>>n;

    vl ax(3010,0);
    vl ay(3010,0);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ax[x]++;
        ay[y]++;
    }


    int q;
    cin>>q;

    vl bx(3010,0);
    vl by(3010,0);

    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        bx[x]++;
        by[y]++;
    }


    ll sum = 0;
    for(ll i=0;i<3010;i++){
        for(ll j=0;j<3010;j++){
            ll curx = ((i-j)*(i-j)*ax[i]*bx[j])%MOD;
            ll cury = ((i-j)*(i-j)*ay[i]*by[j])%MOD;

            sum = (sum+curx+cury)%MOD;
        }
    }


    cout<<sum<<'\n';
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

