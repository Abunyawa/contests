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
    int n,l;
    cin>>n>>l;

    vl a(n);
    int bn[n][l];
    vi ctr(l,0);
    for(int i=0;i<n;i++){
        cin>>a[i];    
        for(int k =0;k<l;k++){
            bn[i][k] = a[i]%2;
            a[i]/=2;
            if(bn[i][k]==0){
                ctr[k]++;
            }
        }
    }

    ll ans = 0;
    for(int i=l-1;i>=0;i--){
        int z = ctr[i];
        int o = n-ctr[i];
        ans*=2;
        if(o>z){
            ans+=1;
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

