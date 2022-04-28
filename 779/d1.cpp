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
    int l,r;
    cin>>l>>r;
    int n = r-l+1;
    ll xr = 0;
    ll gd = 0;
    map<int,int> m;
    vi a(18,0);
    vi b(18,0);
    
    for(int i=l;i<=r;i++){
        ll x;
        cin>>x;
        xr^=x;
        for(int k = 0;k<18;k++){
            if(x&(1<<k)){
                a[k]++;
            }
        }
        x = i;

        gd^=i;
        for(int k = 0;k<18;k++){
            if(x&(1<<k)){
                b[k]++;
            }
        }
    }
    

    ll ans = 0;

    for(int i=0;i<18;i++){
        cout<<a[i]<<' ';
        if(a[i]!=b[i]){
            ans += (1<<i);
        }
    }
    cout<<'\n';
    cout<<ans<<'\n';

    for(int i=l;i<=r;i++){
        cout<<(i^ans)<<' ';
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

