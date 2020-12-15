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
    ll sm = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }

    ll ans = 0;
    if(sm%(n-1)!=0){
        ans+=(n-1)-sm%(n-1);
    }
    sm+=ans;

    ll mx = 0;
    for(int i=0;i<n;i++){
        if(a[i]>mx){
            mx = a[i];
        }
    }
    if(mx<=(sm/(n-1))){
        cout<<ans<<'\n';
        return;
    }else{
        ans+=mx*(n-1)-sm;
        cout<<ans<<'\n';
    }

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

