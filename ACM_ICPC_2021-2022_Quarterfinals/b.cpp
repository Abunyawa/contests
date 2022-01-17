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

ll n,m,c;

ll f(ll mT){
    ll left = n - mT*m;

    if(left<=0){
        return abs(left);
    }else{
        ll cT1 = left/c;
        ll cT2 = (left+c-1)/c;

        return min(abs(n - mT*m - cT1*c), abs(n - mT*m - cT2*c));
    }
}

ll f1(ll cT){
    ll left = n - cT*c;

    if(left<=0){
        return abs(left);
    }else{
        ll mT1 = left/m;
        ll mT2 = (left+m-1)/m;

        return min(abs(n - cT*c - mT1*m), abs(n - cT*c - mT2*m));
    }
}

void solve() {
    cin>>n>>m>>c;
    ll bst = (n+m-1)/m;
    ll bst2 = (n+c-1)/c;

    ll ans = n;
    ll mT;
    ll cT;
    for(int i=0;i<=bst;i++){
        ll cur  = f(i);
        if(cur<ans){
            ans = cur;
            mT = i;
            cT = -1;
        }
    }

    for(int i=0;i<=bst2;i++){
        ll cur  = f1(i);
        if(cur<ans){
            ans = cur;
            cT = i;
            mT = -1;
        }
    }
    if(cT==-1){
        ll left = n - mT*m;
        if(left<=0){
            cout<<mT<<' '<<0<<'\n';
        }else{
            ll cT1 = left/c;
            ll cT2 = (left+c-1)/c;

            if(abs(n - mT*m - cT1*c) < abs(n - mT*m - cT2*c)){
                cout<<mT<<' '<<cT1<<'\n';
            }else{
                cout<<mT<<' '<<cT2<<'\n';
            }
        }
    }else{
        ll left = n - cT*c;

        if(left<=0){
            cout<<0<<' '<<cT<<'\n';
        }else{
            ll mT1 = left/m;
            ll mT2 = (left+m-1)/m;

            if(abs(n - cT*c - mT1*m) < abs(n - cT*c - mT2*m)){
                cout<<mT1<<' '<<cT<<'\n';
            }else{
                cout<<mT2<<' '<<cT<<'\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

