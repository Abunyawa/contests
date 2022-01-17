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

int ask(int x){
    cout<<"? "<<x<<endl;
    int ret;
    cout.flush();
    cin>>ret;
    return ret;
}

void solve() {
    int n;
    cin>>n;
    ll pr[2*n+1][2*n+1];
    ll sm = 0;
    for(int i=1;i<=2*n;i++){
        pr[0][i] = 0;
        pr[i][0] = 0;
        for(int j=1;j<=2*n;j++){
            cin>>pr[i][j];
            if(i>n && j>n){
                sm += pr[i][j];
            }
        }
    }

    ll dp = min(min(pr[n][2*n],pr[2*n][n]),min(pr[n+1][1],pr[1][n+1]));

    dp = min(dp, min(pr[n+1][n], pr[n][n+1]));
    dp = min(dp, min(pr[1][2*n], pr[2*n][1]));

    cout<<sm+dp<<'\n';

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

