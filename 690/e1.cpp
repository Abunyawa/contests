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


ll ctr[200100];
ll count(ll n){
    if(n<3){
        return 0;
    }else{
        return (n*(n-1)*(n-2))/6;
    }
}

void solve() {
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<=n;i++){
        ctr[i] = 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        ctr[a[i]]++;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans+=count(ctr[i]);
        if(i+1<=n){
            ans+=(ctr[i]*(ctr[i]-1)/2LL*(ctr[i+1]));
            ans+=(ctr[i+1]*(ctr[i+1]-1)/2LL*(ctr[i]));
        }
        if(i+2<=n){
            ans+=(ctr[i]*(ctr[i]-1)/2LL*(ctr[i+2]));
            ans+=(ctr[i+2]*(ctr[i+2]-1)/2LL*(ctr[i]));
            ans+=(ctr[i]*(ctr[i+2])*(ctr[i+1]));
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

