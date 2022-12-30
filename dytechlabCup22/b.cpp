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
    ll l,r;
    cin>>l>>r;

    ll lb = min(l/(ll)sqrt(l), (ll)sqrt(l));
    ll rb = min(r/(ll)sqrt(r), (ll)sqrt(r));
    //cout<<lb<<' '<<rb<<'\n';
    ll ans = 0;

    ll asd = 1e9;

    if(lb*lb>=l && lb*lb<=r){
        ans++;
    }

    if(lb*(lb+1LL)>=l && lb*(lb+1LL)<=r){
        ans++;
    }

    if(lb*(lb+2LL)>=l && lb*(lb+2LL)<=r){
        ans++;
    }


    if(rb!=lb){
        if(rb*rb>=l && rb*rb<=r){
            ans++;
        }

        if(rb*(rb+1LL)>=l && rb*(rb+1LL)<=r){
            ans++;
        }

        if(rb*(rb+2LL)>=l && rb*(rb+2LL)<=r){
            ans++;
        }
    }

    if(rb-lb-1LL>0){
        ans+= 3LL*(rb-lb-1LL);
    }

    cout<<ans<<'\n';
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

