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
    int n;
    ll x;
    cin>>n>>x;
    vl a(n);
    ll cur = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cur+=a[i];
    }

    sort(all(a));

    
    ll ans = 0;
    for(int i=n-1;i>=0;i--){
        ll l = 0;
        ll r = 1e10;
        if(cur>x){
            cur-=a[i];
            continue;
        }
        while(l<r-1){
            ll m = (l+r)/2;
            ll sm = cur + (i+1)*m;

            if(sm>x){
                r = m;
            }else{
                l = m;
            }
        }
        //cout<<cur<<' '<<l<<'\n';
        ans += l+1;
        cur-=a[i];
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

