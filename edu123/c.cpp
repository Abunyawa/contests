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

/*
4 3 2 1
1 4 3 2
2 1 4 3
3 2 1 4
*/

void solve() {
    int n,x;
    cin>>n>>x;
    vi a(n+1);
    vi pref(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i] = pref[i-1]+a[i];
    }

    vi bst(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bst[j-i+1] = max(bst[j-i+1], pref[j]-pref[i-1] + (j-i+1)*x);
        }
    }

    vi ans(n+1,0);
    for(int i=n;i>=0;i--){
        for(int j=i;j<=n;j++){
            ans[i] = max(ans[i],bst[j]-x*(j-i));
        }
        for(int j=0;j<i;j++){
            ans[i] = max(ans[i],bst[j]);
        }
    }

    for(int i =0;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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

