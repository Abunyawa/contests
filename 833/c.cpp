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
    cin>>n;
    vl a(n);

    ll last = 0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        last+=a[i];
    }

    map<ll,int> m;

    ll ans = 0;
    int mx = 0;
    for(int i=n-1;i>=0;i--){
        m[last]++;
        mx = max(mx, m[last]);
        

        if(a[i]==0){
            ans += mx;
            mx = 0;
            m.clear();
            continue;
        }
        
        last-=a[i];
    }

    ans+=m[0];

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

