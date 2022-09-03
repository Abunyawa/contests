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
    ll l=0,r=0,u=0,d=0;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;

        if(x==0){
            if(y>0){
                u = max(u,abs(y));
            }else{
                d = max(d,abs(y));
            }
        }else{
            if(x>0){
                r = max(r, abs(x));
            }else{
                l = max(l, abs(x));
            }
        }
    }

    cout<<2*(l+r+d+u)<<'\n';
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

