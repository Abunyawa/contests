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
    ll k;
    cin>>n>>k;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll ans = 0;
    for(int i = 0;i<n;i++){
        if(a[i-1]+a[i]<k){
            ans+=k-(a[i-1]+a[i]);
            a[i] += k-(a[i-1]+a[i]);
        }
    }


    cout<<ans<<'\n';
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
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

