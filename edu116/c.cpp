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
    ll k;
    cin>>n>>k;

    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    k++;
    vl ans;
    for(int i =0;i<n-1;i++){
        if(k!=0){
            int dif = a[i+1]-a[i];
            ll mx = 0;
            for(int j=0;j<dif;j++){
                mx *=10;
                mx+=9;
            }
            if(mx<=k){
                k-=mx;
                ans.pb(mx);
            }else{
                ans.pb(k);
                k = 0;
            }
        }
    }

    if(k!=0){
        ans.pb(k);
    }


    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
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

