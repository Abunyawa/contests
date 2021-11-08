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
const ll MOD = 1e9+7;

ll binPow(ll a, ll b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }else{
        if(b%2==0){
            ll tmp = binPow(a,b/2);

            return (tmp*tmp)%MOD;
        }else{
            return (a*binPow(a,b-1))%MOD;
        }
    }
}

void solve() {
    int n;
    char c;
    cin>>n>>c;
    string s;
    cin>>s;
    bool flag = true;
    for(int i=0;i<n;i++){
        if(s[i]!=c){
            flag = false;
        }
    }

    if(flag){
        cout<<0<<'\n';
        return;
    }

    for(int i=n/2;i<n;i++){
        if(s[i]==c){
            cout<<1<<'\n';
            cout<<i+1<<'\n';
            return;
        }
    }

    cout<<2<<'\n';
    cout<<n<<' '<<n-1<<'\n';
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

