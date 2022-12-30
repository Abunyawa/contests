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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}

bool check(ll s, int d){

    while(s!=0){
        int cur = s%10;
        s/=10;
        if(cur%d!=0){
            return false;
        }
    }

    return true;
}

void solve() {
    ll n;
    int d;
    cin>>n>>d;
    int ans  = 0;
    for(int i=1;i<=n;i++){
        if(check(i,d)){
            ans++;
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

