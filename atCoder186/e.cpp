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
bool check(int x){
    int tmp = x;
    while(tmp!=0){
        if(tmp%10==7){
            return false;
        }
        tmp/=10;
    }
    tmp = x;
    while(tmp!=0){
        if(tmp%8==7){
            return false;
        }
        tmp/=8;
    }

    return true;
}


void solve() {
    ll n, s, k;
    cin>>n>>s>>k;
    ll l = 0;
    ll r = 1e9;
    if((n-s)%k==0){
        cout<<(n-s)/k<<'\n';
    }else{
        if(n%k==0){
            cout<<-1<<'\n';
            return;
        }
        ll need = (n-s)%k;
        ll nw = (n+k-1)/k * k -n;
        for(ll x = 1;x<=k;x++){
            if((nw * x)%k==need){
                cout<<nw<<'\n';
                cout<<x*(n+k-1)/k+(n-s)/k<<'\n';
                return;
            }
        } 

        cout<<-1<<'\n';
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

