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
    ll n, m;
    cin>>n>>m;

    vl a(n*m);
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }


    sort(all(a));

    ll ans = (n*m-1)*a[n*m-1] - min((n*m-n)*a[0] + (n-1)*a[1], (n*m-m)*a[0]+(m-1)*a[1]);
    ll ans1 = -(n*m-1)*a[0] + max((n*m-n)*a[n*m-1] + (n-1)*a[n*m-2], (n*m-m)*a[n*m-1]+(m-1)*a[n*m-2]);
    cout<<max(ans1,ans)<<'\n';

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

