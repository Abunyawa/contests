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
    ll n, a,b;
    cin>>n>>a>>b;

    vl x(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    vl left(n+1,0);

    for(int i=n-1;i>=0;i--){
        left[i] = left[i+1] + (x[i+1]-x[i])*(n-i)*b;
    }

    vl ans(n+1,0);
    ll mn = 1e17;

    for(int i=0;i<=n;i++){
        ans[i] = x[i]*a + left[i] + x[i]*b;
        mn = min(ans[i],mn);
    }

    
    cout<<mn<<'\n';
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

