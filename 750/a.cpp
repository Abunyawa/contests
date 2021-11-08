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
    ll a,b,c;
    cin>>a>>b>>c;

    ll mn = min(a,b);
    c -= mn;
    a -= mn;
    b -= mn;

    if(c%2==0){
        if(a%2!=0){
            cout<<1<<'\n';
            return;
        }else if(b%2!=0){
            cout<<0<<'\n';
            return;
        }else{
            cout<<0<<'\n';
            return;
        }

    }else{
        if(b%2!=0){
            cout<<1<<'\n';
            return;
        }else if(a%2!=0){
            cout<<0<<'\n';
            return;
        }else{
            cout<<1<<'\n';
            return;
        }
    }
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
