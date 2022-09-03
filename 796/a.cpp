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
100000000
100000001


100010101010101
000000000000001


*/

void solve() {
    ll y;
    cin>>y;

    ll x = 0;
    int ind;
    for(int i=0;(1<<(i-1))<=y;i++){
        if(y&(1<<i)){
            x+=(1<<i);
            ind = i;
            break;
        }
    }

    if(__builtin_popcountll(y)>1){
        cout<<x<<'\n';
        return;
    }

    for(int i=0;(1<<(i-1))<=y;i++){
        if(ind == i) continue;
        if(!(y&(1<<i))){
            x+=(1<<i);
            break;
        }
    }
    cout<<x<<'\n';
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

