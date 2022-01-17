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

/*
x/u + y/v = (x+y)/(u+v)

x/u + y/v = (vx + uy) / uv

*/

void solve() {
    ll n,m;
    cin>>n>>m;

    ll ans1 = n*(m/3);
    if(m%3!=0){
        ans1+=(n/3) * (m%3);
        if(n%3!=0){
            if(n%3==1){
                ans1++;
            }else{
                ans1+=2;
            }
        }
    }

    ll tmp = n;
    n = m;
    m = tmp;
    ll ans2 = n*(m/3);
    if(m%3!=0){
        ans2+=(n/3) * (m%3);
        if(n%3!=0){
            if(n%3==1){
                ans2++;
            }else{
                ans2+=2;
            }
        }
    }

    cout<<min(ans1,ans2)<<'\n';
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

