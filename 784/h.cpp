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

    vi a(n);

    vi bts(31,0);
    for(int i=0;i<n;i++){
        cin>>a[i];

        for(int j=0;j<31;j++){
            if(!(a[i]&(1<<j))){
                bts[j]++;
            }
        }
    }

    int ans = 0;

    for(int i=30;i>=0;i--){
        if(bts[i]==0){
            ans+=(1<<i);
        }else{
            if(bts[i]<=k){
                k-=bts[i];
                ans+=(1<<i);
            }
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
