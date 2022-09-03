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
    ll a,b,c,d;

    cin>>a>>b>>c>>d;


    ll g1 = __gcd(a,b);
    ll g2 = __gcd(c,d);

    a/=g1; b/=g1;
    c/=g2; d/=g2;

    if(a==c && d==b){
        cout<<0<<'\n';
        return;
    }else if(a==0 || c==0){
        cout<<1<<'\n';
        return;
    }

    a*=d;
    c*=b;
    b*=d;
    d=b;

    if(a%c==0 || c%a==0){
        cout<<1<<'\n';
        return;
    }

    cout<<2<<'\n';
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

