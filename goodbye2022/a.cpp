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
    int n,m;
    cin>>n>>m;

    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vl b(m);
    ll ans = 0;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(all(a));

    for(int i=0;i<m;i++){
        ll cur = b[i];
        int ind = 0;
        for(int j=0;j<n;j++){
            if(cur-a[j] > cur -a[ind]){
                ind = j;
            }
        }

        a[ind] = b[i];
    }

    for(int i=0;i<n;i++){
        ans+=a[i];
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

