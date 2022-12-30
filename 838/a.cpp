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
    vi a(n);
    int sum = 0;
    int ans = 1e6;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%2==0){
        cout<<0<<'\n';
        return;
    }

    for(int i=0;i<n;i++){
        ll left = sum-a[i];
        int ctr = 0;
        while(a[i]>0){
            ctr++;
            a[i]/=2;
            if((left+a[i])%2==0){
                ans = min(ans,ctr);
                break;
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

