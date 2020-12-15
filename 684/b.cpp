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
    int n,k;
    cin>>n>>k;
    vl a(n*k);
    for(int i=0;i<n*k;i++){
        cin>>a[i];
    }
    int l=0;
    int r = n*k-1;
    int fromL = ((n+1)/2-1);
    int fromR = n-fromL-1;

    ll ans = 0;
    for(int i=0;i<k;i++){
        for(int k=0;k<fromL;k++){
            l++;
        }
        for(int k=0;k<fromR;k++){
            r--;
        }
        ans+=a[r--];
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

