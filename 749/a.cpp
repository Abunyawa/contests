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

bool isPrime(ll x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return false;
        }
    }

    return true;
}

void solve() {
    int n;
    cin>>n;
    vi a(n);
    ll sm = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }

    if(!isPrime(sm)){
        cout<<n<<'\n';
        for(int i=1;i<=n;i++){
            cout<<i<<' ';
        }
        cout<<'\n';
    }else{
        bool flag = false;
        cout<<n-1<<'\n';
        for(int i=1;i<=n;i++){
            if(!flag){
                if(a[i-1]%2==1){
                    flag = true;
                    continue;
                }else{
                    cout<<i<<' ';
                }
            }else{
                cout<<i<<' ';
            }
        }

        cout<<'\n';
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

