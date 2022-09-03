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
    int n,q;
    cin>>n>>q;

    vl a(n+1,0);
    vl pref(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }


    sort(all(a));
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1]+a[i];
    }
    for(int i=0;i<q;i++){
        int x, y;
        cin>>x>>y;

        int l = n-x+1;
        int r = l+y-1;

        cout<<pref[r]-pref[l-1]<<'\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

