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
    ll l, r;
    cin>>l>>r;

    vi ctr(32,0);
    ll n = r-l+1;
    for(ll k = 0; k<32;k++){
        ll dv = (1<<k);
        ll cur = (r+1)/dv;

        ctr[k] = (cur)/2 * dv;

        if(cur%2==1){
            ctr[k] += (r+1)%dv;
        }
        
        cur = l/dv;

        ctr[k] -= (cur)/2 * dv;

        if(cur%2==1){
            ctr[k] -= l%dv;
        }

        //cout<<ctr[k]<<' ';
    }
    //cout<<'\n';
    

    sort(all(ctr));

    cout<<r-l+1-ctr[31]<<'\n';
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

