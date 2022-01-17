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

bool f(ll k, vl a, ll h){
    int n = a.size();
    ll tot = 0;
    for(int i=0;i<n-1;i++){
        tot += min(k, a[i+1]-a[i]);

        //cout<<min(k, a[i+1]-a[i])<<'\n';
    }

    tot+=k;

    return tot>=h;
}

void solve() {
    ll n, h;
    cin>>n>>h;

    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    ll l = 1;
    ll r = h;
    while(l<r){
        ll m = (l+r)/2;

        if(f(m,a,h)){
            r = m;
        }else{
            l = m+1;
        }
    }
    

    cout<<r<<'\n';
    //cout<<f(r,a,h)<<'\n';
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

