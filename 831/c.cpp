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
typedef pair<ll, ll> pll;
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

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(all(a));

    ll ans = 0;
    
    ans+= a[n-1]-a[0];
 
    ans+= max(a[n-1]-a[n-2], a[1]-a[0]);


    for(int i=1;i<n-1;i++){
        ll loc1 = -1;
        if(i+1!=n-1){
            loc1 = a[n-1]-a[i];
            loc1 += a[i+1]-a[i];
        }

        ll loc2 = -1;
        if(i-1!=0){
            loc2 = a[i]-a[0];
            loc2 += a[i]-a[i-1];
        }

        ans = max(ans, max(loc1, loc2));
    }


    for(int i=0;i<n;i++){
        ll loc = 0;
 
        loc += max(a[i]-a[0], a[n-1]-a[i]);
 
        if(i+1<n && i-1>=0){
            loc  += min(a[i]-a[i-1], a[i+1]-a[i]);
        }else if(i+1<n){
            loc += a[i+1]-a[i];
        }else{
            loc += a[i]-a[i-1];
        }
 
        ans = max(ans,loc);
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

