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

    vector<ll> a;
    ll ans = 0;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ans+=x/k;
        if(x%k!=0){
            a.pb(x%k);
        }
    }

    int l = 0;
    int r = a.size()-1;

    sort(all(a));

    while(l<r){
        if(a[l]+a[r]>=k){
            ans++;
            r--;
            l++;
        }else{
            l++;
        }
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

